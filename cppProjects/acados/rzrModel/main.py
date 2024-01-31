from acados_template import AcadosOcp, AcadosOcpSolver, AcadosSimSolver
from vehicle_model import export_vehicle_model
import numpy as np
import scipy.linalg
from utils import plot_results
import pdb
from mppiPlanner import planTrajectory
import time
import matplotlib.pyplot as plt


X0 = np.array([10.0, 0.0, 0.0, 10.0, 45.0, 0.0, 0.0, 0.0])  # Intitalize the states [x,y,v,th,th_d]
N_horizon = 20  # Define the number of discretization steps
T_horizon = 1.0  # Define the prediction horizon
dt = T_horizon/N_horizon # size of time step
d_delta_max = 0.4  # Define the max force allowed
d_delta_min = -0.4
d_trq_max = 8000.0
d_trq_min = -8000.0
# d_mz_min = -4000.0
# d_mz_max = 4000.0
V_min = 3.0
V_max = 12.0
delta_min = -0.45
delta_max = 0.45
trq_min = -4000
trq_max = 4000
# mz_min = -1000 
# mz_max = 1000

x_min = np.array([V_min, -10, -10, -10, -100, -100, delta_min, trq_min])
x_max = np.array([V_max, 10, 10, 1000, 150, 100, delta_max, trq_max])



def create_ocp_solver_description() -> AcadosOcp:
    # create ocp object to formulate the OCP
    ocp = AcadosOcp()

    model = export_vehicle_model()
    ocp.model = model
    nx = model.x.size()[0]
    nu = model.u.size()[0]
    # nz = model.z.size()[0]
    ny = nx + nu

    # set dimensions
    ocp.dims.N = N_horizon

    # set cost
    Q_mat = 2 * np.diag([10e-1, 1e-2, 1e-2, 100e-2, 500e-1, 1e-2, 1e-3/delta_max, 1e-2/trq_max])  # [V, v, r, X, Y, Psi, delta, trq, mz]
    R_mat = 2 * np.diag([1e-3/d_delta_max, 1e-2/d_trq_max])
    # R_mat = 2 * 5 * np.diag([1e-2, 1e-1, 1e-2])

    ocp.cost.cost_type = "LINEAR_LS"
    ocp.cost.cost_type_e = "LINEAR_LS"

    ny = nx + nu
    ny_e = nx

    ocp.cost.W_e = Q_mat
    ocp.cost.W = scipy.linalg.block_diag(Q_mat, R_mat)

    ocp.cost.Vx = np.zeros((ny, nx))
    ocp.cost.Vx[:nx, :nx] = np.eye(nx)
    # ocp.cost.Vz = np.zeros((nz,nz))

    Vu = np.zeros((ny, nu))
    Vu[nx : nx + nu, 0:nu] = np.eye(nu)
    ocp.cost.Vu = Vu

    ocp.cost.Vx_e = np.eye(nx)

    ocp.cost.yref = np.zeros((ny,))
    ocp.cost.yref_e = np.zeros((ny_e,))

    # set constraints
    ocp.constraints.lbu = np.array([d_delta_min, d_trq_min])
    ocp.constraints.ubu = np.array([d_delta_max, d_trq_max])
    # print(ocp.constraints.idxbu)
    ocp.constraints.idxbu = np.array([0,1])
    # print(ocp.constraints.idxbu)
 
    # ocp.dims.nbx = nx
    # print(ocp.constraints.idxbx)
    ocp.constraints.idxbx = np.array([0, 1, 2, 3, 4, 5, 6, 7])
    ocp.constraints.lbx = x_min
    ocp.constraints.ubx = x_max
    # ocp.constraints.idxbx = np.array([0, 1])
    # ocp.constraints.lbx = np.array([3, -10])
    # ocp.constraints.ubx = np.array([25, 10])
    # print(ocp.constraints.idxbx)
    # print(ocp.dims.nbx)
    # print(ocp.dims.nbu)

    # ocp.constraints.idxbx = np.array([0,1,2,3,4,5,6,7])

    # Non-Linear Constraints
    # obs1 = model.x
    # ocp.constraints.con_h_expr

    
    ocp.constraints.x0 = X0

    # set options
    ocp.solver_options.qp_solver = "PARTIAL_CONDENSING_HPIPM"  # FULL_CONDENSING_QPOASES was PARTIAL_CONDENSING_HPIPM
    ocp.solver_options.hessian_approx = "GAUSS_NEWTON"  # 'GAUSS_NEWTON', 'EXACT'
    ocp.solver_options.integrator_type = "IRK" # was IRK
    ocp.solver_options.nlp_solver_type = "SQP_RTI"  # SQP_RTI, SQP
    ocp.solver_options.nlp_solver_max_iter = 400
    ocp.solver_options.print_level = 0

    # ocp.solver_options.levenberg_marquardt = 1e-2

    # set parameters
    # Cf = 420
    # Cr = 420
    # Jz = 1000
    # ocp.parameter_values = np.array([Cf, Cr, Jz])

    # set prediction horizon
    ocp.solver_options.tf = T_horizon
    #pdb.set_trace()

    return ocp


