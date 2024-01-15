/* This file was automatically generated by CasADi 3.6.3.
 *  It consists of: 
 *   1) content generated by CasADi runtime: not copyrighted
 *   2) template code copied from CasADi source: permissively licensed (MIT-0)
 *   3) user code: owned by the user
 *
 */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_s5 CASADI_PREFIX(s5)
#define casadi_s6 CASADI_PREFIX(s6)
#define casadi_sq CASADI_PREFIX(sq)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

casadi_real casadi_sq(casadi_real x) { return x*x;}

static const casadi_int casadi_s0[12] = {8, 1, 0, 8, 0, 1, 2, 3, 4, 5, 6, 7};
static const casadi_int casadi_s1[6] = {2, 1, 0, 2, 0, 1};
static const casadi_int casadi_s2[3] = {0, 0, 0};
static const casadi_int casadi_s3[29] = {8, 8, 0, 4, 9, 13, 13, 13, 15, 17, 18, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 5, 3, 4, 1, 2, 0};
static const casadi_int casadi_s4[19] = {8, 8, 0, 1, 2, 3, 4, 5, 6, 7, 8, 0, 1, 2, 3, 4, 5, 6, 7};
static const casadi_int casadi_s5[7] = {8, 2, 0, 1, 2, 6, 7};
static const casadi_int casadi_s6[3] = {8, 0, 0};

