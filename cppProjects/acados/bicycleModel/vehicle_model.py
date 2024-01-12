from acados_template import AcadosModel
from casadi import SX, vertcat, sin, cos, atan

# Reference for model equations:
# http://users.isr.ist.utl.pt/~jag/publications/08-JETC-RCarona-vcontrol.pdf

def export_robot_model() -> AcadosModel:
    model_name = "unicycle_ode"

    # set up states & controls
    V = SX.sym("V")
    v = SX.sym("v")
    r = SX.sym("r")
    X = SX.sym("X")
    Y = SX.sym("Y")
    Psi = SX.sym("Psi")
    delta = SX.sym("delta")

    x = vertcat(V,v,r,X,Y,Psi,delta)

    delta_dot = SX.sym("delta_dot")
    T = SX.sym("T")
    u = vertcat(delta_dot, T)

    # xdot
    V_dot = SX.sym("V_dot")
    v_dot = SX.sym("v_dot")
    r_dot = SX.sym("r_dot")
    X_dot = SX.sym("X_dot")
    Y_dot = SX.sym("Y_dot")
    Psi_dot = SX.sym("Psi_dot")

    xdot = vertcat(V_dot,v_dot,r_dot,X_dot,Y_dot,Psi_dot,delta_dot)

    # parameters
    mass =1350
    r_tire = 0.5
    lf = 1.8
    lr = 1.8
    tr = 2
    Cf = 420;
    Cr = 420;
    Jz = 1000;
    p = vertcat([Cf, Cr, Jz])

    # algebraic variables
    alpha_f = atan((v+lf*r)/V) -delta
    alpha_r = atan((v-lr*r)/V)
    z = vertcat(alpha_f, alpha_r)

    # dynamics

    f_expl = vertcat(T/r_tire/mass + r*v, (-z[0]*p[0]-z[1]*p[1])/mass - r*V, (-lf*z[0]*p[0]+lr*z[1]*p[1])/Jz,
                     V*cos(Psi) - v*sin(Psi), V*sin(Psi) + v*cos(Psi), r, delta_dot)

    f_impl = xdot - f_expl

    model = AcadosModel()

    model.f_impl_expr = f_impl
    model.f_expl_expr = f_expl
    model.x = x
    model.xdot = xdot
    model.u = u
    model.z = z
    model.p = p
    model.name = model_name

    return model
