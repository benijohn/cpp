#include <acado_optimal_control.hpp>
#include <bindings/acado_gnuplot/gnuplot_window.hpp>
    
int main( )
    {
    USING_NAMESPACE_ACADO

    // THE VARIABLES OF THE JOJO:
    // --------------------------
    DifferentialState          x1;   // the position of the "hand"
    DifferentialState          v1;   // the velocity of the "hand"
    DifferentialState          y1;   // the position of the jojo
    DifferentialState          w1;   // the velocity of the jojo

    Control                    u1;   // the control action of the "hand"

    DifferentialState          x2;   // the position of the "hand"
    DifferentialState          v2;   // the velocity of the "hand"
    DifferentialState          y2;   // the position of the jojo
    DifferentialState          w2;   // the velocity of the jojo

    Control                    u2;   // the control action of the "hand"

    Parameter                 T1;   // the duration of phase I
    Parameter                 T2;   // the duration of phase II

    // THE GIVEN JOJO PARAMETERS:
    // --------------------------
    const double       m = 0.200;   // the mass of the jojo (200g)
    const double       J = 1e-4 ;   // the inertia of the jojo (1e-4kg*m^2)
    const double       r = 0.010;   // the coiling radius of the jojo (1cm)
    const double       g = 9.81 ;   // the gravitational constant (9.81m/s^2)
    const double       a = 1e-2 ;   // the coiling friction (1e-2/s)
    const double       L = 1.00 ;   // the length of the rope (1m)

    // OTHER USEFUL CONSTANTS:
    // ---------------------------
    const double k  = J/(m*r*r+J);   // the jojo's damping ratio
    const double mu = 1.0 - k    ;   // the effective mass ratio

    // THE MODEL EQUATIONS FOR PHASE I and II :
    // ----------------------------------------
    DifferentialEquation f1;                           // with normalized time
    (f1 << dot(x1)) ==  v1*T1                   ;
    (f1 << dot(v1)) ==  u1*T1                   ;
    (f1 << dot(y1)) ==  w1*T1                   ;
    (f1 << dot(w1)) == (-mu*g + k*u1 + a*(v1-w1))  *T1;
    (f1 << dot(x2)) ==  v2*T2                   ;
    (f1 << dot(v2)) ==  u2*T2                   ;
    (f1 << dot(y2)) ==  w2*T2                   ;
    (f1 << dot(w2)) == (-mu*g + k*u2 + a*(v2-w2))  *T2;

    // THE EQUATIONS FOR THE JUMP:
    // ---------------------------

    IntermediateState z1, a1, a2;

    z1 = k*v1;
    a1 = (z1 + sqrt( z1*z1 + k*(w1*w1-2.0*w1*v1))) ;
    a2 = (x2-y2);

    // DEFINE AN OPTIMAL CONTROL PROBLEM:
    // ----------------------------------
    OCP ocp1(0.0,1.0,20);
    ocp1.minimizeLagrangeTerm( u1*u1*T1+ u2*u2*T2 );
    ocp1.subjectTo(f1);

    ocp1.subjectTo( AT_START     , x1   ==  0.00 );
    ocp1.subjectTo( AT_START     , v1   ==  0.00 );
    ocp1.subjectTo( AT_START     , y1   ==  0.00 );
    ocp1.subjectTo( AT_START     , w1   ==  0.00 );

    ocp1.subjectTo( AT_END     , x1-y1   ==  L );
    ocp1.subjectTo( AT_END       , x2   == -0.10 );
    ocp1.subjectTo( AT_END       , v2   ==  0.00 );
    ocp1.subjectTo( AT_END       , a2   ==  0.00 );
    ocp1.subjectTo( AT_END       , w2   ==  0.00 );

    //PERIODIC BOUNDARY CONSTRAINTS:
    // ----------------------------

    ocp1.subjectTo(0.0, x2, -x1, 0.0);
    ocp1.subjectTo(0.0, v2, -v1, 0.0);
    ocp1.subjectTo(0.0, y2, -y1, 0.0);
    ocp1.subjectTo(0.0, w2, -a1, 0.0);

    ocp1.subjectTo( -10 <= u1 <= 10);
    ocp1.subjectTo( -10 <= u2 <= 10);

    ocp1.subjectTo( 0.1 <= T1 <= 2.0 );
    ocp1.subjectTo( 0.1 <= T2 <= 4.0 );

    // DEFINE AN OPTIMIZATION ALGORITHM AND SOLVE THE OCP:
    // ---------------------------------------------------
    OptimizationAlgorithm algorithm(ocp1);
    algorithm.set(INTEGRATOR_TYPE, INT_RK45);
    algorithm.set(DISCRETIZATION_TYPE,  MULTIPLE_SHOOTING );
    algorithm.set(KKT_TOLERANCE, 1e-10);
    algorithm.set(INTEGRATOR_TOLERANCE, 1e-8);
    algorithm.set(MAX_NUM_ITERATIONS, 1000);

    GnuplotWindow window;
        window.addSubplot( x1, "POSITION OF THE HAND: x " );
        window.addSubplot( v1, "VELOCITY OF THE HAND: v " );
        window.addSubplot( y1, "POSITION OF THE JOJO: y " );
        window.addSubplot( w1, "VELOCITY OF THE JOJO: w " );
        window.addSubplot( u1, "THE CONTROL INPUT   : u " );


    algorithm << window;
    //algorithm.set( PRINT_SCP_METHOD_PROFILE, YES );
    algorithm.solve();

    VariablesGrid out_states;
    VariablesGrid out_controls;
    algorithm.getDifferentialStates(out_states);
    algorithm.getControls(out_controls);
    //algorithm.getParameters("/home/laboratoire/mnt/E/Bureau/ElodieP/GIT_Vrille_ACADO/jojo_parameters.txt");

    out_controls.appendValues(out_states);
    //out_controls.print("/home/laboratoire/mnt/E/Bureau/ElodieP/GIT_Vrille_ACADO/out_controls_norm.txt", "", PS_PLAIN);

    // out_states.print("/home/laboratoire/mnt/E/Bureau/ElodieP/GIT_Vrille_ACADO/out_states_norm.txt", "", PS_PLAIN);

    return 0;
}