/* unicycle_ode_impl_dae_fun_jac_x_xdot_u_z:(i0[8],i1[8],i2[2],i3[],i4[],i5[])->(o0[8],o1[8x8,18nz],o2[8x8,8nz],o3[8x2,2nz],o4[8x0]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a20, a21, a3, a4, a5, a6, a7, a8, a9;
  a0=arg[1]? arg[1][0] : 0;
  a1=arg[0]? arg[0][7] : 0;
  a2=5.0000000000000000e-01;
  a1=(a1/a2);
  a2=1350.;
  a1=(a1/a2);
  a3=arg[0]? arg[0][2] : 0;
  a4=arg[0]? arg[0][1] : 0;
  a5=(a3*a4);
  a1=(a1+a5);
  a0=(a0-a1);
  if (res[0]!=0) res[0][0]=a0;
  a0=arg[1]? arg[1][1] : 0;
  a1=-420.;
  a5=1.8000000000000000e+00;
  a6=(a5*a3);
  a6=(a4+a6);
  a7=arg[0]? arg[0][0] : 0;
  a6=(a6/a7);
  a8=atan(a6);
  a9=arg[0]? arg[0][6] : 0;
  a8=(a8-a9);
  a8=(a1*a8);
  a10=420.;
  a11=(a5*a3);
  a11=(a4-a11);
  a12=atan(a11);
  a12=(a12/a7);
  a13=(a10*a12);
  a8=(a8-a13);
  a8=(a8/a2);
  a2=(a3*a7);
  a8=(a8-a2);
  a0=(a0-a8);
  if (res[0]!=0) res[0][1]=a0;
  a0=arg[1]? arg[1][2] : 0;
  a8=-756.;
  a2=(a5*a3);
  a2=(a4+a2);
  a2=(a2/a7);
  a13=atan(a2);
  a13=(a13-a9);
  a13=(a8*a13);
  a9=756.;
  a14=(a5*a3);
  a14=(a4-a14);
  a15=atan(a14);
  a15=(a15/a7);
  a16=(a9*a15);
  a13=(a13+a16);
  a16=1000.;
  a13=(a13/a16);
  a0=(a0-a13);
  if (res[0]!=0) res[0][2]=a0;
  a0=arg[1]? arg[1][3] : 0;
  a13=arg[0]? arg[0][5] : 0;
  a16=cos(a13);
  a17=(a7*a16);
  a18=sin(a13);
  a19=(a4*a18);
  a17=(a17-a19);
  a0=(a0-a17);
  if (res[0]!=0) res[0][3]=a0;
  a0=arg[1]? arg[1][4] : 0;
  a17=sin(a13);
  a19=(a7*a17);
  a20=cos(a13);
  a21=(a4*a20);
  a19=(a19+a21);
  a0=(a0-a19);
  if (res[0]!=0) res[0][4]=a0;
  a0=arg[1]? arg[1][5] : 0;
  a0=(a0-a3);
  if (res[0]!=0) res[0][5]=a0;
  a0=arg[1]? arg[1][6] : 0;
  a19=arg[2]? arg[2][0] : 0;
  a0=(a0-a19);
  if (res[0]!=0) res[0][6]=a0;
  a0=arg[1]? arg[1][7] : 0;
  a19=arg[2]? arg[2][1] : 0;
  a0=(a0-a19);
  if (res[0]!=0) res[0][7]=a0;
  a0=7.4074074074074070e-04;
  a12=(a12/a7);
  a12=(a10*a12);
  a19=(a6/a7);
  a21=1.;
  a6=casadi_sq(a6);
  a6=(a21+a6);
  a19=(a19/a6);
  a19=(a1*a19);
  a12=(a12-a19);
  a12=(a0*a12);
  a12=(a12-a3);
  a12=(-a12);
  if (res[1]!=0) res[1][0]=a12;
  a12=1.0000000000000000e-03;
  a19=(a2/a7);
  a2=casadi_sq(a2);
  a2=(a21+a2);
  a19=(a19/a2);
  a19=(a8*a19);
  a15=(a15/a7);
  a15=(a9*a15);
  a19=(a19+a15);
  a19=(a12*a19);
  if (res[1]!=0) res[1][1]=a19;
  a16=(-a16);
  if (res[1]!=0) res[1][2]=a16;
  a17=(-a17);
  if (res[1]!=0) res[1][3]=a17;
  a3=(-a3);
  if (res[1]!=0) res[1][4]=a3;
  a3=(1./a6);
  a3=(a3/a7);
  a3=(a1*a3);
  a17=(1./a7);
  a11=casadi_sq(a11);
  a11=(a21+a11);
  a17=(a17/a11);
  a17=(a10*a17);
  a3=(a3-a17);
  a3=(a0*a3);
  a3=(-a3);
  if (res[1]!=0) res[1][5]=a3;
  a3=(1./a2);
  a3=(a3/a7);
  a3=(a8*a3);
  a17=(1./a7);
  a14=casadi_sq(a14);
  a14=(a21+a14);
  a17=(a17/a14);
  a17=(a9*a17);
  a3=(a3+a17);
  a3=(a12*a3);
  a3=(-a3);
  if (res[1]!=0) res[1][6]=a3;
  if (res[1]!=0) res[1][7]=a18;
  a20=(-a20);
  if (res[1]!=0) res[1][8]=a20;
  a20=(-a4);
  if (res[1]!=0) res[1][9]=a20;
  a20=(a5/a7);
  a20=(a20/a6);
  a1=(a1*a20);
  a20=-1.8000000000000000e+00;
  a11=(a20/a11);
  a11=(a11/a7);
  a10=(a10*a11);
  a1=(a1-a10);
  a0=(a0*a1);
  a0=(a0-a7);
  a0=(-a0);
  if (res[1]!=0) res[1][10]=a0;
  a5=(a5/a7);
  a5=(a5/a2);
  a8=(a8*a5);
  a20=(a20/a14);
  a20=(a20/a7);
  a9=(a9*a20);
  a8=(a8+a9);
  a12=(a12*a8);
  a12=(-a12);
  if (res[1]!=0) res[1][11]=a12;
  a12=-1.;
  if (res[1]!=0) res[1][12]=a12;
  a8=sin(a13);
  a8=(a7*a8);
  a9=cos(a13);
  a9=(a4*a9);
  a8=(a8+a9);
  if (res[1]!=0) res[1][13]=a8;
  a8=cos(a13);
  a7=(a7*a8);
  a13=sin(a13);
  a4=(a4*a13);
  a7=(a7-a4);
  a7=(-a7);
  if (res[1]!=0) res[1][14]=a7;
  a7=-3.1111111111111112e-01;
  if (res[1]!=0) res[1][15]=a7;
  a7=-7.5600000000000001e-01;
  if (res[1]!=0) res[1][16]=a7;
  a7=-1.4814814814814814e-03;
  if (res[1]!=0) res[1][17]=a7;
  if (res[2]!=0) res[2][0]=a21;
  if (res[2]!=0) res[2][1]=a21;
  if (res[2]!=0) res[2][2]=a21;
  if (res[2]!=0) res[2][3]=a21;
  if (res[2]!=0) res[2][4]=a21;
  if (res[2]!=0) res[2][5]=a21;
  if (res[2]!=0) res[2][6]=a21;
  if (res[2]!=0) res[2][7]=a21;
  if (res[3]!=0) res[3][0]=a12;
  if (res[3]!=0) res[3][1]=a12;
  return 0;
}

CASADI_SYMBOL_EXPORT int unicycle_ode_impl_dae_fun_jac_x_xdot_u_z(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_release(int mem) {
}

CASADI_SYMBOL_EXPORT void unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_incref(void) {
}

CASADI_SYMBOL_EXPORT void unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_n_in(void) { return 6;}

CASADI_SYMBOL_EXPORT casadi_int unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_n_out(void) { return 5;}

CASADI_SYMBOL_EXPORT casadi_real unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_default_in(casadi_int i) {
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_name_in(casadi_int i) {
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    case 4: return "i4";
    case 5: return "i5";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_name_out(casadi_int i) {
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    case 2: return "o2";
    case 3: return "o3";
    case 4: return "o4";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s0;
    case 2: return casadi_s1;
    case 3: return casadi_s2;
    case 4: return casadi_s2;
    case 5: return casadi_s2;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s3;
    case 2: return casadi_s4;
    case 3: return casadi_s5;
    case 4: return casadi_s6;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int unicycle_ode_impl_dae_fun_jac_x_xdot_u_z_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 6;
  if (sz_res) *sz_res = 5;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 0;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