def closed_loop_simulation():

    sizeElite = 100
    map = np.load("map.npy")

    mapLength = 300
    mapHeight = 120
    gridSize = 0.1

    x = np.arange(0,mapLength,gridSize)
    y = np.arange(0,mapHeight,gridSize)

    XG = 280
    YG = 45

    x_coordinates, y_coordinates = np.meshgrid(x,y)
    fig1 = plt.figure()
    plt.pcolor(x_coordinates, y_coordinates, map)

    # create solvers
    ocp = create_ocp_solver_description()
    acados_ocp_solver = AcadosOcpSolver(
        ocp, json_file="acados_ocp_" + ocp.model.name + ".json"
    )
    acados_integrator = AcadosSimSolver(
        ocp, json_file="acados_ocp_" + ocp.model.name + ".json"
    )

    # prepare simulation
    Nsim = 250
    nx = ocp.model.x.size()[0]
    nu = ocp.model.u.size()[0]
    print(nx)
    print(nu)

    simX = np.ndarray((Nsim + 1, nx))
    simU = np.ndarray((Nsim, nu))

    xcurrent = X0
    simX[0, :] = xcurrent

    # initialize solver
    # print(X0)
    for stage in range(N_horizon + 1):
        #acados_ocp_solver.set(stage, "x", 0.0 * np.ones(xcurrent.shape))
        acados_ocp_solver.set(stage, "x", np.array(X0))
    for stage in range(N_horizon):
        acados_ocp_solver.set(stage, "u", np.zeros((nu,)))

    # ref_traj = np.genfromtxt("refTraj.csv", delimiter=',')
    # ref_traj = planTrajectory(x0=xcurrent, preview=3*T_horizon, dt=dt, num_samples=6000, map=map, x=x, y=y, sizeElite=sizeElite, plot=False)   
    # print(ref_traj)
    # print(ref_traj.shape)
    # closed loop
    for i in range(Nsim):
        # print("i="+str(i))
        # set initial state constraint
        acados_ocp_solver.set(0, "lbx", xcurrent)
        acados_ocp_solver.set(0, "ubx", xcurrent)
        # This seems like where we might call the planner and get the new reference values.
        # acados_ocp_solver.set("con_h_expr", )
        # update yref
        t = time.time()
        ref_traj = planTrajectory(x0=xcurrent, preview=3*T_horizon, dt=dt, num_samples=4000, map=map, x=x, y=y, XG=XG, YG=YG, sizeElite=sizeElite, plot=True)
        #print(ref_traj[:,1])
        # print(time.time()-t)
        for j in range(N_horizon):
            V_ref = ref_traj[0,j]
            v_ref = ref_traj[1,j]
            r_ref = ref_traj[2,j]
            X_ref = ref_traj[3,j]
            Y_ref = ref_traj[4,j]
            Psi_ref = ref_traj[5,j]
            yref = np.array([V_ref, v_ref, r_ref, X_ref, Y_ref, Psi_ref, 0, 0, 0, 0])
            acados_ocp_solver.set(j, "yref", yref)
        V_ref = ref_traj[0,N_horizon]
        v_ref = ref_traj[1,N_horizon]
        r_ref = ref_traj[2,N_horizon]
        X_ref = ref_traj[3,N_horizon]
        Y_ref = ref_traj[4,N_horizon]  
        Psi_ref = ref_traj[5,N_horizon]    
        yref_N = np.array([V_ref, v_ref, r_ref, X_ref, Y_ref, Psi_ref, 0, 0])
        acados_ocp_solver.set(N_horizon, "yref", yref_N)

        # solve ocp
        status = acados_ocp_solver.solve()
        # print(time.time()-t)
        # print("solver status: " + str(status))
        if status not in [0, 2]:
            acados_ocp_solver.print_statistics()
            plot_results(
                np.linspace(0, T_horizon / N_horizon * i, i + 1),
                trq_max,
                simU[:i, :],
                simX[: i + 1, :],
            )
            raise Exception(
                f"acados acados_ocp_solver returned status {status} in closed loop instance {i} with {xcurrent}"
            )

        if status == 2:
            print(
                f"acados acados_ocp_solver returned status {status} in closed loop instance {i} with {xcurrent}"
            )
        simU[i, :] = acados_ocp_solver.get(0, "u")
        print(simU[i,:])
        # simulate system
        # add loop to simulate entire plan
        # for k in range(N_horizon):
        #     simU[k, :] = acados_ocp_solver.get(k, "u")
        #     acados_integrator.set("x", xcurrent)
        #     acados_integrator.set("u", simU[k, :])

        #     status = acados_integrator.solve()
        #     if status != 0:
        #         raise Exception(
        #             f"acados integrator returned status {status} in closed loop instance {i}"
        #         )

        #     # update state
        #     xcurrent = acados_integrator.get("x")
        #     #print(xcurrent)
        #     simX[k + 1, :] = xcurrent
        acados_integrator.set("x", xcurrent)
        acados_integrator.set("u", simU[i, :])

        status = acados_integrator.solve()
        if status != 0:
            raise Exception(
                f"acados integrator returned status {status} in closed loop instance {i}"
            )

        # update state
        xcurrent = acados_integrator.get("x")
        #print(xcurrent)
        simX[i + 1, :] = xcurrent
        print(time.time()-t)

    # plot results
        
    plt.plot(simX[:,3],simX[:,4],color='g',alpha=1,linewidth=3) 
    ax = plt.gca()
    ax.set_aspect('equal', adjustable='box')   
    plot_results(
        np.linspace(0, T_horizon / N_horizon * Nsim, Nsim + 1), [d_delta_max, d_trq_max], simU, simX
    )
    #print(simX)

    # x_coordinates, y_coordinates = np.meshgrid(x,y)
    # fig = plt.figure()
    # plt.pcolor(x_coordinates, y_coordinates, map)
    # plt.plot(simX[:,3],simX[:,4],color='g',alpha=1)
    # plt.show()
   


if __name__ == "__main__":
    closed_loop_simulation()
