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

    Parameter mB;
    double mW = 50.0;
    double kS = 20000.0;
    double kT = 200000.0;


    // DEFINE THE DYNAMIC SYSTEM:
    // --------------------------
    DifferentialEquation f;

    f << dot(xB) == vB;
    f << dot(xW) == vW;
    f << dot(vB) == ( -kS*xB + kS*xW + F ) / mB;
    f << dot(vW) == (  kS*xB - (kT+kS)*xW + kT*R - F ) / mW;

    OutputFcn g;
    g << xB;
    g << 500.0*vB + F;

    DynamicSystem dynSys( f,g );


    // SETUP THE PROCESS:
    // ------------------
    Process myProcess;

    myProcess.setDynamicSystem( dynSys,INT_RK45 );
    myProcess.set( ABSOLUTE_TOLERANCE,1.0e-1 );

    DVector x0( 4 );
    x0.setZero( );
    x0( 0 ) = 0.01;

    myProcess.initializeStartValues( x0 );
    myProcess.setProcessDisturbance( "road.txt" );

    // Add control noise
    DVector actuatorMean( 1 ), actuatorAmplitude( 1 );
    actuatorMean.setZero();
    actuatorAmplitude.setAll( 50.0 );

    GaussianNoise myNoise( actuatorMean, actuatorAmplitude );

    Actuator myActuator( 1, 1 );

    myActuator.setControlNoise( myNoise, 0.1 );
    myActuator.setControlDeadTimes( 0.1 );
    myActuator.setParameterDeadTimes( 0.2 );

    myProcess.setActuator( myActuator);

    myProcess.set( PLOT_RESOLUTION, HIGH );

    //myProcess.replot( PLOT_AT_EACH_ITERATION );
    

    GnuplotWindow window;
        window.addSubplot( xB, "Body Position [m]" );
        //window.addSubplot( xW, "Wheel Position [m]" );
        //window.addSubplot( vB, "Body Velocity [m/s]" );
        //window.addSubplot( vW, "Wheel Velocity [m/s]" );

        //window.addSubplot( F,"Damping Force [N]" );
        //window.addSubplot( mB,"Body Mass [kg]" );
        //window.addSubplot( R, "Road Disturbance" );
        //window.addSubplot( g(0),"Output 1" );
        //window.addSubplot( g(1),"Output 2" );

    myProcess << window;

   
    // SIMULATE AND GET THE RESULTS:
    // -----------------------------
    VariablesGrid u( 1,0.0,1.0,6 );

    u( 0,0 ) = 10.0;
    u( 1,0 ) = -200.0;
    u( 2,0 ) = 200.0;
    u( 3,0 ) = 0.0;
    u( 4,0 ) = 0.0;
    u( 5,0 ) = 0.0;

    DVector p( 1 );
    p(0) = 300.0;

    myProcess.init( 0.0 );
    myProcess.run( u,p );

    VariablesGrid xSim, ySim;

    myProcess.getLast( LOG_SIMULATED_DIFFERENTIAL_STATES,xSim );
    xSim.print( "Simulated Differential States" );

    myProcess.getLast( LOG_PROCESS_OUTPUT,ySim );
    ySim.print( "Process Output" );


    return 0;
}