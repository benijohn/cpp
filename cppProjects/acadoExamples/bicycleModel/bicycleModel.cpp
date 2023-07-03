#include <acado_optimal_control.hpp>
#include <acado_toolkit.hpp>
#include <bindings/acado_gnuplot/gnuplot_window.hpp>

int main( )
{
    USING_NAMESPACE_ACADO


    // INTRODUCE THE VARIABLES:
    // -------------------------
    DifferentialState uB;
    DifferentialState vB;
    DifferentialState rB;
    DifferentialState psiB;
    DifferentialState XB;
    DifferentialState YB;
    //DifferentialState omega;

    AlgebraicState alpha_f;
    AlgebraicState alpha_r;
    //AlgebraicState lambda_f;
    //AlgebraicState lambda_r;

    Disturbance R;
    Control delta, torque;
    //Control torque;

    double mB = 1350.0;
    double Jz = 1200;
    double lf = 1.8;
    double lr = 1.8;
    double kT = 200000.0;
    double r_tire = 0.5;
    double C_alpha = 1250;




    // DEFINE A DIFFERENTIAL EQUATION:
    // -------------------------------
    DifferentialEquation f;

    f << dot(uB) == torque/r_tire + vB*rB;
    f << dot(vB) == C_alpha*(alpha_f + alpha_r) - uB*rB;
    f << dot(rB) == C_alpha*(alpha_f*lf - alpha_r*lr)/Jz;
    f << dot(psiB) == rB;
    f << dot(XB) == uB*cos(psiB) - vB*sin(psiB);
    f << dot(YB) == uB*sin(psiB) + vB*cos(psiB);
    //f << dot(omega) == 
    f << 0 == (vB+lf*rB)/uB - delta - alpha_f;
    f << 0 == (vB-lr*rB)/uB - alpha_r;
    //f << 0 == lambda_r - (omega*r_tire - uB)/uB;



    // SETTING UP THE (SIMULATED) PROCESS:
    // -----------------------------------
    OutputFcn identity;
    DynamicSystem dynamicSystem( f,identity );

    Process process( dynamicSystem,INT_BDF );

    //VariablesGrid disturbance;// = readFromFile( "road.txt" );
    //disturbance.read( "road.txt" );
    //process.setProcessDisturbance( disturbance );


    // DEFINE LEAST SQUARE FUNCTION:
    // -----------------------------
    Function h;

    h << uB;
    h << vB;
    h << rB;
    h << psiB;
    h << XB;
    h << YB;
    h << delta;
    h << torque;


    // LSQ coefficient matrix
    DMatrix Q(8,8);
    Q(0,0) = 10.0;

    Q(1,1) = 1.0;
    Q(2,2) = 1.0;
    Q(3,3) = 1.0e-3;
    Q(4,4) = 1.0e-2;
    Q(5,5) = 10.0;
    Q(6,6) = 1.0e-4;
    Q(7,7) = 1.0e-4;

    // Reference
    DVector r(8); 
    r.setAll( 0.0 );
    r(0) = 10;
    r(4) = 100;
    r(5) = 2.7;



    // DEFINE AN OPTIMAL CONTROL PROBLEM:
    // ----------------------------------
    const double t_start = 0.0;
    const double t_end   = 10.0;

    OCP ocp( t_start, t_end, 200 );
    

    ocp.minimizeLSQ( Q, h, r );
    

    ocp.subjectTo( f );
    ocp.subjectTo( -20000.0 <= torque <= 20000.0 );
    //ocp.subjectTo( R == 0.0 );
    ocp.subjectTo( -0.5 <= delta <= 0.5 );


    // SETTING UP THE MPC CONTROLLER:
    // ------------------------------
    RealTimeAlgorithm alg( ocp, 0.1 );
    
    alg.set( INTEGRATOR_TYPE, INT_BDF );
    alg.set( MAX_NUM_ITERATIONS,2 );

    StaticReferenceTrajectory zeroReference;

    Controller controller( alg,zeroReference );


    // SETTING UP THE SIMULATION ENVIRONMENT,  RUN THE EXAMPLE...
    // ----------------------------------------------------------
    SimulationEnvironment sim( t_start, t_end, process, controller );
   

    DVector x0(6);
    x0.setZero();
    x0(0) = 7;

    sim.init( x0 );
    sim.run( );


    // ... AND PLOT THE RESULTS
    // ------------------------
    VariablesGrid diffStates;
    sim.getProcessDifferentialStates( diffStates );

    VariablesGrid feedbackControl;
    sim.getFeedbackControl( feedbackControl );

    GnuplotWindow window;
        window.addSubplot( diffStates(0),   "Body Velocity [m/s]" );
        window.addSubplot( diffStates(1),   "Lateral Velocity [m/s]" );
        window.addSubplot( diffStates(2),   "Yaw Velocity [rad/s]" );
        window.addSubplot( diffStates(3),   "Yaw [rad]" );
        window.addSubplot( diffStates(5), "Body Position X [m]");
        window.addSubplot( diffStates(5), "Body Position Y [m]");
        window.addSubplot( feedbackControl(0), "delta (rad)" );
        window.addSubplot( feedbackControl(1),     "torque (Nm)" );
    window.plot( );

    return 0;
}