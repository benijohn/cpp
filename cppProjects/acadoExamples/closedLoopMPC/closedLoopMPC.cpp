#include <acado_optimal_control.hpp>
#include <acado_toolkit.hpp>
#include <bindings/acado_gnuplot/gnuplot_window.hpp>

int main( )
{
    USING_NAMESPACE_ACADO


    // INTRODUCE THE VARIABLES:
    // -------------------------
    DifferentialState xB;
    DifferentialState xW;
    DifferentialState vB;
    DifferentialState vW;

    Disturbance R;
    Control F;

    double mB = 350.0;
    double mW = 50.0;
    double kS = 20000.0;
    double kT = 200000.0;


    // DEFINE A DIFFERENTIAL EQUATION:
    // -------------------------------
    DifferentialEquation f;

    f << dot(xB) == vB;
    f << dot(xW) == vW;
    f << dot(vB) == ( -kS*xB + kS*xW + F ) / mB;
    f << dot(vW) == (  kS*xB - (kT+kS)*xW + kT*R - F ) / mW;


    // SETTING UP THE (SIMULATED) PROCESS:
    // -----------------------------------
    OutputFcn identity;
    DynamicSystem dynamicSystem( f,identity );

    Process process( dynamicSystem,INT_RK45 );

    VariablesGrid disturbance;// = readFromFile( "road.txt" );
    disturbance.read( "road.txt" );
    process.setProcessDisturbance( disturbance );


    // DEFINE LEAST SQUARE FUNCTION:
    // -----------------------------
    Function h;

    h << xB;
    h << xW;
    h << vB;
    h << vW;
    h << F;

    // LSQ coefficient matrix
    DMatrix Q(5,5);
    Q(0,0) = 10.0;
    Q(1,1) = 10.0;
    Q(2,2) = 1.0;
    Q(3,3) = 1.0;
    Q(4,4) = 1.0e-8;

    // Reference
    DVector r(5); 
    r.setAll( 0.0 );


    // DEFINE AN OPTIMAL CONTROL PROBLEM:
    // ----------------------------------
    const double t_start = 0.0;
    const double t_end   = 1.0;

    OCP ocp( t_start, t_end, 20 );

    ocp.minimizeLSQ( Q, h, r );

    ocp.subjectTo( f );
    ocp.subjectTo( -200.0 <= F <= 200.0 );
    ocp.subjectTo( R == 0.0 );


    // SETTING UP THE MPC CONTROLLER:
    // ------------------------------
    RealTimeAlgorithm alg( ocp,0.025 );
    alg.set( INTEGRATOR_TYPE, INT_RK78 );
    //alg.set( "MAX_NUM_ITERATIONS",2 );

    StaticReferenceTrajectory zeroReference;

    Controller controller( alg,zeroReference );


    // SETTING UP THE SIMULATION ENVIRONMENT,  RUN THE EXAMPLE...
    // ----------------------------------------------------------
    SimulationEnvironment sim( 0.0,2.5,process,controller );

    DVector x0(4);
    x0.setZero();

    sim.init( x0 );
    sim.run( );


    // ... AND PLOT THE RESULTS
    // ------------------------
    VariablesGrid diffStates;
    sim.getProcessDifferentialStates( diffStates );

    VariablesGrid feedbackControl;
    sim.getFeedbackControl( feedbackControl );

    GnuplotWindow window;
        window.addSubplot( diffStates(0),   "Body Position [m]" );
        window.addSubplot( diffStates(1),   "Wheel Position [m]" );
        window.addSubplot( diffStates(2),   "Body Velocity [m/s]" );
        window.addSubplot( diffStates(3),   "Wheel Velocity [m/s]" );
        window.addSubplot( feedbackControl, "Damping Force [N]" );
        window.addSubplot( disturbance,     "Road Excitation [m]" );
    window.plot( );

    return 0;
}