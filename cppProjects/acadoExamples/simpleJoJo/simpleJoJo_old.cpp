#include <acado_optimal_control.hpp>
#include <bindings/acado_gnuplot/gnuplot_window.hpp>

int main( )
{
    USING_NAMESPACE_ACADO

    // THE VARIABLES OF THE JOJO:
    // --------------------------
    DifferentialState          x;   // the position of the "hand"
    DifferentialState          v;   // the velocity of the "hand"
    DifferentialState          y;   // the position of the jojo
    DifferentialState          w;   // the velocity of the jojo

    Control                    u;   // the control action of the "hand"

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


    // THE MODEL EQUATIONS FOR PHASE I:
    // -----------------------------------
    DifferentialEquation f1( 0.0, T1 );
    f1 << dot(x) ==  v                   ;
    f1 << dot(v) ==  u                   ;
    f1 << dot(y) ==  w                   ;
    f1 << dot(w) == -mu*g + k*u + a*(v-w);


    // THE EQUATIONS FOR THE JUMP:
    // ---------------------------
    Transition        j;
    IntermediateState z;

    z = k*v;

    j << x  ==  x ;
    j << v  ==  v ;
    j << y  ==  y ;
    j << w  ==  z + sqrt( z*z + k*(w*w-2.0*w*v) );


    // THE MODEL EQUATIONS FOR PHASE II:
    // -----------------------------------
    DifferentialEquation f2( T1, T2 );
    f2 << dot(x) ==  v                   ;
    f2 << dot(v) ==  u                   ;
    f2 << dot(y) ==  w                   ;
    f2 << dot(w) == -mu*g + k*u + a*(v-w);


    // DEFINE AN OPTIMAL CONTROL PROBLEM:
    // ----------------------------------
    OCP ocp;
    ocp.minimizeLagrangeTerm( u*u );

    ocp.subjectTo( f1 );
    //ocp.subjectTo( j  );
    ocp.subjectTo( f2 );

    ocp.subjectTo( AT_START     , x   ==  0.00 );
    ocp.subjectTo( AT_START     , v   ==  0.00 );
    ocp.subjectTo( AT_START     , y   ==  0.00 );
    ocp.subjectTo( AT_START     , w   ==  0.00 );

    ocp.subjectTo( AT_TRANSITION, x-y ==  L    );

    ocp.subjectTo( AT_END       , x   == -0.10 );
    ocp.subjectTo( AT_END       , v   ==  0.00 );
    ocp.subjectTo( AT_END       , x-y ==  0.00 );
    ocp.subjectTo( AT_END       , w   ==  0.00 );

    ocp.subjectTo( 0.0 <= T1 <= 2.0 );
    ocp.subjectTo( 0.0 <= T2 <= 4.0 );


    // SETUP A GNUPLOT WINDOW TO DISPLAY THE RESULTS:
    // ---------------------------------------------------
    GnuplotWindow window;
        window.addSubplot( x, "POSITION OF THE HAND: x " );
        window.addSubplot( v, "VELOCITY OF THE HAND: v " );
        window.addSubplot( y, "POSITION OF THE JOJO: y " );
        window.addSubplot( w, "VELOCITY OF THE JOJO: w " );
        window.addSubplot( u, "THE CONTROL INPUT   : u " );


    // DEFINE AN OPTIMIZATION ALGORITHM AND SOLVE THE OCP:
    // ---------------------------------------------------
    OptimizationAlgorithm algorithm(ocp);

    algorithm << window;
    algorithm.solve();

    return 0;
}