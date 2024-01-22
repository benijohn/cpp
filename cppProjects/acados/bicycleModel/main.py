from acados_template import AcadosOcp, AcadosOcpSolver, AcadosSimSolver
from vehicle_model import export_vehicle_model
import numpy as np
import scipy.linalg
from utils import plot_results
import pdb


X0 = np.array([10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0])  # Intitalize the states [x,y,v,th,th_d]
N_horizon = 50  # Define the number of discretization steps
T_horizon = 2.0  # Define the prediction horizon
d_delta_max = 0.3  # Define the max force allowed
d_delta_min = -0.3
d_trq_max = 5000.0
d_trq_min = -5000.0
d_mz_min = -4000.0
d_mz_max = 4000.0
V_min = 3.0
V_max = 25.0
delta_min = -0.01
delta_max = 0.01
trq_min = -1000
trq_max = 1000
mz_min = -1000 
mz_max = 1000

x_min = np.array([V_min, -10, -10, -10, -100, -100, delta_min, trq_min, mz_min])
x_max = np.array([V_max, 10, 10, 1000, 100, 100, delta_max, trq_max, mz_max])



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
    Q_mat = 2 * np.diag([1e-1, 0.0, 0.0, 1e-2, 1e-2, 0.0, 1e-2, 1e-3, 1e-2])  # [V, v, r, X, Y, Psi, delta, trq, mz]
    R_mat = 2 * 5 * np.diag([1e-2, 1e-1, 1e-2])

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
    ocp.constraints.lbu = np.array([d_delta_min, d_trq_min, d_mz_min])
    ocp.constraints.ubu = np.array([d_delta_max, d_trq_max, d_mz_max])
    print(ocp.constraints.idxbu)
    ocp.constraints.idxbu = np.array([0,1,2])
    print(ocp.constraints.idxbu)
 
    # ocp.dims.nbx = nx
    print(ocp.constraints.idxbx)
    ocp.constraints.idxbx = np.array([0, 1])
    ocp.constraints.lbx = np.array([3, -10])
    ocp.constraints.ubx = np.array([25, 10])
    print(ocp.constraints.idxbx)
    # print(ocp.dims.nbx)
    # print(ocp.dims.nbu)

    # ocp.constraints.idxbx = np.array([0,1,2,3,4,5,6,7])


    ocp.constraints.x0 = X0

    # set options
    ocp.solver_options.qp_solver = "PARTIAL_CONDENSING_HPIPM"  # FULL_CONDENSING_QPOASES was PARTIAL_CONDENSING_HPIPM
    ocp.solver_options.hessian_approx = "GAUSS_NEWTON"  # 'GAUSS_NEWTON', 'EXACT'
    ocp.solver_options.integrator_type = "IRK" # was IRK
    ocp.solver_options.nlp_solver_type = "SQP"  # SQP_RTI, SQP
    ocp.solver_options.nlp_solver_max_iter = 400
    ocp.solver_options.print_level = 0

    ocp.solver_options.levenberg_marquardt = 1e-2

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

    # create solvers
    ocp = create_ocp_solver_description()
    acados_ocp_solver = AcadosOcpSolver(
        ocp, json_file="acados_ocp_" + ocp.model.name + ".json"
    )
    acados_integrator = AcadosSimSolver(
        ocp, json_file="acados_ocp_" + ocp.model.name + ".json"
    )

    # prepare simulation
    Nsim = 200
    nx = ocp.model.x.size()[0]
    nu = ocp.model.u.size()[0]

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

    # closed loop
    for i in range(Nsim):
        # print("i="+str(i))
        # set initial state constraint
        acados_ocp_solver.set(0, "lbx", xcurrent)
        acados_ocp_solver.set(0, "ubx", xcurrent)

        # update yref
        for j in range(N_horizon):
            yref = np.array([10, 0, 0, 100, 10, 0, 0, 0, 0, 0, 0, 0])
            acados_ocp_solver.set(j, "yref", yref)
        yref_N = np.array([10, 0, 0, 100, 10, 0, 0, 0, 0])
        acados_ocp_solver.set(N_horizon, "yref", yref_N)

        # solve ocp
        status = acados_ocp_solver.solve()

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

        # simulate system
        acados_integrator.set("x", xcurrent)
        acados_integrator.set("u", simU[i, :])

        status = acados_integrator.solve()
        if status != 0:
            raise Exception(
                f"acados integrator returned status {status} in closed loop instance {i}"
            )

        # update state
        xcurrent = acados_integrator.get("x")
        simX[i + 1, :] = xcurrent

    # plot results
    plot_results(
        np.linspace(0, T_horizon / N_horizon * Nsim, Nsim + 1), [d_delta_max, d_trq_max, d_mz_max], simU, simX
    )


if __name__ == "__main__":
    closed_loop_simulation()
