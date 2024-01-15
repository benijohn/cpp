from acados_template import AcadosModel
from casadi import SX, vertcat, sin, cos, atan

# Reference for model equations:
# http://users.isr.ist.utl.pt/~jag/publications/08-JETC-RCarona-vcontrol.pdf

def export_vehicle_model() -> AcadosModel:
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
    # p = vertcat([Cf, Cr, Jz])
    p = []

    # algebraic variables
    alpha_f = atan((v+lf*r)/V) -delta
    alpha_r = atan((v-lr*r)/V)
    # z = vertcat(alpha_f, alpha_r)

    # dynamics

    # f_expl = vertcat(T/r_tire/mass + r*v, (-z[0]*p[0]-z[1]*p[1])/mass - r*V, (-lf*z[0]*p[0]+lr*z[1]*p[1])/Jz,
    #                  V*cos(Psi) - v*sin(Psi), V*sin(Psi) + v*cos(Psi), r, delta_dot)
    
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
    # model.z = z
    model.p = p
    model.name = model_name

    return model
