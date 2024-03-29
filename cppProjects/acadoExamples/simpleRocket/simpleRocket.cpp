#include <acado_optimal_control.hpp>
#include <bindings/acado_gnuplot/gnuplot_window.hpp>

int main( )
{
    USING_NAMESPACE_ACADO

    DifferentialState        s,v,m      ;   // the differential states
    Control                  u          ;   // the control input u
    Parameter                T          ;   // the time horizon T
    DifferentialEquation     f( 0.0, T );   // the differential equation

    //-------------------------------------
    OCP ocp( 0.0, T )                   ;   // time horizon of the OCP: [0,T]
    ocp.minimizeMayerTerm( T )          ;   // the time T should be optimized

    f << dot(s) == v                    ;   // an implementation
    f << dot(v) == (u-0.2*v*v)/m        ;   // of the model equations
    f << dot(m) == -0.01*u*u            ;   // for the rocket.

    ocp.subjectTo( f                   );   // minimize T s.t. the model,
    ocp.subjectTo( AT_START, s ==  0.0 );   // the initial values for s,
    ocp.subjectTo( AT_START, v ==  0.0 );   // v,
    ocp.subjectTo( AT_START, m ==  1.0 );   // and m,

    ocp.subjectTo( AT_END  , s == 10.0 );   // the terminal constraints for s
    ocp.subjectTo( AT_END  , v ==  0.0 );   // and v,

    ocp.subjectTo( -0.1 <= v <=  1.7   );   // as well as the bounds on v
    ocp.subjectTo( -1.1 <= u <=  1.1   );   // the control input u,
    ocp.subjectTo(  5.0 <= T <= 15.0   );   // and the time horizon T.
    //-------------------------------------

    GnuplotWindow window                ;   // visualize the results in a
    window.addSubplot( s, "DISTANCE s" );   // Gnuplot window.
    window.addSubplot( v, "VELOCITY v" );
    window.addSubplot( m, "MASS     m" );
    window.addSubplot( u, "CONTROL  u" );

    OptimizationAlgorithm algorithm(ocp);   // construct optimization algorithm,

    algorithm.set( INTEGRATOR_TYPE      , INT_RK78          ); // ocp algorithm options see ACADO examples (3) for more inforation
    algorithm.set( INTEGRATOR_TOLERANCE , 1e-8              );
    algorithm.set( DISCRETIZATION_TYPE  , SINGLE_SHOOTING   );
    algorithm.set( KKT_TOLERANCE        , 1e-4              );

    algorithm << window                 ;   // flush the plot window,
    algorithm.solve()                   ;   // and solve the problem.

    VariablesGrid states, parameters, controls;

    algorithm.getDifferentialStates(states    );          // saving optimizaton results
    algorithm.getParameters        (parameters);          // see example(4) for more information about how to write directly to MATLAB file
    algorithm.getControls          (controls  );

    states.print();
    parameters.print();
    controls.print();

    return 0                            ;
}