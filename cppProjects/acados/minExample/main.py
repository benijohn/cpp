from acados_template import AcadosModel
from casadi import SX, vertcat, sin, cos, atan
from acados_template import AcadosOcp, AcadosOcpSolver, AcadosSimSolver
import numpy as np
import scipy.linalg

model_name = "bicycle_model_ode"

# set up states & controls
V = SX.sym("V")
v = SX.sym("v")
r = SX.sym("r")
X = SX.sym("X")
Y = SX.sym("Y")
Psi = SX.sym("Psi")
delta = SX.sym("delta")
trq = SX.sym("trq")

x = vertcat(V,v,r,X,Y,Psi,delta,trq)

#controls
d_delta = SX.sym("d_delta")
d_trq = SX.sym("d_trq")
u = vertcat(d_delta,d_trq)

# xdot
V_dot = SX.sym("V_dot")
v_dot = SX.sym("v_dot")
r_dot = SX.sym("r_dot")
X_dot = SX.sym("X_dot")
Y_dot = SX.sym("Y_dot")
Psi_dot = SX.sym("Psi_dot")
delta_dot = SX.sym("delta_dot")
trq_dot = SX.sym("trq_dot")

xdot = vertcat(V_dot,v_dot,r_dot,X_dot,Y_dot,Psi_dot,delta_dot,trq_dot)

# parameters
mass =1350
r_tire = 0.5
lf = 1.8
lr = 1.8
tr = 2
Cf = 420
Cr = 420
Jz = 1000
rho = 1.125
Cd = 0.6
Af = 3.4
g = 9.80655
Cr = 0.018

# intermediate variables
alpha_f = atan((v+lf*r)/V) -delta
alpha_r = atan((v-lr*r)/V)

f_expl = vertcat(((trq/r_tire) - (1/2)*rho*Cd*Af*V**2 - mass*g*Cr)/mass + r*v,  # long acc = driving force - aero_drag - rolling_drag
                    (-Cf*alpha_f- Cr*alpha_r)/mass - r*V, # lateral acc
                    (-lf*Cf*alpha_f + lr*Cr*alpha_r)/Jz, # yaw acc
                    V*cos(Psi) - v*sin(Psi), # X 
                    V*sin(Psi) + v*cos(Psi), # Y 
                    r, # yaw 
                    d_delta,
                    d_trq)

f_impl = xdot - f_expl

model = AcadosModel()

model.f_impl_expr = f_impl
model.f_expl_expr = f_expl
model.x = x
model.xdot = xdot
model.u = u
model.name = model_name

ocp = AcadosOcp()

ocp.model = model
nx = model.x.size()[0]
nu = model.u.size()[0]
ny = nx + nu

# ocp parameters
X0 = np.array([10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0])  # Intitalize the states [V, v, r, X, Y, Psi, delta, trq]
N_horizon = 50  # Define the number of discretization steps
T_horizon = 2.0  # Define the prediction horizon
d_delta_max = 0.0005  # Define the max force allowed
d_delta_min = -0.0005
d_trq_max = 200.0
d_trq_min = -200.0
V_min = 3
V_max = 25
delta_min = -0.001
delta_max = 0.001
trq_min = -1000
trq_max = 1000

x_min = np.array([V_min, -10, -10, -10, -100, -100, delta_min, trq_min])
x_max = np.array([V_max, 10, 10, 1000, 100, 100, delta_max, trq_max])

# set dimensions
ocp.dims.N = N_horizon

# set cost
Q_mat = 2 * np.diag([1e-1, 0.0, 0.0, 1e-2, 0.0, 0.0, 0.0, 0.0])  # [x,y,x_d,y_d,th,th_d]
R_mat = 2 * 5 * np.diag([1e-2, 0.0])

ocp.cost.cost_type = "LINEAR_LS"
ocp.cost.cost_type_e = "LINEAR_LS"


# set constraints
ocp.constraints.lbu = np.array([d_delta_min, d_trq_min])
ocp.constraints.ubu = np.array([d_delta_max, d_trq_max])
ocp.constraints.idxbu = np.array([0,1])

# first method
print(ocp.constraints.lbx)
ocp.constraints.idxbx = np.array([0])
ocp.constraints.lbx = np.array([3])
ocp.constraints.lbu = np.array([25])

# second method
# for i in range(N_horizon):
#     print(i)
#     ocp.set('lbx', x_min[0], i)


acados_ocp_solver = AcadosOcpSolver(
    ocp, json_file="acados_ocp_" + ocp.model.name + ".json"
)