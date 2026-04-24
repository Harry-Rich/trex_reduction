/* Automatically generated file. Do not edit. 
 * Format:     ANSI C source code
 * Creator:    McStas <http://www.mcstas.org>
 * Instrument: ISIS_LET_generated.instr (ISIS_LET_generated)
 * Date:       Thu Apr 23 15:42:18 2026
 * File:       ./ISIS_LET_generated.c
 * CFLAGS=
 */

#ifndef WIN32
#  ifndef OPENACC
#    define _GNU_SOURCE
#  endif
#  define _POSIX_C_SOURCE 200809L
#endif
/* In case of cl.exe on Windows, supppress warnings about #pragma acc */
#ifdef _MSC_EXTENSIONS
#pragma warning(disable: 4068)
#endif

#define MCCODE_STRING " 3.6.14, git"
#define FLAVOR        "mcstas"
#define FLAVOR_UPPER  "MCSTAS"

#define MC_USE_DEFAULT_MAIN
#define MC_TRACE_ENABLED

#include <string.h>
#include <inttypes.h>

typedef double MCNUM;
typedef struct {MCNUM x, y, z;} Coords;
typedef MCNUM Rotation[3][3];
#define MCCODE_BASE_TYPES

/* available random number generators */
#define _RNG_ALG_MT         1
#define _RNG_ALG_KISS       2
/* selection of random number generator */
#ifndef RNG_ALG
#  define RNG_ALG  _RNG_ALG_KISS
#endif
#if RNG_ALG == _RNG_ALG_MT // MT 
#define randstate_t uint32_t
#elif RNG_ALG == _RNG_ALG_KISS  // KISS
#define randstate_t uint64_t
#endif

#ifndef MC_NUSERVAR
#define MC_NUSERVAR 10
#endif

/* Particle JUMP control logic */
struct particle_logic_struct {
int dummy;
};

struct _struct_particle {
  double x,y,z; /* position [m] */
  double vx,vy,vz; /* velocity [m/s] */
  double sx,sy,sz; /* spin [0-1] */
  int mcgravitation; /* gravity-state */
  void *mcMagnet;    /* precession-state */
  int allow_backprop; /* allow backprop */
  /* Generic Temporaries: */
  /* May be used internally by components e.g. for special */
  /* return-values from functions used in trace, thusreturned via */
  /* particle struct. (Example: Wolter Conics from McStas, silicon slabs.) */
  double _mctmp_a; /* temp a */
  double _mctmp_b; /* temp b */
  double _mctmp_c; /* temp c */
  randstate_t randstate[7];
  double t, p;     /* time, event weight */
  long long _uid;  /* Unique event ID */
  long _index;     /* component index where to send this event */
  long _absorbed;  /* flag set to TRUE when this event is to be removed/ignored */
  long _scattered; /* flag set to TRUE when this event has interacted with the last component instance */
  long _restore;   /* set to true if neutron event must be restored */
  long flag_nocoordschange;   /* set to true if particle is jumping */
  struct particle_logic_struct _logic;
};
typedef struct _struct_particle _class_particle;

_class_particle _particle_global_randnbuse_var;
_class_particle* _particle = &_particle_global_randnbuse_var;

#pragma acc routine
_class_particle mcgenstate(void);
#pragma acc routine
_class_particle mcsetstate(double x, double y, double z, double vx, double vy, double vz,
			   double t, double sx, double sy, double sz, double p, int mcgravitation, void *mcMagnet, int mcallowbackprop);
#pragma acc routine
_class_particle mcgetstate(_class_particle mcneutron, double *x, double *y, double *z,
                           double *vx, double *vy, double *vz, double *t,
                           double *sx, double *sy, double *sz, double *p);

extern int mcgravitation;      /* flag to enable gravitation */
#pragma acc declare create ( mcgravitation )

_class_particle mcgenstate(void) {
  _class_particle particle = mcsetstate(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, mcgravitation, NULL, 0);
  return(particle);
}
/*Generated user variable handlers:*/

#pragma acc routine
double particle_getvar(_class_particle *p, char *name, int *suc);

#ifdef OPENACC
#pragma acc routine
int str_comp(char *str1, char *str2);
#endif

double particle_getvar(_class_particle *p, char *name, int *suc){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int s=1;
  double rval=0;
  if(!str_comp("x",name)){rval=p->x;s=0;}
  if(!str_comp("y",name)){rval=p->y;s=0;}
  if(!str_comp("z",name)){rval=p->z;s=0;}
  if(!str_comp("vx",name)){rval=p->vx;s=0;}
  if(!str_comp("vy",name)){rval=p->vy;s=0;}
  if(!str_comp("vz",name)){rval=p->vz;s=0;}
  if(!str_comp("sx",name)){rval=p->sx;s=0;}
  if(!str_comp("sy",name)){rval=p->sy;s=0;}
  if(!str_comp("sz",name)){rval=p->sz;s=0;}
  if(!str_comp("t",name)){rval=p->t;s=0;}
  if(!str_comp("p",name)){rval=p->p;s=0;}
  if(!str_comp("_mctmp_a",name)){rval=p->_mctmp_a;s=0;}
  if(!str_comp("_mctmp_b",name)){rval=p->_mctmp_b;s=0;}
  if(!str_comp("_mctmp_c",name)){rval=p->_mctmp_c;s=0;}
  if (suc!=0x0) {*suc=s;}
  return rval;
}

#pragma acc routine
void* particle_getvar_void(_class_particle *p, char *name, int *suc);

#ifdef OPENACC
#pragma acc routine
int str_comp(char *str1, char *str2);
#endif

void* particle_getvar_void(_class_particle *p, char *name, int *suc){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int s=1;
  void* rval=0;
  if(!str_comp("x",name)) {rval=(void*)&(p->x); s=0;}
  if(!str_comp("y",name)) {rval=(void*)&(p->y); s=0;}
  if(!str_comp("z",name)) {rval=(void*)&(p->z); s=0;}
  if(!str_comp("vx",name)){rval=(void*)&(p->vx);s=0;}
  if(!str_comp("vy",name)){rval=(void*)&(p->vy);s=0;}
  if(!str_comp("vz",name)){rval=(void*)&(p->vz);s=0;}
  if(!str_comp("sx",name)){rval=(void*)&(p->sx);s=0;}
  if(!str_comp("sy",name)){rval=(void*)&(p->sy);s=0;}
  if(!str_comp("sz",name)){rval=(void*)&(p->sz);s=0;}
  if(!str_comp("t",name)) {rval=(void*)&(p->t); s=0;}
  if(!str_comp("p",name)) {rval=(void*)&(p->p); s=0;}
  if (suc!=0x0) {*suc=s;}
  return rval;
}

#pragma acc routine
int particle_setvar_void(_class_particle *, char *, void*);

int particle_setvar_void(_class_particle *p, char *name, void* value){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int rval=1;
  if(!str_comp("x",name)) {memcpy(&(p->x),  value, sizeof(double)); rval=0;}
  if(!str_comp("y",name)) {memcpy(&(p->y),  value, sizeof(double)); rval=0;}
  if(!str_comp("z",name)) {memcpy(&(p->z),  value, sizeof(double)); rval=0;}
  if(!str_comp("vx",name)){memcpy(&(p->vx), value, sizeof(double)); rval=0;}
  if(!str_comp("vy",name)){memcpy(&(p->vy), value, sizeof(double)); rval=0;}
  if(!str_comp("vz",name)){memcpy(&(p->vz), value, sizeof(double)); rval=0;}
  if(!str_comp("sx",name)){memcpy(&(p->sx), value, sizeof(double)); rval=0;}
  if(!str_comp("sy",name)){memcpy(&(p->sy), value, sizeof(double)); rval=0;}
  if(!str_comp("sz",name)){memcpy(&(p->sz), value, sizeof(double)); rval=0;}
  if(!str_comp("p",name)) {memcpy(&(p->p),  value, sizeof(double)); rval=0;}
  if(!str_comp("t",name)) {memcpy(&(p->t),  value, sizeof(double)); rval=0;}
  return rval;
}

#pragma acc routine
int particle_setvar_void_array(_class_particle *, char *, void*, int);

int particle_setvar_void_array(_class_particle *p, char *name, void* value, int elements){
#ifndef OPENACC
#define str_comp strcmp
#endif
  int rval=1;
  return rval;
}

#pragma acc routine
void particle_restore(_class_particle *p, _class_particle *p0);

void particle_restore(_class_particle *p, _class_particle *p0) {
  p->x  = p0->x;  p->y  = p0->y;  p->z  = p0->z;
  p->vx = p0->vx; p->vy = p0->vy; p->vz = p0->vz;
  p->sx = p0->sx; p->sy = p0->sy; p->sz = p0->sz;
  p->t = p0->t;  p->p  = p0->p;
  p->_absorbed=0; p->_restore=0;
}

#pragma acc routine
double particle_getuservar_byid(_class_particle *p, int id, int *suc){
  int s=1;
  double rval=0;
  switch(id){
  }
  if (suc!=0x0) {*suc=s;}
  return rval;
}

#pragma acc routine
void particle_uservar_init(_class_particle *p){
}

#define MC_EMBEDDED_RUNTIME
/* embedding file "mccode-r.h" */

/*******************************************************************************
*
* McCode, neutron/xray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mccode-r.h
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: mcstas 3.6.14
* Version: $Revision$
*
* Runtime system header for McStas/McXtrace.
*
* In order to use this library as an external library, the following variables
* and macros must be declared (see details in the code)
*
*   struct mcinputtable_struct mcinputtable[];
*   int numipar;
*   metadata_table_t metadata_table[];
*   int num_metadata;
*   char instrument_name[], instrument_source[];
*   int traceenabled, defaultmain;
*   extern MCNUM  mccomp_storein[];
*   extern MCNUM  mcAbsorbProp[];
*   extern MCNUM  mcScattered;
*   #define MCCODE_STRING "the McStas/McXtrace version"
*
* Usage: Automatically embbeded in the c code.
*
* $Id$
*
*******************************************************************************/

#ifndef MCCODE_R_H
#define MCCODE_R_H "$Revision$"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#ifndef _MSC_EXTENSIONS
#include <sys/time.h>
#endif
#include <float.h>
#include <inttypes.h>
#include <stdint.h>
#ifdef OPENACC
#include <openacc.h>
#ifndef GCCOFFLOAD
#include <accelmath.h>
#else
#include <math.h>
#endif
#pragma acc routine
int noprintf();
#pragma acc routine
size_t str_len(const char *s);
#else
#include <math.h>
#endif

/* In case of gcc / clang, ensure to use
   the built-in isnan/isinf functions */
#if defined(__GNUC__) || defined(__clang__)
#  ifdef isnan
#    undef isnan
#  endif
#  ifdef isinf
#    undef isinf
#  endif
#  define isnan(x) __builtin_isnan(x)
#  define isinf(x) __builtin_isinf(x)
#endif

#ifdef _MSC_EXTENSIONS
#ifndef _TIMES_H
#define _TIMES_H

#if defined(WIN32) || defined(_WIN32)
#include <sys/timeb.h>
#include <sys/types.h>
#include <winsock2.h>

int gettimeofday(struct timeval* t,void* timezone);

#define __need_clock_t
#include <time.h>


/* Structure describing CPU time used by a process and its children.  */
struct tms
  {
    clock_t tms_utime;          /* User CPU time.  */
    clock_t tms_stime;          /* System CPU time.  */

    clock_t tms_cutime;         /* User CPU time of dead children.  */
    clock_t tms_cstime;         /* System CPU time of dead children.  */
  };

/* Store the CPU time used by this process and all its
   dead children (and their dead children) in BUFFER.
   Return the elapsed real time, or (clock_t) -1 for errors.
   All times are in CLK_TCKths of a second.  */
clock_t times (struct tms *__buffer);

typedef long long suseconds_t ;



int gettimeofday(struct timeval* t,void* timezone)
{       struct _timeb timebuffer;
        _ftime( &timebuffer );
        t->tv_sec=timebuffer.time;
        t->tv_usec=1000*timebuffer.millitm;
		return 0;
}

clock_t times (struct tms *__buffer) {

	__buffer->tms_utime = clock();
	__buffer->tms_stime = 0;
	__buffer->tms_cstime = 0;
	__buffer->tms_cutime = 0;
	return __buffer->tms_utime;
}


#endif
#endif
#endif

/* If the runtime is embedded in the simulation program, some definitions can
   be made static. */

#ifdef MC_EMBEDDED_RUNTIME
#  define mcstatic
#else
#  define mcstatic
#endif

#ifdef __dest_os
#  if (__dest_os == __mac_os)
#    define MAC
#  endif
#endif

#ifdef __FreeBSD__
#  define NEED_STAT_H
#endif

#if defined(__APPLE__) && defined(__GNUC__)
#  define NEED_STAT_H
#endif

#if defined(WIN32) || defined(_WIN32)
#  define NEED_STAT_H
#  define NEED_TYPES_H
#endif

#ifdef NEED_STAT_H
#  include <sys/stat.h>
#endif

#ifdef NEED_TYPES_H
#  include <sys/types.h>
#endif

#ifndef MC_PATHSEP_C
#if defined(WIN32) || defined(_WIN32)
#    define MC_PATHSEP_C '\\'
#    define MC_PATHSEP_S "\\"
#  else  /* !WIN32 */
#    define MC_PATHSEP_C '/'
#    define MC_PATHSEP_S "/"
#  endif /* !WIN32 */
#endif /* MC_PATHSEP_C */

#if defined(WIN32) || defined(_WIN32)
#if defined _MSC_VER
#include <direct.h>
#elif defined __GNUC__
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#define mkdir(a,b) mkdir(a)
#define getpid() _getpid()
#endif

/* the version string is replaced when building distribution with mkdist */
#ifndef MCCODE_STRING
#  define MCCODE_STRING " 3.6.14, git"
#endif

#ifndef MCCODE_DATE
#  define MCCODE_DATE "git"
#endif

#ifndef MCCODE_VERSION
#  define MCCODE_VERSION "3.6.14"
#endif

#ifndef __MCCODE_VERSION__
#define __MCCODE_VERSION__ 306014L
#endif

#ifndef MCCODE_NAME
#  define MCCODE_NAME "mcstas"
#endif

#ifndef MCCODE_PARTICLE
#  define MCCODE_PARTICLE "neutron"
#endif

#ifndef MCCODE_PARTICLE_CODE
#  define MCCODE_PARTICLE_CODE 2112
#endif

#ifndef MCCODE_LIBENV
#  define MCCODE_LIBENV "MCSTAS"
#endif

#ifndef FLAVOR_UPPER
#  define FLAVOR_UPPER MCCODE_NAME
#endif

#ifdef MC_PORTABLE
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#ifdef MAC
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#if (USE_MPI == 0)
#  undef USE_MPI
#endif

#ifdef USE_MPI  /* default is to disable signals with MPI, as MPICH uses them to communicate */
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#ifdef OPENACC  /* default is to disable signals with PGI/OpenACC */
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#ifndef OPENACC
#  ifndef USE_OFF  /* default is to enable OFF when not using PGI/OpenACC */
#    define USE_OFF
#  endif
#  ifndef CPUFUNNEL  /* allow to enable FUNNEL-mode on CPU */
#  ifdef FUNNEL      /* by default disable FUNNEL-mode when not using PGI/OpenACC */
#    undef FUNNEL
#  endif
#  endif
#endif

#if (NOSIGNALS == 0)
#  undef NOSIGNALS
#endif

/** Header information for metadata-r.c ----------------------------------------------------------------------------- */
struct metadata_table_struct { /* stores metadata strings from components */
  char * source;  // component name which provided the metadata
  char * name;    // the name of the metadata
  char * type;    // the MIME type of the metadata (free form, valid identifier)
  char * value;   // the metadata string contents
};
typedef struct metadata_table_struct metadata_table_t;
char * metadata_table_key_component(char* key);
char * metadata_table_key_literal(char * key);
int metadata_table_defined(int, metadata_table_t *, char *);
char * metadata_table_name(int, metadata_table_t *, char *);
char * metadata_table_type(int, metadata_table_t *, char *);
char * metadata_table_literal(int, metadata_table_t *, char *);
void metadata_table_print_all_keys(int no, metadata_table_t * tab);
int metadata_table_print_all_components(int no, metadata_table_t * tab);
int metadata_table_print_component_keys(int no, metadata_table_t * tab, char * key);
/* -------------------------------------------------------------------------- Header information for metadata-r.c --- */

/* Note: the enum instr_formal_types definition MUST be kept
   synchronized with the one in mccode.h and with the
   instr_formal_type_names array in cogen.c. */
enum instr_formal_types
  {
    instr_type_int,
    instr_type_string, instr_type_char,
    instr_type_vector, instr_type_double
  };
struct mcinputtable_struct { /* defines instrument parameters */
  char *name; /* name of parameter */
  void *par;  /* pointer to instrument parameter (variable) */
  enum instr_formal_types type;
  char *val;  /* default value */
  char *unit; /* expected unit for parameter; informational only */
};


#ifndef MCCODE_BASE_TYPES
typedef double MCNUM;
typedef struct {MCNUM x, y, z;} Coords;
typedef MCNUM Rotation[3][3];
#endif

/* the following variables are defined in the McStas generated C code
   but should be defined externally in case of independent library usage */
#ifndef DANSE
extern struct mcinputtable_struct mcinputtable[];         /* list of instrument parameters */
extern int    numipar;                                    /* number of instrument parameters */
extern metadata_table_t metadata_table[];                 /* list of component-defined string metadata */
extern int    num_metadata;                               /* number of component-defined string metadata */
extern char   instrument_name[], instrument_source[]; /* instrument name and filename */
extern char  *instrument_exe;                           /* executable path = argv[0] or NULL */
extern char   instrument_code[];                        /* contains the initial 'instr' file */

#ifndef MC_ANCIENT_COMPATIBILITY
extern int traceenabled, defaultmain;
#endif
#endif


/* Useful macros ============================================================ */


/* SECTION: Dynamic Arrays */
typedef int* IArray1d;
IArray1d create_iarr1d(int n);
void destroy_iarr1d(IArray1d a);

typedef int** IArray2d;
IArray2d create_iarr2d(int nx, int ny);
void destroy_iarr2d(IArray2d a);

typedef int*** IArray3d;
IArray3d create_iarr3d(int nx, int ny, int nz);
void destroy_iarr3d(IArray3d a);

typedef double* DArray1d;
DArray1d create_darr1d(int n);
void destroy_darr1d(DArray1d a);

typedef double** DArray2d;
DArray2d create_darr2d(int nx, int ny);
void destroy_darr2d(DArray2d a);

typedef double*** DArray3d;
DArray3d create_darr3d(int nx, int ny, int nz);
void destroy_darr3d(DArray3d a);


/* MPI stuff */
#ifdef USE_MPI
#include "mpi.h"

#ifdef OMPI_MPI_H  /* openmpi does not use signals: we may install our sighandler */
#ifndef OPENACC    /* ... but only if we are not also running on GPU */
#undef NOSIGNALS
#endif
#endif

/*
 * MPI_MASTER(i):
 * execution of i only on master node
 */
#define MPI_MASTER(statement) { \
  if(mpi_node_rank == mpi_node_root)\
  { statement; } \
}

#ifndef MPI_REDUCE_BLOCKSIZE
#define MPI_REDUCE_BLOCKSIZE 100000
#endif

int mc_MPI_Sum(double* buf, long count);
int mc_MPI_Send(void *sbuf, long count, MPI_Datatype dtype, int dest);
int mc_MPI_Recv(void *rbuf, long count, MPI_Datatype dtype, int source);

/* MPI_Finalize exits gracefully and should be preferred to MPI_Abort */
#define exit(code) do {                                   \
    MPI_Finalize();                                       \
    exit(code);                                           \
  } while(0)

#else /* !USE_MPI */
#define MPI_MASTER(instr) instr
#endif /* USE_MPI */


#ifdef USE_MPI
static int mpi_node_count;
#endif

#ifdef USE_THREADS  /* user want threads */
#error Threading (USE_THREADS) support has been removed for very poor efficiency. Use MPI/SSH grid instead.
#endif


void   mcset_ncount(unsigned long long count);    /* wrapper to get mcncount */
#pragma acc routine
unsigned long long int mcget_ncount(void);            /* wrapper to set mcncount */
unsigned long long mcget_run_num(void);           /* wrapper to get mcrun_num=0:mcncount-1 */

/* Following part is only embedded when not redundant with mccode.h ========= */

#ifndef MCCODE_H

#ifndef NOSIGNALS
#include <signal.h>
char  *mcsig_message;
#define SIG_MESSAGE(msg) mcsig_message=(char *)(msg);
#else
#define SIG_MESSAGE(...)
#endif /* !NOSIGNALS */


/* Useful macros and constants ============================================== */


#ifndef FLT_MAX
#define FLT_MAX         3.40282347E+38F /* max decimal value of a "float" */
#endif

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef SQR
#define SQR(x) ( (x) * (x) )
#endif
#ifndef SIGN
#define SIGN(x) (((x)>0.0)?(1):(-1))
#endif


#  ifndef M_E
#    define M_E        2.71828182845904523536  // e
#  endif
#  ifndef M_LOG2E
#    define M_LOG2E    1.44269504088896340736  //  log2(e)
#  endif
#  ifndef M_LOG10E
#    define M_LOG10E   0.434294481903251827651 //  log10(e)
#  endif
#  ifndef M_LN2
#    define M_LN2      0.693147180559945309417 //  ln(2)
#  endif
#  ifndef M_LN10
#    define M_LN10     2.30258509299404568402  //  ln(10)
#  endif
#  ifndef M_PI
#    define M_PI       3.14159265358979323846  //  pi
#  endif
#  ifndef PI
#    define PI       M_PI                      //  pi - also used in some places
#  endif
#  ifndef M_PI_2
#    define M_PI_2     1.57079632679489661923  //  pi/2
#  endif
#  ifndef M_PI_4
#    define M_PI_4     0.785398163397448309616 //  pi/4
#  endif
#  ifndef M_1_PI
#    define M_1_PI     0.318309886183790671538 //  1/pi
#  endif
#  ifndef M_2_PI
#    define M_2_PI     0.636619772367581343076 //  2/pi
#  endif
#  ifndef M_2_SQRTPI
#    define M_2_SQRTPI 1.12837916709551257390  //  2/sqrt(pi)
#  endif
#  ifndef M_SQRT2
#    define M_SQRT2    1.41421356237309504880  //  sqrt(2)
#  endif
#  ifndef M_SQRT1_2
#    define M_SQRT1_2  0.707106781186547524401 //  1/sqrt(2)
#  endif

#define RAD2MIN  ((180*60)/PI)
#define MIN2RAD  (PI/(180*60))
#define DEG2RAD  (PI/180)
#define RAD2DEG  (180/PI)
#define FWHM2RMS 0.424660900144    /* Convert between full-width-half-max and */
#define RMS2FWHM 2.35482004503     /* root-mean-square (standard deviation) */
#define HBAR     1.05457168e-34    /* [Js] h bar Planck constant CODATA 2002 */
#define MNEUTRON 1.67492728e-27    /* [kg] mass of neutron CODATA 2002 */
#define GRAVITY  9.81              /* [m/s^2] gravitational acceleration */
#define NA       6.02214179e23     /* [#atoms/g .mole] Avogadro's number*/


#define UNSET nan("0x6E6F74736574")
int nans_match(double, double);
int is_unset(double);
int is_valid(double);
int is_set(double);
int all_unset(int n, ...);
int all_set(int n, ...);
int any_unset(int n, ...);
int any_set(int n, ...);


/* wrapper to get absolute and relative position of comp */
/* mccomp_posa and mccomp_posr are defined in McStas generated C code */
#define POS_A_COMP_INDEX(index) (instrument->_position_absolute[index])
#define POS_R_COMP_INDEX(index) (instrument->_position_relative[index])

/* setting parameters based COMP_GETPAR (returned as pointer)         */
/* compname must be given as a string, type and par are symbols.      */
#define COMP_GETPAR3(type, compname, par) \
    &( ((_class_ ## type ##_parameters *) _getvar_parameters(compname))->par )
/* the body of this function depends on component instances, and is cogen'd */
void* _getvar_parameters(char* compname);

int _getcomp_index(char* compname);

/* Note: The two-stage approach to COMP_GETPAR is NOT redundant; without it,
* after #define C sample, COMP_GETPAR(C,x) would refer to component C, not to
* component sample. Such are the joys of ANSI C.

* Anyway the usage of COMP_GETPAR requires that we use sometimes bare names...
* NOTE: This can ONLY be used in instrument descriptions, not components.
*/
#define COMP_GETPAR2(comp, par) (_ ## comp ## _var._parameters.par)
#define COMP_GETPAR(comp, par) COMP_GETPAR2(comp,par)

#define INSTRUMENT_GETPAR(par) (_instrument_var._parameters.par)

/* Current component name, index, position and orientation */
/* These macros work because, using class-based functions, "comp" is usually
*  the local variable of the active/current component. */
#define INDEX_CURRENT_COMP (_comp->_index)
#define NAME_CURRENT_COMP (_comp->_name)
#define TYPE_CURRENT_COMP (_comp->_type)
#define POS_A_CURRENT_COMP (_comp->_position_absolute)
#define POS_R_CURRENT_COMP (_comp->_position_relative)
#define ROT_A_CURRENT_COMP (_comp->_rotation_absolute)
#define ROT_R_CURRENT_COMP (_comp->_rotation_relative)

#define NAME_INSTRUMENT (instrument->_name)


/* MCDISPLAY/trace and debugging message sent to stdout */
#ifdef MC_TRACE_ENABLED
#define DEBUG
#endif

#ifdef DEBUG
#define DEBUG_INSTR() if(!mcdotrace); else { printf("INSTRUMENT:\n"); printf("Instrument '%s' (%s)\n", instrument_name, instrument_source); }
#define DEBUG_COMPONENT(name,c,t) if(!mcdotrace); else {\
     printf("COMPONENT: \"%s\"\n"					  \
     "POS: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
     name, c.x, c.y, c.z, t[0][0], t[0][1], t[0][2], \
     t[1][0], t[1][1], t[1][2], t[2][0], t[2][1], t[2][2]); \
     printf("Component %30s AT (%g,%g,%g)\n", name, c.x, c.y, c.z); }
#define DEBUG_INSTR_END() if(!mcdotrace); else printf("INSTRUMENT END:\n");
#define DEBUG_ENTER() if(!mcdotrace); else printf("ENTER:\n");
#define DEBUG_COMP(c) if(!mcdotrace); else printf("COMP: \"%s\"\n", c);
#define DEBUG_LEAVE() if(!mcdotrace); else printf("LEAVE:\n");
#define DEBUG_ABSORB() if(!mcdotrace); else printf("ABSORB:\n");
#else
#define DEBUG_INSTR()
#define DEBUG_COMPONENT(name,c,t)
#define DEBUG_INSTR_END()
#define DEBUG_ENTER()
#define DEBUG_COMP(c)
#define DEBUG_LEAVE()
#define DEBUG_ABSORB()
#endif

// mcDEBUG_STATE and mcDEBUG_SCATTER are defined by mcstas-r.h and mcxtrace-r.h



#ifdef TEST
#define test_printf printf
#else
#define test_printf while(0) printf
#endif

/* send MCDISPLAY message to stdout to show gemoetry */
void mcdis_magnify(char *what);
void mcdis_line(double x1, double y1, double z1,
                double x2, double y2, double z2);
void mcdis_dashed_line(double x1, double y1, double z1,
		       double x2, double y2, double z2, int n);
void mcdis_multiline(int count, ...);
void mcdis_rectangle(char* plane, double x, double y, double z,
		     double width, double height);
void mcdis_box(double x, double y, double z,
	       double width, double height, double length, double thickness, double nx, double ny, double nz);
void mcdis_circle(char *plane, double x, double y, double z, double r);
void mcdis_Circle(double x, double y, double z, double r, double nx, double ny, double nz);
void mcdis_cylinder( double x, double y, double z,
		     double r, double height, double thickness, double nx, double ny, double nz);
void mcdis_cone( double x, double y, double z,
        double r, double height, double nx, double ny, double nz);
void mcdis_sphere(double x, double y, double z, double r);


/* random number generation. ================================================ */

#if RNG_ALG == _RNG_ALG_MT  // MT (currently not functional for GPU)
#  define MC_RAND_MAX ((uint32_t)0xffffffffUL)
#  define RANDSTATE_LEN 1
#  define srandom(seed) mt_srandom_empty()
#  define random() mt_random()
#  define _random() mt_random()
#elif RNG_ALG == _RNG_ALG_KISS  // KISS
#  ifndef UINT64_MAX
#    define UINT64_MAX ((uint64_t)0xffffffffffffffffULL)
#  endif
#  define MC_RAND_MAX UINT64_MAX
#  define RANDSTATE_LEN 7
#  define srandom(seed) kiss_srandom(_particle->randstate, seed)
#  define random() kiss_random(_particle->randstate)
#  define _random() kiss_random(state)
#endif

#pragma acc routine
double _randnorm2(randstate_t* state);

// Component writer interface
#define randnorm() _randnorm2(_particle->randstate)        // NOTE: can't use _randnorm on GPU
#define rand01() _rand01(_particle->randstate)
#define randpm1() _randpm1(_particle->randstate)
#define rand0max(p1) _rand0max(p1, _particle->randstate)
#define randminmax(p1, p2) _randminmax(p1, p2, _particle->randstate)
#define randtriangle() _randtriangle(_particle->randstate)

// Mersenne Twister rng
uint32_t mt_random(void);
void mt_srandom (uint32_t x);
void mt_srandom_empty();

// KISS rng
#pragma acc routine
uint64_t *kiss_srandom(uint64_t state[7], uint64_t seed);
#pragma acc routine
uint64_t kiss_random(uint64_t state[7]);

// Scrambler / hash function
#pragma acc routine seq
randstate_t _hash(randstate_t x);

// internal RNG (transforms) interface
#pragma acc routine
double _rand01(randstate_t* state);
#pragma acc routine
double _randpm1(randstate_t* state);
#pragma acc routine
double _rand0max(double max, randstate_t* state);
#pragma acc routine
double _randminmax(double min, double max, randstate_t* state);
#pragma acc routine
double _randtriangle(randstate_t* state);


#ifdef USE_OPENCL
#include "opencl-lib.h"
#include "opencl-lib.c"
#endif

#ifndef DANSE
int init(void);
int raytrace(_class_particle*);
int save(FILE *);
int finally(void);
int display(void);
#endif


/* GPU related algorithms =================================================== */

/*
*  Divide-and-conquer strategy for parallel sort absorbed last.
*/
#ifdef FUNNEL
long sort_absorb_last(_class_particle* particles, _class_particle* pbuffer, long len, long buffer_len, long flag_split, long* multiplier);
#endif
long sort_absorb_last_serial(_class_particle* particles, long len);


/* simple vector algebra ==================================================== */


#define vec_prod(x, y, z, x1, y1, z1, x2, y2, z2) \
	vec_prod_func(&x, &y, &z, x1, y1, z1, x2, y2, z2)
#pragma acc routine seq
mcstatic void vec_prod_func(double *x, double *y, double *z,
		double x1, double y1, double z1, double x2, double y2, double z2);

#pragma acc routine seq
mcstatic double scalar_prod(
		double x1, double y1, double z1, double x2, double y2, double z2);

#pragma acc routine seq
mcstatic void norm_func(double *x, double *y, double *z);
#define NORM(x,y,z)	norm_func(&x, &y, &z)

#pragma acc routine seq
void normal_vec(double *nx, double *ny, double *nz,
    double x, double y, double z);

/**
 * Rotate the vector vx,vy,vz psi radians around the vector ax,ay,az
 * and put the result in x,y,z.
 */
#define rotate(x, y, z, vx, vy, vz, phi, ax, ay, az) \
  do { \
    double mcrt_tmpx = (ax), mcrt_tmpy = (ay), mcrt_tmpz = (az); \
    double mcrt_vp, mcrt_vpx, mcrt_vpy, mcrt_vpz; \
    double mcrt_vnx, mcrt_vny, mcrt_vnz, mcrt_vn1x, mcrt_vn1y, mcrt_vn1z; \
    double mcrt_bx, mcrt_by, mcrt_bz; \
    double mcrt_cos, mcrt_sin; \
    NORM(mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_vp = scalar_prod((vx), (vy), (vz), mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_vpx = mcrt_vp*mcrt_tmpx; \
    mcrt_vpy = mcrt_vp*mcrt_tmpy; \
    mcrt_vpz = mcrt_vp*mcrt_tmpz; \
    mcrt_vnx = (vx) - mcrt_vpx; \
    mcrt_vny = (vy) - mcrt_vpy; \
    mcrt_vnz = (vz) - mcrt_vpz; \
    vec_prod(mcrt_bx, mcrt_by, mcrt_bz, \
             mcrt_tmpx, mcrt_tmpy, mcrt_tmpz, mcrt_vnx, mcrt_vny, mcrt_vnz); \
    mcrt_cos = cos((phi)); mcrt_sin = sin((phi)); \
    mcrt_vn1x = mcrt_vnx*mcrt_cos + mcrt_bx*mcrt_sin; \
    mcrt_vn1y = mcrt_vny*mcrt_cos + mcrt_by*mcrt_sin; \
    mcrt_vn1z = mcrt_vnz*mcrt_cos + mcrt_bz*mcrt_sin; \
    (x) = mcrt_vpx + mcrt_vn1x; \
    (y) = mcrt_vpy + mcrt_vn1y; \
    (z) = mcrt_vpz + mcrt_vn1z; \
  } while(0)

/**
 * Mirror (xyz) in the plane given by the point (rx,ry,rz) and normal (nx,ny,nz)
 *
 * TODO: This define is seemingly never used...
 */
#define mirror(x,y,z,rx,ry,rz,nx,ny,nz) \
  do { \
    double mcrt_tmpx= (nx), mcrt_tmpy = (ny), mcrt_tmpz = (nz); \
    double mcrt_tmpt; \
    NORM(mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_tmpt=scalar_prod((rx),(ry),(rz),mcrt_tmpx,mcrt_tmpy,mcrt_tmpz); \
    (x) = rx -2 * mcrt_tmpt*mcrt_rmpx; \
    (y) = ry -2 * mcrt_tmpt*mcrt_rmpy; \
    (z) = rz -2 * mcrt_tmpt*mcrt_rmpz; \
  } while (0)

#pragma acc routine
Coords coords_set(MCNUM x, MCNUM y, MCNUM z);
#pragma acc routine
Coords coords_get(Coords a, MCNUM *x, MCNUM *y, MCNUM *z);
#pragma acc routine
Coords coords_add(Coords a, Coords b);
#pragma acc routine
Coords coords_sub(Coords a, Coords b);
#pragma acc routine
Coords coords_neg(Coords a);
#pragma acc routine
Coords coords_scale(Coords b, double scale);
#pragma acc routine
double coords_sp(Coords a, Coords b);
#pragma acc routine
Coords coords_xp(Coords b, Coords c);
#pragma acc routine
double coords_len(Coords a);
#pragma acc routine seq
void   coords_print(Coords a);
#pragma acc routine seq
mcstatic void coords_norm(Coords* c);

#pragma acc routine seq
void rot_set_rotation(Rotation t, double phx, double phy, double phz);
#pragma acc routine seq
int  rot_test_identity(Rotation t);
#pragma acc routine seq
void rot_mul(Rotation t1, Rotation t2, Rotation t3);
#pragma acc routine seq
void rot_copy(Rotation dest, Rotation src);
#pragma acc routine seq
void rot_transpose(Rotation src, Rotation dst);
#pragma acc routine seq
Coords rot_apply(Rotation t, Coords a);

#pragma acc routine seq
void mccoordschange(Coords a, Rotation t, _class_particle *particle);
#pragma acc routine seq
void mccoordschange_polarisation(Rotation t, double *sx, double *sy, double *sz);

double mcestimate_error(double N, double p1, double p2);
void mcreadparams(void);

/* this is now in mcstas-r.h and mcxtrace-r.h as the number of state parameters
is no longer equal */

_class_particle mcgenstate(void);

// trajectory/shape intersection routines
#pragma acc routine seq
int inside_rectangle(double, double, double, double);
#pragma acc routine seq
int box_intersect(double *dt_in, double *dt_out, double x, double y, double z,
      double vx, double vy, double vz, double dx, double dy, double dz);
#pragma acc routine seq
int cylinder_intersect(double *t0, double *t1, double x, double y, double z,
      double vx, double vy, double vz, double r, double h);
#pragma acc routine seq
int sphere_intersect(double *t0, double *t1, double x, double y, double z,
      double vx, double vy, double vz, double r);
// second order equation roots
#pragma acc routine seq
int solve_2nd_order(double *t1, double *t2,
      double A,  double B,  double C);

// random vector generation to shape
// defines silently introducing _particle as the last argument
#define randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, radius) \
  _randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, radius, _particle)
#define randvec_target_rect_angular(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A) \
  _randvec_target_rect_angular(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, _particle)
#define randvec_target_rect_real(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, lx, ly, lz, order) \
  _randvec_target_rect_real(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, lx, ly, lz, order, _particle)
// defines forwarding to "inner" functions
#define randvec_target_sphere randvec_target_circle
#define randvec_target_rect(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9) \
  randvec_target_rect_real(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,0,0,0,1)
// headers for randvec
#pragma acc routine seq
void _randvec_target_circle(double *xo, double *yo, double *zo,
  double *solid_angle, double xi, double yi, double zi, double radius,
  _class_particle* _particle);
#pragma acc routine seq
void _randvec_target_rect_angular(double *xo, double *yo, double *zo,
  double *solid_angle, double xi, double yi, double zi, double height,
  double width, Rotation A,
  _class_particle* _particle);
#pragma acc routine seq
void _randvec_target_rect_real(double *xo, double *yo, double *zo, double *solid_angle,
  double xi, double yi, double zi, double height, double width, Rotation A,
  double lx, double ly, double lz, int order,
  _class_particle* _particle);


// this is the main()
int mccode_main(int argc, char *argv[]);


#endif /* !MCCODE_H */

#ifndef MCCODE_R_IO_H
#define MCCODE_R_IO_H "$Revision$"

#if (USE_NEXUS == 0)
#undef USE_NEXUS
#endif

#ifndef CHAR_BUF_LENGTH
#define CHAR_BUF_LENGTH 1024
#endif


/* I/O section part ========================================================= */

/* ========================================================================== */

/*                               MCCODE_R_IO_C                                */

/* ========================================================================== */


/* main DETECTOR structure which stores most information to write to data files */
struct mcdetector_struct {
  char   filename[CHAR_BUF_LENGTH];   /* file name of monitor */
  double Position[3];                 /* position of detector component*/
  char   position[CHAR_BUF_LENGTH];   /* position of detector component (string)*/
  Rotation Rotation;                  /* position of detector component*/
  char   options[CHAR_BUF_LENGTH];    /* Monitor_nD style list-mode'options' (string)*/
  char   component[CHAR_BUF_LENGTH];  /* component instance name */
  char   nexuscomp[CHAR_BUF_LENGTH];  /* component naming in NeXus/HDF case */
  char   instrument[CHAR_BUF_LENGTH]; /* instrument name */
  char   type[CHAR_BUF_LENGTH];       /* data type, e.g. 0d, 1d, 2d, 3d */
  char   user[CHAR_BUF_LENGTH];       /* user name, e.g. HOME */
  char   date[CHAR_BUF_LENGTH];       /* date of simulation end/write time */
  char   title[CHAR_BUF_LENGTH];      /* title of detector */
  char   xlabel[CHAR_BUF_LENGTH];     /* X axis label */
  char   ylabel[CHAR_BUF_LENGTH];     /* Y axis label */
  char   zlabel[CHAR_BUF_LENGTH];     /* Z axis label */
  char   xvar[CHAR_BUF_LENGTH];       /* X variable name */
  char   yvar[CHAR_BUF_LENGTH];       /* Y variable name */
  char   zvar[CHAR_BUF_LENGTH];       /* Z variable name */
  char   ncount[CHAR_BUF_LENGTH];     /* number of events initially generated */
  char   limits[CHAR_BUF_LENGTH];     /* X Y Z limits, e.g. [xmin xmax ymin ymax zmin zmax] */
  char   variables[CHAR_BUF_LENGTH];  /* variables written into data block */
  char   statistics[CHAR_BUF_LENGTH]; /* center, mean and half width along axis */
  char   signal[CHAR_BUF_LENGTH];     /* min max and mean of signal (data block) */
  char   values[CHAR_BUF_LENGTH];     /* integrated values e.g. [I I_err N] */
  double xmin,xmax;                   /* min max of axes */
  double ymin,ymax;
  double zmin,zmax;
  double intensity;                   /* integrated values for data block */
  double error;
  double events;
  double min;                         /* statistics for data block */
  double max;
  double mean;
  double centerX;                     /* statistics for axes */
  double halfwidthX;
  double centerY;
  double halfwidthY;
  int    rank;                        /* dimensionaly of monitor, e.g. 0 1 2 3 */
  char   istransposed;                /* flag to transpose matrix for some formats */

  long   m,n,p;                       /* dimensions of data block and along axes */
  long   date_l;                      /* same as date, but in sec since 1970 */

  double *p0, *p1, *p2;               /* pointers to saved data, NULL when freed */
  char   format[CHAR_BUF_LENGTH];    /* format for file generation */
};

typedef struct mcdetector_struct MCDETECTOR;

static   char *dirname             = NULL;      /* name of output directory */
static   char *siminfo_name        = "mccode";  /* default output sim file name */
char    *mcformat                    = NULL;      /* NULL (default) or a specific format */

/* file I/O definitions and function prototypes */

#ifndef MC_EMBEDDED_RUNTIME /* the mcstatic variables (from mccode-r.c) */
extern FILE * siminfo_file;     /* handle to the output siminfo file */
extern int    mcgravitation;      /* flag to enable gravitation */
extern int    mcdotrace;          /* flag to print MCDISPLAY messages */
#else
mcstatic FILE *siminfo_file        = NULL;
#endif

/* I/O function prototypes ================================================== */

// from msysgit: https://code.google.com/p/msysgit/source/browse/compat/strcasestr.c
char *strcasestr(const char *haystack, const char *needle);

/* output functions */
MCDETECTOR mcdetector_out_0D(char *t, double p0, double p1, double p2, char *c, Coords pos, Rotation rot, int index);
MCDETECTOR mcdetector_out_1D(char *t, char *xl, char *yl,
                  char *xvar, double x1, double x2, long n,
                  double *p0, double *p1, double *p2, char *f, char *c, Coords pos, Rotation rot, int index);
MCDETECTOR mcdetector_out_2D(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2, long m,
                  long n, double *p0, double *p1, double *p2, char *f,
                  char *c, Coords pos, Rotation rot, int index);
MCDETECTOR mcdetector_out_list(char *t, char *xl, char *yl,
                  long m, long n,
                  double *p1, char *f,
	          char *c, Coords posa, Rotation rot,char* options, int index);

/* wrappers to output functions, that automatically set NAME and POSITION */
#define DETECTOR_OUT(p0,p1,p2) mcdetector_out_0D(NAME_CURRENT_COMP,p0,p1,p2,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)
#define DETECTOR_OUT_0D(t,p0,p1,p2) mcdetector_out_0D(t,p0,p1,p2,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)
#define DETECTOR_OUT_1D(t,xl,yl,xvar,x1,x2,n,p0,p1,p2,f) \
     mcdetector_out_1D(t,xl,yl,xvar,x1,x2,n,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)
#define DETECTOR_OUT_2D(t,xl,yl,x1,x2,y1,y2,m,n,p0,p1,p2,f) \
     mcdetector_out_2D(t,xl,yl,x1,x2,y1,y2,m,n,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)

#ifdef USE_NEXUS
#include "napi.h"
NXhandle nxhandle;
#endif

#endif /* ndef MCCODE_R_IO_H */

#endif /* MCCODE_R_H */
/* End of file "mccode-r.h". */

/* embedding file "mcstas-r.h" */

/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mcstas-r.h
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y
* Version: $Revision$
*
* Runtime system header for McStas.
*
* In order to use this library as an external library, the following variables
* and macros must be declared (see details in the code)
*
*   struct mcinputtable_struct mcinputtable[];
*   int mcnumipar;
*   char instrument_name[], instrument_source[];
*   int traceenabled, defaultmain;
*   extern MCNUM  mccomp_storein[];
*   extern MCNUM  instrument.counter_AbsorbProp[];
*   extern MCNUM  mcScattered;
*   #define MCCODE_STRING "the McStas version"
*
* Usage: Automatically embbeded in the c code.
*
* $Id$
*
*******************************************************************************/

#ifndef MCSTAS_R_H
#define MCSTAS_R_H "$Revision$"

/* Following part is only embedded when not redundent with mcstas.h */

#ifndef MCCODE_H

#define AA2MS    629.622368        /* Convert k[1/AA] to v[m/s] */
#define MS2AA    1.58825361e-3     /* Convert v[m/s] to k[1/AA] */
#define K2V      AA2MS
#define V2K      MS2AA
#define Q2V      AA2MS
#define V2Q      MS2AA
#define SE2V     437.393377        /* Convert sqrt(E)[meV] to v[m/s] */
#define VS2E     5.22703725e-6     /* Convert (v[m/s])**2 to E[meV] */

#define SCATTER0 do {DEBUG_SCATTER(); SCATTERED++;} while(0)
#define SCATTER SCATTER0

#define JUMPTOCOMP(comp) mcneutron->_index = INDEX_COMP(comp);

#define MAGNET_ON \
  do { \
    mcMagnet = 1; \
  } while(0)

#define MAGNET_OFF \
  do { \
    mcMagnet = 0; \
  } while(0)

#define ALLOW_BACKPROP \
  do { \
    allow_backprop = 1; \
  } while(0)

#define DISALLOW_BACKPROP \
  do { \
    allow_backprop = 0; \
  } while(0)

#define PROP_MAGNET(dt) \
  do { \
  } while (0)
    /* change coordinates from local system to magnet system */
/*    Rotation rotLM, rotTemp; \
      Coords   posLM = coords_sub(POS_A_CURRENT_COMP, mcMagnetPos); \
      rot_transpose(ROT_A_CURRENT_COMP, rotTemp); \
      rot_mul(rotTemp, mcMagnetRot, rotLM); \
      mcMagnetPrecession(x, y, z, t, vx, vy, vz, \
               &sx, &sy, &sz, dt, posLM, rotLM); \
      } while(0)
*/

#define mcPROP_DT(dt) \
  do { \
    if (mcMagnet && dt > 0) PROP_MAGNET(dt);\
    x += vx*(dt); \
    y += vy*(dt); \
    z += vz*(dt); \
    t += (dt); \
    if (isnan(p) || isinf(p)) { ABSORB; }\
  } while(0)

/* ADD: E. Farhi, Aug 6th, 2001 PROP_GRAV_DT propagation with acceleration */
#define PROP_GRAV_DT(dt, Ax, Ay, Az) \
  do { \
    if(dt < 0 && allow_backprop == 0) { ABSORB; }\
    if (mcMagnet) /*printf("Spin precession gravity\n")*/; \
    x  += vx*(dt) + (Ax)*(dt)*(dt)/2; \
    y  += vy*(dt) + (Ay)*(dt)*(dt)/2; \
    z  += vz*(dt) + (Az)*(dt)*(dt)/2; \
    vx += (Ax)*(dt); \
    vy += (Ay)*(dt); \
    vz += (Az)*(dt); \
    t  += (dt); \
    DISALLOW_BACKPROP;\
  } while(0)


#define PROP_DT(dt) \
  do { \
    if(dt < 0 && allow_backprop == 0) { RESTORE=1; ABSORB; }; \
    if (mcgravitation) { Coords mcLocG; double mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    PROP_GRAV_DT(dt, mc_gx, mc_gy, mc_gz); } \
    else mcPROP_DT(dt); \
    DISALLOW_BACKPROP;\
  } while(0)


#define PROP_Z0 \
  do { \
    if (mcgravitation) { Coords mcLocG; int mc_ret; \
    double mc_dt, mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    mc_ret = solve_2nd_order(&mc_dt, NULL, -mc_gz/2, -vz, -z); \
    if (mc_ret) {PROP_GRAV_DT(mc_dt, mc_gx, mc_gy, mc_gz); z=0;}\
    else if (allow_backprop == 0 && mc_dt < 0) { ABSORB; }; } \
    else mcPROP_Z0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define mcPROP_Z0 \
  do { \
    double mc_dt; \
    if(vz == 0) { ABSORB; }; \
    mc_dt = -z/vz; \
    if(mc_dt < 0 && allow_backprop == 0) { ABSORB; }; \
    mcPROP_DT(mc_dt); \
    z = 0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define PROP_X0 \
  do { \
    if (mcgravitation) { Coords mcLocG; int mc_ret; \
    double mc_dt, mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    mc_ret = solve_2nd_order(&mc_dt, NULL, -mc_gx/2, -vx, -x); \
    if (mc_ret) {PROP_GRAV_DT(mc_dt, mc_gx, mc_gy, mc_gz); x=0;}\
    else if (allow_backprop == 0 && mc_dt < 0) { ABSORB; }; } \
    else mcPROP_X0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define mcPROP_X0 \
  do { \
    double mc_dt; \
    if(vx == 0) { ABSORB; }; \
    mc_dt = -x/vx; \
    if(mc_dt < 0 && allow_backprop == 0) { ABSORB; }; \
    mcPROP_DT(mc_dt); \
    x = 0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define PROP_Y0 \
  do { \
    if (mcgravitation) { Coords mcLocG; int mc_ret; \
    double mc_dt, mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    mc_ret = solve_2nd_order(&mc_dt, NULL, -mc_gy/2, -vy, -y); \
    if (mc_ret) {PROP_GRAV_DT(mc_dt, mc_gx, mc_gy, mc_gz); y=0;}\
    else if (allow_backprop == 0 && mc_dt < 0) { ABSORB; }; } \
    else mcPROP_Y0; \
    DISALLOW_BACKPROP;\
  } while(0)


#define mcPROP_Y0 \
  do { \
    double mc_dt; \
    if(vy == 0) { ABSORB; }; \
    mc_dt = -y/vy; \
    if(mc_dt < 0 && allow_backprop == 0) { ABSORB; }; \
    mcPROP_DT(mc_dt); \
    y = 0; \
    DISALLOW_BACKPROP; \
  } while(0)


#ifdef DEBUG

#define DEBUG_STATE() if(!mcdotrace); else \
  printf("STATE: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
         x,y,z,vx,vy,vz,t,sx,sy,sz,p);
#define DEBUG_SCATTER() if(!mcdotrace); else \
  printf("SCATTER: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
         x,y,z,vx,vy,vz,t,sx,sy,sz,p);

#else

#define DEBUG_STATE()
#define DEBUG_SCATTER()

#endif

#endif /* !MCCODE_H */

#endif /* MCSTAS_R_H */
/* End of file "mcstas-r.h". */

/* embedding file "mccode-r.c" */

/*******************************************************************************
*
* McCode, neutron/xray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mccode-r.c
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y/McXtrace X.Y
* Version: $Revision$
*
* Runtime system for McStas and McXtrace.
* Embedded within instrument in runtime mode.
* Contains SECTIONS:
*   MPI handling (sum, send, recv)
*   format definitions
*   I/O
*   mcdisplay support
*   random numbers
*   coordinates handling
*   vectors math (solve 2nd order, normals, randvec...)
*   parameter handling
*   signal and main handlers
*
* Usage: Automatically embbeded in the c code whenever required.
*
* $Id$
*
*******************************************************************************/

/*******************************************************************************
* The I/O format definitions and functions
*******************************************************************************/


/** Include header files to avoid implicit declarations (not allowed on LLVM) */
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

// UNIX specific headers (non-Windows)
#if defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#include <sys/stat.h>
#endif


#ifndef DANSE
#ifdef MC_ANCIENT_COMPATIBILITY
int traceenabled = 0;
int defaultmain  = 0;
#endif
/* else defined directly in the McCode generated C code */

static   long mcseed                 = 0; /* seed for random generator */
#pragma acc declare create ( mcseed )
static   long mcstartdate            = 0; /* start simulation time */
static   int  mcdisable_output_files = 0; /* --no-output-files */
mcstatic int  mcgravitation          = 0; /* use gravitation flag, for PROP macros */
mcstatic int  mcusedefaults          = 0; /* assume default value for all parameters */
mcstatic int  mcappend               = 0; /* flag to allow append mode on datasets/directories */
mcstatic int  mcdotrace              = 0; /* flag for --trace and messages for DISPLAY */
mcstatic int  mcnexus_embed_idf      = 0; /* flag to embed xml-formatted IDF file for Mantid */
#pragma acc declare create ( mcdotrace )
int      mcallowbackprop             = 0;         /* flag to enable negative/backprop */

/* OpenACC-related segmentation parameters: */
int vecsize = 128;
int numgangs = 7813;
long gpu_innerloop = 2147483647;

/* Monitor_nD list/buffer-size default */
/* Starting value may be defined using -DND_BUFFER=N */
/* Can further be controlled dynamically using --bufsiz input */
long MONND_BUFSIZ = 10000000;
#ifdef ND_BUFFER
MONND_BUFSIZ = ND_BUFFER;
#endif
 

/* Number of particle histories to simulate. */
#ifdef NEUTRONICS
mcstatic unsigned long long int mcncount             = 1;
mcstatic unsigned long long int mcrun_num            = 0;
#else
#ifdef MCDEFAULT_NCOUNT
mcstatic unsigned long long int mcncount             = MCDEFAULT_NCOUNT;
#else
mcstatic unsigned long long int mcncount             = 1000000;
#endif
#pragma acc declare create ( mcncount )
mcstatic unsigned long long int mcrun_num            = 0;
#pragma acc declare create ( mcrun_num )
#endif /* NEUTRONICS */

#else
#include "mcstas-globals.h"
#endif /* !DANSE */

#ifndef NX_COMPRESSION
#define NX_COMPRESSION NX_COMP_NONE
#endif

/* String nullification on GPU and other replacements */
#ifdef OPENACC
int noprintf() {
  return 0;
}

int str_comp(char *str1, char *str2) {
  while (*str1 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return (*str1 - *str2);
}

size_t str_len(const char *s)
{
  size_t len = 0;
  if(s != NULL)
  {
    while(*s != '\0')
    {
      ++len;
      ++s;
    }
  }
  return len;
}

#endif

/* SECTION: Predefine (component) parameters ================================= */

int nans_match(double a, double b){
  return (*(uint64_t*)&a == *(uint64_t*)&b);
}
int is_unset(double x){
  return nans_match(x, UNSET);
}
int is_set(double x){
  return !nans_match(x, UNSET);
}
int is_valid(double x){
  return !isnan(x)||is_unset(x);
}
int all_unset(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=1;
  for (int i=0; i<n; ++i) if(is_set(va_arg(ptr, double))) ret=0;
  va_end(ptr);
  return ret;
}
int all_set(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=1;
  for (int i=0; i<n; ++i) if(is_unset(va_arg(ptr, double))) ret=0;
  va_end(ptr);
  return ret;
}
int any_unset(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=0;
  for (int i=0; i<n; ++i) if(is_unset(va_arg(ptr, double))) ret=1;
  va_end(ptr);
  return ret;
}
int any_set(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=0;
  for (int i=0; i<n; ++i) if(is_set(va_arg(ptr, double))) ret=1;
  va_end(ptr);
  return ret;
}


/* SECTION: Dynamic Arrays ================================================== */
IArray1d create_iarr1d(int n){
  IArray1d arr1d;
  arr1d = calloc(n, sizeof(int));
  if (!arr1d) {
    fprintf(stderr, "Error allocating IArray1d of dimension %i\n",n);
    exit(-1);
  }
  return arr1d;
}

void destroy_iarr1d(IArray1d a){
  free(a);
}

IArray2d create_iarr2d(int nx, int ny){
  IArray2d arr2d;
  arr2d = calloc(nx, sizeof(int *));
  if (!arr2d) {
    fprintf(stderr, "Error allocating IArray2d of dimension %i x %i\n",nx,ny);
    exit(-1);
  }

  int *p1;
  p1 = calloc(nx*ny, sizeof(int));

  if (!p1) {
    fprintf(stderr, "Error allocating int* array of dimension %i\n",nx*ny);
    exit(-1);
  }
  
  int i;
  for (i=0; i<nx; i++){
    arr2d[i] = &(p1[i*ny]);
  }
  return arr2d;
}

void destroy_iarr2d(IArray2d a){
  free(a[0]);
  free(a);
}

IArray3d create_iarr3d(int nx, int ny, int nz){
  IArray3d arr3d;
  int i, j;

  // 1d
  arr3d = calloc(nx, sizeof(int **));
  if (!arr3d) {
    fprintf(stderr, "Error allocating IArray3d of dimension %i x %i x %i\n",nx,ny,nz);
    exit(-1);
  }

  // d2
  int **p1;
  p1 = calloc(nx*ny, sizeof(int *));

  if (!p1) {
    fprintf(stderr, "Error allocating int** array of dimension %i\n",nx*ny);
    exit(-1);
  }
  
  for (i=0; i<nx; i++){
    arr3d[i] = &(p1[i*ny]);
  }

  // 3d
  int *p2;
  p2 = calloc(nx*ny*nz, sizeof(int));
  if (!p2) {
    fprintf(stderr, "Error allocating int* array of dimension %i\n",nx*ny*nz);
    exit(-1);
  }
  for (i=0; i<nx; i++){
    for (j=0; j<ny; j++){
      arr3d[i][j] = &(p2[(i*ny+j)*nz]);
    }
  }
  return arr3d;
}

void destroy_iarr3d(IArray3d a){
  free(a[0][0]);
  free(a[0]);
  free(a);
}

DArray1d create_darr1d(int n){
  DArray1d arr1d;
  arr1d = calloc(n, sizeof(double));
  if (!arr1d) {
    fprintf(stderr, "Error allocating DArray1d of dimension %i\n",n);
    exit(-1);
  }
  return arr1d;
}

void destroy_darr1d(DArray1d a){
  free(a);
}

DArray2d create_darr2d(int nx, int ny){
  DArray2d arr2d;
  arr2d = calloc(nx, sizeof(double *));
  if (!arr2d) {
    fprintf(stderr, "Error allocating DArray2d of dimension %i x %i\n",nx,ny);
    exit(-1);
  }
  double *p1;
  p1 = calloc(nx*ny, sizeof(double));
  if (!p1) {
    fprintf(stderr, "Error allocating double* array of dimension %i\n",nx*ny);
    exit(-1);
  }
  int i;
  for (i=0; i<nx; i++){
    arr2d[i] = &(p1[i*ny]);
  }
  return arr2d;
}

void destroy_darr2d(DArray2d a){
  free(a[0]);
  free(a);
}

DArray3d create_darr3d(int nx, int ny, int nz){
  DArray3d arr3d;

  int i, j;

  // 1d
  arr3d = calloc(nx, sizeof(double **));
  if (!arr3d) {
    fprintf(stderr, "Error allocating DArray3d of dimension %i x %i x %i\n",nx,ny,nz);
    exit(-1);
  }
  // d2
  double **p1;
  p1 = calloc(nx*ny, sizeof(double *));
  if (!p1) {
    fprintf(stderr, "Error allocating double** array of dimension %i\n",nx*ny);
    exit(-1);
  }
  for (i=0; i<nx; i++){
    arr3d[i] = &(p1[i*ny]);
  }

  // 3d
  double *p2;
  p2 = calloc(nx*ny*nz, sizeof(double));
  if (!p2) {
    fprintf(stderr, "Error allocating double* array of dimension %i\n",nx*ny*nz);
    exit(-1);
  }
  for (i=0; i<nx; i++){
    for (j=0; j<ny; j++){
      arr3d[i][j] = &(p2[(i*ny+j)*nz]);
    }
  }
  return arr3d;
}

void destroy_darr3d(DArray3d a){
  free(a[0][0]);
  free(a[0]);
  free(a);
}


/* SECTION: MPI handling ==================================================== */

#ifdef USE_MPI
/* MPI rank */
static int mpi_node_rank;
static int mpi_node_root = 0;


/*******************************************************************************
* mc_MPI_Reduce: Gathers arrays from MPI nodes using Reduce function.
*******************************************************************************/
int mc_MPI_Sum(double *sbuf, long count)
{
  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to reduce */
  else {
    /* we must cut the buffer into blocks not exceeding the MPI max buffer size of 32000 */
    long   offset=0;
    double *rbuf=NULL;
    int    length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */
    int    i=0;
    rbuf = calloc(count, sizeof(double));
    if (!rbuf)
      exit(-fprintf(stderr, "Error: Out of memory %zi (mc_MPI_Sum)\n", count*sizeof(double)));
    while (offset < count) {
      if (!length || offset+length > count-1) length=count-offset;
      else length=MPI_REDUCE_BLOCKSIZE;
      if (MPI_Allreduce((double*)(sbuf+offset), (double*)(rbuf+offset),
              length, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD) != MPI_SUCCESS)
        return MPI_ERR_COUNT;
      offset += length;
    }

    for (i=0; i<count; i++) sbuf[i] = rbuf[i];
    free(rbuf);
  }
  return MPI_SUCCESS;
} /* mc_MPI_Sum */

/*******************************************************************************
* mc_MPI_Send: Send array to MPI node by blocks to avoid buffer limit
*******************************************************************************/
int mc_MPI_Send(void *sbuf,
                  long count, MPI_Datatype dtype,
                  int dest)
{
  int dsize;
  long offset=0;
  int  tag=1;
  int  length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */

  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to send */
  MPI_Type_size(dtype, &dsize);

  while (offset < count) {
    if (offset+length > count-1) length=count-offset;
    else length=MPI_REDUCE_BLOCKSIZE;
    if (MPI_Send((void*)((char*)sbuf+offset*dsize), length, dtype, dest, tag++, MPI_COMM_WORLD) != MPI_SUCCESS)
      return MPI_ERR_COUNT;
    offset += length;
  }

  return MPI_SUCCESS;
} /* mc_MPI_Send */

/*******************************************************************************
* mc_MPI_Recv: Receives arrays from MPI nodes by blocks to avoid buffer limit
*             the buffer must have been allocated previously.
*******************************************************************************/
int mc_MPI_Recv(void *sbuf,
                  long count, MPI_Datatype dtype,
                  int source)
{
  int dsize;
  long offset=0;
  int  tag=1;
  int  length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */

  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to recv */
  MPI_Type_size(dtype, &dsize);

  while (offset < count) {
    if (offset+length > count-1) length=count-offset;
    else length=MPI_REDUCE_BLOCKSIZE;
    if (MPI_Recv((void*)((char*)sbuf+offset*dsize), length, dtype, source, tag++,
            MPI_COMM_WORLD, MPI_STATUS_IGNORE) != MPI_SUCCESS)
      return MPI_ERR_COUNT;
    offset += length;
  }

  return MPI_SUCCESS;
} /* mc_MPI_Recv */

#endif /* USE_MPI */

/* SECTION: parameters handling ============================================= */

/* Instrument input parameter type handling. */
/*******************************************************************************
* mcparm_double: extract double value from 's' into 'vptr'
*******************************************************************************/
static int
mcparm_double(char *s, void *vptr)
{
  char *p;
  double *v = (double *)vptr;

  if (!s) { *v = 0; return(1); }
  *v = strtod(s, &p);
  if(*s == '\0' || (p != NULL && *p != '\0') || errno == ERANGE)
    return 0;                        /* Failed */
  else
    return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_double: display parameter type double
*******************************************************************************/
static char *
mcparminfo_double(char *parmname)
{
  return "double";
}

/*******************************************************************************
* mcparmerror_double: display error message when failed extract double
*******************************************************************************/
static void
mcparmerror_double(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for floating point parameter %s (mcparmerror_double)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_double: convert double to string
*******************************************************************************/
static void
mcparmprinter_double(char *f, void *vptr)
{
  double *v = (double *)vptr;
  sprintf(f, "%g", *v);
}

/*******************************************************************************
* mcparm_int: extract int value from 's' into 'vptr'
*******************************************************************************/
static int
mcparm_int(char *s, void *vptr)
{
  char *p;
  int *v = (int *)vptr;
  long x;

  if (!s) { *v = 0; return(1); }
  *v = 0;
  x = strtol(s, &p, 10);
  if(x < INT_MIN || x > INT_MAX)
    return 0;                        /* Under/overflow */
  *v = x;
  if(*s == '\0' || (p != NULL && *p != '\0') || errno == ERANGE)
    return 0;                        /* Failed */
  else
    return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_int: display parameter type int
*******************************************************************************/
static char *
mcparminfo_int(char *parmname)
{
  return "int";
}

/*******************************************************************************
* mcparmerror_int: display error message when failed extract int
*******************************************************************************/
static void
mcparmerror_int(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for integer parameter %s (mcparmerror_int)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_int: convert int to string
*******************************************************************************/
static void
mcparmprinter_int(char *f, void *vptr)
{
  int *v = (int *)vptr;
  sprintf(f, "%d", *v);
}

/*******************************************************************************
* mcparm_string: extract char* value from 's' into 'vptr' (copy)
*******************************************************************************/
static int
mcparm_string(char *s, void *vptr)
{
  char **v = (char **)vptr;
  if (!s) { *v = NULL; return(1); }
  *v = (char *)malloc(strlen(s) + 1);
  if(*v == NULL)
  {
    exit(-fprintf(stderr, "Error: Out of memory %li (mcparm_string).\n", (long)strlen(s) + 1));
  }
  strcpy(*v, s);
  return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_string: display parameter type string
*******************************************************************************/
static char *
mcparminfo_string(char *parmname)
{
  return "string";
}

/*******************************************************************************
* mcparmerror_string: display error message when failed extract string
*******************************************************************************/
static void
mcparmerror_string(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for string parameter %s (mcparmerror_string)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_string: convert string to string (including esc chars)
*******************************************************************************/
static void
mcparmprinter_string(char *f, void *vptr)
{
  char **v = (char **)vptr;
  char *p;

  if (!*v) { *f='\0'; return; }
  strcpy(f, "");
  for(p = *v; *p != '\0'; p++)
  {
    switch(*p)
    {
      case '\n':
        strcat(f, "\\n");
        break;
      case '\r':
        strcat(f, "\\r");
        break;
      case '"':
        strcat(f, "\\\"");
        break;
      case '\\':
        strcat(f, "\\\\");
        break;
      default:
        strncat(f, p, 1);
    }
  }
  /* strcat(f, "\""); */
} /* mcparmprinter_string */

/* now we may define the parameter structure, using previous functions */
static struct
  {
    int (*getparm)(char *, void *);
    char * (*parminfo)(char *);
    void (*error)(char *, char *);
    void (*printer)(char *, void *);
} mcinputtypes[] = {
  {
    mcparm_int, mcparminfo_int, mcparmerror_int,
    mcparmprinter_int
  }, {
    mcparm_string, mcparminfo_string, mcparmerror_string,
    mcparmprinter_string
  }, {
    mcparm_string, mcparminfo_string, mcparmerror_string,
    mcparmprinter_string
  }, {
    mcparm_double, mcparminfo_double, mcparmerror_double,
    mcparmprinter_double
  }, {
    mcparm_double, mcparminfo_double, mcparmerror_double,
    mcparmprinter_double
  }
};

/*******************************************************************************
* mcestimate_error: compute sigma from N,p,p2 in Gaussian large numbers approx
*******************************************************************************/
double mcestimate_error(double N, double p1, double p2)
{
  double pmean, n1;
  if(N <= 1)
    return p1;
  pmean = p1 / N;
  n1 = N - 1;
  /* Note: underflow may cause p2 to become zero; the fabs() below guards
     against this. */
  return sqrt((N/n1)*fabs(p2 - pmean*pmean));
}

double (*mcestimate_error_p)
  (double V2, double psum, double p2sum)=mcestimate_error;

/* ========================================================================== */

/*                               MCCODE_R_IO_C                                */

/* ========================================================================== */

#ifndef MCCODE_R_IO_C
#define MCCODE_R_IO_C "$Revision$"

/* SECTION: file i/o handling ================================================ */

#ifndef HAVE_STRCASESTR
// from msysgit: https://code.google.com/p/msysgit/source/browse/compat/strcasestr.c
char *strcasestr(const char *haystack, const char *needle)
{
  int nlen = strlen(needle);
  int hlen = strlen(haystack) - nlen + 1;
  int i;

  for (i = 0; i < hlen; i++) {
    int j;
    for (j = 0; j < nlen; j++) {
            unsigned char c1 = haystack[i+j];
            unsigned char c2 = needle[j];
            if (toupper(c1) != toupper(c2))
                    goto next;
    }
    return (char *) haystack + i;
  next:
    ;
  }
  return NULL;
}


#endif
#ifndef HAVE_STRCASECMP
int strcasecmp( const char *s1, const char *s2 )
{
  int c1, c2;
  do {
    c1 = tolower( (unsigned char) *s1++ );
    c2 = tolower( (unsigned char) *s2++ );
  } while (c1 == c2 && c1 != 0);
  return c2 > c1 ? -1 : c1 > c2;
}
#endif

#ifndef STRACPY
/* this is a replacement to strncpy, but ensures that the copy ends with NULL */
/* http://stracpy.blogspot.fr/2011/04/stracpy-strncpy-replacement.html */
#define STRACPY
char *stracpy(char *destination, const char *source, size_t amount)
{
        if (!destination || !source || !amount) return(NULL);
        while(amount--)
          if((*destination++ = *source++) == '\0') break;
        *destination = '\0';
        return destination;
}
#endif

/*******************************************************************************
* mcfull_file: allocates a full file name=dirname+file. Catenate extension if missing.
*******************************************************************************/
char *mcfull_file(char *name, char *ext)
{
  int   dirlen=0;
  char *mem   =NULL;

  dirlen = dirname ? strlen(dirname) : 0;
  mem = (char*)malloc(dirlen + strlen(name) + CHAR_BUF_LENGTH);
  if(!mem) {
    exit(-fprintf(stderr, "Error: Out of memory %li (mcfull_file)\n", (long)(dirlen + strlen(name) + 256)));
  }
  strcpy(mem, "");

  /* prepend directory name to path if name does not contain a path */
  if (dirlen > 0 && !strchr(name, MC_PATHSEP_C)) {
    strcat(mem, dirname);
    strcat(mem, MC_PATHSEP_S);
  } /* dirlen */

  strcat(mem, name);
  if (!strchr(name, '.') && ext && strlen(ext))
  { /* add extension if not in file name already */
    strcat(mem, ".");
    strcat(mem, ext);
  }
  return(mem);
} /* mcfull_file */

/*******************************************************************************
* mcnew_file: opens a new file within dirname if non NULL
*             the file is opened in "a" (append, create if does not exist)
*             the extension 'ext' is added if the file name does not include one.
*             the last argument is set to 0 if file did not exist, else to 1.
*******************************************************************************/
FILE *mcnew_file(char *name, char *ext, int *exists)
{
  char *mem;
  FILE *file=NULL;

  if (!name || strlen(name) == 0 || mcdisable_output_files) return(NULL);

  mem  = mcfull_file(name, ext); /* create dirname/name.ext */

  /* check for existence */
  file = fopen(mem, "r"); /* for reading -> fails if does not exist */
  if (file) {
    fclose(file);
    *exists=1;
  } else
    *exists=0;

  /* open the file for writing/appending */
#ifdef USE_NEXUS
  if (mcformat && strcasestr(mcformat, "NeXus")) {
    /* NXhandle nxhandle is defined in the .h with USE_NEXUS */
    NXaccess mode = (*exists ? NXACC_CREATE5 | NXACC_RDWR : NXACC_CREATE5);

    if (NXopen(mem, mode, &nxhandle) != NX_OK)
      file = NULL;
    else
      file = (FILE*)&nxhandle; /* to make it non NULL */
  } else
#endif
    file = fopen(mem, "a+");

  if(!file)
    fprintf(stderr, "Warning: could not open output file '%s' for %s (mcnew_file)\n",
      mem, *exists ? "append" : "create");
  free(mem);

  return file;
} /* mcnew_file */

/*******************************************************************************
* mcdetector_statistics: compute detector statistics, error bars, [x I I_err N] 1D
* RETURN:            updated detector structure
* Used by: detector_import
*******************************************************************************/
MCDETECTOR mcdetector_statistics(
  MCDETECTOR detector)
{

  if (!detector.p1 || !detector.m)
    return(detector);

  /* compute statistics and update MCDETECTOR structure ===================== */
  double sum_z  = 0, min_z  = 0, max_z  = 0;
  double fmon_x =0,  smon_x = 0, fmon_y =0, smon_y=0, mean_z=0;
  double Nsum=0, P2sum=0;

  double sum_xz = 0, sum_yz = 0, sum_x = 0, sum_y = 0, sum_x2z = 0, sum_y2z = 0;
  int    i,j;
  char   hasnan=0, hasinf=0;
  char   israw = ((char*)strcasestr(detector.format,"raw") != NULL);
  double *this_p1=NULL; /* new 1D McCode array [x I E N]. Freed after writing data */

  /* if McCode/PGPLOT and rank==1 we create a new m*4 data block=[x I E N] */
  if (detector.rank == 1 && strcasestr(detector.format,"McCode")) {
    this_p1 = (double *)calloc(detector.m*detector.n*detector.p*4, sizeof(double));
    if (!this_p1)
      exit(-fprintf(stderr, "Error: Out of memory creating %zi 1D " MCCODE_STRING " data set for file '%s' (detector_import)\n",
        detector.m*detector.n*detector.p*4*sizeof(double*), detector.filename));
  }

  max_z = min_z = detector.p1[0];

  /* compute sum and moments (not for lists) */
  if (!strcasestr(detector.format,"list") && detector.m)
  for(j = 0; j < detector.n*detector.p; j++)
  {
    for(i = 0; i < detector.m; i++)
    {
      double x,y,z;
      double N, E;
      long   index= !detector.istransposed ? i*detector.n*detector.p + j : i+j*detector.m;
      char   hasnaninf=0;

      if (detector.m)
        x = detector.xmin + (i + 0.5)/detector.m*(detector.xmax - detector.xmin);
      else x = 0;
      if (detector.n && detector.p)
        y = detector.ymin + (j + 0.5)/detector.n/detector.p*(detector.ymax - detector.ymin);
      else y = 0;
      z = detector.p1[index];
      N = detector.p0 ? detector.p0[index] : 1;
      E = detector.p2 ? detector.p2[index] : 0;
      if (detector.p2 && !israw)
        detector.p2[index] = (*mcestimate_error_p)(detector.p0[index],detector.p1[index],detector.p2[index]); /* set sigma */

      if (detector.rank == 1 && this_p1 && strcasestr(detector.format,"McCode")) {
        /* fill-in 1D McCode array [x I E N] */
        this_p1[index*4]   = x;
        this_p1[index*4+1] = z;
        this_p1[index*4+2] = detector.p2 ? detector.p2[index] : 0;
        this_p1[index*4+3] = N;
      }

      if (isnan(z) || isnan(E) || isnan(N)) hasnaninf=hasnan=1;
      if (isinf(z) || isinf(E) || isinf(N)) hasnaninf=hasinf=1;

      /* compute stats integrals */
      if (!hasnaninf) {
        sum_xz += x*z;
        sum_yz += y*z;
        sum_x  += x;
        sum_y  += y;
        sum_z  += z;
        sum_x2z += x*x*z;
        sum_y2z += y*y*z;
        if (z > max_z) max_z = z;
        if (z < min_z) min_z = z;

        Nsum += N;
        P2sum += E;
      }

    }
  } /* for j */

  /* compute 1st and 2nd moments. For lists, sum_z=0 so this is skipped. */
  if (sum_z && detector.n*detector.m*detector.p)
  {
    fmon_x = sum_xz/sum_z;
    fmon_y = sum_yz/sum_z;
    smon_x = sum_x2z/sum_z-fmon_x*fmon_x; smon_x = smon_x > 0 ? sqrt(smon_x) : 0;
    smon_y = sum_y2z/sum_z-fmon_y*fmon_y; smon_y = smon_y > 0 ? sqrt(smon_y) : 0;
    mean_z = sum_z/detector.n/detector.m/detector.p;
  }
  /* store statistics into detector */
  detector.intensity = sum_z;
  detector.error     = Nsum ? (*mcestimate_error_p)(Nsum, sum_z, P2sum) : 0;
  detector.events    = Nsum;
  detector.min       = min_z;
  detector.max       = max_z;
  detector.mean      = mean_z;
  detector.centerX   = fmon_x;
  detector.halfwidthX= smon_x;
  detector.centerY   = fmon_y;
  detector.halfwidthY= smon_y;

  /* if McCode/PGPLOT and rank==1 replace p1 with new m*4 1D McCode and clear others */
  if (detector.rank == 1 && this_p1 && strcasestr(detector.format,"McCode")) {

    detector.p1 = this_p1;
    detector.n  = detector.m; detector.m  = 4;
    detector.p0 = detector.p2 = NULL;
    detector.istransposed = 1;
  }

  if (detector.n*detector.m*detector.p > 1)
    snprintf(detector.signal, CHAR_BUF_LENGTH,
      "Min=%g; Max=%g; Mean=%g;", detector.min, detector.max, detector.mean);
  else
    strcpy(detector.signal, "None");
  snprintf(detector.values, CHAR_BUF_LENGTH,
    "%g %g %g", detector.intensity, detector.error, detector.events);

  switch (detector.rank) {
    case 1:  snprintf(detector.statistics, CHAR_BUF_LENGTH, "X0=%g; dX=%g;",
      detector.centerX, detector.halfwidthX); break;
    case 2:
    case 3:  snprintf(detector.statistics, CHAR_BUF_LENGTH, "X0=%g; dX=%g; Y0=%g; dY=%g;",
      detector.centerX, detector.halfwidthX, detector.centerY, detector.halfwidthY);
      break;
    default: strcpy(detector.statistics, "None");
  }

  if (hasnan)
    printf("WARNING: Nan detected in component/file %s %s\n",
      detector.component, strlen(detector.filename) ? detector.filename : "");
  if (hasinf)
    printf("WARNING: Inf detected in component/file %s %s\n",
      detector.component, strlen(detector.filename) ? detector.filename : "");

  return(detector);

} /* mcdetector_statistics */

/*******************************************************************************
* detector_import: build detector structure, merge non-lists from MPI
*                    compute basic stat, write "Detector:" line
* RETURN:            detector structure. Invalid data if detector.p1 == NULL
*                    Invalid detector sets m=0 and filename=""
*                    Simulation data  sets m=0 and filename=siminfo_name
* This function is equivalent to the old 'mcdetector_out', returning a structure
*******************************************************************************/
MCDETECTOR detector_import(
  char *format,
  char *component, char *title,
  long m, long n,  long p,
  char *xlabel, char *ylabel, char *zlabel,
  char *xvar, char *yvar, char *zvar,
  double x1, double x2, double y1, double y2, double z1, double z2,
  char *filename,
  double *p0, double *p1, double *p2,
  Coords position, Rotation rotation, int index)
{
  time_t t;       /* for detector.date */
  long   date_l;  /* date as a long number */
  char   istransposed=0;
  char   c[CHAR_BUF_LENGTH]; /* temp var for signal label */

  MCDETECTOR detector;

  /* build MCDETECTOR structure ============================================= */
  /* make sure we do not have NULL for char fields */

  /* these also apply to simfile */
  strncpy (detector.filename,  filename ? filename : "",        CHAR_BUF_LENGTH);
  strncpy (detector.format,    format   ? format   : "McCode" , CHAR_BUF_LENGTH);
  /* add extension if missing */
  if (strlen(detector.filename) && !strchr(detector.filename, '.'))
  { /* add extension if not in file name already */
    strcat(detector.filename, ".dat");
  }
  strncpy (detector.component, component ? component : MCCODE_STRING " component", CHAR_BUF_LENGTH);
  #ifdef USE_NEXUS
  char pref[5];
  if (index-1 < 10) {
    sprintf(pref,"000");
  } else if (index-1 < 100) {
    sprintf(pref,"00");
  } else if (index-1 < 1000) {
    sprintf(pref,"0");
  } else if (index-1 < 10000) {
    sprintf(pref,"");
  } else {
    fprintf(stderr,"Error, no support for > 10000 comps at the moment!\n");
    exit(-1);
  }
  sprintf(detector.nexuscomp,"%s%d_%s",pref,index-1,detector.component);
  #endif

  snprintf(detector.instrument, CHAR_BUF_LENGTH, "%s (%s)", instrument_name, instrument_source);
  snprintf(detector.user, CHAR_BUF_LENGTH,      "%s on %s",
        getenv("USER") ? getenv("USER") : MCCODE_NAME,
        getenv("HOST") ? getenv("HOST") : "localhost");
  time(&t);         /* get current write time */
  date_l = (long)t; /* same but as a long */
  snprintf(detector.date, CHAR_BUF_LENGTH, "%s", ctime(&t));
  if (strlen(detector.date))   detector.date[strlen(detector.date)-1] = '\0'; /* remove last \n in date */
  detector.date_l = date_l;

  if (!mcget_run_num() || mcget_run_num() >= mcget_ncount())
    snprintf(detector.ncount, CHAR_BUF_LENGTH, "%llu", mcget_ncount()
#ifdef USE_MPI
*mpi_node_count
#endif
  );
  else
    snprintf(detector.ncount, CHAR_BUF_LENGTH, "%g/%g", (double)mcget_run_num(), (double)mcget_ncount());

  detector.p0         = p0;
  detector.p1         = p1;
  detector.p2         = p2;

  /* handle transposition (not for NeXus) */
  if (!strcasestr(detector.format, "NeXus")) {
    if (m<0 || n<0 || p<0)             istransposed = !istransposed;
    if (strcasestr(detector.format, "transpose")) istransposed = !istransposed;
    if (istransposed) { /* do the swap once for all */
      long i=m; m=n; n=i;
    }
  }

  m=labs(m); n=labs(n); p=labs(p); /* make sure dimensions are positive */
  detector.istransposed = istransposed;

  /* determine detector rank (dimensionality) */
  if (!m || !n || !p || !p1) detector.rank = 4; /* invalid: exit with m=0 filename="" */
  else if (m*n*p == 1)       detector.rank = 0; /* 0D */
  else if (n == 1 || m == 1) detector.rank = 1; /* 1D */
  else if (p == 1)           detector.rank = 2; /* 2D */
  else                       detector.rank = 3; /* 3D */

  /* from rank, set type */
  switch (detector.rank) {
    case 0:  strcpy(detector.type,  "array_0d"); m=n=p=1; break;
    case 1:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_1d(%ld)", m*n*p); m *= n*p; n=p=1; break;
    case 2:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_2d(%ld, %ld)", m, n*p); n *= p; p=1; break;
    case 3:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_3d(%ld, %ld, %ld)", m, n, p); break;
    default: m=0; strcpy(detector.type, ""); strcpy(detector.filename, "");/* invalid */
  }

  detector.m    = m;
  detector.n    = n;
  detector.p    = p;

  /* these only apply to detector files ===================================== */

  detector.Position[0]=position.x;
  detector.Position[1]=position.y;
  detector.Position[2]=position.z;
  rot_copy(detector.Rotation,rotation);
  snprintf(detector.position, CHAR_BUF_LENGTH, "%g %g %g", position.x, position.y, position.z);
  /* may also store actual detector orientation in the future */

  strncpy(detector.title,      title && strlen(title) ? title : component,       CHAR_BUF_LENGTH);
  strncpy(detector.xlabel,     xlabel && strlen(xlabel) ? xlabel : "X", CHAR_BUF_LENGTH); /* axis labels */
  strncpy(detector.ylabel,     ylabel && strlen(ylabel) ? ylabel : "Y", CHAR_BUF_LENGTH);
  strncpy(detector.zlabel,     zlabel && strlen(zlabel) ? zlabel : "Z", CHAR_BUF_LENGTH);
  strncpy(detector.xvar,       xvar && strlen(xvar) ? xvar :       "x", CHAR_BUF_LENGTH); /* axis variables */
  strncpy(detector.yvar,       yvar && strlen(yvar) ? yvar :       detector.xvar, CHAR_BUF_LENGTH);
  strncpy(detector.zvar,       zvar && strlen(zvar) ? zvar :       detector.yvar, CHAR_BUF_LENGTH);

  /* set "variables" as e.g. "I I_err N" */
  strcpy(c, "I ");
  if (strlen(detector.zvar))      strncpy(c, detector.zvar,32);
  else if (strlen(detector.yvar)) strncpy(c, detector.yvar,32);
  else if (strlen(detector.xvar)) strncpy(c, detector.xvar,32);

  if (detector.rank == 1)
    snprintf(detector.variables, CHAR_BUF_LENGTH, "%s %s %s_err N", detector.xvar, c, c);
  else
    snprintf(detector.variables, CHAR_BUF_LENGTH, "%s %s_err N", c, c);

  /* limits */
  detector.xmin = x1;
  detector.xmax = x2;
  detector.ymin = y1;
  detector.ymax = y2;
  detector.zmin = z1;
  detector.zmax = z2;
  if (abs(detector.rank) == 1)
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g", x1, x2);
  else if (detector.rank == 2)
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g %g %g", x1, x2, y1, y2);
  else
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g %g %g %g %g", x1, x2, y1, y2, z1, z2);

  /* if MPI and nodes_nb > 1: reduce data sets when using MPI =============== */
#ifdef USE_MPI
  if (!strcasestr(detector.format,"list") && mpi_node_count > 1 && m) {
    /* we save additive data: reduce everything into mpi_node_root */
    if (p0) mc_MPI_Sum(p0, m*n*p);
    if (p1) mc_MPI_Sum(p1, m*n*p);
    if (p2) mc_MPI_Sum(p2, m*n*p);
    if (!p0) {  /* additive signal must be then divided by the number of nodes */
      int i;
      for (i=0; i<m*n*p; i++) {
        p1[i] /= mpi_node_count;
        if (p2) p2[i] /= mpi_node_count;
      }
    }
  }
#endif /* USE_MPI */

  /* compute statistics, Nsum, intensity, Error bars */
  detector = mcdetector_statistics(detector);

#ifdef USE_MPI
  /* slaves are done */
  if(mpi_node_rank != mpi_node_root) {
    return detector;
  }
#endif

  /* output "Detector:" line ================================================ */
  /* when this is a detector written by a component (not the SAVE from instrument),
     not an event lists */
  if (!m) return(detector);
  if (!strcasestr(detector.format,"list")) {
    if (!strcmp(detector.component, instrument_name)) {
      if (strlen(detector.filename))  /* we name it from its filename, or from its title */
        strncpy(c, detector.filename, CHAR_BUF_LENGTH);
      else
        snprintf(c, CHAR_BUF_LENGTH, "%s", instrument_name);
    } else
      strncpy(c, detector.component, CHAR_BUF_LENGTH);  /* usual detectors written by components */

    printf("Detector: %s_I=%g %s_ERR=%g %s_N=%g",
           c, detector.intensity,
           c, detector.error,
           c, detector.events);
    printf(" \"%s\"\n", strlen(detector.filename) ? detector.filename : detector.component);
  }


  return(detector);
} /* detector_import */

/* end MCDETECTOR import section ============================================ */

















/* ========================================================================== */

/*                               ASCII output                                 */
/*     The SIM file is YAML based, the data files have '#' headers            */

/* ========================================================================== */


/*******************************************************************************
* mcinfo_out: output instrument tags/info (only in SIM)
* Used in: siminfo_init (ascii), mcinfo(stdout)
*******************************************************************************/
static void mcinfo_out(char *pre, FILE *f)
{
  char Parameters[CHAR_BUF_LENGTH] = "";
  int  i;

  if (!f || mcdisable_output_files) return;

  /* create parameter string ================================================ */
  for(i = 0; i < numipar; i++)
  {
    char ThisParam[CHAR_BUF_LENGTH];
    if (strlen(mcinputtable[i].name) > CHAR_BUF_LENGTH) break;
    snprintf(ThisParam, CHAR_BUF_LENGTH, " %s(%s)", mcinputtable[i].name,
            (*mcinputtypes[mcinputtable[i].type].parminfo)
                (mcinputtable[i].name));
    if (strlen(Parameters) + strlen(ThisParam) + 1 >= CHAR_BUF_LENGTH) break;
    strcat(Parameters, ThisParam);
  }

  /* output data ============================================================ */
  if (f != stdout)
    fprintf(f, "%sFile: %s%c%s\n",    pre, dirname, MC_PATHSEP_C, siminfo_name);
  else
    fprintf(f, "%sCreator: %s\n",     pre, MCCODE_STRING);

  fprintf(f, "%sSource: %s\n",   pre, instrument_source);
  fprintf(f, "%sParameters: %s\n",    pre, Parameters);

  fprintf(f, "%sTrace_enabled: %s\n", pre, traceenabled ? "yes" : "no");
  fprintf(f, "%sDefault_main: %s\n",  pre, defaultmain ?  "yes" : "no");
#ifdef MC_EMBEDDED_RUNTIME
  fprintf(f, "%sEmbedded_runtime: %s\n", pre, "yes");
#else
  fprintf(f, "%sEmbedded_runtime: %s\n", pre, "no");
#endif

  fflush(f);
} /* mcinfo_out */

/*******************************************************************************
* mcruninfo_out: output simulation tags/info (both in SIM and data files)
* Used in: siminfo_init (ascii case), mcdetector_out_xD_ascii
*******************************************************************************/
static void mcruninfo_out(char *pre, FILE *f)
{
  int i;
  char Parameters[CHAR_BUF_LENGTH];

  if (!f || mcdisable_output_files) return;

  fprintf(f, "%sFormat: %s%s\n",      pre,
    mcformat && strlen(mcformat) ? mcformat : MCCODE_NAME,
    mcformat && strcasestr(mcformat,"McCode") ? " with text headers" : "");
  fprintf(f, "%sURL: %s\n",         pre, "http://www.mccode.org");
  fprintf(f, "%sCreator: %s\n",     pre, MCCODE_STRING);
  fprintf(f, "%sInstrument: %s\n", pre, instrument_source);
  fprintf(f, "%sNcount: %llu\n",        pre, mcget_ncount());
  fprintf(f, "%sTrace: %s\n",       pre, mcdotrace ? "yes" : "no");
  fprintf(f, "%sGravitation: %s\n", pre, mcgravitation ? "yes" : "no");
  snprintf(Parameters, CHAR_BUF_LENGTH, "%ld", mcseed);
  fprintf(f, "%sSeed: %s\n",        pre, Parameters);
  fprintf(f, "%sDirectory: %s\n",        pre, dirname ? dirname : ".");
#ifdef USE_MPI
  if (mpi_node_count > 1)
    fprintf(f, "%sNodes: %i\n",        pre, mpi_node_count);
#endif

  // TODO Consider replacing this by a a call to `mcparameterinfo_out(pre+"Param: ", f)`
  /* output parameter string ================================================ */
  for(i = 0; i < numipar; i++) {
      if (mcinputtable[i].par){
	/* Parameters with a default value */
	if(mcinputtable[i].val && strlen(mcinputtable[i].val)){
	  (*mcinputtypes[mcinputtable[i].type].printer)(Parameters, mcinputtable[i].par);
	  fprintf(f, "%sParam: %s=%s\n", pre, mcinputtable[i].name, Parameters);
        /* ... and those without */
	}else{
	  fprintf(f, "%sParam: %s=NULL\n", pre, mcinputtable[i].name);
	}
      }
  }
  fflush(f);
} /* mcruninfo_out */

/*******************************************************************************
 * @brief Print parameter information to the specified file
 * @param pre any beginning-of-line padding
 * @param f the output file
 */
static void mcparameterinfo_out(char * pre, FILE *f){
  if (!f || mcdisable_output_files) return;

  unsigned int nchar = 4;
  for (int i=0; i < numipar; ++i){
    if (mcinputtable[i].par && mcinputtable[i].val && strlen(mcinputtable[i].val) > nchar)
      nchar = strlen(mcinputtable[i].val);
  }
  char * buffer = calloc(nchar+1, sizeof(char));

  if (!buffer) {
    exit(1);
  }

  for (int i=0; i < numipar; ++i) {
    if (mcinputtable[i].par) {
      char * name = mcinputtable[i].name;
      if (mcinputtable[i].val && strlen(mcinputtable[i].val)) {
        mcinputtypes[mcinputtable[i].type].printer(buffer, mcinputtable[i].par);
      } else {
        strcpy(buffer, "NULL");
      }
      if (strlen(mcinputtable[i].unit)){
        //fprintf(f, "%s%s %s (\"%s\") = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, mcinputtable[i].unit, buffer);
        fprintf(f, "%s%s %s/\"%s\" = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, mcinputtable[i].unit, buffer);
      } else {
        fprintf(f, "%s%s %s = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, buffer);
      }
    }
  }

  free(buffer);
}

/*******************************************************************************
* siminfo_out:    wrapper to fprintf(siminfo_file)
*******************************************************************************/
void siminfo_out(char *format, ...)
{
  va_list ap;

  if(siminfo_file && !mcdisable_output_files)
  {
    va_start(ap, format);
    vfprintf(siminfo_file, format, ap);
    va_end(ap);
  }
} /* siminfo_out */


/*******************************************************************************
* mcdatainfo_out: output detector header
*   mcdatainfo_out(prefix, file_handle, detector) writes info to data file
*******************************************************************************/
static void
mcdatainfo_out(char *pre, FILE *f, MCDETECTOR detector)
{
  if (!f || !detector.m || mcdisable_output_files) return;

  /* output data ============================================================ */
  fprintf(f, "%sDate: %s (%li)\n",       pre, detector.date, detector.date_l);
  fprintf(f, "%stype: %s\n",       pre, detector.type);
  fprintf(f, "%sSource: %s\n",     pre, detector.instrument);
  fprintf(f, "%scomponent: %s\n",  pre, detector.component);
  fprintf(f, "%sposition: %s\n",   pre, detector.position);

  fprintf(f, "%stitle: %s\n",      pre, detector.title);
  fprintf(f, !mcget_run_num() || mcget_run_num() >= mcget_ncount() ?
             "%sNcount: %s\n" :
             "%sratio: %s\n",  pre, detector.ncount);

  if (strlen(detector.filename)) {
    fprintf(f, "%sfilename: %s\n", pre, detector.filename);
  }

  fprintf(f, "%sstatistics: %s\n", pre, detector.statistics);
  fprintf(f, "%ssignal: %s\n",     pre, detector.signal);
  fprintf(f, "%svalues: %s\n",     pre, detector.values);

  if (detector.rank >= 1)
  {
    fprintf(f, "%sxvar: %s\n",     pre, detector.xvar);
    fprintf(f, "%syvar: %s\n",     pre, detector.yvar);
    fprintf(f, "%sxlabel: %s\n",   pre, detector.xlabel);
    fprintf(f, "%sylabel: %s\n",   pre, detector.ylabel);
    if (detector.rank > 1) {
      fprintf(f, "%szvar: %s\n",   pre, detector.zvar);
      fprintf(f, "%szlabel: %s\n", pre, detector.zlabel);
    }
  }

  fprintf(f,
    abs(detector.rank)==1 ?
             "%sxlimits: %s\n" :
             "%sxylimits: %s\n", pre, detector.limits);
  fprintf(f, "%svariables: %s\n", pre,
    strcasestr(detector.format, "list") ? detector.ylabel : detector.variables);

  fflush(f);

} /* mcdatainfo_out */

/* mcdetector_out_array_ascii: output a single array to a file
 *   m: columns
 *   n: rows
 *   p: array
 *   f: file handle (already opened)
 */
static void mcdetector_out_array_ascii(long m, long n, double *p, FILE *f, char istransposed)
{
  if(f)
  {
    int i,j;
    for(j = 0; j < n; j++)
    {
      for(i = 0; i < m; i++)
      {
          fprintf(f, "%.10g ", p[!istransposed ? i*n + j : j*m+i]);
      }
      fprintf(f,"\n");
    }
  }
} /* mcdetector_out_array_ascii */

/*******************************************************************************
* mcdetector_out_0D_ascii: called by mcdetector_out_0D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_0D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  /* Write data set information to simulation description file. */
  MPI_MASTER(
    siminfo_out("\nbegin data\n"); // detector.component
    mcdatainfo_out("  ", siminfo_file, detector);
    siminfo_out("end data\n");
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.component, "dat", &exists);
    if(outfile)
    {
      /* write data file header and entry in simulation description file */
      mcruninfo_out( "# ", outfile);
      mcdatainfo_out("# ", outfile, detector);
      /* write I I_err N */
      fprintf(outfile, "%g %g %g\n",
        detector.intensity, detector.error, detector.events);
      fclose(outfile);
    }
  ); /* MPI_MASTER */
  return(detector);
} /* mcdetector_out_0D_ascii */

/*******************************************************************************
* mcdetector_out_1D_ascii: called by mcdetector_out_1D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_1D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  MPI_MASTER(
    /* Write data set information to simulation description file. */
    siminfo_out("\nbegin data\n"); // detector.filename
    mcdatainfo_out("  ", siminfo_file, detector);
    siminfo_out("end data\n");
    /* Loop over array elements, writing to file. */
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.filename, "dat", &exists);
    if(outfile)
    {
      /* write data file header and entry in simulation description file */
      mcruninfo_out( "# ", outfile);
      mcdatainfo_out("# ", outfile, detector);
      /* output the 1D array columns */
      mcdetector_out_array_ascii(detector.m, detector.n, detector.p1, outfile, detector.istransposed);

      fclose(outfile);
    }
  ); /* MPI_MASTER */
  return(detector);

}  /* mcdetector_out_1D_ascii */

/*******************************************************************************
* mcdetector_out_2D_ascii: called by mcdetector_out_2D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_2D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  MPI_MASTER(
    /* Loop over array elements, writing to file. */
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.filename, "dat", &exists);
    if(outfile)
    {
      /* write header only if file has just been created (not appending) */
      if (!exists) {
        /* Write data set information to simulation description file. */
        siminfo_out("\nbegin data\n"); // detector.filename
        mcdatainfo_out("  ", siminfo_file, detector);
        siminfo_out("end data\n");

        mcruninfo_out( "# ", outfile);
        mcdatainfo_out("# ", outfile,   detector);
      }
      /* Add # Data entry for any write to the file (e.g. via -USR2, see GitHub issue #2174 ) */
      fprintf(outfile, "# Data [%s/%s] %s:\n", detector.component, detector.filename, detector.zvar);
      mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p1,
        outfile, detector.istransposed);
      if (detector.p2) {
        fprintf(outfile, "# Errors [%s/%s] %s_err:\n", detector.component, detector.filename, detector.zvar);
        mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p2,
          outfile, detector.istransposed);
      }
      if (detector.p0) {
        fprintf(outfile, "# Events [%s/%s] N:\n", detector.component, detector.filename);
        mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p0,
          outfile, detector.istransposed);
      }
      fclose(outfile);

      if (!exists) {
        if (strcasestr(detector.format, "list"))
          printf("Events:   \"%s\"\n",
            strlen(detector.filename) ? detector.filename : detector.component);
      }
    } /* if outfile */
  ); /* MPI_MASTER */
#ifdef USE_MPI
  if (strcasestr(detector.format, "list") && mpi_node_count > 1) {
    int node_i=0;
    /* loop along MPI nodes to write sequentially */
    for(node_i=0; node_i<mpi_node_count; node_i++) {
      /* MPI: slaves wait for the master to write its block, then append theirs */
      MPI_Barrier(MPI_COMM_WORLD);
      if (node_i != mpi_node_root && node_i == mpi_node_rank) {
        if(strlen(detector.filename) && !mcdisable_output_files)	/* Don't write if filename is NULL */
          outfile = mcnew_file(detector.filename, "dat", &exists);
        if (!exists)
          fprintf(stderr, "Warning: [MPI node %i] file '%s' does not exist yet, "
                          "MASTER should have opened it before.\n",
            mpi_node_rank, detector.filename);
        if(outfile) {
          mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p1,
            outfile, detector.istransposed);
          fclose(outfile);
        }
      }
    }
  } /* if strcasestr list */
#endif
  return(detector);
} /* mcdetector_out_2D_ascii */

/*******************************************************************************
* strcpy_valid: makes a valid string for variable names.
*   copy 'original' into 'valid', replacing invalid characters by '_'
*   char arrays must be pre-allocated
*******************************************************************************/
static char *strcpy_valid(char *valid, char *original)
{
  long i;
  int  n=CHAR_BUF_LENGTH; /* max length of valid names */

  if (original == NULL || !strlen(original)) return(NULL);

  if (n > strlen(original)) n = strlen(original);
  else original += strlen(original)-n;
  strncpy(valid, original, n);

  for (i=0; i < n; i++)
  {
    if ( (valid[i] > 122)
      || (valid[i] < 32)
      || (strchr("!\"#$%&'()*+,-.:;<=>?@[\\]^`/ \n\r\t", valid[i]) != NULL) )
    {
      if (i) valid[i] = '_'; else valid[i] = 'm';
    }
  }
  valid[i] = '\0';

  return(valid);
} /* strcpy_valid */

/* end ascii output section ================================================= */







#ifdef USE_NEXUS

/* ========================================================================== */

/*                               NeXus output                                 */

/* ========================================================================== */

#define nxprintf(...)    nxstr('d', __VA_ARGS__)
#define nxprintattr(...) nxstr('a', __VA_ARGS__)

/*******************************************************************************
* nxstr: output a tag=value data set (char) in NeXus/current group
*   when 'format' is larger that 1024 chars it is used as value for the 'tag'
*   else the value is assembled with format and following arguments.
*   type='d' -> data set
*        'a' -> attribute for current data set
*******************************************************************************/
static int nxstr(char type, NXhandle *f, char *tag, char *format, ...)
{
  va_list ap;
  char value[CHAR_BUF_LENGTH];
  int  i;
  int  ret=NX_OK;

  if (!tag || !format || !strlen(tag) || !strlen(format)) return(NX_OK);

  /* assemble the value string */
  if (strlen(format) < CHAR_BUF_LENGTH) {
    va_start(ap, format);
    ret = vsnprintf(value, CHAR_BUF_LENGTH, format, ap);
    va_end(ap);

    i = strlen(value);
  } else {
    i = strlen(format);
  }

  if (type == 'd') {
    /* open/put/close data set */
    if (NXmakedata (f, tag, NX_CHAR, 1, &i) != NX_OK) return(NX_ERROR);
    NXopendata (f, tag);
    if (strlen(format) < CHAR_BUF_LENGTH)
      ret = NXputdata  (f, value);
    else
      ret = NXputdata  (f, format);
    NXclosedata(f);
  } else {
    if (strlen(format) < CHAR_BUF_LENGTH)
      ret = NXputattr  (f, tag, value, strlen(value), NX_CHAR);
    else
      ret = NXputattr  (f, tag, format, strlen(format), NX_CHAR);
  }

  return(ret);

} /* nxstr */

/*******************************************************************************
* mcinfo_readfile: read a full file into a string buffer which is allocated
*   Think to free the buffer after use.
* Used in: mcinfo_out_nexus (nexus)
*******************************************************************************/
char *mcinfo_readfile(char *filename)
{
  FILE *f = fopen(filename, "rb");
  if (!f) return(NULL);
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  rewind(f);
  char *string = malloc(fsize + 1);
  if (string) {
    int n = fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;
  }
  return(string);
}

/*******************************************************************************
* mcinfo_out: output instrument/simulation groups in NeXus file
* Used in: siminfo_init (nexus)
*******************************************************************************/
static void mcinfo_out_nexus(NXhandle f)
{
  FILE  *fid;     /* for intrument source code/C/IDF */
  char  *buffer=NULL;
  time_t t     =time(NULL); /* for date */
  char   entry0[CHAR_BUF_LENGTH];
  int    count=0;
  char   name[CHAR_BUF_LENGTH];
  char   class[CHAR_BUF_LENGTH];

  if (!f || mcdisable_output_files) return;

  /* write NeXus NXroot attributes */
  /* automatically added: file_name, HDF5_Version, file_time, NeXus_version */
  nxprintattr(f, "creator",   "%s generated with " MCCODE_STRING, instrument_name);

  /* count the number of existing NXentry and create the next one */
  NXgetgroupinfo(f, &count, name, class);
  sprintf(entry0, "entry%i", count+1);

  /* create the main NXentry (mandatory in NeXus) */
  if (NXmakegroup(f, entry0, "NXentry") == NX_OK)
  if (NXopengroup(f, entry0, "NXentry") == NX_OK) {
    nxprintf(nxhandle, "program_name", MCCODE_STRING);
    nxprintf(f, "start_time", ctime(&t));
    nxprintf(f, "title", "%s%s%s simulation generated by instrument %s",
      dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name,
      instrument_name);
    nxprintattr(f, "program_name", MCCODE_STRING);
    nxprintattr(f, "instrument",   instrument_name);
    nxprintattr(f, "simulation",   "%s%s%s",
        dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name);

    /* write NeXus instrument group */
    if (NXmakegroup(f, "instrument", "NXinstrument") == NX_OK)
    if (NXopengroup(f, "instrument", "NXinstrument") == NX_OK) {
      int   i;
      char *string=NULL;

      /* write NeXus parameters(types) data =================================== */
      string = (char*)malloc(CHAR_BUF_LENGTH);
      if (string) {
        strcpy(string, "");
        for(i = 0; i < numipar; i++)
        {
          char ThisParam[CHAR_BUF_LENGTH];
          snprintf(ThisParam, CHAR_BUF_LENGTH, " %s(%s)", mcinputtable[i].name,
                  (*mcinputtypes[mcinputtable[i].type].parminfo)
                      (mcinputtable[i].name));
          if (strlen(string) + strlen(ThisParam) < CHAR_BUF_LENGTH)
            strcat(string, ThisParam);
        }
        nxprintattr(f, "Parameters",    string);
        free(string);
      }

      nxprintattr(f, "name",          instrument_name);
      nxprintf   (f, "name",          instrument_name);
      nxprintattr(f, "Source",        instrument_source);

      nxprintattr(f, "Trace_enabled", traceenabled ? "yes" : "no");
      nxprintattr(f, "Default_main",  defaultmain ?  "yes" : "no");
#ifdef MC_EMBEDDED_RUNTIME
      nxprintattr(f, "Embedded_runtime", "yes");
#else
      nxprintattr(f, "Embedded_runtime", "no");
#endif

      /* add instrument source code when available */
      buffer = mcinfo_readfile(instrument_source);
      if (buffer && strlen(buffer)) {
        long length=strlen(buffer);
        nxprintf (f, "description", buffer);
        NXopendata(f,"description");
        nxprintattr(f, "file_name", instrument_source);
        nxprintattr(f, "file_size", "%li", length);
        nxprintattr(f, "MCCODE_STRING", MCCODE_STRING);
        NXclosedata(f);
        nxprintf (f,"instrument_source", "%s " MCCODE_NAME " " MCCODE_PARTICLE " Monte Carlo simulation", instrument_name);
        free(buffer);
      } else
        nxprintf (f, "description", "File %s not found (instrument description %s is missing)",
          instrument_source, instrument_name);

      if (mcnexus_embed_idf) {
        /* add Mantid/IDF.xml when available */
        char *IDFfile=NULL;
        IDFfile = (char*)malloc(CHAR_BUF_LENGTH);
        sprintf(IDFfile,"%s%s",instrument_source,".xml");
        buffer = mcinfo_readfile(IDFfile);
        if (buffer && strlen(buffer)) {
          NXmakegroup (nxhandle, "instrument_xml", "NXnote");
          NXopengroup (nxhandle, "instrument_xml", "NXnote");
          nxprintf(f, "data", buffer);
          nxprintf(f, "description", "IDF.xml file found with instrument %s", instrument_source);
          nxprintf(f, "type", "text/xml");
          NXclosegroup(f); /* instrument_xml */
          free(buffer);
        }
        free(IDFfile);
      }

      /* Add "components" entry */
      if (NXmakegroup(f, "components", "NXdata") == NX_OK) {
        NXopengroup(f, "components", "NXdata");
        nxprintattr(f, "description", "Component list for instrument %s",  instrument_name);
	NXclosegroup(f); /* components */
      } else {
	printf("Failed to create NeXus component hierarchy\n");
      }
      NXclosegroup(f); /* instrument */
    } /* NXinstrument */

    /* write NeXus simulation group */
    if (NXmakegroup(f, "simulation", "NXnote") == NX_OK)
    if (NXopengroup(f, "simulation", "NXnote") == NX_OK) {

      nxprintattr(f, "name",   "%s%s%s",
        dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name);

      nxprintf   (f, "name",      "%s",     siminfo_name);
      nxprintattr(f, "Format",    mcformat && strlen(mcformat) ? mcformat : MCCODE_NAME);
      nxprintattr(f, "URL",       "http://www.mccode.org");
      nxprintattr(f, "program",   MCCODE_STRING);
      nxprintattr(f, "Instrument",instrument_source);
      nxprintattr(f, "Trace",     mcdotrace ?     "yes" : "no");
      nxprintattr(f, "Gravitation",mcgravitation ? "yes" : "no");
      nxprintattr(f, "Seed",      "%li", mcseed);
      nxprintattr(f, "Directory", dirname);
    #ifdef USE_MPI
      if (mpi_node_count > 1)
        nxprintf(f, "Nodes", "%i",        mpi_node_count);
    #endif

      /* output parameter string ================================================ */
      if (NXmakegroup(f, "Param", "NXparameters") == NX_OK) {
	NXopengroup(f,"Param", "NXparameters");
        int i;
        char string[CHAR_BUF_LENGTH];
        for(i = 0; i < numipar; i++) {
          if (mcget_run_num() || (mcinputtable[i].val && strlen(mcinputtable[i].val))) {
            if (mcinputtable[i].par == NULL)
              strncpy(string, (mcinputtable[i].val ? mcinputtable[i].val : ""), CHAR_BUF_LENGTH);
            else
              (*mcinputtypes[mcinputtable[i].type].printer)(string, mcinputtable[i].par);

            nxprintf(f,  mcinputtable[i].name, "%s", string);
            nxprintattr(f, mcinputtable[i].name, string);
          }
        }
        NXclosegroup(f); /* Param */
      } /* NXparameters */
      NXclosegroup(f); /* simulation */
    } /* NXsimulation */

    /* create a group to hold all links for all monitors */
    NXmakegroup(f, "data", "NXdetector");

    /* leave the NXentry opened (closed at exit) */
  } /* NXentry */
} /* mcinfo_out_nexus */

/*******************************************************************************
* mccomp_placement_type_nexus:
*   Places
*    - absolute (3x1) position
*    - absolute (3x3) rotation
*    - type / class of component instance into attributes under
*     entry<N>/instrument/compname
*   requires: NXentry to be opened
*******************************************************************************/
static void mccomp_placement_type_nexus(NXhandle nxhandle, char* component, Coords position, Rotation rotation, char* comptype)
{
  /* open NeXus instrument group */

  #ifdef USE_NEXUS
  if(nxhandle) {
    if (NXopengroup(nxhandle, "instrument", "NXinstrument") == NX_OK) {
      if (NXopengroup(nxhandle, "components", "NXdata") == NX_OK) {
	if (NXmakegroup(nxhandle, component, "NXdata") == NX_OK) {
	  if (NXopengroup(nxhandle, component, "NXdata") == NX_OK) {
	    int64_t pdims[3]; pdims[0]=3; pdims[1]=0; pdims[2]=0;
	    if (NXcompmakedata64(nxhandle, "Position", NX_FLOAT64, 1, pdims, NX_COMPRESSION, pdims) == NX_OK) {
	      if (NXopendata(nxhandle, "Position") == NX_OK) {
		double pos[3]; coords_get(position, &pos[0], &pos[1], &pos[2]);
		if (NXputdata (nxhandle, pos) == NX_OK) {
		  NXclosedata(nxhandle);
		} else {
		  fprintf(stderr, "COULD NOT PUT Position field for component %s\n",component);
		}
	      } else {
		fprintf(stderr, "Warning: could not open Position field for component %s\n",component);
	      }
	    }
	    int64_t rdims[3]; rdims[0]=3; rdims[1]=3; rdims[2]=0;
	    if (NXcompmakedata64(nxhandle, "Rotation", NX_FLOAT64, 2, rdims, NX_COMPRESSION, rdims) == NX_OK) {
	      if (NXopendata(nxhandle, "Rotation") == NX_OK) {
		if (NXputdata (nxhandle, rotation) == NX_OK) {
		  NXclosedata(nxhandle);
		} else {
		  fprintf(stderr, "COULD NOT PUT Rotation field for component %s\n",component);
		}
	      } else {
		fprintf(stderr, "Warning: could not open Rotation field for component %s\n",component);
	      }
	    }
	    nxprintf(nxhandle, "Component_type", comptype);
	    NXclosegroup(nxhandle); // component
	  } else {
	    printf("FAILED to open comp data group %s\n",component);
	  }
	} else {
	  printf("FAILED to create comp data group %s\n",component);
	}
	NXclosegroup(nxhandle); // components
      } else {
	printf("Failed to open NeXus component hierarchy\n");
      }
      NXclosegroup(nxhandle); // instrument
    } else {
      printf("Failed to open NeXus instrument hierarchy\n");
    }
  } else {
    fprintf(stderr,"NO NEXUS FILE\n");
  }
  #endif
} /* mccomp_placement_nexus */

/*******************************************************************************
* mccomp_param_nexus:
*   Output parameter/value pair for component instance into
*   the attribute
*     entry<N>/instrument/compname/parameter
*   requires: NXentry to be opened
*******************************************************************************/
static void mccomp_param_nexus(NXhandle nxhandle, char* component, char* parameter, char* defval, char* value, char* type)
{
  /* open NeXus instrument group */

  #ifdef USE_NEXUS
  if(nxhandle) {
    if (NXopengroup(nxhandle, "instrument", "NXinstrument") == NX_OK) {
      if (NXopengroup(nxhandle, "components", "NXdata") == NX_OK) {
	if (NXopengroup(nxhandle, component, "NXdata") == NX_OK) {
	  NXMDisableErrorReporting(); /* inactivate NeXus error messages, as creation may fail */
	  NXmakegroup(nxhandle, "parameters", "NXdata");
	  NXMEnableErrorReporting();  /* re-enable NeXus error messages */
	  if (NXopengroup(nxhandle, "parameters", "NXdata") == NX_OK) {
	    NXmakegroup(nxhandle, parameter, "NXnote");
	    if (NXopengroup(nxhandle, parameter, "NXnote") == NX_OK) {
	      nxprintattr(nxhandle, "type", type);
	      nxprintattr(nxhandle, "default",  defval);
	      nxprintattr(nxhandle, "value",  value);
	      NXclosegroup(nxhandle); // parameter
	    } else {
	      printf("FAILED to open parameters %s data group \n",parameter);
	    }
	    NXclosegroup(nxhandle); // "parameters"
	  } else {
	    printf("FAILED to open comp/parameters data group \n");
	  }
	  NXclosegroup(nxhandle); // component
	  } else {
	  printf("FAILED to open comp data group %s\n",component);
	}
	NXclosegroup(nxhandle); // components
      } else {
	printf("Failed to open NeXus component hierarchy\n");
      }
      NXclosegroup(nxhandle); // instrument
    } else {
      printf("Failed to open NeXus instrument hierarchy\n");
    }
  } else {
    fprintf(stderr,"NO NEXUS FILE\n");
  }
#endif
} /* mccomp_param_nexus */

/*******************************************************************************
* mcdatainfo_out_nexus: output detector header
*   mcdatainfo_out_nexus(detector) create group and write info to NeXus data file
*   open data:NXdetector then filename:NXdata and write headers/attributes
*   requires: NXentry to be opened
*******************************************************************************/
static void
mcdatainfo_out_nexus(NXhandle f, MCDETECTOR detector)
{
  char data_name[CHAR_BUF_LENGTH];
  if (!f || !detector.m || mcdisable_output_files) return;

  strcpy_valid(data_name,
    strlen(detector.filename) ?
      detector.filename : detector.component);

  /* the NXdetector group has been created in mcinfo_out_nexus (siminfo_init) */
  if (NXopengroup(f, "instrument", "NXinstrument") == NX_OK) {
    if (NXopengroup(f, "components", "NXdata") == NX_OK) {
      NXMDisableErrorReporting(); /* inactivate NeXus error messages, as creation may fail */
      NXmakegroup(f, detector.nexuscomp, "NXdata");
      if (NXopengroup(f, detector.nexuscomp, "NXdata") == NX_OK) {
	NXmakegroup(f, "output", "NXdetector");
	if (NXopengroup(f, "output", "NXdetector") == NX_OK) {
	  if (NXmakegroup(f, data_name, "NXdata") == NX_OK) {
	    if (NXopengroup(f, data_name, "NXdata") == NX_OK) {
	      /* output metadata (as attributes) ======================================== */
	      nxprintattr(f, "Date",       detector.date);
	      nxprintattr(f, "type",       detector.type);
	      nxprintattr(f, "Source",     detector.instrument);
	      nxprintattr(f, "component",  detector.component);
	      nxprintattr(f, "position",   detector.position);

	      nxprintattr(f, "title",      detector.title);
	      nxprintattr(f, !mcget_run_num() || mcget_run_num() >= mcget_ncount() ?
			  "Ncount" :
			  "ratio",  detector.ncount);

	      if (strlen(detector.filename)) {
		nxprintattr(f, "filename", detector.filename);
	      }

	      nxprintattr(f, "statistics", detector.statistics);
	      nxprintattr(f, "signal",     detector.signal);
	      nxprintattr(f, "values",     detector.values);

	      if (detector.rank >= 1)
		{
		  nxprintattr(f, "xvar",     detector.xvar);
		  nxprintattr(f, "yvar",     detector.yvar);
		  nxprintattr(f, "xlabel",   detector.xlabel);
		  nxprintattr(f, "ylabel",   detector.ylabel);
		  if (detector.rank > 1) {
		    nxprintattr(f, "zvar",   detector.zvar);
		    nxprintattr(f, "zlabel", detector.zlabel);
		  }
		}

	      nxprintattr(f, abs(detector.rank)==1 ?
			  "xlimits" :
			  "xylimits", detector.limits);
	      nxprintattr(f, "variables",
			  strcasestr(detector.format, "list") ? detector.ylabel : detector.variables);

	      NXclosegroup(f); // data_name
	    }
	  }
	}
	NXclosegroup(f); // output
	NXclosegroup(f); // detector.nexuscomp
      }
      NXclosegroup(f); // components
    }
    NXMEnableErrorReporting();  /* re-enable NeXus error messages */
    NXclosegroup(f); // instrument
  } /* NXdetector (instrument) */ 
} /* mcdatainfo_out_nexus */

/*******************************************************************************
* mcdetector_out_axis_nexus: write detector axis into current NXdata
*   requires: NXdata to be opened
*******************************************************************************/
int mcdetector_out_axis_nexus(NXhandle f, char *label, char *var, int rank, long length, double min, double max)
{
  if (!f || length <= 1 || mcdisable_output_files || max == min) return(NX_OK);
  else {
    double *axis;
    axis=malloc(sizeof(double)*length);
    if (!axis ) {
      printf("Fatal memory error allocating NeXus axis of length %li, exiting!\n", length);
      return(NX_ERROR);
    }
    char *valid;
    valid=malloc(sizeof(char)*CHAR_BUF_LENGTH);
    if (!valid ) {
      printf("Fatal memory error allocating label axis of length %i, exiting!\n", CHAR_BUF_LENGTH);
      free(axis);
      return(NX_ERROR);
    }
    int dim=(int)length;
    int i;
    int nprimary=1;
    /* create an axis from [min:max] */
    for(i = 0; i < length; i++)
      axis[i] = min+(max-min)*(i+0.5)/length;
    /* create the data set */
    strcpy_valid(valid, label);
    NXcompmakedata(f, valid, NX_FLOAT64, 1, &dim, NX_COMPRESSION, &dim);
    /* open it */
    if (NXopendata(f, valid) != NX_OK) {
      fprintf(stderr, "Warning: could not open axis rank %i '%s' (NeXus)\n",
        rank, valid);
      free(axis);
      free(valid);
      return(NX_ERROR);
    }
    /* put the axis and its attributes */
    NXputdata  (f, axis);
    nxprintattr(f, "long_name",  label);
    nxprintattr(f, "short_name", var);
    NXputattr  (f, "axis",       &rank,     1, NX_INT32);
    nxprintattr(f, "units",      var);
    NXputattr  (f, "primary",    &nprimary, 1, NX_INT32);
    NXclosedata(f);
    free(axis);
    free(valid);
    return(NX_OK);
  }
} /* mcdetector_out_axis_nexus */

/*******************************************************************************
* mcdetector_out_array_nexus: write detector array into current NXdata (1D,2D)
*   requires: NXdata to be opened
*******************************************************************************/
int mcdetector_out_array_nexus(NXhandle f, char *part, double *data, MCDETECTOR detector)
{

  int64_t dims[3]={detector.m,detector.n,detector.p};  /* number of elements to write */
  int64_t fulldims[3]={detector.m,detector.n,detector.p};
  int signal=1;
  int exists=0;
  int64_t current_dims[3]={0,0,0};
  int ret=NX_OK;

  if (!f || !data || !detector.m || mcdisable_output_files) return(NX_OK);

  /* when this is a list, we set 1st dimension to NX_UNLIMITED for creation */
  if (strcasestr(detector.format, "list")) fulldims[0] = NX_UNLIMITED;

  /* create the data set in NXdata group */
  NXMDisableErrorReporting(); /* inactivate NeXus error messages, as creation may fail */
  ret = NXcompmakedata64(f, part, NX_FLOAT64, detector.rank, fulldims, NX_COMPRESSION, dims);
  if (ret != NX_OK) {
    /* failed: data set already exists */
    int datatype=0;
    int rank=0;
    exists=1;
    /* inquire current size of data set (nb of events stored) */
    NXopendata(f, part);
    NXgetinfo64(f, &rank, current_dims, &datatype);
    NXclosedata(f);
  }
  NXMEnableErrorReporting();  /* re-enable NeXus error messages */

  /* open the data set */
  if (NXopendata(f, part) == NX_ERROR) {
    fprintf(stderr, "Warning: could not open DataSet %s '%s' (NeXus)\n",
      part, detector.title);
    return(NX_ERROR);
  }
  if (strcasestr(detector.format, "list")) {
    current_dims[1] = current_dims[2] = 0; /* set starting location for writing slab */
    NXputslab64(f, data, current_dims, dims);
    if (!exists)
      printf("Events:   \"%s\"\n",
        strlen(detector.filename) ? detector.filename : detector.component);
    else
      printf("Append:   \"%s\"\n",
	     strlen(detector.filename) ? detector.filename : detector.component);
  } else {
    NXputdata (f, data);
  }

  if (strstr(part,"data") || strstr(part, "events")) {
    NXputattr(f, "signal", &signal, 1, NX_INT32);
    nxprintattr(f, "short_name", strlen(detector.filename) ?
      detector.filename : detector.component);
  }
  nxprintattr(f, "long_name", "%s '%s'", part, detector.title);
  NXclosedata(f);

  return(NX_OK);
} /* mcdetector_out_array_nexus */

/*******************************************************************************
* mcdetector_out_data_nexus: write detector axes+data into current NXdata
*   The data:NXdetector is opened, then filename:NXdata
*   requires: NXentry to be opened
*******************************************************************************/
int mcdetector_out_data_nexus(NXhandle f, MCDETECTOR detector)
{
  char data_name[CHAR_BUF_LENGTH];

  if (!f || !detector.m || mcdisable_output_files) return(NX_OK);

  strcpy_valid(data_name,
    strlen(detector.filename) ?
      detector.filename : detector.component);
  NXlink pLink;
  /* the NXdetector group has been created in mcinfo_out_nexus (siminfo_init) */
  if (NXopengroup(f, "instrument", "NXinstrument") == NX_OK) {
    if (NXopengroup(f, "components", "NXdata") == NX_OK) {
      if (NXopengroup(f, detector.nexuscomp, "NXdata") == NX_OK) {
	if (NXopengroup(f, "output", "NXdetector") == NX_OK) {

	  /* the NXdata group has been created in mcdatainfo_out_nexus */
	  if (NXopengroup(f, data_name, "NXdata") == NX_OK) {
	    
	    MPI_MASTER(
		       nxprintattr(f, "options",
				   strlen(detector.options) ? detector.options : "None");
		       );
	    /* write axes, for histogram data sets, not for lists */
	    if (!strcasestr(detector.format, "list")) {
	      mcdetector_out_axis_nexus(f, detector.xlabel, detector.xvar,
					1, detector.m, detector.xmin, detector.xmax);
	      mcdetector_out_axis_nexus(f, detector.ylabel, detector.yvar,
					2, detector.n, detector.ymin, detector.ymax);
	      mcdetector_out_axis_nexus(f, detector.zlabel, detector.zvar,
					3, detector.p, detector.zmin, detector.zmax); 
	    } else {
	      	    MPI_MASTER(
			       nxprintattr(f, "dataset columns",
					   strlen(detector.ylabel) ? detector.ylabel : "None");
		    );
	    }

	    /* write the actual data (appended if already exists) */
	    if (!strcasestr(detector.format, "list") && !strcasestr(detector.format, "pixels")) {
	      mcdetector_out_array_nexus(f, "data", detector.p1, detector);
	      mcdetector_out_array_nexus(f, "errors", detector.p2, detector);
	      mcdetector_out_array_nexus(f, "ncount", detector.p0, detector);
	    } else if (strcasestr(detector.format, "pixels")) {
	      mcdetector_out_array_nexus(  f, "pixels", detector.p1, detector);
	    } else {
	      mcdetector_out_array_nexus(  f, "events", detector.p1, detector);
	    }
	    NXclosegroup(f);
	    NXopengroup(f, data_name, "NXdata");
	    NXgetgroupID(nxhandle, &pLink);
	    NXclosegroup(f);
	  } /* NXdata data_name*/
	  NXclosegroup(f);
	} /* NXdetector output */
	NXclosegroup(f);
      } /* NXdata detector.nexuscomp */
      NXclosegroup(f);
    } /* NXdata components */
    NXclosegroup(f);
  } /* NXdata instrument */
  
  if (!strcasestr(detector.format, "pixels")) {
    if (NXopengroup(f, "data", "NXdetector") == NX_OK) {
      NXmakelink(nxhandle, &pLink);
      NXclosegroup(f);
    }
  }
  return(NX_OK);
} /* mcdetector_out_array_nexus */

#ifdef USE_MPI
/*******************************************************************************
* mcdetector_out_list_slaves: slaves send their list data to master which writes
*   requires: NXentry to be opened
* WARNING: this method has a flaw: it requires all nodes to flush the lists
*   the same number of times. In case one node is just below the buffer size
*   when finishing (e.g. monitor_nd), it may not trigger save but others may.
*   Then the number of recv/send is not constant along nodes, and simulation stalls.
*******************************************************************************/
MCDETECTOR mcdetector_out_list_slaves(MCDETECTOR detector)
{
  int     node_i=0;
  MPI_MASTER(
	     printf("\n** MPI master gathering slave node list data ** \n");
  );

  if (mpi_node_rank != mpi_node_root) {
    /* MPI slave: slaves send their data to master: 2 MPI_Send calls */
    /* m, n, p must be sent first, since all slaves do not have the same number of events */
    int mnp[3]={detector.m,detector.n,detector.p};

    if (mc_MPI_Send(mnp, 3, MPI_INT, mpi_node_root)!= MPI_SUCCESS)
      fprintf(stderr, "Warning: proc %i to master: MPI_Send mnp list error (mcdetector_out_list_slaves)\n", mpi_node_rank);
    if (!detector.p1
     || mc_MPI_Send(detector.p1, mnp[0]*mnp[1]*mnp[2], MPI_DOUBLE, mpi_node_root) != MPI_SUCCESS)
      fprintf(stderr, "Warning: proc %i to master: MPI_Send p1 list error: mnp=%i (mcdetector_out_list_slaves)\n", mpi_node_rank, abs(mnp[0]*mnp[1]*mnp[2]));
    /* slaves are done: sent mnp and p1 */
  } /* end slaves */

  /* MPI master: receive data from slaves sequentially: 2 MPI_Recv calls */

  if (mpi_node_rank == mpi_node_root) {
    for(node_i=0; node_i<mpi_node_count; node_i++) {
      double *this_p1=NULL;                               /* buffer to hold the list from slaves */
      int     mnp[3]={0,0,0};  /* size of this buffer */
      if (node_i != mpi_node_root) { /* get data from slaves */
	if (mc_MPI_Recv(mnp, 3, MPI_INT, node_i) != MPI_SUCCESS)
	  fprintf(stderr, "Warning: master from proc %i: "
		  "MPI_Recv mnp list error (mcdetector_write_data)\n", node_i);
	if (mnp[0]*mnp[1]*mnp[2]) {
	  this_p1 = (double *)calloc(mnp[0]*mnp[1]*mnp[2], sizeof(double));
	  if (!this_p1 || mc_MPI_Recv(this_p1, abs(mnp[0]*mnp[1]*mnp[2]), MPI_DOUBLE, node_i)!= MPI_SUCCESS)
	    fprintf(stderr, "Warning: master from proc %i: "
		    "MPI_Recv p1 list error: mnp=%i (mcdetector_write_data)\n", node_i, mnp[0]*mnp[1]*mnp[2]);
	  else {
	    printf(". MPI master writing data for slave node %i\n",node_i);
	    detector.p1 = this_p1;
	    detector.m  = mnp[0]; detector.n  = mnp[1]; detector.p  = mnp[2];

	    mcdetector_out_data_nexus(nxhandle, detector);
	  }
	}
      } /* if not master */
      free(this_p1);
    } /* for */
  MPI_MASTER(
	     printf("\n** Done ** \n");
  );
  }
  // Common return statement for slaves / master alike
  return(detector);
}
#endif

MCDETECTOR mcdetector_out_0D_nexus(MCDETECTOR detector)
{
  /* Write data set information to NeXus file. */
  MPI_MASTER(
    mcdatainfo_out_nexus(nxhandle, detector);
  );

  return(detector);
} /* mcdetector_out_0D_ascii */

MCDETECTOR mcdetector_out_1D_nexus(MCDETECTOR detector)
{
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );
  return(detector);
} /* mcdetector_out_1D_ascii */

MCDETECTOR mcdetector_out_2D_nexus(MCDETECTOR detector)
{
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );

#ifdef USE_MPI // and USE_NEXUS
  /* NeXus: slave nodes have master write their lists */
  if (strcasestr(detector.format, "list") && mpi_node_count > 1) {
    mcdetector_out_list_slaves(detector);
  }
#endif /* USE_MPI */

  return(detector);
} /* mcdetector_out_2D_nexus */

MCDETECTOR mcdetector_out_3D_nexus(MCDETECTOR detector)
{
  printf("Received detector from %s\n",detector.component);
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );
  return(detector);
} /* mcdetector_out_3D_nexus */


#endif /* USE_NEXUS*/








/* ========================================================================== */

/*                            Main input functions                            */
/*            DETECTOR_OUT_xD function calls -> ascii or NeXus                */

/* ========================================================================== */

/*******************************************************************************
* siminfo_init:   open SIM and write header
*******************************************************************************/
FILE *siminfo_init(FILE *f)
{
  int exists=0;

  /* check format */
  if (!mcformat || !strlen(mcformat)
   || !strcasecmp(mcformat, "MCSTAS") || !strcasecmp(mcformat, "MCXTRACE")
   || !strcasecmp(mcformat, "PGPLOT") || !strcasecmp(mcformat, "GNUPLOT") || !strcasecmp(mcformat, "MCCODE")
   || !strcasecmp(mcformat, "MATLAB")) {
    mcformat="McCode";
#ifdef USE_NEXUS
  } else if (strcasestr(mcformat, "NeXus")) {
    /* Do nothing */
#endif
  } else {
    fprintf(stderr,
	    "Warning: You have requested the output format %s which is unsupported by this binary. Resetting to standard %s format.\n",mcformat ,"McCode");
    mcformat="McCode";
  }

  /* open the SIM file if not defined yet */
  if (siminfo_file || mcdisable_output_files)
    return (siminfo_file);

#ifdef USE_NEXUS
  /* only master writes NeXus header: calls NXopen(nxhandle) */
  if (mcformat && strcasestr(mcformat, "NeXus")) {
	  MPI_MASTER(
	  siminfo_file = mcnew_file(siminfo_name, "h5", &exists);
    if(!siminfo_file)
      fprintf(stderr,
	      "Warning: could not open simulation description file '%s'\n",
	      siminfo_name);
	  else
	    mcinfo_out_nexus(nxhandle);
	  );
    return(siminfo_file); /* points to nxhandle */
  }
#endif

  /* write main description file (only MASTER) */
  MPI_MASTER(

  siminfo_file = mcnew_file(siminfo_name, "sim", &exists);
  if(!siminfo_file)
    fprintf(stderr,
	    "Warning: could not open simulation description file '%s'\n",
	    siminfo_name);
  else
  {
    /* write SIM header */
    time_t t=time(NULL);
    siminfo_out("%s simulation description file for %s.\n",
      MCCODE_NAME, instrument_name);
    siminfo_out("Date:    %s", ctime(&t)); /* includes \n */
    siminfo_out("Program: %s\n\n", MCCODE_STRING);

    siminfo_out("begin instrument: %s\n", instrument_name);
    mcinfo_out(   "  ", siminfo_file);
    siminfo_out("end instrument\n");

    siminfo_out("\nbegin simulation: %s\n", dirname);
    mcruninfo_out("  ", siminfo_file);
    siminfo_out("end simulation\n");

  }
  ); /* MPI_MASTER */
  return (siminfo_file);

} /* siminfo_init */

/*******************************************************************************
*   siminfo_close:  close SIM
*******************************************************************************/
void siminfo_close()
{
#ifdef USE_MPI
  if(mpi_node_rank == mpi_node_root) {
#endif
  if(siminfo_file && !mcdisable_output_files) {
#ifdef USE_NEXUS
    if (mcformat && strcasestr(mcformat, "NeXus")) {
      time_t t=time(NULL);
      nxprintf(nxhandle, "end_time", ctime(&t));
      nxprintf(nxhandle, "duration", "%li", (long)t-mcstartdate);
      NXclosegroup(nxhandle); /* NXentry */
      NXclose(&nxhandle);
    } else {
#endif
      fclose(siminfo_file);
#ifdef USE_NEXUS
    }
#endif
#ifdef USE_MPI
  }
#endif
    siminfo_file = NULL;
  }
} /* siminfo_close */

/*******************************************************************************
* mcdetector_out_0D: wrapper for 0D (single value).
*   Output single detector/monitor data (p0, p1, p2).
*   Title is t, component name is c.
*******************************************************************************/
MCDETECTOR mcdetector_out_0D(char *t, double p0, double p1, double p2,
			     char *c, Coords posa, Rotation rota, int index)
{
  /* import and perform basic detector analysis (and handle MPI reduce) */
  MCDETECTOR detector = detector_import(mcformat,
    c, (t ? t : MCCODE_STRING " data"),
    1, 1, 1,
    "I", "", "",
    "I", "", "",
    0, 0, 0, 0, 0, 0, c,
    &p0, &p1, &p2, posa, rota, index); /* write Detector: line */

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_0D_nexus(detector));
  else
#endif
    return(mcdetector_out_0D_ascii(detector));

} /* mcdetector_out_0D */



/*******************************************************************************
* mcdetector_out_1D: wrapper for 1D.
*   Output 1d detector data (p0, p1, p2) for n bins linearly
*   distributed across the range x1..x2 (x1 is lower limit of first
*   bin, x2 is upper limit of last bin). Title is t, axis labels are xl
*   and yl. File name is f, component name is c.
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   xvar: measured variable length
*   x1:   x axus min
*   x2:   x axis max
*   n:    1d data vector lenght
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_1D(char *t, char *xl, char *yl,
        char *xvar, double x1, double x2,
        long n,
        double *p0, double *p1, double *p2, char *f,
        char *c, Coords posa, Rotation rota, int index)
{
  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  // detector_import calls mcdetector_statistics, which will return different
  // MCDETECTOR versions for 1-D data based on the value of mcformat.
  //
  MCDETECTOR detector = detector_import(mcformat,
    c, (t ? t : MCCODE_STRING " 1D data"),
    n, 1, 1,
    xl, yl, (n > 1 ? "Signal per bin" : " Signal"),
    xvar, "(I,I_err)", "I",
    x1, x2, 0, 0, 0, 0, f,
    p0, p1, p2, posa, rota, index); /* write Detector: line */
  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    detector = mcdetector_out_1D_nexus(detector);
  else
#endif
    detector = mcdetector_out_1D_ascii(detector);
  if (detector.p1 != p1 && detector.p1) {
    // mcdetector_statistics allocated memory but it hasn't been freed.
    free(detector.p1);
    // plus undo the other damage done there:
    detector.p0 = p0; // was set to NULL
    detector.p1 = p1; // was set to this_p1
    detector.p2 = p2; // was set to NULL
    detector.m = detector.n; // (e.g., labs(n))
    detector.n = 1;  // not (n x n)
    detector.istransposed = n < 0 ? 1 : 0;
  }
  return detector;

} /* mcdetector_out_1D */

/*******************************************************************************
* mcdetector_out_2D: wrapper for 2D.
*   Special case for list: master creates file first, then slaves append their
*   blocks without header-
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   x1:   x axus min
*   x2:   x axis max
*   y1:   y axis min
*   y2:   y axis max
*   m:    dim 1 (x) size
*   n:    dim 2 (y) size
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*   rota: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_2D(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2,
                  long m, long n,
                  double *p0, double *p1, double *p2, char *f,
		  char *c, Coords posa, Rotation rota, int index)
{
  char xvar[CHAR_BUF_LENGTH];
  char yvar[CHAR_BUF_LENGTH];

  /* create short axes labels */
  if (xl && strlen(xl)) { strncpy(xvar, xl, CHAR_BUF_LENGTH); xvar[2]='\0'; }
  else strcpy(xvar, "x");
  if (yl && strlen(yl)) { strncpy(yvar, yl, CHAR_BUF_LENGTH); yvar[2]='\0'; }
  else strcpy(yvar, "y");

  MCDETECTOR detector;

  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  if (labs(m) == 1) {/* n>1 on Y, m==1 on X: 1D, no X axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      n, 1, 1,
      yl, "", "Signal per bin",
      yvar, "(I,Ierr)", "I",
      y1, y2, x1, x2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  } else if (labs(n)==1) {/* m>1 on X, n==1 on Y: 1D, no Y axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      m, 1, 1,
      xl, "", "Signal per bin",
      xvar, "(I,Ierr)", "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  }else {
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 2D data"),
      m, n, 1,
      xl, yl, "Signal per bin",
      xvar, yvar, "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  }

  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_2D_nexus(detector));
  else
#endif
    return(mcdetector_out_2D_ascii(detector));

} /* mcdetector_out_2D */

/*******************************************************************************
* mcdetector_out_2D_list: List mode 2D including forwarding "options" from
* Monitor_nD
*
*   Special case for list: master creates file first, then slaves append their
*   blocks without header-
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   x1:   x axus min
*   x2:   x axis max
*   y1:   y axis min
*   y2:   y axis max
*   m:    dim 1 (x) size
*   n:    dim 2 (y) size
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*   rota: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_2D_list(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2,
                  long m, long n,
                  double *p0, double *p1, double *p2, char *f,
		  char *c, Coords posa, Rotation rota, char* options, int index)
{
  char xvar[CHAR_BUF_LENGTH];
  char yvar[CHAR_BUF_LENGTH];

  /* create short axes labels */
  if (xl && strlen(xl)) { strncpy(xvar, xl, CHAR_BUF_LENGTH); xvar[2]='\0'; }
  else strcpy(xvar, "x");
  if (yl && strlen(yl)) { strncpy(yvar, yl, CHAR_BUF_LENGTH); yvar[2]='\0'; }
  else strcpy(yvar, "y");

  MCDETECTOR detector;

  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  if (labs(m) == 1) {/* n>1 on Y, m==1 on X: 1D, no X axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      n, 1, 1,
      yl, "", "Signal per bin",
      yvar, "(I,Ierr)", "I",
      y1, y2, x1, x2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  } else if (labs(n)==1) {/* m>1 on X, n==1 on Y: 1D, no Y axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      m, 1, 1,
      xl, "", "Signal per bin",
      xvar, "(I,Ierr)", "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  }else {
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 2D data"),
      m, n, 1,
      xl, yl, "Signal per bin",
      xvar, yvar, "I",
      x1, x2, y1, y2, 0, 0, f,
     p0, p1, p2, posa, rota, index); /* write Detector: line */
  }

  MPI_MASTER(
  if (strlen(options)) {
    strcpy(detector.options,options);
  } else {
    strcpy(detector.options,"None");
  }
  );

  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_2D_nexus(detector));
  else
#endif
    return(mcdetector_out_2D_ascii(detector));

} /* mcdetector_out_2D_list */

/*******************************************************************************
* mcdetector_out_list: wrapper for list output (calls out_2D with mcformat+"list").
*   m=number of events, n=size of each event
*******************************************************************************/
MCDETECTOR mcdetector_out_list(char *t, char *xl, char *yl,
                  long m, long n,
                  double *p1, char *f,
			       char *c, Coords posa, Rotation rota, char* options, int index)
{
  char       format_new[CHAR_BUF_LENGTH];
  char      *format_org;
  MCDETECTOR detector;

  format_org = mcformat;
  strcpy(format_new, mcformat);
  strcat(format_new, " list");
  mcformat = format_new;
  detector = mcdetector_out_2D_list(t, xl, yl,
                  1,labs(m),1,labs(n),
                  m,n,
                  NULL, p1, NULL, f,
		  c, posa,rota,options, index);

  mcformat = format_org;
  return(detector);
}

/*******************************************************************************
 * mcuse_dir: set data/sim storage directory and create it,
 * or exit with error if exists
 ******************************************************************************/
static void
mcuse_dir(char *dir)
{
  if (!dir || !strlen(dir)) return;
#ifdef MC_PORTABLE
  fprintf(stderr, "Error: "
          "Directory output cannot be used with portable simulation (mcuse_dir)\n");
  exit(1);
#else  /* !MC_PORTABLE */
  /* handle file://directory URL type */
  if (strncmp(dir, "file://", strlen("file://")))
    dirname = dir;
  else
    dirname = dir+strlen("file://");


#ifdef USE_MPI
  if(mpi_node_rank == mpi_node_root) {
#endif
    int exists=0;
    DIR* handle = opendir(dirname);
    if (handle) {
      /* Directory exists. */
      closedir(handle);
      exists=1;
    }
    if(mkdir(dirname, 0777)) {
#ifndef DANSE
      if(!mcappend) {
	fprintf(stderr, "Error: unable to create directory '%s' (mcuse_dir)\n", dir);
	fprintf(stderr, "(Maybe the directory already exists?)\n");
#endif
#ifdef USE_MPI
	MPI_Abort(MPI_COMM_WORLD, -1);
#endif
	exit(-1);
      }
    }
#ifdef USE_MPI
    }
#endif

  /* remove trailing PATHSEP (if any) */
  while (strlen(dirname) && dirname[strlen(dirname) - 1] == MC_PATHSEP_C)
    dirname[strlen(dirname) - 1]='\0';
#endif /* !MC_PORTABLE */
} /* mcuse_dir */

/*******************************************************************************
* mcinfo: display instrument simulation info to stdout and exit
*******************************************************************************/
static void
mcinfo(void)
{
  fprintf(stdout, "begin instrument: %s\n", instrument_name);
  mcinfo_out("  ", stdout);
  fprintf(stdout, "end instrument\n");
  fprintf(stdout, "begin simulation: %s\n", dirname ? dirname : ".");
  mcruninfo_out("  ", stdout);
  fprintf(stdout, "end simulation\n");
  exit(0); /* includes MPI_Finalize in MPI mode */
} /* mcinfo */

/*******************************************************************************
* mcparameterinfo: display instrument parameter info to stdout and exit
*******************************************************************************/
static void
mcparameterinfo(void)
{
  mcparameterinfo_out("  ", stdout);
  exit(0); /* includes MPI_Finalize in MPI mode */
} /* mcparameterinfo */



#endif /* ndef MCCODE_R_IO_C */

/* end of the I/O section =================================================== */







/*******************************************************************************
* mcset_ncount: set total number of rays to generate
*******************************************************************************/
void mcset_ncount(unsigned long long int count)
{
  mcncount = count;
}

/* mcget_ncount: get total number of rays to generate */
unsigned long long int mcget_ncount(void)
{
  return mcncount;
}

/* mcget_run_num: get curent number of rays */
/* Within the TRACE scope we are now using _particle->uid directly */
unsigned long long int mcget_run_num() // shuld be (_class_particle* _particle) somehow
{
  /* This function only remains for the few cases outside TRACE where we need to know
     the number of simulated particles */
  return mcrun_num;
}

/* mcsetn_arg: get ncount from a string argument */
static void
mcsetn_arg(char *arg)
{
  mcset_ncount((long long int) strtod(arg, NULL));
}

/* mcsetseed: set the random generator seed from a string argument */
static void
mcsetseed(char *arg)
{
  mcseed = atol(arg);
  if(!mcseed) {
  //  srandom(mcseed);
  //} else {
    fprintf(stderr, "Error: seed must not be zero (mcsetseed)\n");
    exit(1);
  }
}

/* Following part is only embedded when not redundent with mccode-r.h ========= */

#ifndef MCCODE_H

/* SECTION: MCDISPLAY support. =============================================== */

/*******************************************************************************
* Just output MCDISPLAY keywords to be caught by an external plotter client.
*******************************************************************************/

void mcdis_magnify(char *what){
  // Do nothing here, better use interactive zoom from the tools
}

void mcdis_line(double x1, double y1, double z1,
                double x2, double y2, double z2){
  printf("MCDISPLAY: multiline(2,%g,%g,%g,%g,%g,%g)\n",
         x1,y1,z1,x2,y2,z2);
}

void mcdis_dashed_line(double x1, double y1, double z1,
		       double x2, double y2, double z2, int n){
  int i;
  const double dx = (x2-x1)/(2*n+1);
  const double dy = (y2-y1)/(2*n+1);
  const double dz = (z2-z1)/(2*n+1);

  for(i = 0; i < n+1; i++)
    mcdis_line(x1 + 2*i*dx,     y1 + 2*i*dy,     z1 + 2*i*dz,
	       x1 + (2*i+1)*dx, y1 + (2*i+1)*dy, z1 + (2*i+1)*dz);
}

void mcdis_multiline(int count, ...){
  va_list ap;
  double x,y,z;

  printf("MCDISPLAY: multiline(%d", count);
  va_start(ap, count);
  while(count--)
    {
    x = va_arg(ap, double);
    y = va_arg(ap, double);
    z = va_arg(ap, double);
    printf(",%g,%g,%g", x, y, z);
    }
  va_end(ap);
  printf(")\n");
}

void mcdis_rectangle(char* plane, double x, double y, double z,
		     double width, double height){
  /* draws a rectangle in the plane           */
  /* x is ALWAYS width and y is ALWAYS height */
  if (strcmp("xy", plane)==0) {
    mcdis_multiline(5,
		    x - width/2, y - height/2, z,
		    x + width/2, y - height/2, z,
		    x + width/2, y + height/2, z,
		    x - width/2, y + height/2, z,
		    x - width/2, y - height/2, z);
  } else if (strcmp("xz", plane)==0) {
    mcdis_multiline(5,
		    x - width/2, y, z - height/2,
		    x + width/2, y, z - height/2,
		    x + width/2, y, z + height/2,
		    x - width/2, y, z + height/2,
		    x - width/2, y, z - height/2);
  } else if (strcmp("yz", plane)==0) {
    mcdis_multiline(5,
		    x, y - height/2, z - width/2,
		    x, y - height/2, z + width/2,
		    x, y + height/2, z + width/2,
		    x, y + height/2, z - width/2,
		    x, y - height/2, z - width/2);
  } else {

    fprintf(stderr, "Error: Definition of plane %s unknown\n", plane);
    exit(1);
  }
}

void mcdis_circle(char *plane, double x, double y, double z, double r){
  printf("MCDISPLAY: circle('%s',%g,%g,%g,%g)\n", plane, x, y, z, r);
}

void mcdis_new_circle(double x, double y, double z, double r, double nx, double ny, double nz){
  printf("MCDISPLAY: new_circle(%g,%g,%g,%g,%g,%g,%g)\n", x, y, z, r, nx, ny, nz);
}


/* Draws a circle with center (x,y,z), radius (r), and in the plane
 * with normal (nx,ny,nz)*/
void mcdis_Circle(double x, double y, double z, double r, double nx, double ny, double nz){
    int i;
    if(nx==0 && ny && nz==0){
        for (i=0;i<24; i++){
            mcdis_line(x+r*sin(i*2*PI/24),y,z+r*cos(i*2*PI/24),
                    x+r*sin((i+1)*2*PI/24),y,z+r*cos((i+1)*2*PI/24));
        }
    }else{
        double mx,my,mz;
        /*generate perpendicular vector using (nx,ny,nz) and (0,1,0)*/
        vec_prod(mx,my,mz, 0,1,0, nx,ny,nz);
        NORM(mx,my,mz);
        /*draw circle*/
        for (i=0;i<24; i++){
            double ux,uy,uz;
            double wx,wy,wz;
            rotate(ux,uy,uz, mx,my,mz, i*2*PI/24, nx,ny,nz);
            rotate(wx,wy,wz, mx,my,mz, (i+1)*2*PI/24, nx,ny,nz);
            mcdis_line(x+ux*r,y+uy*r,z+uz*r,
                    x+wx*r,y+wy*r,z+wz*r);
        }
    }
}


/*  OLD IMPLEMENTATION
    draws a box with center at (x, y, z) and
    width (deltax), height (deltay), length (deltaz) */
void mcdis_legacy_box(double x, double y, double z,
	       double width, double height, double length){

  mcdis_rectangle("xy", x, y, z-length/2, width, height);
  mcdis_rectangle("xy", x, y, z+length/2, width, height);
  mcdis_line(x-width/2, y-height/2, z-length/2,
	     x-width/2, y-height/2, z+length/2);
  mcdis_line(x-width/2, y+height/2, z-length/2,
	     x-width/2, y+height/2, z+length/2);
  mcdis_line(x+width/2, y-height/2, z-length/2,
	     x+width/2, y-height/2, z+length/2);
  mcdis_line(x+width/2, y+height/2, z-length/2,
	     x+width/2, y+height/2, z+length/2);
}

/*  NEW 3D IMPLEMENTATION OF BOX SUPPORTS HOLLOW ALSO
    draws a box with center at (x, y, z) and
    width (deltax), height (deltay), length (deltaz) */
void mcdis_box(double x, double y, double z,
	       double width, double height, double length, double thickness, double nx, double ny, double nz){
  if (mcdotrace==2) {
    printf("MCDISPLAY: box(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g)\n", x, y, z, width, height, length, thickness, nx, ny, nz);
  } else {
    mcdis_legacy_box(x, y, z, width, height, length);
    if (thickness)
      mcdis_legacy_box(x, y, z, width-thickness, height-thickness, length);
  }
}


/* OLD IMPLEMENTATION
Draws a cylinder with center at (x,y,z) with extent (r,height).
 * The cylinder axis is along the vector nx,ny,nz. */
void mcdis_legacy_cylinder( double x, double y, double z,
        double r, double height, int N, double nx, double ny, double nz){
    int i;
    /*no lines make little sense - so trigger the default*/
    if(N<=0) N=5;

    NORM(nx,ny,nz);
    double h_2=height/2.0;
    mcdis_Circle(x+nx*h_2,y+ny*h_2,z+nz*h_2,r,nx,ny,nz);
    mcdis_Circle(x-nx*h_2,y-ny*h_2,z-nz*h_2,r,nx,ny,nz);

    double mx,my,mz;
    /*generate perpendicular vector using (nx,ny,nz) and (0,1,0)*/
    if(nx==0 && ny && nz==0){
        mx=my=0;mz=1;
    }else{
        vec_prod(mx,my,mz, 0,1,0, nx,ny,nz);
        NORM(mx,my,mz);
    }
    /*draw circle*/
    for (i=0; i<24; i++){
        double ux,uy,uz;
        rotate(ux,uy,uz, mx,my,mz, i*2*PI/24, nx,ny,nz);
        mcdis_line(x+nx*h_2+ux*r, y+ny*h_2+uy*r, z+nz*h_2+uz*r,
                 x-nx*h_2+ux*r, y-ny*h_2+uy*r, z-nz*h_2+uz*r);
    }
}

/* NEW 3D IMPLEMENTATION ALSO SUPPORTING HOLLOW
Draws a cylinder with center at (x,y,z) with extent (r,height).
 * The cylinder axis is along the vector nx,ny,nz.*/
void mcdis_cylinder( double x, double y, double z,
        double r, double height, double thickness, double nx, double ny, double nz){
  if (mcdotrace==2) {
      printf("MCDISPLAY: cylinder(%g, %g, %g, %g, %g, %g, %g, %g, %g)\n",
         x, y, z, r, height, thickness, nx, ny, nz);
  } else {
    mcdis_legacy_cylinder(x, y, z,
			  r, height, 12, nx, ny, nz);
  }
}

/* Draws a cone with center at (x,y,z) with extent (r,height).
 * The cone axis is along the vector nx,ny,nz.*/
void mcdis_cone( double x, double y, double z,
        double r, double height, double nx, double ny, double nz){
  if (mcdotrace==2) {
    printf("MCDISPLAY: cone(%g, %g, %g, %g, %g, %g, %g, %g)\n",
       x, y, z, r, height, nx, ny, nz);
  } else {
    mcdis_Circle(x, y, z, r, nx, ny, nz);
    mcdis_Circle(x+0.25*height*nx, y+0.25*height*ny, z+0.25*height*nz, 0.75*r, nx, ny, nz);
    mcdis_Circle(x+0.5*height*nx, y+0.5*height*ny, z+0.5*height*nz, 0.5*r, nx, ny, nz);
    mcdis_Circle(x+0.75*height*nx, y+0.75*height*ny, z+0.75*height*nz, 0.25*r, nx, ny, nz);
    mcdis_line(x, y, z, x+height*nx, y+height*ny, z+height*nz);
  }
}

/* Draws a disc with center at (x,y,z) with extent (r).
 * The disc axis is along the vector nx,ny,nz.*/
void mcdis_disc( double x, double y, double z,
        double r, double nx, double ny, double nz){
  printf("MCDISPLAY: disc(%g, %g, %g, %g, %g, %g, %g)\n",
     x, y, z, r, nx, ny, nz);
}

/* Draws a annulus with center at (x,y,z) with extent (outer_radius) and remove inner_radius.
 * The annulus axis is along the vector nx,ny,nz.*/
void mcdis_annulus( double x, double y, double z,
        double outer_radius, double inner_radius, double nx, double ny, double nz){
  printf("MCDISPLAY: annulus(%g, %g, %g, %g, %g, %g, %g, %g)\n",
     x, y, z, outer_radius, inner_radius, nx, ny, nz);
}

/* draws a sphere with center at (x,y,z) with extent (r)*/
void mcdis_sphere(double x, double y, double z, double r){
  if (mcdotrace==2) {
    printf("MCDISPLAY: sphere(%g,%g,%g,%g)\n", x, y, z, r);
  } else {
    double nx,ny,nz;
    int i;
    int N=12;

    nx=0;ny=0;nz=1;
    mcdis_Circle(x,y,z,r,nx,ny,nz);
    for (i=1;i<N;i++){
        rotate(nx,ny,nz, nx,ny,nz, PI/N, 0,1,0);
        mcdis_Circle(x,y,z,r,nx,ny,nz);
    }
    /*lastly draw a great circle perpendicular to all N circles*/
    //mcdis_Circle(x,y,z,radius,1,0,0);

    for (i=1;i<=N;i++){
        double yy=-r+ 2*r*((double)i/(N+1));
        mcdis_Circle(x,y+yy ,z,  sqrt(r*r-yy*yy) ,0,1,0);
    }
  }
}
/* POLYHEDRON IMPLEMENTATION*/

void mcdis_polyhedron(char *vertices_faces){
  printf("MCDISPLAY: polyhedron %s\n", vertices_faces);
}

/* POLYGON IMPLEMENTATION */
void mcdis_polygon(int count, ...){
  va_list ap;
  double *x,*y,*z;

  double x0=0,y0=0,z0=0; /* Used for centre-of-mass in trace==2 */

  x=malloc(count*sizeof(double));
  y=malloc(count*sizeof(double));
  z=malloc(count*sizeof(double));
  if (!x || !y || !z) {
    fprintf(stderr,"Error initializing polygon set size %i\n",count);
    exit(-1);
  }
  va_start(ap, count);
  // Fallback for trace==1 is multiline, one rank higher
  if (mcdotrace==1) {
    printf("MCDISPLAY: multiline(%i,",count+1);
  }
  
  int j;
  for (j=0; j<count; j++) {
    x[j] = va_arg(ap, double);
    y[j] = va_arg(ap, double);
    z[j] = va_arg(ap, double);
    if (mcdotrace==1) {
      printf("%g,%g,%g,",x[j],y[j],z[j]);
    } else {
      // Calculation of polygon centre of mass
      x0 += x[j]; y0 += y[j]; z0 += z[j];
    }
  }
  va_end(ap);

  /* Patch data for multiline(count+1, ... use 0th point*/
  if (mcdotrace==1) {
    printf("%g,%g,%g)\n",x[0],y[0],z[0]);
  } else {
    x0 /= count; y0 /= count; z0 /= count;
    /* Build up a json string for a "polyhedron" */
    // Estimate size of the JSON string
    const int VERTEX_OVERHEAD = 30;
    const int FACE_OVERHEAD_BASE = 20;
    const int FACE_INDEX_OVERHEAD = 15;
    int estimated_size = 256; // Base size
    estimated_size += count * VERTEX_OVERHEAD;

    int faceSize;
    int vtxSize;
    if (count > 3) {
      /* Split in triangles - as many as polygon rank */
      faceSize=count;
      vtxSize=count+1;
    } else {
      faceSize=1;
      vtxSize=count;
    }
    
    for (int i = 0; i < faceSize;) {
        int num_indices = 3;
        estimated_size += FACE_OVERHEAD_BASE + num_indices * FACE_INDEX_OVERHEAD;
        i += num_indices + 1;
    }

    char *json_string = malloc(estimated_size);
    if (json_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    char *ptr = json_string;
    ptr += sprintf(ptr, "{ \"vertices\": [");

    if (count==3) { // Single, basic triangle
      ptr += sprintf(ptr, "[%g, %g, %g], [%g, %g, %g], [%g, %g, %g]", x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2]);
    } else {
      for (int i = 0; i < vtxSize-1; i++) {
        ptr += sprintf(ptr, "[%g, %g, %g]", x[i], y[i], z[i]);
        if (i < vtxSize - 2) {
	  ptr += sprintf(ptr, ", ");
        } else {
	  ptr += sprintf(ptr, ", [%g, %g, %g]", x0, y0, z0);
	}
      }
    }
    ptr += sprintf(ptr, "], \"faces\": [");
    if (count==3) { // Single, basic triangle, 1 face...
      ptr += sprintf(ptr, "{ \"face\": [");
      ptr += sprintf(ptr, "0, 1, 2");
      ptr += sprintf(ptr, "]}");
    } else {
      for (int i = 0; i < faceSize; i++) {
        int num = 3;
        ptr += sprintf(ptr, "{ \"face\": [");
	if (i < faceSize - 1) {
	  ptr += sprintf(ptr, "%d, %d, %d",i,i+1,count);
	} else {
	  ptr += sprintf(ptr, "%d, %d, %d",i,count,0);
	}
	ptr += sprintf(ptr, "]}");
	if (i < faceSize-1) {
	  ptr += sprintf(ptr, ", ");
	}
      }
    }
    ptr += sprintf(ptr, "]}");
    mcdis_polyhedron(json_string);

    free(json_string);
  }
  free(x);free(y);free(z);
}
/* END NEW POLYGON IMPLEMENTATION*/

/*
void mcdis_polygon(double x1, double y1, double z1,
                double x2, double y2, double z2){
  printf("MCDISPLAY: polygon(2,%g,%g,%g,%g,%g,%g)\n",
         x1,y1,z1,x2,y2,z2);
}
*/

/* SECTION: coordinates handling ============================================ */

/*******************************************************************************
* Since we use a lot of geometric calculations using Cartesian coordinates,
* we collect some useful routines here. However, it is also permissible to
* work directly on the underlying struct coords whenever that is most
* convenient (that is, the type Coords is not abstract).
*
* Coordinates are also used to store rotation angles around x/y/z axis.
*
* Since coordinates are used much like a basic type (such as double), the
* structure itself is passed and returned, rather than a pointer.
*
* At compile-time, the values of the coordinates may be unknown (for example
* a motor position). Hence coordinates are general expressions and not simple
* numbers. For this we used the type Coords_exp which has three CExp
* fields. For runtime (or calculations possible at compile time), we use
* Coords which contains three double fields.
*******************************************************************************/

/* coords_set: Assign coordinates. */
Coords coords_set(MCNUM x, MCNUM y, MCNUM z)
{
  Coords a;

  a.x = x;
  a.y = y;
  a.z = z;
  return a;
}

/* coords_get: get coordinates. Required when 'x','y','z' are #defined as ray pars */
Coords coords_get(Coords a, MCNUM *x, MCNUM *y, MCNUM *z)
{
  *x = a.x;
  *y = a.y;
  *z = a.z;
  return a;
}

/* coords_add: Add two coordinates. */
Coords coords_add(Coords a, Coords b)
{
  Coords c;

  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  if (fabs(c.z) < 1e-14) c.z=0.0;
  return c;
}

/* coords_sub: Subtract two coordinates. */
Coords coords_sub(Coords a, Coords b)
{
  Coords c;

  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = a.z - b.z;
  if (fabs(c.z) < 1e-14) c.z=0.0;
  return c;
}

/* coords_neg: Negate coordinates. */
Coords coords_neg(Coords a)
{
  Coords b;

  b.x = -a.x;
  b.y = -a.y;
  b.z = -a.z;
  return b;
}

/* coords_scale: Scale a vector. */
Coords coords_scale(Coords b, double scale) {
  Coords a;

  a.x = b.x*scale;
  a.y = b.y*scale;
  a.z = b.z*scale;
  return a;
}

/* coords_sp: Scalar product: a . b */
double coords_sp(Coords a, Coords b) {
  double value;

  value = a.x*b.x + a.y*b.y + a.z*b.z;
  return value;
}

/* coords_xp: Cross product: a = b x c. */
Coords coords_xp(Coords b, Coords c) {
  Coords a;

  a.x = b.y*c.z - c.y*b.z;
  a.y = b.z*c.x - c.z*b.x;
  a.z = b.x*c.y - c.x*b.y;
  return a;
}

/* coords_len: Gives length of coords set. */
double coords_len(Coords a) {
  return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

/* coords_mirror: Mirror a in plane (through the origin) defined by normal n*/
Coords coords_mirror(Coords a, Coords n) {
  double t = scalar_prod(n.x, n.y, n.z, n.x, n.y, n.z);
  Coords b;
  if (t!=1) {
    t = sqrt(t);
    n.x /= t;
    n.y /= t;
    n.z /= t;
  }
  t=scalar_prod(a.x, a.y, a.z, n.x, n.y, n.z);
  b.x = a.x-2*t*n.x;
  b.y = a.y-2*t*n.y;
  b.z = a.z-2*t*n.z;
  return b;
}

/* coords_print: Print out vector values. */
void coords_print(Coords a) {
  #ifndef OPENACC
  fprintf(stdout, "(%f, %f, %f)\n", a.x, a.y, a.z);
  #endif
  return;
}

mcstatic void coords_norm(Coords* c) {
	double temp = coords_sp(*c,*c);

	// Skip if we will end dividing by zero
	if (temp == 0) return;

	temp = sqrt(temp);

	c->x /= temp;
	c->y /= temp;
	c->z /= temp;
}

/* coords_test_zero: check if zero vector*/
int coords_test_zero(Coords a){
  return ( a.x==0 && a.y==0 && a.z==0 );
}

/*******************************************************************************
* The Rotation type implements a rotation transformation of a coordinate
* system in the form of a double[3][3] matrix.
*
* Contrary to the Coords type in coords.c, rotations are passed by
* reference. Functions that yield new rotations do so by writing to an
* explicit result parameter; rotations are not returned from functions. The
* reason for this is that arrays cannot by returned from functions (though
* structures can; thus an alternative would have been to wrap the
* double[3][3] array up in a struct). Such are the ways of C programming.
*
* A rotation represents the tranformation of the coordinates of a vector when
* changing between coordinate systems that are rotated with respect to each
* other. For example, suppose that coordinate system Q is rotated 45 degrees
* around the Z axis with respect to coordinate system P. Let T be the
* rotation transformation representing a 45 degree rotation around Z. Then to
* get the coordinates of a vector r in system Q, apply T to the coordinates
* of r in P. If r=(1,0,0) in P, it will be (sqrt(1/2),-sqrt(1/2),0) in
* Q. Thus we should be careful when interpreting the sign of rotation angles:
* they represent the rotation of the coordinate systems, not of the
* coordinates (which has opposite sign).
*******************************************************************************/

/*******************************************************************************
* rot_set_rotation: Get transformation for rotation first phx around x axis,
* then phy around y, then phz around z.
*******************************************************************************/
void rot_set_rotation(Rotation t, double phx, double phy, double phz)
{
  if ((phx == 0) && (phy == 0) && (phz == 0)) {
    t[0][0] = 1.0;
    t[0][1] = 0.0;
    t[0][2] = 0.0;
    t[1][0] = 0.0;
    t[1][1] = 1.0;
    t[1][2] = 0.0;
    t[2][0] = 0.0;
    t[2][1] = 0.0;
    t[2][2] = 1.0;
  } else {
    double cx = cos(phx);
    double sx = sin(phx);
    double cy = cos(phy);
    double sy = sin(phy);
    double cz = cos(phz);
    double sz = sin(phz);

    t[0][0] = cy*cz;
    t[0][1] = sx*sy*cz + cx*sz;
    t[0][2] = sx*sz - cx*sy*cz;
    t[1][0] = -cy*sz;
    t[1][1] = cx*cz - sx*sy*sz;
    t[1][2] = sx*cz + cx*sy*sz;
    t[2][0] = sy;
    t[2][1] = -sx*cy;
    t[2][2] = cx*cy;
  }
}

/*******************************************************************************
* rot_test_identity: Test if rotation is identity
*******************************************************************************/
int rot_test_identity(Rotation t)
{
  return (t[0][0] + t[1][1] + t[2][2] == 3);
}

/*******************************************************************************
* rot_mul: Matrix multiplication of transformations (this corresponds to
* combining transformations). After rot_mul(T1, T2, T3), doing T3 is
* equal to doing first T2, then T1.
* Note that T3 must not alias (use the same array as) T1 or T2.
*******************************************************************************/
void rot_mul(Rotation t1, Rotation t2, Rotation t3)
{
  if (rot_test_identity(t1)) {
    rot_copy(t3, t2);
  } else if (rot_test_identity(t2)) {
    rot_copy(t3, t1);
  } else {
    int i,j;
    for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
	t3[i][j] = t1[i][0]*t2[0][j] + t1[i][1]*t2[1][j] + t1[i][2]*t2[2][j];
  }
}

/*******************************************************************************
* rot_copy: Copy a rotation transformation (arrays cannot be assigned in C).
*******************************************************************************/
void rot_copy(Rotation dest, Rotation src)
{
  int i,j;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      dest[i][j] = src[i][j];
}

/*******************************************************************************
* rot_transpose: Matrix transposition, which is inversion for Rotation matrices
*******************************************************************************/
void rot_transpose(Rotation src, Rotation dst)
{
  dst[0][0] = src[0][0];
  dst[0][1] = src[1][0];
  dst[0][2] = src[2][0];
  dst[1][0] = src[0][1];
  dst[1][1] = src[1][1];
  dst[1][2] = src[2][1];
  dst[2][0] = src[0][2];
  dst[2][1] = src[1][2];
  dst[2][2] = src[2][2];
}

/*******************************************************************************
* rot_apply: returns t*a
*******************************************************************************/
Coords rot_apply(Rotation t, Coords a)
{
  Coords b;
  if (rot_test_identity(t)) {
    return a;
  } else {
    b.x = t[0][0]*a.x + t[0][1]*a.y + t[0][2]*a.z;
    b.y = t[1][0]*a.x + t[1][1]*a.y + t[1][2]*a.z;
    b.z = t[2][0]*a.x + t[2][1]*a.y + t[2][2]*a.z;
    return b;
  }
}

/**
 * Pretty-printing of rotation matrices.
 */
void rot_print(Rotation rot) {
	printf("[ %4.2f %4.2f %4.2f ]\n",
			rot[0][0], rot[0][1], rot[0][2]);
	printf("[ %4.2f %4.2f %4.2f ]\n",
			rot[1][0], rot[1][1], rot[1][2]);
	printf("[ %4.2f %4.2f %4.2f ]\n\n",
			rot[2][0], rot[2][1], rot[2][2]);
}

/**
 * Vector product: used by vec_prod (mccode-r.h). Use coords_xp for Coords.
 */
void vec_prod_func(double *x, double *y, double *z,
		double x1, double y1, double z1,
		double x2, double y2, double z2) {
    *x = (y1)*(z2) - (y2)*(z1);
    *y = (z1)*(x2) - (z2)*(x1);
    *z = (x1)*(y2) - (x2)*(y1);
}

/**
 * Scalar product: use coords_sp for Coords.
 */
double scalar_prod(
		double x1, double y1, double z1,
		double x2, double y2, double z2) {
	return ((x1 * x2) + (y1 * y2) + (z1 * z2));
}

mcstatic void norm_func(double *x, double *y, double *z) {
	double temp = (*x * *x) + (*y * *y) + (*z * *z);
	if (temp != 0) {
		temp = sqrt(temp);
		*x /= temp;
		*y /= temp;
		*z /= temp;
	}
}


/* SECTION: GPU algorithms ================================================== */


/*
*  Divide-and-conquer strategy for parallelizing this task: Sort absorbed
*  particles last.
*
*   particles:  the particle array, required to checking _absorbed
*   pbuffer:    same-size particle buffer array required for parallel sort
*   len:        sorting area-of-interest size (e.g. from previous calls)
*   buffer_len: total array size
*   flag_split: if set, multiply live particles into absorbed slots, up to buffer_len
*   multiplier: output arg, becomes the  SPLIT multiplier if flag_split is set
*/
#ifdef FUNNEL
long sort_absorb_last(_class_particle* particles, _class_particle* pbuffer, long len, long buffer_len, long flag_split, long* multiplier) {
  #define SAL_THREADS 1024 // num parallel sections
  if (len<SAL_THREADS) return sort_absorb_last_serial(particles, len);

  if (multiplier != NULL) *multiplier = -1; // set default out value for multiplier
  long newlen = 0;
  long los[SAL_THREADS]; // target array startidxs
  long lens[SAL_THREADS]; // target array sublens
  long l = floor(len/(SAL_THREADS-1)); // subproblem_len
  long ll = len - l*(SAL_THREADS-1); // last_subproblem_len

  // TODO: The l vs ll is too simplistic, since ll can become much larger
  // than l, resulting in idling. We should distribute lengths more evenly.

  // step 1: sort sub-arrays
  #pragma acc parallel loop present(particles[0:buffer_len], pbuffer[0:buffer_len])
  for (unsigned long tidx=0; tidx<SAL_THREADS; tidx++) {
    long lo = l*tidx;
    long loclen = l;
    if (tidx==(SAL_THREADS-1)) loclen = ll; // last sub-problem special case
    long i = lo;
    long j = lo + loclen - 1;

    // write into pbuffer at i and j
    #pragma acc loop seq
    while (i < j) {
      #pragma acc loop seq
      while (!particles[i]._absorbed && i<j) {
        pbuffer[i] = particles[i];
        i++;
      }
      #pragma acc loop seq
      while (particles[j]._absorbed && i<j) {
        pbuffer[j] = particles[j];
        j--;
      }
      if (i < j) {
        pbuffer[j] = particles[i];
        pbuffer[i] = particles[j];
        i++;
        j--;
      }
    }
    // transfer edge case
    if (i==j)
      pbuffer[i] = particles[i];

    lens[tidx] = i - lo;
    if (i==j && !particles[i]._absorbed) lens[tidx]++;
  }

  // determine lo's
  long accumlen = 0;
  #pragma acc loop seq
  for (long idx=0; idx<SAL_THREADS; idx++) {
    los[idx] = accumlen;
    accumlen = accumlen + lens[idx];
  }

  // step 2: write non-absorbed sub-arrays to psorted/output from the left
  #pragma acc parallel loop present(pbuffer[0:buffer_len])
  for (unsigned long tidx=0; tidx<SAL_THREADS; tidx++) {
    long j, k;
    #pragma acc loop seq
    for (long i=0; i<lens[tidx]; i++) {
      j = i + l*tidx;
      k = i + los[tidx];
      particles[k] = pbuffer[j];
    }
  }
  //for (int ii=0;ii<accumlen;ii++) printf("%ld ", (psorted[ii]->_absorbed));

  // return (no SPLIT)
  if (flag_split != 1)
    return accumlen;

  // SPLIT - repeat the non-absorbed block N-1 times, where len % accumlen = N + R
  int mult = buffer_len / accumlen; // TODO: possibly use a new arg, bufferlen, rather than len

  // not enough space for full-block split, return
  if (mult <= 1)
    return accumlen;

  // copy non-absorbed block
  #pragma acc parallel loop present(particles[0:buffer_len])
  for (long tidx = 0; tidx < accumlen; tidx++) { // tidx: thread index
    randstate_t randstate[7];
    _class_particle sourcebuffer;
    _class_particle targetbuffer;
    // assign reduced weight to all particles
    particles[tidx].p=particles[tidx].p/mult;
    #pragma acc loop seq
    for (long bidx = 1; bidx < mult; bidx++) { // bidx: block index
      // preserve absorbed particle (for randstate)
      sourcebuffer = particles[bidx*accumlen + tidx];
      // buffer full particle struct
      targetbuffer = particles[tidx];
      // reassign previous randstate
      targetbuffer.randstate[0] = sourcebuffer.randstate[0];
      targetbuffer.randstate[1] = sourcebuffer.randstate[1];
      targetbuffer.randstate[2] = sourcebuffer.randstate[2];
      targetbuffer.randstate[3] = sourcebuffer.randstate[3];
      targetbuffer.randstate[4] = sourcebuffer.randstate[4];
      targetbuffer.randstate[5] = sourcebuffer.randstate[5];
      targetbuffer.randstate[6] = sourcebuffer.randstate[6];
      // apply
      particles[bidx*accumlen + tidx] = targetbuffer;
    }
  }

  // set out split multiplier value
  *multiplier = mult;

  // return expanded array size
  return accumlen * mult;
}

#endif

/*
*  Fallback serial version of the one above.
*/
long sort_absorb_last_serial(_class_particle* particles, long len) {
  long i = 0;
  long j = len - 1;
  _class_particle pbuffer;

  // bubble
  while (i < j) {
    while (!particles[i]._absorbed && i<j) i++;
    while (particles[j]._absorbed && i<j) j--;
    if (i < j) {
      pbuffer = particles[j];
      particles[j] = particles[i];
      particles[i] = pbuffer;
      i++;
      j--;
    }
  }

  // return new length
  if (i==j && !particles[i]._absorbed)
    return i + 1;
  else
    return i;
}

/*******************************************************************************
* mccoordschange: applies rotation to (x y z) and (vx vy vz) and Spin (sx,sy,sz)
*******************************************************************************/
void mccoordschange(Coords a, Rotation t, _class_particle *particle)
{
  Coords b, c;

  b.x = particle->x;
  b.y = particle->y;
  b.z = particle->z;
  c = rot_apply(t, b);
  b = coords_add(c, a);
  particle->x = b.x;
  particle->y = b.y;
  particle->z = b.z;

#if MCCODE_PARTICLE_CODE == 2112
    if (particle->vz != 0.0 || particle->vx != 0.0 || particle->vy != 0.0)
      mccoordschange_polarisation(t, &(particle->vx), &(particle->vy), &(particle->vz));

    if (particle->sz != 0.0 || particle->sx != 0.0 || particle->sy != 0.0)
      mccoordschange_polarisation(t, &(particle->sx), &(particle->sy), &(particle->sz));
#elif MCCODE_PARTICLE_CODE == 22
    if (particle->kz != 0.0 || particle->kx != 0.0 || particle->ky != 0.0)
      mccoordschange_polarisation(t, &(particle->kx), &(particle->ky), &(particle->kz));

    if (particle->Ez != 0.0 || particle->Ex != 0.0 || particle->Ey != 0.0)
      mccoordschange_polarisation(t, &(particle->Ex), &(particle->Ey), &(particle->Ez));
#endif
}

/*******************************************************************************
* mccoordschange_polarisation: applies rotation to vector (sx sy sz)
*******************************************************************************/
void mccoordschange_polarisation(Rotation t, double *sx, double *sy, double *sz)
{
  Coords b, c;

  b.x = *sx;
  b.y = *sy;
  b.z = *sz;
  c = rot_apply(t, b);
  *sx = c.x;
  *sy = c.y;
  *sz = c.z;
}

/* SECTION: vector math  ==================================================== */

/* normal_vec_func: Compute normal vector to (x,y,z). */
void normal_vec(double *nx, double *ny, double *nz,
                double x, double y, double z)
{
  double ax = fabs(x);
  double ay = fabs(y);
  double az = fabs(z);
  double l;
  if(x == 0 && y == 0 && z == 0)
  {
    *nx = 0;
    *ny = 0;
    *nz = 0;
    return;
  }
  if(ax < ay)
  {
    if(ax < az)
    {                           /* Use X axis */
      l = sqrt(z*z + y*y);
      *nx = 0;
      *ny = z/l;
      *nz = -y/l;
      return;
    }
  }
  else
  {
    if(ay < az)
    {                           /* Use Y axis */
      l = sqrt(z*z + x*x);
      *nx = z/l;
      *ny = 0;
      *nz = -x/l;
      return;
    }
  }
  /* Use Z axis */
  l = sqrt(y*y + x*x);
  *nx = y/l;
  *ny = -x/l;
  *nz = 0;
} /* normal_vec */

/*******************************************************************************
 * solve_2nd_order: second order equation solve: A*t^2 + B*t + C = 0
 * solve_2nd_order(&t1, NULL, A,B,C)
 *   returns 0 if no solution was found, or set 't1' to the smallest positive
 *   solution.
 * solve_2nd_order(&t1, &t2, A,B,C)
 *   same as with &t2=NULL, but also returns the second solution.
 * EXAMPLE usage for intersection of a trajectory with a plane in gravitation
 * field (gx,gy,gz):
 * The neutron starts at point r=(x,y,z) with velocityv=(vx vy vz). The plane
 * has a normal vector n=(nx,ny,nz) and contains the point W=(wx,wy,wz).
 * The problem consists in solving the 2nd order equation:
 *      1/2.n.g.t^2 + n.v.t + n.(r-W) = 0
 * so that A = 0.5 n.g; B = n.v; C = n.(r-W);
 * Without acceleration, t=-n.(r-W)/n.v
 ******************************************************************************/
int solve_2nd_order_old(double *t1, double *t2,
                  double A,  double B,  double C)
{
  int ret=0;

  if (!t1) return 0;
  *t1 = 0;
  if (t2) *t2=0;

  if (fabs(A) < 1E-10) /* approximate to linear equation: A ~ 0 */
  {
    if (B) {  *t1 = -C/B; ret=1; if (t2) *t2=*t1; }
    /* else no intersection: A=B=0 ret=0 */
  }
  else
  {
    double D;
    D = B*B - 4*A*C;
    if (D >= 0) /* Delta > 0: two solutions */
    {
      double sD, dt1, dt2;
      sD = sqrt(D);
      dt1 = (-B + sD)/2/A;
      dt2 = (-B - sD)/2/A;
      /* we identify very small values with zero */
      if (fabs(dt1) < 1e-10) dt1=0.0;
      if (fabs(dt2) < 1e-10) dt2=0.0;

      /* now we choose the smallest positive solution */
      if      (dt1<=0.0 && dt2>0.0) ret=2; /* dt2 positive */
      else if (dt2<=0.0 && dt1>0.0) ret=1; /* dt1 positive */
      else if (dt1> 0.0 && dt2>0.0)
      {  if (dt1 < dt2) ret=1; else ret=2; } /* all positive: min(dt1,dt2) */
      /* else two solutions are negative. ret=-1 */
      if (ret==1) { *t1 = dt1;  if (t2) *t2=dt2; }
      else        { *t1 = dt2;  if (t2) *t2=dt1; }
      ret=2;  /* found 2 solutions and t1 is the positive one */
    } /* else Delta <0: no intersection. ret=0 */
  }
  return(ret);
} /* solve_2nd_order */

int solve_2nd_order(double *t0, double *t1, double A, double B, double C){
  int retval=0;
  double sign=copysign(1.0,B);
  double dt0,dt1;

  dt0=0;
  dt1=0;
  if(t1){ *t1=0;}

  /*protect against rounding errors by locally equating DBL_EPSILON with 0*/
  if (fabs(A)<DBL_EPSILON){
    A=0;
  }
  if (fabs(B)<DBL_EPSILON){
    B=0;
  }
  if (fabs(C)<DBL_EPSILON){
    C=0;
  }

  /*check if coefficient are sane*/
  if( A==0  && B==0){
    retval=0;
  }else{
    if(A==0){
      /*equation is linear*/
      dt0=-C/B;
      retval=1;
    }else if (C==0){
      /*one root is 0*/
      if(sign<0){
        dt0=0;dt1=-B/A;
      }else{
        dt0=-B/A;dt1=0;
      }
      retval=2;
    }else{
      /*a regular 2nd order eq. Also works out fine for B==0.*/
      double D;
      D=B*B-4*A*C;
      if (D>=0){
        dt0=(-B - sign*sqrt(B*B-4*A*C))/(2*A);
        dt1=C/(A*dt0);
        retval=2;
      }else{
        /*no real roots*/
        retval=0;
      }
    }
    /*sort the solutions*/
    if (retval==1){
      /*put both solutions in t0 and t1*/
      *t0=dt0;
      if(t1) *t1=dt1;
    }else{
      /*we have two solutions*/
      /*swap if both are positive and t1 smaller than t0 or t1 the only positive*/
      int swap=0;
      if(dt1>0 && ( dt1<dt0 || dt0<=0) ){
        swap=1;
      }
      if (swap){
        *t0=dt1;
        if(t1) *t1=dt0;
      }else{
        *t0=dt0;
        if(t1) *t1=dt0;
      }
    }

  }
  return retval;

} /*solve_2nd_order_improved*/


/*******************************************************************************
 * randvec_target_circle: Choose random direction towards target at (x,y,z)
 * with given radius.
 * If radius is zero, choose random direction in full 4PI, no target.
 ******************************************************************************/
void _randvec_target_circle(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi, double radius,
        _class_particle* _particle)
{
  double l2, phi, theta, nx, ny, nz, xt, yt, zt, xu, yu, zu;

  if(radius == 0.0)
  {
    /* No target, choose uniformly a direction in full 4PI solid angle. */
    theta = acos(1 - rand0max(2));
    phi = rand0max(2 * PI);
    if(solid_angle)
      *solid_angle = 4*PI;
    nx = 1;
    ny = 0;
    nz = 0;
    yi = sqrt(xi*xi+yi*yi+zi*zi);
    zi = 0;
    xi = 0;
  }
  else
  {
    double costheta0;
    l2 = xi*xi + yi*yi + zi*zi; /* sqr Distance to target. */
    costheta0 = sqrt(l2/(radius*radius+l2));
    if (radius < 0) costheta0 *= -1;
    if(solid_angle)
    {
      /* Compute solid angle of target as seen from origin. */
        *solid_angle = 2*PI*(1 - costheta0);
    }

    /* Now choose point uniformly on circle surface within angle theta0 */
    theta = acos (1 - rand0max(1 - costheta0)); /* radius on circle */
    phi = rand0max(2 * PI); /* rotation on circle at given radius */
    /* Now, to obtain the desired vector rotate (xi,yi,zi) angle theta around a
       perpendicular axis u=i x n and then angle phi around i. */
    if(xi == 0 && zi == 0)
    {
      nx = 1;
      ny = 0;
      nz = 0;
    }
    else
    {
      nx = -zi;
      nz = xi;
      ny = 0;
    }
  }

  /* [xyz]u = [xyz]i x n[xyz] (usually vertical) */
  vec_prod(xu,  yu,  zu, xi, yi, zi,        nx, ny, nz);
  /* [xyz]t = [xyz]i rotated theta around [xyz]u */
  rotate  (xt,  yt,  zt, xi, yi, zi, theta, xu, yu, zu);
  /* [xyz]o = [xyz]t rotated phi around n[xyz] */
  rotate (*xo, *yo, *zo, xt, yt, zt, phi, xi, yi, zi);
}
/* randvec_target_circle */

/*******************************************************************************
 * randvec_target_rect_angular: Choose random direction towards target at
 * (xi,yi,zi) with given ANGULAR dimension height x width. height=phi_x=[0,PI],
 * width=phi_y=[0,2*PI] (radians)
 * If height or width is zero, choose random direction in full 4PI, no target.
 *******************************************************************************/
void _randvec_target_rect_angular(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi, double width, double height, Rotation A,
        _class_particle* _particle)
{
  double theta, phi, nx, ny, nz, xt, yt, zt, xu, yu, zu;
  Coords tmp;
  Rotation Ainverse;

  rot_transpose(A, Ainverse);

  if(height == 0.0 || width == 0.0)
  {
    randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, 0);
    return;
  }
  else
  {
    if(solid_angle)
    {
      /* Compute solid angle of target as seen from origin. */
      *solid_angle = 2*fabs(width*sin(height/2));
    }

    /* Go to global coordinate system */

    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(Ainverse, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    /* Now choose point uniformly on the unit sphere segment with angle theta/phi */
    phi   = width*randpm1()/2.0;
    theta = asin(randpm1()*sin(height/2.0));
    /* Now, to obtain the desired vector rotate (xi,yi,zi) angle theta around
       n, and then phi around u. */
    if(xi == 0 && zi == 0)
    {
      nx = 1;
      ny = 0;
      nz = 0;
    }
    else
    {
      nx = -zi;
      nz = xi;
      ny = 0;
    }
  }

  /* [xyz]u = [xyz]i x n[xyz] (usually vertical) */
  vec_prod(xu,  yu,  zu, xi, yi, zi,        nx, ny, nz);
  /* [xyz]t = [xyz]i rotated theta around [xyz]u */
  rotate  (xt,  yt,  zt, xi, yi, zi, theta, nx, ny, nz);
  /* [xyz]o = [xyz]t rotated phi around n[xyz] */
  rotate (*xo, *yo, *zo, xt, yt, zt, phi, xu,  yu,  zu);

  /* Go back to local coordinate system */
  tmp = coords_set(*xo, *yo, *zo);
  tmp = rot_apply(A, tmp);
  coords_get(tmp, &*xo, &*yo, &*zo);
}
/* randvec_target_rect_angular */

/*******************************************************************************
 * randvec_target_rect_real: Choose random direction towards target at (xi,yi,zi)
 * with given dimension height x width (in meters !).
 *
 * Local emission coordinate is taken into account and corrected for 'order' times.
 * (See remarks posted to mcstas-users by George Apostolopoulus <gapost@ipta.demokritos.gr>)
 *
 * If height or width is zero, choose random direction in full 4PI, no target.
 *
 * Traditionally, this routine had the name randvec_target_rect - this is now a
 * a define (see mcstas-r.h) pointing here. If you use the old rouine, you are NOT
 * taking the local emmission coordinate into account.
*******************************************************************************/
void _randvec_target_rect_real(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi,
        double width, double height, Rotation A,
        double lx, double ly, double lz, int order,
        _class_particle* _particle)
{
  double dx, dy, dist, dist_p, nx, ny, nz, mx, my, mz, n_norm, m_norm;
  double cos_theta;
  Coords tmp;
  Rotation Ainverse;

  rot_transpose(A, Ainverse);

  if(height == 0.0 || width == 0.0)
  {
    randvec_target_circle(xo, yo, zo, solid_angle,
               xi, yi, zi, 0);
    return;
  }
  else
  {
    /* Now choose point uniformly on rectangle within width x height */
    dx = width*randpm1()/2.0;
    dy = height*randpm1()/2.0;

    /* Determine distance to target plane*/
    dist = sqrt(xi*xi + yi*yi + zi*zi);
    /* Go to global coordinate system */

    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(Ainverse, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    /* Determine vector normal to trajectory axis (z) and gravity [0 1 0] */
    vec_prod(nx, ny, nz, xi, yi, zi, 0, 1, 0);

    /* This now defines the x-axis, normalize: */
    n_norm=sqrt(nx*nx + ny*ny + nz*nz);
    nx = nx/n_norm;
    ny = ny/n_norm;
    nz = nz/n_norm;

    /* Now, determine our y-axis (vertical in many cases...) */
    vec_prod(mx, my, mz, xi, yi, zi, nx, ny, nz);
    m_norm=sqrt(mx*mx + my*my + mz*mz);
    mx = mx/m_norm;
    my = my/m_norm;
    mz = mz/m_norm;

    /* Our output, random vector can now be defined by linear combination: */

    *xo = xi + dx * nx + dy * mx;
    *yo = yi + dx * ny + dy * my;
    *zo = zi + dx * nz + dy * mz;

    /* Go back to local coordinate system */
    tmp = coords_set(*xo, *yo, *zo);
    tmp = rot_apply(A, tmp);
    coords_get(tmp, &*xo, &*yo, &*zo);

    /* Go back to local coordinate system */
    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(A, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    if (solid_angle) {
      /* Calculate vector from local point to remote random point */
      lx = *xo - lx;
      ly = *yo - ly;
      lz = *zo - lz;
      dist_p = sqrt(lx*lx + ly*ly + lz*lz);

      /* Adjust the 'solid angle' */
      /* 1/r^2 to the chosen point times cos(\theta) between the normal */
      /* vector of the target rectangle and direction vector of the chosen point. */
      cos_theta = (xi * lx + yi * ly + zi * lz) / (dist * dist_p);
      *solid_angle = width * height / (dist_p * dist_p);
      int counter;
      for (counter = 0; counter < order; counter++) {
        *solid_angle = *solid_angle * cos_theta;
      }
    }
  }
}
/* randvec_target_rect_real */


/* SECTION: random numbers ==================================================

  How to add a new RNG:

  - Use an rng with a manegable state vector, e.g. of lengt 4 or 7. The state
  will sit on the particle struct as a "randstate_t state[RANDSTATE_LEN]"
  - If the rng has a long state (as MT), set an empty "srandom" and initialize
  it explicitly using the appropriate define (RNG_ALG)
  - Add a seed and a random function (the transforms will be reused)
  - Write the proper defines in mccode-r.h, e.g. randstate_t and RANDSTATE_LEN,
  srandom and random.
  - Compile using -DRNG_ALG=<selector int value>

============================================================================= */


/* "Mersenne Twister", by Makoto Matsumoto and Takuji Nishimura. */
/* See http://www.math.keio.ac.jp/~matumoto/emt.html for original source. */
/*
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using mt_srandom(seed)
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.keio.ac.jp/matumoto/emt.html
   email: matumoto@math.keio.ac.jp
*/
#include <stdio.h>
#include <stdint.h>   // for uint32_t
#include <stddef.h>   // for size_t

/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfU   /* constant vector a */
#define UPPER_MASK 0x80000000U /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffU /* least significant r bits */

static uint32_t mt[N]; /* the array for the state vector  */
static int mti = N + 1; /* mti==N+1 means mt[N] is not initialized */

// Required for compatibility with common RNG interface (e.g., kiss/mt polymorphism)
void mt_srandom_empty(void) {}

// Initializes mt[N] with a seed
void mt_srandom(uint32_t seed) {
    mt[0] = seed;
    for (mti = 1; mti < N; mti++) {
        mt[mti] = 1812433253U * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti;
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffU;
        /* for >32 bit machines */
    }
}
/* Initialize by an array with array-length.
   Init_key is the array for initializing keys.
   key_length is its length. */
void init_by_array(uint32_t init_key[], size_t key_length) {
    size_t i = 1, j = 0, k;
    mt_srandom(19650218U);
    k = (N > key_length ? N : key_length);
    for (; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525U))
              + init_key[j] + (uint32_t)j;
        mt[i] &= 0xffffffffU;
        i++; j++;
        if (i >= N) { mt[0] = mt[N - 1]; i = 1; }
        if (j >= key_length) j = 0;
    }
    for (k = N - 1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941U))
              - (uint32_t)i;
        mt[i] &= 0xffffffffU;
        i++;
        if (i >= N) { mt[0] = mt[N - 1]; i = 1; }
    }
    mt[0] = 0x80000000U; /* MSB is 1; ensuring non-zero initial array */
}

// Generates a random number on [0, 0xffffffff]-interval
uint32_t mt_random(void) {
    uint32_t y;
    static const uint32_t mag01[2] = { 0x0U, MATRIX_A };
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N + 1)   /* if mt_srandom() has not been called, */ 
            mt_srandom(5489U);  /* a default initial seed is used */

        for (kk = 0; kk < N - M; kk++) {
            y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
            mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1U];
        }
        for (; kk < N - 1; kk++) {
            y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
            mt[kk] = mt[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1U];
        }
        y = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
        mt[N - 1] = mt[M - 1] ^ (y >> 1) ^ mag01[y & 0x1U];

        mti = 0;
    }

    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680U;
    y ^= (y << 15) & 0xefc60000U;
    y ^= (y >> 18);

    return y;
}
#undef N
#undef M
#undef MATRIX_A
#undef UPPER_MASK
#undef LOWER_MASK
/* End of "Mersenne Twister". */


/*
KISS

 From: http://www.helsbreth.org/random/rng_kiss.html
 Scott Nelson 1999

 Based on Marsaglia's KISS or (KISS+SWB) <http://www.cs.yorku.ca/~oz/marsaglia-
rng.html>

 KISS - Keep it Simple Stupid PRNG

 the idea is to use simple, fast, individually promising
 generators to get a composite that will be fast, easy to code
 have a very long period and pass all the tests put to it.
 The three components of KISS are
        x(n)=a*x(n-1)+1 mod 2^32
        y(n)=y(n-1)(I+L^13)(I+R^17)(I+L^5),
        z(n)=2*z(n-1)+z(n-2) +carry mod 2^32
 The y's are a shift register sequence on 32bit binary vectors
 period 2^32-1;
 The z's are a simple multiply-with-carry sequence with period
 2^63+2^32-1.  The period of KISS is thus
      2^32*(2^32-1)*(2^63+2^32-1) > 2^127

 In 2025 adapted for consistent 64-bit behavior across platforms.
*/

/* the KISS state is stored as a vector of 7 uint64_t        */
/*   0  1  2  3  4      5  6   */
/* [ x, y, z, w, carry, k, m ] */

uint64_t *kiss_srandom(uint64_t state[7], uint64_t seed) {
    if (seed == 0) seed = 1ull;
    state[0] = seed | 1ull; // x
    state[1] = seed | 2ull; // y
    state[2] = seed | 4ull; // z
    state[3] = seed | 8ull; // w
    state[4] = 0ull;        // carry
    state[5] = 0ull;        // k
    state[6] = 0ull;        // m
    return state;
}

uint64_t kiss_random(uint64_t state[7]) {
    // Linear congruential generator
    state[0] = state[0] * 69069ull + 1ull;

    // Xorshift
    state[1] ^= state[1] << 13ull;
    state[1] ^= state[1] >> 17ull;
    state[1] ^= state[1] << 5ull;

    // Multiply-with-carry
    state[5] = (state[2] >> 2ull) + (state[3] >> 3ull) + (state[4] >> 2ull);
    state[6] = state[3] + state[3] + state[2] + state[4];
    state[2] = state[3];
    state[3] = state[6];
    state[4] = state[5] >> 62ull;  // Top bit of carry (adjusted for 64-bit)

    return state[0] + state[1] + state[3];
}
/* end of "KISS" rng */


/* FAST KISS in another implementation (Hundt) */

//////////////////////////////////////////////////////////////////////////////
// fast keep it simple stupid generator
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Thomas Mueller hash for initialization of rngs
// http://stackoverflow.com/questions/664014/
//        what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
//////////////////////////////////////////////////////////////////////////////
randstate_t _hash(randstate_t x) {
  x = ((x >> 16) ^ x) * (randstate_t)0x45d9f3b;
  x = ((x >> 16) ^ x) * (randstate_t)0x45d9f3b;
  x = ((x >> 16) ^ x);
  return x;
}


// SECTION: random number transforms ==========================================



// generate a random number from normal law
double _randnorm(randstate_t* state)
{
  static double v1, v2, s; /* removing static breaks comparison with McStas <= 2.5 */
  static int phase = 0;
  double X, u1, u2;

  if(phase == 0)
  {
    do
    {
      u1 = _rand01(state);
      u2 = _rand01(state);
      v1 = 2*u1 - 1;
      v2 = 2*u2 - 1;
      s = v1*v1 + v2*v2;
    } while(s >= 1 || s == 0);

    X = v1*sqrt(-2*log(s)/s);
  }
  else
  {
    X = v2*sqrt(-2*log(s)/s);
  }

  phase = 1 - phase;
  return X;
}
// another one
double _randnorm2(randstate_t* state) {
  double x, y, r;
  do {
      x = 2.0 * _rand01(state) - 1.0;
      y = 2.0 * _rand01(state) - 1.0;
      r = x*x + y*y;
  } while (r == 0.0 || r >= 1.0);
  return x * sqrt((-2.0 * log(r)) / r);
}

// Generate a random number from -1 to 1 with triangle distribution
double _randtriangle(randstate_t* state) {
	double randnum = _rand01(state);
	if (randnum>0.5) return(1-sqrt(2*(randnum-0.5)));
	else return(sqrt(2*randnum)-1);
}
double _rand01(randstate_t* state) {
	double randnum;
	randnum = (double) _random();
  // TODO: can we mult instead of div?
	randnum /= (double) MC_RAND_MAX + 1;
	return randnum;
}
// Return a random number between 1 and -1
double _randpm1(randstate_t* state) {
	double randnum;
	randnum = (double) _random();
	randnum /= ((double) MC_RAND_MAX + 1) / 2;
	randnum -= 1;
	return randnum;
}
// Return a random number between 0 and max.
double _rand0max(double max, randstate_t* state) {
	double randnum;
	randnum = (double) _random();
	randnum /= ((double) MC_RAND_MAX + 1) / max;
	return randnum;
}
// Return a random number between min and max.
double _randminmax(double min, double max, randstate_t* state) {
	return _rand0max(max - min, state) + max;
}


/* SECTION: main and signal handlers ======================================== */

/*******************************************************************************
* mchelp: displays instrument executable help with possible options
*******************************************************************************/
static void
mchelp(char *pgmname)
{
  int i;

  fprintf(stderr, "%s (%s) instrument simulation, generated with " MCCODE_STRING " (" MCCODE_DATE ")\n", instrument_name, instrument_source);
  fprintf(stderr, "Usage: %s [options] [parm=value ...]\n", pgmname);
  fprintf(stderr,
"Options are:\n"
"  -s SEED   --seed=SEED      Set random seed (must be != 0)\n"
"  -n COUNT  --ncount=COUNT   Set number of particles to simulate.\n"
"  -d DIR    --dir=DIR        Put all data files in directory DIR.\n"
"  -a        --append         Append data files to those in directory DIR.\n"	  
"  -t        --trace          Enable trace of " MCCODE_PARTICLE "s through instrument.\n"
"                             (Use -t=2 or --trace=2 for modernised mcdisplay rendering)\n"
"  -g        --gravitation    Enable gravitation for all trajectories.\n"
"  --no-output-files          Do not write any data files.\n"
"  -h        --help           Show this help message.\n"
"  -i        --info           Detailed instrument information.\n"
"  --list-parameters          Print the instrument parameters to standard out\n"
"  -y        --yes            Assume default values for all parameters with a default\n"
"  --meta-list                Print names of components which defined metadata\n"
"  --meta-defined COMP[:NAME] Print component defined metadata names, or (0,1) if NAME provided\n"
"  --meta-type COMP:NAME      Print metadata format type specified in definition\n"
"  --meta-data COMP:NAME      Print the metadata text\n"
"  --source                   Show the instrument code which was compiled.\n"
#ifdef OPENACC
"\n"
"  --vecsize                  OpenACC vector-size (default: 128)\n"
"  --numgangs                 Number of OpenACC gangs (default: 7813)\n"
"  --gpu_innerloop            Maximum rays to process pr. OpenACC \n"
"                             kernel run (default: 2147483647)\n"
"\n"
#endif
"\n"
"  --bufsiz                   Monitor_nD list/buffer-size (default: 1000000)\n"
"  --format=FORMAT            Output data files using FORMAT="
   FLAVOR_UPPER
#ifdef USE_NEXUS
   " NEXUS\n"
"  --IDF                      Embed an xml-formatted IDF instrument definition\n"
"                             in the NeXus file (if existent in .)\n\n"
#else
"\n\n"
#endif
);
#ifdef USE_MPI
  fprintf(stderr,
  "This instrument has been compiled with MPI support.\n  Use 'mpirun %s [options] [parm=value ...]'.\n", pgmname);
#endif
#ifdef OPENACC
  fprintf(stderr,
  "This instrument has been compiled with NVIDIA GPU support through OpenACC.\n  Running on systems without such devices will lead to segfaults.\nFurter, fprintf, sprintf and printf have been removed from any component TRACE.\n");
#endif

  if(numipar > 0)
  {
    fprintf(stderr, "Instrument parameters are:\n");
    for(i = 0; i < numipar; i++)
      if (mcinputtable[i].val && strlen(mcinputtable[i].val))
        fprintf(stderr, "  %-16s(%s) [default='%s']\n", mcinputtable[i].name,
        (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name),
        mcinputtable[i].val);
      else
        fprintf(stderr, "  %-16s(%s)\n", mcinputtable[i].name,
        (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name));
  }

#ifndef NOSIGNALS
  fprintf(stderr, "Known signals are: "
#ifdef SIGUSR1
  "USR1 (status) "
#endif
#ifdef SIGUSR2
  "USR2 (save) "
#endif
#ifdef SIGBREAK
  "BREAK (save) "
#endif
#ifdef SIGTERM
  "TERM (save and exit)"
#endif
  "\n");
#endif /* !NOSIGNALS */
} /* mchelp */


/* mcshowhelp: show help and exit with 0 */
static void
mcshowhelp(char *pgmname)
{
  mchelp(pgmname);
  exit(0);
}

/* mcusage: display usage when error in input arguments and exit with 1 */
static void
mcusage(char *pgmname)
{
  fprintf(stderr, "Error: incorrect command line arguments\n");
  mchelp(pgmname);
  exit(1);
}

/* mcenabletrace: enable trace/mcdisplay or error if requires recompile */
static void
mcenabletrace(int mode)
{
 if(traceenabled) {
  mcdotrace = mode;
  #pragma acc update device ( mcdotrace )
 } else {
   if (mode>0) {
     fprintf(stderr,
	     "Error: trace not enabled (mcenabletrace)\n"
	     "Please re-run the " MCCODE_NAME " compiler "
	     "with the --trace option, or rerun the\n"
	     "C compiler with the MC_TRACE_ENABLED macro defined.\n");
     exit(1);
   }
 }
}

/*******************************************************************************
* mcreadparams: request parameters from the prompt (or use default)
*******************************************************************************/
void
mcreadparams(void)
{
  int i,j,status;
  static char buf[CHAR_BUF_LENGTH];
  char *p;
  int len;

  MPI_MASTER(printf("Instrument parameters for %s (%s)\n",
                    instrument_name, instrument_source));

  for(i = 0; mcinputtable[i].name != 0; i++)
  {
    do
    {
      MPI_MASTER(
                 if (mcinputtable[i].val && strlen(mcinputtable[i].val))
                   printf("Set value of instrument parameter %s (%s) [default='%s']:\n",
                          mcinputtable[i].name,
                          (*mcinputtypes[mcinputtable[i].type].parminfo)
                          (mcinputtable[i].name), mcinputtable[i].val);
                 else
                   printf("Set value of instrument parameter %s (%s):\n",
                          mcinputtable[i].name,
                          (*mcinputtypes[mcinputtable[i].type].parminfo)
                          (mcinputtable[i].name));
                 fflush(stdout);
                 );
#ifdef USE_MPI
      if(mpi_node_rank == mpi_node_root)
        {
          p = fgets(buf, CHAR_BUF_LENGTH, stdin);
          if(p == NULL)
            {
              fprintf(stderr, "Error: empty input for paramater %s (mcreadparams)\n", mcinputtable[i].name);
              exit(1);
            }
        }
      else
        p = buf;
      MPI_Bcast(buf, CHAR_BUF_LENGTH, MPI_CHAR, mpi_node_root, MPI_COMM_WORLD);
#else /* !USE_MPI */
      p = fgets(buf, CHAR_BUF_LENGTH, stdin);
      if(p == NULL)
        {
          fprintf(stderr, "Error: empty input for paramater %s (mcreadparams)\n", mcinputtable[i].name);
          exit(1);
        }
#endif /* USE_MPI */
      len = strlen(buf);
      if (!len || (len == 1 && (buf[0] == '\n' || buf[0] == '\r')))
      {
        if (mcinputtable[i].val && strlen(mcinputtable[i].val)) {
          strncpy(buf, mcinputtable[i].val, CHAR_BUF_LENGTH);  /* use default value */
          len = strlen(buf);
        }
      }
      for(j = 0; j < 2; j++)
      {
        if(len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
        {
          len--;
          buf[len] = '\0';
        }
      }

      status = (*mcinputtypes[mcinputtable[i].type].getparm)
                   (buf, mcinputtable[i].par);
      if(!status)
      {
        (*mcinputtypes[mcinputtable[i].type].error)(mcinputtable[i].name, buf);
        if (!mcinputtable[i].val || strlen(mcinputtable[i].val)) {
          fprintf(stderr, "       Change %s default value in instrument definition.\n", mcinputtable[i].name);
          exit(1);
        }
      }
    } while(!status);
  }
} /* mcreadparams */

/*******************************************************************************
* mcparseoptions: parse command line arguments (options, parameters)
*******************************************************************************/
void
mcparseoptions(int argc, char *argv[])
{
  int i, j;
  char *p;
  int paramset = 0, *paramsetarray;
  char *usedir=NULL;

  /* Add one to numipar to avoid allocating zero size memory block. */
  paramsetarray = (int*)malloc((numipar + 1)*sizeof(*paramsetarray));
  if(paramsetarray == NULL)
  {
    fprintf(stderr, "Error: insufficient memory (mcparseoptions)\n");
    exit(1);
  }
  for(j = 0; j < numipar; j++)
    {
      paramsetarray[j] = 0;
      if (mcinputtable[j].val != NULL && strlen(mcinputtable[j].val))
      {
        int  status;
        char buf[CHAR_BUF_LENGTH];
        strncpy(buf, mcinputtable[j].val, CHAR_BUF_LENGTH);
        status = (*mcinputtypes[mcinputtable[j].type].getparm)
                   (buf, mcinputtable[j].par);
        if(!status) fprintf(stderr, "Invalid '%s' default value %s in instrument definition (mcparseoptions)\n", mcinputtable[j].name, buf);
        else paramsetarray[j] = 1;
      } else {
        (*mcinputtypes[mcinputtable[j].type].getparm)
          (NULL, mcinputtable[j].par);
        paramsetarray[j] = 0;
      }
    }
  for(i = 1; i < argc; i++)
  {
    if(!strcmp("-s", argv[i]) && (i + 1) < argc)
      mcsetseed(argv[++i]);
    else if(!strncmp("-s", argv[i], 2))
      mcsetseed(&argv[i][2]);
    else if(!strcmp("--seed", argv[i]) && (i + 1) < argc)
      mcsetseed(argv[++i]);
    else if(!strncmp("--seed=", argv[i], 7))
      mcsetseed(&argv[i][7]);
    else if(!strcmp("-n", argv[i]) && (i + 1) < argc)
      mcsetn_arg(argv[++i]);
    else if(!strncmp("-n", argv[i], 2))
      mcsetn_arg(&argv[i][2]);
    else if(!strcmp("--ncount", argv[i]) && (i + 1) < argc)
      mcsetn_arg(argv[++i]);
    else if(!strncmp("--ncount=", argv[i], 9))
      mcsetn_arg(&argv[i][9]);
    else if(!strcmp("-d", argv[i]) && (i + 1) < argc)
      usedir=argv[++i];  /* will create directory after parsing all arguments (end of this function) */
    else if(!strncmp("-d", argv[i], 2))
      usedir=&argv[i][2];
    else if(!strcmp("--dir", argv[i]) && (i + 1) < argc)
      usedir=argv[++i];
    else if(!strncmp("-a", argv[i], 2))
      mcappend = 1;
    else if(!strcmp("--append", argv[i]))
      mcappend = 1;
    else if(!strncmp("--dir=", argv[i], 6))
      usedir=&argv[i][6];
    else if(!strcmp("-h", argv[i]))
      mcshowhelp(argv[0]);
    else if(!strcmp("--help", argv[i]) || !strcmp("--version", argv[i]))
      mcshowhelp(argv[0]);
    else if(!strcmp("-i", argv[i])) {
      mcformat=FLAVOR_UPPER;
      mcinfo();
    }
    else if(!strcmp("--info", argv[i]))
      mcinfo();
    else if (!strcmp("--list-parameters", argv[i]))
      mcparameterinfo();
    else if (!strcmp("--meta-list", argv[i]) && ((i+1) >= argc || argv[i+1][0] == '-')){
      //printf("Components with metadata defined:\n");
      exit(metadata_table_print_all_components(num_metadata, metadata_table) == 0);
    }
    else if (!strcmp("--meta-defined", argv[i]) && (i+1) < argc){
      exit(metadata_table_print_component_keys(num_metadata, metadata_table, argv[i+1]) == 0);
    }
    else if (!strcmp("--meta-type", argv[i]) && (i+1) < argc){
      char * literal_type = metadata_table_type(num_metadata, metadata_table, argv[i+1]);
      if (literal_type == NULL) exit(1);
      printf("%s\n", literal_type);
      exit(0);
    }
    else if (!strcmp("--meta-data", argv[i]) && (i+1) < argc){
      char * literal = metadata_table_literal(num_metadata, metadata_table, argv[i+1]);
      if (literal == NULL) exit(1);
      printf("%s\n", literal);
      exit(0);
    }
    else if(!strncmp("--trace=", argv[i], 8)) {
      mcenabletrace(atoi(&argv[i][8]));
    } else if(!strncmp("-t=", argv[i], 3) || !strcmp("--verbose", argv[i])) {
      mcenabletrace(atoi(&argv[i][3]));
    } else if(!strcmp("-t", argv[i]))
      mcenabletrace(1);
    else if(!strcmp("--trace", argv[i]) || !strcmp("--verbose", argv[i]))
      mcenabletrace(1);
    else if(!strcmp("--gravitation", argv[i]))
      mcgravitation = 1;
    else if(!strcmp("-g", argv[i]))
      mcgravitation = 1;
    else if(!strcmp("--yes", argv[i]))
      mcusedefaults = 1;
    else if(!strcmp("-y", argv[i]))
      mcusedefaults = 1;
    else if(!strncmp("--format=", argv[i], 9)) {
      mcformat=&argv[i][9];
    }
    else if(!strcmp("--format", argv[i]) && (i + 1) < argc) {
      mcformat=argv[++i];
    }
#ifdef USE_NEXUS
    else if(!strcmp("--IDF", argv[i])) {
      mcnexus_embed_idf = 1;
    }
#endif
    else if(!strncmp("--vecsize=", argv[i], 10)) {
      vecsize=atoi(&argv[i][10]);
    }    
    else if(!strcmp("--vecsize", argv[i]) && (i + 1) < argc) {
      vecsize=atoi(argv[++i]);
    }
    else if(!strncmp("--bufsiz=", argv[i], 9)) {
      MONND_BUFSIZ=atoi(&argv[i][9]);
    }
    else if(!strcmp("--bufsiz", argv[i]) && (i + 1) < argc) {
      MONND_BUFSIZ=atoi(argv[++i]);
    }
    else if(!strncmp("--numgangs=", argv[i], 11)) {
      numgangs=atoi(&argv[i][11]);
    }
    else if(!strcmp("--numgangs", argv[i]) && (i + 1) < argc) {
      numgangs=atoi(argv[++i]);
    }
    else if(!strncmp("--gpu_innerloop=", argv[i], 16)) {
      gpu_innerloop=(long)strtod(&argv[i][16], NULL);
    }
    else if(!strcmp("--gpu_innerloop", argv[i]) && (i + 1) < argc) {
      gpu_innerloop=(long)strtod(argv[++i], NULL);
    }

    else if(!strcmp("--no-output-files", argv[i]))
      mcdisable_output_files = 1;
    else if(!strcmp("--source", argv[i])) {
      printf("/* Source code %s from %s: */\n"
        "/******************************************************************************/\n"
        "%s\n"
        "/******************************************************************************/\n"
        "/* End of source code %s from %s */\n",
        instrument_name, instrument_source, instrument_code,
        instrument_name, instrument_source);
      exit(1);
    }
    else if(argv[i][0] != '-' && (p = strchr(argv[i], '=')) != NULL)
    {
      *p++ = '\0';

      for(j = 0; j < numipar; j++)
        if(!strcmp(mcinputtable[j].name, argv[i]))
        {
          int status;
          status = (*mcinputtypes[mcinputtable[j].type].getparm)(p,
                        mcinputtable[j].par);
          if(!status || !strlen(p))
          {
            (*mcinputtypes[mcinputtable[j].type].error)
              (mcinputtable[j].name, p);
            exit(1);
          }
          paramsetarray[j] = 1;
          paramset = 1;
          break;
        }
      if(j == numipar)
      {                                /* Unrecognized parameter name */
        fprintf(stderr, "Error: unrecognized parameter %s (mcparseoptions)\n", argv[i]);
        exit(1);
      }
    }
    else if(argv[i][0] == '-') {
      fprintf(stderr, "Error: unrecognized option argument %s (mcparseoptions). Ignored.\n", argv[i++]);
    }
    else {
      fprintf(stderr, "Error: unrecognized argument %s (mcparseoptions). Aborting.\n", argv[i]);
      mcusage(argv[0]);
    }
  }
  if (mcusedefaults) {
    MPI_MASTER(
     printf("Using all default parameter values\n");
    );
    for(j = 0; j < numipar; j++) {
      int status;
      if(mcinputtable[j].val && strlen(mcinputtable[j].val)){
	status = (*mcinputtypes[mcinputtable[j].type].getparm)(mcinputtable[j].val,
                        mcinputtable[j].par);
	paramsetarray[j] = 1;
	paramset = 1;
      }
    }
  }
  if(!paramset)
    mcreadparams();                /* Prompt for parameters if not specified. */
  else
  {
    for(j = 0; j < numipar; j++)
      if(!paramsetarray[j])
      {
        fprintf(stderr, "Error: Instrument parameter %s left unset (mcparseoptions)\n",
                mcinputtable[j].name);
        exit(1);
      }
  }
  free(paramsetarray);
#ifdef USE_MPI
  if (mcdotrace) mpi_node_count=1; /* disable threading when in trace mode */
#endif
  if (usedir && strlen(usedir) && !mcdisable_output_files) mcuse_dir(usedir);
} /* mcparseoptions */

#ifndef NOSIGNALS
/*******************************************************************************
* sighandler: signal handler that makes simulation stop, and save results
*******************************************************************************/
void sighandler(int sig)
{
  /* MOD: E. Farhi, Sep 20th 2001: give more info */
  time_t t1, t0;
#define SIG_SAVE 0
#define SIG_TERM 1
#define SIG_STAT 2
#define SIG_ABRT 3

  printf("\n# " MCCODE_STRING ": [pid %i] Signal %i detected", getpid(), sig);
#ifdef USE_MPI
  printf(" [proc %i]", mpi_node_rank);
#endif
#if defined(SIGUSR1) && defined(SIGUSR2) && defined(SIGKILL)
  if (!strcmp(mcsig_message, "sighandler") && (sig != SIGUSR1) && (sig != SIGUSR2))
  {
    printf("\n# Fatal : unrecoverable loop ! Suicide (naughty boy).\n");
    kill(0, SIGKILL); /* kill myself if error occurs within sighandler: loops */
  }
#endif
  switch (sig) {
#ifdef SIGINT
    case SIGINT : printf(" SIGINT (interrupt from terminal, Ctrl-C)"); sig = SIG_TERM; break;
#endif
#ifdef SIGILL
    case SIGILL  : printf(" SIGILL (Illegal instruction)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGFPE
    case SIGFPE  : printf(" SIGFPE (Math Error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGSEGV
    case SIGSEGV : printf(" SIGSEGV (Mem Error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGTERM
    case SIGTERM : printf(" SIGTERM (Termination)"); sig = SIG_TERM; break;
#endif
#ifdef SIGABRT
    case SIGABRT : printf(" SIGABRT (Abort)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGQUIT
    case SIGQUIT : printf(" SIGQUIT (Quit from terminal)"); sig = SIG_TERM; break;
#endif
#ifdef SIGTRAP
    case SIGTRAP : printf(" SIGTRAP (Trace trap)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGPIPE
    case SIGPIPE : printf(" SIGPIPE (Broken pipe)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGUSR1
    case SIGUSR1 : printf(" SIGUSR1 (Display info)"); sig = SIG_STAT; break;
#endif
#ifdef SIGUSR2
    case SIGUSR2 : printf(" SIGUSR2 (Save simulation)"); sig = SIG_SAVE; break;
#endif
#ifdef SIGHUP
    case SIGHUP  : printf(" SIGHUP (Hangup/update)"); sig = SIG_SAVE; break;
#endif
#ifdef SIGBUS
    case SIGBUS  : printf(" SIGBUS (Bus error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGURG
    case SIGURG  : printf(" SIGURG (Urgent socket condition)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGBREAK
    case SIGBREAK: printf(" SIGBREAK (Break signal, Ctrl-Break)"); sig = SIG_SAVE; break;
#endif
    default : printf(" (look at signal list for signification)"); sig = SIG_ABRT; break;
  }
  printf("\n");
  printf("# Simulation: %s (%s) \n", instrument_name, instrument_source);
  printf("# Breakpoint: %s ", mcsig_message);
  if (strstr(mcsig_message, "Save") && (sig == SIG_SAVE))
    sig = SIG_STAT;
  SIG_MESSAGE("sighandler");
  if (mcget_ncount() == 0)
    printf("(0 %%)\n" );
  else
  {
    printf("%.2f %% (%10.1f/%10.1f)\n", 100.0*mcget_run_num()/mcget_ncount(), 1.0*mcget_run_num(), 1.0*mcget_ncount());
  }
  t0 = (time_t)mcstartdate;
  t1 = time(NULL);
  printf("# Date:      %s", ctime(&t1));
  printf("# Started:   %s", ctime(&t0));

  if (sig == SIG_STAT)
  {
    printf("# " MCCODE_STRING ": Resuming simulation (continue)\n");
    fflush(stdout);
    return;
  }
  else
  if (sig == SIG_SAVE)
  {
    printf("# " MCCODE_STRING ": Saving data and resume simulation (continue)\n");
    save(NULL);
    fflush(stdout);
    return;
  }
  else
  if (sig == SIG_TERM)
  {
    printf("# " MCCODE_STRING ": Finishing simulation (save results and exit)\n");
    finally();
    exit(0);
  }
  else
  {
    fflush(stdout);
    perror("# Last I/O Error");
    printf("# " MCCODE_STRING ": Simulation stop (abort).\n");
// This portion of the signal handling only works on UNIX
#if defined(__unix__) || defined(__APPLE__)
    signal(sig, SIG_DFL); /* force to use default sighandler now */
    kill(getpid(), sig);  /* and trigger it with the current signal */
#endif
    exit(-1);
  }
#undef SIG_SAVE
#undef SIG_TERM
#undef SIG_STAT
#undef SIG_ABRT

} /* sighandler */
#endif /* !NOSIGNALS */

#ifdef NEUTRONICS
/*Main neutronics function steers the McStas calls, initializes parameters etc */
/* Only called in case NEUTRONICS = TRUE */
void neutronics_main_(float *inx, float *iny, float *inz, float *invx, float *invy, float *invz, float *intime, float *insx, float *insy, float *insz, float *inw, float *outx, float *outy, float *outz, float *outvx, float *outvy, float *outvz, float *outtime, float *outsx, float *outsy, float *outsz, float *outwgt)
{

  extern double mcnx, mcny, mcnz, mcnvx, mcnvy, mcnvz;
  extern double mcnt, mcnsx, mcnsy, mcnsz, mcnp;

  /* External code governs iteration - McStas is iterated once per call to neutronics_main. I.e. below counter must be initiancated for each call to neutronics_main*/
  mcrun_num=0;

  time_t t;
  t = (time_t)mcstartdate;
  mcstartdate = t;  /* set start date before parsing options and creating sim file */
  init();

  /* *** parse options *** */
  SIG_MESSAGE("[" __FILE__ "] main START");
  mcformat=getenv(FLAVOR_UPPER "_FORMAT") ?
           getenv(FLAVOR_UPPER "_FORMAT") : FLAVOR_UPPER;

  /* Set neutron state based on input from neutronics code */
  mcsetstate(*inx,*iny,*inz,*invx,*invy,*invz,*intime,*insx,*insy,*insz,*inw);

  /* main neutron event loop - runs only one iteration */

  //mcstas_raytrace(&mcncount); /* prior to McStas 1.12 */

  mcallowbackprop = 1; //avoid absorbtion from negative dt
  int argc=1;
  char *argv[0];
  int dummy = mccode_main(argc, argv);

  *outx =  mcnx;
  *outy =  mcny;
  *outz =  mcnz;
  *outvx =  mcnvx;
  *outvy =  mcnvy;
  *outvz =  mcnvz;
  *outtime =  mcnt;
  *outsx =  mcnsx;
  *outsy =  mcnsy;
  *outsz =  mcnsz;
  *outwgt =  mcnp;

  return;
} /* neutronics_main */

#endif /*NEUTRONICS*/

#endif /* !MCCODE_H */
/* End of file "mccode-r.c". */
/* End of file "mccode-r.c". */

/* embedding file "mcstas-r.c" */

/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mcstas-r.c
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y
* Version: $Revision$
*
* Runtime system for McStas.
* Embedded within instrument in runtime mode.
*
* Usage: Automatically embbeded in the c code whenever required.
*
* $Id$
*
*******************************************************************************/

#ifndef MCSTAS_R_H
#include "mcstas-r.h"
#endif
#ifdef DANSE
#include "mcstas-globals.h"
#endif

/*******************************************************************************
* The I/O format definitions and functions
*******************************************************************************/

/*the magnet stack*/
#ifdef MC_POL_COMPAT
void (*mcMagnetPrecession) (double, double, double, double, double, double,
    double, double*, double*, double*, double, Coords, Rotation)=NULL;
Coords   mcMagnetPos;
Rotation mcMagnetRot;
double*  mcMagnetData                = NULL;
/* mcMagneticField(x, y, z, t, Bx, By, Bz) */
int (*mcMagneticField) (double, double, double, double,
    double*, double*, double*, void *) = NULL;
#endif

#ifndef MCSTAS_H

/*******************************************************************************
* mcsetstate: transfer parameters into global McStas variables
*******************************************************************************/
_class_particle mcsetstate(double x, double y, double z, double vx, double vy, double vz,
			   double t, double sx, double sy, double sz, double p, int mcgravitation, void *mcMagnet, int mcallowbackprop)
{
  _class_particle mcneutron;

  mcneutron.x  = x;
  mcneutron.y  = y;
  mcneutron.z  = z;
  mcneutron.vx = vx;
  mcneutron.vy = vy;
  mcneutron.vz = vz;
  mcneutron.t  = t;
  mcneutron.sx = sx;
  mcneutron.sy = sy;
  mcneutron.sz = sz;
  mcneutron.p  = p;
  mcneutron.mcgravitation = mcgravitation;
  mcneutron.mcMagnet = mcMagnet;
  mcneutron.allow_backprop = mcallowbackprop;
  mcneutron._uid       = 0;
  mcneutron._index     = 1;
  mcneutron._absorbed  = 0;
  mcneutron._restore   = 0;
  mcneutron._scattered = 0;
  mcneutron.flag_nocoordschange = 0;
  
  /* init tmp-vars - FIXME are they used? */
  mcneutron._mctmp_a = mcneutron._mctmp_b =  mcneutron._mctmp_c = 0;
  // what about mcneutron._logic ?
  mcneutron._logic.dummy=1;
  // init uservars via cogen'd-function
  particle_uservar_init(&mcneutron);

  return(mcneutron);
} /* mcsetstate */

/*******************************************************************************
* mcgetstate: get neutron parameters from particle structure
*******************************************************************************/
_class_particle mcgetstate(_class_particle mcneutron, double *x, double *y, double *z,
               double *vx, double *vy, double *vz, double *t,
               double *sx, double *sy, double *sz, double *p)
{
  *x  =  mcneutron.x;
  *y  =  mcneutron.y;
  *z  =  mcneutron.z;
  *vx =  mcneutron.vx;
  *vy =  mcneutron.vy;
  *vz =  mcneutron.vz;
  *t  =  mcneutron.t;
  *sx =  mcneutron.sx;
  *sy =  mcneutron.sy;
  *sz =  mcneutron.sz;
  *p  =  mcneutron.p;

  return(mcneutron);
} /* mcgetstate */


/*******************************************************************************
* mcgenstate: set default neutron parameters
*******************************************************************************/
// Moved to generated code
/* #pragma acc routine seq */
/* _class_particle mcgenstate(void) */
/* { */
/*   return(mcsetstate(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, mcgravitation, mcMagnet, mcallowbackprop)); */
/* } */

/*******************************************************************************
* mccoordschanges: old style rotation routine rot -> (x y z) ,(vx vy vz),(sx,sy,sz)
*******************************************************************************/
void
mccoordschanges(Coords a, Rotation t, double *x, double *y, double *z,
               double *vx, double *vy, double *vz, double *sx, double *sy, double *sz)
{
  Coords b, c;

  b.x = *x;
  b.y = *y;
  b.z = *z;
  c = rot_apply(t, b);
  b = coords_add(c, a);
  *x = b.x;
  *y = b.y;
  *z = b.z;

  if ( (vz && vy  && vx) && (*vz != 0.0 || *vx != 0.0 || *vy != 0.0) )
    mccoordschange_polarisation(t, vx, vy, vz);

  if ( (sz && sy  && sx) && (*sz != 0.0 || *sx != 0.0 || *sy != 0.0) )
    mccoordschange_polarisation(t, sx, sy, sz);

}

/* intersection routines ==================================================== */

/*******************************************************************************
* inside_rectangle: Check if (x,y) is inside rectangle (xwidth, yheight)
* return 0 if outside and 1 if inside
*******************************************************************************/
int inside_rectangle(double x, double y, double xwidth, double yheight)
{
  if (x>-xwidth/2 && x<xwidth/2 && y>-yheight/2 && y<yheight/2)
    return 1;
  else
    return 0;
}

/*******************************************************************************
 * box_intersect: compute time intersection with a box
 * returns 0 when no intersection is found
 *      or 1 in case of intersection with resulting times dt_in and dt_out
 * This function written by Stine Nyborg, 1999.
 *******************************************************************************/
int box_intersect(double *dt_in, double *dt_out,
                  double x, double y, double z,
                  double vx, double vy, double vz,
                  double dx, double dy, double dz)
{
  double x_in, y_in, z_in, tt, t[6], a, b;
  int i, count, s;

      /* Calculate intersection time for each of the six box surface planes
       *  If the box surface plane is not hit, the result is zero.*/

  if(vx != 0)
   {
    tt = -(dx/2 + x)/vx;
    y_in = y + tt*vy;
    z_in = z + tt*vz;
    if( y_in > -dy/2 && y_in < dy/2 && z_in > -dz/2 && z_in < dz/2)
      t[0] = tt;
    else
      t[0] = 0;

    tt = (dx/2 - x)/vx;
    y_in = y + tt*vy;
    z_in = z + tt*vz;
    if( y_in > -dy/2 && y_in < dy/2 && z_in > -dz/2 && z_in < dz/2)
      t[1] = tt;
    else
      t[1] = 0;
   }
  else
    t[0] = t[1] = 0;

  if(vy != 0)
   {
    tt = -(dy/2 + y)/vy;
    x_in = x + tt*vx;
    z_in = z + tt*vz;
    if( x_in > -dx/2 && x_in < dx/2 && z_in > -dz/2 && z_in < dz/2)
      t[2] = tt;
    else
      t[2] = 0;

    tt = (dy/2 - y)/vy;
    x_in = x + tt*vx;
    z_in = z + tt*vz;
    if( x_in > -dx/2 && x_in < dx/2 && z_in > -dz/2 && z_in < dz/2)
      t[3] = tt;
    else
      t[3] = 0;
   }
  else
    t[2] = t[3] = 0;

  if(vz != 0)
   {
    tt = -(dz/2 + z)/vz;
    x_in = x + tt*vx;
    y_in = y + tt*vy;
    if( x_in > -dx/2 && x_in < dx/2 && y_in > -dy/2 && y_in < dy/2)
      t[4] = tt;
    else
      t[4] = 0;

    tt = (dz/2 - z)/vz;
    x_in = x + tt*vx;
    y_in = y + tt*vy;
    if( x_in > -dx/2 && x_in < dx/2 && y_in > -dy/2 && y_in < dy/2)
      t[5] = tt;
    else
      t[5] = 0;
   }
  else
    t[4] = t[5] = 0;

  /* The intersection is evaluated and *dt_in and *dt_out are assigned */

  a = b = s = 0;
  count = 0;

  for( i = 0; i < 6; i = i + 1 )
    if( t[i] == 0 )
      s = s+1;
    else if( count == 0 )
    {
      a = t[i];
      count = 1;
    }
    else
    {
      b = t[i];
      count = 2;
    }

  if ( a == 0 && b == 0 )
    return 0;
  else if( a < b )
  {
    *dt_in = a;
    *dt_out = b;
    return 1;
  }
  else
  {
    *dt_in = b;
    *dt_out = a;
    return 1;
  }

} /* box_intersect */

/*******************************************************************************
 * cylinder_intersect: compute intersection with a cylinder
 * returns 0 when no intersection is found
 *      or 2/4/8/16 bits depending on intersection,
 *     and resulting times t0 and t1
 * Written by: EM,NB,ABA 4.2.98
  *******************************************************************************/
int cylinder_intersect(double *t0, double *t1, double x, double y, double z,
                   double vx, double vy, double vz, double r, double h)
{
  double D, t_in, t_out, y_in, y_out;
  int ret=1;

  D = (2*vx*x + 2*vz*z)*(2*vx*x + 2*vz*z)
    - 4*(vx*vx + vz*vz)*(x*x + z*z - r*r);

  if (D>=0)
  {
    if (vz*vz + vx*vx) {
      t_in  = (-(2*vz*z + 2*vx*x) - sqrt(D))/(2*(vz*vz + vx*vx));
      t_out = (-(2*vz*z + 2*vx*x) + sqrt(D))/(2*(vz*vz + vx*vx));
    } else if (vy) { /* trajectory parallel to cylinder axis */
      t_in = (-h/2-y)/vy;
      t_out = (h/2-y)/vy;
      if (t_in>t_out){
        double tmp=t_in;
        t_in=t_out;t_out=tmp;
      }
    } else return 0;
    y_in = vy*t_in + y;
    y_out =vy*t_out + y;

    if ( (y_in > h/2 && y_out > h/2) || (y_in < -h/2 && y_out < -h/2) )
      return 0;
    else
    {
      if (y_in > h/2)
        { t_in = ((h/2)-y)/vy; ret += 2; }
      else if (y_in < -h/2)
        { t_in = ((-h/2)-y)/vy; ret += 4; }
      if (y_out > h/2)
        { t_out = ((h/2)-y)/vy; ret += 8; }
      else if (y_out < -h/2)
        { t_out = ((-h/2)-y)/vy; ret += 16; }
    }
    *t0 = t_in;
    *t1 = t_out;
    return ret;
  }
  else
  {
    *t0 = *t1 = 0;
    return 0;
  }
} /* cylinder_intersect */


/*******************************************************************************
 * sphere_intersect: Calculate intersection between a line and a sphere.
 * returns 0 when no intersection is found
 *      or 1 in case of intersection with resulting times t0 and t1
 *******************************************************************************/
int sphere_intersect(double *t0, double *t1, double x, double y, double z,
                 double vx, double vy, double vz, double r)
{
  double A, B, C, D, v;

  v = sqrt(vx*vx + vy*vy + vz*vz);
  A = v*v;
  B = 2*(x*vx + y*vy + z*vz);
  C = x*x + y*y + z*z - r*r;
  D = B*B - 4*A*C;
  if(D < 0)
    return 0;
  D = sqrt(D);
  *t0 = (-B - D) / (2*A);
  *t1 = (-B + D) / (2*A);
  return 1;
} /* sphere_intersect */

/*******************************************************************************
 * plane_intersect: Calculate intersection between a plane and a line.
 * returns 0 when no intersection is found (i.e. line is parallel to the plane)
 * returns 1 or -1 when intersection time is positive and negative respectively
 *******************************************************************************/
int plane_intersect(double *t, double x, double y, double z,
                 double vx, double vy, double vz, double nx, double ny, double nz, double wx, double wy, double wz)
{
  double s;
  if (fabs(s=scalar_prod(nx,ny,nz,vx,vy,vz))<FLT_EPSILON) return 0;
  *t = - scalar_prod(nx,ny,nz,x-wx,y-wy,z-wz)/s;
  if (*t<0) return -1;
  else return 1;
} /* plane_intersect */

#endif /* !MCSTAS_H */
/* End of file "mcstas-r.c". */


/* *****************************************************************************
* Start of instrument 'ISIS_LET_generated' generated code
***************************************************************************** */

#ifdef MC_TRACE_ENABLED
int traceenabled = 1;
#else
int traceenabled = 0;
#endif
#define MCSTAS "/opt/anaconda3/envs/mcstas/share/mcstas/resources/"
int   defaultmain         = 1;
char  instrument_name[]   = "ISIS_LET_generated";
char  instrument_source[] = "ISIS_LET_generated.instr";
char *instrument_exe      = NULL; /* will be set to argv[0] in main */
char  instrument_code[]   = "Instrument ISIS_LET_generated source code ISIS_LET_generated.instr is not embedded in this executable.\n  Use --source option when running mcstas.\n";

int main(int argc, char *argv[]){return mccode_main(argc, argv);}

/* *****************************************************************************
* instrument 'ISIS_LET_generated' and components DECLARE
***************************************************************************** */

/* Instrument parameters: structure and a table for the initialisation
   (Used in e.g. inputparse and I/O function (e.g. detector_out) */

struct _struct_instrument_parameters {
  MCNUM Ei;
  MCNUM dE;
  MCNUM Ch3_speed;
  MCNUM Ch5_speed;
  MCNUM Ch2_phase;
  MCNUM pha_offset;
  char* res;
  char* snout;
  int monitors_on;
  int movable_monitors;
  char* sample_coh;
  char* sample_inc;
};
typedef struct _struct_instrument_parameters _class_instrument_parameters;

struct _instrument_struct {
  char   _name[256]; /* the name of this instrument e.g. 'ISIS_LET_generated' */
/* Counters per component instance */
  double counter_AbsorbProp[40]; /* absorbed events in PROP routines */
  double counter_N[40], counter_P[40], counter_P2[40]; /* event counters after each component instance */
  _class_particle _trajectory[40]; /* current trajectory for STORE/RESTORE */
/* Components position table (absolute and relative coords) */
  Coords _position_relative[40]; /* positions of all components */
  Coords _position_absolute[40];
  _class_instrument_parameters _parameters; /* instrument parameters */
} _instrument_var;
struct _instrument_struct *instrument = & _instrument_var;
#pragma acc declare create ( _instrument_var )
#pragma acc declare create ( instrument )

int numipar = 12;
struct mcinputtable_struct mcinputtable[] = {
  "Ei", &(_instrument_var._parameters.Ei), instr_type_double, "3.7", "",
  "dE", &(_instrument_var._parameters.dE), instr_type_double, "1.1", "",
  "Ch3_speed", &(_instrument_var._parameters.Ch3_speed), instr_type_double, "100", "",
  "Ch5_speed", &(_instrument_var._parameters.Ch5_speed), instr_type_double, "200", "",
  "Ch2_phase", &(_instrument_var._parameters.Ch2_phase), instr_type_double, "95000", "",
  "pha_offset", &(_instrument_var._parameters.pha_offset), instr_type_double, "8e-05", "",
  "res", &(_instrument_var._parameters.res), instr_type_string, "HF", "",
  "snout", &(_instrument_var._parameters.snout), instr_type_string, "out", "",
  "monitors_on", &(_instrument_var._parameters.monitors_on), instr_type_int, "1", "",
  "movable_monitors", &(_instrument_var._parameters.movable_monitors), instr_type_int, "0", "",
  "sample_coh", &(_instrument_var._parameters.sample_coh), instr_type_string, "/Users/bb24144/Documents/McStas/let_scipp/produce_sqw/benz_coh_test.sqw", "",
  "sample_inc", &(_instrument_var._parameters.sample_inc), instr_type_string, "/Users/bb24144/Documents/McStas/let_scipp/produce_sqw/benz_inc_test.sqw", "",
  NULL, NULL, instr_type_double, ""
};

struct metadata_table_struct metadata_table[] = {
  "", "", "", ""
};
int num_metadata = 0;

/* ************************************************************************** */
/*             SHARE user declarations for all components                     */
/* ************************************************************************** */

/* Shared user declarations for all components types 'Commodus_I3'. */

  #include <ctype.h>

  typedef struct {
    int nEnergy; ///< Number of energy bins
    int nTime;   ///< number of time bins

    double XAxis;
    double ZAxis;

    double rdumMid;    ///< tally time Window mid point
    double timeOffset; ///< Time separation
    double* TimeBin;   ///< Time bins
    double* EnergyBin; ///< Energy bins

    double** Flux; ///< Flux per bin (integrated)
    double* EInt;  ///< Integrated Energy point
    double Total;  ///< Integrated Total

  } Source_ViewMod;

  double**
  matrix (const int m, const int n)
  /*!
    Determine a double matrix
  */
  {
    int i;
    double* pv;
    double** pd;

    if (m < 1)
      return 0;
    if (n < 1)
      return 0;
    pv = (double*)malloc (m * n * sizeof (double));
    pd = (double**)malloc (m * sizeof (double*));
    if (!pd) {
      fprintf (stderr, "No room for matrix!\n");
      exit (1);
    }
    for (i = 0; i < m; i++)
      pd[i] = pv + (i * n);
    return pd;
  } /* matrix */

  #pragma acc routine seq
  double
  polInterp (double* X, double* Y, int Psize, double Aim)
  /*!
    returns the interpolated polynomial between Epnts
    and the integration
    \param X :: X coordinates
    \param Y :: Y coordinates
    \param Psize :: number of valid point in array to use
    \param Aim :: Aim point to intepolate result (X coordinate)
    \returns Energy point
  */
  {
    double out, errOut; /* out put variables */
    double* C = malloc (Psize * sizeof (double));
    double* D = malloc (Psize * sizeof (double));
    if (!C || !D) {
      #ifndef OPENACC
      fprintf (stderr, "Error in ISIS_moderator: memory allocation failure. Exit!\n");
      exit (-1);
      #endif
    }
    double testDiff, diff;

    double w, den, ho, hp; /* intermediate variables */
    int i, m, ns;

    ns = 0;
    diff = fabs (Aim - X[0]);
    C[0] = Y[0];
    D[0] = Y[0];
    for (i = 1; i < Psize; i++) {
      testDiff = fabs (Aim - X[i]);
      if (diff > testDiff) {
        ns = i;
        diff = testDiff;
      }
      C[i] = Y[i];
      D[i] = Y[i];
    }

    out = Y[ns];
    ns--; /* Now can be -1 !!!! */

    for (m = 1; m < Psize; m++) {
      for (i = 0; i < Psize - m; i++) {
        ho = X[i] - Aim;
        hp = X[i + m] - Aim;
        w = C[i + 1] - D[i];
        /*	  den=ho-hp;  -- test !=0.0 */
        den = w / (ho - hp);
        D[i] = hp * den;
        C[i] = ho * den;
      }

      errOut = (2 * (ns + 1) < (Psize - m)) ? C[ns + 1] : D[ns--];
      out += errOut;
    }
    free (C);
    free (D);
    return out;
  } /* polInterp */

  #pragma acc routine seq
  int
  binSearch (int Npts, double* AR, double V)
  /*!
    Object is to find the point in
    array AR, closest to the value V
    Checked for ordered array returns lower of backeting objects
  */
  {
    int klo, khi, k;
    if (Npts <= 0)
      return 0;
    if (V > AR[Npts - 1])
      return Npts;

    if (AR[0] > 0.0)
      AR[0] = 0.0;

    if (V < AR[0]) {
      // if(AR[0]>0.0)AR[0]=0.0;
      return 0;
    }
    klo = 0;
    khi = Npts - 1;
    while (khi - klo > 1) {
      k = (khi + klo) >> 1; // quick division by 2
      if (AR[k] > V)
        khi = k;
      else
        klo = k;
    }
    return khi;
  } /* binSearch */

  int
  cmdnumberD (char* mc, double* num)
  /*!
    \returns 1 on success 0 on failure
  */
  {
    int i, j;
    char* ss;
    char** endptr;
    double nmb;
    int len;

    len = strlen (mc);
    j = 0;

    for (i = 0; i < len && mc[i] && (mc[i] == '\t' || mc[i] == ' ' || mc[i] == ','); i++)
      ;
    if (i == len || !mc[i])
      return 0;
    ss = malloc (sizeof (char) * (len + 1));
    if (!ss) {
      fprintf (stderr, "Error in ISIS_moderator: memory allocation failure. Exit!\n");
      exit (-1);
    }

    for (; i < len && mc[i] != '\n' && mc[i] && mc[i] != '\t' && mc[i] != ' ' && mc[i] != ','; i++) {
      ss[j] = mc[i];
      j++;
    }
    if (!j) {
      free (ss);
      return 0; // This should be impossible
    }
    ss[j] = 0;
    endptr = malloc (sizeof (char*));
    nmb = strtod (ss, endptr);
    if (*endptr != ss + j) {
      free (endptr);
      free (ss);
      return 0;
    }
    *num = (double)nmb;
    for (j = 0; j < i && mc[j]; j++)
      mc[j] = ' ';
    free (endptr);
    free (ss);
    return 1;
  } /* cmdnumberD */

  int
  notComment (char* Line)
  /*!
    \returns 0 on a comment, 1 on a non-comment
  */
  {
    int len, i;

    len = strlen (Line);
    for (i = 0; i < len && isspace (Line[i]); i++)
      ;

    if (!Line[i] || Line[i] == 'c' || Line[i] == 'C' || Line[i] == '!' || Line[i] == '#')
      return 0;
    return 1;
  } /* notComment */

  void
  orderEnergy (double* A, double* B) {
    double tmp;
    if (*A > *B) {
      tmp = *A;
      *A = *B;
      *B = tmp;
    }
    return;
  } /* orderEnergy */

  int
  timeStart (char* Line)
  /*!
    Search for a word time at the start of
    the line.
    \param Line :: Line to search
    \returns 1 on success 0 on failure
  */
  {
    int len, i;

    len = strlen (Line);
    for (i = 0; i < len && isspace (Line[i]); i++)
      ;
    if (len - i < 4)
      return 0;
    return (strncmp (Line + i, "time", 4)) ? 0 : 1;
  } /* timeStart */

  void
  cutToNumber (char* Line) {
    int len, i;

    len = strlen (Line);
    for (i = 0; i < len && !isdigit (Line[i]) && Line[i] != '-'; i++)
      Line[i] = ' ';
    return;
  } /* cutToNumber */

  int
  findTimeOffset (char* Line, double* TO)
  /*!
    Determine the time offset from the file
    \return 1 on success
   */
  {
    int len, i;
    double D;

    len = strlen (Line);
    for (i = 0; i < len && Line[i] != 'T'; i++)
      ;
    if (len - i < 11)
      return 0;

    if (strncmp (Line + i, "TimeOffset", 11) && cmdnumberD (Line + i + 11, &D)) {
      *TO = D / 100.0;
      return 1;
    }
    return 0;
  } /* findTimeOffset */

  int
  findRDUM (char* Line)
  /*!
    Search for a word rdum at the start of
    the line.
    \param Line :: Line to search
    \returns 1 on success 0 on failure
  */
  {
    int len, i;

    len = strlen (Line);
    for (i = 0; i < len && Line[i] != 'r'; i++)
      ;
    if (len - i < 4)
      return 0;
    return (strncmp (Line + i, "rdum", 4)) ? 0 : 1;
  } /* findRDUM */

  double
  convertEnergy (double E)
  /*!
    Convert the energy from eV [not change] or
    from negative -ve which is angstrom
  */
  {
    return (E > 0.0) ? E : 81.793936 / (E * E);
  } /* convertEnergy */

  double
  EtoLambda (double E)
  /*!
    Convert the energy from eV [not change] o
    to lambda [A]
  */
  {
    return sqrt (81.793936 / E);
  } /* EtoLambda */

  int
  timeEnd (char* Line)
  /*!
    Search for a word time at the start of
    the line.
    \param Line :: Line to search
    \returns 1 on success 0 on failure
  */
  {
    int len, i;

    len = strlen (Line);
    for (i = 0; i < len && isspace (Line[i]); i++)
      ;
    if (len - i < 5)
      return 0;
    return (strncmp (Line + i, "total", 5)) ? 0 : 1;
  } /* timeEnd */

  int
  energyBin (char* Line, double Einit, double Eend, double* Ea, double* Eb)
  /*!
    Search for a word "energy bin:" at the start of
    the line. Then separte off the energy bin values
    \param Line :: Line to search
    \param Ea :: first energy bin [meV]
    \param Eb :: second energy bin [meV]
    \returns 1 on success 0 on failure
  */
  {
    int len, i;
    double A, B;

    len = strlen (Line);
    for (i = 0; i < len && isspace (Line[i]); i++)
      ;
    if (len - i < 11)
      return 0;

    if (strncmp (Line + i, "energy bin:", 11))
      return 0;

    i += 11;
    if (!cmdnumberD (Line + i, &A))
      return 0;
    // remove 'to'
    for (; i < len - 1 && Line[i] != 'o'; i++)
      ;
    i++;
    if (!cmdnumberD (Line + i, &B))
      return 0;
    A *= 1e9;
    B *= 1e9;
    *Ea = A;
    *Eb = B;
    if (*Eb > Einit && *Ea < Eend)
      return 1;
    return 0;
  } /* energyBin */

  double
  calcFraction (double EI, double EE, double Ea, double Eb)
  /*!
    Calculate the fraction of the bin between Ea -> Eb
    that is encompassed by EI->EE
  */
  {
    double frac;
    double dRange;

    if (EI > Eb)
      return 0.0;
    if (EE < Ea)
      return 0.0;

    dRange = Eb - Ea;
    frac = (EI > Ea) ? (Eb - EI) / dRange : 1.0;

    frac -= (EE < Eb) ? (Eb - EE) / dRange : 0.0;

    //  if(frac != 1.0)
    //  fprintf(stderr,"frac %g, Ea %g,Eb %g, EI %g, EE %g\n",frac,Ea,Eb,EI,EE);

    return frac;
  } /* calcFraction */

  double
  calcRDum (double* RPts, Source_ViewMod TS)
  /*!
    Caluclate the mean distance from the window centre point
   */
  {
    double sum, zMid;
    int i;

    sum = 0.0;
    for (i = 0; i < 4; i++) {
      fprintf (stderr, "RDUM %g %g %g\n", RPts[i * 3], RPts[i * 3 + 1], RPts[i * 3 + 2]);
      sum += sqrt (RPts[i * 3] * RPts[i * 3] + RPts[i * 3 + 1] * RPts[i * 3 + 1]);
    }
    sum /= 400.0; // Convert to metres from cm
    return sum;
  } /* calcRDum */

  void
  processHeader (FILE* TFile, Source_ViewMod* TS, double modPosition, double xwidth, double yheight)
  /*!
    Determine the window and the time offset
    \param TFile :: file [rewound on exit]
  */
  {
    char ss[255]; /* BIG space for line */
    int rdumCnt;
    double Ea, Eb;
    double RPts[12];
    int timeOffsetFlag;
    int i, j;
    double D;

    rdumCnt = 0;
    timeOffsetFlag = 0;

    while (fgets (ss, 255, TFile)) {
      if (!timeOffsetFlag) {
        double toff;
        timeOffsetFlag = findTimeOffset (ss, &toff);
        TS->timeOffset = toff;
      }
      if (!rdumCnt)
        rdumCnt = findRDUM (ss);
      if (rdumCnt && rdumCnt < 5) {
        cutToNumber (ss);
        for (i = 0; i < 3 && cmdnumberD (ss, &D); i++)
          RPts[(rdumCnt - 1) * 3 + i] = D;
        rdumCnt++;
      }
      // EXIT CONDITION:
      if (rdumCnt * timeOffsetFlag == 5) {
        for (j = 0; j < 3; j++) {
          TS->ZAxis += (RPts[3 + j] - RPts[j]) * (RPts[3 + j] - RPts[j]);
          TS->XAxis += (RPts[6 + j] - RPts[3 + j]) * (RPts[6 + j] - RPts[3 + j]);
        }

        TS->ZAxis = sqrt (TS->ZAxis) / 100.0; // convert to metres from cm
        TS->XAxis = sqrt (TS->XAxis) / 100.0;
        if (!modPosition) {
          TS->ZAxis = yheight;
          TS->XAxis = xwidth;
        }
        fprintf (stderr, "Time off sec == %g \n", TS->timeOffset);
        fprintf (stderr, "mod size z == %g \n", TS->ZAxis);
        // TS.rdumMid=calcRDum(RPts, TS);
        TS->rdumMid = TS->timeOffset; // Goran
        return;
      }
    }
    return;
  } /* processHeader */

  int
  readHtable (FILE* TFile, const double Einit, const double Eend, Source_ViewMod* TS, double modPosition, double xwidth, double yheight, int verbose)
  /*!
    Process a general h.o file to create an integrated
    table of results from Einit -> Eend
    \param Einit :: inital Energy
    \param Eend  :: final energy
  */
  {
    char ss[255]; /* BIG space for line */
    double Ea, Eb;
    double T, D;
    double Efrac;     // Fraction of an Energy Bin
    int Ftime;        // time Flag
    int eIndex;       // energy Index
    int tIndex;       // time Index
    double Tsum;      // Running integration
    double Efraction; // Amount to use for an energy/time bin

    // extern Source TS;

    int DebugCnt;
    int i;
    /*!
      Status Flag::
      Ftime=1 :: [time ] Reading Time : Data : Err [Exit on Total]

      Double Read File to determine how many bins and
      memory size
    */
    if (!TFile)
      return (0);
    Ea = 0.0;
    Eb = 0.0;
    fprintf (stderr, "Energy == %g %g\n", Einit, Eend);
    eIndex = -1;
    DebugCnt = 0;
    Ftime = 0;
    tIndex = 0;
    TS->nTime = 0;
    TS->nEnergy = 0;
    processHeader (TFile, TS, modPosition, xwidth, yheight);

    // Read file and get time bins:
    while (fgets (ss, 255, TFile) && Eend > Ea) {
      if (notComment (ss)) {
        DebugCnt++;
        if (!Ftime) {
          // find :: energy bin: <Number> to <Number>
          if (energyBin (ss, Einit, Eend, &Ea, &Eb)) {
            if (eIndex == 0)
              TS->nTime = tIndex;
            eIndex++;
          } else if (timeStart (ss)) {
            Ftime = 1;
            tIndex = 0;
          }
        } else // In the time section
        {
          if (timeEnd (ss)) // Found "total"
            Ftime = 0;
          else {
            // Need to read the line in the case of first run
            if (TS->nTime == 0) {
              if (cmdnumberD (ss, &T) && cmdnumberD (ss, &D))
                tIndex++;
            }
          }
        }
      }
    }
    // Plus 2 since we have a 0 counter and we have missed the last line.
    TS->nEnergy = eIndex + 2;
    if (!TS->nTime && tIndex)
      TS->nTime = tIndex;
    // printf("tIndex %d %d %d %d \n",tIndex,eIndex,TS->nEnergy,TS->nTime);

    /* SECOND TIME THROUGH:: */
    rewind (TFile);

    TS->Flux = matrix (TS->nEnergy, TS->nTime);
    TS->EInt = (double*)malloc (TS->nEnergy * sizeof (double));
    TS->TimeBin = (double*)malloc (TS->nTime * sizeof (double));
    TS->EnergyBin = (double*)malloc (TS->nEnergy * sizeof (double));

    Tsum = 0.0;
    Ea = 0.0;
    Eb = 0.0;
    eIndex = -1;
    DebugCnt = 0;
    Ftime = 0;
    tIndex = 0;
    TS->EInt[0] = 0.0;
    // Read file and get time bins
    while (fgets (ss, 255, TFile) && Eend > Ea) {
      if (notComment (ss)) {
        DebugCnt++;
        if (!Ftime) {
          if (energyBin (ss, Einit, Eend, &Ea, &Eb)) {
            eIndex++;
            TS->EnergyBin[eIndex] = (Einit > Ea) ? Einit : Ea;
            Efraction = calcFraction (Einit, Eend, Ea, Eb);
            Ftime++;
          }
        } else if (Ftime == 1) {
          if (timeStart (ss)) {
            Ftime = 2;
            tIndex = 0;
          }
        } else // In the time section
        {
          if (timeEnd (ss)) // Found "total"
          {
            Ftime = 0;
            TS->EInt[eIndex + 1] = Tsum;
          } else {
            // Need to read the line in the case of first run
            if (cmdnumberD (ss, &T) && cmdnumberD (ss, &D)) {
              TS->TimeBin[tIndex] = T / 1e8; // convert Time into second (from shakes)
              Tsum += D * Efraction;
              TS->Flux[eIndex][tIndex] = Tsum;
              tIndex++;
            }
          }
        }
      }
    }
    TS->EnergyBin[eIndex + 1] = Eend;
    TS->Total = Tsum;

    //  printf("tIndex %d %d %d \n",tIndex,eIndex,TS.nTime);
    // printf("Tsum %g \n",Tsum);
    // fprintf(stderr,"ebin1 ebinN %g %g\n",TS.EnergyBin[0],TS.EnergyBin[TS.nEnergy-1]);

    return 1;
  } // readHtable

  #pragma acc routine seq
  void
  getPoint (double* TV, double* EV, double* lim1, double* lim2, Source_ViewMod TS, _class_particle* _particle)
  /*!
    Calculate the Time and Energy
    by sampling the file.
    Uses TS table to find the point
    \param TV ::
    \param EV ::
    \param lim1 ::
    \param lim2 ::
  */
  {
    int i;

    double R0, R1, R, Rend;
    int Epnt; ///< Points to the next higher index of the neutron integral
    int Tpnt;
    int iStart, iEnd;
    double TRange, Tspread;
    double Espread, Estart;
    double* EX;

    // So that lowPoly+highPoly==maxPoly
    const int maxPoly = 6;
    const int highPoly = maxPoly / 2;
    const int lowPoly = maxPoly - highPoly;

    // static int testVar=0;

    R0 = rand01 ();
    /* if (testVar==0)
      {
      R0=1.0e-8;
      testVar=1;
      }
    */
    Rend = R = TS.Total * R0;
    // This gives Eint[Epnt-1] > R > Eint[Epnt]
    Epnt = binSearch (TS.nEnergy - 1, TS.EInt, R);

    //      if (Epnt < 0)
    //   Epnt=1;
    Tpnt = binSearch (TS.nTime - 1, TS.Flux[Epnt - 1], R);
    //  fprintf(stderr,"TBoundaryX == %12.6e %12.6e \n",TS.TimeBin[Tpnt-1],TS.TimeBin[Tpnt]);
    //  fprintf(stderr,"TFlux == %12.6e %12.6e %12.6e \n\n",TS.Flux[Epnt-1][Tpnt-1],R,TS.Flux[Epnt-1][Tpnt]);
    //  if (Epnt == -1)
    //{
    //    Epnt=0;
    // fprintf(stderr,"\n Rvals == %g %d %d %g\n",R,Epnt,Tpnt,TS.TimeBin[0]);
    //  fprintf(stderr,"EInt == %d %12.6e %12.6e %12.6e %12.6e \n",Epnt,TS.EInt[Epnt-1],R,TS.EInt[Epnt],TS.EInt[Epnt+1]);
    // printf("EBoundary == %12.6e %12.6e \n",TS.EnergyBin[Epnt],TS.EnergyBin[Epnt+1]);

    //  fprintf(stderr,"TFlux == %12.6e %12.6e %12.6e \n\n",TS.Flux[Epnt+1][Tpnt],R,TS.Flux[Epnt+1][Tpnt+1]);
    // }

    if (R < TS.Flux[Epnt - 1][Tpnt - 1] || R > TS.Flux[Epnt - 1][Tpnt]) {
      #ifndef OPENACC
      fprintf (stderr, "outside bin limits Tpnt/Epnt problem  %12.6e %12.6e %12.6e \n", TS.Flux[Epnt - 1][Tpnt - 1], R, TS.Flux[Epnt - 1][Tpnt]);
      #endif
    }

    if (Epnt == 0) {
      Estart = 0.0;
      Espread = TS.EInt[0];
      *EV = TS.EnergyBin[1];
    } else {
      Estart = TS.EInt[Epnt - 1];
      Espread = TS.EInt[Epnt] - TS.EInt[Epnt - 1];
      *EV = TS.EnergyBin[Epnt + 1];
    }

    if (Tpnt == 0 || Epnt == 0) {
      #ifndef OPENACC
      fprintf (stderr, "BIG ERROR WITH Tpnt: %d and Epnt: %d\n", Tpnt, Epnt);
      exit (1);
      #endif
    }
    if (Tpnt == TS.nTime) {
      #ifndef OPENACC
      fprintf (stderr, "BIG ERROR WITH Tpnt and Epnt\n");
      exit (1);
      #endif

      *TV = 0.0;
      Tspread = TS.Flux[Epnt - 1][0] - TS.EInt[Epnt - 1];
      TRange = TS.TimeBin[0];
      R -= TS.EInt[Epnt - 1];
    } else {
      *TV = TS.TimeBin[Tpnt - 1];
      TRange = TS.TimeBin[Tpnt] - TS.TimeBin[Tpnt - 1];
      Tspread = TS.Flux[Epnt - 1][Tpnt] - TS.Flux[Epnt - 1][Tpnt - 1];
      R -= TS.Flux[Epnt - 1][Tpnt - 1];
    }
    //  printf("R == %12.6e\n",R);
    R /= Tspread;
    *TV += TRange * R;

    R1 = TS.EInt[Epnt - 1] + Espread * rand01 ();
    iStart = Epnt > lowPoly ? Epnt - lowPoly : 0;                           // max(Epnt-halfPoly,0)
    iEnd = TS.nEnergy > Epnt + highPoly ? Epnt + highPoly : TS.nEnergy - 1; // min(nEnergy-1,Epnt+highPoly

    *EV = polInterp (TS.EInt + iStart, TS.EnergyBin + iStart, 1 + iEnd - iStart, R1);

    //  fprintf(stderr,"Energy == %d %d %12.6e %12.6e \n",iStart,iEnd,R1,*EV);
    //  fprintf(stderr,"bins == %12.6e %12.6e %12.6e %12.6e \n",TS.EnergyBin[iStart],TS.EnergyBin[iEnd],
    //	  TS.EInt[Epnt],TS.EInt[Epnt-1]);

    if (*TV < TS.TimeBin[Tpnt - 1] || *TV > TS.TimeBin[Tpnt]) {
      #ifndef OPENACC
      fprintf (stderr, "%d Tpnt %d Tval %g Epnt %d \n", TS.nTime, Tpnt, *TV, Epnt);
      fprintf (stderr, "TBoundary == %12.6e,%g , %12.6e \n\n", TS.TimeBin[Tpnt - 1], *TV, TS.TimeBin[Tpnt]);
      #endif
    }

    if (*EV < *lim1 || *EV > *lim2) {
      #ifndef OPENACC
      fprintf (stderr, "outside boundaries\n Epnt= %d, Tpnt= %d binlo %g|%g| binhi %g \n", Epnt, Tpnt, TS.EnergyBin[Epnt - 1], *EV, TS.EnergyBin[Epnt]);

      fprintf (stderr, "TS == %g %g :: %d %d \n", TS.EInt[Epnt - 1], TS.EInt[Epnt], iStart, iEnd);
      fprintf (stderr, "Points (%g) == ", R1);
      for (i = 0; i < iEnd - iStart; i++)
        fprintf (stderr, " %g %g", *(TS.EInt + i + iStart), *(TS.EnergyBin + iStart + i));
      fprintf (stderr, "\n");
      #endif
    }
    return;
  } /* getPoint */

  int
  cmdnumberI (char* mc, int* num, const int len)
  /*!
    \param mc == character string to use
    \param num :: Place to put output
    \param len == length of the character string to process
    returns 1 on success and 0 on failure
  */
  {
    int i, j;
    char* ss;
    char** endptr;
    double nmb;

    if (len < 1)
      return 0;
    j = 0;

    for (i = 0; i < len && mc[i] && (mc[i] == '\t' || mc[i] == ' ' || mc[i] == ','); i++)
      ;
    if (i == len || !mc[i])
      return 0;
    ss = malloc (sizeof (char) * (len + 1));
    if (!ss) {
      fprintf (stderr, "ViewModISIS: malloc() failure in cmdnumberI\n");
      exit (-1);
    }
    /*  char *ss=new char[len+1]; */
    for (; i < len && mc[i] != '\n' && mc[i] && mc[i] != '\t' && mc[i] != ' ' && mc[i] != ','; i++) {
      ss[j] = mc[i];
      j++;
    }
    if (!j) {
      free (ss);
      return 0; // This should be impossible
    }
    ss[j] = 0;
    endptr = malloc (sizeof (char*));
    nmb = strtod (ss, endptr);
    if (*endptr != ss + j) {
      free (endptr);
      free (ss);
      return 0;
    }
    *num = (double)nmb;
    for (j = 0; j < i && mc[j]; j++)
      mc[j] = ' ';
    free (endptr);
    free (ss);
    return 1;
  } /* cmdnumberI */

  FILE*
  openFile (char* FileName)
  /*
    Tries to open the file:
    (i) In current working directory
    (ii) In MC_Path directory + ISIS_tables extension
  */
  {
    FILE* efile = 0;
    int fLen;
    char extFileName[1024];
    char testFileName[2048];
    char mct[2048];

    fLen = strlen (FileName);

    if (fLen > 512) {
      fprintf (stderr, "Filename excessivley long [EXIT]:\n %s\n", FileName);
      exit (1);
    }

    strcpy (extFileName, FileName);
    strcpy (extFileName + fLen, ".mcstas");

    /* Now check for the requested moderator file. In terms of precedence,
       1) Use MCTABLES location if available
       2) Is a local file available in PWD?
       3) Is there an ISIS_tables in PWD?
       4) Is the file available from the MCSTAS/contrib/ISIS_tables folder?
       - otherwise fail */

    fprintf (stderr, "Searching for %s in multiple locations... -- \n", FileName);

    /* 1) Is MCTABLES set and file located there? */
    if (getenv ("MCTABLES")) {
      strcpy (mct, getenv ("MCTABLES"));
      sprintf (testFileName, "%s%c%s", mct, MC_PATHSEP_C, FileName);
      efile = fopen (testFileName, "r");
      if (efile) {
        fprintf (stderr, " - Found in MCTABLES folder %s!\n", mct);
        return efile;
      }
    }

    /* 2) Is the file located in working dir? */
    efile = fopen (FileName, "r");
    if (efile) {
      fprintf (stderr, " - Found in current directory!\n");
      return efile;
    }

    efile = fopen (extFileName, "r");
    if (efile)
      return efile;

    /* 3) Is the file in a local 'tablefiles' folder? */
    sprintf (testFileName, "%s%c%s", "ISIS_tables", MC_PATHSEP_C, FileName);
    efile = fopen (testFileName, "r");
    if (efile) {
      fprintf (stderr, " - Found in local ISIS_tables directory!\n");
      return efile;
    }

    /* 4) Is the file available within the MCSTAS install dir? */
    sprintf (testFileName, "%s%c%s%c%s%c%s", MCSTAS, MC_PATHSEP_C, "data", MC_PATHSEP_C, "ISIS_tables", MC_PATHSEP_C, FileName);
    efile = fopen (testFileName, "r");
    if (efile) {
      fprintf (stderr, " - Found in MCSTAS system dir: \n %s%c%s%c%s\n", MCSTAS, MC_PATHSEP_C, "contrib", MC_PATHSEP_C, "ISIS_tables");
      return efile;
    }

    /* If we reach here, the file was not found - raise fatal error */
    fprintf (stderr, "%s - Not found! \nPlease check your McStas installation and/or MCTABLES environment variable!\n", FileName);
    exit (1);
    return efile;
  } /* openFile */

  double
  strArea (Source_ViewMod TS, double focus_xw, double focus_yh, double dist) {
    /*
      Returns the mean Str view of the viewport
      This integrates over each point on the window focus_xw to focus_yh
      View port is symmetric so use only 1/4 of the view
      for the calcuation.
      Control Values TS.XAxis TS.ZAxis focus_xw focus_yh
    */

    double A;
    double Vx, Vy;    // view temp points
    double Mx, My;    // moderator x,y
    double D2;        // Distance ^2
    double projArea;  // viewport projection to moderator
    int i, j, aa, bb; // loop variables
    int NStep;

    NStep = 50;
    D2 = dist * dist;
    A = 0.0;
    fprintf (stderr, "TS axis == %g %g\n", TS.XAxis, TS.ZAxis);
    fprintf (stderr, "AW axis == %g %g\n", focus_xw, focus_yh);
    for (i = 0; i < NStep; i++) // Mod X
    {
      Mx = (i + 0.5) * TS.XAxis / (NStep * 2.0);
      for (j = 0; j < NStep; j++) // Mod Y
      {
        My = (j + 0.5) * TS.ZAxis / (NStep * 2.0);
        // Position on moderator == (Mx,My)
        for (aa = -NStep; aa <= NStep; aa++) // view port
          for (bb = -NStep; bb <= NStep; bb++) {
            Vx = aa * focus_xw / (2.0 * NStep + 1.0);
            Vy = bb * focus_yh / (2.0 * NStep + 1.0);
            A += 1.0 / ((Mx - Vx) * (Mx - Vx) + (My - Vy) * (My - Vy) + D2);
          }
      }
    }
    // change to Mx*My
    A *= (TS.XAxis * TS.ZAxis) / (NStep * NStep * (2.0 * NStep + 1.0) * (2.0 * NStep + 1.0));
    // Correct for the area of the viewport. (tables are per cm^2)
    A *= focus_xw * focus_yh * 10000;

    //   testing only - Goran
    // if (!modPosition)
    // {
    // projArea=focus_xw*focus_yh/tally/tally*(tally+dist)*(tally+dist);
    // A*=TS.XAxis*TS.ZAxis/(TS.XAxis*TS.ZAxis-projArea);
    // }

    fprintf (stderr, "Viewport == %g %g Moderator size == (%g * %g) m^2 \n", focus_xw, focus_yh, TS.XAxis, TS.ZAxis);
    fprintf (stderr, "Dist == %g (metres) \n", dist);
    fprintf (stderr, "Viewport Solid angle == %g str\n", A / (focus_xw * focus_yh * 10000.0));
    fprintf (stderr, "Solid angle used == %g str\n", A);
    return A;
  } /* strArea */

/* Shared user declarations for all components types 'Guide_channeled'. */
/*****************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2006, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/ref-lib.h
*
* %Identification
* Written by: Peter Christiansen
* Date: August, 2006
* Origin: RISOE
* Release: McStas 1.10
* Version: $Revision$
*
* Add StdDoubleReflecFunc, ExtendedReflecFunc
* Date: October, 2022
* Locale: ESS
* Release: McStas 2.7x, 3.1x
*
* Commonly used reflection functions are declared in this file which
* are used by some guide and mirror components.
*
* Depends on read_table-lib
*
* Usage: within SHARE
* %include "ref-lib"
*
****************************************************************************/
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2002, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/read_table-lib.h
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McStas 1.6
* Version: $Revision$
*
* This file is to be imported by components that may read data from table files
* It handles some shared functions.
*
* This library may be used directly as an external library. It has no dependency
*
* Usage: within SHARE
* %include "read_table-lib"
*
*******************************************************************************/

#ifndef READ_TABLE_LIB_H
#define READ_TABLE_LIB_H "$Revision$"

#define READ_TABLE_STEPTOL  0.04 /* tolerancy for constant step approx */

#ifndef MC_PATHSEP_C
#ifdef WIN32
#define MC_PATHSEP_C '\\'
#define MC_PATHSEP_S "\\"
#else  /* !WIN32 */
#ifdef MAC
#define MC_PATHSEP_C ':'
#define MC_PATHSEP_S ":"
#else  /* !MAC */
#define MC_PATHSEP_C '/'
#define MC_PATHSEP_S "/"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* !MC_PATHSEP_C */

#ifndef MCSTAS
#ifdef WIN32
#define MCSTAS "C:\\mcstas\\lib"
#else  /* !WIN32 */
#ifdef MAC
#define MCSTAS ":mcstas:lib" /* ToDo: What to put here? */
#else  /* !MAC */
#define MCSTAS "/usr/local/lib/mcstas"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* !MCSTAS */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _MSC_EXTENSIONS
#include <strings.h>
#else
#  include <string.h>
#  define strcasecmp _stricmp
#  define strncasecmp _strnicmp
#endif

  typedef struct struct_table
  {
    char    filename[1024];
    long    filesize;
    char   *header;  /* text header, e.g. comments */
    double *data;    /* vector { x[0], y[0], ... x[n-1], y[n-1]... } */
    double  min_x;   /* min value of first column */
    double  max_x;   /* max value of first column */
    double  step_x;  /* minimal step value of first column */
    long    rows;    /* number of rows in matrix block */
    long    columns; /* number of columns in matrix block */

    long    begin;   /* start fseek index of block */
    long    end;     /* stop  fseek index of block */
    long    block_number;  /* block index. 0 is catenation of all */
    long    array_length;  /* number of elements in the t_Table array */
    char    monotonic;     /* true when 1st column/vector data is monotonic */
    char    constantstep;  /* true when 1st column/vector data has constant step */
    char    method[32];    /* interpolation method: nearest, linear */
    char    quiet;   /*output level for messages to the console 0: print all messages, 1:only print some/including errors, 2: never print anything.*/
  } t_Table;

/*maximum number of rows to rebin a table = 1M*/
enum { mcread_table_rebin_maxsize = 1000000 };

typedef struct t_Read_table_file_item {
    int ref_count;
    t_Table *table_ref;
} t_Read_table_file_item;

typedef enum enum_Read_table_file_actions {STORE,FIND,GC}  t_Read_table_file_actions;

/* read_table-lib function prototypes */
/* ========================================================================= */

/* 'public' functions */
long     Table_Read              (t_Table *Table, char *File, long block_number);
long     Table_Read_Offset       (t_Table *Table, char *File, long block_number,
                                  long *offset, long max_lines);
long     Table_Read_Offset_Binary(t_Table *Table, char *File, char *Type,
                                  long *Offset, long Rows, long Columns);
long     Table_Rebin(t_Table *Table); /* rebin table with regular 1st column and interpolate all columns 2:end */
long     Table_Info (t_Table Table);
#pragma acc routine
double   Table_Index(t_Table Table,   long i, long j); /* get indexed value */
#pragma acc routine
double   Table_Value(t_Table Table, double X, long j); /* search X in 1st column and return interpolated value in j-column */
t_Table *Table_Read_Array(char *File, long *blocks);
void     Table_Free_Array(t_Table *Table);
long     Table_Info_Array(t_Table *Table);
int      Table_SetElement(t_Table *Table, long i, long j, double value);
long     Table_Init(t_Table *Table, long rows, long columns); /* create a Table */
#pragma acc routine
double   Table_Value2d(t_Table Table, double X, double Y);    /* same as Table_Index with non-integer indices and 2d interpolation */
MCDETECTOR Table_Write(t_Table Table, char*file, char*xl, char*yl, 
           double x1, double x2, double y1, double y2); /* write Table to disk */
void * Table_File_List_Handler(t_Read_table_file_actions action, void *item, void *item_modifier);
t_Table *Table_File_List_find(char *name, int block, int offset);
int Table_File_List_gc(t_Table *tab);
void *Table_File_List_store(t_Table *tab);

#define Table_ParseHeader(header, ...) \
  Table_ParseHeader_backend(header,__VA_ARGS__,NULL);

char **Table_ParseHeader_backend(char *header, ...);
FILE *Open_File(char *name, const char *Mode, char *path);


/* private functions */
void Table_Free(t_Table *Table);
long Table_Read_Handle(t_Table *Table, FILE *fid, long block_number, long max_lines, char *name);
static void Table_Stat(t_Table *Table);
#pragma acc routine
double Table_Interp1d(double x, double x1, double y1, double x2, double y2);
#pragma acc routine
double Table_Interp1d_nearest(double x, double x1, double y1, double x2, double y2);
#pragma acc routine
double Table_Interp2d(double x, double y, double x1, double y1, double x2, double y2,
double z11, double z12, double z21, double z22);


#endif

/* end of read_table-lib.h */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/read_table-lib.c
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McStas CVS_090504
* Version: $Revision$
*
* This file is to be imported by components that may read data from table files
* It handles some shared functions. Embedded within instrument in runtime mode.
*
* Usage: within SHARE
* %include "read_table-lib"
*
*******************************************************************************/

#ifndef READ_TABLE_LIB_H
#include "read_table-lib.h"
#endif

#ifndef READ_TABLE_LIB_C
#define READ_TABLE_LIB_C "$Revision$"


/*******************************************************************************
 * void *Table_File_List_Handler(action, item, item_modifier)
 *   ACTION: handle file entries in the read_table-lib file list. If a file is read - it is supposed to be
 *   stored in a list such that we can avoid reading the same file many times.
 *   input  action: FIND, STORE, GC. check if file exists in the list, store an item in the list, or check if it can be garbage collected.
 *   input item: depends on the action.
 *    FIND)  item is a filename, and item_modifier is the block number
 *    STORE) item is the Table to store - item_modifier is ignored
 *    GC)    item is the Table to check. If it has a ref_count >1 then this is simply decremented.
 *   return  depends on the action
 *    FIND)  return a reference to a table+ref_count item if found - NULL otherwise. I.e. NULL means the file has not been read before and must be read again.
 *    STORE) return NULL always
 *    GC)    return NULL if no garbage collection is needed, return an adress to the t_Table which should be garbage collected. 0x1 is returned if
 *           the item is not found in the list
*******************************************************************************/
void * Table_File_List_Handler(t_Read_table_file_actions action, void *item, void *item_modifier){

    /* logic here is Read_Table should include a call to FIND. If found the return value should just be used as
     * if the table had been read from disk. If not found then read the table and STORE.
     * Table_Free should include a call to GC. If this returns non-NULL then we should proceed with freeing the memory
     * associated with the table item - otherwise only decrement the reference counter since there are more references
     * that may need it.*/

    static t_Read_table_file_item read_table_file_list[1024];  
    static int read_table_file_count=0;

    t_Read_table_file_item *tr;
    switch(action){
        case FIND:
            /*interpret data item as a filename, if it is found return a pointer to the table and increment refcount.
             * if not found return the item itself*/
            tr=read_table_file_list;
            while ( tr->table_ref!=NULL ){
                int i=*((int*) item_modifier);
                int j=*( ((int*) item_modifier)+1);
                if ( !strcmp(tr->table_ref->filename,(char *) item) &&
                        tr->table_ref->block_number==i && tr->table_ref->begin==j ){
                    tr->ref_count++;
                    return (void *) tr;
                }
                tr++;
            }
            return NULL;
        case STORE:
            /*find an available slot and store references to table there*/
            tr=&(read_table_file_list[read_table_file_count++]);
            tr->table_ref = ((t_Table *) item);
            tr->ref_count++;
            return NULL;
        case GC:
            /* Should this item be garbage collected (freed) - if so scratch the entry and return the address of the item - 
             * else decrement ref_count and return NULL.
             * A non-NULL return expects the item to actually be freed afterwards.*/
            tr=read_table_file_list;
            while ( tr->table_ref!=NULL ){
                if ( tr->table_ref->data ==((t_Table *)item)->data && 
                        tr->table_ref->block_number == ((t_Table *)item)->block_number){
                    /*matching item found*/
                    if (tr->ref_count>1){
                        /*the item is found and no garbage collection needed*/
                        tr->ref_count--;
                        return NULL;
                    }else{
                        /* The item is found and the reference counter is 1.
                         * This means we should garbage collect. Move remaining list items up one slot,
                         * and return the table for garbage collection by caller*/
                        while (tr->table_ref!=NULL){
                            *tr=*(tr+1);
                            tr++;
                        }
                        read_table_file_count--;
                        return (t_Table *) item;
                    }
                }
                tr++;
            }
            /* item not found, and so should be garbage collected. This could be the case if freeing a
             * Table that has been constructed from code - not read from file. Return 0x1 to flag it for
             * collection.*/
            return (void *) 0x1 ;
    }
    /* If we arrive here, nothing worked, return NULL */
    return NULL;
}

/* Access functions to the handler*/

/********************************************
 * t_Table *Table_File_List_find(char *name, int block, int offset)
 * input name: filename to search for in the file list
 * input block: data block in the file as each file may contain more than 1 data block.
 * return a ref. to a table if it is found (you may use this pointer and skip reading the file), NULL otherwise (i.e. go ahead and read the file)
*********************************************/
t_Table *Table_File_List_find(char *name, int block, int offset){
    int vars[2]={block,offset};
    t_Read_table_file_item *item = Table_File_List_Handler(FIND,name, vars);
    if (item == NULL){
        return NULL;
    }else{
        return item->table_ref;
    }
}
/********************************************
 * int Table_File_List_gc(t_Table *tab)
 * input tab: the table to check for references.
 * return 0: no garbage collection needed
 *        1: Table's data and header (at least) should be freed.
*********************************************/
int Table_File_List_gc(t_Table *tab){
    void *rval=Table_File_List_Handler(GC,tab,0);
    if (rval==NULL) return 0;
    else return 1;
}


/*****************************************************************************
 * void *Table_File_List_store(t_Table *tab)
 * input tab: pointer to table to store.
 * return None. 
*******************************************************************************/
void *Table_File_List_store(t_Table *tab){
    return Table_File_List_Handler(STORE,tab,0);
}


/*******************************************************************************
* FILE *Open_File(char *name, char *Mode, char *path)
*   ACTION: search for a file and open it. Optionally return the opened path.
*   input   name:  file name from which table should be extracted
*           mode: "r", "w", "a" or any valid fopen mode
*           path:  NULL or a pointer to at least 1024 allocated chars
*   return  initialized file handle or NULL in case of error
*******************************************************************************/

  FILE *Open_File(char *File, const char *Mode, char *Path)
  {
    char path[1024];
    FILE *hfile = NULL;
    
    if (!File || File[0]=='\0')                     return(NULL);
    if (!strcmp(File,"NULL") || !strcmp(File,"0"))  return(NULL);
    
    /* search in current or full path */
    strncpy(path, File, 1024);
    hfile = fopen(path, Mode);
    if(!hfile)
    {
      char dir[1024];

      if (!hfile && instrument_source[0] != '\0' && strlen(instrument_source)) /* search in instrument source location */
      {
        char *path_pos   = NULL;
        /* extract path: searches for last file separator */
        path_pos    = strrchr(instrument_source, MC_PATHSEP_C);  /* last PATHSEP */
        if (path_pos) {
          long path_length = path_pos +1 - instrument_source;  /* from start to path+sep */
          if (path_length) {
            strncpy(dir, instrument_source, path_length);
            dir[path_length] = '\0';
            snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
            hfile = fopen(path, Mode);
          }
        }
      }
      if (!hfile && instrument_exe[0] != '\0' && strlen(instrument_exe)) /* search in PWD instrument executable location */
      {
        char *path_pos   = NULL;
        /* extract path: searches for last file separator */
        path_pos    = strrchr(instrument_exe, MC_PATHSEP_C);  /* last PATHSEP */
        if (path_pos) {
          long path_length = path_pos +1 - instrument_exe;  /* from start to path+sep */
          if (path_length) {
            strncpy(dir, instrument_exe, path_length);
            dir[path_length] = '\0';
            snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
            hfile = fopen(path, Mode);
          }
        }
      }
      if (!hfile) /* search in HOME or . */
      {
        strcpy(dir, getenv("HOME") ? getenv("HOME") : ".");
        snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if (!hfile) /* search in MCSTAS/data */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        snprintf(path, 1024, "%s%c%s%c%s", dir, MC_PATHSEP_C, "data", MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if (!hfile) /* search in MVCSTAS/contrib */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        snprintf(path, 1024, "%s%c%s%c%s", dir, MC_PATHSEP_C, "contrib", MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if(!hfile)
      {
        // fprintf(stderr, "Warning: Could not open input file '%s' (Open_File)\n", File);
        return (NULL);
      }
    }
    if (Path) strncpy(Path, path, 1024);
    return(hfile);
  } /* end Open_File */

/*******************************************************************************
* long Read_Table(t_Table *Table, char *name, int block_number)
*   ACTION: read a single Table from a text file
*   input   Table: pointer to a t_Table structure
*           name:  file name from which table should be extracted
*           block_number: if the file does contain more than one
*                 data block, then indicates which one to get (from index 1)
*                 a 0 value means append/catenate all
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
* The routine stores any line starting with '#', '%' and ';' into the header
* File is opened, read and closed
* Other lines are interpreted as numerical data, and stored.
* Data block should be a rectangular matrix or vector.
* Data block may be rebinned with Table_Rebin (also sort in ascending order)
*******************************************************************************/
  long Table_Read(t_Table *Table, char *File, long block_number)
  { /* reads all or a single data block from 'file' and returns a Table structure  */
    return(Table_Read_Offset(Table, File, block_number, NULL, 0));
  } /* end Table_Read */

/*******************************************************************************
* long Table_Read_Offset(t_Table *Table, char *name, int block_number, long *offset
*                        long max_rows)
*   ACTION: read a single Table from a text file, starting at offset
*     Same as Table_Read(..) except:
*   input   offset:    pointer to an offset (*offset should be 0 at start)
*           max_rows: max number of data rows to read from file (0 means all)
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
*           updated *offset position (where end of reading occured)
*******************************************************************************/
  long Table_Read_Offset(t_Table *Table, char *File,
                         long block_number, long *offset,
                         long max_rows)
  { /* reads all/a data block in 'file' and returns a Table structure  */
    FILE *hfile;
    long  nelements=0;
    long  begin=0;
    long  filesize=0;
    char  name[1024];
    char  path[1024];
    struct stat stfile;

    /*Need to be able to store the pointer*/
    if (!Table) return(-1);

    /*TK: Valgrind flags it as usage of uninitialised variable: */
    Table->quiet = 0;

    //if (offset && *offset) snprintf(name, 1024, "%s@%li", File, *offset);
    //else                   
    strncpy(name, File, 1024);
    if(offset && *offset){
        begin=*offset;
    }
    /* Check if the table has already been read from file.
     * If so just reuse the table, if not (this is flagged by returning NULL
     * set up a new table and read the data into it */
    t_Table *tab_p= Table_File_List_find(name,block_number,begin);
    if ( tab_p!=NULL ){
        /*table was found in the Table_File_List*/
        *Table=*tab_p;
        MPI_MASTER(
            if(Table->quiet<1)
              printf("Reusing input file '%s' (Table_Read_Offset)\n", name);
            );
        return Table->rows*Table->columns;
    }

    /* open the file */
    hfile = Open_File(File, "r", path);
    if (!hfile) return(-1);
    else {
      MPI_MASTER(
          if(Table->quiet<1)
            printf("Opening input file '%s' (Table_Read_Offset)\n", path);
          );
    }
    
    /* read file state */
    stat(path,&stfile); filesize = stfile.st_size;
    if (offset && *offset) fseek(hfile, *offset, SEEK_SET);
    begin     = ftell(hfile);
    
    Table_Init(Table, 0, 0);

    /* read file content and set the Table */
    nelements = Table_Read_Handle(Table, hfile, block_number, max_rows, name);
    Table->begin = begin;
    Table->end   = ftell(hfile);
    Table->filesize = (filesize>0 ? filesize : 0);
    Table_Stat(Table);
    
    Table_File_List_store(Table);

    if (offset) *offset=Table->end;
    fclose(hfile);
    return(nelements);

  } /* end Table_Read_Offset */

/*******************************************************************************
* long Table_Read_Offset_Binary(t_Table *Table, char *File, char *type,
*                               long *offset, long rows, long columns)
*   ACTION: read a single Table from a binary file, starting at offset
*     Same as Table_Read_Offset(..) except that it handles binary files.
*   input   type: may be "float"/NULL or "double"
*           offset: pointer to an offset (*offset should be 0 at start)
*           rows   : number of rows (0 means read all)
*           columns: number of columns
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
*           updated *offset position (where end of reading occured)
*******************************************************************************/
  long Table_Read_Offset_Binary(t_Table *Table, char *File, char *type,
                                long *offset, long rows, long columns)
  { /* reads all/a data block in binary 'file' and returns a Table structure  */
    long    nelements, sizeofelement;
    long    filesize;
    FILE   *hfile;
    char    path[1024];
    struct stat stfile;
    double *data    = NULL;
    double *datatmp = NULL;
    long    i;
    long    begin;

    if (!Table) return(-1);

    Table_Init(Table, 0, 0);
    
    /* open the file */
    hfile = Open_File(File, "r", path);
    if (!hfile) return(-1);
    else {
      MPI_MASTER(
          if(Table->quiet<1)
            printf("Opening input file '%s' (Table_Read, Binary)\n", path);
      );
    }
    
    /* read file state */
    stat(File,&stfile);
    filesize = stfile.st_size;
    Table->filesize=filesize;
    
    /* read file content */
    if (type && !strcmp(type,"double")) sizeofelement = sizeof(double);
    else  sizeofelement = sizeof(float);
    if (offset && *offset) fseek(hfile, *offset, SEEK_SET);
    begin     = ftell(hfile);
    if (rows && filesize > sizeofelement*columns*rows)
      nelements = columns*rows;
    else nelements = (long)(filesize/sizeofelement);
    if (!nelements || filesize <= *offset) return(0);
    data    = (double*)malloc(nelements*sizeofelement);
    if (!data) {
      if(!(Table->quiet>1))
        fprintf(stderr,"Error: allocating %ld elements for %s file '%s'. Too big (Table_Read_Offset_Binary).\n", nelements, type, File);
      exit(-1);
    }
    nelements = fread(data, sizeofelement, nelements, hfile);

    if (!data || !nelements)
    {
      if(!(Table->quiet>1))
        fprintf(stderr,"Error: reading %ld elements from %s file '%s' (Table_Read_Offset_Binary)\n", nelements, type, File);
      exit(-1);
    }
    Table->begin   = begin;
    Table->end     = ftell(hfile);
    if (offset) *offset=Table->end;
    fclose(hfile);

    datatmp = (double*)realloc(data, (double)nelements*sizeofelement);
    if (!datatmp) {
      free(data);
      fprintf(stderr,"Error: reallocating %ld elements for %s file '%s'. Too big (Table_Read_Offset_Binary).\n", nelements, type, File);
      exit(-1);
    } else {
      data = datatmp;
    }
    /* copy file data into Table */
    if (type && !strcmp(type,"double")) Table->data = data;
    else {
      float  *s;
      double *dataf;
      s     = (float*)data;
      dataf = (double*)malloc(sizeof(double)*nelements);
      if (!dataf) {
	fprintf(stderr, "Could not allocate data block of size %ld\n", nelements);
	exit(-1);
      }
      for (i=0; i<nelements; i++)
        dataf[i]=s[i];
      free(data);
      Table->data = dataf;
    }
    strncpy(Table->filename, File, 1024);
    Table->rows    = nelements/columns;
    Table->columns = columns;
    Table->array_length = 1;
    Table->block_number = 1;

    Table_Stat(Table);

    return(nelements);
  } /* end Table_Read_Offset_Binary */

/*******************************************************************************
* long Table_Read_Handle(t_Table *Table, FILE *fid, int block_number, long max_rows, char *name)
*   ACTION: read a single Table from a text file handle (private)
*   input   Table:pointer to a t_Table structure
*           fid:  pointer to FILE handle
*           block_number: if the file does contain more than one
*                 data block, then indicates which one to get (from index 1)
*                 a 0 value means append/catenate all
*           max_rows: if non 0, only reads that number of lines
*   return  initialized single Table t_Table structure containing data, header, ...
*           modified Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
* The routine stores any line starting with '#', '%' and ';' into the header
* Other lines are interpreted as numerical data, and stored.
* Data block should be a rectangular matrix or vector.
* Data block may be rebined with Table_Rebin (also sort in ascending order)
*******************************************************************************/
  long Table_Read_Handle(t_Table *Table, FILE *hfile,
                         long block_number, long max_rows, char *name)
  { /* reads all/a data block from 'file' handle and returns a Table structure  */
    double *Data              = NULL;
    double *Datatmp           = NULL;
    char *Header              = NULL;
    char *Headertmp           = NULL;
    long  malloc_size         = CHAR_BUF_LENGTH;
    long  malloc_size_h       = 4096;
    long  Rows = 0,   Columns = 0;
    long  count_in_array      = 0;
    long  count_in_header     = 0;
    long  count_invalid       = 0;
    long  block_Current_index = 0;
    char  flag_End_row_loop   = 0;

    if (!Table) return(-1);
    Table_Init(Table, 0, 0);
    if (name && name[0]!='\0') strncpy(Table->filename, name, 1024);

    if(!hfile) {
       fprintf(stderr, "Error: File handle is NULL (Table_Read_Handle).\n");
       return (-1);
    }
    Header = (char*)  calloc(malloc_size_h, sizeof(char));
    Data   = (double*)calloc(malloc_size,   sizeof(double));
    if ((Header == NULL) || (Data == NULL)) {
       fprintf(stderr, "Error: Could not allocate Table and Header (Table_Read_Handle).\n");
       return (-1);
    }

    int flag_In_array = 0;
    do { /* while (!flag_End_row_loop) */
      char  *line=malloc(1024*CHAR_BUF_LENGTH*sizeof(char));
      long  back_pos=0;   /* ftell start of line */

      if (!line) {
	fprintf(stderr,"Could not allocate line buffer\n");
	exit(-1);
      }
      back_pos = ftell(hfile);
      if (fgets(line, 1024*CHAR_BUF_LENGTH, hfile) != NULL) { /* analyse line */
        /* first skip blank and tabulation characters */
        int i = strspn(line, " \t");

        /* handle comments: stored in header */
        if (NULL != strchr("#%;/", line[i]))
        { /* line is a comment */
          count_in_header += strlen(line);
          if (count_in_header >= malloc_size_h) {
            /* if succeed and in array : add (and realloc if necessary) */
            malloc_size_h = count_in_header+4096;
            char *Headertmp = (char*)realloc(Header, malloc_size_h*sizeof(char));
	    if(!Headertmp) {
	      free(Header);
	             fprintf(stderr, "Error: Could not reallocate Header (Table_Read_Handle).\n");
		     free(Header);
		     return (-1);
	    } else {
	      Header = Headertmp;
	    }
          }
          strncat(Header, line, 4096);
          flag_In_array=0;
          /* exit line and file if passed desired block */
          if (block_number > 0 && block_number == block_Current_index) {
            flag_End_row_loop = 1;
          }

          /* Continue with next line */
          continue;
        }
        if (strstr(line, "***"))
        {
          count_invalid++;
          /* Continue with next line */
          continue;
        }

        /* get the number of columns splitting line with strtok */
        char  *lexeme;
        char  flag_End_Line = 0;
        long  block_Num_Columns = 0;
        const char seps[] = " ,;\t\n\r";

        lexeme = strtok(line, seps);
        while (!flag_End_Line) {
          if ((lexeme != NULL) && (lexeme[0] != '\0')) {
            /* reading line: the token is not empty */
            double X;
            int    count=1;
            /* test if we have 'NaN','Inf' */
            if (!strncasecmp(lexeme,"NaN",3))
              X = 0;
            else if (!strncasecmp(lexeme,"Inf",3) || !strncasecmp(lexeme,"+Inf",4))
              X = FLT_MAX;
            else if (!strncasecmp(lexeme,"-Inf",4))
              X = -FLT_MAX;
            else
              count = sscanf(lexeme,"%lg",&X);
            if (count == 1) {
              /* reading line: the token is a number in the line */
              if (!flag_In_array) {
                /* reading num: not already in a block: starts a new data block */
                block_Current_index++;
                flag_In_array    = 1;
                block_Num_Columns= 0;
                if (block_number > 0) {
                  /* initialise a new data block */
                  Rows = 0;
                  count_in_array = 0;
                } /* else append */
              }
              /* reading num: all blocks or selected block */
              if (flag_In_array && (block_number == 0 ||
                  block_number == block_Current_index)) {
                /* starting block: already the desired number of rows ? */
                if (block_Num_Columns == 0 &&
                    max_rows > 0 && Rows >= max_rows) {
                  flag_End_Line      = 1;
                  flag_End_row_loop  = 1;
                  flag_In_array      = 0;
                  /* reposition to begining of line (ignore line) */
                  fseek(hfile, back_pos, SEEK_SET);
                } else { /* store into data array */
                  if (count_in_array >= malloc_size) {
                    /* realloc data buffer if necessary */
                    malloc_size = count_in_array*1.5;
                    Datatmp = (double*) realloc(Data, malloc_size*sizeof(double));
                    if (Datatmp == NULL) {
                      fprintf(stderr, "Error: Can not re-allocate memory %zi (Table_Read_Handle).\n",
                              malloc_size*sizeof(double));
		      free(Data);
                      return (-1);
                    } else {
                      Data=Datatmp;
                    }
                  }
                  if (0 == block_Num_Columns) Rows++;
                  Data[count_in_array] = X;
                  count_in_array++;
                  block_Num_Columns++;
                }
              } /* reading num: end if flag_In_array */
            } /* end reading num: end if sscanf lexeme -> numerical */
            else {
              /* reading line: the token is not numerical in that line. end block */
              if (block_Current_index == block_number) {
                flag_End_Line = 1;
                flag_End_row_loop = 1;
              } else {
                flag_In_array = 0;
                flag_End_Line = 1;
              }
            }
          }
          else {
            /* no more tokens in line */
            flag_End_Line = 1;
            if (block_Num_Columns > 0) Columns = block_Num_Columns;
          }

          // parse next token
          lexeme = strtok(NULL, seps);

        } /* while (!flag_End_Line) */
      } /* end: if fgets */
      else flag_End_row_loop = 1; /* else fgets : end of file */
      free(line);
    } while (!flag_End_row_loop); /* end while flag_End_row_loop */

    Table->block_number = block_number;
    Table->array_length = 1;

    // shrink header to actual size (plus terminating 0-byte)
    if (count_in_header) {
      Headertmp = (char*)realloc(Header, count_in_header*sizeof(char) + 1);
      if(!Headertmp) {
	fprintf(stderr, "Error: Could not shrink Header (Table_Read_Handle).\n");
	free(Header);
	return (-1);
      } else {
        Header = Headertmp;
      }
    }
    Table->header = Header;

    if (count_in_array*Rows*Columns == 0)
    {
      Table->rows         = 0;
      Table->columns      = 0;
      free(Data);
      return (0);
    }
    if (Rows * Columns != count_in_array)
    {
      fprintf(stderr, "Warning: Read_Table :%s %s Data has %li values that should be %li x %li\n",
        (Table->filename[0] != '\0' ? Table->filename : ""),
        (!block_number ? " catenated" : ""),
        count_in_array, Rows, Columns);
      Columns = count_in_array; Rows = 1;
    }
    if (count_invalid)
    {
      fprintf(stderr,"Warning: Read_Table :%s %s Data has %li invalid lines (*****). Ignored.\n",
      (Table->filename[0] != '\0' ? Table->filename : ""),
        (!block_number ? " catenated" : ""),
        count_invalid);
    }
    Datatmp     = (double*)realloc(Data, count_in_array*sizeof(double));
    if(!Datatmp) {
      fprintf(stderr, "Error: Could reallocate Data block to %li doubles (Table_Read_Handle).\n", count_in_array);
      free(Data);
      return (-1);
    } else {
      Data = Datatmp;
    }
    Table->data         = Data;
    Table->rows         = Rows;
    Table->columns      = Columns;

    return (count_in_array);

  } /* end Table_Read_Handle */

/*******************************************************************************
* long Table_Rebin(t_Table *Table)
*   ACTION: rebin a single Table, sorting 1st column in ascending order
*   input   Table: single table containing data.
*                  The data block is reallocated in this process
*   return  updated Table with increasing, evenly spaced first column (index 0)
*           number of data elements (-1: error, 0:empty data)
*******************************************************************************/
  long Table_Rebin(t_Table *Table)
  {
    double new_step=0;
    long   i;
    /* performs linear interpolation on X axis (0-th column) */

    if (!Table) return(-1);
    if (!Table->data 
    || Table->rows*Table->columns == 0 || !Table->step_x)
      return(0);
    Table_Stat(Table); /* recompute statitstics and minimal step */
    new_step = Table->step_x; /* minimal step in 1st column */

    if (!(Table->constantstep)) /* not already evenly spaced */
    {
      long Length_Table;
      double *New_Table;

      Length_Table = ceil(fabs(Table->max_x - Table->min_x)/new_step)+1;
      /*return early if the rebinned table will become too large*/
      if (Length_Table > mcread_table_rebin_maxsize){
        fprintf(stderr,"WARNING: (Table_Rebin): Rebinning table from %s would exceed 1M rows. Skipping.\n", Table->filename); 
        return(Table->rows*Table->columns);
      }
      New_Table    = (double*)malloc(Length_Table*Table->columns*sizeof(double));
      if (!New_Table) {
	fprintf(stderr,"Could not allocate New_Table of size %ld x %ld\n", Length_Table, Table->columns);
	exit(-1);
      }
      for (i=0; i < Length_Table; i++)
      {
        long   j;
        double X;
        X = Table->min_x + i*new_step;
        New_Table[i*Table->columns] = X;
        for (j=1; j < Table->columns; j++)
          New_Table[i*Table->columns+j]
                = Table_Value(*Table, X, j);
      } /* end for i */

      Table->rows = Length_Table;
      Table->step_x = new_step;
      Table->max_x = Table->min_x + (Length_Table-1)*new_step; 
      /*max might not be the same anymore
       * Use Length_Table -1 since the first and laset rows are the limits of the defined interval.*/
      free(Table->data);
      Table->data = New_Table;
      Table->constantstep=1;
    } /* end else (!constantstep) */
    return (Table->rows*Table->columns);
  } /* end Table_Rebin */

/*******************************************************************************
* double Table_Index(t_Table Table, long i, long j)
*   ACTION: read an element [i,j] of a single Table
*   input   Table: table containing data
*           i : index of row      (0:Rows-1)
*           j : index of column   (0:Columns-1)
*   return  Value = data[i][j]
* Returns Value from the i-th row, j-th column of Table
* Tests are performed on indexes i,j to avoid errors
*******************************************************************************/

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif

double Table_Index(t_Table Table, long i, long j)
{
  long AbsIndex;

  if (Table.rows == 1 || Table.columns == 1) {
    /* vector */
    j = MIN(MAX(0, i+j), Table.columns*Table.rows - 1);
    i = 0;
  } else {
    /* matrix */
    i = MIN(MAX(0, i), Table.rows - 1);
    j = MIN(MAX(0, j), Table.columns - 1);
  }

  /* handle vectors specifically */
  AbsIndex = i*(Table.columns)+j;

  if (Table.data != NULL)
    return (Table.data[AbsIndex]);
  else
    return 0;
} /* end Table_Index */

/*******************************************************************************
* void Table_SetElement(t_Table *Table, long i, long j, double value)
*   ACTION: set an element [i,j] of a single Table
*   input   Table: table containing data
*           i : index of row      (0:Rows-1)
*           j : index of column   (0:Columns-1)
*           value = data[i][j]
* Returns 0 in case of error
* Tests are performed on indexes i,j to avoid errors
*******************************************************************************/
int Table_SetElement(t_Table *Table, long i, long j,
                     double value)
{
  long AbsIndex;

  if (Table->rows == 1 || Table->columns == 1) {
    /* vector */
    j = MIN(MAX(0, i+j), Table->columns*Table->rows - 1); i=0;
  } else {
    /* matrix */
    i = MIN(MAX(0, i), Table->rows - 1);
    j = MIN(MAX(0, j), Table->columns - 1);
  }

  AbsIndex = i*(Table->columns)+j;
  if (Table->data != NULL) {
    Table->data[AbsIndex] = value;
    return 1;
  }

  return 0;
} /* end Table_SetElement */

/*******************************************************************************
* double Table_Value(t_Table Table, double X, long j)
*   ACTION: read column [j] of a single Table at row which 1st column is X
*   input   Table: table containing data.
*           X : data value in the first column (index 0)
*           j : index of column from which is extracted the Value (0:Columns-1)
*   return  Value = data[index for X][j] with linear interpolation
* Returns Value from the j-th column of Table corresponding to the
* X value for the 1st column (index 0)
* Tests are performed (within Table_Index) on indexes i,j to avoid errors
* NOTE: data should rather be monotonic, and evenly sampled.
*******************************************************************************/
double Table_Value(t_Table Table, double X, long j)
{
  long   Index = -1;
  double X1=0, Y1=0, X2=0, Y2=0;
  double ret=0;

  if (X > Table.max_x) return Table_Index(Table,Table.rows-1  ,j);
  if (X < Table.min_x) return Table_Index(Table,0  ,j);

  // Use constant-time lookup when possible
  if(Table.constantstep) {
    Index = (long)floor(
              (X - Table.min_x) / (Table.max_x - Table.min_x) * (Table.rows-1));
    X1 = Table_Index(Table,Index-1,0);
    X2 = Table_Index(Table,Index  ,0);
  }
  // Use binary search on large, monotonic tables
  else if(Table.monotonic && Table.rows > 100) {
    long left = Table.min_x;
    long right = Table.max_x;

    while (!((X1 <= X) && (X < X2)) && (right - left > 1)) {
      Index = (left + right) / 2;

      X1 = Table_Index(Table, Index-1, 0);
      X2 = Table_Index(Table, Index,   0);

      if (X < X1) {
        right = Index;
      } else {
        left  = Index;
      }
    }
  }

  // Fall back to linear search, if no-one else has set X1, X2 correctly
  if (!((X1 <= X) && (X < X2))) {
    /* look for index surrounding X in the table -> Index */
    for (Index=1; Index <= Table.rows-1; Index++) {
        X1 = Table_Index(Table, Index-1,0);
        X2 = Table_Index(Table, Index  ,0);
        if ((X1 <= X) && (X < X2)) break;
      } /* end for Index */
  }

  Y1 = Table_Index(Table,Index-1, j);
  Y2 = Table_Index(Table,Index  , j);

#ifdef OPENACC
#define strcmp(a,b) str_comp(a,b)
#endif

  if (!strcmp(Table.method,"linear")) {
    ret = Table_Interp1d(X, X1,Y1, X2,Y2);
  }
  else if (!strcmp(Table.method,"nearest")) {
    ret = Table_Interp1d_nearest(X, X1,Y1, X2,Y2);
  }

#ifdef OPENACC
#ifdef strcmp
#undef strcmp
#endif
#endif

  return ret;
} /* end Table_Value */

/*******************************************************************************
* double Table_Value2d(t_Table Table, double X, double Y)
*   ACTION: read element [X,Y] of a matrix Table
*   input   Table: table containing data.
*           X : row index, may be non integer
*           Y : column index, may be non integer
*   return  Value = data[index X][index Y] with bi-linear interpolation
* Returns Value for the indices [X,Y]
* Tests are performed (within Table_Index) on indexes i,j to avoid errors
* NOTE: data should rather be monotonic, and evenly sampled.
*******************************************************************************/
double Table_Value2d(t_Table Table, double X, double Y)
  {
    long   x1,x2,y1,y2;
    double z11,z12,z21,z22;
    double ret=0;

    x1 = (long)floor(X);
    y1 = (long)floor(Y);

    if (x1 > Table.rows-1 || x1 < 0) {
      x2 = x1;
    } else {
      x2 = x1 + 1;
    }

    if (y1 > Table.columns-1 || y1 < 0) {
      y2 = y1;
    } else {
      y2 = y1 + 1;
    }

    z11 = Table_Index(Table, x1, y1);

    if (y2 != y1) z12=Table_Index(Table, x1, y2); else z12 = z11;
    if (x2 != x1) z21=Table_Index(Table, x2, y1); else z21 = z11;
    if (y2 != y1) z22=Table_Index(Table, x2, y2); else z22 = z21;

#ifdef OPENACC
#define strcmp(a,b) str_comp(a,b)
#endif

    if (!strcmp(Table.method,"linear"))
      ret = Table_Interp2d(X,Y, x1,y1,x2,y2, z11,z12,z21,z22);
#ifdef OPENACC
#ifdef strcmp
#undef strcmp
#endif
#endif
    else {
      if (fabs(X-x1) < fabs(X-x2)) {
        if (fabs(Y-y1) < fabs(Y-y2)) ret = z11; else ret = z12;
      } else {
        if (fabs(Y-y1) < fabs(Y-y2)) ret = z21; else ret = z22;
      }
    }
    return ret;
  } /* end Table_Value2d */


/*******************************************************************************
* void Table_Free(t_Table *Table)
*   ACTION: free a single Table. First Call Table_File_list_gc. If this returns
*   non-zero it means there are more refernces to the table, and so the table
*   should not bee freed.
*   return: empty Table
*******************************************************************************/
  void Table_Free(t_Table *Table)
  {
    if( !Table_File_List_gc(Table) ){
       return;
    } 
    if (!Table) return;
    if (Table->data   != NULL) free(Table->data);
    if (Table->header != NULL) free(Table->header);
    Table->data   = NULL;
    Table->header = NULL;
  } /* end Table_Free */

/******************************************************************************
* void Table_Info(t_Table Table)
*    ACTION: print informations about a single Table
*******************************************************************************/
  long Table_Info(t_Table Table)
  {
    char buffer[256];
    long ret=0;

    if (!Table.block_number) strcpy(buffer, "catenated");
    else sprintf(buffer, "block %li", Table.block_number);
    printf("Table from file '%s' (%s)",
        Table.filename[0] != '\0' ? Table.filename : "", buffer);
    if ((Table.data != NULL) && (Table.rows*Table.columns))
    {
      printf(" is %li x %li ", Table.rows, Table.columns);
      if (Table.rows*Table.columns > 1)
        printf("(x=%g:%g)", Table.min_x, Table.max_x);
      else printf("(x=%g) ", Table.min_x);
      ret = Table.rows*Table.columns;
      if (Table.monotonic)    printf(", monotonic");
      if (Table.constantstep) printf(", constant step");
      printf(". interpolation: %s\n", Table.method);
    }
    else printf(" is empty.\n");

    if (Table.header && strlen(Table.header)) {
      char *header;
      int  i;
      header = malloc(80);
      if (!header) return(ret);
      for (i=0; i<80; header[i++]=0);
      strncpy(header, Table.header, 75);
      if (strlen(Table.header) > 75) {
        strcat( header, " ...");
      }
      for (i=0; i<strlen(header); i++)
        if (header[i] == '\n' || header[i] == '\r') header[i] = ';';
      printf("  '%s'\n", header);
      free(header);
    }

    return(ret);
  } /* end Table_Info */

/******************************************************************************
* long Table_Init(t_Table *Table, m, n)
*   ACTION: initialise a Table to empty m by n table
*   return: empty Table
******************************************************************************/
long Table_Init(t_Table *Table, long rows, long columns)
{
  double *data=NULL;
  long   i;

  if (!Table) return(0);

  Table->header  = NULL;
  Table->filename[0]= '\0';
  Table->filesize= 0;
  Table->min_x   = 0;
  Table->max_x   = 0;
  Table->step_x  = 0;
  Table->block_number = 0;
  Table->array_length = 0;
  Table->monotonic    = 0;
  Table->constantstep = 0;
  Table->begin   = 0;
  Table->end     = 0;
  strcpy(Table->method,"linear");

  if (rows*columns >= 1) {
    data    = (double*)malloc(rows*columns*sizeof(double));
    if (data) for (i=0; i < rows*columns; data[i++]=0);
    else {
      if(Table->quiet<2)
        fprintf(stderr,"Error: allocating %ld double elements."
            "Too big (Table_Init).\n", rows*columns);
      rows = columns = 0;
    }
  }
  Table->rows    = (rows >= 1 ? rows : 0);
  Table->columns = (columns >= 1 ? columns : 0);
  Table->data    = data;
  return(Table->rows*Table->columns);
} /* end Table_Init */

/******************************************************************************
* long Table_Write(t_Table Table, char *file, x1,x2, y1,y2)
*   ACTION: write a Table to disk (ascii).
*     when x1=x2=0 or y1=y2=0, the table default limits are used.
*   return: 0=all is fine, non-0: error
*******************************************************************************/
MCDETECTOR Table_Write(t_Table Table, char *file, char *xl, char *yl, 
  double x1, double x2, double y1, double y2)
{
  MCDETECTOR detector;

  if ((Table.data == NULL) && (Table.rows*Table.columns)) {
    detector.m = 0;
    detector.xmin = 0;
    detector.xmax = 0;
    detector.ymin = 0;
    detector.ymax = 0;
    detector.zmin = 0;
    detector.zmax = 0; 
    detector.intensity = 0;
    detector.error = 0;
    detector.events = 0;
    detector.min = 0;
    detector.max = 0;
    detector.mean = 0;
    detector.centerX = 0;
    detector.halfwidthX = 0;
    detector.centerY = 0;
    detector.halfwidthY = 0;
    detector.rank = 0;
    detector.istransposed = 0;
    detector.n = 0;
    detector.p = 0;
    detector.date_l = 0;
    detector.p0 = NULL;
    detector.p1 = NULL;
    detector.p2 = NULL;
    return(detector); /* Table is empty - nothing to do */
  }
  if (!x1 && !x2) {
    x1 = Table.min_x;
    x2 = Table.max_x;
  }
  if (!y1 && !y2) {
    y1 = 1;
    y2 = Table.columns;
  }

  /* transfer content of the Table into a 2D detector */
  Coords coords = { 0, 0, 0};
  Rotation rot;
  rot_set_rotation(rot, 0, 0, 0);
  
  if (Table.rows == 1 || Table.columns == 1) {
    detector = mcdetector_out_1D(Table.filename,
                      xl ? xl : "", yl ? yl : "",
                      "x", x1, x2,
                      Table.rows * Table.columns,
                      NULL, Table.data, NULL,
		      file, file, coords, rot,9999);
  } else {
    detector = mcdetector_out_2D(Table.filename,
                      xl ? xl : "", yl ? yl : "",
                      x1, x2, y1, y2,
                      Table.rows, Table.columns,
                      NULL, Table.data, NULL,
		      file, file, coords, rot,9999);
  }
  return(detector);
}

/******************************************************************************
* void Table_Stat(t_Table *Table)
*   ACTION: computes min/max/mean step of 1st column for a single table (private)
*   return: updated Table
*******************************************************************************/
  static void Table_Stat(t_Table *Table)
  {
    long   i;
    double max_x, min_x;
    double row=1;
    char   monotonic=1;
    char   constantstep=1;
    double step=0;
    long n;

    if (!Table) return;
    if (!Table->rows || !Table->columns) return;
    if (Table->rows == 1) row=0; // single row
    max_x = -FLT_MAX;
    min_x =  FLT_MAX;
    n     = (row ? Table->rows : Table->columns);
    /* get min and max of first column/vector */
    for (i=0; i < n; i++)
    {
      double X;
      X = (row ? Table_Index(*Table,i  ,0)
                               : Table_Index(*Table,0, i));
      if (X < min_x) min_x = X;
      if (X > max_x) max_x = X;
    } /* for */
    
    /* test for monotonicity and constant step if the table is an XY or single vector */
    if (n > 1) {
      /* mean step */
      step = (max_x - min_x)/(n-1);
      /* now test if table is monotonic on first column, and get minimal step size */
      for (i=0; i < n-1; i++) {
        double X, diff;;
        X    = (row ? Table_Index(*Table,i  ,0)
                    : Table_Index(*Table,0,  i));
        diff = (row ? Table_Index(*Table,i+1,0)
                    : Table_Index(*Table,0,  i+1)) - X;
        if (diff && fabs(diff) < fabs(step)) step = diff;
        /* change sign ? */
        if ((max_x - min_x)*diff < 0 && monotonic)
          monotonic = 0;
      } /* end for */
      
      /* now test if steps are constant within READ_TABLE_STEPTOL */
      if(!step){
        /*means there's a disconitnuity -> not constantstep*/
        constantstep=0;
      }else if (monotonic) {
        for (i=0; i < n-1; i++) {
          double X, diff;
          X    = (row ? Table_Index(*Table,i  ,0)
              : Table_Index(*Table,0,  i));
          diff = (row ? Table_Index(*Table,i+1,0)
              : Table_Index(*Table,0,  i+1)) - X;
          if ( fabs(step)*(1+READ_TABLE_STEPTOL) < fabs(diff) ||
                fabs(diff) < fabs(step)*(1-READ_TABLE_STEPTOL) )
          { constantstep = 0; break; }
        }
      }

    }
    Table->step_x= step;
    Table->max_x = max_x;
    Table->min_x = min_x;
    Table->monotonic = monotonic;
    Table->constantstep = constantstep;
  } /* end Table_Stat */

/******************************************************************************
* t_Table *Table_Read_Array(char *File, long *blocks)
*   ACTION: read as many data blocks as available, iteratively from file
*   return: initialized t_Table array, last element is an empty Table.
*           the number of extracted blocks in non NULL pointer *blocks
*******************************************************************************/
  t_Table *Table_Read_Array(char *File, long *blocks)
  {
    t_Table *Table_Array    = NULL;
    t_Table *Table_Arraytmp = NULL;
    long offset=0;
    long block_number=0;
    long allocated=256;
    long nelements=1;

    /* first allocate an initial empty t_Table array */
    Table_Array = (t_Table *)malloc(allocated*sizeof(t_Table));
    if (!Table_Array) {
      fprintf(stderr, "Error: Can not allocate memory %zi (Table_Read_Array).\n",
         allocated*sizeof(t_Table));
      *blocks = 0;
      return (NULL);
    }

    while (nelements > 0)
    {
      t_Table Table;

      /* if ok, set t_Table block number else exit loop */
      block_number++;
      Table.block_number = block_number;
      
      /* access file at offset and get following block. Block number is from the set offset
       * hence the hardcoded 1 - i.e. the next block counted from offset.*/
      nelements = Table_Read_Offset(&Table, File, 1, &offset,0);
      /*if the block is empty - don't store it*/
      if (nelements>0){
          /* if t_Table array is not long enough, expand and realocate */
          if (block_number >= allocated-1) {
              allocated += 256;
              Table_Arraytmp = (t_Table *)realloc(Table_Array,
                      allocated*sizeof(t_Table));
              if (!Table_Arraytmp) {
                  fprintf(stderr, "Error: Can not re-allocate memory %zi (Table_Read_Array).\n",
                          allocated*sizeof(t_Table));
                  free(Table_Array);
                  *blocks = 0;
                  return (NULL);
              } else {
                Table_Array = Table_Arraytmp;
              }
          }
          /* store it into t_Table array */
          //snprintf(Table.filename, 1024, "%s#%li", File, block_number-1);
          Table_Array[block_number-1] = Table;
      }
      /* continues until we find an empty block */
    }
    /* send back number of extracted blocks */
    if (blocks) *blocks = block_number-1;

    /* now store total number of elements in Table array */
    for (offset=0; offset < block_number;
      Table_Array[offset++].array_length = block_number-1);

    return(Table_Array);
  } /* end Table_Read_Array */
/*******************************************************************************
* void Table_Free_Array(t_Table *Table)
*   ACTION: free a Table array
*******************************************************************************/
  void Table_Free_Array(t_Table *Table)
  {
    long index;
    if (!Table) return;
    for (index=0;index < Table[0].array_length; index++){
            Table_Free(&Table[index]);
    }
    free(Table);
  } /* end Table_Free_Array */

/******************************************************************************
* long Table_Info_Array(t_Table *Table)
*    ACTION: print informations about a Table array
*    return: number of elements in the Table array
*******************************************************************************/
  long Table_Info_Array(t_Table *Table)
  {
    long index=0;

    if (!Table) return(-1);
    while (index < Table[index].array_length
       && (Table[index].data || Table[index].header)
       && (Table[index].rows*Table[index].columns) ) {
      Table_Info(Table[index]);
      index++;
    }
    printf("This Table array contains %li elements\n", index);
    return(index);
  } /* end Table_Info_Array */

/******************************************************************************
* char **Table_ParseHeader(char *header, symbol1, symbol2, ..., NULL)
*    ACTION: search for char* symbols in header and return their value or NULL
*            the search is not case sensitive.
*            Last argument MUST be NULL
*    return: array of char* with line following each symbol, or NULL if not found
*******************************************************************************/
#ifndef MyNL_ARGMAX
#define MyNL_ARGMAX 50
#endif

char **Table_ParseHeader_backend(char *header, ...){
  va_list ap;
  char exit_flag=0;
  int counter   =0;
  char **ret    =NULL;
  if (!header || header[0]=='\0') return(NULL);

  ret = (char**)calloc(MyNL_ARGMAX, sizeof(char*));
  if (!ret) {
    printf("Table_ParseHeader: Cannot allocate %i values array for Parser (Table_ParseHeader).\n",
      MyNL_ARGMAX);
    return(NULL);
  }
  for (counter=0; counter < MyNL_ARGMAX; ret[counter++] = NULL);
  counter=0;

  va_start(ap, header);
  while(!exit_flag && counter < MyNL_ARGMAX-1)
  {
    char *arg_char=NULL;
    char *pos     =NULL;
    /* get variable argument value as a char */
    arg_char = va_arg(ap, char *);
    if (!arg_char || arg_char[0]=='\0'){
      exit_flag = 1; break;
    }
    /* search for the symbol in the header */
    pos = (char*)strcasestr(header, arg_char);
    if (pos) {
      char *eol_pos;
      eol_pos = strchr(pos+strlen(arg_char), '\n');
      if (!eol_pos)
        eol_pos = strchr(pos+strlen(arg_char), '\r');
      if (!eol_pos)
        eol_pos = pos+strlen(pos)-1;
      ret[counter] = (char*)malloc(eol_pos - pos);
      if (!ret[counter]) {
        printf("Table_ParseHeader: Cannot allocate value[%i] array for Parser searching for %s (Table_ParseHeader).\n",
          counter, arg_char);
        exit_flag = 1; break;
      }
      strncpy(ret[counter], pos+strlen(arg_char), eol_pos - pos - strlen(arg_char));
      ret[counter][eol_pos - pos - strlen(arg_char)]='\0';
    }
    counter++;
  }
  va_end(ap);
  return(ret);
} /* Table_ParseHeader */

/******************************************************************************
* double Table_Interp1d(x, x1, y1, x2, y2)
*    ACTION: interpolates linearly at x between y1=f(x1) and y2=f(x2)
*    return: y=f(x) value
*******************************************************************************/
double Table_Interp1d(double x,
  double x1, double y1,
  double x2, double y2)
{
  double slope;
  if (x2 == x1) return (y1+y2)/2;
  if (y1 == y2) return  y1;
  slope = (y2 - y1)/(x2 - x1);
  return y1+slope*(x - x1);
} /* Table_Interp1d */

/******************************************************************************
* double Table_Interp1d_nearest(x, x1, y1, x2, y2)
*    ACTION: table lookup with nearest method at x between y1=f(x1) and y2=f(x2)
*    return: y=f(x) value
*******************************************************************************/
double Table_Interp1d_nearest(double x,
  double x1, double y1,
  double x2, double y2)
{
  if (fabs(x-x1) < fabs(x-x2)) return (y1);
  else return(y2);
} /* Table_Interp1d_nearest */

/******************************************************************************
* double Table_Interp2d(x,y, x1,y1, x2,y2, z11,z12,z21,z22)
*    ACTION: interpolates bi-linearly at (x,y) between z1=f(x1,y1) and z2=f(x2,y2)
*    return: z=f(x,y) value
*    x,y |   x1   x2
*    ----------------
*     y1 |   z11  z21
*     y2 |   z12  z22
*******************************************************************************/
double Table_Interp2d(double x, double y,
  double x1, double y1,
  double x2, double y2,
  double z11, double z12, double z21, double z22)
{
  double ratio_x, ratio_y;
  if (x2 == x1) return Table_Interp1d(y, y1,z11, y2,z12);
  if (y1 == y2) return Table_Interp1d(x, x1,z11, x2,z21);

  ratio_y = (y - y1)/(y2 - y1);
  ratio_x = (x - x1)/(x2 - x1);
  return (1-ratio_x)*(1-ratio_y)*z11 + ratio_x*(1-ratio_y)*z21
    + ratio_x*ratio_y*z22         + (1-ratio_x)*ratio_y*z12;
} /* Table_Interp2d */

/* end of read_table-lib.c */
#endif // READ_TABLE_LIB_C


#ifndef REF_LIB_H
#define REF_LIB_H "$Revision$"

void StdReflecFunc(double, double*, double*);
void TableReflecFunc(double, t_Table*, double*);
void StdDoubleReflecFunc(double, double*, double*);
void ExtendedReflecFunc(double, double*, double*);

#endif

/* end of ref-lib.h */
/****************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2006, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/ref-lib.c
*
* %Identification
* Written by: Peter Christiansen
* Date: August, 2006
* Origin: RISOE
* Release: McStas 1.10
* Version: $Revision$
*
* Add StdDoubleReflecFunc, ExtendedReflecFunc
* Date: October, 2022
* Locale: ESS
* Release: McStas 2.7.x, 3.x
*
* Commonly used reflection functions are declared in this file which
* are used by some guide and mirror components.
*
* Variable names have prefix 'mc_ref_' for 'McStas Reflection'
* to avoid conflicts
*
* Usage: within SHARE
* %include "ref-lib"
*
****************************************************************************/

#ifndef REF_LIB_H
#include "ref-lib.h"
#endif

#ifndef READ_TABLE_LIB_H
#include "read_table-lib.h"
#include "read_table-lib.c"
#endif

/****************************************************************************
* void StdReflecFunc(double q, double *par, double *r)
*
* The McStas standard analytic parametrization of the reflectivity.
* The parameters are:
* R0:      [1]    Low-angle reflectivity
* Qc:      [AA-1] Critical scattering vector
* alpha:   [AA]   Slope of reflectivity
* m:       [1]    m-value of material. Zero means completely absorbing.
* W:       [AA-1] Width of supermirror cut-off
*****************************************************************************/
#pragma acc routine seq
void StdReflecFunc(double mc_pol_q, double *mc_pol_par, double *mc_pol_r) {
    double R0    = mc_pol_par[0];
    double Qc    = mc_pol_par[1];
    double alpha = mc_pol_par[2];
    double m     = mc_pol_par[3];
    double W     = mc_pol_par[4];
    double beta  = 0;
    mc_pol_q     = fabs(mc_pol_q);
    double arg;
    double m_corr;

    /* Simpler parametrization from Henrik Jacobsen uses these values that depend on m only.
       double m_value=m*0.9853+0.1978;
       double W=-0.0002*m_value+0.0022;
       double alpha=0.2304*m_value+5.0944;
       double beta=-7.6251*m_value+68.1137;
       If W and alpha are set to 0, use Henrik's approach for estimating these parameters
       and apply the formulation:
       arg = R0*0.5*(1-tanh(arg))*(1-alpha*(q-Qc)+beta*(q-Qc)*(q-Qc));
    */
    if (W==0 && alpha==0) {
      m = m * 0.9853 + 0.1978;
      m_corr = m * 0.9853 - 0.7875;
      W = -0.0002 * m_corr + 0.0022;
      alpha = 0.2304 * m_corr + 5.0944;
      beta = -7.6251 * m_corr + 68.1137;
      if (m==3) {
	alpha = m_corr;
	beta = 0;
      }
      arg = (mc_pol_q - m*Qc)/W; // <--- here m, not m_corr!!
    }

    arg = W > 0 ? (mc_pol_q - m*Qc)/W : 11;

    if (arg > 10 || m <= 0 || Qc <=0 || R0 <= 0) {
      *mc_pol_r = 0;
      return;
    }

    if (m < 1) { Qc *= m; m=1; }

    if(mc_pol_q <= Qc) {
      *mc_pol_r = R0;
      return;
    }


    *mc_pol_r = R0*0.5*(1 - tanh(arg))*(1 - alpha*(mc_pol_q - Qc) + beta*(mc_pol_q - Qc)*(mc_pol_q - Qc));

    return;
  }

/****************************************************************************
* void TableReflecFunc(double q, t_Table *par, double *r) {
*
* Looks up the reflectivity in a table using the routines in read_table-lib.
*****************************************************************************/
#pragma acc routine seq
void TableReflecFunc(double mc_pol_q, t_Table *mc_pol_par, double *mc_pol_r) {

  *mc_pol_r = Table_Value(*mc_pol_par, mc_pol_q, 1);
  if(*mc_pol_r>1)
    *mc_pol_r = 1;
  return;
}


/****************************************************************************
* void StdDoubleReflecFunc(double q, double *par, double *r)
* 
* The McStas standard analytic parametrization of the reflectivity for 
* double-side coated supermirror.
* The parameters are:
* R0:      [1]    Low-angle reflectivity
* Qc:      [AA-1] Critical scattering vector
* alpha:   [AA]   Slope of reflectivity
* m:       [1]    m-value of material. Zero means completely absorbing.
* W:       [AA-1] Width of supermirror cut-off
*****************************************************************************/
void StdDoubleReflecFunc(double mc_pol_q, double *mc_pol_par, double *mc_pol_r) {
    double R0    = mc_pol_par[0];
    double Qc    = mc_pol_par[1];
    double alpha = mc_pol_par[2];
    double m     = mc_pol_par[3];
    double W     = mc_pol_par[4];
    double beta  = 0;
    mc_pol_q     = fabs(mc_pol_q);
    double arg;
        
    /* Simpler parametrization from Henrik Jacobsen uses these values that depend on m only.
       double m_value=m*0.9853+0.1978;
       double W=-0.0002*m_value+0.0022;
       double alpha=0.2304*m_value+5.0944;
       double beta=-7.6251*m_value+68.1137; 
       If W and alpha are set to 0, use Henrik's approach for estimating these parameters
       and apply the formulation:
       arg = R0*0.5*(1-tanh(arg))*(1-alpha*(q-Qc)+beta*(q-Qc)*(q-Qc));
    */  
    if (W==0 && alpha==0) {
      m=m*0.9853+0.1978;
      W=-0.0002*m+0.0022;
      alpha=0.2304*m+5.0944;
      beta=-7.6251*m+68.1137;
      if (m<=3) {
	alpha=m;
	beta=0;
      }
    }
    
    arg = W > 0 ? (mc_pol_q - m*Qc)/W : 11;

    if (arg > 10 || m <= 0 || Qc <=0 || R0 <= 0) {
      *mc_pol_r = 0;
      return;
    }
    
    if (m < 1) { Qc *= m; m=1; }
    
	/*
		Reflectivity R0 = single-side coated supermirror reflectivity
		double-side coated supermirror reflectivity = 1- (1-R0)^2
	*/
	
    if(mc_pol_q <= Qc) {      
      *mc_pol_r = 1- (1-R0)*(1-R0);
      return;
    }
    
    
    R0 = R0*0.5*(1 - tanh(arg))*(1 - alpha*(mc_pol_q - Qc) + beta*(mc_pol_q - Qc)*(mc_pol_q - Qc));
    *mc_pol_r = 1- (1-R0)*(1-R0);
   
    return;
  }

void ExtendedReflecFunc(double mc_pol_q, double *mc_pol_par, double *mc_pol_r) {
    double R0    = mc_pol_par[0];
    double Qc    = mc_pol_par[1];
    double alpha = mc_pol_par[2];
    double m     = mc_pol_par[3];
    double W     = mc_pol_par[4];
    double beta  = mc_pol_par[5];
    mc_pol_q     = fabs(mc_pol_q);
    double arg;

    /* Simpler parametrization from Henrik Jacobsen uses these values that depend on m only.
       double m_value=m*0.9853+0.1978;
       double W=-0.0002*m_value+0.0022;
       double alpha=0.2304*m_value+5.0944;
       double beta=-7.6251*m_value+68.1137;
       If W and alpha are set to 0, use Henrik's approach for estimating these parameters
       and apply the formulation:
       arg = R0*0.5*(1-tanh(arg))*(1-alpha*(q-Qc)+beta*(q-Qc)*(q-Qc));
    */
    if (W==0 && alpha==0) {
      m=m*0.9853+0.1978;
      W=-0.0002*m+0.0022;
      alpha=0.2304*m+5.0944;
      beta=-7.6251*m+68.1137;
      if (m<=3) {
	alpha=m;
	beta=0;
      }
    }

    arg = W > 0 ? (mc_pol_q - m*Qc)/W : 11;

    if (arg > 10 || m <= 0 || Qc <=0 || R0 <= 0) {
      *mc_pol_r = 0;
      return;
    }

    if (m < 1) { Qc *= m; m=1; }

    if(mc_pol_q <= Qc) {
      *mc_pol_r = R0;
      return;
    }


    *mc_pol_r = R0*0.5*(1 - tanh(arg))*(1 - alpha*(mc_pol_q - Qc) + beta*(mc_pol_q - Qc)*(mc_pol_q - Qc));

    return;
  }

/* end of ref-lib.c */


/* Shared user declarations for all components types 'Isotropic_Sqw'. */

  #ifndef ISOTROPIC_SQW
  #define ISOTROPIC_SQW $Revision$

  /* {j d F2 DW Dd inv2d q F} + { Sq if j == -1}*/
  #ifndef Crystallographica
  #define Crystallographica { 4,5,7,0,0,0,0, 0,0 }
  #define Fullprof          { 4,0,8,0,0,5,0, 0,0 }
  #define Undefined         { 0,0,0,0,0,0,0, 0,0 }
  #define Lazy              {17,6,0,0,0,0,0,13,0 }
  #endif
  /* special case for [q,Sq] table */
  #define qSq               {-1,0,0,0,0,0,1, 0,0 }


/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2008, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/interoff.h
*
* %Identification
* Written by: Reynald Arnerin
* Date:    Jun 12, 2008
* Release:
* Version:
*
* Object File Format intersection header for McStas. Requires the qsort function.
*
* Such files may be obtained with e.g.
*   qhull < points.xyz Qx Qv Tv o > points.off
* where points.xyz has format:
*   3
*   <nb_points>
*   <x> <y> <z>
*   ...
* The resulting file should have its first line being changed from '3' into 'OFF'.
* It can then be displayed with geomview.
* A similar, but somewhat older solution is to use 'powercrust' with e.g.
*   powercrust -i points.xyz
* which will generate a 'pc.off' file to be renamed as suited.
*
*******************************************************************************/

#ifndef INTEROFF_LIB_H
#define INTEROFF_LIB_H "$Revision$"

#ifndef OFF_EPSILON
#define OFF_EPSILON 1e-13
#endif

#ifndef OFF_INTERSECT_MAX
#ifdef OPENACC
#define OFF_INTERSECT_MAX 100
#else
#define OFF_INTERSECT_MAX 1024
#endif
#endif

//#include <float.h>

#define N_VERTEX_DISPLAYED    200000

typedef struct intersection {
	MCNUM time;  	  //time of the intersection
	Coords v;	      //intersection point
	Coords normal;  //normal vector of the surface intersected
	short in_out;	  //1 if the ray enters the volume, -1 otherwise
	short edge;	    //1 if the intersection is on the boundary of the polygon, and error is possible
	unsigned long index; // index of the face
} intersection;

typedef struct polygon {
  MCNUM* p;       //vertices of the polygon in adjacent order, this way : x1 | y1 | z1 | x2 | y2 | z2 ...
  int npol;       //number of vertices
  #pragma acc shape(p[0:npol]) init_needed(npol)
  Coords normal;
  double D;
} polygon;

typedef struct off_struct {
    long vtxSize;
    long polySize;
    long faceSize;
    Coords* vtxArray;
    #pragma acc shape(vtxArray[0:vtxSize]) init_needed(vtxSize)
    Coords* normalArray;
    #pragma acc shape(vtxArray[0:faceSize]) init_needed(faceSize)
    unsigned long* faceArray;
    #pragma acc shape(vtxArray[0:faceSize][0:polySize]) init_needed(faceSize,polySize)
    double* DArray;
    #pragma acc shape(vtxArray[0:polySize]) init_needed(polySize)
    char *filename;
    int mantidflag;
    long mantidoffset;
    intersection intersects[OFF_INTERSECT_MAX]; // After a call to off_intersect_all contains the list of intersections.
    int nextintersect;                 // 'Next' intersection (first t>0) solution after call to off_intersect_all
    int numintersect;               // Number of intersections after call to off_intersect_all
} off_struct;

/*******************************************************************************
* long off_init(  char *offfile, double xwidth, double yheight, double zdepth, off_struct* data)
* ACTION: read an OFF file, optionally center object and rescale, initialize OFF data structure
* INPUT: 'offfile' OFF file to read
*        'xwidth,yheight,zdepth' if given as non-zero, apply bounding box.
*           Specifying only one of these will also use the same ratio on all axes
*        'notcenter' center the object to the (0,0,0) position in local frame when set to zero
* RETURN: number of polyhedra and 'data' OFF structure
*******************************************************************************/
long off_init(  char *offfile, double xwidth, double yheight, double zdepth,
                int notcenter, off_struct* data);

/*******************************************************************************
* int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*         data is the full OFF structure, including a list intersection type
*******************************************************************************/
#pragma acc routine
int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data );

/*******************************************************************************
* int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
#pragma acc routine
int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data );

/*****************************************************************************
* int off_intersectx(double* l0, double* l3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double kx, double ky, double kz,
     off_struct data )
* ACTION: computes intersection of an xray trajectory with an object.
* INPUT:  x,y,z and kx,ky,kz, are spatial coordinates and wavevector of the x-ray
*         respectively. data points to the OFF data structure.
* RETURN: the number of polyhedral the trajectory intersects
*         l0 and l3 are the smallest incoming and outgoing intersection lengths
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
#pragma acc routine
int off_x_intersect(double *l0,double *l3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double kx, double ky, double kz,
     off_struct data );

/*******************************************************************************
* void off_display(off_struct data)
* ACTION: display up to N_VERTEX_DISPLAYED points from the object
*******************************************************************************/
void off_display(off_struct);

/*******************************************************************************
void p_to_quadratic(double eq[], Coords acc,
                    Coords pos, Coords vel,
                    double* teq)
* ACTION: define the quadratic for the intersection of a parabola with a plane
* INPUT: 'eq' plane equation
*        'acc' acceleration vector
*        'vel' velocity of the particle
*        'pos' position of the particle
*         equation of plane A * x + B * y + C * z - D = 0
*         eq[0] = (C*az)/2+(B*ay)/2+(A*ax)/2
*         eq[1] = C*vz+B*vy+A*vx
*         eq[2] = C*z0+B*y0+A*x0-D
* RETURN: equation of parabola: teq(0) * t^2 + teq(1) * t + teq(2)
*******************************************************************************/
void p_to_quadratic(Coords norm, MCNUM d, Coords acc, Coords pos, Coords vel,
		    double* teq);

/*******************************************************************************
int quadraticSolve(double eq[], double* x1, double* x2);
* ACTION: solves the quadratic for the roots x1 and x2 
*         eq[0] * t^2 + eq[1] * t + eq[2] = 0
* INPUT: 'eq' the coefficients of the parabola
* RETURN: roots x1 and x2 and the number of solutions
*******************************************************************************/
int quadraticSolve(double* eq, double* x1, double* x2);

#endif

/* end of interoff-lib.h */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2008, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/interoff-lib.c
*
* %Identification
* Written by: Reynald Arnerin
* Date:    Jun 12, 2008
* Origin: ILL
* Release: $Revision$
* Version: McStas X.Y
*
* Object File Format intersection library for McStas. Requires the qsort function.
*
* Such files may be obtained with e.g.
*   qhull < points.xyz Qx Qv Tv o > points.off
* where points.xyz has format (it supports comments):
*   3
*   <nb_points>
*   <x> <y> <z>
*   ...
* The resulting file should have its first line being changed from '3' into 'OFF'.
* It can then be displayed with geomview.
* A similar, but somewhat older solution is to use 'powercrust' with e.g.
*   powercrust -i points.xyz
* which will generate a 'pc.off' file to be renamed as suited.
*
*******************************************************************************/

#ifndef INTEROFF_LIB_H
#include "interoff-lib.h"
#endif

#ifndef INTEROFF_LIB_C
#define INTEROFF_LIB_C "$Revision$"

#ifdef OPENACC // If on GPU map fprintf to printf
#define fprintf(stderr,...) printf(__VA_ARGS__)
#endif

#pragma acc routine
double off_F(double x, double y,double z,double A,double B,double C,double D) {
  return ( A*x + B*y + C*z + D );
}

#pragma acc routine
char off_sign(double a) {
  if (a<0)       return(-1);
  else if (a==0) return(0);
  else           return(1);
}

// off_normal ******************************************************************
//gives the normal vector of p
#pragma acc routine
void off_normal(Coords* n, polygon p)
{
  //using Newell method
  int i=0,j=0;
  n->x=0;n->y=0;n->z=0;
  for (i = 0, j = p.npol-1; i < p.npol; j = i++)
  {
    MCNUM x1=p.p[3*i],
          y1=p.p[3*i+1],
          z1=p.p[3*i+2];
    MCNUM x2=p.p[3*j],
          y2=p.p[3*j+1],
          z2=p.p[3*j+2];
    // n is the cross product of v1*v2
    n->x += (y1 - y2) * (z1 + z2);
    n->y += (z1 - z2) * (x1 + x2);
    n->z += (x1 - x2) * (y1 + y2);
  }
} /* off_normal */

// off_pnpoly ******************************************************************
//based on http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html
//return 0 if the vertex is out
//    1 if it is in
//   -1 if on the boundary
#pragma acc routine
int off_pnpoly(polygon p, Coords v)
{
  int i=0, c = 0;
  MCNUM minx=FLT_MAX,maxx=-FLT_MAX,miny=FLT_MAX,maxy=-FLT_MAX,minz=FLT_MAX,maxz=-FLT_MAX;
  MCNUM areax=0,areay=0,areaz=0;

  int pol2dx=0,pol2dy=1;          //2d restriction of the poly
  MCNUM x=v.x,y=v.y;

  /*areax: projected area with x-scratched = |v1_yz x v2_yz|, where v1=(x1-x0,0,z1-z0) & v2=(x2-x0,0,z2-z0).*/
  /* In principle, if polygon is triangle area should be scaled by 1/2, but this is irrelevant for finding the maximum area.*/
  /* Similarly for y and z scratched.*/
  areax=coords_len(coords_xp(
        coords_set(0,p.p[3*1+1]-p.p[0+1],p.p[3*1+2]-p.p[0+2]),
        coords_set(0,p.p[3*2+1]-p.p[0+1],p.p[3*2+2]-p.p[0+2])));
  areay=coords_len(coords_xp(
        coords_set(p.p[3*1+0]-p.p[0+0],0,p.p[3*1+2]-p.p[0+2]),
        coords_set(p.p[3*2+0]-p.p[0+0],0,p.p[3*2+2]-p.p[0+2])));
  areaz=coords_len(coords_xp(
        coords_set(p.p[3*1+0]-p.p[0+0],p.p[3*1+1]-p.p[0+1],0),
        coords_set(p.p[3*2+0]-p.p[0+0],p.p[3*2+1]-p.p[0+1],0)));

  if(areaz<areax){
    if(areax<areay){
      /*pick areay - i.e. scratch y*/
      pol2dy=2;
      y=v.z;
    }else{
      /*scratch x*/
      pol2dx=2;
      x=v.z;
    }
  }else if (areaz<areay){
    pol2dy=2;
    y=v.z;
  }

  //trace rays and test number of intersection
  int j;
  for (i = 0, j = p.npol-1; i < p.npol; j = i++) {
    if (((((p.p[3*i+pol2dy])<=y) && (y<(p.p[3*j+pol2dy]))) ||
         (((p.p[3*j+pol2dy])<=y) && (y<(p.p[3*i+pol2dy])))) &&
        (x < ( (p.p[3*j+pol2dx] - p.p[3*i+pol2dx]) * (y - p.p[3*i+pol2dy])
             / (p.p[3*j+pol2dy] - p.p[3*i+pol2dy]) + p.p[3*i+pol2dx]) ))
      c = !c;

    if (((fabs(p.p[3*i+pol2dy]-y)<=OFF_EPSILON) || ((fabs(p.p[3*j+pol2dy]-y)<=OFF_EPSILON))) &&
        fabs(x -((p.p[3*j+pol2dx] - p.p[3*i+pol2dx]) * (y - p.p[3*i+pol2dy])
          / (p.p[3*j+pol2dy] - p.p[3*i+pol2dy]) + p.p[3*i+pol2dx])) < OFF_EPSILON)
    {
      //the point lies on the edge
      c=-1;
      break;
    }
  }

  return c;
} /* off_pnpoly */

// off_intersectPoly ***********************************************************
//gives the intersection vertex between ray [a,b) and polygon p and its parametric value on (a b)
//based on http://geometryalgorithms.com/Archive/algorithm_0105/algorithm_0105.htm
#pragma acc routine
int off_intersectPoly(intersection *inter, Coords a, Coords b, polygon p)
{
  //direction vector of [a,b]
  Coords dir = {b.x-a.x, b.y-a.y, b.z-a.z};

  //the normal vector to the polygon
  Coords normale=p.normal;
  //off_normal(&normale, p); done at the init stage

  //direction vector from a to a vertex of the polygon
  Coords w0 = {a.x-p.p[0], a.y-p.p[1], a.z-p.p[2]};

  //scalar product
  MCNUM nw0  =-scalar_prod(normale.x,normale.y,normale.z,w0.x,w0.y,w0.z);
  MCNUM ndir = scalar_prod(normale.x,normale.y,normale.z,dir.x,dir.y,dir.z);
  inter->time = inter->edge = inter->in_out=0;
  inter->v = inter->normal = coords_set(0,0,1);

  if (fabs(ndir) < OFF_EPSILON)    // ray is parallel to polygon plane
  {
    if (nw0 == 0)              // ray lies in polygon plane (infinite number of solution)
      return 0;
    else return 0;             // ray disjoint from plane (no solution)
  }

  // get intersect point of ray with polygon plane
  inter->time = nw0 / ndir;            //parametric value the point on line (a,b)

  inter->v = coords_set(a.x + inter->time * dir.x,// intersect point of ray and plane
    a.y + inter->time * dir.y,
    a.z + inter->time * dir.z);

  int res=off_pnpoly(p,inter->v);

  inter->edge=(res==-1);
  if (ndir<0)
    inter->in_out=1;  //the negative dot product means we enter the surface
  else
    inter->in_out=-1;

  inter->normal=p.normal;

  return res;         //true if the intersection point lies inside the poly
} /* off_intersectPoly */


// off_getBlocksIndex **********************************************************
/*reads the indexes at the beginning of the off file as this :
line 1  OFF
line 2  nbVertex nbFaces nbEdges
*/
FILE *off_getBlocksIndex(char* filename, long* vtxSize, long* polySize )
{
  FILE* f = Open_File(filename,"r", NULL); /* from read_table-lib: FILE *Open_File(char *name, char *Mode, char *path) */
  if (!f) return (f);

  char line[CHAR_BUF_LENGTH];
  char *ret=0;
  *vtxSize = *polySize = 0;

  /* **************** start to read the file header */
  /* OFF file:
     'OFF' or '3'
   */

  ret=fgets(line,CHAR_BUF_LENGTH , f);// line 1 = "OFF"
  if (ret == NULL)
  {
    fprintf(stderr, "Error: Can not read 1st line in file %s (interoff/off_getBlocksIndex)\n", filename);
    exit(1);
  }
  if (strlen(line)>5)
  {
      fprintf(stderr,"Error: First line in %s is too long (=%lu). Possibly the line is not terminated by '\\n'.\n"
              "       The first line is required to be exactly 'OFF', '3' or 'ply'.\n",
              filename,(long unsigned)strlen(line));
      fclose(f);
      return(NULL);
  }

  if (strncmp(line,"OFF",3) && strncmp(line,"3",1) && strncmp(line,"ply",1))
  {
    fprintf(stderr, "Error: %s is probably not an OFF, NOFF or PLY file (interoff/off_getBlocksIndex).\n"
                    "       Requires first line to be 'OFF', '3' or 'ply'.\n",filename);
    fclose(f);
    return(NULL);
  }

  if (!strncmp(line,"OFF",3) || !strncmp(line,"3",1)) {
    do  /* OFF file: skip # comments which may be there */
    {
      ret=fgets(line,CHAR_BUF_LENGTH , f);
      if (ret == NULL)
      {
        fprintf(stderr, "Error: Can not read line in file %s (interoff/off_getBlocksIndex)\n", filename);
        exit(1);
      }
    } while (line[0]=='#');
    //line = nblines of vertex,faces and edges arrays
    sscanf(line,"%lu %lu",vtxSize,polySize);
  } else {
    do  /* PLY file: read all lines until find 'end_header'
           and locate 'element faces' and 'element vertex' */
    {
      ret=fgets(line,CHAR_BUF_LENGTH , f);
      if (ret == NULL)
      {
        fprintf(stderr, "Error: Can not read line in file %s (interoff/off_getBlocksIndex)\n", filename);
        exit(1);
      }
      if (!strncmp(line,"element face",12))
        sscanf(line,"element face %lu",polySize);
      else if (!strncmp(line,"element vertex",14))
        sscanf(line,"element vertex %lu",vtxSize);
      else if (!strncmp(line,"format binary",13))
        exit(fprintf(stderr,
          "Error: Can not read binary PLY file %s, only 'format ascii' (interoff/off_getBlocksIndex)\n%s\n",
          filename, line));
    } while (strncmp(line,"end_header",10));
  }

  /* The FILE is left opened ready to read 'vtxSize' vertices (vtxSize *3 numbers)
     and then polySize polygons (rows) */

  return(f);
} /* off_getBlocksIndex */

// off_init_planes *************************************************************
//gives the equations of 2 perpandicular planes of [ab]
#pragma acc routine
void off_init_planes(Coords a, Coords b,
  MCNUM* A1, MCNUM* C1, MCNUM* D1, MCNUM *A2, MCNUM* B2, MCNUM* C2, MCNUM* D2)
{
  //direction vector of [a b]
  Coords dir={b.x-a.x, b.y-a.y, b.z-a.z};

  //the plane parallel to the 'y' is computed with the normal vector of the projection of [ab] on plane 'xz'
  *A1= dir.z;
  *C1=-dir.x;
  if(*A1!=0 || *C1!=0)
    *D1=-(a.x)*(*A1)-(a.z)*(*C1);
  else
  {
    //the plane does not support the vector, take the one parallel to 'z''
    *A1=1;
    //B1=dir.x=0
    *D1=-(a.x);
  }
  //the plane parallel to the 'x' is computed with the normal vector of the projection of [ab] on plane 'yz'
  *B2= dir.z;
  *C2=-dir.y;
  *A2= 0;
  if (*B2==0 && *C2==0)
  {
    //the plane does not support the vector, take the one parallel to 'z'
    *B2=1;
    //B1=dir.x=0
    *D2=-(a.y);
  }
  else {
    if (dir.z==0)
    {
      //the planes are the same, take the one parallel to 'z'
      *A2= dir.y;
      *B2=-dir.x;
      *D2=-(a.x)*(*A2)-(a.y)*(*B2);
    }
    else
      *D2=-(a.y)**B2-(a.z)**C2;
  }
} /* off_init_planes */

// off_clip_3D_mod *************************************************************
#pragma acc routine
int off_clip_3D_mod(intersection* t, Coords a, Coords b,
  Coords* vtxArray, unsigned long vtxSize, unsigned long* faceArray,
  unsigned long faceSize, Coords* normalArray)
{
  MCNUM A1=0, C1=0, D1=0, A2=0, B2=0, C2=0, D2=0;      //perpendicular plane equations to [a,b]
  off_init_planes(a, b, &A1, &C1, &D1, &A2, &B2, &C2, &D2);

  int t_size=0;
  MCNUM popol[3*4]; /*3 dimensions and max 4 vertices to form a polygon*/
  unsigned long i=0,indPoly=0;

  //exploring the polygons :
  i=indPoly=0;
  while (i<faceSize)
  {
    polygon pol;
    pol.npol  = faceArray[i];                //nb vertex of polygon
    pol.p     = popol;
    pol.normal= coords_set(0,0,1);
    pol.D     = 1;
    unsigned long indVertP1=faceArray[++i];  //polygon's first vertex index in vtxTable
    int j=1;
    /*check whether vertex is left or right of plane*/
    char sg0=off_sign(off_F(vtxArray[indVertP1].x,vtxArray[indVertP1].y,vtxArray[indVertP1].z,A1,0,C1,D1));
    while (j<pol.npol)
    {
      //polygon's j-th vertex index in vtxTable
      unsigned long indVertP2=faceArray[i+j];
      /*check whether vertex is left or right of plane*/
      char sg1=off_sign(off_F(vtxArray[indVertP2].x,vtxArray[indVertP2].y,vtxArray[indVertP2].z,A1,0,C1,D1));
      if (sg0!=sg1) //if the plane intersect the polygon
        break;

      ++j;
    }

    if (j<pol.npol)          //ok, let's test with the second plane
    {
      char sg1=off_sign(off_F(vtxArray[indVertP1].x,vtxArray[indVertP1].y,vtxArray[indVertP1].z,A2,B2,C2,D2));//tells if vertex is left or right of the plane

      j=1;
      while (j<pol.npol)
      {
        //unsigned long indVertPi=faceArray[i+j];  //polyg's j-th vertex index in vtxTable
        Coords vertPi=vtxArray[faceArray[i+j]];
        if (sg1!=off_sign(off_F(vertPi.x,vertPi.y,vertPi.z,A2,B2,C2,D2)))//if the plane intersect the polygon
          break;
        ++j;
      }
      if (j<pol.npol)
      {
#ifdef OFF_LEGACY
        if (t_size>OFF_INTERSECT_MAX)
        {
          fprintf(stderr, "Warning: number of intersection exceeded (%d) (interoff-lib/off_clip_3D_mod)\n", OFF_INTERSECT_MAX);
            return (t_size);
        }
#endif
        //both planes intersect the polygon, let's find the intersection point
        //our polygon :
        int k;
        for (k=0; k<pol.npol; ++k)
        {
          Coords vertPk=vtxArray[faceArray[i+k]];
          pol.p[3*k]  =vertPk.x;
          pol.p[3*k+1]=vertPk.y;
          pol.p[3*k+2]=vertPk.z;
        }
        pol.normal=normalArray[indPoly];
        intersection x;
        if (off_intersectPoly(&x, a, b, pol))
        {
          x.index = indPoly;
#ifdef OFF_LEGACY
          t[t_size++]=x;
#else
	  /* Check against our 4 existing times, starting from [-FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX] */
	  /* Case 1, negative time? */
	  if (t_size < 4) t_size++;	  
	  if (x.time < 0) {
	    if (x.time > t[0].time) {
	      t[0]=x;
	    }
	  } else {
	    /* Case 2, positive time */
	    intersection xtmp;
	    if (x.time < t[3].time) {
	      t[3]=x;
	      if (t[3].time < t[2].time) {
		xtmp = t[2];
		t[2] = t[3];
		t[3] = xtmp;
	      }
	      if (t[2].time < t[1].time) {
		xtmp = t[1];
		t[1] = t[2];
		t[2] = xtmp;
	      }
	    } 
	  }
#endif
	}
      } /* if (j<pol.npol) */
    } /* if (j<pol.npol) */
    i += pol.npol;
    indPoly++;
  } /* while i<faceSize */
  return t_size;
} /* off_clip_3D_mod */

// off_clip_3D_mod_grav *************************************************************
/*******************************************************************************
version of off_clip_3D_mod_grav
*******************************************************************************/
#pragma acc routine seq
int off_clip_3D_mod_grav(intersection* t, Coords pos, Coords vel, Coords acc,
  Coords* vtxArray, unsigned long vtxSize, unsigned long* faceArray,
  unsigned long faceSize, Coords* normalArray, double* DArray)
{
  int t_size=0;
  MCNUM popol[3*CHAR_BUF_LENGTH];
  double plane_Eq [4];
  double quadratic [3];
  unsigned long i=0,indPoly=0;
  //exploring the polygons :
  i=indPoly=0;
  while (i<faceSize)
  {
    polygon pol;
    pol.npol  = faceArray[i];                //nb vertex of polygon
    pol.p     = popol;
    pol.normal= coords_set(0,0,1);
    unsigned long indVertP1=faceArray[++i];  //polygon's first vertex index in vtxTable
    
    if (t_size>CHAR_BUF_LENGTH)
      {
	fprintf(stderr, "Warning: number of intersection exceeded (%d) (interoff-lib/off_clip_3D_mod)\n", CHAR_BUF_LENGTH);
	return (t_size);
      }
    //both planes intersect the polygon, let's find the intersection point
    //our polygon :
    int k;
    for (k=0; k<pol.npol; ++k)
      {
	Coords vertPk=vtxArray[faceArray[i+k]];
	pol.p[3*k]  =vertPk.x;
	pol.p[3*k+1]=vertPk.y;
	pol.p[3*k+2]=vertPk.z;
      }
    pol.normal=normalArray[indPoly];
    pol.D=DArray[indPoly];
    p_to_quadratic(pol.normal, pol.D, acc, pos, vel, quadratic);
    double x1, x2;
    int nsol = quadraticSolve(quadratic, &x1, &x2);

    if (nsol >= 1) {
      double time = 1.0e36;
      if (x1 < time && x1 > 0.0) {
	time = x1;
      }
      if (nsol == 2 && x2 < time && x2 > 0.0) {
	time = x2;
      }
      if (time != 1.0e36) {
	intersection inters;
	double t2 = time * time * 0.5;
	double tx = pos.x + time * vel.x;
	if (acc.x != 0.0) {
	  tx = tx + t2 * acc.x;
	}
	double ty = pos.y + time * vel.y;
	if (acc.y != 0.0) {
	  ty = ty + t2 * acc.y;
	}
	double tz = pos.z + time * vel.z;
	if (acc.z != 0.0) {
	  tz = tz + t2 * acc.z;
	}
	inters.v = coords_set(tx, ty, tz);
	Coords tvel = coords_set(vel.x + time * acc.x,
				 vel.y + time * acc.y,
				 vel.z + time * acc.z);
	inters.time = time;
	inters.normal = pol.normal;
	inters.index = indPoly;
	int res=off_pnpoly(pol,inters.v);
	if (res != 0) {
	  inters.edge=(res==-1);
	  MCNUM ndir = scalar_prod(pol.normal.x,pol.normal.y,pol.normal.z,tvel.x,tvel.y,tvel.z);
	  if (ndir<0) {
	    inters.in_out=1;  //the negative dot product means we enter the surface
	  } else {
	    inters.in_out=-1;
	  }
#ifdef OFF_LEGACY
          t[t_size++]=inters;
#else
    /* Check against our 4 existing times, starting from [-FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX] */
    /* Case 1, negative time? */
    if (t_size < 4) t_size++;
    if (inters.time < 0) {
      if (inters.time > t[0].time) {
        t[0]=inters;
      }
    } else {
      /* Case 2, positive time */
      intersection xtmp;
      if (inters.time < t[3].time) {
      t[3]=inters;
        if (t[3].time < t[2].time) {
    xtmp = t[2];
    t[2] = t[3];
    t[3] = xtmp;
        }
        if (t[2].time < t[1].time) {
    xtmp = t[1];
    t[1] = t[2];
    t[2] = xtmp;
        }
      }
    }
#endif
	}
      }
    }
    i += pol.npol;
    indPoly++;
  } /* while i<faceSize */
  return t_size;
} /* off_clip_3D_mod_grav */

// off_compare *****************************************************************
#pragma acc routine
int off_compare (void const *a, void const *b)
{
   intersection const *pa = a;
   intersection const *pb = b;

   return off_sign(pa->time - pb->time);
} /* off_compare */

// off_cleanDouble *************************************************************
//given an array of intersections throw those which appear several times
//returns 1 if there is a possibility of error
#pragma acc routine
int off_cleanDouble(intersection* t, int* t_size)
{
  int i=1;
  intersection prev=t[0];
  while (i<*t_size)
  {
    int j=i;
    //for each intersection with the same time
    while (j<*t_size && fabs(prev.time-t[j].time)<OFF_EPSILON)
    {
      //if the intersection is the exact same erase it
      if (prev.in_out==t[j].in_out)
      {
        int k;
        for (k=j+1; k<*t_size; ++k)
        {
          t[k-1]=t[k];
        }
        *t_size-=1;
      }
      else
        ++j;
    }
    prev=t[i];
    ++i;

  }
  return 1;
} /* off_cleanDouble */

// off_cleanInOut **************************************************************
//given an array of intesections throw those which enter and exit in the same time
//Meaning the ray passes very close to the volume
//returns 1 if there is a possibility of error
#pragma acc routine
int off_cleanInOut(intersection* t, int* t_size)
{
  int i=1;
  intersection prev=t[0];
  while (i<*t_size)
  {
    //if two intersection have the same time but one enters and the other exits erase both
    //(such intersections must be adjacent in the array : run off_cleanDouble before)
    if (fabs(prev.time-t[i].time)<OFF_EPSILON && prev.in_out!=t[i].in_out)
    {
      int j=0;
      for (j=i+1; j<*t_size; ++j)
      {
        t[j-2]=t[j];
      }
      *t_size-=2;
      prev=t[i-1];
    }
    else
    {
      prev=t[i];
      ++i;
    }
  }
  return (*t_size);
} /* off_cleanInOut */

/* PUBLIC functions ******************************************************** */

/*******************************************************************************
* long off_init(  char *offfile, double xwidth, double yheight, double zdepth, off_struct* data)
* ACTION: read an OFF file, optionally center object and rescale, initialize OFF data structure
* INPUT: 'offfile' OFF file to read
*        'xwidth,yheight,zdepth' if given as non-zero, apply bounding box.
*           Specifying only one of these will also use the same ratio on all axes
*        'notcenter' center the object to the (0,0,0) position in local frame when set to zero
* RETURN: number of polyhedra and 'data' OFF structure
*******************************************************************************/
long off_init(  char *offfile, double xwidth, double yheight, double zdepth,
                int notcenter, off_struct* data)
{
  // data to be initialized
  long    vtxSize =0, polySize=0, i=0, ret=0, faceSize=0;
  Coords* vtxArray        =NULL;
  Coords* normalArray     =NULL;
  double* DArray          =NULL;
  unsigned long* faceArray=NULL;
  FILE*   f               =NULL; /* the FILE with vertices and polygons */
  double minx=FLT_MAX,maxx=-FLT_MAX,miny=FLT_MAX,maxy=-FLT_MAX,minz=FLT_MAX,maxz=-FLT_MAX;

  // get the indexes
  if (!data) return(0);

  MPI_MASTER(
  printf("Loading geometry file (OFF/PLY): %s\n", offfile);
  );

  f=off_getBlocksIndex(offfile,&vtxSize,&polySize);
  if (!f) return(0);

  // read vertex table = [x y z | x y z | ...] =================================
  // now we read the vertices as 'vtxSize*3' numbers and store it in vtxArray
  MPI_MASTER(
  printf("  Number of vertices: %ld\n", vtxSize);
  );
  vtxArray   = malloc(vtxSize*sizeof(Coords));
  if (!vtxArray) return(0);
  i=0;
  while (i<vtxSize && ~feof(f))
  {
    double x,y,z;
    ret=fscanf(f, "%lg%lg%lg", &x,&y,&z);
    if (!ret) {
      // invalid line: we skip it (probably a comment)
      char line[CHAR_BUF_LENGTH];
      char *s=fgets(line, CHAR_BUF_LENGTH, f);
      continue;
    }
    if (ret != 3) {
      fprintf(stderr, "Error: can not read [xyz] coordinates for vertex %li in file %s (interoff/off_init). Read %li values.\n",
        i, offfile, ret);
      exit(2);
    }
    vtxArray[i].x=x;
    vtxArray[i].y=y;
    vtxArray[i].z=z;

    //bounding box
    if (vtxArray[i].x<minx) minx=vtxArray[i].x;
    if (vtxArray[i].x>maxx) maxx=vtxArray[i].x;
    if (vtxArray[i].y<miny) miny=vtxArray[i].y;
    if (vtxArray[i].y>maxy) maxy=vtxArray[i].y;
    if (vtxArray[i].z<minz) minz=vtxArray[i].z;
    if (vtxArray[i].z>maxz) maxz=vtxArray[i].z;
    i++; // inquire next vertex
  }

  // resizing and repositioning params
  double centerx=0, centery=0, centerz=0;
  if (!notcenter) {
    centerx=(minx+maxx)*0.5;
    centery=(miny+maxy)*0.5;
    centerz=(minz+maxz)*0.5;
  }

  double rangex=-minx+maxx,
         rangey=-miny+maxy,
         rangez=-minz+maxz;

  double ratiox=1,ratioy=1,ratioz=1;

  if (xwidth && rangex)
  {
    ratiox=xwidth/rangex;
    ratioy=ratiox;
    ratioz=ratiox;
  }

  if (yheight && rangey)
  {
    ratioy=yheight/rangey;
    if(!xwidth)  ratiox=ratioy;
    ratioz=ratioy;
  }

  if (zdepth && rangez)
  {
    ratioz=zdepth/rangez;
    if(!xwidth)  ratiox=ratioz;
    if(!yheight) ratioy=ratioz;
  }

  rangex *= ratiox;
  rangey *= ratioy;
  rangez *= ratioz;

  //center and resize the object
  for (i=0; i<vtxSize; ++i)
  {
    vtxArray[i].x=(vtxArray[i].x-centerx)*ratiox+(!notcenter ? 0 : centerx);
    vtxArray[i].y=(vtxArray[i].y-centery)*ratioy+(!notcenter ? 0 : centery);
    vtxArray[i].z=(vtxArray[i].z-centerz)*ratioz+(!notcenter ? 0 : centerz);
  }

  // read face table = [nbvertex v1 v2 vn | nbvertex v1 v2 vn ...] =============
  MPI_MASTER(
  printf("  Number of polygons: %ld\n", polySize);
  );
  normalArray= malloc(polySize*sizeof(Coords));
  faceArray  = malloc(polySize*10*sizeof(unsigned long)); // we assume polygons have less than 9 vertices
  DArray     = malloc(polySize*sizeof(double));
  if (!normalArray || !faceArray || !DArray) return(0);

  // fill faces
  faceSize=0;
  i=0;
  while (i<polySize && ~feof(f)) {
    int  nbVertex=0, j=0;
    // read the length of this polygon
    ret=fscanf(f, "%d", &nbVertex);
    if (!ret) {
      // invalid line: we skip it (probably a comment)
      char line[CHAR_BUF_LENGTH];
      char *s=fgets(line, CHAR_BUF_LENGTH, f);
      continue;
    }
    if (ret != 1) {
      fprintf(stderr, "Error: can not read polygon %li length in file %s (interoff/off_init)\n",
        i, offfile);
      exit(3);
    }
    if (faceSize > polySize*10) {
      fprintf(stderr, "Error: %li exceeded allocated polygon array[%li] in file %s (interoff/off_init)\n",
        faceSize, polySize*10, offfile);
    }
    faceArray[faceSize++] = nbVertex; // length of the polygon/face
    // then read the vertex ID's
    for (j=0; j<nbVertex; j++) {
      double vtx=0;
      ret=fscanf(f, "%lg", &vtx);
      faceArray[faceSize++] = vtx;   // add vertices index after length of polygon
    }
    i++;
  }

  // precomputes normals
  long indNormal=0;//index in polyArray
  i=0;    //index in faceArray
  while (i<faceSize)
  {
    int    nbVertex=faceArray[i];//nb of vertices of this polygon
    double *vertices=malloc(3*nbVertex*sizeof(double));
    if (!vertices) {
      fprintf(stderr,"Error allocating vertex array sized %i\n",nbVertex);
      exit(-1);
    }
    int j;

    for (j=0; j<nbVertex; ++j)
    {
      unsigned long indVertPj=faceArray[i+j+1];
      vertices[3*j]  =vtxArray[indVertPj].x;
      vertices[3*j+1]=vtxArray[indVertPj].y;
      vertices[3*j+2]=vtxArray[indVertPj].z;
    }

    polygon p;
    p.p   =vertices;
    p.npol=nbVertex;
    p.D=1;
    off_normal(&(p.normal),p);

    normalArray[indNormal]=p.normal;
    p.D = scalar_prod(p.normal.x,p.normal.y,p.normal.z,
		      vertices[0],vertices[1],vertices[2]);
    DArray[indNormal]=p.D;

    i += nbVertex+1;
    indNormal++;
    free(vertices);
  }

  MPI_MASTER(
  if (ratiox!=ratioy || ratiox!=ratioz || ratioy!=ratioz)
    printf("Warning: Aspect ratio of the geometry %s was modified.\n"
           "         If you want to keep the original proportions, specifiy only one of the dimensions.\n",
           offfile);
  if ( xwidth==0 && yheight==0 && zdepth==0 ) {
    printf("Warning: Neither xwidth, yheight or zdepth are defined.\n"
	   "           The file-defined (non-scaled) geometry the OFF geometry %s will be applied!\n",
           offfile);
  }
  printf("  Bounding box dimensions for geometry %s:\n", offfile);
  printf("    Length=%f (%.3f%%)\n", rangex, ratiox*100);
  printf("    Width= %f (%.3f%%)\n", rangey, ratioy*100);
  printf("    Depth= %f (%.3f%%)\n", rangez, ratioz*100);
  );

  data->vtxArray   = vtxArray;
  data->normalArray= normalArray;
  data->DArray     = DArray;
  data->faceArray  = faceArray;
  data->vtxSize    = vtxSize;
  data->polySize   = polySize;
  data->faceSize   = faceSize;
  data->filename   = offfile;
  #ifdef OPENACC
  acc_attach((void *)&vtxArray);
  acc_attach((void *)&normalArray);
  acc_attach((void *)&faceArray);
  #endif

  return(polySize);
} /* off_init */

#pragma acc routine
int Min_int(int x, int y) {
  return (x<y)? x :y;
}

 
#pragma acc routine
void merge(intersection *arr, int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 =  r - m;

/* create temp arrays */
intersection *L, *R;
 L = (intersection *)malloc(sizeof(intersection) * n1);
 R = (intersection *)malloc(sizeof(intersection) * n2);
 if (!L||!R) {
   fprintf(stderr,"Error allocating intersection arrays\n");
   exit(-1);
 }
/* Copy data to temp arrays L[] and R[] */
 #pragma acc loop independent
for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
 #pragma acc loop independent
for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];

/* Merge the temp arrays back into arr[l..r]*/
i = 0;
j = 0;
k = l;

while (i < n1 && j < n2)
{
    if (L[i].time <= R[j].time)
    {
        arr[k] = L[i];
        i++;
    }
    else
    {
        arr[k] = R[j];
        j++;
    }
    k++;
}

/* Copy the remaining elements of L[], if there are any */

while (i < n1)
{
    arr[k] = L[i];
    i++;
    k++;
}

/* Copy the remaining elements of R[], if there are any */
while (j < n2)
{
    arr[k] = R[j];
    j++;
    k++;
}
free(L);
free(R);
}


#ifdef USE_OFF
#pragma acc routine
void gpusort(intersection *arr, int size)
{
  int curr_size;  // For current size of subarrays to be merged
  // curr_size varies from 1 to n/2
  int left_start; // For picking starting index of left subarray
  // to be merged
  // pcopying (R[0:n2])
  {
    for (curr_size=1; curr_size<=size-1; curr_size = 2*curr_size)
      {
	// Pick starting point of different subarrays of current size
	for (left_start=0; left_start<size-1; left_start += 2*curr_size)
	  {
	    // Find ending point of left subarray. mid+1 is starting
	    // point of right
	    int mid = left_start + curr_size - 1;

	    int right_end = Min_int(left_start + 2*curr_size - 1, size-1);

	    // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
	    if (mid < right_end) merge(arr, left_start, mid, right_end);
	  }
      }
  }
}
#endif

/*******************************************************************************
void p_to_quadratic(double eq[], Coords acc,
                    Coords pos, Coords vel,
                    double* teq)
* ACTION: define the quadratic for the intersection of a parabola with a plane
* INPUT: 'eq' plane equation
*        'acc' acceleration vector
*        'vel' velocity of the particle
*        'pos' position of the particle
*         equation of plane A * x + B * y + C * z - D = 0
*         eq[0] = (C*az)/2+(B*ay)/2+(A*ax)/2
*         eq[1] = C*vz+B*vy+A*vx
*         eq[2] = C*z0+B*y0+A*x0-D
* RETURN: equation of parabola: teq(0) * t^2 + teq(1) * t + teq(2)
*******************************************************************************/
void p_to_quadratic(Coords norm, MCNUM d, Coords acc, Coords pos, Coords vel,
		    double* teq)
{
  teq[0] = scalar_prod(norm.x, norm.y, norm.z, acc.x, acc.y, acc.z) * 0.5;
  teq[1] = scalar_prod(norm.x, norm.y, norm.z, vel.x, vel.y, vel.z);
  teq[2] = scalar_prod(norm.x, norm.y, norm.z, pos.x, pos.y, pos.z) - d;
  return;
}

/*******************************************************************************
int quadraticSolve(double eq[], double* x1, double* x2);
* ACTION: solves the quadratic for the roots x1 and x2 
*         eq[0] * t^2 + eq[1] * t + eq[2] = 0
* INPUT: 'eq' the coefficients of the parabola
* RETURN: roots x1 and x2 and the number of solutions
*******************************************************************************/
int quadraticSolve(double* eq, double* x1, double* x2)
{
  if (eq[0] == 0.0) { // This is a linear equation
    if (eq[1] != 0.0) { // one solution
      *x1 = -eq[2]/eq[1];
      *x2 = 1.0e36;
      return 1;
    }else { // no solutions, 1.0e36 will be ignored.
      *x1 = 1.0e36;
      *x2 = 1.0e36;
      return 0;
    }
  }
  double delta = eq[1]*eq[1]-4.0*eq[0]*eq[2];
  if (delta < 0.0) { // no solutions, both are imaginary
    *x1 = 1.0e36;
    *x2 = 1.0e36;
    return 0;
  }
  double s = 1.0;
  if (eq[1] < 0) {
    s = -1.0;
  }
  *x1 = (-eq[1] - s * sqrt(delta))/(2.0*eq[0]);
  if (eq[0] != 0.0) { //two solutions
    *x2 = eq[2]/(eq[0]*(*x1));
    return 2;
  } else { //one solution
    *x2 = 1.0e36;
    return 1;
  }
}

/*******************************************************************************
* int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*         data is the full OFF structure, including a list intersection type
*******************************************************************************/
int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
{

    int t_size = 0;
#ifdef OFF_LEGACY

    if(mcgravitation) {
      Coords pos={ x,  y,  z};
      Coords vel={vx, vy, vz};
      Coords acc={ax, ay, az};
      t_size=off_clip_3D_mod_grav(data->intersects, pos, vel, acc,
				  data->vtxArray, data->vtxSize, data->faceArray,
				  data->faceSize, data->normalArray, data->DArray );
    } else {
    ///////////////////////////////////
    // non-grav
      Coords A={x, y, z};
      Coords B={x+vx, y+vy, z+vz};
      t_size=off_clip_3D_mod(data->intersects, A, B,
			     data->vtxArray, data->vtxSize, data->faceArray,
			     data->faceSize, data->normalArray );
    }
    #ifndef OPENACC
    qsort(data->intersects, t_size, sizeof(intersection),  off_compare);
    #else
    #ifdef USE_OFF
    gpusort(data->intersects, t_size);
    #endif
    #endif
    off_cleanDouble(data->intersects, &t_size);
    off_cleanInOut(data->intersects,  &t_size);

    /*find intersections "closest" to 0 (favouring positive ones)*/
    if(t_size>0){
      int i=0;
      if(t_size>1) {
        for (i=1; i < t_size-1; i++){
          if (data->intersects[i-1].time > 0 && data->intersects[i].time > 0)
            break;
        }

	data->nextintersect=i-1;
	data->numintersect=t_size;

        if (t0) *t0 = data->intersects[i-1].time;
        if (n0) *n0 = data->intersects[i-1].normal;
        if (t3) *t3 = data->intersects[i].time;
        if (n3) *n3 = data->intersects[i].normal;
      } else {
        if (t0) *t0 = data->intersects[0].time;
	      if (n0) *n0 = data->intersects[0].normal;
      }
      /* should also return t[0].index and t[i].index as polygon ID */
      data->nextintersect=(data->intersects[data->nextintersect]).index;
      return t_size;
    }
#else
    intersection intersect4[4];
    intersect4[0].time=-FLT_MAX;
    intersect4[1].time=FLT_MAX;
    intersect4[2].time=FLT_MAX;
    intersect4[3].time=FLT_MAX;
    if(mcgravitation) {
      Coords pos={ x,  y,  z};
      Coords vel={vx, vy, vz};
      Coords acc={ax, ay, az};
      t_size=off_clip_3D_mod_grav(intersect4, pos, vel, acc,
				  data->vtxArray, data->vtxSize, data->faceArray,
				  data->faceSize, data->normalArray, data->DArray);
    } else {
    ///////////////////////////////////
    // non-grav
      Coords A={x, y, z};
      Coords B={x+vx, y+vy, z+vz};
      t_size=off_clip_3D_mod(intersect4, A, B,
	  data->vtxArray, data->vtxSize, data->faceArray, data->faceSize, data->normalArray );
    }
    if(t_size>0){
      int i=0;
      if (intersect4[0].time == -FLT_MAX) i=1;
      data->numintersect=t_size;
      if (t0) *t0 = intersect4[i].time;
      if (n0) *n0 = intersect4[i].normal;
      if (t3) *t3 = intersect4[i+1].time;
      if (n3) *n3 = intersect4[i+1].normal;

      if (intersect4[1].time == FLT_MAX)
      {
        if (t3) *t3 = 0.0;
      }

      /* should also return t[0].index and t[i].index as polygon ID */
      data->nextintersect=(int)intersect4[i].index;
      return t_size;
    }
#endif
    return 0;
} /* off_intersect */

/*******************************************************************************
* int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     off_struct data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data )
{
  return off_intersect_all(t0, t3, n0, n3, x, y, z, vx, vy, vz, ax, ay, az, &data );
} /* off_intersect */

/*****************************************************************************
* int off_x_intersect(double* l0, double* l3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double kx, double ky, double kz,
     off_struct data )
* ACTION: computes intersection of an xray trajectory with an object.
* INPUT:  x,y,z and kx,ky,kz, are spatial coordinates and wavevector of the x-ray
*         respectively. data points to the OFF data structure.
* RETURN: the number of polyhedral the trajectory intersects
*         l0 and l3 are the smallest incoming and outgoing intersection lengths
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
int off_x_intersect(double *l0,double *l3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double kx, double ky, double kz,
     off_struct data )
{
  /*This function simply reformats and calls off_intersect (as for neutrons)
   *by normalizing the wavevector - this will yield the intersection lengths
   *in m*/
  double jx,jy,jz,invk;
  int n;
  invk=1/sqrt(scalar_prod(kx,ky,kz,kx,ky,kz));
  jx=kx*invk;jy=ky*invk;jz=kz*invk;
  n=off_intersect(l0,l3,n0,n3,x,y,z,jx,jy,jz,0.0,0.0,0.0,data);
  return n;
}


/*******************************************************************************
* void off_display(off_struct data)
* ACTION: display up to N_VERTEX_DISPLAYED polygons from the object
*******************************************************************************/
void off_display(off_struct data)
{
    if(mcdotrace==2){
    // Estimate size of the JSON string
    const int VERTEX_OVERHEAD = 30;
    const int FACE_OVERHEAD_BASE = 20;
    const int FACE_INDEX_OVERHEAD = 15;
    int estimated_size = 256; // Base size
    estimated_size += data.vtxSize * VERTEX_OVERHEAD;

    for (int i = 0; i < data.faceSize;) {
        int num_indices = data.faceArray[i];
        estimated_size += FACE_OVERHEAD_BASE + num_indices * FACE_INDEX_OVERHEAD;
        i += num_indices + 1;
    }

    char *json_string = malloc(estimated_size);
    if (json_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    char *ptr = json_string;
    ptr += sprintf(ptr, "{ \"vertices\": [");

    for (int i = 0; i < data.vtxSize; i++) {
        ptr += sprintf(ptr, "[%g, %g, %g]", data.vtxArray[i].x, data.vtxArray[i].y, data.vtxArray[i].z);
        if (i < data.vtxSize - 1) {
            ptr += sprintf(ptr, ", ");
        }
    }

    ptr += sprintf(ptr, "], \"faces\": [");

    for (int i = 0; i < data.faceSize;) {
        int num = data.faceArray[i];
        ptr += sprintf(ptr, "{ \"face\": [");
        for (int j = 1; j <= num; j++) {
            ptr += sprintf(ptr, "%lu", data.faceArray[i + j]);
            if (j < num) {
                ptr += sprintf(ptr, ", ");
            }
        }
        ptr += sprintf(ptr, "]}");
        i += num + 1;
        if(i<data.faceSize){
          ptr += sprintf(ptr, ", ");
        }
    }

    ptr += sprintf(ptr, "]}");
    mcdis_polyhedron(json_string);

    free(json_string);
    }
    else {
      unsigned int i;
      double ratio=(double)(N_VERTEX_DISPLAYED)/(double)data.faceSize;
      unsigned int pixel=0;
      for (i=0; i<data.faceSize-1; i++) {
        int j;
        int nbVertex = data.faceArray[i];
        double x0,y0,z0;
        x0 = data.vtxArray[data.faceArray[i+1]].x;
        y0 = data.vtxArray[data.faceArray[i+1]].y;
        z0 = data.vtxArray[data.faceArray[i+1]].z;
        double x1=x0,y1=y0,z1=z0;
        double cmx=0,cmy=0,cmz=0;

        int drawthis = rand01() < ratio;
        // First pass, calculate center of mass location...
        for (j=1; j<=nbVertex; j++) {
          cmx = cmx+data.vtxArray[data.faceArray[i+j]].x;
          cmy = cmy+data.vtxArray[data.faceArray[i+j]].y;
          cmz = cmz+data.vtxArray[data.faceArray[i+j]].z;
        }
        cmx /= nbVertex;
        cmy /= nbVertex;
        cmz /= nbVertex;

        char pixelinfo[1024];
	char pixelinfotmp[1024];
        sprintf(pixelinfo, "%li,%li,%li,%i,%g,%g,%g,%g,%g,%g", data.mantidoffset+pixel, data.mantidoffset, data.mantidoffset+data.polySize-1, nbVertex, cmx, cmy, cmz, x1-cmx, y1-cmy, z1-cmz);
        for (j=2; j<=nbVertex; j++) {
          double x2,y2,z2;
          x2 = data.vtxArray[data.faceArray[i+j]].x;
          y2 = data.vtxArray[data.faceArray[i+j]].y;
          z2 = data.vtxArray[data.faceArray[i+j]].z;
          sprintf(pixelinfotmp, "%s,%g,%g,%g", pixelinfo, x2-cmx, y2-cmy, z2-cmz);
	  sprintf(pixelinfo,"%s",pixelinfotmp);
          if (ratio > 1 || drawthis) {
	    mcdis_line(x1,y1,z1,x2,y2,z2);
          }
          x1 = x2; y1 = y2; z1 = z2;
        }
        if (ratio > 1 || drawthis) {
	    mcdis_line(x1,y1,z1,x0,y0,z0);
          }
        if (data.mantidflag) {
          printf("MANTID_PIXEL: %s\n", pixelinfo);
          pixel++;
        }
        i += nbVertex;
      }
    }
} /* off_display */

/* end of interoff-lib.c */
#endif // INTEROFF_LIB_C


  /* For the density of states S(w) */
  struct Sqw_W_struct {
    double omega;       /* omega value for the data block */
    double cumul_proba; /* cumulated intensity (between 0 and 1) */
  };

  /* For the S(q|w) probabilities */
  struct Sqw_Q_struct {
    double Q;           /* omega value for the data block */
    double cumul_proba; /* normalized cumulated probability */
  };

  struct Sqw_Data_struct /* contains normalized Sqw data for probabilities, coh and inc */
  {
    struct Sqw_W_struct* SW;   /* P(w)  ~ density of states */
    struct Sqw_Q_struct** SQW; /* P(Q|w)= probability of each Q with w */

    long* SW_lookup;
    long** QW_lookup;
    t_Table Sqw;  /* S(q,w) rebin from file in range -w_max:w_max and 0:q_max, with exp(-hw/kT) weight */
    t_Table iqSq; /* sigma(Ei) = sigma/2/Ki^2 * \int q S(q,w) dq dw up to 2*Ki_max */
    long q_bins;
    long w_bins;          /* length of q and w vectors/axes from file */
    double q_max, q_step; /* min=0      */
    double w_max, w_step; /* min=-w_max */
    long lookup_length;
    char filename[80];
    double intensity;
    double Ei_max; /* max neutron incoming energy for Sigma=iqSq table */
    long iqSq_length;
    char type;
    double q_min_file;
  };

  struct Sqw_sample_struct { /* global parameters gathered as a structure */
    char compname[256];

    struct Sqw_Data_struct Data_inc;
    struct Sqw_Data_struct Data_coh;

    double s_abs, s_coh, s_inc; /* material constants */
    double my_s;
    double my_a_v;
    double mat_rho;
    double mat_weight;
    double mat_density;
    double Temperature; /* temperature from the data file */
    int shape;          /* 0:cylinder, 1:box, 2:sphere 3:any shape*/

    double sqw_threshold; /* options to tune S(q,w) */
    double sqw_classical;
    double sqw_norm;

    double barns; /* for powders */
    double Dd, DWfactor;

    double T2E; /* constants */
    char Q_correction[256];
    double sqSE2K;

    int maxloop; /* flags to monitor caught warnings */
    int minevents;
    long neutron_removed;
    long neutron_enter;
    long neutron_pmult;
    long neutron_exit;
    char verbose_output;
    int column_order[9]; /* column signification */
    long lookup_length;

    double dq, dw; /* q/w transfer */
    char type;     /* interaction type: c(coherent),             i(incoherent),
                                        V(isotropic incoherent), t(transmitted) */
    /* store information from the last event */
    double ki_x, ki_y, ki_z, kf_x, kf_y, kf_z;
    double ti, tf;
    double vi, vf;
    double ki, kf;
    double theta;

    double mean_scatt; /* stat to show at the end */
    double mean_abs;
    double psum_scatt;
    double single_coh;
    double single_inc;
    double multi;

    double rw, rq;
  };

  #include <stdio.h>
  #include <math.h>

  /* sets a Data S(q,w) to 'NULL' */
  void
  Sqw_Data_init (struct Sqw_Data_struct* Sqw_Data) {
    Sqw_Data->q_bins = 0;
    Sqw_Data->w_bins = 0;
    Sqw_Data->q_max = 0;
    Sqw_Data->q_step = 1;
    Sqw_Data->w_max = 0;
    Sqw_Data->w_step = 1;
    Sqw_Data->Ei_max = 0;
    Sqw_Data->lookup_length = 100; /* length of lookup tables */
    Sqw_Data->intensity = 0;
    strcpy (Sqw_Data->filename, "");
    Sqw_Data->SW = NULL;
    Sqw_Data->SQW = NULL;
    Sqw_Data->SW_lookup = NULL;
    Sqw_Data->QW_lookup = NULL;
    Sqw_Data->iqSq_length = 100;
    Sqw_Data->type = ' ';
    Sqw_Data->q_min_file = 0;
  }

  off_struct offdata;

  /* gaussian distribution to appply around Bragg peaks in a powder */
  double
  Sqw_powder_gauss (double x, double mean, double rms) {
    return (exp (-(x - mean) * (x - mean) / (2 * rms * rms)) / (sqrt (2 * PI) * rms));
  }

  /* Sqw_quantum_correction
  *
  * Return the 'quantum correction factor Q so that:
  *
  *   S(q, w) = Q(w) S*(q,w)
  *   S(q,-w) = exp(-hw/kT) S(q,w)
  *   S(q, w) = exp( hw/kT) S(q,-w)
  *
  * with S*=classical limit and Q(w) defined below. For omega > 0, S(q,w) > S(q,-w)
  *
  * input:
  *   w: energy      [meV]
  *   T: temperature [K]
  *   type: 'Schofield' or 'Boltzmann'        Q = exp(hw/kT/2)
  *         'harmonic'  or 'Bader'            Q = hw/kT./(1-exp(-hw/kT))
  *         'standard'  or 'Frommhold'        Q = 2./(1+exp(-hw/kT)) [recommended]
  *
  * References:
  *  B. Hehr, http://www.lib.ncsu.edu/resolver/1840.16/7422 PhD manuscript (2010).
  *  S. A. Egorov, K. F. Everitt and J. L. Skinner. J. Phys. Chem., 103, 9494 (1999).
  *  P. Schofield. Phys. Rev. Lett., 4, 239 (1960).
  *  J. S. Bader and B. J. Berne. J. Chem. Phys., 100, 8359 (1994).
  *  T. D. Hone and G. A. Voth. J. Chem. Phys., 121, 6412 (2004).
  *  L. Frommhold. Collision-induced absorption in gases, 1 st ed., Cambridge
  *    Monographs on Atomic, Molecular, and Chemical Physics, Vol. 2,
  *    Cambridge Univ. Press: London (1993).

   */
  double
  Sqw_quantum_correction (double hw, double T, char* type) {
    double Q = 1;
    double kT = T / 11.605; /* [K] -> [meV = 1000*KB/e] */
    if (!hw || !T)
      return 1;
    if (type == NULL || !strcmp (type, "standard") || !strcmp (type, "Frommhold") || !strcmp (type, "default"))
      Q = 2 / (1 + exp (-hw / kT));
    if (!strcmp (type, "Schofield") || !strcmp (type, "Boltzmann"))
      Q = exp (hw / kT / 2);
    if (!strcmp (type, "harmonic") || !strcmp (type, "Bader"))
      Q = hw / kT / (1 - exp (-hw / kT));

    return Q;
  }

  /*****************************************************************************
   * Sqw_read_PowderN: Read PowderN data files
   *   Returns t_Table array or NULL in case of error
   * Used in : Sqw_readfile (1)
   *****************************************************************************/
  t_Table*
  Sqw_read_PowderN (struct Sqw_sample_struct* Sqw, t_Table sqwTable) {
    struct line_data {
      double F2;       /* Value of structure factor */
      double q;        /* Q vector */
      int j;           /* Multiplicity */
      double DWfactor; /* Debye-Waller factor */
      double w;        /* Intrinsic line width */
    };
    struct line_data* list = NULL;
    double q_count = 0, j_count = 0, F2_count = 0;
    int mult_count = 0;
    double q_step = FLT_MAX;
    long size = 0;
    int i, index;
    double q_min = 0, q_max = 0;
    char flag = 0;
    int list_count = 0;
    double q_step_cur;
    char flag_qSq = 0;

    t_Table* retTable;

    flag_qSq = (Sqw->column_order[8] > 0 && Sqw->column_order[6] > 0);

    MPI_MASTER (if (Sqw->column_order[0] == 4 && Sqw->barns != 0)
                    printf ("Isotropic_sqw: %s: Powder file probably of type Crystallographica/Fullprof (lau)\n"
                            "WARNING:       but F2 unit is set to powder_barns=1 (barns). Intensity might be 100 times too high.\n",
                            Sqw->compname);
                if (Sqw->column_order[0] == 17 && Sqw->barns == 0)
                    printf ("Isotropic_sqw: %s: Powder file probably of type Lazy Pulver (laz)\n"
                            "WARNING:       but F2 unit is set to powder_barns=0 (fm^2). Intensity might be 100 times too low.\n",
                            Sqw->compname););
    size = sqwTable.rows;
    MPI_MASTER (if (Sqw->verbose_output > 0) {
      printf ("Isotropic_sqw: Converting %ld %s from %s into S(q,w) data\n", size, flag_qSq ? "S(q)" : "powder lines", sqwTable.filename);
    });
    /* allocate line_data array */
    list = (struct line_data*)malloc (size * sizeof (struct line_data));

    for (i = 0; i < size; i++) {
      double j = 0, d = 0, w = 0, DWfactor = 0, F2 = 0, Sq = -1, q = 0;
      int index;

      if (Sqw->Dd >= 0)
        w = Sqw->Dd;
      if (Sqw->DWfactor > 0)
        DWfactor = Sqw->DWfactor;

      /* get data from table using columns {j d F2 DW Dd inv2d q} + { Sq }*/
      /* column indexes start at 1, thus need to substract 1 */
      if (Sqw->column_order[0] > 0)
        j = Table_Index (sqwTable, i, Sqw->column_order[0] - 1);
      if (Sqw->column_order[1] > 0)
        d = Table_Index (sqwTable, i, Sqw->column_order[1] - 1);
      if (Sqw->column_order[2] > 0)
        F2 = Table_Index (sqwTable, i, Sqw->column_order[2] - 1);
      if (Sqw->column_order[3] > 0)
        DWfactor = Table_Index (sqwTable, i, Sqw->column_order[3] - 1);
      if (Sqw->column_order[4] > 0)
        w = Table_Index (sqwTable, i, Sqw->column_order[4] - 1);
      if (Sqw->column_order[5] > 0 && !(Sqw->column_order[1] > 0)) {
        d = Table_Index (sqwTable, i, Sqw->column_order[5] - 1);
        if (d)
          d = 1 / d / 2;
      }
      if (Sqw->column_order[6] > 0)
        q = Table_Index (sqwTable, i, Sqw->column_order[6] - 1);
      if (Sqw->column_order[7] > 0 && !F2) {
        F2 = Table_Index (sqwTable, i, Sqw->column_order[7] - 1);
        F2 *= F2;
      }

      if (Sqw->column_order[8] > 0)
        Sq = Table_Index (sqwTable, i, Sqw->column_order[8] - 1);

      if (q > 0 && Sq >= 0)
        F2 = Sq;
      if (d > 0 && q <= 0)
        q = 2 * PI / d;

      /* assign and check values */
      j = (j > 0 ? j : 0);
      if (flag_qSq)
        j = 1;
      DWfactor = (DWfactor > 0 ? DWfactor : 1);
      w = (w > 0 ? w : 0);
      F2 = (F2 >= 0 ? F2 : 0);
      d = (q > 0 ? 2 * PI / d : 0);
      if (j == 0 || d == 0 || q == 0) {
        MPI_MASTER (printf ("Isotropic_sqw: %s: Warning: line %i has invalid definition\n"
                            "         (mult=0 or q=0 or d=0)\n",
                            Sqw->compname, i););
        continue;
      }
      list[list_count].j = j;
      list[list_count].q = q;
      list[list_count].DWfactor = DWfactor;
      list[list_count].w = w;
      list[list_count].F2 = F2; /* or S(q) if flag_qSq */

      if (q_max < d)
        q_max = q;
      if (q_min > d)
        q_min = q;
      if (list_count > 1) {
        q_step_cur = fabs (list[list_count].q - list[list_count - 1].q);
        if (q_step_cur > 1e-5 && (!q_step || q_step_cur < q_step))
          q_step = q_step_cur;
      }

      /* adjust multiplicity if j-column + multiple d-spacing lines */
      /* if  d = previous d, increase line duplication index */
      if (!q_count)
        q_count = q;
      if (!j_count)
        j_count = j;
      if (!F2_count)
        F2_count = F2;
      if (fabs (q_count - q) < 0.0001 * fabs (q) && fabs (F2_count - F2) < 0.0001 * fabs (F2) && j_count == j) {
        mult_count++;
        flag = 0;
      } else
        flag = 1;
      if (i == size - 1)
        flag = 1;
      /* else if d != previous d : just passed equivalent lines */
      if (flag) {
        if (i == size - 1)
          list_count++;
        /*   if duplication index == previous multiplicity */
        /*      set back multiplicity of previous lines to 1 */
        if (Sqw->verbose_output > 2 && (mult_count == list[list_count - 1].j || (mult_count == list[list_count].j && i == size - 1))) {
          MPI_MASTER (printf ("Isotropic_Sqw: %s: Setting multiplicity to 1 for lines [%i:%i]\n"
                              "         (d-spacing %g is duplicated %i times)\n",
                              Sqw->compname, list_count - mult_count, list_count - 1, list[list_count - 1].q, mult_count););
          for (index = list_count - mult_count; index < list_count; list[index++].j = 1)
            ;
          mult_count = 1;
          q_count = q;
          j_count = j;
          F2_count = F2;
        }
        if (i == size - 1)
          list_count--;
        flag = 0;
      }
      list_count++;
    } /* end for */

    /* now builds new Table_Array to continue with Sqw_readfile */
    if (q_max == q_min || !q_step)
      return (NULL);
    if (!flag_qSq)
      size = 3 * q_max / q_step; /* set a default of 3 q values per line */
    else
      size = list_count;
    /* update the value of q_step */
    q_step = q_max / size;
    MPI_MASTER (if (Sqw->verbose_output > 0) printf ("Isotropic_sqw: q range [%g:%g], creating %li elements vector\n", q_min, q_max, size););

    retTable = (t_Table*)calloc (4, sizeof (t_Table));
    if (!retTable)
      printf ("Isotropic_Sqw: ERROR: Cannot allocate PowderN->Sqw table.\n");
    else {
      char* header;
      if (!Table_Init (&retTable[0], size, 1)) {
        printf ("Isotropic_Sqw: ERROR Cannot allocate q-axis [%li] from Powder lines.\n", size);
        return (NULL);
      }
      if (!Table_Init (&retTable[1], 1, 1)) {
        printf ("Isotropic_Sqw: ERROR Cannot allocate w-axis from Powder lines.\n");
        return (NULL);
      }
      if (!Table_Init (&retTable[2], size, 1)) {
        printf ("Isotropic_Sqw: ERROR Cannot allocate Sqw [%li] from Powder lines.\n", size);
        return (NULL);
      }
      Table_Init (&retTable[3], 0, 0);

      header = malloc (64);
      if (header) {
        retTable[0].header = header;
        strcpy (retTable[0].header, "q");
      }
      header = malloc (64);
      if (header) {
        retTable[1].header = header;
        strcpy (retTable[1].header, "w");
      }
      header = malloc (64);
      if (header) {
        retTable[2].header = header;
        strcpy (retTable[2].header, "Sqw");
      }
      for (i = 0; i < 4; i++) {
        retTable[i].array_length = 3;
        retTable[i].block_number = i + 1;
      }
      if (!flag_qSq)
        for (i = 0; i < size; i++)
          retTable[0].data[i] = i * q_max / size;
      for (i = 0; i < list_count; i++) { /* loop on each Bragg peak */
        double peak_qmin, peak_qmax, factor, q;
        if (list[i].w > 0 && !flag_qSq) {
          peak_qmin = list[i].q * (1 - list[i].w * 3);
          peak_qmax = list[i].q * (1 + list[i].w * 3);
        } else { /* Dirac peak, no width */
          peak_qmin = peak_qmax = list[i].q;
        }
        /* S(q) intensity is here */
        factor = list[i].j * (list[i].DWfactor ? list[i].DWfactor : 1) * Sqw->mat_rho * PI / 2 / (Sqw->type == 'c' ? Sqw->s_coh : Sqw->s_inc) * list[i].F2
                 / list[i].q / list[i].q;
        if (Sqw->barns)
          factor *= 100;
        for (q = peak_qmin; q <= peak_qmax; q += q_step) {
          index = (long)floor (size * q / q_max);
          if (index < 0)
            index = 0;
          else if (index >= size)
            index = size - 1;
          if (flag_qSq) {
            retTable[2].data[index] += list[i].F2;
            retTable[0].data[index] = list[i].q;
          } else {
            if (list[i].w <= 0 || list[i].w * q < q_step) /* step function */
              retTable[2].data[index] += factor / q_step;
            else /* gaussian */
              retTable[2].data[index] += factor * Sqw_powder_gauss (q, list[i].q, list[i].w * list[i].q);
          }
        }
      } /* end for i */
      Table_Stat (&retTable[0]);
      Table_Stat (&retTable[1]);
      Table_Stat (&retTable[2]);
      Sqw->sqw_norm = 0; /* F2 are normalized already */
    }

    return (retTable);
  } /* Sqw_read_PowderN */

  /*****************************************************************************
   *  Sqw_search_SW: For a given random number 'randnum', search for the bin
   *   containing  the corresponding Sqw->SW
   *  Choose an energy in the projected S(w) distribution
   * Used in : TRACE (1)
   *****************************************************************************/
  #pragma acc routine seq
  int
  Sqw_search_SW (struct Sqw_Data_struct Sqw, double randnum) {
    int index_w = 0;

    if (randnum < 0)
      randnum = 0;
    if (randnum > 1)
      randnum = 1;

    if (Sqw.w_bins == 1)
      return (0);
    /* benefit from fast lookup table if exists */
    if (Sqw.SW_lookup) {
      index_w = Sqw.SW_lookup[(long)floor (randnum * Sqw.lookup_length)] - 1;
      if (index_w < 0)
        index_w = 0;
    }

    while (index_w < Sqw.w_bins && (&(Sqw.SW[index_w]) != NULL) && (randnum > Sqw.SW[index_w].cumul_proba))
      index_w++;
    if (index_w >= Sqw.w_bins)
      index_w = Sqw.w_bins - 1;

    if (&(Sqw.SW[index_w]) == NULL) {
      printf ("Isotropic_Sqw: Warning: No corresponding value in the SW. randnum too big.\n");
      printf ("  index_w=%i ; randnum=%f ; Sqw.SW[index_w-1].cumul_proba=%f (Sqw_search_SW)\n", index_w, randnum, Sqw.SW[index_w - 1].cumul_proba);
      return index_w - 1;
    } else
      return (index_w);
  }

  /*****************************************************************************
   *  Sqw_search_Q_proba_per_w: For a given random number randnum, search for
   *   the bin containing the corresponding Sqw.SW in the Q probablility grid
   *  Choose a momentum in the S(q|w) distribution
   *  index is given by Sqw_search_SW
   * Used in : TRACE (1)
   *****************************************************************************/
  #pragma acc routine seq
  int
  Sqw_search_Q_proba_per_w (struct Sqw_Data_struct Sqw, double randnum, int index_w) {
    int index_q = 0;

    if (randnum < 0)
      randnum = 0;
    if (randnum > 1)
      randnum = 1;

    /* benefit from fast lookup table if exists */
    if (Sqw.QW_lookup && Sqw.QW_lookup[index_w]) {
      index_q = Sqw.QW_lookup[index_w][(long)floor (randnum * Sqw.lookup_length)] - 1;
      if (index_q < 0)
        index_q = 0;
    }

    while (index_q < Sqw.q_bins && (&(Sqw.SQW[index_w][index_q]) != NULL) && (randnum > Sqw.SQW[index_w][index_q].cumul_proba)) {
      index_q++;
    }
    if (index_q >= Sqw.q_bins)
      index_q = Sqw.q_bins - 1;

    if (&(Sqw.SQW[index_w][index_q]) == NULL)
      return -1;
    else
      return (index_q);
  }

  /*****************************************************************************
   * compute the effective total cross section \int q S(q,w) dw dq
   * for incoming neutron energy 0 < Ei < 2*w_max, and
   * integration range w=-w_max:Ei and q=Q0:Q1 with
   *   Q0 = SE2Q*(sqrt(Ei)-sqrt(Ei-w))=|Ki-Kf|
   *   Q1 = SE2Q*(sqrt(Ei)+sqrt(Ei-w))=|Ki+Kf|
   * The data to use is Sqw_Data->Sqw, and the limits are Sqw_Data->w_max Sqw_Data->q_max
   *   Returns the integral value
   * Used in: Sqw_readfile (1)
   *****************************************************************************/
  #pragma acc routine seq
  double
  Sqw_integrate_iqSq (struct Sqw_Data_struct* Sqw_Data, double Ei) {
    long index_w;
    double iqSq = 0;
    /* w=Ei-Ef q=ki-kf w>0 neutron looses energy, Stokes, Ef = Ei-w > 0, Kf =|Ki-q| > 0 */
    for (index_w = 0; index_w < Sqw_Data->w_bins; index_w++) {
      long index_q;
      double w = -Sqw_Data->w_max + index_w * Sqw_Data->w_step; /* in the Sqw table */
      if (w <= Ei) {                                            /* integration range w=-w_max:Ei, Ef = Ei-w > 0 */
        double sq = 0, Q0 = 0, Q1 = 0;
        sq = sqrt (Ei - w); /* always real as test was true before */
        Q0 = SE2V * V2K * (sqrt (Ei) - sq);
        Q1 = SE2V * V2K * (sqrt (Ei) + sq);

        for (index_q = 0; index_q < Sqw_Data->q_bins; index_q++) {
          double q = (double)index_q * Sqw_Data->q_step;
          /* add 'pixel' = q S(q,w) */
          if (Q0 <= q && q <= Q1)
            iqSq += q * Table_Index (Sqw_Data->Sqw, index_q, index_w);
        }
      }
    }
    /* multiply by 'pixel' size = dq dw */
    return (iqSq * Sqw_Data->q_step * Sqw_Data->w_step);
  } /* Sqw_integrate_iqSq */

  /*****************************************************************************
   * Sqw_diagnosis: Computes Sqw_classical, moments and physical quantities
   *                make consistency checks, and output some data files
   *   Return: output files and information displayed
   * Used in: Sqw_init (2) only by MASTER node with MPI
   *****************************************************************************/
  void
  Sqw_diagnosis (struct Sqw_sample_struct* Sqw, struct Sqw_Data_struct* Sqw_Data) {

    t_Table Sqw_cl;         /* the Sqw symmetric/classical version (T-> Inf) */
    t_Table Gqw;            /* the generalized density of states as of Carpenter and Price, J Non Cryst Sol 92 (1987) 153 */
    t_Table Sqw_moments[7]; /* M0=S(q) M1=E_r M3 w_c w_l M0_cl=S_cl(q) G(w) */
    t_Table w_c, w_l;
    long index_q, index_w;
    char c[CHAR_BUF_LENGTH]; /* temporary variable */
    long q_min_index = 0;

    char do_coh = 0, do_inc = 0;
    double q_min = 0;
    double u2 = 0, S0 = 1;
    long u2_count = 0;

    if (!Sqw_Data || !Sqw_Data->intensity)
      return; /* nothing to do with empty S(q,w) */

    if (Sqw_Data->type == 'c')
      do_coh = 1;
    if (Sqw_Data->type == 'i')
      do_inc = 1;

    q_min = Sqw_Data->q_min_file;
    if (q_min <= 0)
      q_min = Sqw_Data->q_step;

    /* test if there is only one S(q,w) available */
    if (!((Sqw->Data_inc).intensity) || !((Sqw->Data_coh).intensity))
      do_coh = do_inc = 1; /* do both if only one file given */

    if (Sqw->Temperature > 0) {
      if (!Table_Init (&Sqw_cl, Sqw_Data->q_bins, Sqw_Data->w_bins)) {
        printf ("Isotropic_Sqw: %s: Cannot allocate S_cl(q,w) Table (%lix%i).\n"
                "WARNING          Skipping S(q,w) diagnosis.\n",
                Sqw->compname, Sqw_Data->q_bins, 1);
        return;
      }
      sprintf (Sqw_cl.filename, "S(q,w)_cl from %s (dynamic structure factor, classical)", Sqw_Data->filename);
      Sqw_cl.block_number = 1;
      Sqw_cl.min_x = 0;
      Sqw_cl.max_x = Sqw_Data->q_max;
      Sqw_cl.step_x = Sqw_Data->q_step;
    }

    /* initialize moments and 1D stuff */
    for (index_q = 0; index_q < 6; index_q++) {
      if (!Table_Init (&Sqw_moments[index_q], Sqw_Data->q_bins, 1)) {
        printf ("Isotropic_Sqw: %s: Cannot allocate S(q,w) moment %ld Table (%lix%i).\n"
                "WARNING          Skipping S(q,w) diagnosis.\n",
                Sqw->compname, index_q, Sqw_Data->q_bins, 1);
        Table_Free (&Sqw_cl);
        return;
      }
      Sqw_moments[index_q].block_number = 1;
      Sqw_moments[index_q].min_x = 0;
      Sqw_moments[index_q].max_x = Sqw_Data->q_max;
      Sqw_moments[index_q].step_x = Sqw_Data->q_step;
    }
    index_q = 6;
    Table_Init (&Sqw_moments[index_q], Sqw_Data->w_bins, 1);
    Sqw_moments[index_q].block_number = 1;
    Sqw_moments[index_q].min_x = -Sqw_Data->w_max;
    Sqw_moments[index_q].max_x = Sqw_Data->w_max;
    Sqw_moments[index_q].step_x = Sqw_Data->w_step;

    /* set Table titles */
    sprintf (Sqw_moments[0].filename, "S(q)=M0(q) from %s [int S(q,w) dw]", Sqw_Data->filename);
    sprintf (Sqw_moments[1].filename, "M1(q) 1-st moment from %s [int w S(q,w) dw] = HBAR^2*q^2/2/m (f-sum rule, recoil, Lovesey T1 Eq 3.63 p72, Egelstaff p196)",
             Sqw_Data->filename);
    sprintf (Sqw_moments[2].filename, "M3(q) 3-rd moment from %s [int w^3 S(q,w) dw] = M1(q)*w_l^2(q)", Sqw_Data->filename);
    sprintf (Sqw_moments[3].filename,
             "w_c(q) = sqrt(M1(q)/M0(q)*2kT) collective excitation from %s (Lovesey T1 Eq 5.38 p180, p211 Eq 5.204). Gaussian half-width of the S(q,w) classical",
             Sqw_Data->filename);
    sprintf (Sqw_moments[4].filename, "w_l(q) = sqrt(M3(q)/M1(q)) harmonic frequency from %s (Lovesey T1 5.39 p 180)", Sqw_Data->filename);
    sprintf (Sqw_moments[5].filename, "S_cl(q)=M0_cl(q) from %s [int S_cl(q,w) dw]", Sqw_Data->filename);
    sprintf (Sqw_moments[6].filename, "G(w) generalized effective density of states from %s (Carpenter J Non Cryst Sol 92 (1987) 153)", Sqw_Data->filename);

    for (index_q = 0; index_q < Sqw_Data->q_bins; index_q++) {
      double q = index_q * Sqw_Data->q_step; /* q value in Sqw_full ; q_min = 0 */
      double sq = 0;                         /* S(q) = w0 = 0-th moment */
      double w1 = 0;                         /* first  moment      \int w     Sqw dw */
      double w3 = 0;                         /* third  moment      \int w^3   Sqw dw */
      double sq_cl = 0;                      /* S(q) = M0 = 0-th moment classical */
      double w_c = 0;
      double w_l = 0;

      for (index_w = 0; index_w < Sqw_Data->w_bins; index_w++) {

        double w = -Sqw_Data->w_max + index_w * Sqw_Data->w_step; /* w value in Sqw_full */
        double sqw_cl = 0;
        double sqw_full = 0;

        sqw_full = Table_Index (Sqw_Data->Sqw, index_q, index_w);

        /* Sqw moments */
        if (w && Sqw_Data->w_bins) {
          double tmp;
          tmp = sqw_full * Sqw_Data->w_step;
          tmp *= w;
          w1 += tmp;
          tmp *= w * w;
          w3 += tmp;
        }

        /* compute classical Sqw and S(q)_cl */
        if (Sqw->Temperature > 0) {
          double n;
          sqw_cl = sqw_full * Sqw_quantum_correction (-w, Sqw->Temperature, Sqw->Q_correction);
          if (!Table_SetElement (&Sqw_cl, index_q, index_w, sqw_cl))
            printf ("Isotropic_Sqw: %s: "
                    "Error when setting Sqw_cl[%li q=%g,%li w=%g]=%g from file %s\n",
                    Sqw->compname, index_q, q, index_w, w, sqw_cl, Sqw_Data->filename);
          sq_cl += sqw_cl;
        }
        sq += sqw_full;
      } /* for index_w */

      sq *= Sqw_Data->w_step; /* S(q) = \int S(q,w) dw = structure factor */
      sq_cl *= Sqw_Data->w_step;
      /* find minimal reliable q value (not interpolated) */
      if (q >= q_min && !q_min_index && sq) {
        q_min_index = index_q;
        q_min = q;
        if (0.9 < sq)
          S0 = sq; /* minimum reliable S(q) */
        else
          S0 = 1;
      }
      /* compute <u^2> = <3 * ln(S(q)) / q^2> */
      if (q_min_index && q && S0 && sq) {
        u2 += 3 * log (sq / S0) / q / q;
        u2_count++;
      }

      /* store moment values (q) as M0=S(q) M1=E_r M3 w_c w_l M0_cl=S_cl(q) */
      Table_SetElement (&Sqw_moments[0], index_q, 0, sq);
      Table_SetElement (&Sqw_moments[1], index_q, 0, w1);
      Table_SetElement (&Sqw_moments[2], index_q, 0, w3);
      if (w1 > 0 && sq && Sqw->Temperature > 0) {
        double w_c = sqrt (w1 / sq * 2 * Sqw->Temperature * Sqw->T2E); /* HBAR^2 q^2 kT /m/ S(q) */
        Table_SetElement (&Sqw_moments[3], index_q, 0, w_c);           /* collective dispersion */
      }
      if (w1 && w3 * w1 > 0) {
        double w_l = sqrt (w3 / w1);
        Table_SetElement (&Sqw_moments[4], index_q, 0, w_l); /* harmonic dispersion */
      }
      if (Sqw->Temperature > 0)
        Table_SetElement (&Sqw_moments[5], index_q, 0, sq_cl);

    } /* for index_q */

    /* display some usefull information, only once in MPI mode (MASTER) */
    if (Sqw->Temperature > 0) {
      double Da = 1.660538921e-27; /* [kg] unified atomic mass unit = Dalton = 1 g/mol */
                                   #ifndef KB
      double KB = 1.3806503e-23;   /* [J/K] */
      /* HBAR   = 1.05457168e-34 */
      #endif
      double CELE = 1.602176487e-19;               /* [C] Elementary charge CODATA 2006 'e' */
      double meV2Hz = CELE / HBAR / 1000 / 2 / PI; /* 1 meV = 241.80e9 GHz */
      double gqw_sum = 0;

      /* classical Sqw */
      sprintf (c, "%s_%s_cl.sqw", Sqw->compname, Sqw_Data->type == 'c' ? "coh" : "inc");
      Table_Write (Sqw_cl, c, "Momentum [Angs-1]", "'S(q,w)*exp(hw/2kT) classical limit' Energy [meV]", 0, Sqw_Data->q_max, -Sqw_Data->w_max, Sqw_Data->w_max);
      Table_Free (&Sqw_cl);

      if (u2_count)
        u2 /= u2_count;

      MPI_MASTER (
          if (do_coh || do_inc) printf ("Isotropic_Sqw: %s: "
                                        "Physical constants from the S(q,w) %s for T=%g [K]. Values are estimates.\n",
                                        Sqw->compname, Sqw_Data->filename, Sqw->Temperature);
          if (do_coh) {
            if (Sqw->mat_weight) {
              double LAMBDA = HBAR * 2 * PI / sqrt (2 * PI * Sqw->mat_weight * Da * KB * Sqw->Temperature) * 1e10; /* in [Angs] */
              double z = Sqw->mat_rho * LAMBDA * LAMBDA * LAMBDA;                                                  /* fugacity , rho=N/V in [Angs-3]*/
              double mu = KB * Sqw->Temperature * log (z);                                                         /* perfect gas chemical potential */
              printf ("# De Broglie wavelength     LAMBDA=%g [Angs]\n", LAMBDA);
              printf ("# Fugacity                       z=%g (from Egelstaff p32 Eq 2.31)\n", z);
              printf ("# Chemical potential            mu=%g [eV] (eq. perfect gas)\n", mu / CELE);
            }

            /* compute isothermal sound velocity and compressibility */
            /* get the S(q_min) value and the corresponding w_c */

            if (q_min_index > 0 && q_min && q_min < 0.6) {
              double w_c = Table_Index (Sqw_moments[3], q_min_index, 0); /* meV */
              /* HBAR = [J*s] */
              double c_T = 2 * PI * w_c * meV2Hz / q_min / 1e10; /* meV*Angs -> m/s */
              double ChiT = S0 / (KB * Sqw->Temperature * Sqw->mat_rho * 1e30);
              printf ("# Isothermal compressibility Chi_T=%g [Pa-1] (Egelstaff  p201 Eq 10.21) at q=%g [Angs-1]\n", ChiT, q_min);
              printf ("# Isothermal sound velocity    c_T=%g [m/s]  (Lovesey T1 p210 Eq 5.197) at q=%g [Angs-1]\n", c_T, q_min);

              /* Computation if C11 is rather tricky as it is obtained from w_l, which is usually quite noisy
               * This means that the obtained values are not reliable from C = rho c_l^2 (Egelstaff Eq 14.10b p284)
               * C44 = rho c_c^2 ~ C11/3
               */
              double w_l = Table_Index (Sqw_moments[4], q_min_index, 0); /* meV */
              double c_l = 2 * PI * w_l * meV2Hz / q_min / 1e10;         /* meV*Angs -> m/s */
              double C11 = (Sqw->mat_weight * Da) * (Sqw->mat_rho * 1e30) * c_l * c_l;
              printf ("# Elastic modulus              C11=%g [GPa]  (Egelstaff Eq 14.10b p284) [rough estimate] at q=%g [Angs-1]\n", C11 / 1e9, q_min);
            }
          } if (do_inc) {
            /* display the mean square displacement from S(q) = exp(-<u^2>q^2/3)
                 <u^2>= <3 * ln(S(q)) / q^2>
             */
            if (u2_count && u2) {
              printf ("# Mean square displacement   <u^2>=%g [Angs^2] (<3 * ln(S(q)) / q^2>)\n", u2);
            }

            /* compute the mean diffusion coefficient D=w_c/q^2 */
            /* FWHM of gaussian is Gamma*RMS2FWHM, only in diffusive regime (Q < 0.2 Angs-1) */
            if (q_min_index > 0 && q_min && q_min < 0.6) {
              double w_c = Table_Index (Sqw_moments[3], q_min_index, 0);
              double D = 2 * PI * w_c * meV2Hz / q_min / q_min / 1e14 * RMS2FWHM / 2; /* meV*Angs^2 -> mm^2/s */
              printf ("# Diffusion coefficient          D=%g [mm^2/s] (Egelstaff p220)\n", D);
              if (u2_count && u2 && D)
                printf ("# Jump relaxation time         tau=%g [ns] (Egelstaff Eq 11.8 p220)\n", u2 * 1e-2 / 6 / D);
            }
          }); /* MPI_MASTER */

      /* density of states (generalized) */
      if (!Table_Init (&Gqw, Sqw_Data->q_bins, Sqw_Data->w_bins)) {
        printf ("Isotropic_Sqw: %s: Cannot allocate G(q,w) Table (%lix%i).\n"
                "WARNING          Skipping S(q,w) diagnosis.\n",
                Sqw->compname, Sqw_Data->q_bins, 1);
        return;
      }
      sprintf (Gqw.filename, "G(q,w) from %s (generalized density of states, Carpenter J Non Cryst Sol 92 (1987) 153)", Sqw_Data->filename);
      Gqw.block_number = 1;
      Gqw.min_x = 0;
      Gqw.max_x = Sqw_Data->q_max;
      Gqw.step_x = Sqw_Data->q_step;

      for (index_w = 0; index_w < Sqw_Data->w_bins; index_w++) {
        double w = -Sqw_Data->w_max + index_w * Sqw_Data->w_step; /* w value in Sqw_full */
        double gw = 0;
        for (index_q = 0; index_q < Sqw_Data->q_bins; index_q++) {
          double q = index_q * Sqw_Data->q_step; /* q value in Sqw_full ; q_min = 0 */
          double sqw_full = Table_Index (Sqw_Data->Sqw, index_q, index_w);
          double n = 1 / (exp (w / (Sqw->Temperature * Sqw->T2E)) - 1); /* Bose factor */
          double DW = q && u2 ? exp (2 * u2 * q * q / 6) : 1;           /* Debye-Weller factor */
          double gqw = q && n + 1 ? sqw_full * DW * 2 * (Sqw->mat_weight * Da) * w / (n + 1) / q / q : 0;
          if (!Table_SetElement (&Gqw, index_q, index_w, gqw))
            printf ("Isotropic_Sqw: %s: "
                    "Error when setting Gqw[%li q=%g,%li w=%g]=%g from file %s\n",
                    Sqw->compname, index_q, q, index_w, w, gqw, Sqw_Data->filename);
          gw += gqw;
          gqw_sum += gqw;
        }
        Table_SetElement (&Sqw_moments[6], index_w, 0, gw);
      }

      /* normalize the density of states */
      for (index_w = 0; index_w < Sqw_Data->w_bins; index_w++) {
        double gw = Table_Index (Sqw_moments[6], index_w, 0);
        Table_SetElement (&Sqw_moments[6], index_w, 0, gw / gqw_sum);
        for (index_q = 0; index_q < Sqw_Data->q_bins; index_q++) {
          double gqw = Table_Index (Gqw, index_q, index_w);
          Table_SetElement (&Gqw, index_q, index_w, gqw / gqw_sum);
        }
      }

      /* write Gqw and free memory */
      if (Sqw_Data->w_bins > 1) {
        sprintf (c, "%s_%s.gqw", Sqw->compname, Sqw_Data->type == 'c' ? "coh" : "inc");
        Table_Write (Gqw, c, "Momentum [Angs-1]", "'Generalized density of states' Energy [meV]", 0, Sqw_Data->q_max, -Sqw_Data->w_max, Sqw_Data->w_max);
        Table_Free (&Gqw);
      }
    } /* if T>0 */

    /* write all tables to disk M0=S(q) M1=E_r M3 w_c w_l M0_cl=S_cl(q) */
    if (Sqw_Data->w_bins > 1) {
      sprintf (c, "%s_%s.m1", Sqw->compname, Sqw_Data->type == 'c' ? "coh" : "inc");
      Table_Write (Sqw_moments[1], c, "Momentum [Angs-1]", "int w S(q,w) dw (recoil) q^2/2m [meV]", 0, Sqw_Data->q_max, 0, 0);
      sprintf (c, "%s_%s.w_l", Sqw->compname, Sqw_Data->type == 'c' ? "coh" : "inc");
      Table_Write (Sqw_moments[4], c, "Momentum [Angs-1]", "w_l(q) harmonic frequency [meV]", 0, Sqw_Data->q_max, 0, 0);
      sprintf (c, "%s_%s.sqw", Sqw->compname, Sqw_Data->type == 'c' ? "coh" : "inc");
      Table_Write (Sqw_Data->Sqw, c, "Momentum [Angs-1]", "'S(q,w) dynamical structure factor [meV-1]' Energy [meV]", 0, Sqw_Data->q_max, -Sqw_Data->w_max,
                   Sqw_Data->w_max);

      if (Sqw->Temperature > 0) {
        sprintf (c, "%s_%s.w_c", Sqw->compname, Sqw_Data->type == 'c' ? "coh" : "inc");
        Table_Write (Sqw_moments[3], c, "Momentum [Angs-1]", "w_c(q) collective excitation [meV]", 0, Sqw_Data->q_max, 0, 0);
        sprintf (c, "%s_%s_cl.sq", Sqw->compname, Sqw_Data->type == 'c' ? "coh" : "inc");
        Table_Write (Sqw_moments[5], c, "Momentum [Angs-1]", "int S_cl(q,w) dw", 0, Sqw_Data->q_max, 0, 0);
        sprintf (c, "%s_%s.gw", Sqw->compname, Sqw_Data->type == 'c' ? "coh" : "inc");
        Table_Write (Sqw_moments[6], c, "Energy [meV]", "'Generalized effective density of states' Energy [meV]", -Sqw_Data->w_max, Sqw_Data->w_max, 0, 0);
      }
    }
    sprintf (c, "%s_%s.sq", Sqw->compname, Sqw_Data->type == 'c' ? "coh" : "inc");
    Table_Write (Sqw_moments[0], c, "Momentum [Angs-1]", "S(q) = int S(q,w) dw", 0, Sqw_Data->q_max, 0, 0);
    sprintf (c, "%s_%s.sigma", Sqw->compname, Sqw_Data->type == 'c' ? "coh" : "inc");
    Table_Write (Sqw_Data->iqSq, c, "Energy [meV]", "sigma kf/ki int q S(q,w) dw scattering cross section [barns]", 0, 0, 0, 0);

    /* free Tables */
    for (index_q = 0; index_q < 7; Table_Free (&Sqw_moments[index_q++]))
      ;

  } /* Sqw_diagnosis */

  /*****************************************************************************
   * Sqw_readfile: Read Sqw data files
   *   Returns Sqw_Data_struct or NULL in case of error
   * Used in : Sqw_init (2)
   *****************************************************************************/
  struct Sqw_Data_struct*
  Sqw_readfile (struct Sqw_sample_struct* Sqw, char* file, struct Sqw_Data_struct* Sqw_Data) {

    t_Table* Table_Array = NULL;
    long nblocks = 0;
    char flag = 0;

    t_Table Sqw_full, iqSq; /* the Sqw (non symmetric) and total scattering X section */

    double sum = 0;
    double mat_at_nb = 1;
    double iq2Sq = 0;
    long* SW_lookup = NULL;
    long** QW_lookup = NULL;
    char** parsing = NULL;

    long index_q, index_w;
    double q_min_file, q_max_file, q_step_file;
    long q_bins_file;
    double w_min_file, w_max_file, w_step_file;
    long w_bins_file;
    double q_max, q_step;
    long q_bins;
    double w_max, w_step;
    long w_bins;

    double alpha = 0;

    double M1 = 0;
    double M1_cl = 0;
    double T = 0;
    double T_file = 0;
    long T_count = 0;
    long M1_count = 0;
    long M1_cl_count = 0;

    /* setup default */
    Sqw_Data_init (Sqw_Data);

    if (!file || !strlen (file) || !strcmp (file, "NULL") || !strcmp (file, "0"))
      return (Sqw_Data);
    /* read the Sqw file */
    Table_Array = Table_Read_Array (file, &nblocks);
    strncpy (Sqw_Data->filename, file, 80);
    if (!Table_Array)
      return (NULL);

    /* (1) parsing of header ================================================== */
    parsing = Table_ParseHeader (Table_Array[0].header, "Vc", "V_0", "sigma_abs", "sigma_a ", "sigma_inc", "sigma_i ", "column_j",                       /* 6 */
                                 "column_d", "column_F2", "column_DW", "column_Dd", "column_inv2d", "column_1/2d", "column_sintheta_lambda", "column_q", /* 14 */
                                 "sigma_coh", "sigma_c ", "Temperature", "column_Sq", "column_F ",                                                       /* 19 */
                                 "V_rho", "density", "weight", "nb_atoms", "multiplicity", "classical", NULL);
    if (parsing) {
      int i;
      if (parsing[0] && !Sqw->mat_rho)
        Sqw->mat_rho = 1 / atof (parsing[0]);
      if (parsing[1] && !Sqw->mat_rho)
        Sqw->mat_rho = 1 / atof (parsing[1]);
      if (parsing[2] && !Sqw->s_abs)
        Sqw->s_abs = atof (parsing[2]);
      if (parsing[3] && !Sqw->s_abs)
        Sqw->s_abs = atof (parsing[3]);
      if (parsing[4] && !Sqw->s_inc)
        Sqw->s_inc = atof (parsing[4]);
      if (parsing[5] && !Sqw->s_inc)
        Sqw->s_inc = atof (parsing[5]);
      if (parsing[6])
        Sqw->column_order[0] = atoi (parsing[6]);
      if (parsing[7])
        Sqw->column_order[1] = atoi (parsing[7]);
      if (parsing[8])
        Sqw->column_order[2] = atoi (parsing[8]);
      if (parsing[9])
        Sqw->column_order[3] = atoi (parsing[9]);
      if (parsing[10])
        Sqw->column_order[4] = atoi (parsing[10]);
      if (parsing[11])
        Sqw->column_order[5] = atoi (parsing[11]);
      if (parsing[12])
        Sqw->column_order[5] = atoi (parsing[12]);
      if (parsing[13])
        Sqw->column_order[5] = atoi (parsing[13]);
      if (parsing[14])
        Sqw->column_order[6] = atoi (parsing[14]);
      if (parsing[15] && !Sqw->s_coh)
        Sqw->s_coh = atof (parsing[15]);
      if (parsing[16] && !Sqw->s_coh)
        Sqw->s_coh = atof (parsing[16]);
      if (parsing[17] && !Sqw->Temperature)
        Sqw->Temperature = atof (parsing[17]); /* from user or file */
      if (parsing[17])
        T_file = atof (parsing[17]); /* from file */
      if (parsing[18])
        Sqw->column_order[8] = atoi (parsing[18]);
      if (parsing[19])
        Sqw->column_order[7] = atoi (parsing[19]);
      if (parsing[20] && !Sqw->mat_rho)
        Sqw->mat_rho = atof (parsing[20]);
      if (parsing[21] && !Sqw->mat_density)
        Sqw->mat_density = atof (parsing[21]);
      if (parsing[22] && !Sqw->mat_weight)
        Sqw->mat_weight = atof (parsing[22]);
      if (parsing[23])
        mat_at_nb = atof (parsing[23]);
      if (parsing[24])
        mat_at_nb = atof (parsing[24]);
      if (parsing[25]) { /* classical is found in the header */
        char* endptr;
        double value = strtod (parsing[25], &endptr);
        if (*endptr == *parsing[25]) {
          if (Sqw->sqw_classical < 0)
            Sqw->sqw_classical = 1;
        } else
          Sqw->sqw_classical = value;
      }
      for (i = 0; i <= 25; i++)
        if (parsing[i])
          free (parsing[i]);
      free (parsing);
    }

    /* compute the scattering unit density from material weight and density */
    /* the weight of the scattering element is the chemical formula molecular weight
     * times the nb of chemical formulae in the scattering element (nb_atoms) */
    if (!Sqw->mat_rho && Sqw->mat_density > 0 && Sqw->mat_weight > 0 && mat_at_nb > 0) {
      /* molar volume [cm^3/mol] = weight [g/mol] / density [g/cm^3] */
      /* atom density per Angs^3 = [mol/cm^3] * N_Avogadro *(1e-8)^3 */
      Sqw->mat_rho = Sqw->mat_density / (Sqw->mat_weight * mat_at_nb) / 1e24 * NA;
      MPI_MASTER (if (Sqw->verbose_output > 0)
                      printf ("Isotropic_Sqw: %s: Computing scattering unit density V_rho=%g [AA^-3] from density=%g [g/cm^3] weight=%g [g/mol].\n",
                              Sqw->compname, Sqw->mat_rho, Sqw->mat_density, Sqw->mat_weight););
    }

    /* the scattering unit cross sections are the chemical formula ones
     * times the nb of chemical formulae in the scattering element */
    if (mat_at_nb > 0) {
      Sqw->s_abs *= mat_at_nb;
      Sqw->s_inc *= mat_at_nb;
      Sqw->s_coh *= mat_at_nb;
    }

    if (nblocks) {
      if (nblocks == 1) {
        /* import Powder file */
        t_Table* newTable = NULL;
        newTable = Sqw_read_PowderN (Sqw, Table_Array[0]);
        if (!newTable) {
          MPI_MASTER (printf ("Isotropic_Sqw: %s: ERROR importing powder line file %s.\n"
                              "               Check format definition.\n",
                              Sqw->compname, file););
          exit (-1);
        } else
          flag = 0;
        Table_Free_Array (Table_Array);
        Table_Array = newTable;
      } else if (nblocks != 3) {
        MPI_MASTER (printf ("Isotropic_Sqw: %s: ERROR "
                            "File %s contains %li block%s instead of 3.\n",
                            Sqw->compname, file, nblocks, (nblocks == 1 ? "" : "s")););
      } else {
        flag = 0;
        Sqw->barns = 0; /* Sqw files do not use powder_barns */
      }
    }

    /* print some info about Sqw files */
    if (flag)
      Sqw->verbose_output = 2;

    if (flag) {
      MPI_MASTER (if (nblocks) printf ("ERROR          Wrong file format.\n"
                                       "               Disabling contribution.\n"
                                       "               File must contain 3 blocks for [q,w,sqw] or Powder file (1 block, laz,lau).\n"););
      return (Sqw_Data);
    }

    sprintf (Table_Array[0].filename, "%s#q", file);
    sprintf (Table_Array[1].filename, "%s#w", file);
    sprintf (Table_Array[2].filename, "%s#sqw", file);

    MPI_MASTER (if (nblocks && Sqw->verbose_output > 2) {
      printf ("Isotropic_Sqw: %s file read, analysing...\n", file);
      Table_Info_Array (Table_Array);
    });

    /* (2) compute range for full +/- w and allocate S(q,w) =================== */

    /* get the q,w extend of the table from the file */
    q_bins_file = Table_Array[0].rows * Table_Array[0].columns;
    w_bins_file = Table_Array[1].rows * Table_Array[1].columns;

    /* is there enough qw data in file to proceed ? */
    if (q_bins_file <= 1 || w_bins_file <= 0) {
      MPI_MASTER (printf ("Isotropic_Sqw: %s: Data file %s has incomplete q or omega information (%lix%li).\n"
                          "ERROR          Exiting.\n",
                          Sqw->compname, file, q_bins_file, w_bins_file););
      return (Sqw_Data);
    }

    q_min_file = Table_Array[0].min_x;
    q_max_file = Table_Array[0].max_x;
    q_step_file = Table_Array[0].step_x ? Table_Array[0].step_x : (q_max_file - q_min_file) / (Table_Array[0].rows * Table_Array[0].columns);
    w_min_file = Table_Array[1].min_x;
    w_max_file = Table_Array[1].max_x;
    w_step_file = Table_Array[1].step_x;

    /* create a regular extended q,w and Sqw tables applying the exp(-hw/kT) factor */
    q_max = q_max_file;
    q_bins = (q_step_file ? q_max / q_step_file : q_bins_file) + 1;
    q_step = q_bins - 1 > 0 ? q_max / (q_bins - 1) : 1;
    w_max = fabs (w_max_file);
    if (fabs (w_min_file) > fabs (w_max_file))
      w_max = fabs (w_min_file);
    /* w_min =-w_max */
    w_bins = (w_step_file ? (long)(2 * w_max / w_step_file) : 0) + 1; /* twice the initial w range */
    w_step = w_bins - 1 > 0 ? 2 * w_max / (w_bins - 1) : 1;           /* that is +/- w_max         */

    /* create the Sqw table in full range */
    if (!Table_Init (&Sqw_full, q_bins, w_bins)) {
      printf ("Isotropic_Sqw: %s: Cannot allocate Sqw_full Table (%lix%li).\n"
              "ERROR          Exiting.\n",
              Sqw->compname, q_bins, w_bins);
      return (NULL);
    }
    sprintf (Sqw_full.filename, "S(q,w) from %s (dynamic structure factor)", file);
    Sqw_full.block_number = 1;

    Sqw_Data->q_bins = q_bins;
    Sqw_Data->q_max = q_max;
    Sqw_Data->q_step = q_step;
    Sqw_Data->w_bins = w_bins;
    Sqw_Data->w_max = w_max;
    Sqw_Data->w_step = w_step;
    Sqw_Data->q_min_file = q_min_file;

    /* build an energy symmetric Sqw data set with detailed balance there-in, so
     * that we can both compute effective scattering Xsection, probability distributions
     * that is S(q) and \int q S(q).
     * We scan the new Sqw table elements with regular qw binning and search for their
     * equivalent element in the Sqw file data set. This is slower than doing the opposite.
     * We could be scanning all file elements, and fill the new table, but in the
     * process some empty spaces may appear when the initial file binning is not regular
     * in qw, leading to gaps in the new table.
     */

    /* (3) we build q and w lookup table for conversion file -> sqw_full ====== */
    MPI_MASTER (if (Sqw->verbose_output > 2)
                    printf ("Isotropic_Sqw: %s: Creating Sqw_full... (%s, %s)\n", Sqw->compname, file, Sqw->type == 'c' ? "coh" : "inc"););

    double* w_file2full = malloc (w_bins * sizeof (double)); /* lookup table for fast file -> Sqw_full allocation */
    if (!w_file2full) {
      fprintf (stderr, "Isotropic_Sqw: Catastrophic Error allocating lookup table w_file2full!\nEXIT\n");
      exit (-1);
    }

    for (index_w = 0; index_w < w_bins; w_file2full[index_w++] = 0)
      ;

    for (index_w = 0; index_w < w_bins; index_w++) {

      double w = -w_max + index_w * w_step; /* w value in Sqw_full */
      double index_w_file = 0;              /* w index in Sqw file */
      char found = 0;
      for (index_w_file = 0; index_w_file < w_bins_file; index_w_file++) {
        double w0 = Table_Index (Table_Array[1], (long)index_w_file, 0);
        double w1 = Table_Index (Table_Array[1], (long)index_w_file + 1, 0);
        /* test if we are in Stokes */
        if (w0 > w1) {
          double tmp = w0;
          w0 = w1;
          w1 = tmp;
        }
        if (w0 <= w && w < w1) {
          /* w ~ w_file exists in file, usually on w > 0 side Stokes, neutron looses energy */
          index_w_file += w1 - w0 ? (w - w0) / (w1 - w0) : 0; /* may correspond with a position in-betwwen two w elements */
          found = 1;
          break;
        }
      }
      /* test if we are in anti-Stokes */
      if (!found)
        for (index_w_file = 0; index_w_file < w_bins_file; index_w_file++) {
          double w0 = Table_Index (Table_Array[1], (long)index_w_file, 0);
          double w1 = Table_Index (Table_Array[1], (long)index_w_file + 1, 0);
          /* test if we are in anti-Stokes */
          if (w0 > w1) {
            double tmp = w0;
            w0 = w1;
            w1 = tmp;
          }
          if (w0 <= -w && -w < w1) { /* w value is mirrored from the opposite side in file */
            index_w_file += w1 - w0 ? (-w - w0) / (w1 - w0) : 0;
            index_w_file = -index_w_file; /* in this case, index value is set to negative */
            break;
          }
        }
      w_file2full[index_w] = index_w_file;
    }

    double* q_file2full = malloc (q_bins * sizeof (double));
    if (!q_file2full) {
      fprintf (stderr, "Isotropic_Sqw: Catastrophic Error allocating lookup table q_file2full!\nEXIT\n");
      exit (-1);
    }
    for (index_q = 0; index_q < q_bins; q_file2full[index_q++] = 0)
      ;

    for (index_q = 0; index_q < q_bins; index_q++) {

      double q = index_q * q_step; /* q value in Sqw_full ; q_min = 0 */
      double index_q_file = 0;     /* q index in Sqw file */

      /* search for q value in the initial file data set */
      if (q <= q_min_file)
        index_q_file = 0;
      else if (q >= q_max_file)
        index_q_file = q_bins_file - 1;
      else
        for (index_q_file = 0; index_q_file < q_bins_file; index_q_file++) {
          double q0 = Table_Index (Table_Array[0], (long)index_q_file, 0);
          double q1 = Table_Index (Table_Array[0], (long)index_q_file + 1, 0);
          if (q0 <= q && q <= q1) {
            index_q_file += q1 - q0 ? (q - q0) / (q1 - q0) : 0; /* may correspond with a position in-betwwen two q elements */
            break;
          }
        }
      q_file2full[index_q] = index_q_file;
    }

    /* (4) now we build Sqw on full Q,W ranges, using the Q,W table lookup above -> Sqw_full */
    for (index_q = 0; index_q < q_bins; index_q++) {

      double q = index_q * q_step; /* q value in Sqw_full ; q_min = 0 */
      double index_q_file = 0;     /* q index in Sqw file */

      /* get q value in the initial file data set */
      index_q_file = q_file2full[index_q];

      /* now scan energy elements in Sqw full, and search these in file data */
      for (index_w = 0; index_w < w_bins; index_w++) {
        double w = -w_max + index_w * w_step; /* w value in Sqw_full */
        double index_w_file = 0;              /* w index in Sqw file */
        double sqw_file = 0;                  /* Sqw(index_q, index_w) value interpolated from file */

        /* search for w value in the file data set, negative when mirrored */
        index_w_file = w_file2full[index_w];
        /* get Sqw_file element, with bi-linear interpolation from file */
        /* when the initial file does not contain the energy, the opposite element (-w) is used */
        sqw_file = Table_Value2d (Table_Array[2], index_q_file, fabs (index_w_file));
        /* apply the minimum threshold to remove noisy background in S(q,w) */
        if (sqw_file < Sqw->sqw_threshold)
          sqw_file = 0;
        else if (index_w_file < 0)
          sqw_file = -sqw_file; /* negative == mirrored from other side */

        if (!Table_SetElement (&Sqw_full, index_q, index_w, sqw_file))
          printf ("Isotropic_Sqw: %s: "
                  "Error when setting Sqw[%li q=%g,%li w=%g]=%g from file %s\n",
                  Sqw->compname, index_q, q, index_w, w, fabs (sqw_file), file);
      } /* for index_w */
    } /* for index_q */

    /* free memory and store limits for new full Sqw table */
    Table_Free_Array (Table_Array);

    /* if only one S(q,w) side is given, it is symmetrised by mirroring, then M1=0 */

    /* (5) test if the Sqw_full is classical or not by computing the 1st moment (=0 for classical) */
    /* also compute temperature (quantum case) from file if not set */
    for (index_q = 0; index_q < q_bins; index_q++) {

      double q = index_q * q_step; /* q value in Sqw_full ; q_min = 0 */

      for (index_w = 0; index_w < w_bins; index_w++) {
        double w = -w_max + index_w * w_step; /* w value in Sqw_full */
        double sqw_full = Table_Index (Sqw_full, index_q, index_w);
        long index_mw = w_bins - 1 - index_w; /* opposite w index in S(q,w) */
        double sqw_opp = Table_Index (Sqw_full, index_q, index_mw);
        double T_defined = T_file ? T_file : Sqw->Temperature; /* T better from file, else from user */

        /* the analysis must be done only on values which exist on both sides */
        /* as integrals must be symmetric, and Bose factor requires both sides as well */
        if (sqw_full > 0 && sqw_opp > 0) {
          /* compute temperature from Bose factor */
          if (sqw_opp != sqw_full) {
            T += fabs (w / log (sqw_opp / sqw_full) / Sqw->T2E);
            T_count++;
          }
          /* we first assume Sqw is quantum. M1_cl should be 0, M1 should be recoil */
          M1 += w * sqw_full * w_step;
          M1_count++;
          /* we assume it is quantum (non symmetric) and check that its symmetrized version has M1_cl=0 */
          if (T_defined > 0) {
            sqw_opp = sqw_full * Sqw_quantum_correction (-w, T_defined, Sqw->Q_correction); /* Sqw_cl */
            M1_cl += w * sqw_opp * w_step;
            M1_cl_count++;
          } else if (Sqw->mat_weight) {
            /* T=0 ? would compute the M1_cl = M1 - recoil energy, assuming we have a quantum S(q,w) in file */
            /* the M1(quantum) = (MNEUTRON/m)*2.0725*q^2 recoil energy */
            double Da = 1.660538921e-27;                                    /* atomic mass unit */
            double Er = (MNEUTRON / Sqw->mat_weight / Da) * 2.0725 * q * q; /* recoil for one scattering unit in the cell [meV] Schober JDN16 p239 */
            M1_cl += M1 - Er;
            M1_cl_count++;
          }
        } /* both side from file */
      } /*index_w */
    } /*index_q */

    if (T_count)
      T /= T_count; /* mean temperature from Bose ratio */
    if (M1_count)
      M1 /= M1_count;
    if (M1_cl_count)
      M1_cl /= M1_cl_count; /* mean energy value along q range */

    /* determine if we use a classical or quantum S(q,w) */
    if (Sqw->sqw_classical < 0) {
      if (fabs (M1) < 2 * w_step) {
        Sqw->sqw_classical = 1; /* the initial Sqw from file seems to be centered, thus classical */
      } else if (fabs (M1_cl) < fabs (M1)) {
        /* M1 for classical is closer to 0 than for quantum one */
        Sqw->sqw_classical = 0; /* initial data from file seems to be quantum (non classical) */
      } else {                  /* M1_cl > M1 > 2*w_step */
        MPI_MASTER (printf ("Isotropic_Sqw: %s: I do not know if S(q,w) data is classical or quantum.\n"
                            "WARNING        First moment M1=%g M1_cl=%g for file %s. Defaulting to classical case.\n",
                            Sqw->compname, M1, M1_cl, file););
      }
    }
    if (Sqw->sqw_classical < 0)
      Sqw->sqw_classical = 1; /* default when quantum/classical choice is not set */

    /* (5b) set temperature. Temperatures defined are:
     *   T_file:           temperature read from the .sqw file
     *   T:                temperature computed from the quantum Sqw using detailed balance
     *   Sqw->Temperature: temperature defined by user, or read from file when not set
     */

    /* display some warnings about the computed temperature */
    if (T > 3000)
      T = 0; /* unrealistic */
    if (!T_file && T) {
      MPI_MASTER (
        if (Sqw->verbose_output > 0) {
	  printf ("Isotropic_Sqw: %s: Temperature computed from S(q,w) data from %s is T=%g [K].\n", Sqw->compname, file, T);
	}
      );
    }

    if (Sqw->Temperature == 0) {
      Sqw->Temperature = T_file ? T_file : T; /* 0:  not set: we use file value, else computed */
    } else if (Sqw->Temperature == -1) {
      Sqw->Temperature = 0; /* -1: no detailed balance. Display message at end of INIT */
    } else if (Sqw->Temperature == -2) {
      Sqw->Temperature = T ? T : T_file; /* -2: use guessed value when available */
    } /* else let value as it is (e.g. >0) */

    if (Sqw->verbose_output > 0 && Sqw->Temperature) {
      MPI_MASTER (printf ("Isotropic_Sqw: %s: Temperature set to T=%g [K]\n", Sqw->compname, Sqw->Temperature););
    }

    MPI_MASTER (if (Sqw->verbose_output > 0 && w_bins > 1)
                    printf ("Isotropic_Sqw: %s: S(q,w) data from %s (%s) assumed to be %s.\n", Sqw->compname, file, Sqw->type == 'c' ? "coh" : "inc",
                            Sqw->sqw_classical ? "classical (symmetrised in energy)" : "non-classical (includes Bose factor, non symmetric in energy)"););

    /* (6) apply detailed balance on Sqw_full for classical or quantum S(q,w) */
    /* compute the \int q^2 S(q) for normalisation */

    MPI_MASTER (if (Sqw->sqw_classical && Sqw->verbose_output > 0 && Sqw->Temperature > 0)
                    printf ("Isotropic_Sqw: %s: Applying exp(hw/2kT) factor with T=%g [K] on %s file (classical/symmetric) using '%s' quantum correction\n",
                            Sqw->compname, Sqw->Temperature, file, Sqw->Q_correction););
    for (index_q = 0; index_q < q_bins; index_q++) {
      double sq = 0;
      double q = index_q * q_step; /* q value in Sqw_full ; q_min = 0 */
      for (index_w = 0; index_w < w_bins; index_w++) {
        double w = -w_max + index_w * w_step; /* w value in Sqw_full */
        double balance = 1;                   /* detailed balance factor, default is 1 */
        double sqw_full = Table_Index (Sqw_full, index_q, index_w);

        /* do we use a symmetric S(q,w) from real G(r,t) from e.g. MD ? */

        if (Sqw->sqw_classical && Sqw->Temperature > 0) /* data is symmetric, we apply Bose factor */
          /* un-symmetrize Sqw(file) * exp(hw/kT/2) on both sides */
          balance = Sqw_quantum_correction (w, Sqw->Temperature, Sqw->Q_correction);
        else if (!Sqw->sqw_classical) { /* data is quantum (contains Bose) */
          if (sqw_full < 0) {           /* quantum but mirrored/symmetric value (was missing in file) */
            if (T)
              /* prefer to use T computed from file for mirroring */
              balance *= exp (w / (T * Sqw->T2E)); /* apply Bose where missing */
            else if (Sqw->Temperature)
              balance *= exp (w / (Sqw->Temperature * Sqw->T2E)); /* apply Bose where missing */
          }
          /* test if T computed from file matches requested T, else apply correction */
          if (T && Sqw->Temperature > 0 && Sqw->Temperature != T) {
            balance *= exp (-w / (T * Sqw->T2E) / 2);               /* make it a classical data set: remove computed/read T from quantum data file */
            balance *= exp (w / (Sqw->Temperature * Sqw->T2E) / 2); /* then apply Bose to requested temperature */
          }
        }

        /* update Sqw value */
        sqw_full = fabs (sqw_full) * balance;
        Table_SetElement (&Sqw_full, index_q, index_w, sqw_full);
        /* sum up the S(q) (0-th moment) = w0 */
        sq += sqw_full;
      } /* index_w */
      sq *= w_step;                 /* S(q)  = \int S(q,w) dw    = structure factor */
      iq2Sq += q * q * sq * q_step; /* iq2Sq = \int q^2 S(q) dq  = used for g-sum rule (normalisation) */
      sum += sq * q_step;           /* |S|   = \int S(q,w) dq dw = total integral value in file */
    } /* index_q */

    if (!sum) {
      MPI_MASTER (printf ("Isotropic_Sqw: %s: No valid data in the selected (Q,w) range: sum(S)=0\n"
                          "ERROR          Available Sqw data is\n",
                          Sqw->compname);
                  printf ("                 q=[%g:%g] w=[%g:%g]\n", q_min_file, q_max_file, w_min_file, w_max_file););
      Table_Free (&Sqw_full);
      return (NULL);
    }

    /* norm S(q ,w) = sum(S)*q_range/q_bins on total q,w range from file */
    sum *= (q_max_file - q_min_file) / q_bins_file;

    /* (7) renormalization of S(q,w) ========================================== */

    if (Sqw->sqw_norm > 0)
      alpha = Sqw->sqw_norm;
    else if (!Sqw->sqw_norm)
      alpha = 1;

    if (!alpha && iq2Sq) { /* compute theoretical |S| norm */
      /* Eq (2.44) from H.E. Fischer et al, Rep. Prog. Phys., 69 (2006) 233 */
      alpha = (q_max * q_max * q_max / 3 - (Sqw->type == 'c' ? 2 * PI * PI * Sqw->mat_rho : 0)) / iq2Sq;
    }

    if (alpha < 0) {
      MPI_MASTER (printf ("Isotropic_Sqw: %s: normalisation factor is negative. rho=%g [Angs^-3] may be too high.\n"
                          "WARNING        Disabling renormalization i.e. keeping initial S(q,w).\n",
                          Sqw->compname, Sqw->mat_rho););
      alpha = 0;
    }

    /* apply normalization on S(q,w) */
    if (alpha && alpha != 1) {
      sum *= alpha;
      for (index_q = 0; index_q < q_bins; index_q++) {
        for (index_w = 0; index_w < w_bins; index_w++)
          Table_SetElement (&Sqw_full, index_q, index_w, Table_Index (Sqw_full, index_q, index_w) * alpha);
      }
    }

    Sqw_Data->intensity = sum;

    Table_Stat (&Sqw_full);
    Sqw_full.min_x = 0;
    Sqw_full.max_x = q_max;
    Sqw_full.step_x = q_step;

    MPI_MASTER (if (Sqw->verbose_output > 0) {
      printf ("Isotropic_Sqw: %s: Generated %s %scoherent Sqw\n"
              "                   q=[%g:%g Angs-1] w=[%g:%g meV] |S|=%g size=[%lix%li] sigma=%g [barns]\n",
              Sqw->compname, file, (Sqw->type == 'i' ? "in" : ""), q_min_file, q_max_file, w_min_file, w_max_file, Sqw_Data->intensity, q_bins, Sqw_Data->w_bins,
              (Sqw->type == 'i' ? Sqw->s_inc : Sqw->s_coh));
      if (w_max < 1e-2)
        printf ("               Mainly elastic scattering.\n");
      if (Sqw->sqw_norm > 0 && Sqw->sqw_norm != 1)
        printf ("                   normalization factor S(q,w)*%g (user)\n", alpha);
      else if (Sqw->sqw_norm < 0)
        printf ("                   normalization factor S(q,w)*%g (auto) \\int q^2 S(q) dq=%g\n", alpha, iq2Sq);
    });

    /* (8) Compute total cross section ======================================== */

    /* now compute the effective total cross section  (Sqw_integrate_iqSq)
          sigma(Ei) = sigma/2/Ki^2 * \int q S(q,w) dw dq
     * for each incoming neutron energy 0 < Ei < 2*w_max, and
     * integration range w=-Ei:w_max and q=Q0:Q1 with
     *   Q0 = SE2Q*(sqrt(E)-sqrt(E+w))
     *   Q1 = SE2Q*(sqrt(E)+sqrt(E+w))
     */

    Sqw_Data->lookup_length = Sqw->lookup_length;
    Sqw_Data->iqSq_length = Sqw->lookup_length;
    /* this length should be greater when w_max=0 for e.g. elastic only */
    if (w_bins <= 1)
      Sqw_Data->iqSq_length = q_bins;

    if (!Table_Init (&iqSq, Sqw_Data->iqSq_length, 1)) {
      /* from 0 to 2*Ki_max */
      printf ("Isotropic_Sqw: %s: Cannot allocate [int q S(q,w) dq dw] array (%li bytes).\n"
              "ERROR          Exiting.\n",
              Sqw->compname, Sqw->lookup_length * sizeof (double));
      Table_Free (&Sqw_full);
      return (NULL);
    }

    /* compute the maximum incoming energy that can be handled */
    Sqw_Data->Ei_max = 2 * w_max;

    /* Checked in different ways in Powder and "proper inelastic" case */
    if (w_step == 1) {
      /* Powder */
      double Ei_max_q = (q_max * K2V) * (q_max * K2V) * VS2E / 2;
      if (Ei_max_q > Sqw_Data->Ei_max)
        Sqw_Data->Ei_max = Ei_max_q;
    } else {
      /* Proper inelastic */
      /* check if the q-range will limit the integration */
      if ((q_max * K2V) * (q_max * K2V) * VS2E / 2 > Sqw_Data->Ei_max) {
        /* then scan Ei until we pass q_max */
        for (index_w = 0; index_w < Sqw_Data->iqSq_length; index_w++) {
          double Ei = index_w * 2 * w_max / Sqw_Data->iqSq_length;
          if ((Ei > w_max && sqrt (Ei) + sqrt (Ei - w_max) >= q_max / (SE2V * V2K)) || sqrt (Ei) + sqrt (Ei + w_max) >= q_max / (SE2V * V2K))
            if (Ei < Sqw_Data->Ei_max) {
              Sqw_Data->Ei_max = Ei;
              break;
            }
        }
      }
    }

    MPI_MASTER (if (Sqw->verbose_output >= 2) printf ("Isotropic_Sqw: %s: Creating Sigma(Ei=0:%g [meV]) with %li entries...(%s %s)\n", Sqw->compname,
                                                      Sqw_Data->Ei_max, Sqw_Data->iqSq_length, file, Sqw->type == 'c' ? "coh" : "inc"););
    Sqw_Data->Sqw = Sqw_full; /* store the S(q,w) Table (matrix) for Sqw_integrate_iqSq */

    /* this loop takes time: use MPI when available */

    for (index_w = 0; index_w < Sqw_Data->iqSq_length; index_w++) {

      /* Ei = energy of incoming neutron, typically 0:w_max or 0:2*q_max */
      double Ei; /* neutron energy value in Sqw_full, up to 2*w_max */
      double Ki, Vi;
      double Sigma = 0;
      Ei = index_w * Sqw_Data->Ei_max / Sqw_Data->iqSq_length;
      Vi = sqrt (Ei / VS2E);
      Ki = V2K * Vi;
      /* sigma(Ei) = sigma/2/Ki^2 * \int q S(q,w) dq dw */
      /* Eq (6) from E. Farhi et al. J. Comp. Phys. 228 (2009) 5251 */
      Sigma = Ki <= 0 ? 0 : (Sqw->type == 'c' ? Sqw->s_coh : Sqw->s_inc) / 2 / Ki / Ki * Sqw_integrate_iqSq (Sqw_Data, Ei);
      Table_SetElement (&iqSq, index_w, 0, Sigma);
    }

    sprintf (iqSq.filename, "[sigma/2Ki^2 int q S(q,w) dq dw] from %s", file);
    iqSq.min_x = 0;
    iqSq.max_x = Sqw_Data->Ei_max;
    iqSq.step_x = Sqw_Data->Ei_max / Sqw_Data->iqSq_length;
    iqSq.block_number = 1;

    Sqw_Data->iqSq = iqSq; /* store the sigma(Ei) = \int q S(q,w) dq dw Table (vector) */

    /* (9) Compute P(w) probability =========================================== */

    /* set up 'density of states' */
    /* uses: Sqw_full and w axes */
    Sqw_Data->SW = (struct Sqw_W_struct*)calloc (w_bins, sizeof (struct Sqw_W_struct));

    if (!Sqw_Data->SW) {
      printf ("Isotropic_Sqw: %s: Cannot allocate SW (%li bytes).\n"
              "ERROR          Exiting.\n",
              Sqw->compname, w_bins * sizeof (struct Sqw_W_struct));
      Table_Free (&Sqw_full);
      Table_Free (&iqSq);
      return (NULL);
    }
    sum = 0;
    for (index_w = 0; index_w < w_bins; index_w++) {
      double local_val = 0;
      double w = -w_max + index_w * w_step;
      for (index_q = 0; index_q < q_bins; index_q++) {                                     /* integrate on all q values */
        local_val += Table_Index (Sqw_full, index_q, index_w) * q_step * index_q * q_step; /* q*S(q,w) */
      }
      Sqw_Data->SW[index_w].omega = w;
      sum += local_val; /* S(w)=\int S(q,w) dq */
      /* compute cumulated probability */
      Sqw_Data->SW[index_w].cumul_proba = local_val;
      if (index_w)
        Sqw_Data->SW[index_w].cumul_proba += Sqw_Data->SW[index_w - 1].cumul_proba;
      else
        Sqw_Data->SW[index_w].cumul_proba = 0;
    }

    if (!sum) {
      MPI_MASTER (printf ("Isotropic_Sqw: %s: Total S(q,w) intensity is NULL.\n"
                          "ERROR          Exiting.\n",
                          Sqw->compname););
      Table_Free (&Sqw_full);
      Table_Free (&iqSq);
      return (NULL);
    }

    /* normalize Pw distribution to 0:1 range */
    for (index_w = 0; index_w < w_bins; index_w++) {
      Sqw_Data->SW[index_w].cumul_proba /= Sqw_Data->SW[w_bins - 1].cumul_proba;
    }

    if (Sqw->verbose_output > 2) {
      MPI_MASTER (printf ("Isotropic_Sqw: %s: Generated normalized SW[%li] in range [0:%g]\n", Sqw->compname, w_bins, Sqw_Data->SW[w_bins - 1].cumul_proba););
    }

    /* (10) Compute P(Q|w) probability ======================================== */

    /* set up Q probability table per w bin */
    /* uses:  Sqw_full */
    Sqw_Data->SQW = (struct Sqw_Q_struct**)calloc (w_bins, sizeof (struct Sqw_Q_struct*));

    if (!Sqw_Data->SQW) {
      printf ("Isotropic_Sqw: %s: Cannot allocate P(Q|w) array (%li bytes).\n"
              "ERROR          Exiting.\n",
              Sqw->compname, w_bins * sizeof (struct Sqw_Q_struct*));
      Table_Free (&Sqw_full);
      Table_Free (&iqSq);
      return (NULL);
    }
    for (index_w = 0; index_w < w_bins; index_w++) {
      Sqw_Data->SQW[index_w] = (struct Sqw_Q_struct*)calloc (q_bins, sizeof (struct Sqw_Q_struct));

      if (!Sqw_Data->SQW[index_w]) {
        printf ("Isotropic_Sqw: %s: Cannot allocate P(Q|w)[%li] (%li bytes).\n"
                "ERROR          Exiting.\n",
                Sqw->compname, index_w, q_bins * sizeof (struct Sqw_Q_struct));
        Table_Free (&Sqw_full);
        Table_Free (&iqSq);
        return (NULL);
      }
      /* set P(Q|W) and compute total intensity */
      for (index_q = 0; index_q < q_bins; index_q++) {
        double q = index_q * q_step;
        Sqw_Data->SQW[index_w][index_q].Q = q;

        /* compute cumulated probability and take into account Jacobian with additional 'q' factor */
        Sqw_Data->SQW[index_w][index_q].cumul_proba = q * Table_Index (Sqw_full, index_q, index_w); /* q*S(q,w) */
        if (index_q)
          Sqw_Data->SQW[index_w][index_q].cumul_proba += Sqw_Data->SQW[index_w][index_q - 1].cumul_proba;
        else
          Sqw_Data->SQW[index_w][index_q].cumul_proba = 0;
      }
      /* normalize P(q|w) distribution to 0:1 range */
      for (index_q = 0; index_q < q_bins; Sqw_Data->SQW[index_w][index_q++].cumul_proba /= Sqw_Data->SQW[index_w][q_bins - 1].cumul_proba)
        ;
    }
    if (Sqw->verbose_output > 2) {
      MPI_MASTER (printf ("Isotropic_Sqw: %s: Generated P(Q|w)\n", Sqw->compname););
    }

    /* (11) generate quick lookup tables for SW and SQW ======================= */

    SW_lookup = (long*)calloc (Sqw->lookup_length, sizeof (long));

    if (!SW_lookup) {
      printf ("Isotropic_Sqw: %s: Cannot allocate SW_lookup (%li bytes).\n"
              "Warning        Will be slower.\n",
              Sqw->compname, Sqw->lookup_length * sizeof (long));
    } else {
      int i;
      for (i = 0; i < Sqw->lookup_length; i++) {
        double w = (double)i / (double)Sqw->lookup_length; /* a random number tabulated value */
        SW_lookup[i] = Sqw_search_SW (*Sqw_Data, w);
      }
      Sqw_Data->SW_lookup = SW_lookup;
    }
    QW_lookup = (long**)calloc (w_bins, sizeof (long*));

    if (!QW_lookup) {
      printf ("Isotropic_Sqw: %s: Cannot allocate QW_lookup (%li bytes).\n"
              "Warning        Will be slower.\n",
              Sqw->compname, w_bins * sizeof (long*));
    } else {
      for (index_w = 0; index_w < w_bins; index_w++) {
        QW_lookup[index_w] = (long*)calloc (Sqw->lookup_length, sizeof (long));
        if (!QW_lookup[index_w]) {
          printf ("Isotropic_Sqw: %s: Cannot allocate QW_lookup[%li] (%li bytes).\n"
                  "Warning        Will be slower.\n",
                  Sqw->compname, index_w, Sqw->lookup_length * sizeof (long));
          free (QW_lookup);
          Sqw_Data->QW_lookup = QW_lookup = NULL;
          break;
        } else {
          int i;
          for (i = 0; i < Sqw->lookup_length; i++) {
            double w = (double)i / (double)Sqw->lookup_length; /* a random number tabulated value */
            QW_lookup[index_w][i] = Sqw_search_Q_proba_per_w (*Sqw_Data, w, index_w);
          }
        }
      }
      Sqw_Data->QW_lookup = QW_lookup;
    }
    if ((Sqw_Data->QW_lookup || Sqw_Data->SW_lookup) && Sqw->verbose_output > 2) {
      MPI_MASTER (printf ("Isotropic_Sqw: %s: Generated lookup tables with %li entries\n", Sqw->compname, Sqw->lookup_length););
    }
    free (w_file2full);
    free (q_file2full);
    return (Sqw_Data);
  } /* end Sqw_readfile */

  /*****************************************************************************
   * Sqw_init_read: Read coherent/incoherent Sqw data files
   *   Returns Sqw total intensity, or 0 (error)
   * Used in : INITIALIZE (1)
   *****************************************************************************/
  double
  Sqw_init (struct Sqw_sample_struct* Sqw, char* file_coh, char* file_inc) {
    double ret = 0;

    /* read files */
    struct Sqw_Data_struct *d_inc, *d_coh;
    Sqw->type = 'i';
    d_inc = Sqw_readfile (Sqw, file_inc, &(Sqw->Data_inc));
    Sqw->type = 'c';
    d_coh = Sqw_readfile (Sqw, file_coh, &(Sqw->Data_coh));

    if (d_inc && !d_inc->intensity && Sqw->s_inc > 0) {
      MPI_MASTER (if (Sqw->verbose_output > 0)
                      printf ("Isotropic_Sqw: %s: Using Isotropic elastic incoherent scattering (sigma=%g [barns])\n", Sqw->compname, Sqw->s_inc););
      ret = 1;
    }

    if (!d_inc || !d_coh)
      return (0);

    d_coh->type = 'c';
    Sqw->Data_inc.type = 'i';
    MPI_MASTER (if (d_coh && !d_coh->intensity && Sqw->s_coh) printf ("Isotropic_Sqw: %s: Coherent scattering Sqw intensity is null.\n"
                                                                      "Warning        Disabling coherent scattering.\n",
                                                                      Sqw->compname););
    if (d_inc && d_coh && d_inc->intensity && d_coh->intensity) {
      char msg[80];
      strcpy (msg, "");
      /* check dimensions/limits for Q, Energy in coh and inc Tables */
      if (d_inc->q_bins != d_coh->q_bins)
        strcpy (msg, "Q axis size");
      if (d_inc->w_bins != d_coh->w_bins)
        strcpy (msg, "Energy axis size");
      if (d_inc->q_max != d_coh->q_max)
        strcpy (msg, "Q axis limits");
      if (d_inc->w_max != d_coh->w_max)
        strcpy (msg, "Energy axis limits");
      MPI_MASTER (if (strlen (msg)) {
        printf ("Isotropic_Sqw: %s: Sqw data from files %s and %s do not match\n"
                "WARNING        wrong %s\n",
                Sqw->compname, file_coh, file_inc, msg);
      });
    }

    if (!ret)
      ret = d_inc->intensity + d_coh->intensity;
    return (ret);
  } /* Sqw_init */

  #endif /* definied ISOTROPIC_SQW */

/* Shared user declarations for all components types 'Monitor_nD'. */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2002, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/monitor_nd-lib.h
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Modified by: TW, Nov 2020: introduced user doubles
* Release: McStas 1.6
* Version: $Revision$
*
* This file is to be imported by the monitor_nd related components
* It handles some shared functions.
*
* Usage: within SHARE
* %include "monitor_nd-lib"
*
*******************************************************************************/

#ifndef MONITOR_ND_LIB_H

#define MONITOR_ND_LIB_H "$Revision$"
#define MONnD_COORD_NMAX  30  /* max number of variables to record */

  typedef struct MonitornD_Defines
  {
    int COORD_NONE  ;
    int COORD_X     ;
    int COORD_Y     ;
    int COORD_Z     ;
    int COORD_RADIUS; 
    int COORD_VX    ;
    int COORD_VY    ;
    int COORD_VZ    ;
    int COORD_V     ;
    int COORD_T     ;
    int COORD_P     ;
    int COORD_SX    ;
    int COORD_SY    ;
    int COORD_SZ    ;
    int COORD_KX    ;
    int COORD_KY    ;
    int COORD_KZ    ;
    int COORD_K     ;
    int COORD_ENERGY;
    int COORD_LAMBDA;
    int COORD_KXY   ;
    int COORD_KYZ   ;
    int COORD_KXZ   ;
    int COORD_VXY   ;
    int COORD_VYZ   ;
    int COORD_VXZ   ;
    int COORD_HDIV  ;
    int COORD_VDIV  ;
    int COORD_ANGLE ;
    int COORD_NCOUNT;
    int COORD_THETA ;
    int COORD_PHI   ;
    int COORD_USER1 ;
    int COORD_USER2 ;
    int COORD_USER3 ;
    int COORD_USERDOUBLE0 ;
    int COORD_USERDOUBLE1 ;
    int COORD_USERDOUBLE2 ;
    int COORD_USERDOUBLE3 ;
    int COORD_USERDOUBLE4 ;
    int COORD_USERDOUBLE5 ;
    int COORD_USERDOUBLE6 ;
    int COORD_USERDOUBLE7 ;
    int COORD_USERDOUBLE8 ;
    int COORD_USERDOUBLE9 ;
    int COORD_USERDOUBLE10 ;
    int COORD_USERDOUBLE11 ;
    int COORD_USERDOUBLE12 ;
    int COORD_USERDOUBLE13 ;
    int COORD_USERDOUBLE14 ;
    int COORD_USERDOUBLE15 ;
    int COORD_XY    ;
    int COORD_XZ    ;
    int COORD_YZ    ;
    int COORD_PIXELID;

    /* token modifiers */
    int COORD_VAR   ; /* next token should be a variable or normal option */
    int COORD_MIN   ; /* next token is a min value */
    int COORD_MAX   ; /* next token is a max value */
    int COORD_DIM   ; /* next token is a bin value */
    int COORD_FIL   ; /* next token is a filename */
    int COORD_EVNT  ; /* next token is a buffer size value */
    int COORD_3HE   ; /* next token is a 3He pressure value */
    int COORD_LOG   ; /* next variable will be in log scale */
    int COORD_ABS   ; /* next variable will be in abs scale */
    int COORD_SIGNAL; /* next variable will be the signal var */
    int COORD_AUTO  ; /* set auto limits */

    char TOKEN_DEL[32]; /* token separators */

    char SHAPE_SQUARE; /* shape of the monitor */
    char SHAPE_DISK  ;
    char SHAPE_SPHERE;
    char SHAPE_CYLIND;
    char SHAPE_BANANA; /* cylinder without top/bottom, on restricted angular area */
    char SHAPE_BOX   ;
    char SHAPE_PREVIOUS;
    char SHAPE_OFF;

  } MonitornD_Defines_type;

  typedef struct MonitornD_Variables
  {
    double area;
    double Sphere_Radius     ;
    double Cylinder_Height   ;
    char   Flag_With_Borders ;   /* 2 means xy borders too */
    char   Flag_List         ;   /* 1 store 1 buffer, 2 is list all, 3 list all+append */
    char   Flag_nexusbins    ;   /* Only relevant in NeXus mode. -1 fully disable, 0 store BINS arrays if list mode, 1 store always */
    char   Flag_Multiple     ;   /* 1 when n1D, 0 for 2D */
    char   Flag_Verbose      ;
    int    Flag_Shape        ;
    char   Flag_Auto_Limits  ;   /* get limits from first Buffer */
    char   Flag_Absorb       ;   /* monitor is also a slit */
    char   Flag_per_cm2      ;   /* flux is per cm2 */
    char   Flag_log          ;   /* log10 of the flux */
    char   Flag_parallel     ;   /* set neutron state back after detection (parallel components) */
    char   Flag_Binary_List  ;
    char   Flag_capture      ;   /* lambda monitor with lambda/lambda(2200m/s = 1.7985 Angs) weightening */
    int    Flag_signal       ;   /* 0:monitor p, else monitor a mean value */
    int    Flag_mantid       ;   /* 0:normal monitor, else do mantid-event specifics */
    int    Flag_OFF          ;   /* Flag to indicate external geometry from OFF file */
    long long OFF_polyidx;   /* When intersection is done externally by off_intersect, this gives the 
				    polygon number, i.e. pixel index */
    unsigned long Coord_Number      ;   /* total number of variables to monitor, plus intensity (0) */
    unsigned long Coord_NumberNoPixel;  /* same but without counting PixelID */
    unsigned long Buffer_Block      ;   /* Buffer size for list or auto limits */
    long long Neutron_Counter   ;   /* event counter, simulation total counts is mcget_ncount() */
    unsigned long Buffer_Counter    ;   /* index in Buffer size (for realloc) */
    unsigned long Buffer_Size       ;
    int    Coord_Type[MONnD_COORD_NMAX];      /* type of variable */
    char   Coord_Label[MONnD_COORD_NMAX][30]; /* label of variable */
    char   Coord_Var[MONnD_COORD_NMAX][30];   /* short id of variable */
    long   Coord_Bin[MONnD_COORD_NMAX];       /* bins of variable array */
    long   Coord_BinProd[MONnD_COORD_NMAX];   /* product of bins of variable array */
    double Coord_Min[MONnD_COORD_NMAX];
    double Coord_Max[MONnD_COORD_NMAX];
    char   Monitor_Label[MONnD_COORD_NMAX*30];/* Label for monitor */
    char   Mon_File[128];                     /* output file name */

    /* these don't seem to be used anymore as they are superseded by _particle
    double cx, cy, cz;
    double cvx, cvy, cvz;
    double ckx, cky, ckz;
    double csx, csy, csz;
    double cEx, cEy, cEz;
    double cs1, cs2, ct, cphi, cp; */

    double He3_pressure;
    char   Flag_UsePreMonitor    ;   /* use a previously stored neutron parameter set */
    char   UserName1[128];
    char   UserName2[128];
    char   UserName3[128];
    char   UserVariable1[128];
    char   UserVariable2[128];
    char   UserVariable3[128];
    double UserDoubles[16];
    char   option[CHAR_BUF_LENGTH];

    long long int Nsum;
    double psum, p2sum;
    double **Mon2D_N;
    double **Mon2D_p;
    double **Mon2D_p2;
    double *Mon2D_Buffer;
    unsigned long PixelID;

    double mxmin,mxmax,mymin,mymax,mzmin,mzmax;
    double mean_dx, mean_dy, min_x, min_y, max_x, max_y, mean_p;

    char   compcurname[128];
    Coords compcurpos;
    Rotation compcurrot;
    int compcurindex;
  } MonitornD_Variables_type;

/* monitor_nd-lib function prototypes */
/* ========================================================================= */

void Monitor_nD_Init(MonitornD_Defines_type *, MonitornD_Variables_type *, MCNUM, MCNUM, MCNUM, MCNUM, MCNUM, MCNUM, MCNUM, MCNUM, MCNUM, int, int);
#pragma acc routine
int Monitor_nD_Trace(MonitornD_Defines_type *, MonitornD_Variables_type *, _class_particle* _particle);
MCDETECTOR Monitor_nD_Save(MonitornD_Defines_type *, MonitornD_Variables_type *);
void Monitor_nD_Finally(MonitornD_Defines_type *, MonitornD_Variables_type *);
void Monitor_nD_McDisplay(MonitornD_Defines_type *, MonitornD_Variables_type *);

#endif

/* end of monitor_nd-lib.h */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2002, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/monitor_nd-lib.c
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Modified by: TW, Nov 2020: introduced user doubles
* Release: McStas 1.6
* Version: $Revision$
*
* This file is to be imported by the monitor_nd related components
* It handles some shared functions. Embedded within instrument in runtime mode.
*
* Usage: within SHARE
* %include "monitor_nd-lib"
*
*******************************************************************************/

#ifndef MONITOR_ND_LIB_H
#error McStas : please import this library with %include "monitor_nd-lib"
#endif

/* ========================================================================= */
/* Monitor_nD_Init: this routine is used to parse options                    */
/* ========================================================================= */

void Monitor_nD_Init(MonitornD_Defines_type *DEFS,
  MonitornD_Variables_type *Vars,
  MCNUM xwidth,
  MCNUM yheight,
  MCNUM zdepth,
  MCNUM xmin,
  MCNUM xmax,
  MCNUM ymin,
  MCNUM ymax,
  MCNUM zmin,
  MCNUM zmax,
  int offflag,
  int nexusbins)
  {
    long carg = 1;
    char *option_copy, *token;
    char Flag_New_token = 1;
    char Flag_End       = 1;
    char Flag_All       = 0;
    char Flag_No        = 0;
    char Flag_abs       = 0;
    int  Flag_auto      = 0;  /* -1: all, 1: the current variable */
    int  Set_Vars_Coord_Type;
    char Set_Vars_Coord_Label[64];
    char Set_Vars_Coord_Var[64];
    char Short_Label[MONnD_COORD_NMAX][64];
    int  Set_Coord_Mode;
    long i=0, j=0;
    double lmin, lmax, XY=0;
    long t;
    int N_spatial_dims=0;

    t = (long)time(NULL);

/* initialize DEFS */
/* Variables to monitor */
    DEFS->COORD_NONE   =0;
    DEFS->COORD_X      =1;
    DEFS->COORD_Y      =2;
    DEFS->COORD_Z      =3;
    DEFS->COORD_RADIUS =19;
    DEFS->COORD_VX     =4;
    DEFS->COORD_VY     =5;
    DEFS->COORD_VZ     =6;
    DEFS->COORD_V      =16;
    DEFS->COORD_T      =7;
    DEFS->COORD_P      =8;
    DEFS->COORD_SX     =9;
    DEFS->COORD_SY     =10;
    DEFS->COORD_SZ     =11;
    DEFS->COORD_KX     =12;
    DEFS->COORD_KY     =13;
    DEFS->COORD_KZ     =14;
    DEFS->COORD_K      =15;
    DEFS->COORD_ENERGY =17;
    DEFS->COORD_LAMBDA =18;
    DEFS->COORD_HDIV   =20;
    DEFS->COORD_VDIV   =21;
    DEFS->COORD_ANGLE  =22;
    DEFS->COORD_NCOUNT =23;
    DEFS->COORD_THETA  =24;
    DEFS->COORD_PHI    =25;
    DEFS->COORD_USER1  =26;
    DEFS->COORD_USER2  =27;
    DEFS->COORD_USER3  =28;
    DEFS->COORD_USERDOUBLE0=39;
    DEFS->COORD_USERDOUBLE1=40;
    DEFS->COORD_USERDOUBLE2=41;
    DEFS->COORD_USERDOUBLE3=42;
    DEFS->COORD_USERDOUBLE4=43;
    DEFS->COORD_USERDOUBLE5=44;
    DEFS->COORD_USERDOUBLE6=45;
    DEFS->COORD_USERDOUBLE7=46;
    DEFS->COORD_USERDOUBLE8=47;
    DEFS->COORD_USERDOUBLE9=48;
    DEFS->COORD_USERDOUBLE10=49;
    DEFS->COORD_USERDOUBLE11=50;
    DEFS->COORD_USERDOUBLE12=51;
    DEFS->COORD_USERDOUBLE13=52;
    DEFS->COORD_USERDOUBLE14=53;
    DEFS->COORD_USERDOUBLE15=54;
    DEFS->COORD_XY     =37;
    DEFS->COORD_YZ     =31;
    DEFS->COORD_XZ     =32;
    DEFS->COORD_VXY    =30;
    DEFS->COORD_VYZ    =34;
    DEFS->COORD_VXZ    =36;
    DEFS->COORD_KXY    =29;
    DEFS->COORD_KYZ    =33;
    DEFS->COORD_KXZ    =35;
    DEFS->COORD_PIXELID=38;

/* token modifiers */
    DEFS->COORD_VAR    =0;    /* next token should be a variable or normal option */
    DEFS->COORD_MIN    =1;    /* next token is a min value */
    DEFS->COORD_MAX    =2;    /* next token is a max value */
    DEFS->COORD_DIM    =3;    /* next token is a bin value */
    DEFS->COORD_FIL    =4;    /* next token is a filename */
    DEFS->COORD_EVNT   =5;    /* next token is a buffer size value */
    DEFS->COORD_3HE    =6;    /* next token is a 3He pressure value */
    DEFS->COORD_LOG    =64;   /* next variable will be in log scale */
    DEFS->COORD_ABS    =128;  /* next variable will be in abs scale */
    DEFS->COORD_SIGNAL =256;  /* next variable will be the signal var */
    DEFS->COORD_AUTO   =512;  /* set auto limits */

    strcpy(DEFS->TOKEN_DEL, " =,;[](){}:");  /* token separators */

    DEFS->SHAPE_SQUARE =0;    /* shape of the monitor */
    DEFS->SHAPE_DISK   =1;
    DEFS->SHAPE_SPHERE =2;
    DEFS->SHAPE_CYLIND =3;
    DEFS->SHAPE_BANANA =4;
    DEFS->SHAPE_BOX    =5;
    DEFS->SHAPE_PREVIOUS=6;
    DEFS->SHAPE_OFF=7;

    Vars->Sphere_Radius     = 0;
    Vars->Cylinder_Height   = 0;
    Vars->Flag_With_Borders = 0;   /* 2 means xy borders too */
    Vars->Flag_List         = 0;   /* 1=store 1 buffer, 2=list all, 3=re-use buffer */
    Vars->Flag_nexusbins    = 0;   /* NeXus only: -1=disable, 0=enable for list mode, 1=enable for all monitors */
                                   /*  (Actual control of variable happens in comp INIT) */
    Vars->Flag_Multiple     = 0;   /* 1 when n1D, 0 for 2D */
    Vars->Flag_Verbose      = 0;
    Vars->Flag_Shape        = DEFS->SHAPE_SQUARE;
    Vars->Flag_Auto_Limits  = 0;   /* get limits from first Buffer */
    Vars->Flag_Absorb       = 0;   /* monitor is also a slit */
    Vars->Flag_per_cm2      = 0;   /* flux is per cm2 */
    Vars->Flag_log          = 0;   /* log10 of the flux */
    Vars->Flag_parallel     = 0;   /* set neutron state back after detection (parallel components) */
    Vars->Flag_Binary_List  = 0;   /* save list as a binary file (smaller) */
    Vars->Coord_Number      = 0;   /* total number of variables to monitor, plus intensity (0) */
    Vars->Coord_NumberNoPixel=0;   /* same but without counting PixelID */

    Vars->Buffer_Block      = MONND_BUFSIZ;     /* Buffer size for list or auto limits */	
    Vars->Neutron_Counter   = 0;   /* event counter, simulation total counts is mcget_ncount() */
    Vars->Buffer_Counter    = 0;   /* index in Buffer size (for realloc) */
    Vars->Buffer_Size       = 0;
    Vars->He3_pressure      = 0;
    Vars->Flag_capture      = 0;
    Vars->Flag_signal       = DEFS->COORD_P;
    Vars->Flag_mantid       = 0;
    Vars->Flag_OFF          = offflag;
    Vars->OFF_polyidx       = -1;
    Vars->mean_dx=Vars->mean_dy=0;
    Vars->min_x = Vars->max_x  =0;
    Vars->min_y = Vars->max_y  =0;

    Set_Vars_Coord_Type = DEFS->COORD_NONE;
    Set_Coord_Mode = DEFS->COORD_VAR;

    /* handle size parameters */
    /* normal use is with xwidth, yheight, zdepth */
    /* if xmin,xmax,ymin,ymax,zmin,zmax are non 0, use them */
    if (fabs(xmin-xmax) == 0)
      { Vars->mxmin = -fabs(xwidth)/2; Vars->mxmax = fabs(xwidth)/2; }
    else
      { if (xmin < xmax) {Vars->mxmin = xmin; Vars->mxmax = xmax;}
        else {Vars->mxmin = xmax; Vars->mxmax = xmin;}
      }
    if (fabs(ymin-ymax) == 0)
      { Vars->mymin = -fabs(yheight)/2; Vars->mymax = fabs(yheight)/2; }
    else
      { if (ymin < ymax) {Vars->mymin = ymin; Vars->mymax = ymax;}
        else {Vars->mymin = ymax; Vars->mymax = ymin;}
      }
    if (fabs(zmin-zmax) == 0)
      { Vars->mzmin = -fabs(zdepth)/2; Vars->mzmax = fabs(zdepth)/2; }
    else
      { if (zmin < zmax) {Vars->mzmin = zmin; Vars->mzmax = zmax; }
        else {Vars->mzmin = zmax; Vars->mzmax = zmin; }
      }

    if (fabs(Vars->mzmax-Vars->mzmin) == 0)
      Vars->Flag_Shape        = DEFS->SHAPE_SQUARE;
    else
      Vars->Flag_Shape        = DEFS->SHAPE_BOX;

    if (Vars->Flag_OFF) {
      N_spatial_dims++;
      Vars->Flag_Shape        = DEFS->SHAPE_OFF;
    }
    
    /* parse option string */

    option_copy = (char*)malloc(strlen(Vars->option)+1);
    if (option_copy == NULL)
    {
      fprintf(stderr,"Monitor_nD: %s cannot allocate 'options' copy (%li). Fatal.\n", Vars->compcurname, (long)strlen(Vars->option));
      exit(-1);
    }

    if (strlen(Vars->option))
    {
      Flag_End = 0;
      strcpy(option_copy, Vars->option);
    }

    if (strstr(Vars->option, "cm2") || strstr(Vars->option, "cm^2")) Vars->Flag_per_cm2 = 1;

    if (strstr(Vars->option, "binary") || strstr(Vars->option, "float"))
      Vars->Flag_Binary_List  = 1;
    if (strstr(Vars->option, "double"))
      Vars->Flag_Binary_List  = 2;

    strcpy(Vars->Coord_Label[0],"Intensity");
    strncpy(Vars->Coord_Var[0],"p",30);
    Vars->Coord_Type[0] = DEFS->COORD_P;
    Vars->Coord_Bin[0] = 1;
    Vars->Coord_Min[0] = 0;
    Vars->Coord_Max[0] = FLT_MAX;

    /* default file name is comp_name+dateID */
    sprintf(Vars->Mon_File, "%s_%li", Vars->compcurname, t);

    carg = 1;
    while((Flag_End == 0) && (carg < 128))
    {
      if (Flag_New_token) /* retain previous token or get a new one */
      {
        if (carg == 1) token=(char *)strtok(option_copy,DEFS->TOKEN_DEL);
        else token=(char *)strtok(NULL,DEFS->TOKEN_DEL);
        if (token == NULL) Flag_End=1;
      }
      Flag_New_token = 1;
      if ((token != NULL) && (strlen(token) != 0))
      {
        char iskeyword=0; /* left at 0 when variables are processed, 1 for modifiers */
        int  old_Mode;
        /* change token to lower case */
        for (i=0; i<strlen(token); i++) token[i]=tolower(token[i]);
        /* first handle option values from preceeding keyword token detected */
        old_Mode = Set_Coord_Mode;
        if (Set_Coord_Mode == DEFS->COORD_MAX)  /* max=%i */
        {
          if (!Flag_All)
            Vars->Coord_Max[Vars->Coord_Number] = atof(token);
          else
            for (i = 0; i <= Vars->Coord_Number; Vars->Coord_Max[i++] = atof(token));
          Set_Coord_Mode = DEFS->COORD_VAR; Flag_All = 0;
        }
        if (Set_Coord_Mode == DEFS->COORD_MIN)  /* min=%i */
        {
          if (!Flag_All)
            Vars->Coord_Min[Vars->Coord_Number] = atof(token);
          else
            for (i = 0; i <= Vars->Coord_Number; Vars->Coord_Min[i++] = atof(token));
          Set_Coord_Mode = DEFS->COORD_MAX;
        }
        if (Set_Coord_Mode == DEFS->COORD_DIM)  /* bins=%i */
        {
          if (!Flag_All)
            Vars->Coord_Bin[Vars->Coord_Number] = atoi(token);
          else
            for (i = 0; i <= Vars->Coord_Number; Vars->Coord_Bin[i++] = atoi(token));
          Set_Coord_Mode = DEFS->COORD_VAR; Flag_All = 0;
        }
        if (Set_Coord_Mode == DEFS->COORD_FIL)  /* file=%s */
        {
          if (!Flag_No) strncpy(Vars->Mon_File,token,128);
          else { strcpy(Vars->Mon_File,""); Vars->Coord_Number = 0; Flag_End = 1;}
          Set_Coord_Mode = DEFS->COORD_VAR;
        }
        if (Set_Coord_Mode == DEFS->COORD_EVNT) /* list=%i */
        {
          if (!strcmp(token, "all") || Flag_All) Vars->Flag_List = 2;
          else { i = (long)ceil(atof(token)); if (i) Vars->Buffer_Block = i;
            Vars->Flag_List = 1; }
          Set_Coord_Mode = DEFS->COORD_VAR; Flag_All = 0;
        }
        if (Set_Coord_Mode == DEFS->COORD_3HE)  /* pressure=%g */
        {
            Vars->He3_pressure = atof(token);
            Set_Coord_Mode = DEFS->COORD_VAR; Flag_All = 0;
        }

        /* now look for general option keywords */
        if (!strcmp(token, "borders"))  {Vars->Flag_With_Borders = 1; iskeyword=1; }
        if (!strcmp(token, "verbose"))  {Vars->Flag_Verbose      = 1; iskeyword=1; }
        if (!strcmp(token, "log"))      {Vars->Flag_log          = 1; iskeyword=1; }
        if (!strcmp(token, "abs"))      {Flag_abs                = 1; iskeyword=1; }
        if (!strcmp(token, "multiple")) {Vars->Flag_Multiple     = 1; iskeyword=1; }
        if (!strcmp(token, "list") || !strcmp(token, "events")) {
          Vars->Flag_List = 1; Set_Coord_Mode = DEFS->COORD_EVNT;  }
        if (!strcmp(token, "limits") || !strcmp(token, "min"))
          Set_Coord_Mode = DEFS->COORD_MIN;
        if (!strcmp(token, "slit") || !strcmp(token, "absorb")) {
          Vars->Flag_Absorb = 1;  iskeyword=1; }
        if (!strcmp(token, "max"))  Set_Coord_Mode = DEFS->COORD_MAX;
        if (!strcmp(token, "bins") || !strcmp(token, "dim")) Set_Coord_Mode = DEFS->COORD_DIM;
        if (!strcmp(token, "file") || !strcmp(token, "filename")) {
          Set_Coord_Mode = DEFS->COORD_FIL;
          if (Flag_No) { strcpy(Vars->Mon_File,""); Vars->Coord_Number = 0; Flag_End = 1; }
        }
        if (!strcmp(token, "inactivate")) {
          Flag_End = 1; Vars->Coord_Number = 0; iskeyword=1; }
        if (!strcmp(token, "all"))    { Flag_All = 1;  iskeyword=1; }
        if (!strcmp(token, "sphere")) { Vars->Flag_Shape = DEFS->SHAPE_SPHERE; iskeyword=1; }
        if (!strcmp(token, "cylinder")) { Vars->Flag_Shape = DEFS->SHAPE_CYLIND; iskeyword=1; }
        if (!strcmp(token, "banana")) { Vars->Flag_Shape = DEFS->SHAPE_BANANA; iskeyword=1; }
        if (!strcmp(token, "square")) { Vars->Flag_Shape = DEFS->SHAPE_SQUARE; iskeyword=1; }
        if (!strcmp(token, "disk"))   { Vars->Flag_Shape = DEFS->SHAPE_DISK; iskeyword=1; }
        if (!strcmp(token, "box"))     { Vars->Flag_Shape = DEFS->SHAPE_BOX; iskeyword=1; }
        if (!strcmp(token, "previous")) { Vars->Flag_Shape = DEFS->SHAPE_PREVIOUS; iskeyword=1; }
        if (!strcmp(token, "parallel")){ Vars->Flag_parallel = 1; iskeyword=1; }
        if (!strcmp(token, "capture")) { Vars->Flag_capture = 1; iskeyword=1; }
        if (!strcmp(token, "auto")) { 
        #ifndef OPENACC
        if (Flag_auto != -1) {
	    Vars->Flag_Auto_Limits = 1;
	    if (Flag_All) Flag_auto = -1;
	    else          Flag_auto = 1;
	    iskeyword=1; Flag_All=0; 
	  }
        #endif
	}
        if (!strcmp(token, "premonitor")) {
          Vars->Flag_UsePreMonitor = 1; iskeyword=1; }
        if (!strcmp(token, "3He_pressure") || !strcmp(token, "pressure")) {
          Vars->He3_pressure = 3; iskeyword=1; }
        if (!strcmp(token, "no") || !strcmp(token, "not")) { Flag_No = 1;  iskeyword=1; }
        if (!strcmp(token, "signal")) Set_Coord_Mode = DEFS->COORD_SIGNAL;
        if (!strcmp(token, "mantid")) { Vars->Flag_mantid = 1; iskeyword=1; }

        /* Mode has changed: this was a keyword or value  ? */
        if (Set_Coord_Mode != old_Mode) iskeyword=1;

        /* now look for variable names to monitor */
        Set_Vars_Coord_Type = DEFS->COORD_NONE; lmin = 0; lmax = 0;

        if (!strcmp(token, "x"))
          { Set_Vars_Coord_Type = DEFS->COORD_X; strcpy(Set_Vars_Coord_Label,"x [m]"); strcpy(Set_Vars_Coord_Var,"x");
          lmin = Vars->mxmin; lmax = Vars->mxmax;
          Vars->Coord_Min[Vars->Coord_Number+1] = Vars->mxmin;
          Vars->Coord_Max[Vars->Coord_Number+1] = Vars->mxmax;
	  N_spatial_dims++;}
        if (!strcmp(token, "y"))
          { Set_Vars_Coord_Type = DEFS->COORD_Y; strcpy(Set_Vars_Coord_Label,"y [m]"); strcpy(Set_Vars_Coord_Var,"y");
          lmin = Vars->mymin; lmax = Vars->mymax;
          Vars->Coord_Min[Vars->Coord_Number+1] = Vars->mymin;
          Vars->Coord_Max[Vars->Coord_Number+1] = Vars->mymax;
	  N_spatial_dims++;}
        if (!strcmp(token, "z"))
          { Set_Vars_Coord_Type = DEFS->COORD_Z; strcpy(Set_Vars_Coord_Label,"z [m]"); strcpy(Set_Vars_Coord_Var,"z"); lmin = Vars->mzmin; lmax = Vars->mzmax;
	    N_spatial_dims++;}
        if (!strcmp(token, "k") || !strcmp(token, "wavevector"))
          { Set_Vars_Coord_Type = DEFS->COORD_K; strcpy(Set_Vars_Coord_Label,"|k| [Angs-1]"); strcpy(Set_Vars_Coord_Var,"k"); lmin = 0; lmax = 10; }
        if (!strcmp(token, "v"))
          { Set_Vars_Coord_Type = DEFS->COORD_V; strcpy(Set_Vars_Coord_Label,"Velocity [m/s]"); strcpy(Set_Vars_Coord_Var,"v"); lmin = 0; lmax = 10000; }
        if (!strcmp(token, "t") || !strcmp(token, "time") || !strcmp(token, "tof"))
          { Set_Vars_Coord_Type = DEFS->COORD_T; strcpy(Set_Vars_Coord_Label,"TOF [s]"); strcpy(Set_Vars_Coord_Var,"t"); lmin = 0; lmax = 1.0; }
        if ((!strcmp(token, "p") || !strcmp(token, "i") || !strcmp(token, "intensity") || !strcmp(token, "flux")))
          { Set_Vars_Coord_Type = DEFS->COORD_P;
            strcpy(Set_Vars_Coord_Label,"Intensity");
            strncat(Set_Vars_Coord_Label, " [n/s", 30);
            if (Vars->Flag_per_cm2) strncat(Set_Vars_Coord_Label, "/cm2", 30);
            if (XY > 1 && Vars->Coord_Number)
              strncat(Set_Vars_Coord_Label, "/bin", 30);
            strncat(Set_Vars_Coord_Label, "]", 30);
            strcpy(Set_Vars_Coord_Var,"I");
            lmin = 0; lmax = FLT_MAX;
            if (Flag_auto>0) Flag_auto=0;
          }

        if (!strcmp(token, "vx"))
          { Set_Vars_Coord_Type = DEFS->COORD_VX; strcpy(Set_Vars_Coord_Label,"vx [m/s]"); strcpy(Set_Vars_Coord_Var,"vx"); lmin = -1000; lmax = 1000; }
        if (!strcmp(token, "vy"))
          { Set_Vars_Coord_Type = DEFS->COORD_VY; strcpy(Set_Vars_Coord_Label,"vy [m/s]"); strcpy(Set_Vars_Coord_Var,"vy"); lmin = -1000; lmax = 1000; }
        if (!strcmp(token, "vz"))
          { Set_Vars_Coord_Type = DEFS->COORD_VZ; strcpy(Set_Vars_Coord_Label,"vz [m/s]"); strcpy(Set_Vars_Coord_Var,"vz"); lmin = -10000; lmax = 10000; }
        if (!strcmp(token, "kx"))
          { Set_Vars_Coord_Type = DEFS->COORD_KX; strcpy(Set_Vars_Coord_Label,"kx [Angs-1]"); strcpy(Set_Vars_Coord_Var,"kx"); lmin = -1; lmax = 1; }
        if (!strcmp(token, "ky"))
          { Set_Vars_Coord_Type = DEFS->COORD_KY; strcpy(Set_Vars_Coord_Label,"ky [Angs-1]"); strcpy(Set_Vars_Coord_Var,"ky"); lmin = -1; lmax = 1; }
        if (!strcmp(token, "kz"))
          { Set_Vars_Coord_Type = DEFS->COORD_KZ; strcpy(Set_Vars_Coord_Label,"kz [Angs-1]"); strcpy(Set_Vars_Coord_Var,"kz"); lmin = -10; lmax = 10; }
        if (!strcmp(token, "sx"))
          { Set_Vars_Coord_Type = DEFS->COORD_SX; strcpy(Set_Vars_Coord_Label,"sx [1]"); strcpy(Set_Vars_Coord_Var,"sx"); lmin = -1; lmax = 1; }
        if (!strcmp(token, "sy"))
          { Set_Vars_Coord_Type = DEFS->COORD_SY; strcpy(Set_Vars_Coord_Label,"sy [1]"); strcpy(Set_Vars_Coord_Var,"sy"); lmin = -1; lmax = 1; }
        if (!strcmp(token, "sz"))
          { Set_Vars_Coord_Type = DEFS->COORD_SZ; strcpy(Set_Vars_Coord_Label,"sz [1]"); strcpy(Set_Vars_Coord_Var,"sz"); lmin = -1; lmax = 1; }

        if (!strcmp(token, "energy") || !strcmp(token, "omega") || !strcmp(token, "e"))
          { Set_Vars_Coord_Type = DEFS->COORD_ENERGY; strcpy(Set_Vars_Coord_Label,"Energy [meV]"); strcpy(Set_Vars_Coord_Var,"E"); lmin = 0; lmax = 100; }
        if (!strcmp(token, "lambda") || !strcmp(token, "wavelength") || !strcmp(token, "l"))
          { Set_Vars_Coord_Type = DEFS->COORD_LAMBDA; strcpy(Set_Vars_Coord_Label,"Wavelength [Angs]"); strcpy(Set_Vars_Coord_Var,"L"); lmin = 0; lmax = 100; }
        if (!strcmp(token, "radius") || !strcmp(token, "r"))
          { Set_Vars_Coord_Type = DEFS->COORD_RADIUS; strcpy(Set_Vars_Coord_Label,"Radius [m]"); strcpy(Set_Vars_Coord_Var,"xy"); lmin = 0; lmax = xmax; }
        if (!strcmp(token, "xy"))
          { Set_Vars_Coord_Type = DEFS->COORD_XY; strcpy(Set_Vars_Coord_Label,"Radius (xy) [m]"); strcpy(Set_Vars_Coord_Var,"xy"); lmin = 0; lmax = xmax; N_spatial_dims+=1;}
        if (!strcmp(token, "yz"))
          { Set_Vars_Coord_Type = DEFS->COORD_YZ; strcpy(Set_Vars_Coord_Label,"Radius (yz) [m]"); strcpy(Set_Vars_Coord_Var,"yz"); lmin = 0; lmax = xmax; N_spatial_dims+=1;}
        if (!strcmp(token, "xz"))
          { Set_Vars_Coord_Type = DEFS->COORD_XZ; strcpy(Set_Vars_Coord_Label,"Radius (xz) [m]"); strcpy(Set_Vars_Coord_Var,"xz"); lmin = 0; lmax = xmax; N_spatial_dims+=1;}
        if (!strcmp(token, "vxy"))
          { Set_Vars_Coord_Type = DEFS->COORD_VXY; strcpy(Set_Vars_Coord_Label,"Radial Velocity (xy) [m]"); strcpy(Set_Vars_Coord_Var,"Vxy"); lmin = 0; lmax = 2000; }
        if (!strcmp(token, "kxy"))
          { Set_Vars_Coord_Type = DEFS->COORD_KXY; strcpy(Set_Vars_Coord_Label,"Radial Wavevector (xy) [Angs-1]"); strcpy(Set_Vars_Coord_Var,"Kxy"); lmin = 0; lmax = 2; }
        if (!strcmp(token, "vyz"))
          { Set_Vars_Coord_Type = DEFS->COORD_VYZ; strcpy(Set_Vars_Coord_Label,"Radial Velocity (yz) [m]"); strcpy(Set_Vars_Coord_Var,"Vyz"); lmin = 0; lmax = 2000; }
        if (!strcmp(token, "kyz"))
          { Set_Vars_Coord_Type = DEFS->COORD_KYZ; strcpy(Set_Vars_Coord_Label,"Radial Wavevector (yz) [Angs-1]"); strcpy(Set_Vars_Coord_Var,"Kyz"); lmin = 0; lmax = 2; }
        if (!strcmp(token, "vxz"))
          { Set_Vars_Coord_Type = DEFS->COORD_VXZ; strcpy(Set_Vars_Coord_Label,"Radial Velocity (xz) [m]"); strcpy(Set_Vars_Coord_Var,"Vxz"); lmin = 0; lmax = 2000; }
        if (!strcmp(token, "kxz"))
          { Set_Vars_Coord_Type = DEFS->COORD_KXZ; strcpy(Set_Vars_Coord_Label,"Radial Wavevector (xz) [Angs-1]"); strcpy(Set_Vars_Coord_Var,"Kxz"); lmin = 0; lmax = 2; }
        if (!strcmp(token, "angle") || !strcmp(token, "a"))
          { Set_Vars_Coord_Type = DEFS->COORD_ANGLE; strcpy(Set_Vars_Coord_Label,"Angle [deg]"); strcpy(Set_Vars_Coord_Var,"A"); lmin = -50; lmax = 50; N_spatial_dims++;}
        if (!strcmp(token, "hdiv")|| !strcmp(token, "divergence") || !strcmp(token, "xdiv") || !strcmp(token, "hd") || !strcmp(token, "dx"))
          { Set_Vars_Coord_Type = DEFS->COORD_HDIV; strcpy(Set_Vars_Coord_Label,"Hor. Divergence [deg]"); strcpy(Set_Vars_Coord_Var,"hd"); lmin = -5; lmax = 5; N_spatial_dims++;}
        if (!strcmp(token, "vdiv") || !strcmp(token, "ydiv") || !strcmp(token, "vd") || !strcmp(token, "dy"))
          { Set_Vars_Coord_Type = DEFS->COORD_VDIV; strcpy(Set_Vars_Coord_Label,"Vert. Divergence [deg]"); strcpy(Set_Vars_Coord_Var,"vd"); lmin = -5; lmax = 5; N_spatial_dims++;}
        if (!strcmp(token, "theta") || !strcmp(token, "longitude") || !strcmp(token, "th"))
          { Set_Vars_Coord_Type = DEFS->COORD_THETA; strcpy(Set_Vars_Coord_Label,"Longitude [deg]"); strcpy(Set_Vars_Coord_Var,"th"); lmin = -180; lmax = 180; N_spatial_dims++;}
        if (!strcmp(token, "phi") || !strcmp(token, "latitude") || !strcmp(token, "ph"))
          { Set_Vars_Coord_Type = DEFS->COORD_PHI; strcpy(Set_Vars_Coord_Label,"Latitude [deg]"); strcpy(Set_Vars_Coord_Var,"ph"); lmin = -90; lmax = 90; N_spatial_dims++;}
        if (!strcmp(token, "ncounts") || !strcmp(token, "n") || !strcmp(token, "neutron"))
          { Set_Vars_Coord_Type = DEFS->COORD_NCOUNT; strcpy(Set_Vars_Coord_Label,"Neutron ID [1]"); strcpy(Set_Vars_Coord_Var,"n"); lmin = 0; lmax = mcget_ncount(); if (Flag_auto>0) Flag_auto=0; }
        if (!strcmp(token, "id") || !strcmp(token, "pixel"))
          { Set_Vars_Coord_Type = DEFS->COORD_PIXELID; 
            strcpy(Set_Vars_Coord_Label,"Pixel ID [1]"); 
            strcpy(Set_Vars_Coord_Var,"id"); lmin = 0; lmax = FLT_MAX; 
            if (Flag_auto>0) Flag_auto=0;
            Vars->Flag_List = 1; }
        if (!strcmp(token, "user") || !strcmp(token, "user1") || !strcmp(token, "u1"))
          { Set_Vars_Coord_Type = DEFS->COORD_USER1; strncpy(Set_Vars_Coord_Label,Vars->UserName1,30); strcpy(Set_Vars_Coord_Var,"U1"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "user2") || !strcmp(token, "u2"))
          { Set_Vars_Coord_Type = DEFS->COORD_USER2; strncpy(Set_Vars_Coord_Label,Vars->UserName2,30); strcpy(Set_Vars_Coord_Var,"U2"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "user3") || !strcmp(token, "u3"))
          { Set_Vars_Coord_Type = DEFS->COORD_USER3; strncpy(Set_Vars_Coord_Label,Vars->UserName3,30); strcpy(Set_Vars_Coord_Var,"U3"); lmin = -1e10; lmax = 1e10; }

        if (!strcmp(token, "userdouble0") || !strcmp(token, "ud0"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE0; strcpy(Set_Vars_Coord_Label,"ud0 [1]"); strcpy(Set_Vars_Coord_Var,"ud0"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble1") || !strcmp(token, "ud1"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE1; strcpy(Set_Vars_Coord_Label,"ud1 [1]"); strcpy(Set_Vars_Coord_Var,"ud1"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble2") || !strcmp(token, "ud2"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE2; strcpy(Set_Vars_Coord_Label,"ud2 [1]"); strcpy(Set_Vars_Coord_Var,"ud2"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble3") || !strcmp(token, "ud3"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE3; strcpy(Set_Vars_Coord_Label,"ud3 [1]"); strcpy(Set_Vars_Coord_Var,"ud3"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble4") || !strcmp(token, "ud4"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE4; strcpy(Set_Vars_Coord_Label,"ud4 [1]"); strcpy(Set_Vars_Coord_Var,"ud4"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble5") || !strcmp(token, "ud5"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE5; strcpy(Set_Vars_Coord_Label,"ud5 [1]"); strcpy(Set_Vars_Coord_Var,"ud5"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble6") || !strcmp(token, "ud6"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE6; strcpy(Set_Vars_Coord_Label,"ud6 [1]"); strcpy(Set_Vars_Coord_Var,"ud6"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble7") || !strcmp(token, "ud7"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE7; strcpy(Set_Vars_Coord_Label,"ud7 [1]"); strcpy(Set_Vars_Coord_Var,"ud7"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble8") || !strcmp(token, "ud8"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE8; strcpy(Set_Vars_Coord_Label,"ud8 [1]"); strcpy(Set_Vars_Coord_Var,"ud8"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble9") || !strcmp(token, "ud9"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE9; strcpy(Set_Vars_Coord_Label,"ud9 [1]"); strcpy(Set_Vars_Coord_Var,"ud9"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble10") || !strcmp(token, "ud10"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE10; strcpy(Set_Vars_Coord_Label,"ud10 [1]"); strcpy(Set_Vars_Coord_Var,"ud10"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble11") || !strcmp(token, "ud11"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE11; strcpy(Set_Vars_Coord_Label,"ud11 [1]"); strcpy(Set_Vars_Coord_Var,"ud11"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble12") || !strcmp(token, "ud12"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE12; strcpy(Set_Vars_Coord_Label,"ud12 [1]"); strcpy(Set_Vars_Coord_Var,"ud12"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble13") || !strcmp(token, "ud13"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE13; strcpy(Set_Vars_Coord_Label,"ud13 [1]"); strcpy(Set_Vars_Coord_Var,"ud13"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble14") || !strcmp(token, "ud14"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE14; strcpy(Set_Vars_Coord_Label,"ud14 [1]"); strcpy(Set_Vars_Coord_Var,"ud14"); lmin = -1e10; lmax = 1e10; }
        if (!strcmp(token, "userdouble15") || !strcmp(token, "ud15"))
          { Set_Vars_Coord_Type = DEFS->COORD_USERDOUBLE15; strcpy(Set_Vars_Coord_Label,"ud15 [1]"); strcpy(Set_Vars_Coord_Var,"ud15"); lmin = -1e10; lmax = 1e10; }

        /* now stores variable keywords detected, if any */
        if (Set_Vars_Coord_Type != DEFS->COORD_NONE)
        {
          int Coord_Number = Vars->Coord_Number;
          if (Vars->Flag_log) { Set_Vars_Coord_Type |= DEFS->COORD_LOG; Vars->Flag_log = 0; }
          if (Flag_abs) { Set_Vars_Coord_Type |= DEFS->COORD_ABS; Flag_abs = 0; }
          if (Flag_auto != 0) { Set_Vars_Coord_Type |= DEFS->COORD_AUTO; 
            if (Flag_auto > 0) Flag_auto = 0; }
          if (Set_Coord_Mode == DEFS->COORD_SIGNAL)
          {
            Coord_Number = 0;
            Vars->Flag_signal = Set_Vars_Coord_Type;
          }
          else
          {
            if (Coord_Number < MONnD_COORD_NMAX)
            { Coord_Number++;
              Vars->Coord_Number = Coord_Number; 
              if (Set_Vars_Coord_Type != DEFS->COORD_PIXELID)
                Vars->Coord_NumberNoPixel++;
            }
            else if (Vars->Flag_Verbose) printf("Monitor_nD: %s reached max number of variables (%i).\n", Vars->compcurname, MONnD_COORD_NMAX);
          }
          Vars->Coord_Type[Coord_Number] = Set_Vars_Coord_Type;
          strncpy(Vars->Coord_Label[Coord_Number], Set_Vars_Coord_Label,30);
          strncpy(Vars->Coord_Var[Coord_Number], Set_Vars_Coord_Var,30);
          if (lmin > lmax) { XY = lmin; lmin=lmax; lmax = XY; }
          Vars->Coord_Min[Coord_Number] = lmin;
          Vars->Coord_Max[Coord_Number] = lmax;
          if (Set_Vars_Coord_Type == DEFS->COORD_NCOUNT || Set_Vars_Coord_Type == DEFS->COORD_PIXELID || Set_Vars_Coord_Type == DEFS->COORD_SIGNAL)
            Vars->Coord_Bin[Coord_Number] = 1;
          else
            Vars->Coord_Bin[Coord_Number] = 20;
          Set_Coord_Mode = DEFS->COORD_VAR;
          Flag_All = 0;
          Flag_No  = 0;
        } else {
          /* no variable name could be read from options */
          if (!iskeyword) {
            if (strcmp(token, "cm2") && strcmp(token, "incoming")
             && strcmp(token, "outgoing") && strcmp(token, "cm2")
             && strcmp(token, "cm^2") && strcmp(token, "float")
             && strcmp(token, "double") && strcmp(token, "binary")
             && strcmp(token, "steradian") && Vars->Flag_Verbose)
              printf("Monitor_nD: %s: unknown '%s' keyword in 'options'. Ignoring.\n", Vars->compcurname, token);
          }
        }
      carg++;
      } /* end if token */
    } /* end while carg */

    /* Handle nexusbins information */
    /* Case 1, list mode and not disabled i.e. >-1 */
    if (Vars->Flag_List && nexusbins>-1) Vars->Flag_nexusbins=1;
    /* Case 2, NOT list mode and enabled i.e. ==1 */
    if (!Vars->Flag_List && nexusbins==1) Vars->Flag_nexusbins=1;

    free(option_copy);
    if (carg == 128) printf("Monitor_nD: %s reached max number of tokens (%i). Skipping.\n", Vars->compcurname, 128);

    if ((Vars->Flag_Shape == DEFS->SHAPE_BOX) && (fabs(Vars->mzmax - Vars->mzmin) == 0)) Vars->Flag_Shape = DEFS->SHAPE_SQUARE;

    if (Vars->Flag_log == 1) Vars->Coord_Type[0] |= DEFS->COORD_LOG;
    if (Vars->Coord_Number == 0)
    { Vars->Flag_Auto_Limits=0; Vars->Flag_Multiple=0; Vars->Flag_List=0; }

    /* now setting Monitor Name from variable labels */
    strcpy(Vars->Monitor_Label,"");
    XY = 1; /* will contain total bin number */
    for (i = 0; i <= Vars->Coord_Number; i++)
    {
      if (Flag_auto != 0) Vars->Coord_Type[i] |= DEFS->COORD_AUTO;
      Set_Vars_Coord_Type = (Vars->Coord_Type[i] & (DEFS->COORD_LOG-1));
      if ((Set_Vars_Coord_Type == DEFS->COORD_X)
       || (Set_Vars_Coord_Type == DEFS->COORD_Y)
       || (Set_Vars_Coord_Type == DEFS->COORD_Z))
       strcpy(Short_Label[i],"Position");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_THETA)
       || (Set_Vars_Coord_Type == DEFS->COORD_PHI)
       || (Set_Vars_Coord_Type == DEFS->COORD_ANGLE))
       strcpy(Short_Label[i],"Angle");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_XY)
       || (Set_Vars_Coord_Type == DEFS->COORD_XZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_YZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_RADIUS))
       strcpy(Short_Label[i],"Radius");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_VX)
       || (Set_Vars_Coord_Type == DEFS->COORD_VY)
       || (Set_Vars_Coord_Type == DEFS->COORD_VZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_V)
       || (Set_Vars_Coord_Type == DEFS->COORD_VXY)
       || (Set_Vars_Coord_Type == DEFS->COORD_VYZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_VXZ))
       strcpy(Short_Label[i],"Velocity");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_KX)
       || (Set_Vars_Coord_Type == DEFS->COORD_KY)
       || (Set_Vars_Coord_Type == DEFS->COORD_KZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_KXY)
       || (Set_Vars_Coord_Type == DEFS->COORD_KYZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_KXZ)
       || (Set_Vars_Coord_Type == DEFS->COORD_K))
       strcpy(Short_Label[i],"Wavevector");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_SX)
       || (Set_Vars_Coord_Type == DEFS->COORD_SY)
       || (Set_Vars_Coord_Type == DEFS->COORD_SZ))
       strcpy(Short_Label[i],"Spin");
      else
      if ((Set_Vars_Coord_Type == DEFS->COORD_HDIV)
       || (Set_Vars_Coord_Type == DEFS->COORD_VDIV))
       strcpy(Short_Label[i],"Divergence");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_ENERGY)
       strcpy(Short_Label[i],"Energy");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_LAMBDA)
       strcpy(Short_Label[i],"Wavelength");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_NCOUNT)
       strcpy(Short_Label[i],"Neutron_ID");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_PIXELID)
       strcpy(Short_Label[i],"Pixel_ID");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_T)
          strcpy(Short_Label[i],"Time_Of_Flight");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_P)
          strcpy(Short_Label[i],"Intensity");
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_USER1)
          strncpy(Short_Label[i],Vars->UserName1,30);
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_USER2)
          strncpy(Short_Label[i],Vars->UserName2,30);
      else
      if (Set_Vars_Coord_Type == DEFS->COORD_USER3)
          strncpy(Short_Label[i],Vars->UserName3,30);
      else
          strcpy(Short_Label[i],"Unknown");

      if (Vars->Coord_Type[i] & DEFS->COORD_ABS)
      { strcat(Vars->Coord_Label[i]," (abs)"); }

      if (Vars->Coord_Type[i] & DEFS->COORD_LOG)
      { strcat(Vars->Coord_Label[i]," (log)"); }

      strcat(Vars->Monitor_Label, " ");
      strcat(Vars->Monitor_Label, Short_Label[i]);
      XY *= Vars->Coord_Bin[i];

    } /* end for Short_Label */

    if ((Vars->Coord_Type[0] & (DEFS->COORD_LOG-1)) == DEFS->COORD_P) {
      strncat(Vars->Coord_Label[0], " [n/s", 30);
      if (Vars->Flag_per_cm2) strncat(Vars->Coord_Label[0], "/cm2", 30);

      if (XY > 1 && Vars->Coord_Number)
        strncat(Vars->Coord_Label[0], "/bin", 30);
      strncat(Vars->Coord_Label[0], "]", 30);
    }

    /* update label 'signal per bin' if more than 1 bin */
    if (XY > 1 && Vars->Coord_Number) {
      if (Vars->Flag_capture)
        printf("Monitor_nD: %s: Using capture flux weightening on %ld bins.\n"
               "WARNING     Use binned data with caution, and prefer monitor integral value (I,Ierr).\n", Vars->compcurname, (long)XY);
    }

    strcat(Vars->Monitor_Label, " Monitor");
    if (Vars->Flag_Shape == DEFS->SHAPE_SQUARE) strcat(Vars->Monitor_Label, " (Square)");
    if (Vars->Flag_Shape == DEFS->SHAPE_DISK)   strcat(Vars->Monitor_Label, " (Disk)");
    if (Vars->Flag_Shape == DEFS->SHAPE_SPHERE) strcat(Vars->Monitor_Label, " (Sphere)");
    if (Vars->Flag_Shape == DEFS->SHAPE_CYLIND) strcat(Vars->Monitor_Label, " (Cylinder)");
    if (Vars->Flag_Shape == DEFS->SHAPE_BANANA) strcat(Vars->Monitor_Label, " (Banana)");
    if (Vars->Flag_Shape == DEFS->SHAPE_BOX)    strcat(Vars->Monitor_Label, " (Box)");
    if (Vars->Flag_Shape == DEFS->SHAPE_PREVIOUS) strcat(Vars->Monitor_Label, " (on PREVIOUS)");
    if (Vars->Flag_Shape == DEFS->SHAPE_OFF) strcat(Vars->Monitor_Label, " (OFF geometry)");
    if ((Vars->Flag_Shape == DEFS->SHAPE_CYLIND) || (Vars->Flag_Shape == DEFS->SHAPE_BANANA) || (Vars->Flag_Shape == DEFS->SHAPE_SPHERE) || (Vars->Flag_Shape == DEFS->SHAPE_BOX))
    {
      if (strstr(Vars->option, "incoming"))
      {
        Vars->Flag_Shape = abs(Vars->Flag_Shape);
        strcat(Vars->Monitor_Label, " [in]");
      }
      else /* if strstr(Vars->option, "outgoing")) */
      {
        Vars->Flag_Shape = -abs(Vars->Flag_Shape);
        strcat(Vars->Monitor_Label, " [out]");
      }
    }
    if (Vars->Flag_UsePreMonitor == 1)
    {
        strcat(Vars->Monitor_Label, " at ");
        strncat(Vars->Monitor_Label, Vars->UserName1,30);
    }
    if (Vars->Flag_log == 1) strcat(Vars->Monitor_Label, " [log] ");

    /* now allocate memory to store variables in TRACE */

    /* Vars->Coord_Number  0   : intensity or signal
     * Vars->Coord_Number  1:n : detector variables */

    if ((Vars->Coord_NumberNoPixel != 2) && !Vars->Flag_Multiple && !Vars->Flag_List)
    { Vars->Flag_Multiple = 1; /* default is n1D */
      if (Vars->Coord_Number != Vars->Coord_NumberNoPixel) Vars->Flag_List = 1; }

    /* list and auto limits case : Vars->Flag_List or Vars->Flag_Auto_Limits
     * -> Buffer to flush and suppress after Vars->Flag_Auto_Limits
     */
    if ((Vars->Flag_Auto_Limits || Vars->Flag_List) && Vars->Coord_Number)
    { /* Dim : (Vars->Coord_Number+1)*Vars->Buffer_Block matrix (for p, dp) */
      Vars->Mon2D_Buffer = (double *)malloc((Vars->Coord_Number+1)*Vars->Buffer_Block*sizeof(double));
      if (Vars->Mon2D_Buffer == NULL)
      { printf("Monitor_nD: %s cannot allocate Vars->Mon2D_Buffer (%zi). No list and auto limits.\n", Vars->compcurname, Vars->Buffer_Block*(Vars->Coord_Number+1)*sizeof(double)); Vars->Flag_List = 0; Vars->Flag_Auto_Limits = 0; }
      else
      {
        for (i=0; i < (Vars->Coord_Number+1)*Vars->Buffer_Block; Vars->Mon2D_Buffer[i++] = (double)0);
      }
      Vars->Buffer_Size = Vars->Buffer_Block;
    }

    /* 1D and n1D case : Vars->Flag_Multiple */
    if (Vars->Flag_Multiple && Vars->Coord_NumberNoPixel)
    { /* Dim : Vars->Coord_Number*Vars->Coord_Bin[i] vectors */
      Vars->Mon2D_N  = (double **)malloc((Vars->Coord_Number)*sizeof(double *));
      Vars->Mon2D_p  = (double **)malloc((Vars->Coord_Number)*sizeof(double *));
      Vars->Mon2D_p2 = (double **)malloc((Vars->Coord_Number)*sizeof(double *));
      if ((Vars->Mon2D_N == NULL) || (Vars->Mon2D_p == NULL) || (Vars->Mon2D_p2 == NULL))
      { fprintf(stderr,"Monitor_nD: %s n1D cannot allocate Vars->Mon2D_N/p/p2 (%zi). Fatal.\n", Vars->compcurname, (Vars->Coord_Number)*sizeof(double *)); exit(-1); }
      for (i= 1; i <= Vars->Coord_Number; i++)
      {
        Vars->Mon2D_N[i-1]  = (double *)malloc(Vars->Coord_Bin[i]*sizeof(double));
        Vars->Mon2D_p[i-1]  = (double *)malloc(Vars->Coord_Bin[i]*sizeof(double));
        Vars->Mon2D_p2[i-1] = (double *)malloc(Vars->Coord_Bin[i]*sizeof(double));
        if ((Vars->Mon2D_N == NULL) || (Vars->Mon2D_p == NULL) || (Vars->Mon2D_p2 == NULL))
        { fprintf(stderr,"Monitor_nD: %s n1D cannot allocate %s Vars->Mon2D_N/p/p2[%li] (%zi). Fatal.\n", Vars->compcurname, Vars->Coord_Var[i], i, (Vars->Coord_Bin[i])*sizeof(double *)); exit(-1); }
        else
        {
          for (j=0; j < Vars->Coord_Bin[i]; j++ )
          { Vars->Mon2D_N[i-1][j] = (double)0; Vars->Mon2D_p[i-1][j] = (double)0; Vars->Mon2D_p2[i-1][j] = (double)0; }
        }
      }
    }
    else /* 2D case : Vars->Coord_Number==2 and !Vars->Flag_Multiple and !Vars->Flag_List */
    if ((Vars->Coord_NumberNoPixel == 2) && !Vars->Flag_Multiple)
    { /* Dim : Vars->Coord_Bin[1]*Vars->Coord_Bin[2] matrix */
      Vars->Mon2D_N  = (double **)malloc((Vars->Coord_Bin[1])*sizeof(double *));
      Vars->Mon2D_p  = (double **)malloc((Vars->Coord_Bin[1])*sizeof(double *));
      Vars->Mon2D_p2 = (double **)malloc((Vars->Coord_Bin[1])*sizeof(double *));
      if ((Vars->Mon2D_N == NULL) || (Vars->Mon2D_p == NULL) || (Vars->Mon2D_p2 == NULL))
      { fprintf(stderr,"Monitor_nD: %s 2D cannot allocate %s Vars->Mon2D_N/p/p2 (%zi). Fatal.\n", Vars->compcurname, Vars->Coord_Var[1], (Vars->Coord_Bin[1])*sizeof(double *)); exit(-1); }
      for (i= 0; i < Vars->Coord_Bin[1]; i++)
      {
        Vars->Mon2D_N[i]  = (double *)malloc(Vars->Coord_Bin[2]*sizeof(double));
        Vars->Mon2D_p[i]  = (double *)malloc(Vars->Coord_Bin[2]*sizeof(double));
        Vars->Mon2D_p2[i] = (double *)malloc(Vars->Coord_Bin[2]*sizeof(double));
        if ((Vars->Mon2D_N == NULL) || (Vars->Mon2D_p == NULL) || (Vars->Mon2D_p2 == NULL))
        { fprintf(stderr,"Monitor_nD: %s 2D cannot allocate %s Vars->Mon2D_N/p/p2[%li] (%zi). Fatal.\n", Vars->compcurname, Vars->Coord_Var[1], i, (Vars->Coord_Bin[2])*sizeof(double *)); exit(-1); }
        else
        {
          for (j=0; j < Vars->Coord_Bin[2]; j++ )
          { Vars->Mon2D_N[i][j] = (double)0; Vars->Mon2D_p[i][j] = (double)0; Vars->Mon2D_p2[i][j] = (double)0; }
        }
      }
    }
    else {
      Vars->Mon2D_N = Vars->Mon2D_p = Vars->Mon2D_p2 = NULL;
    }
      /* no Mon2D allocated for
       * (Vars->Coord_Number != 2) && !Vars->Flag_Multiple && Vars->Flag_List */

    Vars->psum  = 0;
    Vars->p2sum = 0;
    Vars->Nsum  = 0;

    Vars->area  = fabs(Vars->mxmax - Vars->mxmin)*fabs(Vars->mymax - Vars->mymin)*1E4; /* in cm**2 for square and box shapes */
    Vars->Sphere_Radius = fabs(Vars->mxmax - Vars->mxmin)/2;
    if ((abs(Vars->Flag_Shape) == DEFS->SHAPE_DISK) || (abs(Vars->Flag_Shape) == DEFS->SHAPE_SPHERE))
    {
      Vars->area = PI*Vars->Sphere_Radius*Vars->Sphere_Radius*1E4; /* disk shapes */
    }


    if (Vars->area == 0 && abs(Vars->Flag_Shape) != DEFS->SHAPE_PREVIOUS ) {
      if (abs(Vars->Flag_Shape) != DEFS->SHAPE_OFF) {  
	Vars->Coord_Number = 0;
      }
    }
    if (Vars->Coord_Number == 0 && Vars->Flag_Verbose)
      printf("Monitor_nD: %s is inactivated (0D)\n", Vars->compcurname);
    Vars->Cylinder_Height = fabs(Vars->mymax - Vars->mymin);

    if (Vars->Flag_Verbose)
    {
      printf("Monitor_nD: %s is a %s.\n", Vars->compcurname, Vars->Monitor_Label);
      printf("Monitor_nD: version %s with options=%s\n", MONITOR_ND_LIB_H, Vars->option);
    }
    
    /* compute the product of bin dimensions for PixelID */
    Vars->Coord_BinProd[0]=1;

    for (i = 1; i <= Vars->Coord_Number; i++) {
      Vars->Coord_BinProd[i]=Vars->Coord_Bin[i]*Vars->Coord_BinProd[i-1];
    }

    #ifdef USE_NEXUS

    #ifdef USE_MPI
    if(mpi_node_rank == mpi_node_root) {
    #endif
      if(nxhandle) {

	/* This section of code writes detector shape information to
	   entryN/instrument/components/'name'/geometry in the NeXus file */

	char nexuscomp[CHAR_BUF_LENGTH];
	char pref[5];
	if (Vars->compcurindex-1 < 10) {
	  sprintf(pref,"000");
	} else if (Vars->compcurindex-1 < 100) {
	  sprintf(pref,"00");
	} else if (Vars->compcurindex-1 < 1000) {
	  sprintf(pref,"0");
	} else if (Vars->compcurindex-1 < 10000) {
	  sprintf(pref,"");
	} else {
	  fprintf(stderr,"Error, no support for > 10000 comps at the moment!\n");
	  exit(-1);
	}
	sprintf(nexuscomp,"%s%d_%s",pref,Vars->compcurindex-1,Vars->compcurname);

	if (NXopengroup(nxhandle, "instrument", "NXinstrument") == NX_OK) {
	  if (NXopengroup(nxhandle, "components", "NXdata") == NX_OK) {
	    if (NXopengroup(nxhandle, nexuscomp, "NXdata") == NX_OK) {
	      if (NXmakegroup(nxhandle, "Geometry", "NXdata") == NX_OK) {
		if (NXopengroup(nxhandle, "Geometry", "NXdata") == NX_OK) {
		  char tmp[CHAR_BUF_LENGTH];
		  sprintf(tmp,"%g",Vars->Sphere_Radius);
		  nxprintattr(nxhandle, "radius", tmp);

		  sprintf(tmp,"%g",Vars->Cylinder_Height);
		  nxprintattr(nxhandle, "height", tmp);

		  sprintf(tmp,"%g",Vars->mxmin);
		  nxprintattr(nxhandle, "xmin",  tmp);
		  sprintf(tmp,"%g",Vars->mxmax);
		  nxprintattr(nxhandle, "xmax",  tmp);

		  sprintf(tmp,"%g",Vars->mymin);
		  nxprintattr(nxhandle, "ymin",  tmp);
		  sprintf(tmp,"%g",Vars->mymax);
		  nxprintattr(nxhandle, "ymax",  tmp);

		  sprintf(tmp,"%g",Vars->mzmin);
		  nxprintattr(nxhandle, "zmin",  tmp);
		  sprintf(tmp,"%g",Vars->mzmax);
		  nxprintattr(nxhandle, "zmax",  tmp);

		  sprintf(tmp,"%g",Vars->mzmin);
		  nxprintattr(nxhandle, "zmin",  tmp);
		  sprintf(tmp,"%g",Vars->mzmax);
		  nxprintattr(nxhandle, "zmax",  tmp);

		  sprintf(tmp,"%i",Vars->Flag_Shape);
		  nxprintattr(nxhandle, "Shape identifier",  tmp);
		  sprintf(tmp,"%s",Vars->Monitor_Label);
		  nxprintattr(nxhandle, "Shape string",  tmp);
		  sprintf(tmp,"%s",Vars->option);
		  nxprintattr(nxhandle, "Option string",  tmp);

		  NXclosegroup(nxhandle); // Geometry
		} else {
		  printf("Failed to open component NeXus component Geometry group\n");
		}
	      } else {
		printf("Failed to create component NeXus component Geometry group\n");
	      }
	      NXclosegroup(nxhandle); // component
	    }
	    NXclosegroup(nxhandle); // components
	  } else {
	    printf("Failed to open NeXus component hierarchy\n");
	  }
	  NXclosegroup(nxhandle); // instrument
	}

	if (Vars->Flag_nexusbins) {
	  /* Below code communicates geometry-oriented "BINS" for the detector. */
	  char metadata[CHAR_BUF_LENGTH];
	  char metadatatmp[CHAR_BUF_LENGTH];
	  // Vars for 1D, >3D, OFF
	  long numbins;
	  long minbins = 0;
	  long maxbins = 0;
	  char binlabel[CHAR_BUF_LENGTH];
	  char binvar[CHAR_BUF_LENGTH];
	  sprintf(binlabel,"none");
	  sprintf(binvar,"none");
	  
	  // Find index of pixel column
	  int id_index;
	  for (id_index=0;id_index<30;id_index++) {
	    if (strcmp(Vars->Coord_Var[id_index], "id") == 0) break;
	  }
	  if (id_index == 30) id_index = Vars->Coord_Number-1; // Revert to earlier behavior is id not found
	  long pix=Vars->Coord_Min[id_index];
	  
	  MCDETECTOR detector;
	  
	  /* Init - perhaps better with an init-function in mccode-r? */
	  detector.m = 0;
	  detector.xmin = 0;
	  detector.xmax = 0;
	  detector.ymin = 0;
	  detector.ymax = 0;
	  detector.zmin = 0;
	  detector.zmax = 0;
	  detector.intensity = 0;
	  detector.error = 0;
	  detector.events = 0;
	  detector.min = 0;
	  detector.max = 0;
	  detector.mean = 0;
	  detector.centerX = 0;
	  detector.halfwidthX = 0;
	  detector.centerY = 0;
	  detector.halfwidthY = 0;
	  detector.rank = 0;
	  detector.istransposed = 0;
	  detector.n = 0;
	  detector.p = 0;
	  detector.date_l = 0;
	  detector.p0 = NULL;
	  detector.p1 = NULL;
	  detector.p2 = NULL;
	  
	  sprintf(detector.filename,"BINS");
	  sprintf(detector.component,"%s",Vars->compcurname);
	  sprintf(detector.nexuscomp,"%s%d_%s",pref,Vars->compcurindex-1,detector.component);
	  sprintf(detector.format,"pixels");
	  
	  if(!Vars->Flag_OFF) {
	    
	    sprintf(metadata,"id=%ld + %ld pixels: ",(long)Vars->Coord_Min[id_index],(long)Vars->Coord_BinProd[Vars->Coord_Number]);
	    for (i=1; i<N_spatial_dims; i++) {
	      sprintf(metadatatmp,"%s %s (%ld bins) x ",metadata,Vars->Coord_Label[i],Vars->Coord_Bin[i]);
	      sprintf(metadata,"%s",metadatatmp);
	    }
	    sprintf(metadatatmp,"%s %s (%ld bins)",metadata,Vars->Coord_Label[i],Vars->Coord_Bin[i]);
	    sprintf(metadata,"%s",metadatatmp);
	    numbins = Vars->Coord_BinProd[Vars->Coord_Number];
	    if (N_spatial_dims==1) {
	      minbins=Vars->Coord_Min[1];
	      maxbins=Vars->Coord_Max[1];
	      sprintf(binlabel,"%s",Vars->Coord_Label[1]);
	      sprintf(binvar,"%s",Vars->Coord_Var[1]);
	    } else if (N_spatial_dims>3) {
	      minbins=1;
	      maxbins=Vars->Coord_BinProd[Vars->Coord_Number];
	      sprintf(binlabel,"More than 3 dimensions");
	      sprintf(binvar,"wrapped_variables_4plus_dims");
	      N_spatial_dims=1;
	    }
	    sprintf(detector.xlabel,"%s",binlabel);
	    sprintf(detector.xvar,"%s",binvar);
	    detector.xmin=minbins;
	    detector.xmax=maxbins;
	  } else {
	    numbins = Vars->Flag_OFF;
	    minbins=1;
	    maxbins=Vars->Flag_OFF;
	    sprintf(binlabel,"OFF pixel index");
	    sprintf(binvar,"OFF");
	    N_spatial_dims=1;
	    sprintf(detector.xlabel,"%s",binlabel);
	    sprintf(detector.xvar,"%s",binvar);
	    detector.xmin=minbins;
	    detector.xmax=maxbins;
	  }
	  
	  long k,l,m;
	  if (N_spatial_dims==1) { // 1D case or ND
	    detector.m=numbins;
	    detector.n=1;
	    detector.p=1;
	    detector.rank=1;
	    detector.p0=(double *)calloc(numbins, sizeof(double));
	    detector.p1=(double *)calloc(numbins, sizeof(double));
	    detector.p2=(double *)calloc(numbins, sizeof(double));
	    if (Vars->Flag_Verbose) printf("1D case %ld \n",Vars->Coord_Bin[1]);
	    for (k=0; k<numbins; k++) {
	      if (Vars->Flag_Verbose) printf("Assigning pixel no [%ld] = %ld\n",k,pix);
	      detector.p1[k]=pix;
	      pix++;
	    }
	    mcdetector_out_1D_nexus(detector);
	    free(detector.p0);
	    free(detector.p1);
	    free(detector.p2);
	  } else if (N_spatial_dims==2) { // 2D case
	    detector.m=Vars->Coord_Bin[1];
	    detector.n=Vars->Coord_Bin[2];
	    detector.p=1;
	    detector.rank=2;
	    sprintf(detector.xlabel,"%s",Vars->Coord_Label[1]);
	    sprintf(detector.xvar,"%s",Vars->Coord_Var[1]);
	    detector.xmin=Vars->Coord_Min[1];
	    detector.xmax=Vars->Coord_Max[1];
	    sprintf(detector.ylabel,"%s",Vars->Coord_Label[2]);
	    sprintf(detector.yvar,"%s",Vars->Coord_Var[2]);
	    detector.ymin=Vars->Coord_Min[2];
	    detector.ymax=Vars->Coord_Max[2];
	    detector.p0=(double *)calloc(Vars->Coord_BinProd[Vars->Coord_Number], sizeof(double));
	    detector.p1=(double *)calloc(Vars->Coord_BinProd[Vars->Coord_Number], sizeof(double));
	    detector.p2=(double *)calloc(Vars->Coord_BinProd[Vars->Coord_Number], sizeof(double));
	    if (Vars->Flag_Verbose) printf("2D case %ld x %ld \n",Vars->Coord_Bin[1],Vars->Coord_Bin[2]);
	    for (k=0; k<Vars->Coord_Bin[1]; k++) {
	      for (l=0; l<Vars->Coord_Bin[2]; l++) {
		if (Vars->Flag_Verbose) printf("Assigning pixel no [%ld,%ld] = %ld\n",l,k,pix);
		detector.p1[k*Vars->Coord_Bin[2]+l]=pix;
		pix++;
	      }
	    }
	    mcdetector_out_2D_nexus(detector);
	    free(detector.p0);
	    free(detector.p1);
	    free(detector.p2);
	  } else if (N_spatial_dims==3) { // 3D case
	    detector.m=Vars->Coord_Bin[1];
	    detector.n=Vars->Coord_Bin[2];
	    detector.p=Vars->Coord_Bin[3];;
	    detector.rank=3;
	    sprintf(detector.xlabel,"%s",Vars->Coord_Label[1]);
	    sprintf(detector.xvar,"%s",Vars->Coord_Var[1]);
	    detector.xmin=Vars->Coord_Min[1];
	    detector.xmax=Vars->Coord_Max[1];
	    sprintf(detector.ylabel,"%s",Vars->Coord_Label[2]);
	    sprintf(detector.yvar,"%s",Vars->Coord_Var[2]);
	    detector.ymin=Vars->Coord_Min[2];
	    detector.ymax=Vars->Coord_Max[2];
	    sprintf(detector.zlabel,"%s",Vars->Coord_Label[3]);
	    sprintf(detector.zvar,"%s",Vars->Coord_Var[3]);
	    detector.zmin=Vars->Coord_Min[3];
	    detector.zmax=Vars->Coord_Max[3];
	    detector.p0=(double *)calloc(Vars->Coord_BinProd[Vars->Coord_Number], sizeof(double));
	    detector.p1=(double *)calloc(Vars->Coord_BinProd[Vars->Coord_Number], sizeof(double));
	    detector.p2=(double *)calloc(Vars->Coord_BinProd[Vars->Coord_Number], sizeof(double));
	    if (Vars->Flag_Verbose) printf("3D case %ld x %ld x %ld \n",Vars->Coord_Bin[1],Vars->Coord_Bin[2],Vars->Coord_Bin[3]);
	    for (k=0; k<Vars->Coord_Bin[1]; k++) {
	      for (l=0; l<Vars->Coord_Bin[2]; l++) {
		for (m=0; m<Vars->Coord_Bin[3]; m++) {
		  if (Vars->Flag_Verbose) printf("Assigning pixel no [%ld,%ld,%ld] = %ld\n",m,l,k,pix);
		  detector.p1[k*Vars->Coord_Bin[2]*Vars->Coord_Bin[3] + l*Vars->Coord_Bin[3] + m]=pix;
		  pix++;
		}
	      }
	    }
	    mcdetector_out_3D_nexus(detector);
	    free(detector.p0);
	    free(detector.p1);
	    free(detector.p2);
	  }
	} // Flag_nexusbins active
      } // nxhandle available
    #ifdef USE_MPI
    } // Master only
    #endif

    #endif // USE_NEXUS
    } /* end Monitor_nD_Init */

/* ========================================================================= */
/* Monitor_nD_Trace: this routine is used to monitor one propagating neutron */
/* return values: 0=neutron was absorbed, -1=neutron was outside bounds, 1=neutron was measured*/
/* ========================================================================= */

int Monitor_nD_Trace(MonitornD_Defines_type *DEFS, MonitornD_Variables_type *Vars, _class_particle* _particle)
{

  double  XY=0, pp=0;
  long    i =0, j =0;
  double  Coord[MONnD_COORD_NMAX];
  long    Coord_Index[MONnD_COORD_NMAX];
  char    While_End   =0;
  long    While_Buffer=0;
  char    Set_Vars_Coord_Type = DEFS->COORD_NONE;

  /* the logic below depends mainly on:
       Flag_List:        1=store 1 buffer, 2=list all, 3=re-use buffer 
       Flag_Auto_Limits: 0 (no auto limits/list), 1 (store events into Buffer), 2 (re-emit store events)
   */

  /* Vars->Flag_Auto_Limits=1: buffer full, we read the Buffer, and determine min and max bounds */
  if ((Vars->Buffer_Counter >= Vars->Buffer_Block) && (Vars->Flag_Auto_Limits == 1) && (Vars->Coord_Number > 0))
  {
    /* auto limits case : get limits in Buffer for each variable */
          /* Dim : (Vars->Coord_Number+1)*Vars->Buffer_Block matrix (for p, dp) */
    if (Vars->Flag_Verbose) printf("Monitor_nD: %s getting %li Auto Limits from List (%li events) in TRACE.\n", Vars->compcurname, Vars->Coord_Number, Vars->Buffer_Counter);
    for (i = 1; i <= Vars->Coord_Number; i++)
    {
      if (Vars->Coord_Type[i] & DEFS->COORD_AUTO)
      {
        Vars->Coord_Min[i] =  FLT_MAX;
        Vars->Coord_Max[i] = -FLT_MAX;
        for (j = 0; j < Vars->Buffer_Counter; j++)
        {
          XY = Vars->Mon2D_Buffer[i+j*(Vars->Coord_Number+1)];  /* scanning variables in Buffer */
          if (XY < Vars->Coord_Min[i]) Vars->Coord_Min[i] = XY;
          if (XY > Vars->Coord_Max[i]) Vars->Coord_Max[i] = XY;
        }
        if  (Vars->Flag_Verbose)  
          printf("  %s: min=%g max=%g\n", Vars->Coord_Var[i], Vars->Coord_Min[i], Vars->Coord_Max[i]);
      }
    }
    Vars->Flag_Auto_Limits = 2;  /* pass to 2nd auto limits step (read Buffer and generate new events to store in histograms) */
  } /* end if Flag_Auto_Limits == 1 */

#ifndef OPENACC
  /* manage realloc for 'list all' if Buffer size exceeded: flush Buffer to file */
  if ((Vars->Buffer_Counter >= Vars->Buffer_Block) && (Vars->Flag_List >= 2))
  {
    if (Vars->Buffer_Size >= 1000000 || Vars->Flag_List == 3)
    { /* save current (possibly append) and re-use Buffer */

      Monitor_nD_Save(DEFS, Vars);
      Vars->Flag_List = 3;
      Vars->Buffer_Block = Vars->Buffer_Size;
      Vars->Buffer_Counter  = 0;
      Vars->Neutron_Counter = 0;
    }
    else
    {
      Vars->Mon2D_Buffer  = (double *)realloc(Vars->Mon2D_Buffer, (Vars->Coord_Number+1)*(2*Vars->Buffer_Block)*sizeof(double));
      if (Vars->Mon2D_Buffer == NULL)
            { printf("Monitor_nD: %s cannot reallocate Vars->Mon2D_Buffer[%li] (%zi). Skipping.\n", Vars->compcurname, i, (long int)(2*Vars->Buffer_Block)*sizeof(double)); Vars->Flag_List = 1; }
      else { 
		  Vars->Buffer_Block = 2*Vars->Buffer_Block;
		  Vars->Buffer_Size = Vars->Buffer_Block;
	  }
    }
  } /* end if Buffer realloc */
#endif

  char    outsidebounds=0;
  while (!While_End)
  { /* we generate Coord[] and Coord_index[] from Buffer (auto limits) or passing neutron */
    if ((Vars->Flag_Auto_Limits == 2) && (Vars->Coord_Number > 0))
    { /* Vars->Flag_Auto_Limits == 2: read back from Buffer (Buffer is filled or auto limits have been computed) */
      if (While_Buffer < Vars->Buffer_Block)
      {
        /* first while loop (While_Buffer) */
        /* auto limits case : scan Buffer within limits and store in Mon2D */
        Coord[0] = pp = Vars->Mon2D_Buffer[While_Buffer*(Vars->Coord_Number+1)];

        for (i = 1; i <= Vars->Coord_Number; i++)
        {
          /* scanning variables in Buffer */
          if (Vars->Coord_Bin[i] <= 1) continue;
          XY = (Vars->Coord_Max[i]-Vars->Coord_Min[i]);

          Coord[i] = Vars->Mon2D_Buffer[i+While_Buffer*(Vars->Coord_Number+1)];
          if (XY > 0) Coord_Index[i] = floor((Coord[i]-Vars->Coord_Min[i])*Vars->Coord_Bin[i]/XY);
          else        Coord_Index[i] = 0;
          if (Vars->Flag_With_Borders)
          {
            if (Coord_Index[i] < 0)                   Coord_Index[i] = 0;
            if (Coord_Index[i] >= Vars->Coord_Bin[i]) Coord_Index[i] = Vars->Coord_Bin[i] - 1;
          }
        } /* end for */
        
        /* update the PixelID, we compute it from the previous variables index */
        if (Vars->Coord_NumberNoPixel < Vars->Coord_Number) /* there is a Pixel variable */
        for (i = 1; i <= Vars->Coord_Number; i++) {
          char Set_Vars_Coord_Type = (Vars->Coord_Type[i] & (DEFS->COORD_LOG-1));
          if (Set_Vars_Coord_Type == DEFS->COORD_PIXELID) {
            char flag_outside=0;
            Coord_Index[i] = Coord[i] = 0;
            for (j= 1; j < i; j++) {
              /* not for 1D variables with Bin=1 such as PixelID, NCOUNT, Intensity */
              if (Vars->Coord_Bin[j] == 1) continue; 
              if (0 > Coord_Index[j] || Coord_Index[j] >= Vars->Coord_Bin[j]) {
                flag_outside=1;
                Coord[i] = 0;
                break;
              }
              Coord[i] += Coord_Index[j]*Vars->Coord_BinProd[j-1];
            }
            if (!flag_outside) {
              Vars->Mon2D_Buffer[i+While_Buffer*(Vars->Coord_Number+1)] = Coord[i];
            }
          } /* end if PixelID */
        }
        While_Buffer++;
      } /* end if in Buffer */
      else /* (While_Buffer >= Vars->Buffer_Block) && (Vars->Flag_Auto_Limits == 2) */
      {
        Vars->Flag_Auto_Limits = 0;
        if (!Vars->Flag_List) /* free Buffer not needed anymore (no list to output) */
        { /* Dim : (Vars->Coord_Number+1)*Vars->Buffer_Block matrix (for p, p2) */
          free(Vars->Mon2D_Buffer); Vars->Mon2D_Buffer = NULL;
        }
        if (Vars->Flag_Verbose) printf("Monitor_nD: %s flushed %li Auto Limits from List (%li) in TRACE.\n", Vars->compcurname, Vars->Coord_Number, Vars->Buffer_Counter);
      }
    } /* if Vars->Flag_Auto_Limits == 2 */
    
    if (Vars->Flag_Auto_Limits != 2 || !Vars->Coord_Number) /* Vars->Flag_Auto_Limits == 0 (no auto limits/list) or 1 (store events into Buffer) */
    {
      /* automatically compute area and steradian solid angle when in AUTO mode */
      /* compute the steradian solid angle incoming on the monitor */
      double v;
      double tmp;
      v=sqrt(_particle->vx*_particle->vx + _particle->vy*_particle->vy + _particle->vz*_particle->vz);
      tmp=_particle->x;
      if (Vars->min_x > _particle->x){
        #pragma acc atomic write
        Vars->min_x = tmp;
      }
      if (Vars->max_x < _particle->x){
        #pragma acc atomic write
        Vars->max_x = tmp;
      }
      tmp=_particle->y;
      if (Vars->min_y > _particle->y){
        #pragma acc atomic write
        Vars->min_y = tmp;
      }
      if (Vars->max_y < _particle->y){
	tmp=_particle->y;
        #pragma acc atomic write
	Vars->max_y = tmp;
      }

      #pragma acc atomic
      Vars->mean_p = Vars->mean_p + _particle->p;
      if (v) {
        tmp=_particle->p*fabs(_particle->vx/v);
        #pragma acc atomic
        Vars->mean_dx = Vars->mean_dx + tmp; //_particle->p*fabs(_particle->vx/v);
        tmp=_particle->p*fabs(_particle->vy/v);
        #pragma acc atomic
        Vars->mean_dy = Vars->mean_dy + tmp; //_particle->p*fabs(_particle->vy/v);
      }

      for (i = 0; i <= Vars->Coord_Number; i++)
      { /* handle current neutron : last while */
        XY = 0;
        Set_Vars_Coord_Type = (Vars->Coord_Type[i] & (DEFS->COORD_LOG-1));
        /* get values for variables to monitor */
        if (Set_Vars_Coord_Type == DEFS->COORD_X) XY = _particle->x;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_Y) XY = _particle->y;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_Z) XY = _particle->z;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VX) XY = _particle->vx;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VY) XY = _particle->vy;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VZ) XY = _particle->vz;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KX) XY = V2K*_particle->vx;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KY) XY = V2K*_particle->vy;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KZ) XY = V2K*_particle->vz;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_SX) XY = _particle->sx;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_SY) XY = _particle->sy;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_SZ) XY = _particle->sz;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_T) XY = _particle->t;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_P) XY = _particle->p;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE0) XY = Vars->UserDoubles[0];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE1) XY = Vars->UserDoubles[1];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE2) XY = Vars->UserDoubles[2];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE3) XY = Vars->UserDoubles[3];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE4) XY = Vars->UserDoubles[4];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE5) XY = Vars->UserDoubles[5];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE6) XY = Vars->UserDoubles[6];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE7) XY = Vars->UserDoubles[7];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE8) XY = Vars->UserDoubles[8];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE9) XY = Vars->UserDoubles[9];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE10) XY = Vars->UserDoubles[10];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE11) XY = Vars->UserDoubles[11];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE12) XY = Vars->UserDoubles[12];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE13) XY = Vars->UserDoubles[13];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE14) XY = Vars->UserDoubles[14];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USERDOUBLE15) XY = Vars->UserDoubles[15];
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_HDIV) XY = RAD2DEG*atan2(_particle->vx,_particle->vz);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VDIV) XY = RAD2DEG*atan2(_particle->vy,_particle->vz);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_V) XY = sqrt(_particle->vx*_particle->vx+_particle->vy*_particle->vy+_particle->vz*_particle->vz);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_RADIUS)
          XY = sqrt(_particle->x*_particle->x+_particle->y*_particle->y+_particle->z*_particle->z);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_XY)
          XY = sqrt(_particle->x*_particle->x+_particle->y*_particle->y)*(_particle->x > 0 ? 1 : -1);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_YZ) XY = sqrt(_particle->y*_particle->y+_particle->z*_particle->z);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_XZ)
          XY = sqrt(_particle->x*_particle->x+_particle->z*_particle->z);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VXY) XY = sqrt(_particle->vx*_particle->vx+_particle->vy*_particle->vy);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VXZ) XY = sqrt(_particle->vx*_particle->vx+_particle->vz*_particle->vz);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_VYZ) XY = sqrt(_particle->vy*_particle->vy+_particle->vz*_particle->vz);
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_K) { XY = sqrt(_particle->vx*_particle->vx+_particle->vy*_particle->vy+_particle->vz*_particle->vz);  XY *= V2K; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KXY) { XY = sqrt(_particle->vx*_particle->vx+_particle->vy*_particle->vy);  XY *= V2K; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KXZ) { XY = sqrt(_particle->vx*_particle->vx+_particle->vz*_particle->vz);  XY *= V2K; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_KYZ) { XY = sqrt(_particle->vy*_particle->vy+_particle->vz*_particle->vz);  XY *= V2K; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_ENERGY) { XY = _particle->vx*_particle->vx+_particle->vy*_particle->vy+_particle->vz*_particle->vz;  XY *= VS2E; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_LAMBDA) { XY = sqrt(_particle->vx*_particle->vx+_particle->vy*_particle->vy+_particle->vz*_particle->vz);  XY *= V2K; if (XY != 0) XY = 2*PI/XY; }
        else
	  if (Set_Vars_Coord_Type == DEFS->COORD_NCOUNT) XY = _particle->_uid;
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_ANGLE)
        {  XY = sqrt(_particle->vx*_particle->vx+_particle->vy*_particle->vy);
           if (_particle->vz != 0)
                XY = RAD2DEG*atan2(XY,_particle->vz)*(_particle->x > 0 ? 1 : -1);
           else XY = 0;
        }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_THETA)  { if (_particle->z != 0) XY = RAD2DEG*atan2(_particle->x,_particle->z); }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_PHI) { double rr=sqrt(_particle->x*_particle->x+ _particle->y*_particle->y + _particle->z*_particle->z); if (rr != 0) XY = RAD2DEG*asin(_particle->y/rr); }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USER1) {int fail; XY = particle_getvar(_particle,Vars->UserVariable1,&fail); if(fail) XY=0; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USER2) {int fail; XY = particle_getvar(_particle,Vars->UserVariable2,&fail); if(fail) XY=0; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_USER3) {int fail; XY = particle_getvar(_particle,Vars->UserVariable3,&fail); if(fail) XY=0; }
        else
        if (Set_Vars_Coord_Type == DEFS->COORD_PIXELID && !Vars->Flag_Auto_Limits) {
          /* compute the PixelID from previous coordinates 
             the PixelID is the product of Coord_Index[i] in the detector geometry 
             pixelID = sum( Coord_Index[j]*prod(Vars->Coord_Bin[1:(j-1)]) )
             
             this does not apply when we store events in the buffer as Coord_Index
             is not set. Then the pixelID will be re-computed during SAVE.
          */
          char flag_outside=0;
          for (j= 1; j < i; j++) {
            /* not for 1D variables with Bin=1 such as PixelID, NCOUNT, Intensity */
            if (Vars->Coord_Bin[j] <= 1) continue; 
            if (0 > Coord_Index[j] || Coord_Index[j] >= Vars->Coord_Bin[j]) { 
              flag_outside=1; XY=0; break;
            }
            XY += Coord_Index[j]*Vars->Coord_BinProd[j-1];
          }
	  if (Vars->Flag_mantid && Vars->Flag_OFF && Vars->OFF_polyidx >=0) XY=Vars->OFF_polyidx;
          if (!flag_outside) XY += Vars->Coord_Min[i];
        }
        
        /* handle 'abs' and 'log' keywords */
        if (Vars->Coord_Type[i] & DEFS->COORD_ABS) XY=fabs(XY);

        if (Vars->Coord_Type[i] & DEFS->COORD_LOG) /* compute log of variable if requested */
        {  if (XY > 0) XY = log(XY)/log(10);
           else        XY = -100; }

        Coord[i] = XY; Coord_Index[i] = 0;
        if (i == 0) { pp = XY; Coord_Index[i] = 0; }
        else {
        /* check bounds for variables which have no automatic limits */
          if ((!Vars->Flag_Auto_Limits || !(Vars->Coord_Type[i] & DEFS->COORD_AUTO)) && Vars->Coord_Bin[i]>1)
          { /* compute index in histograms for each variable to monitor */
            XY = (Vars->Coord_Max[i]-Vars->Coord_Min[i]);
            if (XY > 0) Coord_Index[i] = floor((Coord[i]-Vars->Coord_Min[i])*Vars->Coord_Bin[i]/XY);
            if (Vars->Flag_With_Borders)
            {
              if (Coord_Index[i] >= Vars->Coord_Bin[i]) Coord_Index[i] = Vars->Coord_Bin[i] - 1;
              if (Coord_Index[i] < 0) Coord_Index[i] = 0;
            }
            //if (0 > Coord_Index[i] || Coord_Index[i] >= Vars->Coord_Bin[i])
            //  outsidebounds=1;
          } /* else will get Index later from Buffer when Flag_Auto_Limits == 2 */
        }
        
      } /* end for i */
      While_End = 1;
    }/* end else if Vars->Flag_Auto_Limits == 2 */
    
    /* ====================================================================== */
    /* store n1d/2d neutron from Buffer (Auto_Limits == 2) or current neutron in while */
    if (Vars->Flag_Auto_Limits != 1) /* not when storing auto limits Buffer */
    {
      /* apply per cm2 */
      if (Vars->Flag_per_cm2 && Vars->area != 0)
        pp /= Vars->area;

      /* 2D case : Vars->Coord_Number==2 and !Vars->Flag_Multiple and !Vars->Flag_List */
      if ( Vars->Coord_NumberNoPixel == 2 && !Vars->Flag_Multiple)
      { /* Dim : Vars->Coord_Bin[1]*Vars->Coord_Bin[2] matrix */
        
        i = Coord_Index[1];
        j = Coord_Index[2];
        if (i >= 0 && i < Vars->Coord_Bin[1] && j >= 0 && j < Vars->Coord_Bin[2])
        {
          if (Vars->Mon2D_N) {
	    double p2 = pp*pp;
            #pragma acc atomic
	    Vars->Mon2D_N[i][j] = Vars->Mon2D_N[i][j]+1;
            #pragma acc atomic
	    Vars->Mon2D_p[i][j] = Vars->Mon2D_p[i][j]+pp;
            #pragma acc atomic
	    Vars->Mon2D_p2[i][j] = Vars->Mon2D_p2[i][j] + p2;
	  }
        } else {
          outsidebounds=1; 
        }
      } else {
        /* 1D and n1D case : Vars->Flag_Multiple */
        /* Dim : Vars->Coord_Number*Vars->Coord_Bin[i] vectors (intensity is not included) */
          
        for (i= 1; i <= Vars->Coord_Number; i++) {
          j = Coord_Index[i];
          if (j >= 0 && j < Vars->Coord_Bin[i]) {
            if  (Vars->Flag_Multiple && Vars->Mon2D_N) {
	      if (Vars->Mon2D_N) {
		double p2 = pp*pp;
                #pragma acc atomic
		Vars->Mon2D_N[i-1][j] = Vars->Mon2D_N[i-1][j]+1;
                #pragma acc atomic
		Vars->Mon2D_p[i-1][j] = Vars->Mon2D_p[i-1][j]+pp;
		#pragma acc atomic
		Vars->Mon2D_p2[i-1][j] = Vars->Mon2D_p2[i-1][j] + p2;
	      }
	    }
          } else { 
            outsidebounds=1;
            break;
          }
        }
      }
    } /* end (Vars->Flag_Auto_Limits != 1) */
    
    if (Vars->Flag_Auto_Limits != 2 && !outsidebounds) /* not when reading auto limits Buffer */
    { /* now store Coord into Buffer (no index needed) if necessary (list or auto limits) */
      if ((Vars->Buffer_Counter < Vars->Buffer_Block) && ((Vars->Flag_List) || (Vars->Flag_Auto_Limits == 1)))
      {
        for (i = 0; i <= Vars->Coord_Number; i++)
        {
	  // This is is where the list is appended. How to make this "atomic"?
          #pragma acc atomic write 
          Vars->Mon2D_Buffer[i + Vars->Buffer_Counter*(Vars->Coord_Number+1)] = Coord[i];
        }
	    #pragma acc atomic update
        Vars->Buffer_Counter = Vars->Buffer_Counter + 1;
        if (Vars->Flag_Verbose && (Vars->Buffer_Counter >= Vars->Buffer_Block) && (Vars->Flag_List == 1)) 
          printf("Monitor_nD: %s %li neutrons stored in List.\n", Vars->compcurname, Vars->Buffer_Counter);
      }
    } /* end (Vars->Flag_Auto_Limits != 2) */
    
  } /* end while */
  #pragma acc atomic
  Vars->Nsum = Vars->Nsum + 1;
  #pragma acc atomic
  Vars->psum  = Vars->psum + pp;
  #pragma acc atomic
  Vars->p2sum = Vars->p2sum + pp*pp;

  /*determine return value: 1:neutron was in bounds and measured, -1: outside bounds, 0: outside bounds, should be absorbed.*/
  if(outsidebounds){
      if(Vars->Flag_Absorb){
          return 0;
      }else{
          return -1;
      }
  } else {
   /* For the OPENACC list buffer an atomic capture/update of the
      updated Neutron_counter - updated below under list mode 
	  Only need to be updated when inside bounds. */
   #pragma acc atomic update
   Vars->Neutron_Counter++;
  }
  return 1;
} /* end Monitor_nD_Trace */

/* ========================================================================= */
/* Monitor_nD_Save: this routine is used to save data files                  */
/* ========================================================================= */

MCDETECTOR Monitor_nD_Save(MonitornD_Defines_type *DEFS, MonitornD_Variables_type *Vars)
  {
    char   *fname;
    long    i,j;
    double *p0m = NULL;
    double *p1m = NULL;
    double *p2m = NULL;
    char    Coord_X_Label[CHAR_BUF_LENGTH];
    double  min1d, max1d;
    double  min2d, max2d;
    char    While_End = 0;
    long    While_Buffer = 0;
    double  XY=0, pp=0;
    double  Coord[MONnD_COORD_NMAX];
    long    Coord_Index[MONnD_COORD_NMAX];
    char    label[CHAR_BUF_LENGTH];

    MCDETECTOR detector;
    strcpy(detector.options,Vars->option);
    if (Vars->Flag_Verbose && Vars->Flag_per_cm2) {
      printf("Monitor_nD: %s: active flat detector area is %g [cm^2], total area is %g [cm^2]\n",
        Vars->compcurname, (Vars->max_x-Vars->min_x)
                          *(Vars->max_y-Vars->min_y)*1E4, Vars->area);
      printf("Monitor_nD: %s: beam solid angle is %g [st] (%g x %g [deg^2])\n",
        Vars->compcurname,
        2*fabs(2*atan2(Vars->mean_dx,Vars->mean_p)
         *sin(2*atan2(Vars->mean_dy,Vars->mean_p)/2)),
        atan2(Vars->mean_dx,Vars->mean_p)*RAD2DEG,
        atan2(Vars->mean_dy,Vars->mean_p)*RAD2DEG);
    }

    /* check Buffer flush when end of simulation reached */
    if ((Vars->Buffer_Counter <= Vars->Buffer_Block) && Vars->Flag_Auto_Limits && Vars->Mon2D_Buffer && Vars->Buffer_Counter)
    {
      /* Get Auto Limits */
      if (Vars->Flag_Verbose) printf("Monitor_nD: %s getting %li Auto Limits from List (%li events).\n", Vars->compcurname, Vars->Coord_Number, Vars->Buffer_Counter);

      for (i = 1; i <= Vars->Coord_Number; i++)
      {
        if ((Vars->Coord_Type[i] & DEFS->COORD_AUTO) && Vars->Coord_Bin[i] > 1)
        {
          Vars->Coord_Min[i] = FLT_MAX;
          Vars->Coord_Max[i] = -FLT_MAX;
          for (j = 0; j < Vars->Buffer_Counter; j++)
          {
            XY = Vars->Mon2D_Buffer[i+j*(Vars->Coord_Number+1)];  /* scanning variables in Buffer */
            if (XY < Vars->Coord_Min[i]) Vars->Coord_Min[i] = XY;
            if (XY > Vars->Coord_Max[i]) Vars->Coord_Max[i] = XY;
          }
          if  (Vars->Flag_Verbose)  
            printf("  %s: min=%g max=%g in %li bins\n", Vars->Coord_Var[i], Vars->Coord_Min[i], Vars->Coord_Max[i], Vars->Coord_Bin[i]);
        }
      }
      Vars->Flag_Auto_Limits = 2;  /* pass to 2nd auto limits step */
      Vars->Buffer_Block = Vars->Buffer_Counter;

      while (!While_End)
      { /* we generate Coord[] and Coord_index[] from Buffer (auto limits) */
        /* simulation ended before Buffer was filled. Limits have to be computed, and stored events must be sent into histograms */
        
        if (While_Buffer < Vars->Buffer_Block)
        {
          /* first while loops (While_Buffer) */
          Coord[0] = Vars->Mon2D_Buffer[While_Buffer*(Vars->Coord_Number+1)];

          /* auto limits case : scan Buffer within limits and store in Mon2D */
          for (i = 1; i <= Vars->Coord_Number; i++)
          {
            /* scanning variables in Buffer */
            if (Vars->Coord_Bin[i] <= 1) Coord_Index[i] = 0;
            else {
              XY = (Vars->Coord_Max[i]-Vars->Coord_Min[i]);
              Coord[i] = Vars->Mon2D_Buffer[i+While_Buffer*(Vars->Coord_Number+1)];
              if (XY > 0) Coord_Index[i] = floor((Coord[i]-Vars->Coord_Min[i])*Vars->Coord_Bin[i]/XY);
              else Coord_Index[i] = 0;
              if (Vars->Flag_With_Borders)
              {
                if (Coord_Index[i] < 0) Coord_Index[i] = 0;
                if (Coord_Index[i] >= Vars->Coord_Bin[i]) Coord_Index[i] = Vars->Coord_Bin[i] - 1;
              }
            }
          } /* end for */

          /* update the PixelID, we compute it from the previous variables index */
          for (i = 1; i <= Vars->Coord_Number; i++) {
            char Set_Vars_Coord_Type = (Vars->Coord_Type[i] & (DEFS->COORD_LOG-1));
            if (Set_Vars_Coord_Type == DEFS->COORD_PIXELID) {
              char outsidebounds=0;
              Coord_Index[i] = Coord[i] = 0;
              for (j= 1; j < i; j++) {
                /* not for 1D variables with Bin=1 such as PixelID, NCOUNT, Intensity */
                if (Vars->Coord_Bin[j] == 1) continue; 
                if (0 > Coord_Index[j] || Coord_Index[j] >= Vars->Coord_Bin[j]) {
                  outsidebounds=1;
                  Coord[i] = 0;
                  break;
                }
                Coord[i] += Coord_Index[j]*Vars->Coord_BinProd[j-1];
              }
              if (!outsidebounds) {
                Vars->Mon2D_Buffer[i+While_Buffer*(Vars->Coord_Number+1)] = Coord[i];
              }
            } /* end if PixelID */
          }
          While_Buffer++;
        } /* end if in Buffer */
        else /* (While_Buffer >= Vars->Buffer_Block) && (Vars->Flag_Auto_Limits == 2) */
        {
          Vars->Flag_Auto_Limits = 0;
          While_End = 1;
          if (Vars->Flag_Verbose) printf("Monitor_nD: %s flushed %li Auto Limits from List (%li).\n", Vars->compcurname, Vars->Coord_Number, Vars->Buffer_Counter);
        }

        /* store n1d/2d section from Buffer */

        pp = Coord[0];
        /* apply per cm2 or per st */
        if (Vars->Flag_per_cm2 && Vars->area      != 0)
          pp /= Vars->area;
        
        /* 2D case : Vars->Coord_Number==2 and !Vars->Flag_Multiple and !Vars->Flag_List */
        if (!Vars->Flag_Multiple && Vars->Coord_NumberNoPixel == 2)
        { /* Dim : Vars->Coord_Bin[1]*Vars->Coord_Bin[2] matrix */
          i = Coord_Index[1];
          j = Coord_Index[2];
          if (i >= 0 && i < Vars->Coord_Bin[1] && j >= 0 && j < Vars->Coord_Bin[2])
          {
            if (Vars->Mon2D_N) {
              Vars->Mon2D_N[i][j]++;
              Vars->Mon2D_p[i][j] += pp;
              Vars->Mon2D_p2[i][j] += pp*pp;
            }
          } else if (Vars->Flag_Absorb) pp=0;
        }
        else
        /* 1D and n1D case : Vars->Flag_Multiple */
        { /* Dim : Vars->Coord_Number*Vars->Coord_Bin[i] vectors (intensity is not included) */
          for (i= 1; i <= Vars->Coord_Number; i++)
          {
            j = Coord_Index[i];
            if (j >= 0 && j < Vars->Coord_Bin[i])
            {
              if (Vars->Flag_Multiple && Vars->Mon2D_N) {
                Vars->Mon2D_N[i-1][j]++;
                Vars->Mon2D_p[i-1][j] += pp;
                Vars->Mon2D_p2[i-1][j] += pp*pp;
              }
            } else if (Vars->Flag_Absorb) {
              pp=0; break;
            }
          }
        } /* end store 2D/1D */
        
      } /* end while */
    } /* end Force Get Limits */

    /* write output files (sent to file as p[i*n + j] vectors) */
    if (Vars->Coord_Number == 0)
    {
      double Nsum;
      double psum, p2sum;
      Nsum = Vars->Nsum;
      psum = Vars->psum;
      p2sum= Vars->p2sum;
      if (Vars->Flag_signal != DEFS->COORD_P && Nsum > 0)
      { psum /=Nsum; p2sum /= Nsum*Nsum; }
      /* DETECTOR_OUT_0D(Vars->Monitor_Label, Vars->Nsum, Vars->psum, Vars->p2sum); */
      detector = mcdetector_out_0D(Vars->Monitor_Label, Nsum, psum, p2sum, Vars->compcurname, Vars->compcurpos, Vars->compcurrot,Vars->compcurindex);
    }
    else
    if (strlen(Vars->Mon_File) > 0)
    {
      fname = (char*)malloc(strlen(Vars->Mon_File)+10*Vars->Coord_Number);
      if (Vars->Flag_List && Vars->Mon2D_Buffer) /* List: DETECTOR_OUT_2D */
      {
       
        if (Vars->Flag_List >= 2) Vars->Buffer_Size = Vars->Neutron_Counter;
        if (Vars->Buffer_Size >= Vars->Neutron_Counter)
          Vars->Buffer_Size = Vars->Neutron_Counter;
        strcpy(fname,Vars->Mon_File);
        if (strchr(Vars->Mon_File,'.') == NULL) strcat(fname, "_list");

        strcpy(Coord_X_Label,"");
        for (i= 0; i <= Vars->Coord_Number; i++)
        {
          strcat(Coord_X_Label, Vars->Coord_Var[i]);
          strcat(Coord_X_Label, " ");
          if (strchr(Vars->Mon_File,'.') == NULL)
          { strcat(fname, "."); strcat(fname, Vars->Coord_Var[i]); }
        }
        if (Vars->Flag_Verbose) printf("Monitor_nD: %s write monitor file %s List (%lix%li).\n", Vars->compcurname, fname,(long int)Vars->Neutron_Counter,Vars->Coord_Number);

        /* handle the type of list output */
        strcpy(label, Vars->Monitor_Label);
        
        detector = mcdetector_out_list(
              label, "List of neutron events", Coord_X_Label,
              -Vars->Buffer_Size, Vars->Coord_Number+1,
              Vars->Mon2D_Buffer,
              fname, Vars->compcurname, Vars->compcurpos, Vars->compcurrot, Vars->option,Vars->compcurindex);
      }
      if (Vars->Flag_Multiple) /* n1D: DETECTOR_OUT_1D */
      {
        for (i= 0; i < Vars->Coord_Number; i++)
        {

          strcpy(fname,Vars->Mon_File);
          if (strchr(Vars->Mon_File,'.') == NULL)
          { strcat(fname, "."); strcat(fname, Vars->Coord_Var[i+1]); }
          sprintf(Coord_X_Label, "%s monitor", Vars->Coord_Label[i+1]);
          strcpy(label, Coord_X_Label);
          if (Vars->Coord_Bin[i+1] > 0) { /* 1D monitor */
            if (Vars->Flag_Verbose) printf("Monitor_nD: %s write monitor file %s 1D (%li).\n", Vars->compcurname, fname, Vars->Coord_Bin[i+1]);
            min1d = Vars->Coord_Min[i+1];
            max1d = Vars->Coord_Max[i+1];
            if (min1d == max1d) max1d = min1d+1e-6;
            p1m = (double *)malloc(Vars->Coord_Bin[i+1]*sizeof(double));
            p2m = (double *)malloc(Vars->Coord_Bin[i+1]*sizeof(double));
            if (p2m == NULL) /* use Raw Buffer line output */
            {
              if (Vars->Flag_Verbose) printf("Monitor_nD: %s cannot allocate memory for output. Using raw data.\n", Vars->compcurname);
              if (p1m != NULL) free(p1m);
              detector = mcdetector_out_1D(
              label,
              Vars->Coord_Label[i+1],
              Vars->Coord_Label[0],
              Vars->Coord_Var[i+1],
              min1d, max1d,
              Vars->Coord_Bin[i+1],
              Vars->Mon2D_N[i],Vars->Mon2D_p[i],Vars->Mon2D_p2[i],
              fname, Vars->compcurname, Vars->compcurpos, Vars->compcurrot,Vars->compcurindex);
            } /* if (p2m == NULL) */
            else
            {
              if (Vars->Flag_log != 0)
              {
                XY = FLT_MAX;
                for (j=0; j < Vars->Coord_Bin[i+1]; j++) /* search min of signal */
                  if ((XY > Vars->Mon2D_p[i][j]) && (Vars->Mon2D_p[i][j] > 0)) XY = Vars->Mon2D_p[i][j];
                if (XY <= 0) XY = -log(FLT_MAX)/log(10); else XY = log(XY)/log(10)-1;
              } /* if */

              for (j=0; j < Vars->Coord_Bin[i+1]; j++)
              {
                p1m[j] = Vars->Mon2D_p[i][j];
                p2m[j] = Vars->Mon2D_p2[i][j];
                if (Vars->Flag_signal != DEFS->COORD_P && Vars->Mon2D_N[i][j] > 0)
                { /* normalize mean signal to the number of events */
                  p1m[j] /= Vars->Mon2D_N[i][j];
                  p2m[j] /= Vars->Mon2D_N[i][j]*Vars->Mon2D_N[i][j];
                }
                if (Vars->Flag_log != 0)
                {
                  if ((p1m[j] > 0) && (p2m[j] > 0))
                  {
                    p2m[j] /= p1m[j]*p1m[j];
                    p1m[j] = log(p1m[j])/log(10);
                  }
                  else
                  {
                    p1m[j] = XY;
                    p2m[j] = 0;
                  }
                }
              } /* for */
              detector = mcdetector_out_1D(
                label,
                Vars->Coord_Label[i+1],
                Vars->Coord_Label[0],
                Vars->Coord_Var[i+1],
                min1d, max1d,
                Vars->Coord_Bin[i+1],
                Vars->Mon2D_N[i],p1m,p2m,
                fname, Vars->compcurname, Vars->compcurpos, Vars->compcurrot,Vars->compcurindex);

            } /* else */
            /* comment out 'free memory' lines to avoid loosing arrays if
               'detector' structure is used by other instrument parts
            if (p1m != NULL) free(p1m); p1m=NULL;
            if (p2m != NULL) free(p2m); p2m=NULL;
            */
          } else { /* 0d monitor */
            detector = mcdetector_out_0D(label, Vars->Mon2D_p[i][0], Vars->Mon2D_p2[i][0], Vars->Mon2D_N[i][0], Vars->compcurname, Vars->compcurpos, Vars->compcurrot,Vars->compcurindex);
          }


        } /* for */
      } /* if 1D */
      else
      if (Vars->Coord_NumberNoPixel == 2)  /* 2D: DETECTOR_OUT_2D */
      {
        strcpy(fname,Vars->Mon_File);

        p0m = (double *)malloc(Vars->Coord_Bin[1]*Vars->Coord_Bin[2]*sizeof(double));
        p1m = (double *)malloc(Vars->Coord_Bin[1]*Vars->Coord_Bin[2]*sizeof(double));
        p2m = (double *)malloc(Vars->Coord_Bin[1]*Vars->Coord_Bin[2]*sizeof(double));
        if (p2m == NULL)
        {
          if (Vars->Flag_Verbose) printf("Monitor_nD: %s cannot allocate memory for 2D array (%zi). Skipping.\n", Vars->compcurname, 3*Vars->Coord_Bin[1]*Vars->Coord_Bin[2]*sizeof(double));
          /* comment out 'free memory' lines to avoid loosing arrays if
               'detector' structure is used by other instrument parts
          if (p0m != NULL) free(p0m);
          if (p1m != NULL) free(p1m);
          */
        }
        else
        {
          if (Vars->Flag_log != 0)
          {
            XY = FLT_MAX;
            for (i= 0; i < Vars->Coord_Bin[1]; i++)
              for (j= 0; j < Vars->Coord_Bin[2]; j++) /* search min of signal */
                if ((XY > Vars->Mon2D_p[i][j]) && (Vars->Mon2D_p[i][j]>0)) XY = Vars->Mon2D_p[i][j];
            if (XY <= 0) XY = -log(FLT_MAX)/log(10); else XY = log(XY)/log(10)-1;
          }
          for (i= 0; i < Vars->Coord_Bin[1]; i++)
          {
            for (j= 0; j < Vars->Coord_Bin[2]; j++)
            {
              long index;
              index = j + i*Vars->Coord_Bin[2];
              p0m[index] = Vars->Mon2D_N[i][j];
              p1m[index] = Vars->Mon2D_p[i][j];
              p2m[index] = Vars->Mon2D_p2[i][j];
              if (Vars->Flag_signal != DEFS->COORD_P && p0m[index] > 0)
              {
                  p1m[index] /= p0m[index];
                  p2m[index] /= p0m[index]*p0m[index];
              }

              if (Vars->Flag_log != 0)
              {
                if ((p1m[index] > 0) && (p2m[index] > 0))
                {
                  p2m[index] /= (p1m[index]*p1m[index]);
                  p1m[index] = log(p1m[index])/log(10);

                }
                else
                {
                  p1m[index] = XY;
                  p2m[index] = 0;
                }
              }
            }
          }
          if (strchr(Vars->Mon_File,'.') == NULL)
          { strcat(fname, "."); strcat(fname, Vars->Coord_Var[1]);
              strcat(fname, "_"); strcat(fname, Vars->Coord_Var[2]); }
          if (Vars->Flag_Verbose) printf("Monitor_nD: %s write monitor file %s 2D (%lix%li).\n", Vars->compcurname, fname, Vars->Coord_Bin[1], Vars->Coord_Bin[2]);

          min1d = Vars->Coord_Min[1];
          max1d = Vars->Coord_Max[1];
          if (min1d == max1d) max1d = min1d+1e-6;
          min2d = Vars->Coord_Min[2];
          max2d = Vars->Coord_Max[2];
          if (min2d == max2d) max2d = min2d+1e-6;
          strcpy(label, Vars->Monitor_Label);
          if (Vars->Coord_Bin[1]*Vars->Coord_Bin[2] > 1
           && Vars->Flag_signal == DEFS->COORD_P)
            strcat(label, " per bin");
	  if (Vars->Flag_List) {
            detector = mcdetector_out_2D_list(
              label,
              Vars->Coord_Label[1],
	      Vars->Coord_Label[2],
	      min1d, max1d,
	      min2d, max2d,
	      Vars->Coord_Bin[1],
	      Vars->Coord_Bin[2],
	      p0m,p1m,p2m,
	      fname, Vars->compcurname, Vars->compcurpos, Vars->compcurrot,Vars->option,Vars->compcurindex);
	  } else {
            detector = mcdetector_out_2D(
              label,
              Vars->Coord_Label[1],
	      Vars->Coord_Label[2],
	      min1d, max1d,
	      min2d, max2d,
	      Vars->Coord_Bin[1],
	      Vars->Coord_Bin[2],
	      p0m,p1m,p2m,
	      fname, Vars->compcurname, Vars->compcurpos, Vars->compcurrot,Vars->compcurindex);
	  }

          /* comment out 'free memory' lines to avoid loosing arrays if
               'detector' structure is used by other instrument parts
          if (p0m != NULL) free(p0m);
          if (p1m != NULL) free(p1m);
          if (p2m != NULL) free(p2m);
          */
        }
      }
      free(fname);
    }
    return(detector);
  } /* end Monitor_nD_Save */

/* ========================================================================= */
/* Monitor_nD_Finally: this routine is used to free memory                   */
/* ========================================================================= */

void Monitor_nD_Finally(MonitornD_Defines_type *DEFS,
  MonitornD_Variables_type *Vars)
  {
    int i;

    /* Now Free memory Mon2D.. */
    if ((Vars->Flag_Auto_Limits || Vars->Flag_List) && Vars->Coord_Number)
    { /* Dim : (Vars->Coord_Number+1)*Vars->Buffer_Block matrix (for p, dp) */
      if (Vars->Mon2D_Buffer != NULL) free(Vars->Mon2D_Buffer);
    }

    /* 1D and n1D case : Vars->Flag_Multiple */
    if (Vars->Flag_Multiple && Vars->Coord_Number)
    { /* Dim : Vars->Coord_Number*Vars->Coord_Bin[i] vectors */
      for (i= 0; i < Vars->Coord_Number; i++)
      {
        free(Vars->Mon2D_N[i]);
        free(Vars->Mon2D_p[i]);
        free(Vars->Mon2D_p2[i]);
      }
      free(Vars->Mon2D_N);
      free(Vars->Mon2D_p);
      free(Vars->Mon2D_p2);
    }


    /* 2D case : Vars->Coord_Number==2 and !Vars->Flag_Multiple and !Vars->Flag_List */
    if ((Vars->Coord_NumberNoPixel == 2) && !Vars->Flag_Multiple)
    { /* Dim : Vars->Coord_Bin[1]*Vars->Coord_Bin[2] matrix */
      for (i= 0; i < Vars->Coord_Bin[1]; i++)
      {
        free(Vars->Mon2D_N[i]);
        free(Vars->Mon2D_p[i]);
        free(Vars->Mon2D_p2[i]);
      }
      free(Vars->Mon2D_N);
      free(Vars->Mon2D_p);
      free(Vars->Mon2D_p2);
    }
  } /* end Monitor_nD_Finally */

/* ========================================================================= */
/* Monitor_nD_McDisplay: this routine is used to display component           */
/* ========================================================================= */

void Monitor_nD_McDisplay(MonitornD_Defines_type *DEFS,
  MonitornD_Variables_type *Vars)
  {
    double radius, h;
    double xmin;
    double xmax;
    double ymin;
    double ymax;
    double zmin;
    double zmax;
    int    i;
    double hdiv_min=-180, hdiv_max=180, vdiv_min=-90, vdiv_max=90;
    char   restricted = 0;

    radius = Vars->Sphere_Radius;
    h = Vars->Cylinder_Height;
    xmin = Vars->mxmin;
    xmax = Vars->mxmax;
    ymin = Vars->mymin;
    ymax = Vars->mymax;
    zmin = Vars->mzmin;
    zmax = Vars->mzmax;

    /* determine if there are angular limits set at start (no auto) in coord_types
     * cylinder/banana: look for hdiv
     * sphere: look for angle, radius (->atan2(val,radius)), hdiv, vdiv
     * this activates a 'restricted' flag, to draw a region as blades on cylinder/sphere
     */
    for (i= 0; i <= Vars->Coord_Number; i++)
    {
      int Set_Vars_Coord_Type;
      Set_Vars_Coord_Type = (Vars->Coord_Type[i] & (DEFS->COORD_LOG-1));
      if (Set_Vars_Coord_Type == DEFS->COORD_HDIV || Set_Vars_Coord_Type == DEFS->COORD_THETA)
      { hdiv_min = Vars->Coord_Min[i]; hdiv_max = Vars->Coord_Max[i]; restricted = 1; }
      else if (Set_Vars_Coord_Type == DEFS->COORD_VDIV || Set_Vars_Coord_Type == DEFS->COORD_PHI)
      { vdiv_min = Vars->Coord_Min[i]; vdiv_max = Vars->Coord_Max[i];restricted = 1;  }
      else if (Set_Vars_Coord_Type == DEFS->COORD_ANGLE)
      { hdiv_min = vdiv_min = Vars->Coord_Min[i];
        hdiv_max = vdiv_max = Vars->Coord_Max[i];
        restricted = 1; }
      else if (Set_Vars_Coord_Type == DEFS->COORD_RADIUS)
      { double angle;
        angle = RAD2DEG*atan2(Vars->Coord_Max[i], radius);
        hdiv_min = vdiv_min = angle;
        hdiv_max = vdiv_max = angle;
        restricted = 1; }
      else if (Set_Vars_Coord_Type == DEFS->COORD_Y && abs(Vars->Flag_Shape) == DEFS->SHAPE_SPHERE)
      {
        vdiv_min = atan2(ymin,radius)*RAD2DEG;
        vdiv_max = atan2(ymax,radius)*RAD2DEG;
        restricted = 1;
      }
    }
    /* full sphere */
    if ((!restricted && (abs(Vars->Flag_Shape) == DEFS->SHAPE_SPHERE))
    || abs(Vars->Flag_Shape) == DEFS->SHAPE_PREVIOUS)
    {
      mcdis_magnify("");
      mcdis_circle("xy",0,0,0,radius);
      mcdis_circle("xz",0,0,0,radius);
      mcdis_circle("yz",0,0,0,radius);
    }
    /* banana/cylinder/sphere portion */
    else
    if (restricted && ((abs(Vars->Flag_Shape) == DEFS->SHAPE_CYLIND)
                    || (abs(Vars->Flag_Shape) == DEFS->SHAPE_BANANA)
                    || (abs(Vars->Flag_Shape) == DEFS->SHAPE_SPHERE)))
    {
      int NH=24, NV=24;
      int ih, iv;
      double width, height;
      int issphere;
      issphere = (abs(Vars->Flag_Shape) == DEFS->SHAPE_SPHERE);
      width = (hdiv_max-hdiv_min)/NH;
      if (!issphere) {
	NV=1; /* cylinder has vertical axis */
      }
      height= (vdiv_max-vdiv_min)/NV;
      
      /* check width and height of elements (sphere) to make sure the nb
         of plates remains limited */
      if (width < 10  && NH > 1) { width = 10;  NH=(hdiv_max-hdiv_min)/width; width=(hdiv_max-hdiv_min)/NH; }
      if (height < 10 && NV > 1) { height = 10; NV=(vdiv_max-vdiv_min)/height; height= (vdiv_max-vdiv_min)/NV; }
      
      mcdis_magnify("xyz");
      for(ih = 0; ih < NH; ih++)
        for(iv = 0; iv < NV; iv++)
        {
          double theta0, phi0, theta1, phi1;          /* angles in spherical coordinates */
          double x0,y0,z0,x1,y1,z1,x2,y2,z2,x3,y3,z3; /* vertices at plate edges */
          phi0 = (hdiv_min+ width*ih-90)*DEG2RAD;        /* in xz plane */
          phi1 = (hdiv_min+ width*(ih+1)-90)*DEG2RAD;
          if (issphere)
          {
            theta0= (vdiv_min+height* iv + 90)   *DEG2RAD; /* in vertical plane */
            theta1= (vdiv_min+height*(iv+1) + 90)*DEG2RAD;
            
            y0 = -radius*cos(theta0);            /* z with Z vertical */
            y1 = -radius*cos(theta1);
            if (y0 < ymin) y0=ymin;
            if (y0 > ymax) y0=ymax;
            if (y1 < ymin) y1=ymin;
            if (y1 > ymax) y1=ymax;
          } else {
            y0 = ymin;
            y1 = ymax;
            theta0=theta1=90*DEG2RAD;
          }

          x0 = radius*sin(theta0)*cos(phi0); /* x with Z vertical */
          z0 =-radius*sin(theta0)*sin(phi0); /* y with Z vertical */
          x1 = radius*sin(theta1)*cos(phi0); 
          z1 =-radius*sin(theta1)*sin(phi0);
          x2 = radius*sin(theta1)*cos(phi1); 
          z2 =-radius*sin(theta1)*sin(phi1);
          x3 = radius*sin(theta0)*cos(phi1); 
          z3 =-radius*sin(theta0)*sin(phi1);
          y2 = y1; y3 = y0;

          mcdis_multiline(5,
            x0,y0,z0,
            x1,y1,z1,
            x2,y2,z2,
            x3,y3,z3,
            x0,y0,z0);
        }
      if (Vars->Flag_mantid) {
	/* First define the base pixel type */
	double dt, dy;
	dt = (Vars->Coord_Max[1]-Vars->Coord_Min[1])/Vars->Coord_Bin[1];
	dy = (Vars->Coord_Max[2]-Vars->Coord_Min[2])/Vars->Coord_Bin[2];
	printf("MANTID_BANANA_DET:  %g, %g, %g, %g, %g, %li, %li, %llu\n", radius, 
	       Vars->Coord_Min[1],Vars->Coord_Max[1], Vars->Coord_Min[2],Vars->Coord_Max[2], Vars->Coord_Bin[1], Vars->Coord_Bin[2], (long long unsigned)Vars->Coord_Min[4]); 
      }
    }
    /* disk (circle) */
    else
    if (abs(Vars->Flag_Shape) == DEFS->SHAPE_DISK)
    {
      mcdis_magnify("");
      mcdis_circle("xy",0,0,0,radius);
    }
    /* rectangle (square) */
    else
    if (abs(Vars->Flag_Shape) == DEFS->SHAPE_SQUARE)
    {
      mcdis_magnify("xy");
      mcdis_multiline(5, (double)xmin, (double)ymin, 0.0,
             (double)xmax, (double)ymin, 0.0,
             (double)xmax, (double)ymax, 0.0,
             (double)xmin, (double)ymax, 0.0,
             (double)xmin, (double)ymin, 0.0);
      
      if (Vars->Flag_mantid) {
	/* First define the base pixel type */
	double dx, dy;
	dx = (Vars->Coord_Max[1]-Vars->Coord_Min[1])/Vars->Coord_Bin[1];
	dy = (Vars->Coord_Max[2]-Vars->Coord_Min[2])/Vars->Coord_Bin[2];
	printf("MANTID_RECTANGULAR_DET:  %g, %g, %g, %g, %li, %li, %llu\n", 
	       Vars->Coord_Min[1],Vars->Coord_Max[1], Vars->Coord_Min[2],Vars->Coord_Max[2], Vars->Coord_Bin[1], Vars->Coord_Bin[2], (long long unsigned)Vars->Coord_Min[4]);
      }
    }
    /* full cylinder/banana */
    else
    if (!restricted && ((abs(Vars->Flag_Shape) == DEFS->SHAPE_CYLIND) || (abs(Vars->Flag_Shape) == DEFS->SHAPE_BANANA)))
    {
      mcdis_magnify("xyz");
      mcdis_circle("xz", 0,  h/2.0, 0, radius);
      mcdis_circle("xz", 0, -h/2.0, 0, radius);
      mcdis_line(-radius, -h/2.0, 0, -radius, +h/2.0, 0);
      mcdis_line(+radius, -h/2.0, 0, +radius, +h/2.0, 0);
      mcdis_line(0, -h/2.0, -radius, 0, +h/2.0, -radius);
      mcdis_line(0, -h/2.0, +radius, 0, +h/2.0, +radius);
    }
    else
    /* box */
    if (abs(Vars->Flag_Shape) == DEFS->SHAPE_BOX)
    {
      mcdis_magnify("xyz");
      mcdis_multiline(5, xmin, ymin, zmin,
                   xmax, ymin, zmin,
                   xmax, ymax, zmin,
                   xmin, ymax, zmin,
                   xmin, ymin, zmin);
      mcdis_multiline(5, xmin, ymin, zmax,
                   xmax, ymin, zmax,
                   xmax, ymax, zmax,
                   xmin, ymax, zmax,
                   xmin, ymin, zmax);
      mcdis_line(xmin, ymin, zmin, xmin, ymin, zmax);
      mcdis_line(xmax, ymin, zmin, xmax, ymin, zmax);
      mcdis_line(xmin, ymax, zmin, xmin, ymax, zmax);
      mcdis_line(xmax, ymax, zmin, xmax, ymax, zmax);
    }
  } /* end Monitor_nD_McDisplay */

/* end of monitor_nd-lib.c */






/* ************************************************************************** */
/*             End of SHARE user declarations for all components              */
/* ************************************************************************** */


/* ********************** component definition declarations. **************** */

/* component Origin=Arm() [1] DECLARE */
/* Parameter definition for component type 'Arm' */
struct _struct_Arm_parameters {
  char Arm_has_no_parameters;
}; /* _struct_Arm_parameters */
typedef struct _struct_Arm_parameters _class_Arm_parameters;

/* Parameters for component type 'Arm' */
struct _struct_Arm {
  char     _name[256]; /* e.g. Origin */
  char     _type[256]; /* Arm */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Arm_parameters _parameters;
};
typedef struct _struct_Arm _class_Arm;
_class_Arm _Origin_var;
#pragma acc declare create ( _Origin_var )

/* component SourceMantid=Commodus_I3() [2] DECLARE */
/* Parameter definition for component type 'Commodus_I3' */
struct _struct_Commodus_I3_parameters {
  /* Component type 'Commodus_I3' setting parameters */
  char Face[16384];
  MCNUM E0;
  MCNUM E1;
  MCNUM modPosition;
  MCNUM dist;
  int verbose;
  MCNUM beamcurrent;
  MCNUM modXsize;
  MCNUM modZsize;
  MCNUM xw;
  MCNUM yh;
  /* Component type 'Commodus_I3' private parameters */
  double  p_in;
  int  Tnpts;
  double  scaleSize;
  double  angleArea;
  double  Nsim;
  int  Ncount;
  Source_ViewMod  TS;
  double  fullAngle;
  double  rtE0;
  double  rtE1;
  double  xwidth;
  double  yheight;
  double  focus_xw;
  double  focus_yh;
}; /* _struct_Commodus_I3_parameters */
typedef struct _struct_Commodus_I3_parameters _class_Commodus_I3_parameters;

/* Parameters for component type 'Commodus_I3' */
struct _struct_Commodus_I3 {
  char     _name[256]; /* e.g. SourceMantid */
  char     _type[256]; /* Commodus_I3 */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Commodus_I3_parameters _parameters;
};
typedef struct _struct_Commodus_I3 _class_Commodus_I3;
_class_Commodus_I3 _SourceMantid_var;
#pragma acc declare create ( _SourceMantid_var )

/* component shutter=Guide_channeled() [3] DECLARE */
/* Parameter definition for component type 'Guide_channeled' */
struct _struct_Guide_channeled_parameters {
  /* Component type 'Guide_channeled' setting parameters */
  MCNUM w1;
  MCNUM h1;
  MCNUM w2;
  MCNUM h2;
  MCNUM l;
  MCNUM R0;
  MCNUM Qc;
  MCNUM alpha;
  MCNUM m;
  MCNUM nslit;
  MCNUM d;
  MCNUM Qcx;
  MCNUM Qcy;
  MCNUM alphax;
  MCNUM alphay;
  MCNUM W;
  MCNUM mx;
  MCNUM my;
  MCNUM nu;
  MCNUM phase;
  /* Component type 'Guide_channeled' private parameters */
  double  w1c;
  double  w2c;
  double  ww;
  double  hh;
  double  whalf;
  double  hhalf;
  double  lwhalf;
  double  lhhalf;
}; /* _struct_Guide_channeled_parameters */
typedef struct _struct_Guide_channeled_parameters _class_Guide_channeled_parameters;

/* Parameters for component type 'Guide_channeled' */
struct _struct_Guide_channeled {
  char     _name[256]; /* e.g. shutter */
  char     _type[256]; /* Guide_channeled */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Guide_channeled_parameters _parameters;
};
typedef struct _struct_Guide_channeled _class_Guide_channeled;
_class_Guide_channeled _shutter_var;
#pragma acc declare create ( _shutter_var )

_class_Guide_channeled _insert_var;
#pragma acc declare create ( _insert_var )

_class_Guide_channeled _after_insert_var;
#pragma acc declare create ( _after_insert_var )

/* component Monitor1=TOF_monitor() [6] DECLARE */
/* Parameter definition for component type 'TOF_monitor' */
struct _struct_TOF_monitor_parameters {
  /* Component type 'TOF_monitor' setting parameters */
  int nt;
  char filename[16384];
  MCNUM xmin;
  MCNUM xmax;
  MCNUM ymin;
  MCNUM ymax;
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM tmin;
  MCNUM tmax;
  MCNUM dt;
  int restore_neutron;
  int nowritefile;
  /* Component type 'TOF_monitor' private parameters */
  DArray1d  TOF_N;
  DArray1d  TOF_p;
  DArray1d  TOF_p2;
  double  t_min;
  double  t_max;
  double  delta_t;
}; /* _struct_TOF_monitor_parameters */
typedef struct _struct_TOF_monitor_parameters _class_TOF_monitor_parameters;

/* Parameters for component type 'TOF_monitor' */
struct _struct_TOF_monitor {
  char     _name[256]; /* e.g. Monitor1 */
  char     _type[256]; /* TOF_monitor */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_TOF_monitor_parameters _parameters;
};
typedef struct _struct_TOF_monitor _class_TOF_monitor;
_class_TOF_monitor _Monitor1_var;
#pragma acc declare create ( _Monitor1_var )

/* component LET_Chopper1_disk1=DiskChopper() [7] DECLARE */
/* Parameter definition for component type 'DiskChopper' */
struct _struct_DiskChopper_parameters {
  /* Component type 'DiskChopper' setting parameters */
  MCNUM theta_0;
  MCNUM radius;
  MCNUM yheight;
  MCNUM nu;
  MCNUM nslit;
  MCNUM jitter;
  MCNUM delay;
  MCNUM isfirst;
  MCNUM n_pulse;
  MCNUM abs_out;
  MCNUM phase;
  MCNUM xwidth;
  MCNUM verbose;
  /* Component type 'DiskChopper' private parameters */
  double  Tg;
  double  To;
  double  delta_y;
  double  height;
  double  omega;
}; /* _struct_DiskChopper_parameters */
typedef struct _struct_DiskChopper_parameters _class_DiskChopper_parameters;

/* Parameters for component type 'DiskChopper' */
struct _struct_DiskChopper {
  char     _name[256]; /* e.g. LET_Chopper1_disk1 */
  char     _type[256]; /* DiskChopper */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_DiskChopper_parameters _parameters;
};
typedef struct _struct_DiskChopper _class_DiskChopper;
_class_DiskChopper _LET_Chopper1_disk1_var;
#pragma acc declare create ( _LET_Chopper1_disk1_var )

_class_DiskChopper _LET_Chopper1_disk2_var;
#pragma acc declare create ( _LET_Chopper1_disk2_var )

_class_TOF_monitor _Monitor2_var;
#pragma acc declare create ( _Monitor2_var )

_class_Guide_channeled _between_chop1_and_chop2_var;
#pragma acc declare create ( _between_chop1_and_chop2_var )

_class_DiskChopper _LET_Chopper2_var;
#pragma acc declare create ( _LET_Chopper2_var )

_class_TOF_monitor _Monitor3_var;
#pragma acc declare create ( _Monitor3_var )

_class_Guide_channeled _between_chop2_and_chop3_var;
#pragma acc declare create ( _between_chop2_and_chop3_var )

_class_DiskChopper _LET_Chopper3_var;
#pragma acc declare create ( _LET_Chopper3_var )

_class_TOF_monitor _Monitor4_var;
#pragma acc declare create ( _Monitor4_var )

_class_Guide_channeled _between_chop3_and_chop4_var;
#pragma acc declare create ( _between_chop3_and_chop4_var )

_class_DiskChopper _LET_Chopper4_var;
#pragma acc declare create ( _LET_Chopper4_var )

_class_TOF_monitor _Monitor5_var;
#pragma acc declare create ( _Monitor5_var )

_class_Guide_channeled _between_chop4_and_movable_var;
#pragma acc declare create ( _between_chop4_and_movable_var )

/* component moveable_front_PSDmon=PSD_monitor() [20] DECLARE */
/* Parameter definition for component type 'PSD_monitor' */
struct _struct_PSD_monitor_parameters {
  /* Component type 'PSD_monitor' setting parameters */
  int nx;
  int ny;
  char filename[16384];
  MCNUM xmin;
  MCNUM xmax;
  MCNUM ymin;
  MCNUM ymax;
  MCNUM xwidth;
  MCNUM yheight;
  int restore_neutron;
  int nowritefile;
  /* Component type 'PSD_monitor' private parameters */
  DArray2d  PSD_N;
  DArray2d  PSD_p;
  DArray2d  PSD_p2;
}; /* _struct_PSD_monitor_parameters */
typedef struct _struct_PSD_monitor_parameters _class_PSD_monitor_parameters;

/* Parameters for component type 'PSD_monitor' */
struct _struct_PSD_monitor {
  char     _name[256]; /* e.g. moveable_front_PSDmon */
  char     _type[256]; /* PSD_monitor */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_PSD_monitor_parameters _parameters;
};
typedef struct _struct_PSD_monitor _class_PSD_monitor;
_class_PSD_monitor _moveable_front_PSDmon_var;
#pragma acc declare create ( _moveable_front_PSDmon_var )

/* component moveable_front_Divmon=Divergence_monitor() [21] DECLARE */
/* Parameter definition for component type 'Divergence_monitor' */
struct _struct_Divergence_monitor_parameters {
  /* Component type 'Divergence_monitor' setting parameters */
  int nh;
  int nv;
  char filename[16384];
  MCNUM xmin;
  MCNUM xmax;
  MCNUM ymin;
  MCNUM ymax;
  int nowritefile;
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM maxdiv_h;
  MCNUM maxdiv_v;
  int restore_neutron;
  MCNUM nx;
  MCNUM ny;
  MCNUM nz;
  /* Component type 'Divergence_monitor' private parameters */
  DArray2d  Div_N;
  DArray2d  Div_p;
  DArray2d  Div_p2;
}; /* _struct_Divergence_monitor_parameters */
typedef struct _struct_Divergence_monitor_parameters _class_Divergence_monitor_parameters;

/* Parameters for component type 'Divergence_monitor' */
struct _struct_Divergence_monitor {
  char     _name[256]; /* e.g. moveable_front_Divmon */
  char     _type[256]; /* Divergence_monitor */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Divergence_monitor_parameters _parameters;
};
typedef struct _struct_Divergence_monitor _class_Divergence_monitor;
_class_Divergence_monitor _moveable_front_Divmon_var;
#pragma acc declare create ( _moveable_front_Divmon_var )

_class_Guide_channeled _moveable_guide_var;
#pragma acc declare create ( _moveable_guide_var )

_class_PSD_monitor _moveable_back_PSDmon_var;
#pragma acc declare create ( _moveable_back_PSDmon_var )

_class_Divergence_monitor _moveable_back_Divmon_var;
#pragma acc declare create ( _moveable_back_Divmon_var )

_class_Guide_channeled _funnel_var;
#pragma acc declare create ( _funnel_var )

_class_DiskChopper _LET_Chopper5_Disk1_var;
#pragma acc declare create ( _LET_Chopper5_Disk1_var )

_class_DiskChopper _LET_Chopper5_Disk2_var;
#pragma acc declare create ( _LET_Chopper5_Disk2_var )

_class_TOF_monitor _Monitor6_var;
#pragma acc declare create ( _Monitor6_var )

_class_Guide_channeled _tanksection_var;
#pragma acc declare create ( _tanksection_var )

_class_Guide_channeled _snout_var;
#pragma acc declare create ( _snout_var )

_class_Arm _sample_var;
#pragma acc declare create ( _sample_var )

_class_PSD_monitor _sample_PSDmon_var;
#pragma acc declare create ( _sample_PSDmon_var )

_class_Divergence_monitor _sample_Divmon_var;
#pragma acc declare create ( _sample_Divmon_var )

_class_TOF_monitor _sample_tof_var;
#pragma acc declare create ( _sample_tof_var )

/* component sample_Emon=E_monitor() [35] DECLARE */
/* Parameter definition for component type 'E_monitor' */
struct _struct_E_monitor_parameters {
  /* Component type 'E_monitor' setting parameters */
  int nE;
  char filename[16384];
  MCNUM xmin;
  MCNUM xmax;
  MCNUM ymin;
  MCNUM ymax;
  int nowritefile;
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM Emin;
  MCNUM Emax;
  int restore_neutron;
  /* Component type 'E_monitor' private parameters */
  DArray1d  E_N;
  DArray1d  E_p;
  DArray1d  E_p2;
  double  S_p;
  double  S_pE;
  double  S_pE2;
}; /* _struct_E_monitor_parameters */
typedef struct _struct_E_monitor_parameters _class_E_monitor_parameters;

/* Parameters for component type 'E_monitor' */
struct _struct_E_monitor {
  char     _name[256]; /* e.g. sample_Emon */
  char     _type[256]; /* E_monitor */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_E_monitor_parameters _parameters;
};
typedef struct _struct_E_monitor _class_E_monitor;
_class_E_monitor _sample_Emon_var;
#pragma acc declare create ( _sample_Emon_var )

/* component iso_samp=Isotropic_Sqw() [36] DECLARE */
/* Parameter definition for component type 'Isotropic_Sqw' */
struct _struct_Isotropic_Sqw_parameters {
  /* Component type 'Isotropic_Sqw' setting parameters */
  MCNUM powder_format[9];
  char Sqw_coh[16384];
  char Sqw_inc[16384];
  char geometry[16384];
  MCNUM radius;
  MCNUM thickness;
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM zdepth;
  MCNUM threshold;
  int order;
  MCNUM T;
  MCNUM verbose;
  MCNUM d_phi;
  int concentric;
  MCNUM rho;
  MCNUM sigma_abs;
  MCNUM sigma_coh;
  MCNUM sigma_inc;
  MCNUM classical;
  MCNUM powder_Dd;
  MCNUM powder_DW;
  MCNUM powder_Vc;
  MCNUM density;
  MCNUM weight;
  MCNUM p_interact;
  MCNUM norm;
  MCNUM powder_barns;
  char quantum_correction[16384];
  /* Component type 'Isotropic_Sqw' private parameters */
  struct Sqw_sample_struct  VarSqw;
  int*  columns;
  off_struct  offdata;
}; /* _struct_Isotropic_Sqw_parameters */
typedef struct _struct_Isotropic_Sqw_parameters _class_Isotropic_Sqw_parameters;

/* Parameters for component type 'Isotropic_Sqw' */
struct _struct_Isotropic_Sqw {
  char     _name[256]; /* e.g. iso_samp */
  char     _type[256]; /* Isotropic_Sqw */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Isotropic_Sqw_parameters _parameters;
};
typedef struct _struct_Isotropic_Sqw _class_Isotropic_Sqw;
_class_Isotropic_Sqw _iso_samp_var;
#pragma acc declare create ( _iso_samp_var )

_class_Arm _detectorArm_var;
#pragma acc declare create ( _detectorArm_var )

/* component Banana_1=Monitor_nD() [38] DECLARE */
/* Parameter definition for component type 'Monitor_nD' */
struct _struct_Monitor_nD_parameters {
  /* Component type 'Monitor_nD' setting parameters */
  char user1[16384];
  char user2[16384];
  char user3[16384];
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM zdepth;
  MCNUM xmin;
  MCNUM xmax;
  MCNUM ymin;
  MCNUM ymax;
  MCNUM zmin;
  MCNUM zmax;
  int bins;
  MCNUM min;
  MCNUM max;
  int restore_neutron;
  MCNUM radius;
  char options[16384];
  char filename[16384];
  char geometry[16384];
  int nowritefile;
  int nexus_bins;
  char username1[16384];
  char username2[16384];
  char username3[16384];
  /* Component type 'Monitor_nD' private parameters */
  MonitornD_Defines_type  DEFS;
  MonitornD_Variables_type  Vars;
  MCDETECTOR  detector;
  off_struct  offdata;
}; /* _struct_Monitor_nD_parameters */
typedef struct _struct_Monitor_nD_parameters _class_Monitor_nD_parameters;

/* Parameters for component type 'Monitor_nD' */
struct _struct_Monitor_nD {
  char     _name[256]; /* e.g. Banana_1 */
  char     _type[256]; /* Monitor_nD */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  _class_Monitor_nD_parameters _parameters;
};
typedef struct _struct_Monitor_nD _class_Monitor_nD;
_class_Monitor_nD _Banana_1_var;
#pragma acc declare create ( _Banana_1_var )

int mcNUMCOMP = 38;

/* User declarations from instrument definition. Can define functions. */

double SE2K, v_foc, emin, emax, lam_min, lam_max, jitter=7e-7;
double Ch1_speed, Ch2_speed=10, Ch2_offset=14500, Ch4_speed, Ch5_slit, snout_length;
double L_Ch1=7.833, L_Ch2=8.200, L_Ch3=11.749, L_Ch4=15.664, L_Ch5=23.499;
double L_sample=25, L2=3.5, Ch1_5_halfgap=0.005, smidge = 0.001;
    

#undef compcurname
#undef compcurtype
#undef compcurindex
/* end of instrument 'ISIS_LET_generated' and components DECLARE */

/* *****************************************************************************
* instrument 'ISIS_LET_generated' and components INITIALISE
***************************************************************************** */

double index_getdistance(int first_index, int second_index)
/* Calculate the distance two components from their indexes*/
{
  return coords_len(coords_sub(POS_A_COMP_INDEX(first_index), POS_A_COMP_INDEX(second_index)));
}

double getdistance(char* first_component, char* second_component)
/* Calculate the distance between two named components */
{
  int first_index = _getcomp_index(first_component);
  int second_index = _getcomp_index(second_component);
  return index_getdistance(first_index, second_index);
}

double checked_setpos_getdistance(int current_index, char* first_component, char* second_component)
/* Calculate the distance between two named components at *_setpos() time, with component index checking */
{
  int first_index = _getcomp_index(first_component);
  int second_index = _getcomp_index(second_component);
  if (first_index >= current_index || second_index >= current_index) {
    printf("setpos_getdistance can only be used with the names of components before the current one!\n");
    return 0;
  }
  return index_getdistance(first_index, second_index);
}
#define setpos_getdistance(first, second) checked_setpos_getdistance(current_setpos_index, first, second)

/* component Origin=Arm() SETTING, POSITION/ROTATION */
int _Origin_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Origin_setpos] component Origin=Arm() SETTING [Arm:0]");
  stracpy(_Origin_var._name, "Origin", 16384);
  stracpy(_Origin_var._type, "Arm", 16384);
  _Origin_var._index=1;
  int current_setpos_index = 1;
  /* component Origin=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(_Origin_var._rotation_absolute,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_copy(_Origin_var._rotation_relative, _Origin_var._rotation_absolute);
    _Origin_var._rotation_is_identity =  rot_test_identity(_Origin_var._rotation_relative);
    _Origin_var._position_absolute = coords_set(
      0, 0, 0);
    tc1 = coords_neg(_Origin_var._position_absolute);
    _Origin_var._position_relative = rot_apply(_Origin_var._rotation_absolute, tc1);
  } /* Origin=Arm() AT ROTATED */
  DEBUG_COMPONENT("Origin", _Origin_var._position_absolute, _Origin_var._rotation_absolute);
  instrument->_position_absolute[1] = _Origin_var._position_absolute;
  instrument->_position_relative[1] = _Origin_var._position_relative;
    _Origin_var._position_relative_is_zero =  coords_test_zero(_Origin_var._position_relative);
  instrument->counter_N[1]  = instrument->counter_P[1] = instrument->counter_P2[1] = 0;
  instrument->counter_AbsorbProp[1]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0000_Origin", _Origin_var._position_absolute, _Origin_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Origin_setpos */

/* component SourceMantid=Commodus_I3() SETTING, POSITION/ROTATION */
int _SourceMantid_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_SourceMantid_setpos] component SourceMantid=Commodus_I3() SETTING [Commodus_I3:0]");
  stracpy(_SourceMantid_var._name, "SourceMantid", 16384);
  stracpy(_SourceMantid_var._type, "Commodus_I3", 16384);
  _SourceMantid_var._index=2;
  int current_setpos_index = 2;
  if("Let_TS2_HydroMod_Upgrade2021_8cmThick.mcstas" && strlen("Let_TS2_HydroMod_Upgrade2021_8cmThick.mcstas"))
    stracpy(_SourceMantid_var._parameters.Face, "Let_TS2_HydroMod_Upgrade2021_8cmThick.mcstas" ? "Let_TS2_HydroMod_Upgrade2021_8cmThick.mcstas" : "", 16384);
  else 
  _SourceMantid_var._parameters.Face[0]='\0';
  _SourceMantid_var._parameters.E0 = emin;
  _SourceMantid_var._parameters.E1 = emax;
  _SourceMantid_var._parameters.modPosition = 0;
  _SourceMantid_var._parameters.dist = 1.68;
  _SourceMantid_var._parameters.verbose = 0;
  _SourceMantid_var._parameters.beamcurrent = 1;
  _SourceMantid_var._parameters.modXsize = 0.12;
  _SourceMantid_var._parameters.modZsize = 0.12;
  _SourceMantid_var._parameters.xw = 0.04;
  _SourceMantid_var._parameters.yh = 0.09;


  /* component SourceMantid=Commodus_I3() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _SourceMantid_var._rotation_absolute);
    rot_copy(_SourceMantid_var._rotation_relative, _SourceMantid_var._rotation_absolute);
    _SourceMantid_var._rotation_is_identity =  rot_test_identity(_SourceMantid_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _SourceMantid_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_neg(_SourceMantid_var._position_absolute);
    _SourceMantid_var._position_relative = rot_apply(_SourceMantid_var._rotation_absolute, tc1);
  } /* SourceMantid=Commodus_I3() AT ROTATED */
  DEBUG_COMPONENT("SourceMantid", _SourceMantid_var._position_absolute, _SourceMantid_var._rotation_absolute);
  instrument->_position_absolute[2] = _SourceMantid_var._position_absolute;
  instrument->_position_relative[2] = _SourceMantid_var._position_relative;
    _SourceMantid_var._position_relative_is_zero =  coords_test_zero(_SourceMantid_var._position_relative);
  instrument->counter_N[2]  = instrument->counter_P[2] = instrument->counter_P2[2] = 0;
  instrument->counter_AbsorbProp[2]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0001_SourceMantid", _SourceMantid_var._position_absolute, _SourceMantid_var._rotation_absolute, "Commodus_I3");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "Face", "TS1_S04_Merlin.mcstas", "Let_TS2_HydroMod_Upgrade2021_8cmThick.mcstas", "char*");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "E0", "NONE", "emin","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "E1", "NONE", "emax","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "modPosition", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "dist", "1.7", "1.68","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "verbose", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "beamcurrent", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "modXsize", "0.12", "0.12","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "modZsize", "0.12", "0.12","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "xw", "0.094", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_SourceMantid", "yh", "0.094", "0.09","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _SourceMantid_setpos */

/* component shutter=Guide_channeled() SETTING, POSITION/ROTATION */
int _shutter_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_shutter_setpos] component shutter=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_shutter_var._name, "shutter", 16384);
  stracpy(_shutter_var._type, "Guide_channeled", 16384);
  _shutter_var._index=3;
  int current_setpos_index = 3;
  _shutter_var._parameters.w1 = 0.04;
  _shutter_var._parameters.h1 = 0.09;
  _shutter_var._parameters.w2 = 0;
  _shutter_var._parameters.h2 = 0;
  _shutter_var._parameters.l = 1.980;
  _shutter_var._parameters.R0 = 0.995;
  _shutter_var._parameters.Qc = 0;
  _shutter_var._parameters.alpha = 4.38;
  _shutter_var._parameters.m = 0;
  _shutter_var._parameters.nslit = 1;
  _shutter_var._parameters.d = 0.0005;
  _shutter_var._parameters.Qcx = 0.0218;
  _shutter_var._parameters.Qcy = 0.0218;
  _shutter_var._parameters.alphax = 4.38;
  _shutter_var._parameters.alphay = 4.38;
  _shutter_var._parameters.W = 3e-3;
  _shutter_var._parameters.mx = 2;
  _shutter_var._parameters.my = 3;
  _shutter_var._parameters.nu = 0;
  _shutter_var._parameters.phase = 0;


  /* component shutter=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _shutter_var._rotation_absolute);
    rot_transpose(_SourceMantid_var._rotation_absolute, tr1);
    rot_mul(_shutter_var._rotation_absolute, tr1, _shutter_var._rotation_relative);
    _shutter_var._rotation_is_identity =  rot_test_identity(_shutter_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 1.680);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _shutter_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_SourceMantid_var._position_absolute, _shutter_var._position_absolute);
    _shutter_var._position_relative = rot_apply(_shutter_var._rotation_absolute, tc1);
  } /* shutter=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("shutter", _shutter_var._position_absolute, _shutter_var._rotation_absolute);
  instrument->_position_absolute[3] = _shutter_var._position_absolute;
  instrument->_position_relative[3] = _shutter_var._position_relative;
    _shutter_var._position_relative_is_zero =  coords_test_zero(_shutter_var._position_relative);
  instrument->counter_N[3]  = instrument->counter_P[3] = instrument->counter_P2[3] = 0;
  instrument->counter_AbsorbProp[3]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0002_shutter", _shutter_var._position_absolute, _shutter_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0002_shutter", "w1", "NONE", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "h1", "NONE", "0.09","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "w2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "h2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "l", "NONE", "1.980","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "m", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "mx", "1", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "my", "1", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_shutter", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _shutter_setpos */

/* component insert=Guide_channeled() SETTING, POSITION/ROTATION */
int _insert_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_insert_setpos] component insert=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_insert_var._name, "insert", 16384);
  stracpy(_insert_var._type, "Guide_channeled", 16384);
  _insert_var._index=4;
  int current_setpos_index = 4;
  _insert_var._parameters.w1 = 0.04;
  _insert_var._parameters.h1 = 0.09;
  _insert_var._parameters.w2 = 0;
  _insert_var._parameters.h2 = 0;
  _insert_var._parameters.l = 2.500;
  _insert_var._parameters.R0 = 0.995;
  _insert_var._parameters.Qc = 0;
  _insert_var._parameters.alpha = 4.38;
  _insert_var._parameters.m = 0;
  _insert_var._parameters.nslit = 1;
  _insert_var._parameters.d = 0.0005;
  _insert_var._parameters.Qcx = 0.0218;
  _insert_var._parameters.Qcy = 0.0218;
  _insert_var._parameters.alphax = 4.38;
  _insert_var._parameters.alphay = 4.38;
  _insert_var._parameters.W = 3e-3;
  _insert_var._parameters.mx = 2;
  _insert_var._parameters.my = 3;
  _insert_var._parameters.nu = 0;
  _insert_var._parameters.phase = 0;


  /* component insert=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _insert_var._rotation_absolute);
    rot_transpose(_shutter_var._rotation_absolute, tr1);
    rot_mul(_insert_var._rotation_absolute, tr1, _insert_var._rotation_relative);
    _insert_var._rotation_is_identity =  rot_test_identity(_insert_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 3.740);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _insert_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_shutter_var._position_absolute, _insert_var._position_absolute);
    _insert_var._position_relative = rot_apply(_insert_var._rotation_absolute, tc1);
  } /* insert=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("insert", _insert_var._position_absolute, _insert_var._rotation_absolute);
  instrument->_position_absolute[4] = _insert_var._position_absolute;
  instrument->_position_relative[4] = _insert_var._position_relative;
    _insert_var._position_relative_is_zero =  coords_test_zero(_insert_var._position_relative);
  instrument->counter_N[4]  = instrument->counter_P[4] = instrument->counter_P2[4] = 0;
  instrument->counter_AbsorbProp[4]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0003_insert", _insert_var._position_absolute, _insert_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0003_insert", "w1", "NONE", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "h1", "NONE", "0.09","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "w2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "h2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "l", "NONE", "2.500","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "m", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "mx", "1", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "my", "1", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_insert", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _insert_setpos */

/* component after_insert=Guide_channeled() SETTING, POSITION/ROTATION */
int _after_insert_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_after_insert_setpos] component after_insert=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_after_insert_var._name, "after_insert", 16384);
  stracpy(_after_insert_var._type, "Guide_channeled", 16384);
  _after_insert_var._index=5;
  int current_setpos_index = 5;
  _after_insert_var._parameters.w1 = 0.04;
  _after_insert_var._parameters.h1 = 0.09;
  _after_insert_var._parameters.w2 = 0;
  _after_insert_var._parameters.h2 = 0;
  _after_insert_var._parameters.l = 1.514;
  _after_insert_var._parameters.R0 = 0.995;
  _after_insert_var._parameters.Qc = 0;
  _after_insert_var._parameters.alpha = 4.38;
  _after_insert_var._parameters.m = 0;
  _after_insert_var._parameters.nslit = 1;
  _after_insert_var._parameters.d = 0.0005;
  _after_insert_var._parameters.Qcx = 0.0218;
  _after_insert_var._parameters.Qcy = 0.0218;
  _after_insert_var._parameters.alphax = 4.38;
  _after_insert_var._parameters.alphay = 4.38;
  _after_insert_var._parameters.W = 3e-3;
  _after_insert_var._parameters.mx = 2;
  _after_insert_var._parameters.my = 3;
  _after_insert_var._parameters.nu = 0;
  _after_insert_var._parameters.phase = 0;


  /* component after_insert=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _after_insert_var._rotation_absolute);
    rot_transpose(_insert_var._rotation_absolute, tr1);
    rot_mul(_after_insert_var._rotation_absolute, tr1, _after_insert_var._rotation_relative);
    _after_insert_var._rotation_is_identity =  rot_test_identity(_after_insert_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 6.300);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _after_insert_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_insert_var._position_absolute, _after_insert_var._position_absolute);
    _after_insert_var._position_relative = rot_apply(_after_insert_var._rotation_absolute, tc1);
  } /* after_insert=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("after_insert", _after_insert_var._position_absolute, _after_insert_var._rotation_absolute);
  instrument->_position_absolute[5] = _after_insert_var._position_absolute;
  instrument->_position_relative[5] = _after_insert_var._position_relative;
    _after_insert_var._position_relative_is_zero =  coords_test_zero(_after_insert_var._position_relative);
  instrument->counter_N[5]  = instrument->counter_P[5] = instrument->counter_P2[5] = 0;
  instrument->counter_AbsorbProp[5]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0004_after_insert", _after_insert_var._position_absolute, _after_insert_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "w1", "NONE", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "h1", "NONE", "0.09","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "w2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "h2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "l", "NONE", "1.514","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "m", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "mx", "1", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "my", "1", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_after_insert", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _after_insert_setpos */

/* component Monitor1=TOF_monitor() SETTING, POSITION/ROTATION */
int _Monitor1_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Monitor1_setpos] component Monitor1=TOF_monitor() SETTING [TOF_monitor:0]");
  stracpy(_Monitor1_var._name, "Monitor1", 16384);
  stracpy(_Monitor1_var._type, "TOF_monitor", 16384);
  _Monitor1_var._index=6;
  int current_setpos_index = 6;
  _Monitor1_var._parameters.nt = 100;
  if("monitor1.dat" && strlen("monitor1.dat"))
    stracpy(_Monitor1_var._parameters.filename, "monitor1.dat" ? "monitor1.dat" : "", 16384);
  else 
  _Monitor1_var._parameters.filename[0]='\0';
  _Monitor1_var._parameters.xmin = -0.05;
  _Monitor1_var._parameters.xmax = 0.05;
  _Monitor1_var._parameters.ymin = -0.05;
  _Monitor1_var._parameters.ymax = 0.05;
  _Monitor1_var._parameters.xwidth = 0.06;
  _Monitor1_var._parameters.yheight = 0.1;
  _Monitor1_var._parameters.tmin = 1e6 * ( ( L_Ch1 - Ch1_5_halfgap - smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset );
  _Monitor1_var._parameters.tmax = 1e6 * ( ( L_Ch1 - Ch1_5_halfgap - smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset );
  _Monitor1_var._parameters.dt = 1.0;
  _Monitor1_var._parameters.restore_neutron = 1;
  _Monitor1_var._parameters.nowritefile = ! _instrument_var._parameters.monitors_on;


  /* component Monitor1=TOF_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _Monitor1_var._rotation_absolute);
    rot_transpose(_after_insert_var._rotation_absolute, tr1);
    rot_mul(_Monitor1_var._rotation_absolute, tr1, _Monitor1_var._rotation_relative);
    _Monitor1_var._rotation_is_identity =  rot_test_identity(_Monitor1_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch1 - Ch1_5_halfgap - smidge);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _Monitor1_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_after_insert_var._position_absolute, _Monitor1_var._position_absolute);
    _Monitor1_var._position_relative = rot_apply(_Monitor1_var._rotation_absolute, tc1);
  } /* Monitor1=TOF_monitor() AT ROTATED */
  DEBUG_COMPONENT("Monitor1", _Monitor1_var._position_absolute, _Monitor1_var._rotation_absolute);
  instrument->_position_absolute[6] = _Monitor1_var._position_absolute;
  instrument->_position_relative[6] = _Monitor1_var._position_relative;
    _Monitor1_var._position_relative_is_zero =  coords_test_zero(_Monitor1_var._position_relative);
  instrument->counter_N[6]  = instrument->counter_P[6] = instrument->counter_P2[6] = 0;
  instrument->counter_AbsorbProp[6]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0005_Monitor1", _Monitor1_var._position_absolute, _Monitor1_var._rotation_absolute, "TOF_monitor");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "nt", "20", "100","int");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "filename", 0, "monitor1.dat", "char*");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "yheight", "0", "0.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "tmin", "0", "1e6 * ( ( L_Ch1 - Ch1_5_halfgap - smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "tmax", "0", "1e6 * ( ( L_Ch1 - Ch1_5_halfgap - smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "dt", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0005_Monitor1", "nowritefile", "0", "! _instrument_var._parameters.monitors_on","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Monitor1_setpos */

/* component LET_Chopper1_disk1=DiskChopper() SETTING, POSITION/ROTATION */
int _LET_Chopper1_disk1_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_LET_Chopper1_disk1_setpos] component LET_Chopper1_disk1=DiskChopper() SETTING [DiskChopper:0]");
  stracpy(_LET_Chopper1_disk1_var._name, "LET_Chopper1_disk1", 16384);
  stracpy(_LET_Chopper1_disk1_var._type, "DiskChopper", 16384);
  _LET_Chopper1_disk1_var._index=7;
  int current_setpos_index = 7;
  _LET_Chopper1_disk1_var._parameters.theta_0 = 0;
  _LET_Chopper1_disk1_var._parameters.radius = 0.350;
  _LET_Chopper1_disk1_var._parameters.yheight = 0.095;
  _LET_Chopper1_disk1_var._parameters.nu = Ch1_speed;
  _LET_Chopper1_disk1_var._parameters.nslit = 6;
  _LET_Chopper1_disk1_var._parameters.jitter = jitter;
  _LET_Chopper1_disk1_var._parameters.delay = ( L_Ch1 - Ch1_5_halfgap ) / v_foc + _instrument_var._parameters.pha_offset;
  _LET_Chopper1_disk1_var._parameters.isfirst = 0;
  _LET_Chopper1_disk1_var._parameters.n_pulse = 1;
  _LET_Chopper1_disk1_var._parameters.abs_out = 1;
  _LET_Chopper1_disk1_var._parameters.phase = 0;
  _LET_Chopper1_disk1_var._parameters.xwidth = 0.056;
  _LET_Chopper1_disk1_var._parameters.verbose = 0;


  /* component LET_Chopper1_disk1=DiskChopper() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _LET_Chopper1_disk1_var._rotation_absolute);
    rot_transpose(_Monitor1_var._rotation_absolute, tr1);
    rot_mul(_LET_Chopper1_disk1_var._rotation_absolute, tr1, _LET_Chopper1_disk1_var._rotation_relative);
    _LET_Chopper1_disk1_var._rotation_is_identity =  rot_test_identity(_LET_Chopper1_disk1_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch1 - Ch1_5_halfgap);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _LET_Chopper1_disk1_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_Monitor1_var._position_absolute, _LET_Chopper1_disk1_var._position_absolute);
    _LET_Chopper1_disk1_var._position_relative = rot_apply(_LET_Chopper1_disk1_var._rotation_absolute, tc1);
  } /* LET_Chopper1_disk1=DiskChopper() AT ROTATED */
  DEBUG_COMPONENT("LET_Chopper1_disk1", _LET_Chopper1_disk1_var._position_absolute, _LET_Chopper1_disk1_var._rotation_absolute);
  instrument->_position_absolute[7] = _LET_Chopper1_disk1_var._position_absolute;
  instrument->_position_relative[7] = _LET_Chopper1_disk1_var._position_relative;
    _LET_Chopper1_disk1_var._position_relative_is_zero =  coords_test_zero(_LET_Chopper1_disk1_var._position_relative);
  instrument->counter_N[7]  = instrument->counter_P[7] = instrument->counter_P2[7] = 0;
  instrument->counter_AbsorbProp[7]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0006_LET_Chopper1_disk1", _LET_Chopper1_disk1_var._position_absolute, _LET_Chopper1_disk1_var._rotation_absolute, "DiskChopper");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "theta_0", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "radius", "0.5", "0.350","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "yheight", "NONE", "0.095","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "nu", "NONE", "Ch1_speed","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "nslit", "3", "6","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "jitter", "0", "jitter","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "delay", "0", "( L_Ch1 - Ch1_5_halfgap ) / v_foc + _instrument_var._parameters.pha_offset","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "isfirst", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "n_pulse", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "abs_out", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "phase", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "xwidth", "0", "0.056","MCNUM");
        mccomp_param_nexus(nxhandle,"0006_LET_Chopper1_disk1", "verbose", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _LET_Chopper1_disk1_setpos */

/* component LET_Chopper1_disk2=DiskChopper() SETTING, POSITION/ROTATION */
int _LET_Chopper1_disk2_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_LET_Chopper1_disk2_setpos] component LET_Chopper1_disk2=DiskChopper() SETTING [DiskChopper:0]");
  stracpy(_LET_Chopper1_disk2_var._name, "LET_Chopper1_disk2", 16384);
  stracpy(_LET_Chopper1_disk2_var._type, "DiskChopper", 16384);
  _LET_Chopper1_disk2_var._index=8;
  int current_setpos_index = 8;
  _LET_Chopper1_disk2_var._parameters.theta_0 = 0;
  _LET_Chopper1_disk2_var._parameters.radius = 0.350;
  _LET_Chopper1_disk2_var._parameters.yheight = 0.095;
  _LET_Chopper1_disk2_var._parameters.nu = Ch1_speed;
  _LET_Chopper1_disk2_var._parameters.nslit = 6;
  _LET_Chopper1_disk2_var._parameters.jitter = jitter;
  _LET_Chopper1_disk2_var._parameters.delay = ( L_Ch1 + Ch1_5_halfgap ) / v_foc + _instrument_var._parameters.pha_offset;
  _LET_Chopper1_disk2_var._parameters.isfirst = 0;
  _LET_Chopper1_disk2_var._parameters.n_pulse = 1;
  _LET_Chopper1_disk2_var._parameters.abs_out = 1;
  _LET_Chopper1_disk2_var._parameters.phase = 0;
  _LET_Chopper1_disk2_var._parameters.xwidth = 0.056;
  _LET_Chopper1_disk2_var._parameters.verbose = 0;


  /* component LET_Chopper1_disk2=DiskChopper() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (0)*DEG2RAD, (180)*DEG2RAD);
    rot_mul(tr1, _LET_Chopper1_disk1_var._rotation_absolute, _LET_Chopper1_disk2_var._rotation_absolute);
    rot_transpose(_LET_Chopper1_disk1_var._rotation_absolute, tr1);
    rot_mul(_LET_Chopper1_disk2_var._rotation_absolute, tr1, _LET_Chopper1_disk2_var._rotation_relative);
    _LET_Chopper1_disk2_var._rotation_is_identity =  rot_test_identity(_LET_Chopper1_disk2_var._rotation_relative);
    tc1 = coords_set(
      0, 0, ( L_Ch1 + Ch1_5_halfgap ));
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _LET_Chopper1_disk2_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_LET_Chopper1_disk1_var._position_absolute, _LET_Chopper1_disk2_var._position_absolute);
    _LET_Chopper1_disk2_var._position_relative = rot_apply(_LET_Chopper1_disk2_var._rotation_absolute, tc1);
  } /* LET_Chopper1_disk2=DiskChopper() AT ROTATED */
  DEBUG_COMPONENT("LET_Chopper1_disk2", _LET_Chopper1_disk2_var._position_absolute, _LET_Chopper1_disk2_var._rotation_absolute);
  instrument->_position_absolute[8] = _LET_Chopper1_disk2_var._position_absolute;
  instrument->_position_relative[8] = _LET_Chopper1_disk2_var._position_relative;
    _LET_Chopper1_disk2_var._position_relative_is_zero =  coords_test_zero(_LET_Chopper1_disk2_var._position_relative);
  instrument->counter_N[8]  = instrument->counter_P[8] = instrument->counter_P2[8] = 0;
  instrument->counter_AbsorbProp[8]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0007_LET_Chopper1_disk2", _LET_Chopper1_disk2_var._position_absolute, _LET_Chopper1_disk2_var._rotation_absolute, "DiskChopper");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "theta_0", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "radius", "0.5", "0.350","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "yheight", "NONE", "0.095","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "nu", "NONE", "Ch1_speed","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "nslit", "3", "6","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "jitter", "0", "jitter","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "delay", "0", "( L_Ch1 + Ch1_5_halfgap ) / v_foc + _instrument_var._parameters.pha_offset","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "isfirst", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "n_pulse", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "abs_out", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "phase", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "xwidth", "0", "0.056","MCNUM");
        mccomp_param_nexus(nxhandle,"0007_LET_Chopper1_disk2", "verbose", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _LET_Chopper1_disk2_setpos */

/* component Monitor2=TOF_monitor() SETTING, POSITION/ROTATION */
int _Monitor2_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Monitor2_setpos] component Monitor2=TOF_monitor() SETTING [TOF_monitor:0]");
  stracpy(_Monitor2_var._name, "Monitor2", 16384);
  stracpy(_Monitor2_var._type, "TOF_monitor", 16384);
  _Monitor2_var._index=9;
  int current_setpos_index = 9;
  _Monitor2_var._parameters.nt = 100;
  if("monitor2.dat" && strlen("monitor2.dat"))
    stracpy(_Monitor2_var._parameters.filename, "monitor2.dat" ? "monitor2.dat" : "", 16384);
  else 
  _Monitor2_var._parameters.filename[0]='\0';
  _Monitor2_var._parameters.xmin = -0.05;
  _Monitor2_var._parameters.xmax = 0.05;
  _Monitor2_var._parameters.ymin = -0.05;
  _Monitor2_var._parameters.ymax = 0.05;
  _Monitor2_var._parameters.xwidth = 0.06;
  _Monitor2_var._parameters.yheight = 0.1;
  _Monitor2_var._parameters.tmin = 1e6 * ( ( L_Ch1 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset );
  _Monitor2_var._parameters.tmax = 1e6 * ( ( L_Ch1 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset );
  _Monitor2_var._parameters.dt = 1.0;
  _Monitor2_var._parameters.restore_neutron = 1;
  _Monitor2_var._parameters.nowritefile = ! _instrument_var._parameters.monitors_on;


  /* component Monitor2=TOF_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _Monitor2_var._rotation_absolute);
    rot_transpose(_LET_Chopper1_disk2_var._rotation_absolute, tr1);
    rot_mul(_Monitor2_var._rotation_absolute, tr1, _Monitor2_var._rotation_relative);
    _Monitor2_var._rotation_is_identity =  rot_test_identity(_Monitor2_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch1 + Ch1_5_halfgap + smidge);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _Monitor2_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_LET_Chopper1_disk2_var._position_absolute, _Monitor2_var._position_absolute);
    _Monitor2_var._position_relative = rot_apply(_Monitor2_var._rotation_absolute, tc1);
  } /* Monitor2=TOF_monitor() AT ROTATED */
  DEBUG_COMPONENT("Monitor2", _Monitor2_var._position_absolute, _Monitor2_var._rotation_absolute);
  instrument->_position_absolute[9] = _Monitor2_var._position_absolute;
  instrument->_position_relative[9] = _Monitor2_var._position_relative;
    _Monitor2_var._position_relative_is_zero =  coords_test_zero(_Monitor2_var._position_relative);
  instrument->counter_N[9]  = instrument->counter_P[9] = instrument->counter_P2[9] = 0;
  instrument->counter_AbsorbProp[9]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0008_Monitor2", _Monitor2_var._position_absolute, _Monitor2_var._rotation_absolute, "TOF_monitor");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "nt", "20", "100","int");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "filename", 0, "monitor2.dat", "char*");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "yheight", "0", "0.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "tmin", "0", "1e6 * ( ( L_Ch1 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "tmax", "0", "1e6 * ( ( L_Ch1 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "dt", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0008_Monitor2", "nowritefile", "0", "! _instrument_var._parameters.monitors_on","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Monitor2_setpos */

/* component between_chop1_and_chop2=Guide_channeled() SETTING, POSITION/ROTATION */
int _between_chop1_and_chop2_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_between_chop1_and_chop2_setpos] component between_chop1_and_chop2=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_between_chop1_and_chop2_var._name, "between_chop1_and_chop2", 16384);
  stracpy(_between_chop1_and_chop2_var._type, "Guide_channeled", 16384);
  _between_chop1_and_chop2_var._index=10;
  int current_setpos_index = 10;
  _between_chop1_and_chop2_var._parameters.w1 = 0.04;
  _between_chop1_and_chop2_var._parameters.h1 = 0.09;
  _between_chop1_and_chop2_var._parameters.w2 = 0;
  _between_chop1_and_chop2_var._parameters.h2 = 0;
  _between_chop1_and_chop2_var._parameters.l = 0.312;
  _between_chop1_and_chop2_var._parameters.R0 = 0.995;
  _between_chop1_and_chop2_var._parameters.Qc = 0;
  _between_chop1_and_chop2_var._parameters.alpha = 4.38;
  _between_chop1_and_chop2_var._parameters.m = 0;
  _between_chop1_and_chop2_var._parameters.nslit = 1;
  _between_chop1_and_chop2_var._parameters.d = 0.0005;
  _between_chop1_and_chop2_var._parameters.Qcx = 0.0218;
  _between_chop1_and_chop2_var._parameters.Qcy = 0.0218;
  _between_chop1_and_chop2_var._parameters.alphax = 4.38;
  _between_chop1_and_chop2_var._parameters.alphay = 4.38;
  _between_chop1_and_chop2_var._parameters.W = 3e-3;
  _between_chop1_and_chop2_var._parameters.mx = 2;
  _between_chop1_and_chop2_var._parameters.my = 3;
  _between_chop1_and_chop2_var._parameters.nu = 0;
  _between_chop1_and_chop2_var._parameters.phase = 0;


  /* component between_chop1_and_chop2=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _between_chop1_and_chop2_var._rotation_absolute);
    rot_transpose(_Monitor2_var._rotation_absolute, tr1);
    rot_mul(_between_chop1_and_chop2_var._rotation_absolute, tr1, _between_chop1_and_chop2_var._rotation_relative);
    _between_chop1_and_chop2_var._rotation_is_identity =  rot_test_identity(_between_chop1_and_chop2_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 7.852);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _between_chop1_and_chop2_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_Monitor2_var._position_absolute, _between_chop1_and_chop2_var._position_absolute);
    _between_chop1_and_chop2_var._position_relative = rot_apply(_between_chop1_and_chop2_var._rotation_absolute, tc1);
  } /* between_chop1_and_chop2=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("between_chop1_and_chop2", _between_chop1_and_chop2_var._position_absolute, _between_chop1_and_chop2_var._rotation_absolute);
  instrument->_position_absolute[10] = _between_chop1_and_chop2_var._position_absolute;
  instrument->_position_relative[10] = _between_chop1_and_chop2_var._position_relative;
    _between_chop1_and_chop2_var._position_relative_is_zero =  coords_test_zero(_between_chop1_and_chop2_var._position_relative);
  instrument->counter_N[10]  = instrument->counter_P[10] = instrument->counter_P2[10] = 0;
  instrument->counter_AbsorbProp[10]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0009_between_chop1_and_chop2", _between_chop1_and_chop2_var._position_absolute, _between_chop1_and_chop2_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "w1", "NONE", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "h1", "NONE", "0.09","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "w2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "h2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "l", "NONE", "0.312","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "m", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "mx", "1", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "my", "1", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0009_between_chop1_and_chop2", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _between_chop1_and_chop2_setpos */

/* component LET_Chopper2=DiskChopper() SETTING, POSITION/ROTATION */
int _LET_Chopper2_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_LET_Chopper2_setpos] component LET_Chopper2=DiskChopper() SETTING [DiskChopper:0]");
  stracpy(_LET_Chopper2_var._name, "LET_Chopper2", 16384);
  stracpy(_LET_Chopper2_var._type, "DiskChopper", 16384);
  _LET_Chopper2_var._index=11;
  int current_setpos_index = 11;
  _LET_Chopper2_var._parameters.theta_0 = 0;
  _LET_Chopper2_var._parameters.radius = 0.600;
  _LET_Chopper2_var._parameters.yheight = 0.107;
  _LET_Chopper2_var._parameters.nu = Ch2_speed;
  _LET_Chopper2_var._parameters.nslit = 1;
  _LET_Chopper2_var._parameters.jitter = jitter;
  _LET_Chopper2_var._parameters.delay = ( _instrument_var._parameters.Ch2_phase + Ch2_offset ) / 1e6;
  _LET_Chopper2_var._parameters.isfirst = 0;
  _LET_Chopper2_var._parameters.n_pulse = 1;
  _LET_Chopper2_var._parameters.abs_out = 1;
  _LET_Chopper2_var._parameters.phase = 0;
  _LET_Chopper2_var._parameters.xwidth = 0.79;
  _LET_Chopper2_var._parameters.verbose = 0;


  /* component LET_Chopper2=DiskChopper() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _LET_Chopper2_var._rotation_absolute);
    rot_transpose(_between_chop1_and_chop2_var._rotation_absolute, tr1);
    rot_mul(_LET_Chopper2_var._rotation_absolute, tr1, _LET_Chopper2_var._rotation_relative);
    _LET_Chopper2_var._rotation_is_identity =  rot_test_identity(_LET_Chopper2_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch2);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _LET_Chopper2_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_between_chop1_and_chop2_var._position_absolute, _LET_Chopper2_var._position_absolute);
    _LET_Chopper2_var._position_relative = rot_apply(_LET_Chopper2_var._rotation_absolute, tc1);
  } /* LET_Chopper2=DiskChopper() AT ROTATED */
  DEBUG_COMPONENT("LET_Chopper2", _LET_Chopper2_var._position_absolute, _LET_Chopper2_var._rotation_absolute);
  instrument->_position_absolute[11] = _LET_Chopper2_var._position_absolute;
  instrument->_position_relative[11] = _LET_Chopper2_var._position_relative;
    _LET_Chopper2_var._position_relative_is_zero =  coords_test_zero(_LET_Chopper2_var._position_relative);
  instrument->counter_N[11]  = instrument->counter_P[11] = instrument->counter_P2[11] = 0;
  instrument->counter_AbsorbProp[11]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0010_LET_Chopper2", _LET_Chopper2_var._position_absolute, _LET_Chopper2_var._rotation_absolute, "DiskChopper");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "theta_0", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "radius", "0.5", "0.600","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "yheight", "NONE", "0.107","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "nu", "NONE", "Ch2_speed","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "nslit", "3", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "jitter", "0", "jitter","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "delay", "0", "( _instrument_var._parameters.Ch2_phase + Ch2_offset ) / 1e6","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "isfirst", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "n_pulse", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "abs_out", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "phase", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "xwidth", "0", "0.79","MCNUM");
        mccomp_param_nexus(nxhandle,"0010_LET_Chopper2", "verbose", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _LET_Chopper2_setpos */

/* component Monitor3=TOF_monitor() SETTING, POSITION/ROTATION */
int _Monitor3_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Monitor3_setpos] component Monitor3=TOF_monitor() SETTING [TOF_monitor:0]");
  stracpy(_Monitor3_var._name, "Monitor3", 16384);
  stracpy(_Monitor3_var._type, "TOF_monitor", 16384);
  _Monitor3_var._index=12;
  int current_setpos_index = 12;
  _Monitor3_var._parameters.nt = 100;
  if("monitor3.dat" && strlen("monitor3.dat"))
    stracpy(_Monitor3_var._parameters.filename, "monitor3.dat" ? "monitor3.dat" : "", 16384);
  else 
  _Monitor3_var._parameters.filename[0]='\0';
  _Monitor3_var._parameters.xmin = -0.05;
  _Monitor3_var._parameters.xmax = 0.05;
  _Monitor3_var._parameters.ymin = -0.05;
  _Monitor3_var._parameters.ymax = 0.05;
  _Monitor3_var._parameters.xwidth = 0.06;
  _Monitor3_var._parameters.yheight = 0.1;
  _Monitor3_var._parameters.tmin = 1e6 * ( ( L_Ch2 + smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset );
  _Monitor3_var._parameters.tmax = 1e6 * ( ( L_Ch2 + smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset );
  _Monitor3_var._parameters.dt = 1.0;
  _Monitor3_var._parameters.restore_neutron = 1;
  _Monitor3_var._parameters.nowritefile = ! _instrument_var._parameters.monitors_on;


  /* component Monitor3=TOF_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _Monitor3_var._rotation_absolute);
    rot_transpose(_LET_Chopper2_var._rotation_absolute, tr1);
    rot_mul(_Monitor3_var._rotation_absolute, tr1, _Monitor3_var._rotation_relative);
    _Monitor3_var._rotation_is_identity =  rot_test_identity(_Monitor3_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch2 + smidge);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _Monitor3_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_LET_Chopper2_var._position_absolute, _Monitor3_var._position_absolute);
    _Monitor3_var._position_relative = rot_apply(_Monitor3_var._rotation_absolute, tc1);
  } /* Monitor3=TOF_monitor() AT ROTATED */
  DEBUG_COMPONENT("Monitor3", _Monitor3_var._position_absolute, _Monitor3_var._rotation_absolute);
  instrument->_position_absolute[12] = _Monitor3_var._position_absolute;
  instrument->_position_relative[12] = _Monitor3_var._position_relative;
    _Monitor3_var._position_relative_is_zero =  coords_test_zero(_Monitor3_var._position_relative);
  instrument->counter_N[12]  = instrument->counter_P[12] = instrument->counter_P2[12] = 0;
  instrument->counter_AbsorbProp[12]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0011_Monitor3", _Monitor3_var._position_absolute, _Monitor3_var._rotation_absolute, "TOF_monitor");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "nt", "20", "100","int");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "filename", 0, "monitor3.dat", "char*");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "yheight", "0", "0.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "tmin", "0", "1e6 * ( ( L_Ch2 + smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "tmax", "0", "1e6 * ( ( L_Ch2 + smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "dt", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0011_Monitor3", "nowritefile", "0", "! _instrument_var._parameters.monitors_on","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Monitor3_setpos */

/* component between_chop2_and_chop3=Guide_channeled() SETTING, POSITION/ROTATION */
int _between_chop2_and_chop3_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_between_chop2_and_chop3_setpos] component between_chop2_and_chop3=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_between_chop2_and_chop3_var._name, "between_chop2_and_chop3", 16384);
  stracpy(_between_chop2_and_chop3_var._type, "Guide_channeled", 16384);
  _between_chop2_and_chop3_var._index=13;
  int current_setpos_index = 13;
  _between_chop2_and_chop3_var._parameters.w1 = 0.04;
  _between_chop2_and_chop3_var._parameters.h1 = 0.09;
  _between_chop2_and_chop3_var._parameters.w2 = 0;
  _between_chop2_and_chop3_var._parameters.h2 = 0;
  _between_chop2_and_chop3_var._parameters.l = 3.499;
  _between_chop2_and_chop3_var._parameters.R0 = 0.995;
  _between_chop2_and_chop3_var._parameters.Qc = 0;
  _between_chop2_and_chop3_var._parameters.alpha = 4.38;
  _between_chop2_and_chop3_var._parameters.m = 0;
  _between_chop2_and_chop3_var._parameters.nslit = 1;
  _between_chop2_and_chop3_var._parameters.d = 0.0005;
  _between_chop2_and_chop3_var._parameters.Qcx = 0.0218;
  _between_chop2_and_chop3_var._parameters.Qcy = 0.0218;
  _between_chop2_and_chop3_var._parameters.alphax = 4.38;
  _between_chop2_and_chop3_var._parameters.alphay = 4.38;
  _between_chop2_and_chop3_var._parameters.W = 3e-3;
  _between_chop2_and_chop3_var._parameters.mx = 2;
  _between_chop2_and_chop3_var._parameters.my = 3;
  _between_chop2_and_chop3_var._parameters.nu = 0;
  _between_chop2_and_chop3_var._parameters.phase = 0;


  /* component between_chop2_and_chop3=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _between_chop2_and_chop3_var._rotation_absolute);
    rot_transpose(_Monitor3_var._rotation_absolute, tr1);
    rot_mul(_between_chop2_and_chop3_var._rotation_absolute, tr1, _between_chop2_and_chop3_var._rotation_relative);
    _between_chop2_and_chop3_var._rotation_is_identity =  rot_test_identity(_between_chop2_and_chop3_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 8.236);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _between_chop2_and_chop3_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_Monitor3_var._position_absolute, _between_chop2_and_chop3_var._position_absolute);
    _between_chop2_and_chop3_var._position_relative = rot_apply(_between_chop2_and_chop3_var._rotation_absolute, tc1);
  } /* between_chop2_and_chop3=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("between_chop2_and_chop3", _between_chop2_and_chop3_var._position_absolute, _between_chop2_and_chop3_var._rotation_absolute);
  instrument->_position_absolute[13] = _between_chop2_and_chop3_var._position_absolute;
  instrument->_position_relative[13] = _between_chop2_and_chop3_var._position_relative;
    _between_chop2_and_chop3_var._position_relative_is_zero =  coords_test_zero(_between_chop2_and_chop3_var._position_relative);
  instrument->counter_N[13]  = instrument->counter_P[13] = instrument->counter_P2[13] = 0;
  instrument->counter_AbsorbProp[13]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0012_between_chop2_and_chop3", _between_chop2_and_chop3_var._position_absolute, _between_chop2_and_chop3_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "w1", "NONE", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "h1", "NONE", "0.09","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "w2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "h2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "l", "NONE", "3.499","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "m", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "mx", "1", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "my", "1", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0012_between_chop2_and_chop3", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _between_chop2_and_chop3_setpos */

/* component LET_Chopper3=DiskChopper() SETTING, POSITION/ROTATION */
int _LET_Chopper3_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_LET_Chopper3_setpos] component LET_Chopper3=DiskChopper() SETTING [DiskChopper:0]");
  stracpy(_LET_Chopper3_var._name, "LET_Chopper3", 16384);
  stracpy(_LET_Chopper3_var._type, "DiskChopper", 16384);
  _LET_Chopper3_var._index=14;
  int current_setpos_index = 14;
  _LET_Chopper3_var._parameters.theta_0 = 0;
  _LET_Chopper3_var._parameters.radius = 0.340;
  _LET_Chopper3_var._parameters.yheight = 0.090;
  _LET_Chopper3_var._parameters.nu = _instrument_var._parameters.Ch3_speed;
  _LET_Chopper3_var._parameters.nslit = 2;
  _LET_Chopper3_var._parameters.jitter = jitter;
  _LET_Chopper3_var._parameters.delay = L_Ch3 / v_foc + _instrument_var._parameters.pha_offset;
  _LET_Chopper3_var._parameters.isfirst = 0;
  _LET_Chopper3_var._parameters.n_pulse = 1;
  _LET_Chopper3_var._parameters.abs_out = 1;
  _LET_Chopper3_var._parameters.phase = 0;
  _LET_Chopper3_var._parameters.xwidth = 0.045;
  _LET_Chopper3_var._parameters.verbose = 0;


  /* component LET_Chopper3=DiskChopper() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _LET_Chopper3_var._rotation_absolute);
    rot_transpose(_between_chop2_and_chop3_var._rotation_absolute, tr1);
    rot_mul(_LET_Chopper3_var._rotation_absolute, tr1, _LET_Chopper3_var._rotation_relative);
    _LET_Chopper3_var._rotation_is_identity =  rot_test_identity(_LET_Chopper3_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch3);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _LET_Chopper3_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_between_chop2_and_chop3_var._position_absolute, _LET_Chopper3_var._position_absolute);
    _LET_Chopper3_var._position_relative = rot_apply(_LET_Chopper3_var._rotation_absolute, tc1);
  } /* LET_Chopper3=DiskChopper() AT ROTATED */
  DEBUG_COMPONENT("LET_Chopper3", _LET_Chopper3_var._position_absolute, _LET_Chopper3_var._rotation_absolute);
  instrument->_position_absolute[14] = _LET_Chopper3_var._position_absolute;
  instrument->_position_relative[14] = _LET_Chopper3_var._position_relative;
    _LET_Chopper3_var._position_relative_is_zero =  coords_test_zero(_LET_Chopper3_var._position_relative);
  instrument->counter_N[14]  = instrument->counter_P[14] = instrument->counter_P2[14] = 0;
  instrument->counter_AbsorbProp[14]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0013_LET_Chopper3", _LET_Chopper3_var._position_absolute, _LET_Chopper3_var._rotation_absolute, "DiskChopper");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "theta_0", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "radius", "0.5", "0.340","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "yheight", "NONE", "0.090","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "nu", "NONE", "_instrument_var._parameters.Ch3_speed","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "nslit", "3", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "jitter", "0", "jitter","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "delay", "0", "L_Ch3 / v_foc + _instrument_var._parameters.pha_offset","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "isfirst", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "n_pulse", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "abs_out", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "phase", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "xwidth", "0", "0.045","MCNUM");
        mccomp_param_nexus(nxhandle,"0013_LET_Chopper3", "verbose", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _LET_Chopper3_setpos */

/* component Monitor4=TOF_monitor() SETTING, POSITION/ROTATION */
int _Monitor4_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Monitor4_setpos] component Monitor4=TOF_monitor() SETTING [TOF_monitor:0]");
  stracpy(_Monitor4_var._name, "Monitor4", 16384);
  stracpy(_Monitor4_var._type, "TOF_monitor", 16384);
  _Monitor4_var._index=15;
  int current_setpos_index = 15;
  _Monitor4_var._parameters.nt = 100;
  if("monitor4.dat" && strlen("monitor4.dat"))
    stracpy(_Monitor4_var._parameters.filename, "monitor4.dat" ? "monitor4.dat" : "", 16384);
  else 
  _Monitor4_var._parameters.filename[0]='\0';
  _Monitor4_var._parameters.xmin = -0.05;
  _Monitor4_var._parameters.xmax = 0.05;
  _Monitor4_var._parameters.ymin = -0.05;
  _Monitor4_var._parameters.ymax = 0.05;
  _Monitor4_var._parameters.xwidth = 0.06;
  _Monitor4_var._parameters.yheight = 0.1;
  _Monitor4_var._parameters.tmin = 1e6 * ( ( L_Ch3 + smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset );
  _Monitor4_var._parameters.tmax = 1e6 * ( ( L_Ch3 + smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset );
  _Monitor4_var._parameters.dt = 1.0;
  _Monitor4_var._parameters.restore_neutron = 1;
  _Monitor4_var._parameters.nowritefile = ! _instrument_var._parameters.monitors_on;


  /* component Monitor4=TOF_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _Monitor4_var._rotation_absolute);
    rot_transpose(_LET_Chopper3_var._rotation_absolute, tr1);
    rot_mul(_Monitor4_var._rotation_absolute, tr1, _Monitor4_var._rotation_relative);
    _Monitor4_var._rotation_is_identity =  rot_test_identity(_Monitor4_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch3 + smidge);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _Monitor4_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_LET_Chopper3_var._position_absolute, _Monitor4_var._position_absolute);
    _Monitor4_var._position_relative = rot_apply(_Monitor4_var._rotation_absolute, tc1);
  } /* Monitor4=TOF_monitor() AT ROTATED */
  DEBUG_COMPONENT("Monitor4", _Monitor4_var._position_absolute, _Monitor4_var._rotation_absolute);
  instrument->_position_absolute[15] = _Monitor4_var._position_absolute;
  instrument->_position_relative[15] = _Monitor4_var._position_relative;
    _Monitor4_var._position_relative_is_zero =  coords_test_zero(_Monitor4_var._position_relative);
  instrument->counter_N[15]  = instrument->counter_P[15] = instrument->counter_P2[15] = 0;
  instrument->counter_AbsorbProp[15]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0014_Monitor4", _Monitor4_var._position_absolute, _Monitor4_var._rotation_absolute, "TOF_monitor");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "nt", "20", "100","int");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "filename", 0, "monitor4.dat", "char*");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "yheight", "0", "0.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "tmin", "0", "1e6 * ( ( L_Ch3 + smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "tmax", "0", "1e6 * ( ( L_Ch3 + smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "dt", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0014_Monitor4", "nowritefile", "0", "! _instrument_var._parameters.monitors_on","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Monitor4_setpos */

/* component between_chop3_and_chop4=Guide_channeled() SETTING, POSITION/ROTATION */
int _between_chop3_and_chop4_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_between_chop3_and_chop4_setpos] component between_chop3_and_chop4=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_between_chop3_and_chop4_var._name, "between_chop3_and_chop4", 16384);
  stracpy(_between_chop3_and_chop4_var._type, "Guide_channeled", 16384);
  _between_chop3_and_chop4_var._index=16;
  int current_setpos_index = 16;
  _between_chop3_and_chop4_var._parameters.w1 = 0.04;
  _between_chop3_and_chop4_var._parameters.h1 = 0.09;
  _between_chop3_and_chop4_var._parameters.w2 = 0;
  _between_chop3_and_chop4_var._parameters.h2 = 0;
  _between_chop3_and_chop4_var._parameters.l = 3.886;
  _between_chop3_and_chop4_var._parameters.R0 = 0.995;
  _between_chop3_and_chop4_var._parameters.Qc = 0;
  _between_chop3_and_chop4_var._parameters.alpha = 4.38;
  _between_chop3_and_chop4_var._parameters.m = 0;
  _between_chop3_and_chop4_var._parameters.nslit = 1;
  _between_chop3_and_chop4_var._parameters.d = 0.0005;
  _between_chop3_and_chop4_var._parameters.Qcx = 0.0218;
  _between_chop3_and_chop4_var._parameters.Qcy = 0.0218;
  _between_chop3_and_chop4_var._parameters.alphax = 4.38;
  _between_chop3_and_chop4_var._parameters.alphay = 4.38;
  _between_chop3_and_chop4_var._parameters.W = 3e-3;
  _between_chop3_and_chop4_var._parameters.mx = 2;
  _between_chop3_and_chop4_var._parameters.my = 3;
  _between_chop3_and_chop4_var._parameters.nu = 0;
  _between_chop3_and_chop4_var._parameters.phase = 0;


  /* component between_chop3_and_chop4=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _between_chop3_and_chop4_var._rotation_absolute);
    rot_transpose(_Monitor4_var._rotation_absolute, tr1);
    rot_mul(_between_chop3_and_chop4_var._rotation_absolute, tr1, _between_chop3_and_chop4_var._rotation_relative);
    _between_chop3_and_chop4_var._rotation_is_identity =  rot_test_identity(_between_chop3_and_chop4_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 11.765);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _between_chop3_and_chop4_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_Monitor4_var._position_absolute, _between_chop3_and_chop4_var._position_absolute);
    _between_chop3_and_chop4_var._position_relative = rot_apply(_between_chop3_and_chop4_var._rotation_absolute, tc1);
  } /* between_chop3_and_chop4=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("between_chop3_and_chop4", _between_chop3_and_chop4_var._position_absolute, _between_chop3_and_chop4_var._rotation_absolute);
  instrument->_position_absolute[16] = _between_chop3_and_chop4_var._position_absolute;
  instrument->_position_relative[16] = _between_chop3_and_chop4_var._position_relative;
    _between_chop3_and_chop4_var._position_relative_is_zero =  coords_test_zero(_between_chop3_and_chop4_var._position_relative);
  instrument->counter_N[16]  = instrument->counter_P[16] = instrument->counter_P2[16] = 0;
  instrument->counter_AbsorbProp[16]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0015_between_chop3_and_chop4", _between_chop3_and_chop4_var._position_absolute, _between_chop3_and_chop4_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "w1", "NONE", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "h1", "NONE", "0.09","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "w2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "h2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "l", "NONE", "3.886","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "m", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "mx", "1", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "my", "1", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0015_between_chop3_and_chop4", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _between_chop3_and_chop4_setpos */

/* component LET_Chopper4=DiskChopper() SETTING, POSITION/ROTATION */
int _LET_Chopper4_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_LET_Chopper4_setpos] component LET_Chopper4=DiskChopper() SETTING [DiskChopper:0]");
  stracpy(_LET_Chopper4_var._name, "LET_Chopper4", 16384);
  stracpy(_LET_Chopper4_var._type, "DiskChopper", 16384);
  _LET_Chopper4_var._index=17;
  int current_setpos_index = 17;
  _LET_Chopper4_var._parameters.theta_0 = 0;
  _LET_Chopper4_var._parameters.radius = 0.338;
  _LET_Chopper4_var._parameters.yheight = 0.090;
  _LET_Chopper4_var._parameters.nu = _instrument_var._parameters.Ch5_speed / 2;
  _LET_Chopper4_var._parameters.nslit = 6;
  _LET_Chopper4_var._parameters.jitter = jitter;
  _LET_Chopper4_var._parameters.delay = L_Ch4 / v_foc + _instrument_var._parameters.pha_offset;
  _LET_Chopper4_var._parameters.isfirst = 0;
  _LET_Chopper4_var._parameters.n_pulse = 1;
  _LET_Chopper4_var._parameters.abs_out = 1;
  _LET_Chopper4_var._parameters.phase = 0;
  _LET_Chopper4_var._parameters.xwidth = 0.045;
  _LET_Chopper4_var._parameters.verbose = 0;


  /* component LET_Chopper4=DiskChopper() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _LET_Chopper4_var._rotation_absolute);
    rot_transpose(_between_chop3_and_chop4_var._rotation_absolute, tr1);
    rot_mul(_LET_Chopper4_var._rotation_absolute, tr1, _LET_Chopper4_var._rotation_relative);
    _LET_Chopper4_var._rotation_is_identity =  rot_test_identity(_LET_Chopper4_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch4);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _LET_Chopper4_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_between_chop3_and_chop4_var._position_absolute, _LET_Chopper4_var._position_absolute);
    _LET_Chopper4_var._position_relative = rot_apply(_LET_Chopper4_var._rotation_absolute, tc1);
  } /* LET_Chopper4=DiskChopper() AT ROTATED */
  DEBUG_COMPONENT("LET_Chopper4", _LET_Chopper4_var._position_absolute, _LET_Chopper4_var._rotation_absolute);
  instrument->_position_absolute[17] = _LET_Chopper4_var._position_absolute;
  instrument->_position_relative[17] = _LET_Chopper4_var._position_relative;
    _LET_Chopper4_var._position_relative_is_zero =  coords_test_zero(_LET_Chopper4_var._position_relative);
  instrument->counter_N[17]  = instrument->counter_P[17] = instrument->counter_P2[17] = 0;
  instrument->counter_AbsorbProp[17]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0016_LET_Chopper4", _LET_Chopper4_var._position_absolute, _LET_Chopper4_var._rotation_absolute, "DiskChopper");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "theta_0", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "radius", "0.5", "0.338","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "yheight", "NONE", "0.090","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "nu", "NONE", "_instrument_var._parameters.Ch5_speed / 2","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "nslit", "3", "6","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "jitter", "0", "jitter","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "delay", "0", "L_Ch4 / v_foc + _instrument_var._parameters.pha_offset","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "isfirst", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "n_pulse", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "abs_out", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "phase", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "xwidth", "0", "0.045","MCNUM");
        mccomp_param_nexus(nxhandle,"0016_LET_Chopper4", "verbose", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _LET_Chopper4_setpos */

/* component Monitor5=TOF_monitor() SETTING, POSITION/ROTATION */
int _Monitor5_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Monitor5_setpos] component Monitor5=TOF_monitor() SETTING [TOF_monitor:0]");
  stracpy(_Monitor5_var._name, "Monitor5", 16384);
  stracpy(_Monitor5_var._type, "TOF_monitor", 16384);
  _Monitor5_var._index=18;
  int current_setpos_index = 18;
  _Monitor5_var._parameters.nt = 100;
  if("monitor5.dat" && strlen("monitor5.dat"))
    stracpy(_Monitor5_var._parameters.filename, "monitor5.dat" ? "monitor5.dat" : "", 16384);
  else 
  _Monitor5_var._parameters.filename[0]='\0';
  _Monitor5_var._parameters.xmin = -0.05;
  _Monitor5_var._parameters.xmax = 0.05;
  _Monitor5_var._parameters.ymin = -0.05;
  _Monitor5_var._parameters.ymax = 0.05;
  _Monitor5_var._parameters.xwidth = 0.06;
  _Monitor5_var._parameters.yheight = 0.08;
  _Monitor5_var._parameters.tmin = 1e6 * ( ( L_Ch4 + smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset );
  _Monitor5_var._parameters.tmax = 1e6 * ( ( L_Ch4 + smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset );
  _Monitor5_var._parameters.dt = 1.0;
  _Monitor5_var._parameters.restore_neutron = 1;
  _Monitor5_var._parameters.nowritefile = ! _instrument_var._parameters.monitors_on;


  /* component Monitor5=TOF_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _Monitor5_var._rotation_absolute);
    rot_transpose(_LET_Chopper4_var._rotation_absolute, tr1);
    rot_mul(_Monitor5_var._rotation_absolute, tr1, _Monitor5_var._rotation_relative);
    _Monitor5_var._rotation_is_identity =  rot_test_identity(_Monitor5_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch4 + smidge);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _Monitor5_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_LET_Chopper4_var._position_absolute, _Monitor5_var._position_absolute);
    _Monitor5_var._position_relative = rot_apply(_Monitor5_var._rotation_absolute, tc1);
  } /* Monitor5=TOF_monitor() AT ROTATED */
  DEBUG_COMPONENT("Monitor5", _Monitor5_var._position_absolute, _Monitor5_var._rotation_absolute);
  instrument->_position_absolute[18] = _Monitor5_var._position_absolute;
  instrument->_position_relative[18] = _Monitor5_var._position_relative;
    _Monitor5_var._position_relative_is_zero =  coords_test_zero(_Monitor5_var._position_relative);
  instrument->counter_N[18]  = instrument->counter_P[18] = instrument->counter_P2[18] = 0;
  instrument->counter_AbsorbProp[18]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0017_Monitor5", _Monitor5_var._position_absolute, _Monitor5_var._rotation_absolute, "TOF_monitor");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "nt", "20", "100","int");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "filename", 0, "monitor5.dat", "char*");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "yheight", "0", "0.08","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "tmin", "0", "1e6 * ( ( L_Ch4 + smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "tmax", "0", "1e6 * ( ( L_Ch4 + smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "dt", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0017_Monitor5", "nowritefile", "0", "! _instrument_var._parameters.monitors_on","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Monitor5_setpos */

/* component between_chop4_and_movable=Guide_channeled() SETTING, POSITION/ROTATION */
int _between_chop4_and_movable_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_between_chop4_and_movable_setpos] component between_chop4_and_movable=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_between_chop4_and_movable_var._name, "between_chop4_and_movable", 16384);
  stracpy(_between_chop4_and_movable_var._type, "Guide_channeled", 16384);
  _between_chop4_and_movable_var._index=19;
  int current_setpos_index = 19;
  _between_chop4_and_movable_var._parameters.w1 = 0.04;
  _between_chop4_and_movable_var._parameters.h1 = 0.09;
  _between_chop4_and_movable_var._parameters.w2 = 0;
  _between_chop4_and_movable_var._parameters.h2 = 0.0639;
  _between_chop4_and_movable_var._parameters.l = 5.800;
  _between_chop4_and_movable_var._parameters.R0 = 0.995;
  _between_chop4_and_movable_var._parameters.Qc = 0;
  _between_chop4_and_movable_var._parameters.alpha = 4.38;
  _between_chop4_and_movable_var._parameters.m = 0;
  _between_chop4_and_movable_var._parameters.nslit = 1;
  _between_chop4_and_movable_var._parameters.d = 0.0005;
  _between_chop4_and_movable_var._parameters.Qcx = 0.0218;
  _between_chop4_and_movable_var._parameters.Qcy = 0.0218;
  _between_chop4_and_movable_var._parameters.alphax = 4.38;
  _between_chop4_and_movable_var._parameters.alphay = 4.38;
  _between_chop4_and_movable_var._parameters.W = 3e-3;
  _between_chop4_and_movable_var._parameters.mx = 2;
  _between_chop4_and_movable_var._parameters.my = 3;
  _between_chop4_and_movable_var._parameters.nu = 0;
  _between_chop4_and_movable_var._parameters.phase = 0;


  /* component between_chop4_and_movable=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _between_chop4_and_movable_var._rotation_absolute);
    rot_transpose(_Monitor5_var._rotation_absolute, tr1);
    rot_mul(_between_chop4_and_movable_var._rotation_absolute, tr1, _between_chop4_and_movable_var._rotation_relative);
    _between_chop4_and_movable_var._rotation_is_identity =  rot_test_identity(_between_chop4_and_movable_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 15.681);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _between_chop4_and_movable_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_Monitor5_var._position_absolute, _between_chop4_and_movable_var._position_absolute);
    _between_chop4_and_movable_var._position_relative = rot_apply(_between_chop4_and_movable_var._rotation_absolute, tc1);
  } /* between_chop4_and_movable=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("between_chop4_and_movable", _between_chop4_and_movable_var._position_absolute, _between_chop4_and_movable_var._rotation_absolute);
  instrument->_position_absolute[19] = _between_chop4_and_movable_var._position_absolute;
  instrument->_position_relative[19] = _between_chop4_and_movable_var._position_relative;
    _between_chop4_and_movable_var._position_relative_is_zero =  coords_test_zero(_between_chop4_and_movable_var._position_relative);
  instrument->counter_N[19]  = instrument->counter_P[19] = instrument->counter_P2[19] = 0;
  instrument->counter_AbsorbProp[19]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0018_between_chop4_and_movable", _between_chop4_and_movable_var._position_absolute, _between_chop4_and_movable_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "w1", "NONE", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "h1", "NONE", "0.09","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "w2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "h2", "0", "0.0639","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "l", "NONE", "5.800","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "m", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "mx", "1", "2","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "my", "1", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0018_between_chop4_and_movable", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _between_chop4_and_movable_setpos */

/* component moveable_front_PSDmon=PSD_monitor() SETTING, POSITION/ROTATION */
int _moveable_front_PSDmon_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_moveable_front_PSDmon_setpos] component moveable_front_PSDmon=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_moveable_front_PSDmon_var._name, "moveable_front_PSDmon", 16384);
  stracpy(_moveable_front_PSDmon_var._type, "PSD_monitor", 16384);
  _moveable_front_PSDmon_var._index=20;
  int current_setpos_index = 20;
  _moveable_front_PSDmon_var._parameters.nx = 50;
  _moveable_front_PSDmon_var._parameters.ny = 50;
  if("moveable_front_PSDmon.dat" && strlen("moveable_front_PSDmon.dat"))
    stracpy(_moveable_front_PSDmon_var._parameters.filename, "moveable_front_PSDmon.dat" ? "moveable_front_PSDmon.dat" : "", 16384);
  else 
  _moveable_front_PSDmon_var._parameters.filename[0]='\0';
  _moveable_front_PSDmon_var._parameters.xmin = -0.05;
  _moveable_front_PSDmon_var._parameters.xmax = 0.05;
  _moveable_front_PSDmon_var._parameters.ymin = -0.05;
  _moveable_front_PSDmon_var._parameters.ymax = 0.05;
  _moveable_front_PSDmon_var._parameters.xwidth = 0.06;
  _moveable_front_PSDmon_var._parameters.yheight = 0.08;
  _moveable_front_PSDmon_var._parameters.restore_neutron = 1;
  _moveable_front_PSDmon_var._parameters.nowritefile = ! _instrument_var._parameters.movable_monitors;


  /* component moveable_front_PSDmon=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _moveable_front_PSDmon_var._rotation_absolute);
    rot_transpose(_between_chop4_and_movable_var._rotation_absolute, tr1);
    rot_mul(_moveable_front_PSDmon_var._rotation_absolute, tr1, _moveable_front_PSDmon_var._rotation_relative);
    _moveable_front_PSDmon_var._rotation_is_identity =  rot_test_identity(_moveable_front_PSDmon_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 21.485);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _moveable_front_PSDmon_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_between_chop4_and_movable_var._position_absolute, _moveable_front_PSDmon_var._position_absolute);
    _moveable_front_PSDmon_var._position_relative = rot_apply(_moveable_front_PSDmon_var._rotation_absolute, tc1);
  } /* moveable_front_PSDmon=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("moveable_front_PSDmon", _moveable_front_PSDmon_var._position_absolute, _moveable_front_PSDmon_var._rotation_absolute);
  instrument->_position_absolute[20] = _moveable_front_PSDmon_var._position_absolute;
  instrument->_position_relative[20] = _moveable_front_PSDmon_var._position_relative;
    _moveable_front_PSDmon_var._position_relative_is_zero =  coords_test_zero(_moveable_front_PSDmon_var._position_relative);
  instrument->counter_N[20]  = instrument->counter_P[20] = instrument->counter_P2[20] = 0;
  instrument->counter_AbsorbProp[20]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0019_moveable_front_PSDmon", _moveable_front_PSDmon_var._position_absolute, _moveable_front_PSDmon_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "nx", "90", "50","int");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "ny", "90", "50","int");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "filename", 0, "moveable_front_PSDmon.dat", "char*");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "yheight", "0", "0.08","MCNUM");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0019_moveable_front_PSDmon", "nowritefile", "0", "! _instrument_var._parameters.movable_monitors","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _moveable_front_PSDmon_setpos */

/* component moveable_front_Divmon=Divergence_monitor() SETTING, POSITION/ROTATION */
int _moveable_front_Divmon_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_moveable_front_Divmon_setpos] component moveable_front_Divmon=Divergence_monitor() SETTING [Divergence_monitor:0]");
  stracpy(_moveable_front_Divmon_var._name, "moveable_front_Divmon", 16384);
  stracpy(_moveable_front_Divmon_var._type, "Divergence_monitor", 16384);
  _moveable_front_Divmon_var._index=21;
  int current_setpos_index = 21;
  _moveable_front_Divmon_var._parameters.nh = 50;
  _moveable_front_Divmon_var._parameters.nv = 50;
  if("moveable_front_Divmon.dat" && strlen("moveable_front_Divmon.dat"))
    stracpy(_moveable_front_Divmon_var._parameters.filename, "moveable_front_Divmon.dat" ? "moveable_front_Divmon.dat" : "", 16384);
  else 
  _moveable_front_Divmon_var._parameters.filename[0]='\0';
  _moveable_front_Divmon_var._parameters.xmin = -0.05;
  _moveable_front_Divmon_var._parameters.xmax = 0.05;
  _moveable_front_Divmon_var._parameters.ymin = -0.05;
  _moveable_front_Divmon_var._parameters.ymax = 0.05;
  _moveable_front_Divmon_var._parameters.nowritefile = ! _instrument_var._parameters.movable_monitors;
  _moveable_front_Divmon_var._parameters.xwidth = 0.06;
  _moveable_front_Divmon_var._parameters.yheight = 0.08;
  _moveable_front_Divmon_var._parameters.maxdiv_h = 3;
  _moveable_front_Divmon_var._parameters.maxdiv_v = 3;
  _moveable_front_Divmon_var._parameters.restore_neutron = 1;
  _moveable_front_Divmon_var._parameters.nx = 0;
  _moveable_front_Divmon_var._parameters.ny = 0;
  _moveable_front_Divmon_var._parameters.nz = 1;


  /* component moveable_front_Divmon=Divergence_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _moveable_front_Divmon_var._rotation_absolute);
    rot_transpose(_moveable_front_PSDmon_var._rotation_absolute, tr1);
    rot_mul(_moveable_front_Divmon_var._rotation_absolute, tr1, _moveable_front_Divmon_var._rotation_relative);
    _moveable_front_Divmon_var._rotation_is_identity =  rot_test_identity(_moveable_front_Divmon_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 21.485);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _moveable_front_Divmon_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_moveable_front_PSDmon_var._position_absolute, _moveable_front_Divmon_var._position_absolute);
    _moveable_front_Divmon_var._position_relative = rot_apply(_moveable_front_Divmon_var._rotation_absolute, tc1);
  } /* moveable_front_Divmon=Divergence_monitor() AT ROTATED */
  DEBUG_COMPONENT("moveable_front_Divmon", _moveable_front_Divmon_var._position_absolute, _moveable_front_Divmon_var._rotation_absolute);
  instrument->_position_absolute[21] = _moveable_front_Divmon_var._position_absolute;
  instrument->_position_relative[21] = _moveable_front_Divmon_var._position_relative;
    _moveable_front_Divmon_var._position_relative_is_zero =  coords_test_zero(_moveable_front_Divmon_var._position_relative);
  instrument->counter_N[21]  = instrument->counter_P[21] = instrument->counter_P2[21] = 0;
  instrument->counter_AbsorbProp[21]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0020_moveable_front_Divmon", _moveable_front_Divmon_var._position_absolute, _moveable_front_Divmon_var._rotation_absolute, "Divergence_monitor");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "nh", "20", "50","int");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "nv", "20", "50","int");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "filename", 0, "moveable_front_Divmon.dat", "char*");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "nowritefile", "0", "! _instrument_var._parameters.movable_monitors","int");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "yheight", "0", "0.08","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "maxdiv_h", "2", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "maxdiv_v", "2", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "nx", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "ny", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0020_moveable_front_Divmon", "nz", "1", "1","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _moveable_front_Divmon_setpos */

/* component moveable_guide=Guide_channeled() SETTING, POSITION/ROTATION */
int _moveable_guide_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_moveable_guide_setpos] component moveable_guide=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_moveable_guide_var._name, "moveable_guide", 16384);
  stracpy(_moveable_guide_var._type, "Guide_channeled", 16384);
  _moveable_guide_var._index=22;
  int current_setpos_index = 22;
  _moveable_guide_var._parameters.w1 = 0.04;
  _moveable_guide_var._parameters.h1 = 0.0639;
  _moveable_guide_var._parameters.w2 = 0.0311;
  _moveable_guide_var._parameters.h2 = 0.05718;
  _moveable_guide_var._parameters.l = 0.8813;
  _moveable_guide_var._parameters.R0 = 0.995;
  _moveable_guide_var._parameters.Qc = 0;
  _moveable_guide_var._parameters.alpha = 4.38;
  _moveable_guide_var._parameters.m = 4;
  _moveable_guide_var._parameters.nslit = 1;
  _moveable_guide_var._parameters.d = 0.0005;
  _moveable_guide_var._parameters.Qcx = 0.0218;
  _moveable_guide_var._parameters.Qcy = 0.0218;
  _moveable_guide_var._parameters.alphax = 4.38;
  _moveable_guide_var._parameters.alphay = 4.38;
  _moveable_guide_var._parameters.W = 3e-3;
  _moveable_guide_var._parameters.mx = 1;
  _moveable_guide_var._parameters.my = 1;
  _moveable_guide_var._parameters.nu = 0;
  _moveable_guide_var._parameters.phase = 0;


  /* component moveable_guide=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _moveable_guide_var._rotation_absolute);
    rot_transpose(_moveable_front_Divmon_var._rotation_absolute, tr1);
    rot_mul(_moveable_guide_var._rotation_absolute, tr1, _moveable_guide_var._rotation_relative);
    _moveable_guide_var._rotation_is_identity =  rot_test_identity(_moveable_guide_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 21.489);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _moveable_guide_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_moveable_front_Divmon_var._position_absolute, _moveable_guide_var._position_absolute);
    _moveable_guide_var._position_relative = rot_apply(_moveable_guide_var._rotation_absolute, tc1);
  } /* moveable_guide=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("moveable_guide", _moveable_guide_var._position_absolute, _moveable_guide_var._rotation_absolute);
  instrument->_position_absolute[22] = _moveable_guide_var._position_absolute;
  instrument->_position_relative[22] = _moveable_guide_var._position_relative;
    _moveable_guide_var._position_relative_is_zero =  coords_test_zero(_moveable_guide_var._position_relative);
  instrument->counter_N[22]  = instrument->counter_P[22] = instrument->counter_P2[22] = 0;
  instrument->counter_AbsorbProp[22]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0021_moveable_guide", _moveable_guide_var._position_absolute, _moveable_guide_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "w1", "NONE", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "h1", "NONE", "0.0639","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "w2", "0", "0.0311","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "h2", "0", "0.05718","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "l", "NONE", "0.8813","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "m", "0", "4","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "mx", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "my", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0021_moveable_guide", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _moveable_guide_setpos */

/* component moveable_back_PSDmon=PSD_monitor() SETTING, POSITION/ROTATION */
int _moveable_back_PSDmon_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_moveable_back_PSDmon_setpos] component moveable_back_PSDmon=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_moveable_back_PSDmon_var._name, "moveable_back_PSDmon", 16384);
  stracpy(_moveable_back_PSDmon_var._type, "PSD_monitor", 16384);
  _moveable_back_PSDmon_var._index=23;
  int current_setpos_index = 23;
  _moveable_back_PSDmon_var._parameters.nx = 100;
  _moveable_back_PSDmon_var._parameters.ny = 100;
  if("moveable_back_PSDmon.dat" && strlen("moveable_back_PSDmon.dat"))
    stracpy(_moveable_back_PSDmon_var._parameters.filename, "moveable_back_PSDmon.dat" ? "moveable_back_PSDmon.dat" : "", 16384);
  else 
  _moveable_back_PSDmon_var._parameters.filename[0]='\0';
  _moveable_back_PSDmon_var._parameters.xmin = -0.05;
  _moveable_back_PSDmon_var._parameters.xmax = 0.05;
  _moveable_back_PSDmon_var._parameters.ymin = -0.05;
  _moveable_back_PSDmon_var._parameters.ymax = 0.05;
  _moveable_back_PSDmon_var._parameters.xwidth = 0.06;
  _moveable_back_PSDmon_var._parameters.yheight = 0.08;
  _moveable_back_PSDmon_var._parameters.restore_neutron = 1;
  _moveable_back_PSDmon_var._parameters.nowritefile = ! _instrument_var._parameters.movable_monitors;


  /* component moveable_back_PSDmon=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _moveable_back_PSDmon_var._rotation_absolute);
    rot_transpose(_moveable_guide_var._rotation_absolute, tr1);
    rot_mul(_moveable_back_PSDmon_var._rotation_absolute, tr1, _moveable_back_PSDmon_var._rotation_relative);
    _moveable_back_PSDmon_var._rotation_is_identity =  rot_test_identity(_moveable_back_PSDmon_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 22.372);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _moveable_back_PSDmon_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_moveable_guide_var._position_absolute, _moveable_back_PSDmon_var._position_absolute);
    _moveable_back_PSDmon_var._position_relative = rot_apply(_moveable_back_PSDmon_var._rotation_absolute, tc1);
  } /* moveable_back_PSDmon=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("moveable_back_PSDmon", _moveable_back_PSDmon_var._position_absolute, _moveable_back_PSDmon_var._rotation_absolute);
  instrument->_position_absolute[23] = _moveable_back_PSDmon_var._position_absolute;
  instrument->_position_relative[23] = _moveable_back_PSDmon_var._position_relative;
    _moveable_back_PSDmon_var._position_relative_is_zero =  coords_test_zero(_moveable_back_PSDmon_var._position_relative);
  instrument->counter_N[23]  = instrument->counter_P[23] = instrument->counter_P2[23] = 0;
  instrument->counter_AbsorbProp[23]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0022_moveable_back_PSDmon", _moveable_back_PSDmon_var._position_absolute, _moveable_back_PSDmon_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "filename", 0, "moveable_back_PSDmon.dat", "char*");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "yheight", "0", "0.08","MCNUM");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0022_moveable_back_PSDmon", "nowritefile", "0", "! _instrument_var._parameters.movable_monitors","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _moveable_back_PSDmon_setpos */

/* component moveable_back_Divmon=Divergence_monitor() SETTING, POSITION/ROTATION */
int _moveable_back_Divmon_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_moveable_back_Divmon_setpos] component moveable_back_Divmon=Divergence_monitor() SETTING [Divergence_monitor:0]");
  stracpy(_moveable_back_Divmon_var._name, "moveable_back_Divmon", 16384);
  stracpy(_moveable_back_Divmon_var._type, "Divergence_monitor", 16384);
  _moveable_back_Divmon_var._index=24;
  int current_setpos_index = 24;
  _moveable_back_Divmon_var._parameters.nh = 50;
  _moveable_back_Divmon_var._parameters.nv = 50;
  if("moveable_back_Divmon.dat" && strlen("moveable_back_Divmon.dat"))
    stracpy(_moveable_back_Divmon_var._parameters.filename, "moveable_back_Divmon.dat" ? "moveable_back_Divmon.dat" : "", 16384);
  else 
  _moveable_back_Divmon_var._parameters.filename[0]='\0';
  _moveable_back_Divmon_var._parameters.xmin = -0.05;
  _moveable_back_Divmon_var._parameters.xmax = 0.05;
  _moveable_back_Divmon_var._parameters.ymin = -0.05;
  _moveable_back_Divmon_var._parameters.ymax = 0.05;
  _moveable_back_Divmon_var._parameters.nowritefile = ! _instrument_var._parameters.movable_monitors;
  _moveable_back_Divmon_var._parameters.xwidth = 0.06;
  _moveable_back_Divmon_var._parameters.yheight = 0.08;
  _moveable_back_Divmon_var._parameters.maxdiv_h = 3;
  _moveable_back_Divmon_var._parameters.maxdiv_v = 3;
  _moveable_back_Divmon_var._parameters.restore_neutron = 1;
  _moveable_back_Divmon_var._parameters.nx = 0;
  _moveable_back_Divmon_var._parameters.ny = 0;
  _moveable_back_Divmon_var._parameters.nz = 1;


  /* component moveable_back_Divmon=Divergence_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _moveable_back_Divmon_var._rotation_absolute);
    rot_transpose(_moveable_back_PSDmon_var._rotation_absolute, tr1);
    rot_mul(_moveable_back_Divmon_var._rotation_absolute, tr1, _moveable_back_Divmon_var._rotation_relative);
    _moveable_back_Divmon_var._rotation_is_identity =  rot_test_identity(_moveable_back_Divmon_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 22.372);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _moveable_back_Divmon_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_moveable_back_PSDmon_var._position_absolute, _moveable_back_Divmon_var._position_absolute);
    _moveable_back_Divmon_var._position_relative = rot_apply(_moveable_back_Divmon_var._rotation_absolute, tc1);
  } /* moveable_back_Divmon=Divergence_monitor() AT ROTATED */
  DEBUG_COMPONENT("moveable_back_Divmon", _moveable_back_Divmon_var._position_absolute, _moveable_back_Divmon_var._rotation_absolute);
  instrument->_position_absolute[24] = _moveable_back_Divmon_var._position_absolute;
  instrument->_position_relative[24] = _moveable_back_Divmon_var._position_relative;
    _moveable_back_Divmon_var._position_relative_is_zero =  coords_test_zero(_moveable_back_Divmon_var._position_relative);
  instrument->counter_N[24]  = instrument->counter_P[24] = instrument->counter_P2[24] = 0;
  instrument->counter_AbsorbProp[24]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0023_moveable_back_Divmon", _moveable_back_Divmon_var._position_absolute, _moveable_back_Divmon_var._rotation_absolute, "Divergence_monitor");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "nh", "20", "50","int");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "nv", "20", "50","int");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "filename", 0, "moveable_back_Divmon.dat", "char*");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "nowritefile", "0", "! _instrument_var._parameters.movable_monitors","int");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "yheight", "0", "0.08","MCNUM");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "maxdiv_h", "2", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "maxdiv_v", "2", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "nx", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "ny", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0023_moveable_back_Divmon", "nz", "1", "1","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _moveable_back_Divmon_setpos */

/* component funnel=Guide_channeled() SETTING, POSITION/ROTATION */
int _funnel_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_funnel_setpos] component funnel=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_funnel_var._name, "funnel", 16384);
  stracpy(_funnel_var._type, "Guide_channeled", 16384);
  _funnel_var._index=25;
  int current_setpos_index = 25;
  _funnel_var._parameters.w1 = 0.031;
  _funnel_var._parameters.h1 = 0.05711;
  _funnel_var._parameters.w2 = 0.02;
  _funnel_var._parameters.h2 = 0.04868;
  _funnel_var._parameters.l = 1.107;
  _funnel_var._parameters.R0 = 0.995;
  _funnel_var._parameters.Qc = 0;
  _funnel_var._parameters.alpha = 4.38;
  _funnel_var._parameters.m = 4;
  _funnel_var._parameters.nslit = 1;
  _funnel_var._parameters.d = 0.0005;
  _funnel_var._parameters.Qcx = 0.0218;
  _funnel_var._parameters.Qcy = 0.0218;
  _funnel_var._parameters.alphax = 4.38;
  _funnel_var._parameters.alphay = 4.38;
  _funnel_var._parameters.W = 3e-3;
  _funnel_var._parameters.mx = 1;
  _funnel_var._parameters.my = 1;
  _funnel_var._parameters.nu = 0;
  _funnel_var._parameters.phase = 0;


  /* component funnel=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _funnel_var._rotation_absolute);
    rot_transpose(_moveable_back_Divmon_var._rotation_absolute, tr1);
    rot_mul(_funnel_var._rotation_absolute, tr1, _funnel_var._rotation_relative);
    _funnel_var._rotation_is_identity =  rot_test_identity(_funnel_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 22.373);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _funnel_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_moveable_back_Divmon_var._position_absolute, _funnel_var._position_absolute);
    _funnel_var._position_relative = rot_apply(_funnel_var._rotation_absolute, tc1);
  } /* funnel=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("funnel", _funnel_var._position_absolute, _funnel_var._rotation_absolute);
  instrument->_position_absolute[25] = _funnel_var._position_absolute;
  instrument->_position_relative[25] = _funnel_var._position_relative;
    _funnel_var._position_relative_is_zero =  coords_test_zero(_funnel_var._position_relative);
  instrument->counter_N[25]  = instrument->counter_P[25] = instrument->counter_P2[25] = 0;
  instrument->counter_AbsorbProp[25]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0024_funnel", _funnel_var._position_absolute, _funnel_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0024_funnel", "w1", "NONE", "0.031","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "h1", "NONE", "0.05711","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "w2", "0", "0.02","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "h2", "0", "0.04868","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "l", "NONE", "1.107","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "m", "0", "4","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "mx", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "my", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0024_funnel", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _funnel_setpos */

/* component LET_Chopper5_Disk1=DiskChopper() SETTING, POSITION/ROTATION */
int _LET_Chopper5_Disk1_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_LET_Chopper5_Disk1_setpos] component LET_Chopper5_Disk1=DiskChopper() SETTING [DiskChopper:0]");
  stracpy(_LET_Chopper5_Disk1_var._name, "LET_Chopper5_Disk1", 16384);
  stracpy(_LET_Chopper5_Disk1_var._type, "DiskChopper", 16384);
  _LET_Chopper5_Disk1_var._index=26;
  int current_setpos_index = 26;
  _LET_Chopper5_Disk1_var._parameters.theta_0 = 0;
  _LET_Chopper5_Disk1_var._parameters.radius = 0.350;
  _LET_Chopper5_Disk1_var._parameters.yheight = 0.06;
  _LET_Chopper5_Disk1_var._parameters.nu = _instrument_var._parameters.Ch5_speed;
  _LET_Chopper5_Disk1_var._parameters.nslit = 1;
  _LET_Chopper5_Disk1_var._parameters.jitter = jitter;
  _LET_Chopper5_Disk1_var._parameters.delay = ( L_Ch5 - Ch1_5_halfgap ) / v_foc + _instrument_var._parameters.pha_offset;
  _LET_Chopper5_Disk1_var._parameters.isfirst = 0;
  _LET_Chopper5_Disk1_var._parameters.n_pulse = 1;
  _LET_Chopper5_Disk1_var._parameters.abs_out = 1;
  _LET_Chopper5_Disk1_var._parameters.phase = 0;
  _LET_Chopper5_Disk1_var._parameters.xwidth = Ch5_slit;
  _LET_Chopper5_Disk1_var._parameters.verbose = 0;


  /* component LET_Chopper5_Disk1=DiskChopper() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _LET_Chopper5_Disk1_var._rotation_absolute);
    rot_transpose(_funnel_var._rotation_absolute, tr1);
    rot_mul(_LET_Chopper5_Disk1_var._rotation_absolute, tr1, _LET_Chopper5_Disk1_var._rotation_relative);
    _LET_Chopper5_Disk1_var._rotation_is_identity =  rot_test_identity(_LET_Chopper5_Disk1_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch5 - Ch1_5_halfgap);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _LET_Chopper5_Disk1_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_funnel_var._position_absolute, _LET_Chopper5_Disk1_var._position_absolute);
    _LET_Chopper5_Disk1_var._position_relative = rot_apply(_LET_Chopper5_Disk1_var._rotation_absolute, tc1);
  } /* LET_Chopper5_Disk1=DiskChopper() AT ROTATED */
  DEBUG_COMPONENT("LET_Chopper5_Disk1", _LET_Chopper5_Disk1_var._position_absolute, _LET_Chopper5_Disk1_var._rotation_absolute);
  instrument->_position_absolute[26] = _LET_Chopper5_Disk1_var._position_absolute;
  instrument->_position_relative[26] = _LET_Chopper5_Disk1_var._position_relative;
    _LET_Chopper5_Disk1_var._position_relative_is_zero =  coords_test_zero(_LET_Chopper5_Disk1_var._position_relative);
  instrument->counter_N[26]  = instrument->counter_P[26] = instrument->counter_P2[26] = 0;
  instrument->counter_AbsorbProp[26]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0025_LET_Chopper5_Disk1", _LET_Chopper5_Disk1_var._position_absolute, _LET_Chopper5_Disk1_var._rotation_absolute, "DiskChopper");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "theta_0", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "radius", "0.5", "0.350","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "yheight", "NONE", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "nu", "NONE", "_instrument_var._parameters.Ch5_speed","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "nslit", "3", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "jitter", "0", "jitter","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "delay", "0", "( L_Ch5 - Ch1_5_halfgap ) / v_foc + _instrument_var._parameters.pha_offset","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "isfirst", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "n_pulse", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "abs_out", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "phase", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "xwidth", "0", "Ch5_slit","MCNUM");
        mccomp_param_nexus(nxhandle,"0025_LET_Chopper5_Disk1", "verbose", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _LET_Chopper5_Disk1_setpos */

/* component LET_Chopper5_Disk2=DiskChopper() SETTING, POSITION/ROTATION */
int _LET_Chopper5_Disk2_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_LET_Chopper5_Disk2_setpos] component LET_Chopper5_Disk2=DiskChopper() SETTING [DiskChopper:0]");
  stracpy(_LET_Chopper5_Disk2_var._name, "LET_Chopper5_Disk2", 16384);
  stracpy(_LET_Chopper5_Disk2_var._type, "DiskChopper", 16384);
  _LET_Chopper5_Disk2_var._index=27;
  int current_setpos_index = 27;
  _LET_Chopper5_Disk2_var._parameters.theta_0 = 0;
  _LET_Chopper5_Disk2_var._parameters.radius = 0.350;
  _LET_Chopper5_Disk2_var._parameters.yheight = 0.06;
  _LET_Chopper5_Disk2_var._parameters.nu = _instrument_var._parameters.Ch5_speed;
  _LET_Chopper5_Disk2_var._parameters.nslit = 1;
  _LET_Chopper5_Disk2_var._parameters.jitter = jitter;
  _LET_Chopper5_Disk2_var._parameters.delay = ( L_Ch5 + Ch1_5_halfgap ) / v_foc + _instrument_var._parameters.pha_offset;
  _LET_Chopper5_Disk2_var._parameters.isfirst = 0;
  _LET_Chopper5_Disk2_var._parameters.n_pulse = 1;
  _LET_Chopper5_Disk2_var._parameters.abs_out = 1;
  _LET_Chopper5_Disk2_var._parameters.phase = 0;
  _LET_Chopper5_Disk2_var._parameters.xwidth = Ch5_slit;
  _LET_Chopper5_Disk2_var._parameters.verbose = 0;


  /* component LET_Chopper5_Disk2=DiskChopper() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (0)*DEG2RAD, (180)*DEG2RAD);
    rot_mul(tr1, _LET_Chopper5_Disk1_var._rotation_absolute, _LET_Chopper5_Disk2_var._rotation_absolute);
    rot_transpose(_LET_Chopper5_Disk1_var._rotation_absolute, tr1);
    rot_mul(_LET_Chopper5_Disk2_var._rotation_absolute, tr1, _LET_Chopper5_Disk2_var._rotation_relative);
    _LET_Chopper5_Disk2_var._rotation_is_identity =  rot_test_identity(_LET_Chopper5_Disk2_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch5 + Ch1_5_halfgap);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _LET_Chopper5_Disk2_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_LET_Chopper5_Disk1_var._position_absolute, _LET_Chopper5_Disk2_var._position_absolute);
    _LET_Chopper5_Disk2_var._position_relative = rot_apply(_LET_Chopper5_Disk2_var._rotation_absolute, tc1);
  } /* LET_Chopper5_Disk2=DiskChopper() AT ROTATED */
  DEBUG_COMPONENT("LET_Chopper5_Disk2", _LET_Chopper5_Disk2_var._position_absolute, _LET_Chopper5_Disk2_var._rotation_absolute);
  instrument->_position_absolute[27] = _LET_Chopper5_Disk2_var._position_absolute;
  instrument->_position_relative[27] = _LET_Chopper5_Disk2_var._position_relative;
    _LET_Chopper5_Disk2_var._position_relative_is_zero =  coords_test_zero(_LET_Chopper5_Disk2_var._position_relative);
  instrument->counter_N[27]  = instrument->counter_P[27] = instrument->counter_P2[27] = 0;
  instrument->counter_AbsorbProp[27]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0026_LET_Chopper5_Disk2", _LET_Chopper5_Disk2_var._position_absolute, _LET_Chopper5_Disk2_var._rotation_absolute, "DiskChopper");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "theta_0", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "radius", "0.5", "0.350","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "yheight", "NONE", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "nu", "NONE", "_instrument_var._parameters.Ch5_speed","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "nslit", "3", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "jitter", "0", "jitter","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "delay", "0", "( L_Ch5 + Ch1_5_halfgap ) / v_foc + _instrument_var._parameters.pha_offset","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "isfirst", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "n_pulse", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "abs_out", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "phase", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "xwidth", "0", "Ch5_slit","MCNUM");
        mccomp_param_nexus(nxhandle,"0026_LET_Chopper5_Disk2", "verbose", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _LET_Chopper5_Disk2_setpos */

/* component Monitor6=TOF_monitor() SETTING, POSITION/ROTATION */
int _Monitor6_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Monitor6_setpos] component Monitor6=TOF_monitor() SETTING [TOF_monitor:0]");
  stracpy(_Monitor6_var._name, "Monitor6", 16384);
  stracpy(_Monitor6_var._type, "TOF_monitor", 16384);
  _Monitor6_var._index=28;
  int current_setpos_index = 28;
  _Monitor6_var._parameters.nt = 100;
  if("monitor6.dat" && strlen("monitor6.dat"))
    stracpy(_Monitor6_var._parameters.filename, "monitor6.dat" ? "monitor6.dat" : "", 16384);
  else 
  _Monitor6_var._parameters.filename[0]='\0';
  _Monitor6_var._parameters.xmin = -0.05;
  _Monitor6_var._parameters.xmax = 0.05;
  _Monitor6_var._parameters.ymin = -0.05;
  _Monitor6_var._parameters.ymax = 0.05;
  _Monitor6_var._parameters.xwidth = 0.06;
  _Monitor6_var._parameters.yheight = 0.06;
  _Monitor6_var._parameters.tmin = 1e6 * ( ( L_Ch5 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset );
  _Monitor6_var._parameters.tmax = 1e6 * ( ( L_Ch5 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset );
  _Monitor6_var._parameters.dt = 1.0;
  _Monitor6_var._parameters.restore_neutron = 1;
  _Monitor6_var._parameters.nowritefile = ! _instrument_var._parameters.monitors_on;


  /* component Monitor6=TOF_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _Monitor6_var._rotation_absolute);
    rot_transpose(_LET_Chopper5_Disk2_var._rotation_absolute, tr1);
    rot_mul(_Monitor6_var._rotation_absolute, tr1, _Monitor6_var._rotation_relative);
    _Monitor6_var._rotation_is_identity =  rot_test_identity(_Monitor6_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_Ch5 + Ch1_5_halfgap + smidge);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _Monitor6_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_LET_Chopper5_Disk2_var._position_absolute, _Monitor6_var._position_absolute);
    _Monitor6_var._position_relative = rot_apply(_Monitor6_var._rotation_absolute, tc1);
  } /* Monitor6=TOF_monitor() AT ROTATED */
  DEBUG_COMPONENT("Monitor6", _Monitor6_var._position_absolute, _Monitor6_var._rotation_absolute);
  instrument->_position_absolute[28] = _Monitor6_var._position_absolute;
  instrument->_position_relative[28] = _Monitor6_var._position_relative;
    _Monitor6_var._position_relative_is_zero =  coords_test_zero(_Monitor6_var._position_relative);
  instrument->counter_N[28]  = instrument->counter_P[28] = instrument->counter_P2[28] = 0;
  instrument->counter_AbsorbProp[28]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0027_Monitor6", _Monitor6_var._position_absolute, _Monitor6_var._rotation_absolute, "TOF_monitor");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "nt", "20", "100","int");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "filename", 0, "monitor6.dat", "char*");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "yheight", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "tmin", "0", "1e6 * ( ( L_Ch5 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emax ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "tmax", "0", "1e6 * ( ( L_Ch5 + Ch1_5_halfgap + smidge ) / SE2V / sqrt ( emin ) + _instrument_var._parameters.pha_offset )","MCNUM");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "dt", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0027_Monitor6", "nowritefile", "0", "! _instrument_var._parameters.monitors_on","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Monitor6_setpos */

/* component tanksection=Guide_channeled() SETTING, POSITION/ROTATION */
int _tanksection_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_tanksection_setpos] component tanksection=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_tanksection_var._name, "tanksection", 16384);
  stracpy(_tanksection_var._type, "Guide_channeled", 16384);
  _tanksection_var._index=29;
  int current_setpos_index = 29;
  _tanksection_var._parameters.w1 = 0.02;
  _tanksection_var._parameters.h1 = 0.0484;
  _tanksection_var._parameters.w2 = 0.020;
  _tanksection_var._parameters.h2 = 0.04;
  _tanksection_var._parameters.l = 1.1;
  _tanksection_var._parameters.R0 = 0.995;
  _tanksection_var._parameters.Qc = 0;
  _tanksection_var._parameters.alpha = 4.38;
  _tanksection_var._parameters.m = 4;
  _tanksection_var._parameters.nslit = 1;
  _tanksection_var._parameters.d = 0.0005;
  _tanksection_var._parameters.Qcx = 0.0218;
  _tanksection_var._parameters.Qcy = 0.0218;
  _tanksection_var._parameters.alphax = 4.38;
  _tanksection_var._parameters.alphay = 4.38;
  _tanksection_var._parameters.W = 3e-3;
  _tanksection_var._parameters.mx = 1;
  _tanksection_var._parameters.my = 1;
  _tanksection_var._parameters.nu = 0;
  _tanksection_var._parameters.phase = 0;


  /* component tanksection=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _tanksection_var._rotation_absolute);
    rot_transpose(_Monitor6_var._rotation_absolute, tr1);
    rot_mul(_tanksection_var._rotation_absolute, tr1, _tanksection_var._rotation_relative);
    _tanksection_var._rotation_is_identity =  rot_test_identity(_tanksection_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 23.52);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _tanksection_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_Monitor6_var._position_absolute, _tanksection_var._position_absolute);
    _tanksection_var._position_relative = rot_apply(_tanksection_var._rotation_absolute, tc1);
  } /* tanksection=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("tanksection", _tanksection_var._position_absolute, _tanksection_var._rotation_absolute);
  instrument->_position_absolute[29] = _tanksection_var._position_absolute;
  instrument->_position_relative[29] = _tanksection_var._position_relative;
    _tanksection_var._position_relative_is_zero =  coords_test_zero(_tanksection_var._position_relative);
  instrument->counter_N[29]  = instrument->counter_P[29] = instrument->counter_P2[29] = 0;
  instrument->counter_AbsorbProp[29]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0028_tanksection", _tanksection_var._position_absolute, _tanksection_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "w1", "NONE", "0.02","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "h1", "NONE", "0.0484","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "w2", "0", "0.020","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "h2", "0", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "l", "NONE", "1.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "m", "0", "4","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "mx", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "my", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0028_tanksection", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _tanksection_setpos */

/* component snout=Guide_channeled() SETTING, POSITION/ROTATION */
int _snout_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_snout_setpos] component snout=Guide_channeled() SETTING [Guide_channeled:0]");
  stracpy(_snout_var._name, "snout", 16384);
  stracpy(_snout_var._type, "Guide_channeled", 16384);
  _snout_var._index=30;
  int current_setpos_index = 30;
  _snout_var._parameters.w1 = 0.02;
  _snout_var._parameters.h1 = 0.04;
  _snout_var._parameters.w2 = 0;
  _snout_var._parameters.h2 = 0;
  _snout_var._parameters.l = snout_length;
  _snout_var._parameters.R0 = 0.995;
  _snout_var._parameters.Qc = 0;
  _snout_var._parameters.alpha = 4.38;
  _snout_var._parameters.m = 4;
  _snout_var._parameters.nslit = 1;
  _snout_var._parameters.d = 0.0005;
  _snout_var._parameters.Qcx = 0.0218;
  _snout_var._parameters.Qcy = 0.0218;
  _snout_var._parameters.alphax = 4.38;
  _snout_var._parameters.alphay = 4.38;
  _snout_var._parameters.W = 3e-3;
  _snout_var._parameters.mx = 1;
  _snout_var._parameters.my = 1;
  _snout_var._parameters.nu = 0;
  _snout_var._parameters.phase = 0;


  /* component snout=Guide_channeled() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _snout_var._rotation_absolute);
    rot_transpose(_tanksection_var._rotation_absolute, tr1);
    rot_mul(_snout_var._rotation_absolute, tr1, _snout_var._rotation_relative);
    _snout_var._rotation_is_identity =  rot_test_identity(_snout_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 24.622);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _snout_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_tanksection_var._position_absolute, _snout_var._position_absolute);
    _snout_var._position_relative = rot_apply(_snout_var._rotation_absolute, tc1);
  } /* snout=Guide_channeled() AT ROTATED */
  DEBUG_COMPONENT("snout", _snout_var._position_absolute, _snout_var._rotation_absolute);
  instrument->_position_absolute[30] = _snout_var._position_absolute;
  instrument->_position_relative[30] = _snout_var._position_relative;
    _snout_var._position_relative_is_zero =  coords_test_zero(_snout_var._position_relative);
  instrument->counter_N[30]  = instrument->counter_P[30] = instrument->counter_P2[30] = 0;
  instrument->counter_AbsorbProp[30]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0029_snout", _snout_var._position_absolute, _snout_var._rotation_absolute, "Guide_channeled");
        mccomp_param_nexus(nxhandle,"0029_snout", "w1", "NONE", "0.02","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "h1", "NONE", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "w2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "h2", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "l", "NONE", "snout_length","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "R0", "0.995", "0.995","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "Qc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "alpha", "0", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "m", "0", "4","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "nslit", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "d", "0.0005", "0.0005","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "Qcx", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "Qcy", "0.0218", "0.0218","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "alphax", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "alphay", "4.38", "4.38","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "W", "0.003", "3e-3","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "mx", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "my", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "nu", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0029_snout", "phase", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _snout_setpos */

/* component sample=Arm() SETTING, POSITION/ROTATION */
int _sample_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_setpos] component sample=Arm() SETTING [Arm:0]");
  stracpy(_sample_var._name, "sample", 16384);
  stracpy(_sample_var._type, "Arm", 16384);
  _sample_var._index=31;
  int current_setpos_index = 31;
  /* component sample=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _Origin_var._rotation_absolute, _sample_var._rotation_absolute);
    rot_transpose(_snout_var._rotation_absolute, tr1);
    rot_mul(_sample_var._rotation_absolute, tr1, _sample_var._rotation_relative);
    _sample_var._rotation_is_identity =  rot_test_identity(_sample_var._rotation_relative);
    tc1 = coords_set(
      0, 0, L_sample);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_var._position_absolute = coords_add(_Origin_var._position_absolute, tc2);
    tc1 = coords_sub(_snout_var._position_absolute, _sample_var._position_absolute);
    _sample_var._position_relative = rot_apply(_sample_var._rotation_absolute, tc1);
  } /* sample=Arm() AT ROTATED */
  DEBUG_COMPONENT("sample", _sample_var._position_absolute, _sample_var._rotation_absolute);
  instrument->_position_absolute[31] = _sample_var._position_absolute;
  instrument->_position_relative[31] = _sample_var._position_relative;
    _sample_var._position_relative_is_zero =  coords_test_zero(_sample_var._position_relative);
  instrument->counter_N[31]  = instrument->counter_P[31] = instrument->counter_P2[31] = 0;
  instrument->counter_AbsorbProp[31]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0030_sample", _sample_var._position_absolute, _sample_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_setpos */

/* component sample_PSDmon=PSD_monitor() SETTING, POSITION/ROTATION */
int _sample_PSDmon_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_PSDmon_setpos] component sample_PSDmon=PSD_monitor() SETTING [PSD_monitor:0]");
  stracpy(_sample_PSDmon_var._name, "sample_PSDmon", 16384);
  stracpy(_sample_PSDmon_var._type, "PSD_monitor", 16384);
  _sample_PSDmon_var._index=32;
  int current_setpos_index = 32;
  _sample_PSDmon_var._parameters.nx = 100;
  _sample_PSDmon_var._parameters.ny = 100;
  if("sample_PSDmon.dat" && strlen("sample_PSDmon.dat"))
    stracpy(_sample_PSDmon_var._parameters.filename, "sample_PSDmon.dat" ? "sample_PSDmon.dat" : "", 16384);
  else 
  _sample_PSDmon_var._parameters.filename[0]='\0';
  _sample_PSDmon_var._parameters.xmin = -0.05;
  _sample_PSDmon_var._parameters.xmax = 0.05;
  _sample_PSDmon_var._parameters.ymin = -0.05;
  _sample_PSDmon_var._parameters.ymax = 0.05;
  _sample_PSDmon_var._parameters.xwidth = 0.04;
  _sample_PSDmon_var._parameters.yheight = 0.06;
  _sample_PSDmon_var._parameters.restore_neutron = 1;
  _sample_PSDmon_var._parameters.nowritefile = 0;


  /* component sample_PSDmon=PSD_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _sample_var._rotation_absolute, _sample_PSDmon_var._rotation_absolute);
    rot_transpose(_snout_var._rotation_absolute, tr1);
    rot_mul(_sample_PSDmon_var._rotation_absolute, tr1, _sample_PSDmon_var._rotation_relative);
    _sample_PSDmon_var._rotation_is_identity =  rot_test_identity(_sample_PSDmon_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_PSDmon_var._position_absolute = coords_add(_sample_var._position_absolute, tc2);
    tc1 = coords_sub(_snout_var._position_absolute, _sample_PSDmon_var._position_absolute);
    _sample_PSDmon_var._position_relative = rot_apply(_sample_PSDmon_var._rotation_absolute, tc1);
  } /* sample_PSDmon=PSD_monitor() AT ROTATED */
  DEBUG_COMPONENT("sample_PSDmon", _sample_PSDmon_var._position_absolute, _sample_PSDmon_var._rotation_absolute);
  instrument->_position_absolute[32] = _sample_PSDmon_var._position_absolute;
  instrument->_position_relative[32] = _sample_PSDmon_var._position_relative;
    _sample_PSDmon_var._position_relative_is_zero =  coords_test_zero(_sample_PSDmon_var._position_relative);
  instrument->counter_N[32]  = instrument->counter_P[32] = instrument->counter_P2[32] = 0;
  instrument->counter_AbsorbProp[32]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0031_sample_PSDmon", _sample_PSDmon_var._position_absolute, _sample_PSDmon_var._rotation_absolute, "PSD_monitor");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "nx", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "ny", "90", "100","int");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "filename", 0, "sample_PSDmon.dat", "char*");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "xwidth", "0", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "yheight", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0031_sample_PSDmon", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_PSDmon_setpos */

/* component sample_Divmon=Divergence_monitor() SETTING, POSITION/ROTATION */
int _sample_Divmon_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_Divmon_setpos] component sample_Divmon=Divergence_monitor() SETTING [Divergence_monitor:0]");
  stracpy(_sample_Divmon_var._name, "sample_Divmon", 16384);
  stracpy(_sample_Divmon_var._type, "Divergence_monitor", 16384);
  _sample_Divmon_var._index=33;
  int current_setpos_index = 33;
  _sample_Divmon_var._parameters.nh = 50;
  _sample_Divmon_var._parameters.nv = 50;
  if("sample_Divmon.dat" && strlen("sample_Divmon.dat"))
    stracpy(_sample_Divmon_var._parameters.filename, "sample_Divmon.dat" ? "sample_Divmon.dat" : "", 16384);
  else 
  _sample_Divmon_var._parameters.filename[0]='\0';
  _sample_Divmon_var._parameters.xmin = -0.05;
  _sample_Divmon_var._parameters.xmax = 0.05;
  _sample_Divmon_var._parameters.ymin = -0.05;
  _sample_Divmon_var._parameters.ymax = 0.05;
  _sample_Divmon_var._parameters.nowritefile = 0;
  _sample_Divmon_var._parameters.xwidth = 0.06;
  _sample_Divmon_var._parameters.yheight = 0.06;
  _sample_Divmon_var._parameters.maxdiv_h = 3;
  _sample_Divmon_var._parameters.maxdiv_v = 3;
  _sample_Divmon_var._parameters.restore_neutron = 1;
  _sample_Divmon_var._parameters.nx = 0;
  _sample_Divmon_var._parameters.ny = 0;
  _sample_Divmon_var._parameters.nz = 1;


  /* component sample_Divmon=Divergence_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _sample_var._rotation_absolute, _sample_Divmon_var._rotation_absolute);
    rot_transpose(_sample_PSDmon_var._rotation_absolute, tr1);
    rot_mul(_sample_Divmon_var._rotation_absolute, tr1, _sample_Divmon_var._rotation_relative);
    _sample_Divmon_var._rotation_is_identity =  rot_test_identity(_sample_Divmon_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_Divmon_var._position_absolute = coords_add(_sample_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_PSDmon_var._position_absolute, _sample_Divmon_var._position_absolute);
    _sample_Divmon_var._position_relative = rot_apply(_sample_Divmon_var._rotation_absolute, tc1);
  } /* sample_Divmon=Divergence_monitor() AT ROTATED */
  DEBUG_COMPONENT("sample_Divmon", _sample_Divmon_var._position_absolute, _sample_Divmon_var._rotation_absolute);
  instrument->_position_absolute[33] = _sample_Divmon_var._position_absolute;
  instrument->_position_relative[33] = _sample_Divmon_var._position_relative;
    _sample_Divmon_var._position_relative_is_zero =  coords_test_zero(_sample_Divmon_var._position_relative);
  instrument->counter_N[33]  = instrument->counter_P[33] = instrument->counter_P2[33] = 0;
  instrument->counter_AbsorbProp[33]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0032_sample_Divmon", _sample_Divmon_var._position_absolute, _sample_Divmon_var._rotation_absolute, "Divergence_monitor");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "nh", "20", "50","int");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "nv", "20", "50","int");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "filename", 0, "sample_Divmon.dat", "char*");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "nowritefile", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "xwidth", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "yheight", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "maxdiv_h", "2", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "maxdiv_v", "2", "3","MCNUM");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "nx", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "ny", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0032_sample_Divmon", "nz", "1", "1","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_Divmon_setpos */

/* component sample_tof=TOF_monitor() SETTING, POSITION/ROTATION */
int _sample_tof_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_tof_setpos] component sample_tof=TOF_monitor() SETTING [TOF_monitor:0]");
  stracpy(_sample_tof_var._name, "sample_tof", 16384);
  stracpy(_sample_tof_var._type, "TOF_monitor", 16384);
  _sample_tof_var._index=34;
  int current_setpos_index = 34;
  _sample_tof_var._parameters.nt = 100;
  if("sample_tof.dat" && strlen("sample_tof.dat"))
    stracpy(_sample_tof_var._parameters.filename, "sample_tof.dat" ? "sample_tof.dat" : "", 16384);
  else 
  _sample_tof_var._parameters.filename[0]='\0';
  _sample_tof_var._parameters.xmin = -0.05;
  _sample_tof_var._parameters.xmax = 0.05;
  _sample_tof_var._parameters.ymin = -0.05;
  _sample_tof_var._parameters.ymax = 0.05;
  _sample_tof_var._parameters.xwidth = 0.04;
  _sample_tof_var._parameters.yheight = 0.06;
  _sample_tof_var._parameters.tmin = 1e6 * ( ( L_sample ) / SE2V / sqrt ( _instrument_var._parameters.Ei ) + _instrument_var._parameters.pha_offset ) * 0.99;
  _sample_tof_var._parameters.tmax = 1e6 * ( ( L_sample ) / SE2V / sqrt ( _instrument_var._parameters.Ei ) + _instrument_var._parameters.pha_offset ) * 1.01;
  _sample_tof_var._parameters.dt = 1.0;
  _sample_tof_var._parameters.restore_neutron = 1;
  _sample_tof_var._parameters.nowritefile = 0;


  /* component sample_tof=TOF_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _sample_var._rotation_absolute, _sample_tof_var._rotation_absolute);
    rot_transpose(_sample_Divmon_var._rotation_absolute, tr1);
    rot_mul(_sample_tof_var._rotation_absolute, tr1, _sample_tof_var._rotation_relative);
    _sample_tof_var._rotation_is_identity =  rot_test_identity(_sample_tof_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_tof_var._position_absolute = coords_add(_sample_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_Divmon_var._position_absolute, _sample_tof_var._position_absolute);
    _sample_tof_var._position_relative = rot_apply(_sample_tof_var._rotation_absolute, tc1);
  } /* sample_tof=TOF_monitor() AT ROTATED */
  DEBUG_COMPONENT("sample_tof", _sample_tof_var._position_absolute, _sample_tof_var._rotation_absolute);
  instrument->_position_absolute[34] = _sample_tof_var._position_absolute;
  instrument->_position_relative[34] = _sample_tof_var._position_relative;
    _sample_tof_var._position_relative_is_zero =  coords_test_zero(_sample_tof_var._position_relative);
  instrument->counter_N[34]  = instrument->counter_P[34] = instrument->counter_P2[34] = 0;
  instrument->counter_AbsorbProp[34]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0033_sample_tof", _sample_tof_var._position_absolute, _sample_tof_var._rotation_absolute, "TOF_monitor");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "nt", "20", "100","int");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "filename", 0, "sample_tof.dat", "char*");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "xwidth", "0", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "yheight", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "tmin", "0", "1e6 * ( ( L_sample ) / SE2V / sqrt ( _instrument_var._parameters.Ei ) + _instrument_var._parameters.pha_offset ) * 0.99","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "tmax", "0", "1e6 * ( ( L_sample ) / SE2V / sqrt ( _instrument_var._parameters.Ei ) + _instrument_var._parameters.pha_offset ) * 1.01","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "dt", "1.0", "1.0","MCNUM");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0033_sample_tof", "nowritefile", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_tof_setpos */

/* component sample_Emon=E_monitor() SETTING, POSITION/ROTATION */
int _sample_Emon_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_Emon_setpos] component sample_Emon=E_monitor() SETTING [E_monitor:0]");
  stracpy(_sample_Emon_var._name, "sample_Emon", 16384);
  stracpy(_sample_Emon_var._type, "E_monitor", 16384);
  _sample_Emon_var._index=35;
  int current_setpos_index = 35;
  _sample_Emon_var._parameters.nE = 100;
  if("sample_Emon.dat" && strlen("sample_Emon.dat"))
    stracpy(_sample_Emon_var._parameters.filename, "sample_Emon.dat" ? "sample_Emon.dat" : "", 16384);
  else 
  _sample_Emon_var._parameters.filename[0]='\0';
  _sample_Emon_var._parameters.xmin = -0.05;
  _sample_Emon_var._parameters.xmax = 0.05;
  _sample_Emon_var._parameters.ymin = -0.05;
  _sample_Emon_var._parameters.ymax = 0.05;
  _sample_Emon_var._parameters.nowritefile = 0;
  _sample_Emon_var._parameters.xwidth = 0.04;
  _sample_Emon_var._parameters.yheight = 0.06;
  _sample_Emon_var._parameters.Emin = _instrument_var._parameters.Ei - ( emax - emin ) / 12;
  _sample_Emon_var._parameters.Emax = _instrument_var._parameters.Ei + ( emax - emin ) / 6;
  _sample_Emon_var._parameters.restore_neutron = 1;


  /* component sample_Emon=E_monitor() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _sample_var._rotation_absolute, _sample_Emon_var._rotation_absolute);
    rot_transpose(_sample_tof_var._rotation_absolute, tr1);
    rot_mul(_sample_Emon_var._rotation_absolute, tr1, _sample_Emon_var._rotation_relative);
    _sample_Emon_var._rotation_is_identity =  rot_test_identity(_sample_Emon_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_Emon_var._position_absolute = coords_add(_sample_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_tof_var._position_absolute, _sample_Emon_var._position_absolute);
    _sample_Emon_var._position_relative = rot_apply(_sample_Emon_var._rotation_absolute, tc1);
  } /* sample_Emon=E_monitor() AT ROTATED */
  DEBUG_COMPONENT("sample_Emon", _sample_Emon_var._position_absolute, _sample_Emon_var._rotation_absolute);
  instrument->_position_absolute[35] = _sample_Emon_var._position_absolute;
  instrument->_position_relative[35] = _sample_Emon_var._position_relative;
    _sample_Emon_var._position_relative_is_zero =  coords_test_zero(_sample_Emon_var._position_relative);
  instrument->counter_N[35]  = instrument->counter_P[35] = instrument->counter_P2[35] = 0;
  instrument->counter_AbsorbProp[35]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0034_sample_Emon", _sample_Emon_var._position_absolute, _sample_Emon_var._rotation_absolute, "E_monitor");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "nE", "20", "100","int");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "filename", 0, "sample_Emon.dat", "char*");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "xmin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "xmax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "ymin", "-0.05", "-0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "ymax", "0.05", "0.05","MCNUM");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "nowritefile", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "xwidth", "0", "0.04","MCNUM");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "yheight", "0", "0.06","MCNUM");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "Emin", "NONE", "_instrument_var._parameters.Ei - ( emax - emin ) / 12","MCNUM");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "Emax", "NONE", "_instrument_var._parameters.Ei + ( emax - emin ) / 6","MCNUM");
        mccomp_param_nexus(nxhandle,"0034_sample_Emon", "restore_neutron", "0", "1","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_Emon_setpos */

/* component iso_samp=Isotropic_Sqw() SETTING, POSITION/ROTATION */
int _iso_samp_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_iso_samp_setpos] component iso_samp=Isotropic_Sqw() SETTING [Isotropic_Sqw:0]");
  stracpy(_iso_samp_var._name, "iso_samp", 16384);
  stracpy(_iso_samp_var._type, "Isotropic_Sqw", 16384);
  _iso_samp_var._index=36;
  int current_setpos_index = 36;
  _iso_samp_var._parameters.powder_format[0] = 0;
  _iso_samp_var._parameters.powder_format[1] = 0;
  _iso_samp_var._parameters.powder_format[2] = 0;
  _iso_samp_var._parameters.powder_format[3] = 0;
  _iso_samp_var._parameters.powder_format[4] = 0;
  _iso_samp_var._parameters.powder_format[5] = 0;
  _iso_samp_var._parameters.powder_format[6] = 0;
  _iso_samp_var._parameters.powder_format[7] = 0;
  _iso_samp_var._parameters.powder_format[8] = 0;
  if(_instrument_var._parameters.sample_coh && strlen(_instrument_var._parameters.sample_coh))
    stracpy(_iso_samp_var._parameters.Sqw_coh, _instrument_var._parameters.sample_coh ? _instrument_var._parameters.sample_coh : "", 16384);
  else 
  _iso_samp_var._parameters.Sqw_coh[0]='\0';
  if(_instrument_var._parameters.sample_inc && strlen(_instrument_var._parameters.sample_inc))
    stracpy(_iso_samp_var._parameters.Sqw_inc, _instrument_var._parameters.sample_inc ? _instrument_var._parameters.sample_inc : "", 16384);
  else 
  _iso_samp_var._parameters.Sqw_inc[0]='\0';
  _iso_samp_var._parameters.geometry[0]='\0';
  _iso_samp_var._parameters.radius = 0.01;
  _iso_samp_var._parameters.thickness = 0;
  _iso_samp_var._parameters.xwidth = 0;
  _iso_samp_var._parameters.yheight = 0.055;
  _iso_samp_var._parameters.zdepth = 0;
  _iso_samp_var._parameters.threshold = 1e-20;
  _iso_samp_var._parameters.order = 0;
  _iso_samp_var._parameters.T = 0;
  _iso_samp_var._parameters.verbose = 1;
  _iso_samp_var._parameters.d_phi = 0;
  _iso_samp_var._parameters.concentric = 0;
  _iso_samp_var._parameters.rho = 0;
  _iso_samp_var._parameters.sigma_abs = 0;
  _iso_samp_var._parameters.sigma_coh = 0;
  _iso_samp_var._parameters.sigma_inc = 0;
  _iso_samp_var._parameters.classical = 1;
  _iso_samp_var._parameters.powder_Dd = 0;
  _iso_samp_var._parameters.powder_DW = 0;
  _iso_samp_var._parameters.powder_Vc = 0;
  _iso_samp_var._parameters.density = 0;
  _iso_samp_var._parameters.weight = 0;
  _iso_samp_var._parameters.p_interact = 0.2;
  _iso_samp_var._parameters.norm = -1;
  _iso_samp_var._parameters.powder_barns = 1;
  if("Frommhold" && strlen("Frommhold"))
    stracpy(_iso_samp_var._parameters.quantum_correction, "Frommhold" ? "Frommhold" : "", 16384);
  else 
  _iso_samp_var._parameters.quantum_correction[0]='\0';


  /* component iso_samp=Isotropic_Sqw() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _sample_var._rotation_absolute, _iso_samp_var._rotation_absolute);
    rot_transpose(_sample_Emon_var._rotation_absolute, tr1);
    rot_mul(_iso_samp_var._rotation_absolute, tr1, _iso_samp_var._rotation_relative);
    _iso_samp_var._rotation_is_identity =  rot_test_identity(_iso_samp_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _iso_samp_var._position_absolute = coords_add(_sample_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_Emon_var._position_absolute, _iso_samp_var._position_absolute);
    _iso_samp_var._position_relative = rot_apply(_iso_samp_var._rotation_absolute, tc1);
  } /* iso_samp=Isotropic_Sqw() AT ROTATED */
  DEBUG_COMPONENT("iso_samp", _iso_samp_var._position_absolute, _iso_samp_var._rotation_absolute);
  instrument->_position_absolute[36] = _iso_samp_var._position_absolute;
  instrument->_position_relative[36] = _iso_samp_var._position_relative;
    _iso_samp_var._position_relative_is_zero =  coords_test_zero(_iso_samp_var._position_relative);
  instrument->counter_N[36]  = instrument->counter_P[36] = instrument->counter_P2[36] = 0;
  instrument->counter_AbsorbProp[36]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0035_iso_samp", _iso_samp_var._position_absolute, _iso_samp_var._rotation_absolute, "Isotropic_Sqw");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "powder_format", "{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }", "{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "Sqw_coh", 0, _instrument_var._parameters.sample_coh, "char*");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "Sqw_inc", 0, _instrument_var._parameters.sample_inc, "char*");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "geometry", 0, 0, "char*");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "radius", "0", "0.01","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "thickness", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "yheight", "0", "0.055","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "zdepth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "threshold", "1e-20", "1e-20","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "order", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "T", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "verbose", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "d_phi", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "concentric", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "rho", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "sigma_abs", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "sigma_coh", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "sigma_inc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "classical", "-1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "powder_Dd", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "powder_DW", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "powder_Vc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "density", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "weight", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "p_interact", "-1", "0.2","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "norm", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "powder_barns", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0035_iso_samp", "quantum_correction", "Frommhold", "Frommhold", "char*");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _iso_samp_setpos */

/* component detectorArm=Arm() SETTING, POSITION/ROTATION */
int _detectorArm_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_detectorArm_setpos] component detectorArm=Arm() SETTING [Arm:0]");
  stracpy(_detectorArm_var._name, "detectorArm", 16384);
  stracpy(_detectorArm_var._type, "Arm", 16384);
  _detectorArm_var._index=37;
  int current_setpos_index = 37;
  /* component detectorArm=Arm() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0)*DEG2RAD, (90)*DEG2RAD, (0)*DEG2RAD);
    rot_mul(tr1, _sample_var._rotation_absolute, _detectorArm_var._rotation_absolute);
    rot_transpose(_iso_samp_var._rotation_absolute, tr1);
    rot_mul(_detectorArm_var._rotation_absolute, tr1, _detectorArm_var._rotation_relative);
    _detectorArm_var._rotation_is_identity =  rot_test_identity(_detectorArm_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _detectorArm_var._position_absolute = coords_add(_sample_var._position_absolute, tc2);
    tc1 = coords_sub(_iso_samp_var._position_absolute, _detectorArm_var._position_absolute);
    _detectorArm_var._position_relative = rot_apply(_detectorArm_var._rotation_absolute, tc1);
  } /* detectorArm=Arm() AT ROTATED */
  DEBUG_COMPONENT("detectorArm", _detectorArm_var._position_absolute, _detectorArm_var._rotation_absolute);
  instrument->_position_absolute[37] = _detectorArm_var._position_absolute;
  instrument->_position_relative[37] = _detectorArm_var._position_relative;
    _detectorArm_var._position_relative_is_zero =  coords_test_zero(_detectorArm_var._position_relative);
  instrument->counter_N[37]  = instrument->counter_P[37] = instrument->counter_P2[37] = 0;
  instrument->counter_AbsorbProp[37]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0036_detectorArm", _detectorArm_var._position_absolute, _detectorArm_var._rotation_absolute, "Arm");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _detectorArm_setpos */

/* component Banana_1=Monitor_nD() SETTING, POSITION/ROTATION */
int _Banana_1_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Banana_1_setpos] component Banana_1=Monitor_nD() SETTING [Monitor_nD:0]");
  stracpy(_Banana_1_var._name, "Banana_1", 16384);
  stracpy(_Banana_1_var._type, "Monitor_nD", 16384);
  _Banana_1_var._index=38;
  int current_setpos_index = 38;
  if("" && strlen(""))
    stracpy(_Banana_1_var._parameters.user1, "" ? "" : "", 16384);
  else 
  _Banana_1_var._parameters.user1[0]='\0';
  if("" && strlen(""))
    stracpy(_Banana_1_var._parameters.user2, "" ? "" : "", 16384);
  else 
  _Banana_1_var._parameters.user2[0]='\0';
  if("" && strlen(""))
    stracpy(_Banana_1_var._parameters.user3, "" ? "" : "", 16384);
  else 
  _Banana_1_var._parameters.user3[0]='\0';
  _Banana_1_var._parameters.xwidth = 0;
  _Banana_1_var._parameters.yheight = 0.1;
  _Banana_1_var._parameters.zdepth = 0;
  _Banana_1_var._parameters.xmin = 0;
  _Banana_1_var._parameters.xmax = 0;
  _Banana_1_var._parameters.ymin = 0;
  _Banana_1_var._parameters.ymax = 0;
  _Banana_1_var._parameters.zmin = 0;
  _Banana_1_var._parameters.zmax = 0;
  _Banana_1_var._parameters.bins = 0;
  _Banana_1_var._parameters.min = -1e40;
  _Banana_1_var._parameters.max = 1e40;
  _Banana_1_var._parameters.restore_neutron = 1;
  _Banana_1_var._parameters.radius = 1;
  if("mantid banana theta bins=20 limits=[-10, 25] y bins=12, neutron pixel min=0 t, list all neutrons" && strlen("mantid banana theta bins=20 limits=[-10, 25] y bins=12, neutron pixel min=0 t, list all neutrons"))
    stracpy(_Banana_1_var._parameters.options, "mantid banana theta bins=20 limits=[-10, 25] y bins=12, neutron pixel min=0 t, list all neutrons" ? "mantid banana theta bins=20 limits=[-10, 25] y bins=12, neutron pixel min=0 t, list all neutrons" : "", 16384);
  else 
  _Banana_1_var._parameters.options[0]='\0';
  if("direct_event_banana_signal.dat" && strlen("direct_event_banana_signal.dat"))
    stracpy(_Banana_1_var._parameters.filename, "direct_event_banana_signal.dat" ? "direct_event_banana_signal.dat" : "", 16384);
  else 
  _Banana_1_var._parameters.filename[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_Banana_1_var._parameters.geometry, "NULL" ? "NULL" : "", 16384);
  else 
  _Banana_1_var._parameters.geometry[0]='\0';
  _Banana_1_var._parameters.nowritefile = 0;
  _Banana_1_var._parameters.nexus_bins = 0;
  if("NULL" && strlen("NULL"))
    stracpy(_Banana_1_var._parameters.username1, "NULL" ? "NULL" : "", 16384);
  else 
  _Banana_1_var._parameters.username1[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_Banana_1_var._parameters.username2, "NULL" ? "NULL" : "", 16384);
  else 
  _Banana_1_var._parameters.username2[0]='\0';
  if("NULL" && strlen("NULL"))
    stracpy(_Banana_1_var._parameters.username3, "NULL" ? "NULL" : "", 16384);
  else 
  _Banana_1_var._parameters.username3[0]='\0';


  /* component Banana_1=Monitor_nD() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _sample_var._rotation_absolute, _Banana_1_var._rotation_absolute);
    rot_transpose(_iso_samp_var._rotation_absolute, tr1);
    rot_mul(_Banana_1_var._rotation_absolute, tr1, _Banana_1_var._rotation_relative);
    _Banana_1_var._rotation_is_identity =  rot_test_identity(_Banana_1_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0.0);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _Banana_1_var._position_absolute = coords_add(_sample_var._position_absolute, tc2);
    tc1 = coords_sub(_iso_samp_var._position_absolute, _Banana_1_var._position_absolute);
    _Banana_1_var._position_relative = rot_apply(_Banana_1_var._rotation_absolute, tc1);
  } /* Banana_1=Monitor_nD() AT ROTATED */
  DEBUG_COMPONENT("Banana_1", _Banana_1_var._position_absolute, _Banana_1_var._rotation_absolute);
  instrument->_position_absolute[38] = _Banana_1_var._position_absolute;
  instrument->_position_relative[38] = _Banana_1_var._position_relative;
    _Banana_1_var._position_relative_is_zero =  coords_test_zero(_Banana_1_var._position_relative);
  instrument->counter_N[38]  = instrument->counter_P[38] = instrument->counter_P2[38] = 0;
  instrument->counter_AbsorbProp[38]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0037_Banana_1", _Banana_1_var._position_absolute, _Banana_1_var._rotation_absolute, "Monitor_nD");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "user1", "", "", "char*");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "user2", "", "", "char*");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "user3", "", "", "char*");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "yheight", "0", "0.1","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "zdepth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "xmin", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "xmax", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "ymin", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "ymax", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "zmin", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "zmax", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "bins", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "min", "-1e40", "-1e40","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "max", "1e40", "1e40","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "restore_neutron", "0", "1","int");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "radius", "0", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "options", "NULL", "mantid banana theta bins=20 limits=[-10, 25] y bins=12, neutron pixel min=0 t, list all neutrons", "char*");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "filename", "NULL", "direct_event_banana_signal.dat", "char*");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "geometry", "NULL", "NULL", "char*");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "nowritefile", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "nexus_bins", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "username1", "NULL", "NULL", "char*");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "username2", "NULL", "NULL", "char*");
        mccomp_param_nexus(nxhandle,"0037_Banana_1", "username3", "NULL", "NULL", "char*");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Banana_1_setpos */

_class_Commodus_I3 *class_Commodus_I3_init(_class_Commodus_I3 *_comp
) {
  #define Face (_comp->_parameters.Face)
  #define E0 (_comp->_parameters.E0)
  #define E1 (_comp->_parameters.E1)
  #define modPosition (_comp->_parameters.modPosition)
  #define dist (_comp->_parameters.dist)
  #define verbose (_comp->_parameters.verbose)
  #define beamcurrent (_comp->_parameters.beamcurrent)
  #define modXsize (_comp->_parameters.modXsize)
  #define modZsize (_comp->_parameters.modZsize)
  #define xw (_comp->_parameters.xw)
  #define yh (_comp->_parameters.yh)
  #define p_in (_comp->_parameters.p_in)
  #define Tnpts (_comp->_parameters.Tnpts)
  #define scaleSize (_comp->_parameters.scaleSize)
  #define angleArea (_comp->_parameters.angleArea)
  #define Nsim (_comp->_parameters.Nsim)
  #define Ncount (_comp->_parameters.Ncount)
  #define TS (_comp->_parameters.TS)
  #define fullAngle (_comp->_parameters.fullAngle)
  #define rtE0 (_comp->_parameters.rtE0)
  #define rtE1 (_comp->_parameters.rtE1)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  SIG_MESSAGE("[_SourceMantid_init] component SourceMantid=Commodus_I3() INITIALISE [Commodus_I3:0]");

  xwidth = modXsize;
  yheight = modZsize;
  focus_xw = xw;
  focus_yh = yh;

  /* READ IN THE ENERGY FILE */
  FILE* Tfile;

  Nsim = mcget_ncount (); // Number of points requested.

  Tfile = openFile (Face); // Get open file
  rtE0 = convertEnergy (E0);
  rtE1 = convertEnergy (E1);
  orderEnergy (&rtE0, &rtE1);

  readHtable (Tfile, rtE0, rtE1, &TS, modPosition, xwidth, yheight, verbose);
  fclose (Tfile);
  // Below pragma was needed with PGI 19.x, compilation fails with NVC 20.7
  // #pragma acc declare create( TS )
  /**********************************************************************/

  Tnpts = 0;
  Ncount = 0;

  fprintf (stderr, "Face == %s \n", Face);
  fprintf (stderr, "Number of Energy Points == %d\n", TS.nEnergy);
  if (dist < 0) {
    dist = TS.rdumMid;
    fprintf (stderr, "Setting distance to moderator surface == %g\n", dist);
  }
  /* Do solid angle correction */
  angleArea = strArea (TS, focus_xw, focus_yh, dist);
  // Below pragma was needed with PGI 19.x, compilation fails with NVC 20.7
  // #pragma acc update host( TS )
  fprintf (stderr, "Totals:: %g %d %d \n", TS.Total, TS.nEnergy, TS.nTime);
  #undef Face
  #undef E0
  #undef E1
  #undef modPosition
  #undef dist
  #undef verbose
  #undef beamcurrent
  #undef modXsize
  #undef modZsize
  #undef xw
  #undef yh
  #undef p_in
  #undef Tnpts
  #undef scaleSize
  #undef angleArea
  #undef Nsim
  #undef Ncount
  #undef TS
  #undef fullAngle
  #undef rtE0
  #undef rtE1
  #undef xwidth
  #undef yheight
  #undef focus_xw
  #undef focus_yh
  return(_comp);
} /* class_Commodus_I3_init */

_class_Guide_channeled *class_Guide_channeled_init(_class_Guide_channeled *_comp
) {
  #define w1 (_comp->_parameters.w1)
  #define h1 (_comp->_parameters.h1)
  #define w2 (_comp->_parameters.w2)
  #define h2 (_comp->_parameters.h2)
  #define l (_comp->_parameters.l)
  #define R0 (_comp->_parameters.R0)
  #define Qc (_comp->_parameters.Qc)
  #define alpha (_comp->_parameters.alpha)
  #define m (_comp->_parameters.m)
  #define nslit (_comp->_parameters.nslit)
  #define d (_comp->_parameters.d)
  #define Qcx (_comp->_parameters.Qcx)
  #define Qcy (_comp->_parameters.Qcy)
  #define alphax (_comp->_parameters.alphax)
  #define alphay (_comp->_parameters.alphay)
  #define W (_comp->_parameters.W)
  #define mx (_comp->_parameters.mx)
  #define my (_comp->_parameters.my)
  #define nu (_comp->_parameters.nu)
  #define phase (_comp->_parameters.phase)
  #define w1c (_comp->_parameters.w1c)
  #define w2c (_comp->_parameters.w2c)
  #define ww (_comp->_parameters.ww)
  #define hh (_comp->_parameters.hh)
  #define whalf (_comp->_parameters.whalf)
  #define hhalf (_comp->_parameters.hhalf)
  #define lwhalf (_comp->_parameters.lwhalf)
  #define lhhalf (_comp->_parameters.lhhalf)
  SIG_MESSAGE("[_shutter_init] component shutter=Guide_channeled() INITIALISE [Guide_channeled:0]");

  if (!w2)
    w2 = w1;
  if (!h2)
    h2 = h1;
  if (nslit <= 0 || W <= 0) {
    fprintf (stderr, "Guide_channeled: %s: nslit and W must be positive\n", NAME_CURRENT_COMP);
    exit (-1);
  }
  w1c = (w1 + d) / (double)nslit;
  w2c = (w2 + d) / (double)nslit;
  ww = .5 * (w2c - w1c);
  hh = .5 * (h2 - h1);
  whalf = .5 * (w1c - d);
  hhalf = .5 * h1;
  lwhalf = l * whalf;
  lhhalf = l * hhalf;

  if (m) {
    mx = my = m;
  }
  if (Qc) {
    Qcx = Qcy = Qc;
  }
  if (alpha) {
    alphax = alphay = alpha;
  }

  if ((nslit > 1) && (w1 != w2)) {
    fprintf (stderr,
             "WARNING: Guide_channeled: %s:"
             "This component does not work with multichannel focusing guide\n"
             "Use Guide_gravity for that.\n",
             NAME_CURRENT_COMP);
    exit (-1);
  }

  if (d * nslit > w1)
    exit (fprintf (stderr, "Guide_channeled: %s: absorbing walls fill input window. No space left for transmission (d*nslit > w1).\n", NAME_CURRENT_COMP));

  if (mcgravitation)
    fprintf (stderr,
             "WARNING: Guide_channeled: %s: "
             "This component produces wrong results with gravitation !\n"
             "Use Guide_gravity.\n",
             NAME_CURRENT_COMP);
  if (nu != 0 || phase != 0) {
    if (w1 != w2 || h1 != h2)
      exit (fprintf (stderr, "Guide_channeled: %s: rotating slit pack must be straight (w1=w2 and h1=h2).\n", NAME_CURRENT_COMP));
    printf ("Guide_channeled: %s: Fermi Chopper mode: frequency=%g [Hz] phase=%g [deg]\n", NAME_CURRENT_COMP, nu, phase);
  }
  #undef w1
  #undef h1
  #undef w2
  #undef h2
  #undef l
  #undef R0
  #undef Qc
  #undef alpha
  #undef m
  #undef nslit
  #undef d
  #undef Qcx
  #undef Qcy
  #undef alphax
  #undef alphay
  #undef W
  #undef mx
  #undef my
  #undef nu
  #undef phase
  #undef w1c
  #undef w2c
  #undef ww
  #undef hh
  #undef whalf
  #undef hhalf
  #undef lwhalf
  #undef lhhalf
  return(_comp);
} /* class_Guide_channeled_init */

_class_TOF_monitor *class_TOF_monitor_init(_class_TOF_monitor *_comp
) {
  #define nt (_comp->_parameters.nt)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define tmin (_comp->_parameters.tmin)
  #define tmax (_comp->_parameters.tmax)
  #define dt (_comp->_parameters.dt)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define TOF_N (_comp->_parameters.TOF_N)
  #define TOF_p (_comp->_parameters.TOF_p)
  #define TOF_p2 (_comp->_parameters.TOF_p2)
  #define t_min (_comp->_parameters.t_min)
  #define t_max (_comp->_parameters.t_max)
  #define delta_t (_comp->_parameters.delta_t)
  SIG_MESSAGE("[_Monitor1_init] component Monitor1=TOF_monitor() INITIALISE [TOF_monitor:0]");

  if (xwidth > 0) {
    xmax = xwidth / 2;
    xmin = -xmax;
  }
  if (yheight > 0) {
    ymax = yheight / 2;
    ymin = -ymax;
  }

  if ((xmin >= xmax) || (ymin >= ymax)) {
    printf ("TOF_monitor: %s: Null detection area !\n"
            "ERROR        (xwidth,yheight,xmin,xmax,ymin,ymax). Exiting",
            NAME_CURRENT_COMP);
    exit (0);
  }

  TOF_N = create_darr1d (nt);
  TOF_p = create_darr1d (nt);
  TOF_p2 = create_darr1d (nt);

  if (tmax != 0) {
    t_max = tmax;
    t_min = tmin;
    delta_t = (t_max - t_min) / nt;
  } else {
    delta_t = dt;
    t_min = 0;
    t_max = nt * dt + tmin;
  }

  // Use instance name for monitor output if no input was given
  if (!strcmp (filename, "\0"))
    sprintf (filename, "%s", NAME_CURRENT_COMP);
  #undef nt
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef tmin
  #undef tmax
  #undef dt
  #undef restore_neutron
  #undef nowritefile
  #undef TOF_N
  #undef TOF_p
  #undef TOF_p2
  #undef t_min
  #undef t_max
  #undef delta_t
  return(_comp);
} /* class_TOF_monitor_init */

_class_DiskChopper *class_DiskChopper_init(_class_DiskChopper *_comp
) {
  #define theta_0 (_comp->_parameters.theta_0)
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define nu (_comp->_parameters.nu)
  #define nslit (_comp->_parameters.nslit)
  #define jitter (_comp->_parameters.jitter)
  #define delay (_comp->_parameters.delay)
  #define isfirst (_comp->_parameters.isfirst)
  #define n_pulse (_comp->_parameters.n_pulse)
  #define abs_out (_comp->_parameters.abs_out)
  #define phase (_comp->_parameters.phase)
  #define xwidth (_comp->_parameters.xwidth)
  #define verbose (_comp->_parameters.verbose)
  #define Tg (_comp->_parameters.Tg)
  #define To (_comp->_parameters.To)
  #define delta_y (_comp->_parameters.delta_y)
  #define height (_comp->_parameters.height)
  #define omega (_comp->_parameters.omega)
  SIG_MESSAGE("[_LET_Chopper1_disk1_init] component LET_Chopper1_disk1=DiskChopper() INITIALISE [DiskChopper:0]");

  /* If slit height 'unset', assume full opening */
  if (yheight == 0) {
    height = radius;
  } else {
    height = yheight;
  }
  delta_y = radius - height / 2; /* radius at beam center */
  omega = 2.0 * PI * nu;         /* rad/s */
  if (xwidth && !theta_0 && radius)
    theta_0 = 2 * RAD2DEG * asin (xwidth / 2 / delta_y);

  if (nslit <= 0 || theta_0 <= 0 || radius <= 0) {
    fprintf (stderr, "DiskChopper: %s: nslit, theta_0 and radius must be > 0\n", NAME_CURRENT_COMP);
    exit (-1);
  }
  if (nslit * theta_0 >= 360) {
    fprintf (stderr, "DiskChopper: %s: nslit * theta_0 exceeds 2PI\n", NAME_CURRENT_COMP);
    exit (-1);
  }
  if (yheight && yheight > radius) {
    fprintf (stderr, "DiskChopper: %s: yheight must be < radius\n", NAME_CURRENT_COMP);
    exit (-1);
  }
  if (isfirst && n_pulse <= 0) {
    fprintf (stderr, "DiskChopper: %s: wrong First chopper pulse number (n_pulse=%g)\n", NAME_CURRENT_COMP, n_pulse);
    exit (-1);
  }
  if (!omega) {
    fprintf (stderr, "DiskChopper: %s WARNING: chopper frequency is 0!\n", NAME_CURRENT_COMP);
    omega = 1e-15; /* We should actually use machine epsilon here... */
  }
  if (!abs_out) {
    fprintf (stderr, "DiskChopper: %s WARNING: chopper will NOT absorb neutrons outside radius %g [m]\n", NAME_CURRENT_COMP, radius);
  }

  theta_0 *= DEG2RAD;

  /* Calulate delay from phase and vice versa */
  if (phase) {
    if (delay) {
      fprintf (stderr, "DiskChopper: %s WARNING: delay AND phase specified. Using phase setting\n", NAME_CURRENT_COMP);
    }
    phase *= DEG2RAD;
    /* 'Delay' should always be a delay, taking rotation direction into account: */
    delay = phase / fabs (omega);
  } else {
    phase = delay * omega; /* rad */
  }

  /* Time from opening of slit to next opening of slit */
  Tg = 2.0 * PI / fabs (omega) / nslit;

  /* How long can neutrons pass the Chopper at a single point */
  To = theta_0 / fabs (omega);

  if (!xwidth)
    xwidth = 2 * delta_y * sin (theta_0 / 2);

  if (verbose && nu) {
    printf ("DiskChopper: %s: frequency=%g [Hz] %g [rpm], time frame=%g [s] phase=%g [deg]\n", NAME_CURRENT_COMP, nu, nu * 60, Tg, phase * RAD2DEG);
    printf ("             %g slits, angle=%g [deg] height=%g [m], width=%g [m] at radius=%g [m]\n", nslit, theta_0 * RAD2DEG, height, xwidth, delta_y);
  }
  #undef theta_0
  #undef radius
  #undef yheight
  #undef nu
  #undef nslit
  #undef jitter
  #undef delay
  #undef isfirst
  #undef n_pulse
  #undef abs_out
  #undef phase
  #undef xwidth
  #undef verbose
  #undef Tg
  #undef To
  #undef delta_y
  #undef height
  #undef omega
  return(_comp);
} /* class_DiskChopper_init */

_class_PSD_monitor *class_PSD_monitor_init(_class_PSD_monitor *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_moveable_front_PSDmon_init] component moveable_front_PSDmon=PSD_monitor() INITIALISE [PSD_monitor:0]");

  if (xwidth > 0) {
    xmax = xwidth / 2;
    xmin = -xmax;
  }
  if (yheight > 0) {
    ymax = yheight / 2;
    ymin = -ymax;
  }

  if ((xmin >= xmax) || (ymin >= ymax)) {
    printf ("PSD_monitor: %s: Null detection area !\n"
            "ERROR        (xwidth,yheight,xmin,xmax,ymin,ymax). Exiting",
            NAME_CURRENT_COMP);
    exit (0);
  }

  PSD_N = create_darr2d (nx, ny);
  PSD_p = create_darr2d (nx, ny);
  PSD_p2 = create_darr2d (nx, ny);

  // Use instance name for monitor output if no input was given
  if (!strcmp (filename, "\0"))
    sprintf (filename, "%s", NAME_CURRENT_COMP);
  #undef nx
  #undef ny
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef restore_neutron
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_init */

_class_Divergence_monitor *class_Divergence_monitor_init(_class_Divergence_monitor *_comp
) {
  #define nh (_comp->_parameters.nh)
  #define nv (_comp->_parameters.nv)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define maxdiv_h (_comp->_parameters.maxdiv_h)
  #define maxdiv_v (_comp->_parameters.maxdiv_v)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define nz (_comp->_parameters.nz)
  #define Div_N (_comp->_parameters.Div_N)
  #define Div_p (_comp->_parameters.Div_p)
  #define Div_p2 (_comp->_parameters.Div_p2)
  SIG_MESSAGE("[_moveable_front_Divmon_init] component moveable_front_Divmon=Divergence_monitor() INITIALISE [Divergence_monitor:0]");

  if (xwidth > 0) {
    xmax = xwidth / 2;
    xmin = -xmax;
  }
  if (yheight > 0) {
    ymax = yheight / 2;
    ymin = -ymax;
  }

  if ((xmin >= xmax) || (ymin >= ymax)) {
    printf ("Divergence_monitor: %s: Null detection area !\n"
            "ERROR               (xwidth,yheight,xmin,xmax,ymin,ymax). Exiting",
            NAME_CURRENT_COMP);
    exit (0);
  }

  Div_N = create_darr2d (nh, nv);
  Div_p = create_darr2d (nh, nv);
  Div_p2 = create_darr2d (nh, nv);

  NORM (nx, ny, nz);

  // Use instance name for monitor output if no input was given
  if (!strcmp (filename, "\0"))
    sprintf (filename, "%s", NAME_CURRENT_COMP);
  #undef nh
  #undef nv
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef nowritefile
  #undef xwidth
  #undef yheight
  #undef maxdiv_h
  #undef maxdiv_v
  #undef restore_neutron
  #undef nx
  #undef ny
  #undef nz
  #undef Div_N
  #undef Div_p
  #undef Div_p2
  return(_comp);
} /* class_Divergence_monitor_init */

_class_E_monitor *class_E_monitor_init(_class_E_monitor *_comp
) {
  #define nE (_comp->_parameters.nE)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define Emin (_comp->_parameters.Emin)
  #define Emax (_comp->_parameters.Emax)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define E_N (_comp->_parameters.E_N)
  #define E_p (_comp->_parameters.E_p)
  #define E_p2 (_comp->_parameters.E_p2)
  #define S_p (_comp->_parameters.S_p)
  #define S_pE (_comp->_parameters.S_pE)
  #define S_pE2 (_comp->_parameters.S_pE2)
  SIG_MESSAGE("[_sample_Emon_init] component sample_Emon=E_monitor() INITIALISE [E_monitor:0]");

  if (xwidth > 0) {
    xmax = xwidth / 2;
    xmin = -xmax;
  }
  if (yheight > 0) {
    ymax = yheight / 2;
    ymin = -ymax;
  }

  if ((xmin >= xmax) || (ymin >= ymax)) {
    printf ("E_monitor: %s: Null detection area !\n"
            "ERROR      (xwidth,yheight,xmin,xmax,ymin,ymax). Exiting",
            NAME_CURRENT_COMP);
    exit (0);
  }

  E_N = create_darr1d (nE);
  E_p = create_darr1d (nE);
  E_p2 = create_darr1d (nE);

  S_p = S_pE = S_pE2 = 0;

  // Use instance name for monitor output if no input was given
  if (!strcmp (filename, "\0"))
    sprintf (filename, "%s", NAME_CURRENT_COMP);
  #undef nE
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef nowritefile
  #undef xwidth
  #undef yheight
  #undef Emin
  #undef Emax
  #undef restore_neutron
  #undef E_N
  #undef E_p
  #undef E_p2
  #undef S_p
  #undef S_pE
  #undef S_pE2
  return(_comp);
} /* class_E_monitor_init */

_class_Isotropic_Sqw *class_Isotropic_Sqw_init(_class_Isotropic_Sqw *_comp
) {
  #define powder_format (_comp->_parameters.powder_format)
  #define Sqw_coh (_comp->_parameters.Sqw_coh)
  #define Sqw_inc (_comp->_parameters.Sqw_inc)
  #define geometry (_comp->_parameters.geometry)
  #define radius (_comp->_parameters.radius)
  #define thickness (_comp->_parameters.thickness)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define threshold (_comp->_parameters.threshold)
  #define order (_comp->_parameters.order)
  #define T (_comp->_parameters.T)
  #define verbose (_comp->_parameters.verbose)
  #define d_phi (_comp->_parameters.d_phi)
  #define concentric (_comp->_parameters.concentric)
  #define rho (_comp->_parameters.rho)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_coh (_comp->_parameters.sigma_coh)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define classical (_comp->_parameters.classical)
  #define powder_Dd (_comp->_parameters.powder_Dd)
  #define powder_DW (_comp->_parameters.powder_DW)
  #define powder_Vc (_comp->_parameters.powder_Vc)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define p_interact (_comp->_parameters.p_interact)
  #define norm (_comp->_parameters.norm)
  #define powder_barns (_comp->_parameters.powder_barns)
  #define quantum_correction (_comp->_parameters.quantum_correction)
  #define VarSqw (_comp->_parameters.VarSqw)
  #define columns (_comp->_parameters.columns)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_iso_samp_init] component iso_samp=Isotropic_Sqw() INITIALISE [Isotropic_Sqw:0]");

  int i;
  /* check for parameters */
  columns = (int*)powder_format;

  VarSqw.verbose_output = verbose;
  VarSqw.shape = -1; /* -1:no shape, 0:cyl, 1:box, 2:sphere, 3:any-shape  */
  if (geometry && strlen (geometry) && strcmp (geometry, "NULL") && strcmp (geometry, "0")) {
    #ifndef USE_OFF
    fprintf (stderr, "Error: You are attempting to use an OFF geometry without -DUSE_OFF. You will need to recompile with that define set!\n");
    exit (-1);
    #else
    if (off_init (geometry, xwidth, yheight, zdepth, 0, &offdata)) {
      VarSqw.shape = 3;
      thickness = 0;
      concentric = 0;
    }
    #endif
  } else if (xwidth && yheight && zdepth)
    VarSqw.shape = 1; /* box */
  else if (radius > 0 && yheight)
    VarSqw.shape = 0; /* cylinder */
  else if (radius > 0 && !yheight)
    VarSqw.shape = 2; /* sphere */

  if (VarSqw.shape < 0)
    exit (fprintf (stderr,
                   "Isotropic_Sqw: %s: sample has invalid dimensions.\n"
                   "ERROR          Please check parameter values (xwidth, yheight, zdepth, radius).\n",
                   NAME_CURRENT_COMP));

  if (thickness) {
    if (radius && (radius < fabs (thickness))) {
      MPI_MASTER (fprintf (stderr,
                           "Isotropic_Sqw: %s: hollow sample thickness is larger than its volume (sphere/cylinder).\n"
                           "WARNING        Please check parameter values. Using bulk sample (thickness=0).\n",
                           NAME_CURRENT_COMP););
      thickness = 0;
    } else if (!radius && (xwidth < 2 * fabs (thickness) || yheight < 2 * fabs (thickness) || zdepth < 2 * fabs (thickness))) {
      MPI_MASTER (fprintf (stderr,
                           "Isotropic_Sqw: %s: hollow sample thickness is larger than its volume (box).\n"
                           "WARNING        Please check parameter values.\n",
                           NAME_CURRENT_COMP););
    }
  }
  MPI_MASTER (if (VarSqw.verbose_output) {
    switch (VarSqw.shape) {
    case 0:
      printf ("Isotropic_Sqw: %s: is a %scylinder: radius=%f thickness=%f height=%f [J Comp Phys 228 (2009) 5251]\n", NAME_CURRENT_COMP,
              (thickness ? "hollow " : ""), radius, fabs (thickness), yheight);
      break;
    case 1:
      printf ("Isotropic_Sqw: %s: is a %sbox: width=%f height=%f depth=%f \n", NAME_CURRENT_COMP, (thickness ? "hollow " : ""), xwidth, yheight, zdepth);
      break;
    case 2:
      printf ("Isotropic_Sqw: %s: is a %ssphere: radius=%f thickness=%f\n", NAME_CURRENT_COMP, (thickness ? "hollow " : ""), radius, fabs (thickness));
      break;
    case 3:
      printf ("Isotropic_Sqw: %s: is a volume defined from file %s\n", NAME_CURRENT_COMP, geometry);
    }
  });

  if (concentric && !thickness) {
    MPI_MASTER (printf ("Isotropic_Sqw: %s:Can not use concentric mode\n"
                        "WARNING        on non hollow shape. Ignoring.\n",
                        NAME_CURRENT_COMP););
    concentric = 0;
  }

  strncpy (VarSqw.compname, NAME_CURRENT_COMP, 256);
  VarSqw.T2E = (1 / 11.605); /* Kelvin to meV = 1000*KB/e */
  VarSqw.sqSE2K = (V2K * SE2V) * (V2K * SE2V);
  VarSqw.sqw_threshold = (threshold > 0 ? threshold : 0);
  VarSqw.s_abs = sigma_abs;
  VarSqw.s_coh = sigma_coh;
  VarSqw.s_inc = sigma_inc; /* s_scatt member initialized in Sqw_init */
  VarSqw.maxloop = 100;     /* atempts to close triangle */
  VarSqw.minevents = 100;   /* minimal # of events required to get dynamical range */
  VarSqw.neutron_removed = 0;
  VarSqw.neutron_enter = 0;
  VarSqw.neutron_pmult = 0;
  VarSqw.neutron_exit = 0;
  VarSqw.mat_rho = rho;
  VarSqw.sqw_norm = norm;
  VarSqw.mean_scatt = 0;
  VarSqw.mean_abs = 0;
  VarSqw.psum_scatt = 0;
  VarSqw.single_coh = 0;
  VarSqw.single_inc = 0;
  VarSqw.multi = 0;
  VarSqw.barns = powder_barns;
  VarSqw.sqw_classical = classical;
  VarSqw.lookup_length = 100;
  VarSqw.mat_weight = weight;
  VarSqw.mat_density = density;
  if (quantum_correction && strlen (quantum_correction))
    strncpy (VarSqw.Q_correction, quantum_correction, 256);
  else
    strncpy (VarSqw.Q_correction, "default", 256);

  /* PowderN compatibility members */
  VarSqw.Dd = powder_Dd;
  VarSqw.DWfactor = powder_DW;
  VarSqw.Temperature = T;
  for (i = 0; i < 9; i++)
    VarSqw.column_order[i] = columns[i];
  VarSqw.column_order[8] = (VarSqw.column_order[0] >= 0 ? 0 : 2);

  /* optional ways to define rho */
  if (!VarSqw.mat_rho && powder_Vc > 0)
    VarSqw.mat_rho = 1 / powder_Vc;
  /* import the data files ================================================== */
  if (!Sqw_init (&VarSqw, Sqw_coh, Sqw_inc)) {
    MPI_MASTER (printf ("Isotropic_Sqw: %s: ERROR importing data files (Sqw_init coh=%s inc=%s).\n", NAME_CURRENT_COMP, Sqw_coh, Sqw_inc););
  }
  if (VarSqw.s_coh < 0)
    VarSqw.s_coh = 0;
  if (VarSqw.s_inc < 0)
    VarSqw.s_inc = 0;
  if (VarSqw.s_abs < 0)
    VarSqw.s_abs = 0;
  if ((VarSqw.s_coh > 0 || VarSqw.s_inc > 0) && VarSqw.mat_rho <= 0) {
    MPI_MASTER (printf ("Isotropic_Sqw: %s: WARNING: Null density (V_rho). Unactivating component.\n", NAME_CURRENT_COMP););
    VarSqw.s_coh = VarSqw.s_inc = 0;
  }
  /* 100: convert from barns to fm^2 */
  VarSqw.my_a_v = (VarSqw.mat_rho * 100 * VarSqw.s_abs * 2200);
  VarSqw.my_s = (VarSqw.mat_rho * 100 * (VarSqw.s_coh > 0 ? VarSqw.s_coh : 0 + VarSqw.s_inc > 0 ? VarSqw.s_inc : 0));
  MPI_MASTER (if ((VarSqw.s_coh > 0 || VarSqw.s_inc > 0) && !VarSqw.Temperature && (VarSqw.Data_coh.intensity || VarSqw.Data_inc.intensity)
                  && VarSqw.verbose_output) printf ("Isotropic_Sqw: %s: Sample temperature not defined (T=0).\n"
                                                    "Warning        Disabling detailed balance.\n",
                                                    NAME_CURRENT_COMP);
              if (VarSqw.s_coh <= 0 && VarSqw.s_inc <= 0) {
                printf ("Isotropic_Sqw: %s: Scattering cross section is zero\n"
                        "ERROR          (sigma_coh, sigma_inc).\n",
                        NAME_CURRENT_COMP);
              });
  if (d_phi)
    d_phi = fabs (d_phi) * DEG2RAD;

  if (d_phi > PI)
    d_phi = 0; /* V_scatt on 4*PI */

  if (d_phi && order != 1) {
    MPI_MASTER (printf ("Isotropic_Sqw: %s: Focusing can only apply for single\n"
                        "               scattering. Setting to order=1.\n",
                        NAME_CURRENT_COMP););
    order = 1;
  }

  /* request statistics */
  if (VarSqw.verbose_output > 1) {
    Sqw_diagnosis (&VarSqw, &VarSqw.Data_coh);
    Sqw_diagnosis (&VarSqw, &VarSqw.Data_inc);
  }

  for (i = 0; i < 2; i++) {
    struct Sqw_Data_struct Data_sqw;
    Data_sqw = (i == 0 ? VarSqw.Data_coh : VarSqw.Data_inc);
    Table_Free (&(Data_sqw.Sqw));
  }

  /* end INITIALIZE */
  #undef powder_format
  #undef Sqw_coh
  #undef Sqw_inc
  #undef geometry
  #undef radius
  #undef thickness
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef threshold
  #undef order
  #undef T
  #undef verbose
  #undef d_phi
  #undef concentric
  #undef rho
  #undef sigma_abs
  #undef sigma_coh
  #undef sigma_inc
  #undef classical
  #undef powder_Dd
  #undef powder_DW
  #undef powder_Vc
  #undef density
  #undef weight
  #undef p_interact
  #undef norm
  #undef powder_barns
  #undef quantum_correction
  #undef VarSqw
  #undef columns
  #undef offdata
  return(_comp);
} /* class_Isotropic_Sqw_init */

_class_Monitor_nD *class_Monitor_nD_init(_class_Monitor_nD *_comp
) {
  #define user1 (_comp->_parameters.user1)
  #define user2 (_comp->_parameters.user2)
  #define user3 (_comp->_parameters.user3)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define zmin (_comp->_parameters.zmin)
  #define zmax (_comp->_parameters.zmax)
  #define bins (_comp->_parameters.bins)
  #define min (_comp->_parameters.min)
  #define max (_comp->_parameters.max)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define radius (_comp->_parameters.radius)
  #define options (_comp->_parameters.options)
  #define filename (_comp->_parameters.filename)
  #define geometry (_comp->_parameters.geometry)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define nexus_bins (_comp->_parameters.nexus_bins)
  #define username1 (_comp->_parameters.username1)
  #define username2 (_comp->_parameters.username2)
  #define username3 (_comp->_parameters.username3)
  #define DEFS (_comp->_parameters.DEFS)
  #define Vars (_comp->_parameters.Vars)
  #define detector (_comp->_parameters.detector)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_Banana_1_init] component Banana_1=Monitor_nD() INITIALISE [Monitor_nD:0]");

  char tmp[CHAR_BUF_LENGTH];
  strcpy (Vars.compcurname, NAME_CURRENT_COMP);
  Vars.compcurindex = INDEX_CURRENT_COMP;
  if (options != NULL)
    strncpy (Vars.option, options, CHAR_BUF_LENGTH);
  else {
    strcpy (Vars.option, "x y");
    printf ("Monitor_nD: %s has no option specified. Setting to PSD ('x y') monitor.\n", NAME_CURRENT_COMP);
  }
  Vars.compcurpos = POS_A_CURRENT_COMP;

  if (strstr (Vars.option, "source"))
    strcat (Vars.option, " list, x y z vx vy vz t sx sy sz ");

  if (bins) {
    sprintf (tmp, " all bins=%ld ", (long)bins);
    strcat (Vars.option, tmp);
  }
  if (min > -FLT_MAX && max < FLT_MAX) {
    sprintf (tmp, " all limits=[%g %g]", min, max);
    strcat (Vars.option, tmp);
  } else if (min > -FLT_MAX) {
    sprintf (tmp, " all min=%g", min);
    strcat (Vars.option, tmp);
  } else if (max < FLT_MAX) {
    sprintf (tmp, " all max=%g", max);
    strcat (Vars.option, tmp);
  }

  /* transfer, "zero", and check username- and user variable strings to Vars struct*/
  strncpy (Vars.UserName1, username1&& strlen (username1) && strcmp (username1, "0") && strcmp (username1, "NULL") ? username1 : "", 128);
  strncpy (Vars.UserName2, username2&& strlen (username2) && strcmp (username2, "0") && strcmp (username2, "NULL") ? username2 : "", 128);
  strncpy (Vars.UserName3, username3&& strlen (username3) && strcmp (username3, "0") && strcmp (username3, "NULL") ? username3 : "", 128);
  if (user1 && strlen (user1) && strcmp (user1, "0") && strcmp (user1, "NULL")) {
    strncpy (Vars.UserVariable1, user1, 128);
    int fail;
    _class_particle testparticle;
    particle_getvar (&testparticle, Vars.UserVariable1, &fail);
    if (fail) {
      fprintf (stderr, "Warning (%s): user1=%s is unknown. The signal will not be resolved - this is likely not what you intended.\n", NAME_CURRENT_COMP, user1);
    }
  }
  if (user2 && strlen (user2) && strcmp (user2, "0") && strcmp (user2, "NULL")) {
    strncpy (Vars.UserVariable2, user2, 128);
    int fail;
    _class_particle testparticle;
    particle_getvar (&testparticle, Vars.UserVariable2, &fail);
    if (fail) {
      fprintf (stderr, "Warning (%s): user2=%s is unknown. The signal will not be resolved - this is likely not what you intended.\n", NAME_CURRENT_COMP, user2);
    }
  }
  if (user3 && strlen (user3) && strcmp (user3, "0") && strcmp (user3, "NULL")) {
    strncpy (Vars.UserVariable3, user3, 128);
    int fail;
    _class_particle testparticle;
    particle_getvar (&testparticle, Vars.UserVariable3, &fail);
    if (fail) {
      fprintf (stderr, "Warning (%s): user3=%s is unknown. The signal will not be resolved - this is likely not what you intended.\n", NAME_CURRENT_COMP, user3);
    }
  }

  /*sanitize parameters set for curved shapes*/
  if (strstr (Vars.option, "cylinder") || strstr (Vars.option, "banana") || strstr (Vars.option, "sphere")) {
    /*this _is_ an explicit curved shape. Should have a radius. Inherit from xwidth or zdepth (diameters), x has precedence.*/
    if (!radius) {
      if (xwidth) {
        radius = xwidth / 2.0;
      } else {
        radius = zdepth / 2.0;
      }
    } else {
      xwidth = 2 * radius;
    }
    if (!yheight) {
      /*if not set - use the diameter as height for the curved object. This will likely only happen for spheres*/
      yheight = 2 * radius;
    }
  } else if (radius) {
    /*radius is set - this must be a curved shape. Infer shape from yheight, and set remaining values
     (xwidth etc. They are used inside monitor_nd-lib.*/
    xwidth = zdepth = 2 * radius;
    if (yheight) {
      /*a height is given (and no shape explitly set - assume cylinder*/
      strcat (Vars.option, " banana");
    } else {
      strcat (Vars.option, " sphere");
      yheight = 2 * radius;
    }
  }

  int offflag = 0;
  if (geometry && strlen (geometry) && strcmp (geometry, "0") && strcmp (geometry, "NULL")) {
    #ifndef USE_OFF
    fprintf (stderr, "Error: You are attempting to use an OFF geometry without -DUSE_OFF. You will need to recompile with that define set!\n");
    exit (-1);
    #else
    if (!off_init (geometry, xwidth, yheight, zdepth, 1, &offdata)) {
      printf ("Monitor_nD: %s could not initiate the OFF geometry %s. \n"
              "            Defaulting to normal Monitor dimensions.\n",
              NAME_CURRENT_COMP, geometry);
      strcpy (geometry, "");
    } else {
      offflag = 1;
    }
    #endif
  }

  if (!radius && !xwidth && !yheight && !zdepth && !xmin && !xmax && !ymin && !ymax && !strstr (Vars.option, "previous") && (!geometry || !strlen (geometry)))
    exit (printf ("Monitor_nD: %s has no dimension specified. Aborting (radius, xwidth, yheight, zdepth, previous, geometry).\n", NAME_CURRENT_COMP));

  Monitor_nD_Init (&DEFS, &Vars, xwidth, yheight, zdepth, xmin, xmax, ymin, ymax, zmin, zmax, offflag, nexus_bins);

  if (Vars.Flag_OFF) {
    offdata.mantidflag = Vars.Flag_mantid;
    offdata.mantidoffset = Vars.Coord_Min[Vars.Coord_Number - 1];
  }

  if (filename && strlen (filename) && strcmp (filename, "NULL") && strcmp (filename, "0"))
    strncpy (Vars.Mon_File, filename, 128);

  /* check if user given filename with ext will be used more than once */
  if (((Vars.Flag_Multiple && Vars.Coord_Number > 1) || Vars.Flag_List) && strchr (Vars.Mon_File, '.')) {
    char* XY;
    XY = strrchr (Vars.Mon_File, '.');
    *XY = '_';
  }

  if (restore_neutron)
    Vars.Flag_parallel = 1;
  detector.m = 0;

  #ifdef USE_MPI
  MPI_MASTER (if (strstr (Vars.option, "auto") && mpi_node_count > 1)
                  printf ("Monitor_nD: %s is using automatic limits option 'auto' together with MPI.\n"
                          "WARNING     this may create incorrect distributions (but integrated flux will be right).\n",
                          NAME_CURRENT_COMP););
  #else
  #ifdef OPENACC
  if (strstr (Vars.option, "auto"))
    printf ("Monitor_nD: %s is requesting automatic limits option 'auto' together with OpenACC.\n"
            "WARNING     this feature is NOT supported using OpenACC and has been disabled!\n",
            NAME_CURRENT_COMP);
  #endif
  #endif
  #undef user1
  #undef user2
  #undef user3
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef zmin
  #undef zmax
  #undef bins
  #undef min
  #undef max
  #undef restore_neutron
  #undef radius
  #undef options
  #undef filename
  #undef geometry
  #undef nowritefile
  #undef nexus_bins
  #undef username1
  #undef username2
  #undef username3
  #undef DEFS
  #undef Vars
  #undef detector
  #undef offdata
  return(_comp);
} /* class_Monitor_nD_init */



int init(void) { /* called by mccode_main for ISIS_LET_generated:INITIALISE */
  DEBUG_INSTR();
  // Initialise rng
  srandom(_hash(mcseed-1));

  /* code_main/parseoptions/readparams sets instrument parameters value */
  stracpy(instrument->_name, "ISIS_LET_generated", 256);

  /* Instrument 'ISIS_LET_generated' INITIALISE */
  SIG_MESSAGE("[ISIS_LET_generated] INITIALISE [(null):-1]");
  #define Ei (instrument->_parameters.Ei)
  #define dE (instrument->_parameters.dE)
  #define Ch3_speed (instrument->_parameters.Ch3_speed)
  #define Ch5_speed (instrument->_parameters.Ch5_speed)
  #define Ch2_phase (instrument->_parameters.Ch2_phase)
  #define pha_offset (instrument->_parameters.pha_offset)
  #define res (instrument->_parameters.res)
  #define snout (instrument->_parameters.snout)
  #define monitors_on (instrument->_parameters.monitors_on)
  #define movable_monitors (instrument->_parameters.movable_monitors)
  #define sample_coh (instrument->_parameters.sample_coh)
  #define sample_inc (instrument->_parameters.sample_inc)
{
// Start of initialize for generated ISIS_LET_generated


// get chopper5 slit width and speeds from resolution setting
if (strcmp(res,"HR") == 0){
	Ch5_slit = 0.015;
	Ch1_speed = Ch5_speed / 2;
} else if (strcmp(res,"I") == 0){
	Ch5_slit = 0.02;
	Ch1_speed = Ch5_speed / 4;
} else if (strcmp(res,"HF") == 0){
	Ch5_slit = 0.028;
	Ch1_speed = Ch5_speed / 4;
} else {
	printf("\n Need valid resolution option, 'HR', 'I' or 'HF'\n");
}

// decide whether snout is in or out
if (strcmp(snout,"out") == 0){
	snout_length = 0.0;
} else {
	snout_length = 0.23;
}

SE2K	= SE2V * V2K;
v_foc	= SE2V * sqrt(Ei);
emax	= Ei*dE;
emin	= Ei/dE;
lam_min   	= 2 * PI / SE2K / sqrt(emax);
lam_max 	= 2 * PI / SE2K / sqrt(emin);

printf("\nv_foc: %f", v_foc);
printf("\nChopper 1 delay: %f\n", (L_Ch1 - Ch1_5_halfgap)/v_foc+pha_offset);
printf("\nEnergy range: Emin = %f, Emax = %f\n", emin, emax);
    
}
  #undef Ei
  #undef dE
  #undef Ch3_speed
  #undef Ch5_speed
  #undef Ch2_phase
  #undef pha_offset
  #undef res
  #undef snout
  #undef monitors_on
  #undef movable_monitors
  #undef sample_coh
  #undef sample_inc
  _Origin_setpos(); /* type Arm */
  _SourceMantid_setpos(); /* type Commodus_I3 */
  _shutter_setpos(); /* type Guide_channeled */
  _insert_setpos(); /* type Guide_channeled */
  _after_insert_setpos(); /* type Guide_channeled */
  _Monitor1_setpos(); /* type TOF_monitor */
  _LET_Chopper1_disk1_setpos(); /* type DiskChopper */
  _LET_Chopper1_disk2_setpos(); /* type DiskChopper */
  _Monitor2_setpos(); /* type TOF_monitor */
  _between_chop1_and_chop2_setpos(); /* type Guide_channeled */
  _LET_Chopper2_setpos(); /* type DiskChopper */
  _Monitor3_setpos(); /* type TOF_monitor */
  _between_chop2_and_chop3_setpos(); /* type Guide_channeled */
  _LET_Chopper3_setpos(); /* type DiskChopper */
  _Monitor4_setpos(); /* type TOF_monitor */
  _between_chop3_and_chop4_setpos(); /* type Guide_channeled */
  _LET_Chopper4_setpos(); /* type DiskChopper */
  _Monitor5_setpos(); /* type TOF_monitor */
  _between_chop4_and_movable_setpos(); /* type Guide_channeled */
  _moveable_front_PSDmon_setpos(); /* type PSD_monitor */
  _moveable_front_Divmon_setpos(); /* type Divergence_monitor */
  _moveable_guide_setpos(); /* type Guide_channeled */
  _moveable_back_PSDmon_setpos(); /* type PSD_monitor */
  _moveable_back_Divmon_setpos(); /* type Divergence_monitor */
  _funnel_setpos(); /* type Guide_channeled */
  _LET_Chopper5_Disk1_setpos(); /* type DiskChopper */
  _LET_Chopper5_Disk2_setpos(); /* type DiskChopper */
  _Monitor6_setpos(); /* type TOF_monitor */
  _tanksection_setpos(); /* type Guide_channeled */
  _snout_setpos(); /* type Guide_channeled */
  _sample_setpos(); /* type Arm */
  _sample_PSDmon_setpos(); /* type PSD_monitor */
  _sample_Divmon_setpos(); /* type Divergence_monitor */
  _sample_tof_setpos(); /* type TOF_monitor */
  _sample_Emon_setpos(); /* type E_monitor */
  _iso_samp_setpos(); /* type Isotropic_Sqw */
  _detectorArm_setpos(); /* type Arm */
  _Banana_1_setpos(); /* type Monitor_nD */

  /* call iteratively all components INITIALISE */

  class_Commodus_I3_init(&_SourceMantid_var);

  class_Guide_channeled_init(&_shutter_var);

  class_Guide_channeled_init(&_insert_var);

  class_Guide_channeled_init(&_after_insert_var);

  class_TOF_monitor_init(&_Monitor1_var);

  class_DiskChopper_init(&_LET_Chopper1_disk1_var);

  class_DiskChopper_init(&_LET_Chopper1_disk2_var);

  class_TOF_monitor_init(&_Monitor2_var);

  class_Guide_channeled_init(&_between_chop1_and_chop2_var);

  class_DiskChopper_init(&_LET_Chopper2_var);

  class_TOF_monitor_init(&_Monitor3_var);

  class_Guide_channeled_init(&_between_chop2_and_chop3_var);

  class_DiskChopper_init(&_LET_Chopper3_var);

  class_TOF_monitor_init(&_Monitor4_var);

  class_Guide_channeled_init(&_between_chop3_and_chop4_var);

  class_DiskChopper_init(&_LET_Chopper4_var);

  class_TOF_monitor_init(&_Monitor5_var);

  class_Guide_channeled_init(&_between_chop4_and_movable_var);

  class_PSD_monitor_init(&_moveable_front_PSDmon_var);

  class_Divergence_monitor_init(&_moveable_front_Divmon_var);

  class_Guide_channeled_init(&_moveable_guide_var);

  class_PSD_monitor_init(&_moveable_back_PSDmon_var);

  class_Divergence_monitor_init(&_moveable_back_Divmon_var);

  class_Guide_channeled_init(&_funnel_var);

  class_DiskChopper_init(&_LET_Chopper5_Disk1_var);

  class_DiskChopper_init(&_LET_Chopper5_Disk2_var);

  class_TOF_monitor_init(&_Monitor6_var);

  class_Guide_channeled_init(&_tanksection_var);

  class_Guide_channeled_init(&_snout_var);


  class_PSD_monitor_init(&_sample_PSDmon_var);

  class_Divergence_monitor_init(&_sample_Divmon_var);

  class_TOF_monitor_init(&_sample_tof_var);

  class_E_monitor_init(&_sample_Emon_var);

  class_Isotropic_Sqw_init(&_iso_samp_var);


  class_Monitor_nD_init(&_Banana_1_var);

  if (mcdotrace) display();
  DEBUG_INSTR_END();

#ifdef OPENACC
#include <openacc.h>
#pragma acc update device(_Origin_var)
#pragma acc update device(_SourceMantid_var)
#pragma acc update device(_shutter_var)
#pragma acc update device(_insert_var)
#pragma acc update device(_after_insert_var)
#pragma acc update device(_Monitor1_var)
#pragma acc update device(_LET_Chopper1_disk1_var)
#pragma acc update device(_LET_Chopper1_disk2_var)
#pragma acc update device(_Monitor2_var)
#pragma acc update device(_between_chop1_and_chop2_var)
#pragma acc update device(_LET_Chopper2_var)
#pragma acc update device(_Monitor3_var)
#pragma acc update device(_between_chop2_and_chop3_var)
#pragma acc update device(_LET_Chopper3_var)
#pragma acc update device(_Monitor4_var)
#pragma acc update device(_between_chop3_and_chop4_var)
#pragma acc update device(_LET_Chopper4_var)
#pragma acc update device(_Monitor5_var)
#pragma acc update device(_between_chop4_and_movable_var)
#pragma acc update device(_moveable_front_PSDmon_var)
#pragma acc update device(_moveable_front_Divmon_var)
#pragma acc update device(_moveable_guide_var)
#pragma acc update device(_moveable_back_PSDmon_var)
#pragma acc update device(_moveable_back_Divmon_var)
#pragma acc update device(_funnel_var)
#pragma acc update device(_LET_Chopper5_Disk1_var)
#pragma acc update device(_LET_Chopper5_Disk2_var)
#pragma acc update device(_Monitor6_var)
#pragma acc update device(_tanksection_var)
#pragma acc update device(_snout_var)
#pragma acc update device(_sample_var)
#pragma acc update device(_sample_PSDmon_var)
#pragma acc update device(_sample_Divmon_var)
#pragma acc update device(_sample_tof_var)
#pragma acc update device(_sample_Emon_var)
#pragma acc update device(_iso_samp_var)
#pragma acc update device(_detectorArm_var)
#pragma acc update device(_Banana_1_var)
#pragma acc update device(_instrument_var)
#endif

  return(0);
} /* init */

/*******************************************************************************
* components TRACE
*******************************************************************************/

#define x (_particle->x)
#define y (_particle->y)
#define z (_particle->z)
#define vx (_particle->vx)
#define vy (_particle->vy)
#define vz (_particle->vz)
#define t (_particle->t)
#define sx (_particle->sx)
#define sy (_particle->sy)
#define sz (_particle->sz)
#define p (_particle->p)
#define mcgravitation (_particle->mcgravitation)
#define mcMagnet (_particle->mcMagnet)
#define allow_backprop (_particle->allow_backprop)
#define _mctmp_a (_particle->_mctmp_a)
#define _mctmp_b (_particle->_mctmp_b)
#define _mctmp_c (_particle->_mctmp_c)
/* if on GPU, globally nullify sprintf,fprintf,printfs   */
/* (Similar defines are available in each comp trace but */
/*  those are not enough to handle external libs etc. )  */
#ifdef OPENACC
#define fprintf(stderr,...) printf(__VA_ARGS__)
#define sprintf(string,...) printf(__VA_ARGS__)
#define exit(...) noprintf()
#define strcmp(a,b) str_comp(a,b)
#define strlen(a) str_len(a)
#endif
#define SCATTERED (_particle->_scattered)
#define RESTORE (_particle->_restore)
#define RESTORE_NEUTRON(_index, ...) _particle->_restore = _index;
#define ABSORB0 do { DEBUG_STATE(); DEBUG_ABSORB(); MAGNET_OFF; ABSORBED++; return; } while(0)
#define ABSORBED (_particle->_absorbed)
#define mcget_run_num() _particle->_uid
#define ABSORB ABSORB0
#pragma acc routine
void class_Commodus_I3_trace(_class_Commodus_I3 *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define Face (_comp->_parameters.Face)
  #define E0 (_comp->_parameters.E0)
  #define E1 (_comp->_parameters.E1)
  #define modPosition (_comp->_parameters.modPosition)
  #define dist (_comp->_parameters.dist)
  #define verbose (_comp->_parameters.verbose)
  #define beamcurrent (_comp->_parameters.beamcurrent)
  #define modXsize (_comp->_parameters.modXsize)
  #define modZsize (_comp->_parameters.modZsize)
  #define xw (_comp->_parameters.xw)
  #define yh (_comp->_parameters.yh)
  #define p_in (_comp->_parameters.p_in)
  #define Tnpts (_comp->_parameters.Tnpts)
  #define scaleSize (_comp->_parameters.scaleSize)
  #define angleArea (_comp->_parameters.angleArea)
  #define Nsim (_comp->_parameters.Nsim)
  #define Ncount (_comp->_parameters.Ncount)
  #define TS (_comp->_parameters.TS)
  #define fullAngle (_comp->_parameters.fullAngle)
  #define rtE0 (_comp->_parameters.rtE0)
  #define rtE1 (_comp->_parameters.rtE1)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  SIG_MESSAGE("[_SourceMantid_trace] component SourceMantid=Commodus_I3() TRACE [Commodus_I3:0]");

  double v, r, E;
  double xf, yf, dx, dy; /* mxp ->max var in param space */
  double Ival, Tval, Eval;

  Ncount++;

  x = TS.XAxis * (0.5 - rand01 ()); /* Get point on shutter enterance */
  y = TS.ZAxis * (0.5 - rand01 ()); /* Get point on shutter enterance */

  xf = focus_xw * (0.5 - rand01 ()); /* Choose focusing position uniformly */
  yf = focus_yh * (0.5 - rand01 ()); /* Choose focusing position uniformly */

  getPoint (&Tval, &Eval, &rtE0, &rtE1, TS, _particle);

  Ival = TS.Total * 6.2415093e+12; // Number of proton in 1uAmp

  dx = xf - x;
  dy = yf - y;
  r = sqrt (dx * dx + dy * dy + dist * dist); // Actual distance to point
  v = SE2V * sqrt (Eval);                     // Calculate the velocity
  vz = v * fabs (dist) / r;
  vy = v * dy / r;
  vx = v * dx / r;

  t = Tval - (TS.rdumMid - TS.timeOffset) / vz;

  if (modPosition) {
    t += TS.rdumMid / vz;
  }

  p = beamcurrent * angleArea * Ival / Nsim;

  #ifndef OPENACC
  if (verbose && !(Ncount % 100000)) {
    fprintf (stderr, "FPos[%d]=> %g %g %g  \n", Ncount, x, y, z);
    fprintf (stderr, "FDir[%d]=> %g %g %g  \n", Ncount, vx, vy, vz);
    fprintf (stderr, "PlaneAxis %g %g \n", TS.XAxis, fullAngle);
    fprintf (stderr, "RMID %g \n", TS.rdumMid);
    fprintf (stderr, "TimeMid[%d]=> %g\n", Ncount, TS.rdumMid);
    fprintf (stderr, "TimeOffset[%d]=> %g\n", Ncount, TS.timeOffset);
    fprintf (stderr, "TimeTval[%d]=> %g\n", Ncount, Tval);
    fprintf (stderr, "TimeZero[%d]=> %g\n", Ncount, t);
  }
  #endif
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef Face
  #undef E0
  #undef E1
  #undef modPosition
  #undef dist
  #undef verbose
  #undef beamcurrent
  #undef modXsize
  #undef modZsize
  #undef xw
  #undef yh
  #undef p_in
  #undef Tnpts
  #undef scaleSize
  #undef angleArea
  #undef Nsim
  #undef Ncount
  #undef TS
  #undef fullAngle
  #undef rtE0
  #undef rtE1
  #undef xwidth
  #undef yheight
  #undef focus_xw
  #undef focus_yh
  return;
} /* class_Commodus_I3_trace */

#pragma acc routine
void class_Guide_channeled_trace(_class_Guide_channeled *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define w1 (_comp->_parameters.w1)
  #define h1 (_comp->_parameters.h1)
  #define w2 (_comp->_parameters.w2)
  #define h2 (_comp->_parameters.h2)
  #define l (_comp->_parameters.l)
  #define R0 (_comp->_parameters.R0)
  #define Qc (_comp->_parameters.Qc)
  #define alpha (_comp->_parameters.alpha)
  #define m (_comp->_parameters.m)
  #define nslit (_comp->_parameters.nslit)
  #define d (_comp->_parameters.d)
  #define Qcx (_comp->_parameters.Qcx)
  #define Qcy (_comp->_parameters.Qcy)
  #define alphax (_comp->_parameters.alphax)
  #define alphay (_comp->_parameters.alphay)
  #define W (_comp->_parameters.W)
  #define mx (_comp->_parameters.mx)
  #define my (_comp->_parameters.my)
  #define nu (_comp->_parameters.nu)
  #define phase (_comp->_parameters.phase)
  #define w1c (_comp->_parameters.w1c)
  #define w2c (_comp->_parameters.w2c)
  #define ww (_comp->_parameters.ww)
  #define hh (_comp->_parameters.hh)
  #define whalf (_comp->_parameters.whalf)
  #define hhalf (_comp->_parameters.hhalf)
  #define lwhalf (_comp->_parameters.lwhalf)
  #define lhhalf (_comp->_parameters.lhhalf)
  SIG_MESSAGE("[_shutter_trace] component shutter=Guide_channeled() TRACE [Guide_channeled:0]");

  double t1, t2;                                 /* Intersection times. */
  double av, ah, bv, bh, cv1, cv2, ch1, ch2, dd; /* Intermediate values */
  double vdotn_v1, vdotn_v2, vdotn_h1, vdotn_h2; /* Dot products. */
  int i;                                         /* Which mirror hit? */
  double q;                                      /* Q [1/AA] of reflection */
  double nlen2;                                  /* Vector lengths squared */
  double edge;
  double hadj; /* Channel displacement */
  double angle = 0;

  if (nu != 0 || phase != 0) { /* rotate neutron w/r to guide element */
    /* approximation of rotating straight Fermi Chopper */
    Coords X = coords_set (x, y, z - l / 2); /* current coordinates of neutron in centered static frame */
    Rotation R;
    double dt = (-z + l / 2) / vz;                   /* time shift to each center of slit package */
    angle = fmod (360 * nu * (t + dt) + phase, 360); /* in deg */
    /* modify angle so that Z0 guide side is always in front of incoming neutron */
    if (angle > 90 && angle < 270) {
      angle -= 180;
    }
    angle *= DEG2RAD;
    rot_set_rotation (R, 0, -angle, 0); /* will rotate neutron instead of comp: negative side */
    /* apply rotation to centered coordinates */
    Coords RX = rot_apply (R, X);
    coords_get (RX, &x, &y, &z);
    z = z + l / 2;
    /* rotate speed */
    X = coords_set (vx, vy, vz);
    RX = rot_apply (R, X);
    coords_get (RX, &vx, &vy, &vz);
  }

  /* Propagate neutron to guide entrance. */
  PROP_Z0;
  /* Scatter here to ensure that fully transmitted neutrons will not be
     absorbed in a GROUP construction, e.g. all neutrons - even the
     later absorbed ones are scattered at the guide entry. */
  SCATTER;
  if (x <= w1 / -2.0 || x >= w1 / 2.0 || y <= -hhalf || y >= hhalf)
    ABSORB;
  /* Shift origin to center of channel hit (absorb if hit dividing walls) */
  x += w1 / 2.0;
  edge = floor (x / w1c) * w1c;
  if (x - edge > w1c - d) {
    x -= w1 / 2.0; /* Re-adjust origin */
    ABSORB;
  }
  x -= (edge + (w1c - d) / 2.0);
  hadj = edge + (w1c - d) / 2.0 - w1 / 2.0;
  for (;;) {
    /* Compute the dot products of v and n for the four mirrors. */
    av = l * vx;
    bv = ww * vz;
    ah = l * vy;
    bh = hh * vz;
    vdotn_v1 = bv + av; /* Left vertical */
    vdotn_v2 = bv - av; /* Right vertical */
    vdotn_h1 = bh + ah; /* Lower horizontal */
    vdotn_h2 = bh - ah; /* Upper horizontal */
    /* Compute the dot products of (O - r) and n as c1+c2 and c1-c2 */
    cv1 = -whalf * l - z * ww;
    cv2 = x * l;
    ch1 = -hhalf * l - z * hh;
    ch2 = y * l;
    /* Compute intersection times. */
    t1 = (l - z) / vz;
    i = 0;
    if (vdotn_v1 < 0 && (t2 = (cv1 - cv2) / vdotn_v1) < t1) {
      t1 = t2;
      i = 1;
    }
    if (vdotn_v2 < 0 && (t2 = (cv1 + cv2) / vdotn_v2) < t1) {
      t1 = t2;
      i = 2;
    }
    if (vdotn_h1 < 0 && (t2 = (ch1 - ch2) / vdotn_h1) < t1) {
      t1 = t2;
      i = 3;
    }
    if (vdotn_h2 < 0 && (t2 = (ch1 + ch2) / vdotn_h2) < t1) {
      t1 = t2;
      i = 4;
    }
    if (i == 0)
      break; /* Neutron left guide. */
    PROP_DT (t1);
    switch (i) {
    case 1: /* Left vertical mirror */
      nlen2 = l * l + ww * ww;
      q = V2Q * (-2) * vdotn_v1 / sqrt (nlen2);
      dd = 2 * vdotn_v1 / nlen2;
      vx = vx - dd * l;
      vz = vz - dd * ww;
      break;
    case 2: /* Right vertical mirror */
      nlen2 = l * l + ww * ww;
      q = V2Q * (-2) * vdotn_v2 / sqrt (nlen2);
      dd = 2 * vdotn_v2 / nlen2;
      vx = vx + dd * l;
      vz = vz - dd * ww;
      break;
    case 3: /* Lower horizontal mirror */
      nlen2 = l * l + hh * hh;
      q = V2Q * (-2) * vdotn_h1 / sqrt (nlen2);
      dd = 2 * vdotn_h1 / nlen2;
      vy = vy - dd * l;
      vz = vz - dd * hh;
      break;
    case 4: /* Upper horizontal mirror */
      nlen2 = l * l + hh * hh;
      q = V2Q * (-2) * vdotn_h2 / sqrt (nlen2);
      dd = 2 * vdotn_h2 / nlen2;
      vy = vy + dd * l;
      vz = vz - dd * hh;
      break;
    }
    /* Now compute reflectivity. */
    if ((i <= 2 && mx == 0) || (i > 2 && my == 0)) {
      x += hadj; /* Re-adjust origin */
      ABSORB;
    } else {
      double ref = 1;
      if (i <= 2) {
        double par[] = { R0, Qcx, alphax, mx, W };
        StdReflecFunc (q, par, &ref);
        if (ref > 0)
          p *= ref;
        else {
          x += hadj; /* Re-adjust origin */
          ABSORB;    /* Cutoff ~ 1E-10 */
        }
      } else {
        double par[] = { R0, Qcy, alphay, my, W };
        StdReflecFunc (q, par, &ref);
        if (ref > 0)
          p *= ref;
        else {
          x += hadj; /* Re-adjust origin */
          ABSORB;    /* Cutoff ~ 1E-10 */
        }
      }
    }
    x += hadj;
    SCATTER;
    x -= hadj;
  } /* end for */
  x += hadj;                   /* Re-adjust origin */
  if (nu != 0 || phase != 0) { /* rotate back neutron w/r to guide element */
    /* approximation of rotating straight Fermi Chopper */
    Coords X = coords_set (x, y, z - l / 2); /* current coordinates of neutron in centered static frame */
    Rotation R;
    rot_set_rotation (R, 0, angle, 0); /* will rotate back neutron: positive side */
    /* apply rotation to centered coordinates */
    Coords RX = rot_apply (R, X);
    coords_get (RX, &x, &y, &z);
    z = z + l / 2;
    /* rotate speed */
    X = coords_set (vx, vy, vz);
    RX = rot_apply (R, X);
    coords_get (RX, &vx, &vy, &vz);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef w1
  #undef h1
  #undef w2
  #undef h2
  #undef l
  #undef R0
  #undef Qc
  #undef alpha
  #undef m
  #undef nslit
  #undef d
  #undef Qcx
  #undef Qcy
  #undef alphax
  #undef alphay
  #undef W
  #undef mx
  #undef my
  #undef nu
  #undef phase
  #undef w1c
  #undef w2c
  #undef ww
  #undef hh
  #undef whalf
  #undef hhalf
  #undef lwhalf
  #undef lhhalf
  return;
} /* class_Guide_channeled_trace */

#pragma acc routine
void class_TOF_monitor_trace(_class_TOF_monitor *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define nt (_comp->_parameters.nt)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define tmin (_comp->_parameters.tmin)
  #define tmax (_comp->_parameters.tmax)
  #define dt (_comp->_parameters.dt)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define TOF_N (_comp->_parameters.TOF_N)
  #define TOF_p (_comp->_parameters.TOF_p)
  #define TOF_p2 (_comp->_parameters.TOF_p2)
  #define t_min (_comp->_parameters.t_min)
  #define t_max (_comp->_parameters.t_max)
  #define delta_t (_comp->_parameters.delta_t)
  SIG_MESSAGE("[_Monitor1_trace] component Monitor1=TOF_monitor() TRACE [TOF_monitor:0]");

  int i;

  PROP_Z0;
  if (x > xmin && x < xmax && y > ymin && y < ymax) {
    i = floor ((1E6 * t - t_min) / delta_t); /* Bin number */
    if (i >= 0 && i < nt) {
      double p2 = p * p;
      #pragma acc atomic
      TOF_N[i] = TOF_N[i] + 1;
      #pragma acc atomic
      TOF_p[i] = TOF_p[i] + p;
      #pragma acc atomic
      TOF_p2[i] = TOF_p2[i] + p2;
      SCATTER;
    }
  }
  if (restore_neutron) {
    RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef nt
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef tmin
  #undef tmax
  #undef dt
  #undef restore_neutron
  #undef nowritefile
  #undef TOF_N
  #undef TOF_p
  #undef TOF_p2
  #undef t_min
  #undef t_max
  #undef delta_t
  return;
} /* class_TOF_monitor_trace */

#pragma acc routine
void class_DiskChopper_trace(_class_DiskChopper *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define theta_0 (_comp->_parameters.theta_0)
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define nu (_comp->_parameters.nu)
  #define nslit (_comp->_parameters.nslit)
  #define jitter (_comp->_parameters.jitter)
  #define delay (_comp->_parameters.delay)
  #define isfirst (_comp->_parameters.isfirst)
  #define n_pulse (_comp->_parameters.n_pulse)
  #define abs_out (_comp->_parameters.abs_out)
  #define phase (_comp->_parameters.phase)
  #define xwidth (_comp->_parameters.xwidth)
  #define verbose (_comp->_parameters.verbose)
  #define Tg (_comp->_parameters.Tg)
  #define To (_comp->_parameters.To)
  #define delta_y (_comp->_parameters.delta_y)
  #define height (_comp->_parameters.height)
  #define omega (_comp->_parameters.omega)
  SIG_MESSAGE("[_LET_Chopper1_disk1_trace] component LET_Chopper1_disk1=DiskChopper() TRACE [DiskChopper:0]");

  double toff;
  double yprime;
  PROP_Z0;
  yprime = y + delta_y;

  /* Is neutron outside the vertical slit range and should we absorb? */
  if (abs_out && (x * x + yprime * yprime) > radius * radius) {
    ABSORB;
  }
  /* Does neutron hit inner solid part of chopper in case of yheight!=radius? */
  if ((x * x + yprime * yprime) < (radius - height) * (radius - height)) {
    ABSORB;
  }

  if (isfirst) {
    /* all events are put in the transmitted time frame */
    t = atan2 (x, yprime) / omega + To * randpm1 () / 2.0 + delay + (jitter ? jitter * randnorm () : 0) + (n_pulse > 1 ? floor (n_pulse * rand01 ()) * Tg : 0);
    /* correction: chopper slits transmission opening/full disk */
    p *= nslit * theta_0 / 2.0 / PI;
  } else {
    toff = fabs (t - atan2 (x, yprime) / omega - delay - (jitter ? jitter * randnorm () : 0));

    /* does neutron hit outside slit? */
    if (fmod (toff + To / 2.0, Tg) > To)
      ABSORB;
  }
  SCATTER;
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef theta_0
  #undef radius
  #undef yheight
  #undef nu
  #undef nslit
  #undef jitter
  #undef delay
  #undef isfirst
  #undef n_pulse
  #undef abs_out
  #undef phase
  #undef xwidth
  #undef verbose
  #undef Tg
  #undef To
  #undef delta_y
  #undef height
  #undef omega
  return;
} /* class_DiskChopper_trace */

#pragma acc routine
void class_PSD_monitor_trace(_class_PSD_monitor *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_moveable_front_PSDmon_trace] component moveable_front_PSDmon=PSD_monitor() TRACE [PSD_monitor:0]");

  PROP_Z0;
  if (x > xmin && x < xmax && y > ymin && y < ymax) {
    int i = floor ((x - xmin) * nx / (xmax - xmin));
    int j = floor ((y - ymin) * ny / (ymax - ymin));

    double p2 = p * p;
    #pragma acc atomic
    PSD_N[i][j] = PSD_N[i][j] + 1;

    #pragma acc atomic
    PSD_p[i][j] = PSD_p[i][j] + p;

    #pragma acc atomic
    PSD_p2[i][j] = PSD_p2[i][j] + p2;

    SCATTER;
  }
  if (restore_neutron) {
    RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef nx
  #undef ny
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef restore_neutron
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return;
} /* class_PSD_monitor_trace */

#pragma acc routine
void class_Divergence_monitor_trace(_class_Divergence_monitor *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define nh (_comp->_parameters.nh)
  #define nv (_comp->_parameters.nv)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define maxdiv_h (_comp->_parameters.maxdiv_h)
  #define maxdiv_v (_comp->_parameters.maxdiv_v)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define nz (_comp->_parameters.nz)
  #define Div_N (_comp->_parameters.Div_N)
  #define Div_p (_comp->_parameters.Div_p)
  #define Div_p2 (_comp->_parameters.Div_p2)
  SIG_MESSAGE("[_moveable_front_Divmon_trace] component moveable_front_Divmon=Divergence_monitor() TRACE [Divergence_monitor:0]");

  int i, j;
  double h_div, v_div;
  double v, vn;

  PROP_Z0;
  if (x > xmin && x < xmax && y > ymin && y < ymax) {
    /* Find length of projection onto the [nx ny nz] axis */
    vn = scalar_prod (vx, vy, vz, nx, ny, nz);
    h_div = RAD2DEG * atan2 (vx, vn);
    v_div = RAD2DEG * atan2 (vy, vn);
    if (h_div < maxdiv_h && h_div > -maxdiv_h && v_div < maxdiv_v && v_div > -maxdiv_v) {
      i = floor ((h_div + maxdiv_h) * nh / (2.0 * maxdiv_h));
      j = floor ((v_div + maxdiv_v) * nv / (2.0 * maxdiv_v));
      double p2 = p * p;
      #pragma acc atomic
      Div_N[i][j] = Div_N[i][j] + 1;
      #pragma acc atomic
      Div_p[i][j] = Div_p[i][j] + p;
      #pragma acc atomic
      Div_p2[i][j] = Div_p2[i][j] + p2;
      SCATTER;
    }
  }
  if (restore_neutron) {
    RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef nh
  #undef nv
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef nowritefile
  #undef xwidth
  #undef yheight
  #undef maxdiv_h
  #undef maxdiv_v
  #undef restore_neutron
  #undef nx
  #undef ny
  #undef nz
  #undef Div_N
  #undef Div_p
  #undef Div_p2
  return;
} /* class_Divergence_monitor_trace */

#pragma acc routine
void class_E_monitor_trace(_class_E_monitor *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define nE (_comp->_parameters.nE)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define Emin (_comp->_parameters.Emin)
  #define Emax (_comp->_parameters.Emax)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define E_N (_comp->_parameters.E_N)
  #define E_p (_comp->_parameters.E_p)
  #define E_p2 (_comp->_parameters.E_p2)
  #define S_p (_comp->_parameters.S_p)
  #define S_pE (_comp->_parameters.S_pE)
  #define S_pE2 (_comp->_parameters.S_pE2)
  SIG_MESSAGE("[_sample_Emon_trace] component sample_Emon=E_monitor() TRACE [E_monitor:0]");

  int i;
  double E;

  PROP_Z0;
  if (x > xmin && x < xmax && y > ymin && y < ymax) {
    E = VS2E * (vx * vx + vy * vy + vz * vz);

    S_p += p;
    S_pE += p * E;
    S_pE2 += p * E * E;

    i = floor ((E - Emin) * nE / (Emax - Emin));
    if (i >= 0 && i < nE) {
      double p2 = p * p;
      #pragma acc atomic
      E_N[i] = E_N[i] + 1;
      #pragma acc atomic
      E_p[i] = E_p[i] + p;
      #pragma acc atomic
      E_p2[i] = E_p2[i] + p2;
      SCATTER;
    }
  }
  if (restore_neutron) {
    RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef nE
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef nowritefile
  #undef xwidth
  #undef yheight
  #undef Emin
  #undef Emax
  #undef restore_neutron
  #undef E_N
  #undef E_p
  #undef E_p2
  #undef S_p
  #undef S_pE
  #undef S_pE2
  return;
} /* class_E_monitor_trace */

#pragma acc routine
void class_Isotropic_Sqw_trace(_class_Isotropic_Sqw *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define powder_format (_comp->_parameters.powder_format)
  #define Sqw_coh (_comp->_parameters.Sqw_coh)
  #define Sqw_inc (_comp->_parameters.Sqw_inc)
  #define geometry (_comp->_parameters.geometry)
  #define radius (_comp->_parameters.radius)
  #define thickness (_comp->_parameters.thickness)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define threshold (_comp->_parameters.threshold)
  #define order (_comp->_parameters.order)
  #define T (_comp->_parameters.T)
  #define verbose (_comp->_parameters.verbose)
  #define d_phi (_comp->_parameters.d_phi)
  #define concentric (_comp->_parameters.concentric)
  #define rho (_comp->_parameters.rho)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_coh (_comp->_parameters.sigma_coh)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define classical (_comp->_parameters.classical)
  #define powder_Dd (_comp->_parameters.powder_Dd)
  #define powder_DW (_comp->_parameters.powder_DW)
  #define powder_Vc (_comp->_parameters.powder_Vc)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define p_interact (_comp->_parameters.p_interact)
  #define norm (_comp->_parameters.norm)
  #define powder_barns (_comp->_parameters.powder_barns)
  #define quantum_correction (_comp->_parameters.quantum_correction)
  #define VarSqw (_comp->_parameters.VarSqw)
  #define columns (_comp->_parameters.columns)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_iso_samp_trace] component iso_samp=Isotropic_Sqw() TRACE [Isotropic_Sqw:0]");


  int intersect = 0;        /* flag to continue/stop */
  double t0, t1, t2, t3;    /* times for intersections */
  double dt0, dt1, dt2, dt; /* time intervals */
  double k = 0, Ei = 0;
  double v = 0, vf = 0;
  double d_path;                   /* total path length for straight trajectory */
  double my_a;                     /* absorption cross-section scaled to velocity (2200) */
  double ws, p_scatt;              /* probability for scattering/absorption and for */
                                   /* interaction along d_path */
  double tmp_rand;                 /* temporary var */
  double ratio_w = 0, ratio_q = 0; /* variables for bilinear interpolation */
  double q11, q21, q22, q12;
  double omega = 0;               /* energy transfer */
  double q = 0;                   /* wavevector transfer */
  long index_w;                   /* energy index for table look-up SW */
  long index_q;                   /* Q index for table look-up P(Q|w) */
  double theta = 0, costheta = 0; /* for the choice of kf direction */
  double u1x, u1y, u1z;
  double u2x, u2y, u2z;
  double u0x, u0y, u0z;
  int index_counter;
  int flag = 0;
  int flag_concentric = 0;
  int flag_ishollow = 0;
  double solid_angle = 0;
  double my_t = 0;
  double p_mult = 1;
  double mc_trans, p_trans, mc_scatt;
  double coh = 0, inc = 0;
  struct Sqw_Data_struct Data_sqw;
  double d_phi_thread = d_phi;

  char type;

  double ki_x, ki_y, ki_z, ti, vi, ki;
  double kf_x, kf_y, kf_z, tf, kf;

  /* Store Initial neutron state */

  ki_x = V2K * vx;
  ki_y = V2K * vy;
  ki_z = V2K * vz;
  ti = t;
  vi = 0;
  ki = 0;
  type = '\0';

  #ifdef OPENACC
  #ifdef USE_OFF
  off_struct thread_offdata = offdata;
  #endif
  #else
  #define thread_offdata offdata
  #endif

  do { /* Main interaction loop. Ends with intersect=0 */

    /* Intersection neutron trajectory / sample (sample surface) */
    if (VarSqw.s_coh > 0 || VarSqw.s_inc > 0) {
      if (thickness >= 0) {
        if (VarSqw.shape == 0)
          intersect = cylinder_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius, yheight);
        else if (VarSqw.shape == 1)
          intersect = box_intersect (&t0, &t3, x, y, z, vx, vy, vz, xwidth, yheight, zdepth);
        else if (VarSqw.shape == 2)
          intersect = sphere_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius);
        #ifdef USE_OFF
        else if (VarSqw.shape == 3)
          intersect = off_intersect (&t0, &t3, NULL, NULL, x, y, z, vx, vy, vz, 0, 0, 0, thread_offdata);
        #endif
      } else {
        if (VarSqw.shape == 0)
          intersect = cylinder_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius - thickness, yheight - 2 * thickness > 0 ? yheight - 2 * thickness : yheight);
        else if (VarSqw.shape == 1)
          intersect
              = box_intersect (&t0, &t3, x, y, z, vx, vy, vz, xwidth - 2 * thickness > 0 ? xwidth - 2 * thickness : xwidth,
                               yheight - 2 * thickness > 0 ? yheight - 2 * thickness : yheight, zdepth - 2 * thickness > 0 ? zdepth - 2 * thickness : zdepth);
        else if (VarSqw.shape == 2)
          intersect = sphere_intersect (&t0, &t3, x, y, z, vx, vy, vz, radius - thickness);
        #ifdef USE_OFF
        else if (VarSqw.shape == 3)
          intersect = off_intersect (&t0, &t3, NULL, NULL, x, y, z, vx, vy, vz, 0, 0, 0, thread_offdata);
        #endif
      }
    } else
      intersect = 0;

    /* Computing the intermediate times */
    if (intersect) {
      flag_ishollow = 0;
      if (thickness > 0) {
        if (VarSqw.shape == 0
            && cylinder_intersect (&t1, &t2, x, y, z, vx, vy, vz, radius - thickness, yheight - 2 * thickness > 0 ? yheight - 2 * thickness : yheight))
          flag_ishollow = 1;
        else if (VarSqw.shape == 2 && sphere_intersect (&t1, &t2, x, y, z, vx, vy, vz, radius - thickness))
          flag_ishollow = 1;
        else if (VarSqw.shape == 1
                 && box_intersect (&t1, &t2, x, y, z, vx, vy, vz, xwidth - 2 * thickness > 0 ? xwidth - 2 * thickness : xwidth,
                                   yheight - 2 * thickness > 0 ? yheight - 2 * thickness : yheight, zdepth - 2 * thickness > 0 ? zdepth - 2 * thickness : zdepth))
          flag_ishollow = 1;
      } else if (thickness < 0) {
        if (VarSqw.shape == 0 && cylinder_intersect (&t1, &t2, x, y, z, vx, vy, vz, radius, yheight))
          flag_ishollow = 1;
        else if (VarSqw.shape == 2 && sphere_intersect (&t1, &t2, x, y, z, vx, vy, vz, radius))
          flag_ishollow = 1;
        else if (VarSqw.shape == 1 && box_intersect (&t1, &t2, x, y, z, vx, vy, vz, xwidth, yheight, zdepth))
          flag_ishollow = 1;
      }
      if (!flag_ishollow)
        t1 = t2 = t3; /* no empty space inside */
    } else
      break; /* neutron does not hit sample: transmitted  */

    if (intersect) { /* the neutron hits the sample */

      if (t0 > 0) {                   /* we are before the sample */
        PROP_DT (t0);                 /* propagates neutron to the entry of the sample */
      } else if (t1 > 0 && t1 > t0) { /* we are inside first part of the sample */
        /* no propagation, stay inside */
      } else if (t2 > 0 && t2 > t1) { /* we are in the hole */
        PROP_DT (t2);                 /* propagate to inner surface of 2nd part of sample */
      } else if (t3 > 0 && t3 > t2) { /* we are in the 2nd part of sample */
        /* no propagation, stay inside */
      }

      dt0 = t1 - (t0 > 0 ? t0 : 0); /* Time in first part of hollow/cylinder/box */
      dt1 = t2 - (t1 > 0 ? t1 : 0); /* Time in hole */
      dt2 = t3 - (t2 > 0 ? t2 : 0); /* Time in 2nd part of hollow cylinder */

      if (dt0 < 0)
        dt0 = 0;
      if (dt1 < 0)
        dt1 = 0;
      if (dt2 < 0)
        dt2 = 0;

      /* initialize concentric mode */
      if (concentric && !flag_concentric && t0 >= 0 && VarSqw.shape == 0 && thickness) {
        flag_concentric = 1;
      }

      if (flag_concentric == 1) {
        dt1 = dt2 = 0; /* force exit when reaching hole/2nd part */
      }

      if (!dt0 && !dt2) {
        intersect = 0; /* the sample was passed entirely */
        break;
      }

      VarSqw.neutron_enter++;
      p_mult = 1;
      if (!v) {
        v = vx * vx + vy * vy + vz * vz;
        v = sqrt (v);
      }
      k = V2K * v;
      Ei = VS2E * v * v;

      if (!vi)
        vi = v;
      if (!ki)
        ki = k;

      if (v <= 0) {
        printf ("Isotropic_Sqw: %s: ERROR: Null velocity !\n", NAME_CURRENT_COMP);
        VarSqw.neutron_removed++;
        ABSORB; /* should never occur */
      }

      /* check for scattering event */
      my_a = VarSqw.my_a_v / v; /* absorption 'mu' */
      /* compute total scattering X section */
      /* \int q S(q) dq /2 /ki^2 sigma  OR  bare Xsection*/
      /* contains the 4*PI*kf/ki factor */
      coh = VarSqw.s_coh;
      inc = VarSqw.s_inc;
      if (k && VarSqw.s_coh > 0 && VarSqw.Data_coh.intensity) {
        double Ei = VS2E * v * v;
        double index_Ei = Ei / (VarSqw.Data_coh.Ei_max / VarSqw.Data_coh.iqSq_length);
        coh = Table_Value2d (VarSqw.Data_coh.iqSq, index_Ei, 0);
      }
      if (k && VarSqw.s_inc > 0 && VarSqw.Data_inc.intensity) {
        double Ei = VS2E * v * v;
        double index_Ei = Ei / (VarSqw.Data_inc.Ei_max / VarSqw.Data_inc.iqSq_length);
        inc = Table_Value2d (VarSqw.Data_inc.iqSq, index_Ei, 0);
      }
      if (coh < 0)
        coh = 0;
      if (inc < 0)
        inc = 0;
      VarSqw.my_s = (VarSqw.mat_rho * 100 * (coh + inc));

      my_t = my_a + VarSqw.my_s; /* total scattering Xsect */
      if (my_t <= 0) {
        if (VarSqw.neutron_removed < VarSqw.maxloop)
          printf ("Isotropic_Sqw: %s: ERROR: Null total cross section %g. Removing event.\n", NAME_CURRENT_COMP, my_t);
        VarSqw.neutron_removed++;
        ABSORB; /* should never occur */
      } else if (VarSqw.my_s <= 0) {
        if (VarSqw.verbose_output > 1 && VarSqw.neutron_removed < VarSqw.maxloop)
          printf ("Isotropic_Sqw: %s: Warning: Null scattering cross section %g. Ignoring.\n", NAME_CURRENT_COMP, VarSqw.my_s);
        VarSqw.my_s = 0;
      }

      /* Proba of scattering vs absorption (integrating along the whole trajectory) */
      ws = VarSqw.my_s / my_t;  /* (inc+coh)/(inc+coh+abs) */
      d_path = v * (dt0 + dt2); /* total path lenght in sample */
      /* Proba of transmission/interaction along length d_path */
      p_trans = exp (-my_t * d_path);
      p_scatt = 1 - p_trans; /* portion of beam which scatters */

      flag = 0; /* flag used for propagation to exit point before ending */

      /* are we next to the exit ? probably no scattering (avoid rounding errors) */
      if (VarSqw.my_s * d_path <= 4e-7) {
        flag = 1; /* No interaction before the exit */
      }
      /* force a given fraction of the beam to scatter */
      if (p_interact > 0 && p_interact <= 1) {
        /* we force a portion of the beam to interact */
        /* This is used to improve statistics on single scattering (and multiple) */
        if (!SCATTERED)
          mc_trans = 1 - p_interact;
        else
          mc_trans = 1 - p_interact / (4 * SCATTERED + 1); /* reduce effect on multi scatt */
      } else {
        mc_trans = p_trans; /* 1 - p_scatt */
      }
      mc_scatt = 1 - mc_trans; /* portion of beam to scatter (or force to) */
      if (mc_scatt <= 0 || mc_scatt > 1)
        flag = 1;
      /* MC choice: Interaction or transmission ? */
      if (!flag && mc_scatt > 0 && (mc_scatt >= 1 || rand01 () < mc_scatt)) { /* Interaction neutron/sample */
        p_mult *= ws;                                                         /* Update weight ; account for absorption and retain scattered fraction */
        /* we have chosen portion mc_scatt of beam instead of p_scatt, so we compensate */
        if (!mc_scatt)
          ABSORB;
        p_mult *= fabs (p_scatt / mc_scatt); /* lower than 1 */
      } else {
        flag = 1; /* Transmission : no interaction neutron/sample */
        if (!type)
          type = 't';
        if (!mc_trans)
          ABSORB;
        p_mult *= fabs (p_trans / mc_trans); /* attenuate beam by portion which is scattered (and left along) */
      }

      if (flag) { /* propagate to exit of sample and finish */
        intersect = 0;
        p *= p_mult; /* apply absorption correction */
        PROP_DT (dt0 + dt2);
        break; /* exit main multi scatt while loop */
      }
    } /* end if intersect the neutron hits the sample */
    else
      break;

    if (intersect) { /* scattering event */
      double kf = 0, kf1, kf2;
      /* mean scattering probability and absorption fraction */
      VarSqw.mean_scatt += (1 - exp (-VarSqw.my_s * d_path)) * p;
      VarSqw.mean_abs += (1 - ws) * p;
      VarSqw.psum_scatt += p;

      /* Decaying exponential distribution of the path length before scattering */
      /* Select a point at which to scatter the neutron, taking
           secondary extinction into account. */
      if (my_t * d_path < 1e-6)
        /* For very weak scattering, use simple uniform sampling of scattering
           point to avoid rounding errors. */
        dt = rand0max (d_path); /* length */
      else
        dt = -log (1 - rand0max ((1 - exp (-my_t * d_path)))) / my_t; /* length */
      dt /= v;                                                        /* Time from present position to scattering point */

      /* If t0 is in hole, propagate to next part of the hollow cylinder */
      if (dt1 > 0 && dt0 > 0 && dt > dt0)
        dt += dt1;

      /* Neutron propagation to the scattering point */
      PROP_DT (dt);

      /* choice between coherent/incoherent scattering */
      tmp_rand = rand01 ();
      /* local description at the scattering point (scat probability for atom) */
      tmp_rand *= (coh + inc);

      flag = 0;
      if (VarSqw.s_inc > 0 && tmp_rand < inc) {
        /* CASE 1: incoherent case */
        if (!VarSqw.Data_inc.intensity) {
          /* CASE 1a: no incoherent Sqw from file, use isotropic V-like */
          if (d_phi_thread && order == 1) {
            randvec_target_rect_angular (&u1x, &u1y, &u1z, &solid_angle, vx, vy, vz, 2 * PI, d_phi_thread, ROT_A_CURRENT_COMP);
            p_mult *= solid_angle / 4 / PI; /* weighted by focused range to total range */
          } else
            randvec_target_circle (&u1x, &u1y, &u1z, NULL, vx, vy, vz, 0);

          vx = u1x;
          vy = u1y;
          vz = u1z;
          vf = v;
          kf = k;
          if (!type)
            type = 'v';
          SCATTER;
        } else {
          /* CASE 1b: incoherent Sqw from file */
          if (VarSqw.Data_inc.intensity) {
            Data_sqw = VarSqw.Data_inc;
            if (!type)
              type = 'i';
            flag = 1;
          }
        }
      } else if (VarSqw.s_coh > 0 && tmp_rand > VarSqw.s_inc) {
        if (VarSqw.Data_coh.intensity) {
          /* CASE2: coherent case */
          Data_sqw = VarSqw.Data_coh;
          if (!type)
            type = 'c';
          flag = 1;
        }
      }

      if (flag) { /* true when S(q,w) table exists (Data_sqw) */

        double alpha = 0, alpha0;
        /* give us a limited number of tries for scattering: choose W then Q */
        for (index_counter = VarSqw.maxloop; index_counter > 0; index_counter--) {

          /* MC choice: energy transfer w=Ei-Ef in the S(w) = SW */
          omega = 0;
          tmp_rand = rand01 ();
          /* energy index for rand > cumul SW */
          index_w = Sqw_search_SW (Data_sqw, tmp_rand);
          VarSqw.rw = (double)index_w;
          if (index_w >= 0 && &(Data_sqw.SW[index_w]) != NULL) {
            if (Data_sqw.w_bins > 1) {
              double w1, w2;
              if (index_w > 0) { /* interpolate linearly energy */
                ratio_w = (tmp_rand - Data_sqw.SW[index_w - 1].cumul_proba) / (Data_sqw.SW[index_w].cumul_proba - Data_sqw.SW[index_w - 1].cumul_proba);
                /* ratio_w=0 omega[index_w-1], ratio=1 omega[index] */
                w1 = Data_sqw.SW[index_w - 1].omega;
                w2 = Data_sqw.SW[index_w].omega;
              } else { /* index_w = 0 interpolate to 0 energy */
                /* ratio_w=0 omega=0, ratio=1 omega[index] */
                w1 = Data_sqw.SW[index_w].omega;
                w2 = Data_sqw.SW[index_w + 1].omega;
                if (!w2 && index_w + 1 < Data_sqw.w_bins)
                  w2 = Data_sqw.SW[index_w + 1].omega;
                if (Data_sqw.w_bins && Data_sqw.SW[index_w].cumul_proba) {
                  ratio_w = tmp_rand / Data_sqw.SW[index_w].cumul_proba;
                } else
                  ratio_w = 0;
              }
              if (ratio_w < 0)
                ratio_w = 0;
              else if (ratio_w > 1)
                ratio_w = 1;
              omega = (1 - ratio_w) * w1 + ratio_w * w2;
            } else {
              ratio_w = 0;
              omega = Data_sqw.SW[index_w].omega;
            }
          } else {
            if (VarSqw.verbose_output >= 3 && VarSqw.neutron_removed < VarSqw.maxloop)
              printf ("Isotropic_Sqw: %s: Warning: No suitable w transfer for index_w=%li.\n", NAME_CURRENT_COMP, index_w);
            continue; /* no W value: try again with an other energy transfer */
          }

          /* MC choice: momentum transfer Q in P(Q|w) */
          tmp_rand = rand01 ();

          /* momentum index for rand > cumul SQ|W */
          index_q = Sqw_search_Q_proba_per_w (Data_sqw, tmp_rand, index_w);
          VarSqw.rq = (double)index_q;

          if (index_q >= 0 && &(Data_sqw.SQW[index_w]) != NULL) {
            if (Data_sqw.q_bins > 1 && index_q > 0) {
              if (index_w > 0 && Data_sqw.w_bins > 1) {
                /* bilinear interpolation on - side: index_w > 0, index_q > 0 */
                ratio_q = (tmp_rand - Data_sqw.SQW[index_w][index_q - 1].cumul_proba)
                          / (Data_sqw.SQW[index_w][index_q].cumul_proba - Data_sqw.SQW[index_w][index_q - 1].cumul_proba);
                q22 = Data_sqw.SQW[index_w][index_q].Q;
                q11 = Data_sqw.SQW[index_w - 1][index_q - 1].Q;
                q21 = Data_sqw.SQW[index_w][index_q - 1].Q;
                q12 = Data_sqw.SQW[index_w - 1][index_q].Q;
                if (ratio_q < 0)
                  ratio_q = 0;
                else if (ratio_q > 1)
                  ratio_q = 1;
                q = (1 - ratio_w) * (1 - ratio_q) * q11 + ratio_w * (1 - ratio_q) * q21 + ratio_w * ratio_q * q22 + (1 - ratio_w) * ratio_q * q12;
              } else { /* bilinear interpolation on + side: index_w=0, index_q > 0 */
                ratio_q = (tmp_rand - Data_sqw.SQW[index_w][index_q - 1].cumul_proba)
                          / (Data_sqw.SQW[index_w][index_q].cumul_proba - Data_sqw.SQW[index_w][index_q - 1].cumul_proba);
                q11 = Data_sqw.SQW[index_w][index_q - 1].Q;
                q12 = Data_sqw.SQW[index_w][index_q].Q;
                if (ratio_q < 0)
                  ratio_q = 0;
                else if (ratio_q > 1)
                  ratio_q = 1;
                if (index_w < Data_sqw.w_bins - 1 && Data_sqw.w_bins > 1) {
                  q22 = Data_sqw.SQW[index_w + 1][index_q].Q;
                  q21 = Data_sqw.SQW[index_w + 1][index_q - 1].Q;
                  q = (1 - ratio_w) * (1 - ratio_q) * q11 + ratio_w * (1 - ratio_q) * q21 + ratio_w * ratio_q * q22 + (1 - ratio_w) * ratio_q * q12;
                } else {
                  q = (1 - ratio_q) * q11 + ratio_q * q12;
                }
              }
            } else {
              q = Data_sqw.SQW[index_w][index_q].Q;
            }
          } else {
            if (VarSqw.verbose_output >= 3 && VarSqw.neutron_removed < VarSqw.maxloop)
              printf ("Isotropic_Sqw: %s: Warning: No suitable q transfer for w=%g.\n", NAME_CURRENT_COMP, omega);
            VarSqw.neutron_removed++;
            continue; /* no Q value for this w choice */
          }

          /* Search for length of final wave vector kf */
          /* kf is such that : hbar*w = hbar*hbar/2/m*(k*k - kf*kf) */
          /* acceptable values for kf are kf1 and kf2 */
          if (!solve_2nd_order (&kf1, &kf2, 1, 0, -k * k + VarSqw.sqSE2K * omega)) {
            if (VarSqw.verbose_output >= 3 && VarSqw.neutron_removed < VarSqw.maxloop)
              printf ("Isotropic_Sqw: %s: Warning: imaginary root for w=%g q=%g Ei=%g (triangle can not close)\n", NAME_CURRENT_COMP, omega, q, Ei);
            VarSqw.neutron_removed++;
            continue; /* all roots are imaginary */
          }

          /* kf1 and kf2 are opposite */
          kf = fabs (kf1);
          vf = K2V * kf;

          /* Search of the direction of kf such that : q = ki - kf */
          /* cos theta = (ki2+kf2-q2)/(2ki kf) */

          costheta = (k * k + kf * kf - q * q) / (2 * kf * k); /* this is cos(theta) */

          if (-1 < costheta && costheta < 1) {
            break; /* satisfies q momentum conservation */
          }
          /*      else continue; */

          /* exit for loop on success */
        } /* end for index_counter */

        if (!index_counter) { /* for loop ended: failure for scattering */
          intersect = 0;      /* Could not scatter: finish multiple scattering loop */
          if (VarSqw.verbose_output >= 2 && VarSqw.neutron_removed < VarSqw.maxloop)
            printf ("Isotropic_Sqw: %s: Warning: No scattering [q,w] conditions\n"
                    "               last try (%i): type=%c w=%g q=%g cos(theta)=%g k=%g\n",
                    NAME_CURRENT_COMP, VarSqw.maxloop, (type ? type : '-'), omega, q, costheta, k);
          VarSqw.neutron_removed++;
          if (order && SCATTERED != order)
            ABSORB;
          break; /* finish multiple scattering loop */
        }

        /* scattering angle from ki to DS cone */
        theta = acos (costheta);

        /* Choose point on Debye-Scherrer cone */
        if (order == 1 && d_phi_thread) { /* relate height of detector to the height on DS cone */
          double cone_focus;
          cone_focus = sin (d_phi_thread / 2) / sin (theta);
          /* If full Debye-Scherrer cone is within d_phi_thread, don't focus */
          if (cone_focus < -1 || cone_focus > 1)
            d_phi_thread = 0;
          /* Otherwise, determine alpha to rotate from scattering plane
              into d_phi_thread focusing area*/
          else
            alpha = 2 * asin (cone_focus);
          if (d_phi_thread)
            p_mult *= alpha / PI;
        }
        if (d_phi_thread) {
          /* Focusing */
          alpha = fabs (alpha);
          /* Trick to get scattering for pos/neg theta's */
          alpha0 = 2 * rand01 () * alpha;
          if (alpha0 > alpha) {
            alpha0 = PI + (alpha0 - 1.5 * alpha);
          } else {
            alpha0 = alpha0 - 0.5 * alpha;
          }
        } else
          alpha0 = PI * randpm1 ();

        /* now find a nearly vertical rotation axis (u1) :
         * Either
         *  (v along Z) x (X axis) -> nearly Y axis
         * Or
         *  (v along X) x (Z axis) -> nearly Y axis
         */
        if (fabs (scalar_prod (1, 0, 0, vx / v, vy / v, vz / v)) < fabs (scalar_prod (0, 0, 1, vx / v, vy / v, vz / v))) {
          u1x = 1;
          u1y = u1z = 0;
        } else {
          u1x = u1y = 0;
          u1z = 1;
        }
        vec_prod (u2x, u2y, u2z, vx, vy, vz, u1x, u1y, u1z);

        /* handle case where v and aim are parallel */
        if (!u2x && !u2y && !u2z) {
          u2x = u2z = 0;
          u2y = 1;
        }

        /* u1 = rotate 'v' by theta around u2: DS scattering angle, nearly in horz plane */
        rotate (u1x, u1y, u1z, vx, vy, vz, theta, u2x, u2y, u2z);

        /* u0 = rotate u1 by alpha0 around 'v' (Debye-Scherrer cone) */
        rotate (u0x, u0y, u0z, u1x, u1y, u1z, alpha0, vx, vy, vz);
        NORM (u0x, u0y, u0z);
        vx = u0x * vf;
        vy = u0y * vf;
        vz = u0z * vf;

        SCATTER;

        v = vf;
        k = kf; /* for next iteration */

      } /* end if (flag) */

      VarSqw.neutron_exit++;
      p *= p_mult;
      if (p_mult > 1)
        VarSqw.neutron_pmult++;

      /* test for a given multiple order */
      if (order && SCATTERED >= order) {
        intersect = 0; /* reached required number of SCATTERing */
        break;         /* finish multiple scattering loop */
      }

    } /* end if (intersect) scattering event  */

  } while (intersect); /* end do (intersect) (multiple scattering loop) */

  /* Store Final neutron state */
  kf_x = V2K * vx;
  kf_y = V2K * vy;
  kf_z = V2K * vz;
  tf = t;
  vf = v;
  kf = k;
  VarSqw.theta = theta;

  if (SCATTERED) {

    if (SCATTERED == 1) {
      if (type == 'c')
        VarSqw.single_coh += p;
      else
        VarSqw.single_inc += p;
      VarSqw.dq = sqrt ((kf_x - ki_x) * (kf_x - ki_x) + (kf_y - ki_y) * (kf_y - ki_y) + (kf_z - ki_z) * (kf_z - ki_z));
      VarSqw.dw = VS2E * (vf * vf - vi * vi);
    } else
      VarSqw.multi += p;

  } else
    VarSqw.dq = VarSqw.dw = 0;

  /* end TRACE */
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif

if (_comp->_index == 36) { // EXTEND 'iso_samp'

if (!SCATTERED) ABSORB;
    
}

  #undef powder_format
  #undef Sqw_coh
  #undef Sqw_inc
  #undef geometry
  #undef radius
  #undef thickness
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef threshold
  #undef order
  #undef T
  #undef verbose
  #undef d_phi
  #undef concentric
  #undef rho
  #undef sigma_abs
  #undef sigma_coh
  #undef sigma_inc
  #undef classical
  #undef powder_Dd
  #undef powder_DW
  #undef powder_Vc
  #undef density
  #undef weight
  #undef p_interact
  #undef norm
  #undef powder_barns
  #undef quantum_correction
  #undef VarSqw
  #undef columns
  #undef offdata
  return;
} /* class_Isotropic_Sqw_trace */

#pragma acc routine
void class_Monitor_nD_trace(_class_Monitor_nD *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define user1 (_comp->_parameters.user1)
  #define user2 (_comp->_parameters.user2)
  #define user3 (_comp->_parameters.user3)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define zmin (_comp->_parameters.zmin)
  #define zmax (_comp->_parameters.zmax)
  #define bins (_comp->_parameters.bins)
  #define min (_comp->_parameters.min)
  #define max (_comp->_parameters.max)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define radius (_comp->_parameters.radius)
  #define options (_comp->_parameters.options)
  #define filename (_comp->_parameters.filename)
  #define geometry (_comp->_parameters.geometry)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define nexus_bins (_comp->_parameters.nexus_bins)
  #define username1 (_comp->_parameters.username1)
  #define username2 (_comp->_parameters.username2)
  #define username3 (_comp->_parameters.username3)
  #define DEFS (_comp->_parameters.DEFS)
  #define Vars (_comp->_parameters.Vars)
  #define detector (_comp->_parameters.detector)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_Banana_1_trace] component Banana_1=Monitor_nD() TRACE [Monitor_nD:0]");

  double transmit_he3 = 1.0;
  double multiplier_capture = 1.0;
  double t0 = 0;
  double t1 = 0;
  int pp;
  int intersect = 0;
  char Flag_Restore = 0;

  #ifdef OPENACC
  #ifdef USE_OFF
  off_struct thread_offdata = offdata;
  #endif
  #else
  #define thread_offdata offdata
  #endif

  /* this is done automatically
    STORE_NEUTRON(INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  */
  #ifdef USE_OFF
  if (geometry && strlen (geometry) && strcmp (geometry, "0") && strcmp (geometry, "NULL")) {
    /* determine intersections with object */
    intersect = off_intersect_all (&t0, &t1, NULL, NULL, x, y, z, vx, vy, vz, 0, 0, 0, &thread_offdata);
    if (Vars.Flag_mantid) {
      if (intersect) {
        Vars.OFF_polyidx = thread_offdata.nextintersect;
      } else {
        Vars.OFF_polyidx = -1;
      }
    }
  } else
    #endif
    if ((abs (Vars.Flag_Shape) == DEFS.SHAPE_SQUARE) || (abs (Vars.Flag_Shape) == DEFS.SHAPE_DISK)) /* square xy or disk xy */
    {
      // propagate to xy plane and find intersection
      // make sure the event is recoverable afterwards
      t0 = t;
      ALLOW_BACKPROP;
      PROP_Z0;
      if ((t >= t0) && (z == 0.0)) // forward propagation to xy plane was successful
      {
        if (abs (Vars.Flag_Shape) == DEFS.SHAPE_SQUARE) {
          // square xy
          intersect = (x >= Vars.mxmin && x <= Vars.mxmax && y >= Vars.mymin && y <= Vars.mymax);
        } else {
          // disk xy
          intersect = (SQR (x) + SQR (y)) <= SQR (Vars.Sphere_Radius);
        }
      } else {
        intersect = 0;
      }
    } else if (abs (Vars.Flag_Shape) == DEFS.SHAPE_SPHERE) /* sphere */
    {
      intersect = sphere_intersect (&t0, &t1, x, y, z, vx, vy, vz, Vars.Sphere_Radius);
      /*      intersect = (intersect && t0 > 0); */
    } else if ((abs (Vars.Flag_Shape) == DEFS.SHAPE_CYLIND) || (abs (Vars.Flag_Shape) == DEFS.SHAPE_BANANA)) /* cylinder */
    {
      intersect = cylinder_intersect (&t0, &t1, x, y, z, vx, vy, vz, Vars.Sphere_Radius, Vars.Cylinder_Height);
    } else if (abs (Vars.Flag_Shape) == DEFS.SHAPE_BOX) /* box */
    {
      intersect = box_intersect (&t0, &t1, x, y, z, vx, vy, vz, fabs (Vars.mxmax - Vars.mxmin), fabs (Vars.mymax - Vars.mymin), fabs (Vars.mzmax - Vars.mzmin));
    } else if (abs (Vars.Flag_Shape) == DEFS.SHAPE_PREVIOUS) /* previous comp */
    {
      intersect = 1;
    }

  if (intersect) {
    if ((abs (Vars.Flag_Shape) == DEFS.SHAPE_SPHERE) || (abs (Vars.Flag_Shape) == DEFS.SHAPE_CYLIND) || (abs (Vars.Flag_Shape) == DEFS.SHAPE_BOX)
        || (abs (Vars.Flag_Shape) == DEFS.SHAPE_BANANA) || (geometry && strlen (geometry) && strcmp (geometry, "0") && strcmp (geometry, "NULL"))) {
      /* check if we have to remove the top/bottom with BANANA shape */
      if (abs (Vars.Flag_Shape) == DEFS.SHAPE_BANANA) {
        if (intersect == 1) { // Entered and left through sides
          if (t0 < 0 && t1 > 0) {
            t0 = t; /* neutron was already inside ! */
          }
          if (t1 < 0 && t0 > 0) { /* neutron exit before entering !! */
            t1 = t;
          }
          /* t0 is now time of incoming intersection with the detection area */
          if ((Vars.Flag_Shape < 0) && (t1 > 0)) {
            PROP_DT (t1); /* t1 outgoing beam */
          } else {
            PROP_DT (t0); /* t0 incoming beam */
          }
        } else if (intersect == 3 || intersect == 5) { // Entered from top or bottom, left through side
          if ((Vars.Flag_Shape < 0) && (t1 > 0)) {
            PROP_DT (t1); /* t1 outgoing beam */
          } else {
            intersect = 0;
            Flag_Restore = 1;
          }
        } else if (intersect == 9 || intersect == 17) { // Entered through side, left from top or bottom
          if ((Vars.Flag_Shape < 0) && (t1 > 0)) {
            intersect = 0;
            Flag_Restore = 1;
          } else {
            PROP_DT (t0); /* t0 incoming beam */
          }
        } else if (intersect == 13 || intersect == 19) { // Went through top/bottom on entry and exit
          intersect = 0;
          Flag_Restore = 1;
        } else {
          printf ("Cylinder_intersect returned unexpected value %i\n", intersect);
        }
      } else {
        // All other shapes than the BANANA
        if (t0 < 0 && t1 > 0)
          t0 = t;             /* neutron was already inside ! */
        if (t1 < 0 && t0 > 0) /* neutron exit before entering !! */
          t1 = t;
        /* t0 is now time of incoming intersection with the detection area */
        if ((Vars.Flag_Shape < 0) && (t1 > 0))
          PROP_DT (t1); /* t1 outgoing beam */
        else
          PROP_DT (t0); /* t0 incoming beam */
      }

      /* Final test if we are on lid / bottom of banana/sphere */
      if (abs (Vars.Flag_Shape) == DEFS.SHAPE_BANANA || abs (Vars.Flag_Shape) == DEFS.SHAPE_SPHERE) {
        if (Vars.Cylinder_Height && fabs (y) >= Vars.Cylinder_Height / 2 - FLT_EPSILON) {
          intersect = 0;
          Flag_Restore = 1;
        }
      }
    }
  }

  if (intersect) {
    /* Now get the data to monitor: current or keep from PreMonitor */
    /*    if (Vars.Flag_UsePreMonitor != 1)*/
    /*    {*/
    /*      Vars.cp  = p;*/
    /*      Vars.cx  = x;*/
    /*      Vars.cvx = vx;*/
    /*      Vars.csx = sx;*/
    /*      Vars.cy  = y;*/
    /*      Vars.cvy = vy;*/
    /*      Vars.csy = sy;*/
    /*      Vars.cz  = z;*/
    /*      Vars.cvz = vz;*/
    /*      Vars.csz = sz;*/
    /*      Vars.ct  = t;*/
    /*    }*/

    if ((Vars.He3_pressure > 0) && (t1 != t0)
        && ((abs (Vars.Flag_Shape) == DEFS.SHAPE_SPHERE) || (abs (Vars.Flag_Shape) == DEFS.SHAPE_CYLIND) || (abs (Vars.Flag_Shape) == DEFS.SHAPE_BOX))) {
      transmit_he3 = exp (-7.417 * Vars.He3_pressure * fabs (t1 - t0) * 2 * PI * K2V);
      /* will monitor the absorbed part */
      p = p * (1 - transmit_he3);
    }

    if (Vars.Flag_capture) {
      multiplier_capture = V2K * sqrt (vx * vx + vy * vy + vz * vz);
      if (multiplier_capture != 0)
        multiplier_capture = 2 * PI / multiplier_capture; /* lambda. lambda(2200 m/2) = 1.7985 Angs  */
      p = p * multiplier_capture / 1.7985;
    }

    pp = Monitor_nD_Trace (&DEFS, &Vars, _particle);
    if (pp == 0.0) {
      ABSORB;
    } else if (pp == 1) {
      SCATTER;
    }

    /*set weight to undetected part if capture and/or he3_pressure*/
    if (Vars.He3_pressure > 0) {
      /* after monitor, only remains 1-p_detect */
      p = p * transmit_he3 / (1.0 - transmit_he3);
    }

    if (Vars.Flag_capture) {
      p = p / multiplier_capture * 1.7985;
    }

    if (Vars.Flag_parallel) /* back to neutron state before detection */
      Flag_Restore = 1;
  } /* end if intersection */
  else {
    if (Vars.Flag_Absorb && !Vars.Flag_parallel) {
      // restore neutron ray before absorbing for correct mcdisplay
      RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
      ABSORB;
    } else
      Flag_Restore = 1; /* no intersection, back to previous state */
  }

  if (Flag_Restore) {
    RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef user1
  #undef user2
  #undef user3
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef zmin
  #undef zmax
  #undef bins
  #undef min
  #undef max
  #undef restore_neutron
  #undef radius
  #undef options
  #undef filename
  #undef geometry
  #undef nowritefile
  #undef nexus_bins
  #undef username1
  #undef username2
  #undef username3
  #undef DEFS
  #undef Vars
  #undef detector
  #undef offdata
  return;
} /* class_Monitor_nD_trace */

/* *****************************************************************************
* instrument 'ISIS_LET_generated' TRACE
***************************************************************************** */

#ifndef FUNNEL
#pragma acc routine
int raytrace(_class_particle* _particle) { /* single event propagation, called by mccode_main for ISIS_LET_generated:TRACE */

  /* init variables and counters for TRACE */
  #undef ABSORB0
  #undef ABSORB
  #define ABSORB0 do { DEBUG_ABSORB(); MAGNET_OFF; ABSORBED++;} while(0)
  #define ABSORB ABSORB0
  DEBUG_ENTER();
  DEBUG_STATE();
  _particle->flag_nocoordschange=0; /* Init */
  _class_particle _particle_save=*_particle;
  /* the main iteration loop for one incoming event */
  while (!ABSORBED) { /* iterate event until absorbed */
    /* send particle event to component instance, one after the other */
    /* begin component Origin=Arm() [1] */
    if (!ABSORBED && _particle->_index == 1) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component Origin [1] */
    /* begin component SourceMantid=Commodus_I3() [2] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_SourceMantid_var._rotation_is_identity) {
        if(!_SourceMantid_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _SourceMantid_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_SourceMantid_var._position_relative, _SourceMantid_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 2) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_SourceMantid_var._name);
      DEBUG_STATE();
      class_Commodus_I3_trace(&_SourceMantid_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component SourceMantid [2] */
    /* begin component shutter=Guide_channeled() [3] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_shutter_var._rotation_is_identity) {
        if(!_shutter_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _shutter_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_shutter_var._position_relative, _shutter_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 3) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_shutter_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_shutter_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component shutter [3] */
    /* begin component insert=Guide_channeled() [4] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_insert_var._rotation_is_identity) {
        if(!_insert_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _insert_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_insert_var._position_relative, _insert_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 4) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_insert_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_insert_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component insert [4] */
    /* begin component after_insert=Guide_channeled() [5] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_after_insert_var._rotation_is_identity) {
        if(!_after_insert_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _after_insert_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_after_insert_var._position_relative, _after_insert_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 5) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_after_insert_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_after_insert_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component after_insert [5] */
    /* begin component Monitor1=TOF_monitor() [6] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Monitor1_var._rotation_is_identity) {
        if(!_Monitor1_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Monitor1_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Monitor1_var._position_relative, _Monitor1_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 6) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Monitor1_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN execution
      class_TOF_monitor_trace(&_Monitor1_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Monitor1 [6] */
    /* begin component LET_Chopper1_disk1=DiskChopper() [7] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_LET_Chopper1_disk1_var._rotation_is_identity) {
        if(!_LET_Chopper1_disk1_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper1_disk1_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_LET_Chopper1_disk1_var._position_relative, _LET_Chopper1_disk1_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 7) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_LET_Chopper1_disk1_var._name);
      DEBUG_STATE();
      class_DiskChopper_trace(&_LET_Chopper1_disk1_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component LET_Chopper1_disk1 [7] */
    /* begin component LET_Chopper1_disk2=DiskChopper() [8] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_LET_Chopper1_disk2_var._rotation_is_identity) {
        if(!_LET_Chopper1_disk2_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper1_disk2_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_LET_Chopper1_disk2_var._position_relative, _LET_Chopper1_disk2_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 8) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_LET_Chopper1_disk2_var._name);
      DEBUG_STATE();
      class_DiskChopper_trace(&_LET_Chopper1_disk2_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component LET_Chopper1_disk2 [8] */
    /* begin component Monitor2=TOF_monitor() [9] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Monitor2_var._rotation_is_identity) {
        if(!_Monitor2_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Monitor2_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Monitor2_var._position_relative, _Monitor2_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 9) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Monitor2_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN execution
      class_TOF_monitor_trace(&_Monitor2_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Monitor2 [9] */
    /* begin component between_chop1_and_chop2=Guide_channeled() [10] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_between_chop1_and_chop2_var._rotation_is_identity) {
        if(!_between_chop1_and_chop2_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _between_chop1_and_chop2_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_between_chop1_and_chop2_var._position_relative, _between_chop1_and_chop2_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 10) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_between_chop1_and_chop2_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_between_chop1_and_chop2_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component between_chop1_and_chop2 [10] */
    /* begin component LET_Chopper2=DiskChopper() [11] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_LET_Chopper2_var._rotation_is_identity) {
        if(!_LET_Chopper2_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper2_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_LET_Chopper2_var._position_relative, _LET_Chopper2_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 11) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_LET_Chopper2_var._name);
      DEBUG_STATE();
      class_DiskChopper_trace(&_LET_Chopper2_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component LET_Chopper2 [11] */
    /* begin component Monitor3=TOF_monitor() [12] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Monitor3_var._rotation_is_identity) {
        if(!_Monitor3_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Monitor3_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Monitor3_var._position_relative, _Monitor3_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 12) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Monitor3_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN execution
      class_TOF_monitor_trace(&_Monitor3_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Monitor3 [12] */
    /* begin component between_chop2_and_chop3=Guide_channeled() [13] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_between_chop2_and_chop3_var._rotation_is_identity) {
        if(!_between_chop2_and_chop3_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _between_chop2_and_chop3_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_between_chop2_and_chop3_var._position_relative, _between_chop2_and_chop3_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 13) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_between_chop2_and_chop3_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_between_chop2_and_chop3_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component between_chop2_and_chop3 [13] */
    /* begin component LET_Chopper3=DiskChopper() [14] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_LET_Chopper3_var._rotation_is_identity) {
        if(!_LET_Chopper3_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper3_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_LET_Chopper3_var._position_relative, _LET_Chopper3_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 14) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_LET_Chopper3_var._name);
      DEBUG_STATE();
      class_DiskChopper_trace(&_LET_Chopper3_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component LET_Chopper3 [14] */
    /* begin component Monitor4=TOF_monitor() [15] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Monitor4_var._rotation_is_identity) {
        if(!_Monitor4_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Monitor4_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Monitor4_var._position_relative, _Monitor4_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 15) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Monitor4_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN execution
      class_TOF_monitor_trace(&_Monitor4_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Monitor4 [15] */
    /* begin component between_chop3_and_chop4=Guide_channeled() [16] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_between_chop3_and_chop4_var._rotation_is_identity) {
        if(!_between_chop3_and_chop4_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _between_chop3_and_chop4_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_between_chop3_and_chop4_var._position_relative, _between_chop3_and_chop4_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 16) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_between_chop3_and_chop4_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_between_chop3_and_chop4_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component between_chop3_and_chop4 [16] */
    /* begin component LET_Chopper4=DiskChopper() [17] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_LET_Chopper4_var._rotation_is_identity) {
        if(!_LET_Chopper4_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper4_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_LET_Chopper4_var._position_relative, _LET_Chopper4_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 17) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_LET_Chopper4_var._name);
      DEBUG_STATE();
      class_DiskChopper_trace(&_LET_Chopper4_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component LET_Chopper4 [17] */
    /* begin component Monitor5=TOF_monitor() [18] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Monitor5_var._rotation_is_identity) {
        if(!_Monitor5_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Monitor5_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Monitor5_var._position_relative, _Monitor5_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 18) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Monitor5_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN execution
      class_TOF_monitor_trace(&_Monitor5_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Monitor5 [18] */
    /* begin component between_chop4_and_movable=Guide_channeled() [19] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_between_chop4_and_movable_var._rotation_is_identity) {
        if(!_between_chop4_and_movable_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _between_chop4_and_movable_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_between_chop4_and_movable_var._position_relative, _between_chop4_and_movable_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 19) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_between_chop4_and_movable_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_between_chop4_and_movable_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component between_chop4_and_movable [19] */
    /* begin component moveable_front_PSDmon=PSD_monitor() [20] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_moveable_front_PSDmon_var._rotation_is_identity) {
        if(!_moveable_front_PSDmon_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _moveable_front_PSDmon_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_moveable_front_PSDmon_var._position_relative, _moveable_front_PSDmon_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 20) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_moveable_front_PSDmon_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.movable_monitors == 1 ))) // conditional WHEN execution
      class_PSD_monitor_trace(&_moveable_front_PSDmon_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component moveable_front_PSDmon [20] */
    /* begin component moveable_front_Divmon=Divergence_monitor() [21] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_moveable_front_Divmon_var._rotation_is_identity) {
        if(!_moveable_front_Divmon_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _moveable_front_Divmon_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_moveable_front_Divmon_var._position_relative, _moveable_front_Divmon_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 21) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_moveable_front_Divmon_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.movable_monitors == 1 ))) // conditional WHEN execution
      class_Divergence_monitor_trace(&_moveable_front_Divmon_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component moveable_front_Divmon [21] */
    /* begin component moveable_guide=Guide_channeled() [22] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_moveable_guide_var._rotation_is_identity) {
        if(!_moveable_guide_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _moveable_guide_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_moveable_guide_var._position_relative, _moveable_guide_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 22) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_moveable_guide_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_moveable_guide_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component moveable_guide [22] */
    /* begin component moveable_back_PSDmon=PSD_monitor() [23] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_moveable_back_PSDmon_var._rotation_is_identity) {
        if(!_moveable_back_PSDmon_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _moveable_back_PSDmon_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_moveable_back_PSDmon_var._position_relative, _moveable_back_PSDmon_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 23) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_moveable_back_PSDmon_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.movable_monitors == 1 ))) // conditional WHEN execution
      class_PSD_monitor_trace(&_moveable_back_PSDmon_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component moveable_back_PSDmon [23] */
    /* begin component moveable_back_Divmon=Divergence_monitor() [24] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_moveable_back_Divmon_var._rotation_is_identity) {
        if(!_moveable_back_Divmon_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _moveable_back_Divmon_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_moveable_back_Divmon_var._position_relative, _moveable_back_Divmon_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 24) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_moveable_back_Divmon_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.movable_monitors == 1 ))) // conditional WHEN execution
      class_Divergence_monitor_trace(&_moveable_back_Divmon_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component moveable_back_Divmon [24] */
    /* begin component funnel=Guide_channeled() [25] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_funnel_var._rotation_is_identity) {
        if(!_funnel_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _funnel_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_funnel_var._position_relative, _funnel_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 25) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_funnel_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_funnel_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component funnel [25] */
    /* begin component LET_Chopper5_Disk1=DiskChopper() [26] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_LET_Chopper5_Disk1_var._rotation_is_identity) {
        if(!_LET_Chopper5_Disk1_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper5_Disk1_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_LET_Chopper5_Disk1_var._position_relative, _LET_Chopper5_Disk1_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 26) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_LET_Chopper5_Disk1_var._name);
      DEBUG_STATE();
      class_DiskChopper_trace(&_LET_Chopper5_Disk1_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component LET_Chopper5_Disk1 [26] */
    /* begin component LET_Chopper5_Disk2=DiskChopper() [27] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_LET_Chopper5_Disk2_var._rotation_is_identity) {
        if(!_LET_Chopper5_Disk2_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper5_Disk2_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_LET_Chopper5_Disk2_var._position_relative, _LET_Chopper5_Disk2_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 27) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_LET_Chopper5_Disk2_var._name);
      DEBUG_STATE();
      class_DiskChopper_trace(&_LET_Chopper5_Disk2_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component LET_Chopper5_Disk2 [27] */
    /* begin component Monitor6=TOF_monitor() [28] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Monitor6_var._rotation_is_identity) {
        if(!_Monitor6_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Monitor6_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Monitor6_var._position_relative, _Monitor6_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 28) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Monitor6_var._name);
      DEBUG_STATE();
      if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN execution
      class_TOF_monitor_trace(&_Monitor6_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Monitor6 [28] */
    /* begin component tanksection=Guide_channeled() [29] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_tanksection_var._rotation_is_identity) {
        if(!_tanksection_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _tanksection_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_tanksection_var._position_relative, _tanksection_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 29) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_tanksection_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_tanksection_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component tanksection [29] */
    /* begin component snout=Guide_channeled() [30] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_snout_var._rotation_is_identity) {
        if(!_snout_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _snout_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_snout_var._position_relative, _snout_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 30) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_snout_var._name);
      DEBUG_STATE();
      class_Guide_channeled_trace(&_snout_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component snout [30] */
    /* begin component sample=Arm() [31] */
    if (!ABSORBED && _particle->_index == 31) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component sample [31] */
    /* begin component sample_PSDmon=PSD_monitor() [32] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_PSDmon_var._rotation_is_identity) {
        if(!_sample_PSDmon_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_PSDmon_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_PSDmon_var._position_relative, _sample_PSDmon_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 32) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_PSDmon_var._name);
      DEBUG_STATE();
      class_PSD_monitor_trace(&_sample_PSDmon_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample_PSDmon [32] */
    /* begin component sample_Divmon=Divergence_monitor() [33] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_Divmon_var._rotation_is_identity) {
        if(!_sample_Divmon_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_Divmon_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_Divmon_var._position_relative, _sample_Divmon_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 33) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_Divmon_var._name);
      DEBUG_STATE();
      class_Divergence_monitor_trace(&_sample_Divmon_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample_Divmon [33] */
    /* begin component sample_tof=TOF_monitor() [34] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_tof_var._rotation_is_identity) {
        if(!_sample_tof_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_tof_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_tof_var._position_relative, _sample_tof_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 34) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_tof_var._name);
      DEBUG_STATE();
      class_TOF_monitor_trace(&_sample_tof_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample_tof [34] */
    /* begin component sample_Emon=E_monitor() [35] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_Emon_var._rotation_is_identity) {
        if(!_sample_Emon_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_Emon_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_Emon_var._position_relative, _sample_Emon_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 35) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_Emon_var._name);
      DEBUG_STATE();
      class_E_monitor_trace(&_sample_Emon_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample_Emon [35] */
    /* begin component iso_samp=Isotropic_Sqw() [36] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_iso_samp_var._rotation_is_identity) {
        if(!_iso_samp_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _iso_samp_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_iso_samp_var._position_relative, _iso_samp_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 36) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_iso_samp_var._name);
      DEBUG_STATE();
      class_Isotropic_Sqw_trace(&_iso_samp_var, _particle); /* contains EXTEND code */
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component iso_samp [36] */
    /* begin component detectorArm=Arm() [37] */
    if (!ABSORBED && _particle->_index == 37) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle->_index++;
    } /* end component detectorArm [37] */
    /* begin component Banana_1=Monitor_nD() [38] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Banana_1_var._rotation_is_identity) {
        if(!_Banana_1_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Banana_1_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Banana_1_var._position_relative, _Banana_1_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 38) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Banana_1_var._name);
      DEBUG_STATE();
      class_Monitor_nD_trace(&_Banana_1_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Banana_1 [38] */
    if (_particle->_index > 38)
      ABSORBED++; /* absorbed when passed all components */
  } /* while !ABSORBED */

  DEBUG_LEAVE()
  particle_restore(_particle, &_particle_save);
  DEBUG_STATE()

  return(_particle->_index);
} /* raytrace */

/* loop to generate events and call raytrace() propagate them */
void raytrace_all(unsigned long long ncount, unsigned long seed) {

  /* CPU-loop */
  unsigned long long loops;
  loops = ceil((double)ncount/gpu_innerloop);
  /* if on GPU, printf has been globally nullified, re-enable here */
  #ifdef OPENACC
  #undef strlen
  #undef strcmp
  #undef exit
  #undef printf
  #undef sprintf
  #undef fprintf
  #endif

  #ifdef OPENACC
  if (ncount>gpu_innerloop) {
    printf("Defining %llu CPU loops around GPU kernel and adjusting ncount\n",loops);
    mcset_ncount(loops*gpu_innerloop);
  } else {
    #endif
    loops=1;
    gpu_innerloop = ncount;
    #ifdef OPENACC
  }
    #endif

  for (unsigned long long cloop=0; cloop<loops; cloop++) {
    #ifdef OPENACC
    if (loops>1) fprintf(stdout, "%d..", (int)cloop); fflush(stdout);
    #endif

    /* if on GPU, re-nullify printf */
     #ifdef OPENACC
     #undef strlen
     #undef strcmp
     #undef exit
     #undef printf
     #undef sprintf
     #undef fprintf
     #endif

    #pragma acc parallel loop num_gangs(numgangs) vector_length(vecsize)
    for (unsigned long pidx=0 ; pidx < gpu_innerloop ; pidx++) {
      _class_particle particleN = mcgenstate(); // initial particle
      _class_particle* _particle = &particleN;
      particleN._uid = pidx;
      #ifdef USE_MPI
      particleN._uid += mpi_node_rank * ncount; 
      #endif

      srandom(_hash((pidx+1)*(seed+1)));

      raytrace(_particle);
    } /* inner for */
    seed = seed+gpu_innerloop;
  } /* CPU for */
  /* if on GPU, printf has been globally nullified, re-enable here */
     #ifdef OPENACC
     #undef strlen
     #undef strcmp
     #undef exit
     #undef printf
     #undef sprintf
     #undef fprintf
     #endif
  MPI_MASTER(
  printf("*** TRACE end *** \n");
  );
} /* raytrace_all */

#endif //no-FUNNEL

#ifdef FUNNEL
// Alternative raytrace algorithm which iterates all particles through
// one component at the time, can remove absorbs from the next loop and
// switch between cpu/gpu.
void raytrace_all_funnel(unsigned long long ncount, unsigned long seed) {

  // set up outer (CPU) loop / particle batches
  unsigned long long loops;

  /* if on GPU, printf has been globally nullified, re-enable here */
   #ifdef OPENACC
   #undef strlen
   #undef strcmp
   #undef exit
   #undef printf
   #undef sprintf
   #undef fprintf
   #endif
  #ifdef OPENACC
  loops = ceil((double)ncount/gpu_innerloop);
  if (ncount>gpu_innerloop) {
    printf("Defining %llu CPU loops around kernel and adjusting ncount\n",loops);
    mcset_ncount(loops*gpu_innerloop);
  } else {
  #endif
    loops=1;
    gpu_innerloop = ncount;
  #ifdef OPENACC
  }
  #endif

  // create particles struct and pointer arrays (same memory used by all batches)
  _class_particle* particles = malloc(gpu_innerloop*sizeof(_class_particle));
  _class_particle* pbuffer = malloc(gpu_innerloop*sizeof(_class_particle));
  long livebatchsize = gpu_innerloop;

  #undef ABSORB0
  #undef ABSORB
  #define ABSORB0 do { DEBUG_ABSORB(); MAGNET_OFF; ABSORBED++; } while(0)
  #define ABSORB ABSORB0
  // outer loop / particle batches
  for (unsigned long long cloop=0; cloop<loops; cloop++) {
    if (loops>1) fprintf(stdout, "%d..", (int)cloop); fflush(stdout);

    // init particles
    #pragma acc parallel loop present(particles[0:livebatchsize])
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      // generate particle state, set loop index and seed
      particles[pidx] = mcgenstate();
      _class_particle* _particle = particles + pidx;
      _particle->_uid = pidx;
      #ifdef USE_MPI
      _particle->_uid += mpi_node_rank * ncount; 
      #endif
      srandom(_hash((pidx+1)*(seed+1))); // _particle->state usage built into srandom macro
    }

    // iterate components

    #pragma acc parallel loop present(particles[0:livebatchsize])
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      _class_particle* _particle = &particles[pidx];
      _class_particle _particle_save;

      // Origin
    if (!ABSORBED && _particle->_index == 1) {
        _particle->_index++;
      }

      // SourceMantid
    if (!ABSORBED && _particle->_index == 2) {
#ifndef MULTICORE
        if (_SourceMantid_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _SourceMantid_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_SourceMantid_var._position_relative, _SourceMantid_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Commodus_I3_trace(&_SourceMantid_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // shutter
    if (!ABSORBED && _particle->_index == 3) {
#ifndef MULTICORE
        if (_shutter_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _shutter_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_shutter_var._position_relative, _shutter_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_shutter_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // insert
    if (!ABSORBED && _particle->_index == 4) {
#ifndef MULTICORE
        if (_insert_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _insert_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_insert_var._position_relative, _insert_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_insert_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // after_insert
    if (!ABSORBED && _particle->_index == 5) {
#ifndef MULTICORE
        if (_after_insert_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _after_insert_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_after_insert_var._position_relative, _after_insert_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_after_insert_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // Monitor1
    if (!ABSORBED && _particle->_index == 6) {
#ifndef MULTICORE
        if (_Monitor1_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Monitor1_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Monitor1_var._position_relative, _Monitor1_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN
        class_TOF_monitor_trace(&_Monitor1_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // LET_Chopper1_disk1
    if (!ABSORBED && _particle->_index == 7) {
#ifndef MULTICORE
        if (_LET_Chopper1_disk1_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper1_disk1_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_LET_Chopper1_disk1_var._position_relative, _LET_Chopper1_disk1_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_DiskChopper_trace(&_LET_Chopper1_disk1_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // LET_Chopper1_disk2
    if (!ABSORBED && _particle->_index == 8) {
#ifndef MULTICORE
        if (_LET_Chopper1_disk2_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper1_disk2_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_LET_Chopper1_disk2_var._position_relative, _LET_Chopper1_disk2_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_DiskChopper_trace(&_LET_Chopper1_disk2_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // Monitor2
    if (!ABSORBED && _particle->_index == 9) {
#ifndef MULTICORE
        if (_Monitor2_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Monitor2_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Monitor2_var._position_relative, _Monitor2_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN
        class_TOF_monitor_trace(&_Monitor2_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // between_chop1_and_chop2
    if (!ABSORBED && _particle->_index == 10) {
#ifndef MULTICORE
        if (_between_chop1_and_chop2_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _between_chop1_and_chop2_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_between_chop1_and_chop2_var._position_relative, _between_chop1_and_chop2_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_between_chop1_and_chop2_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // LET_Chopper2
    if (!ABSORBED && _particle->_index == 11) {
#ifndef MULTICORE
        if (_LET_Chopper2_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper2_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_LET_Chopper2_var._position_relative, _LET_Chopper2_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_DiskChopper_trace(&_LET_Chopper2_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // Monitor3
    if (!ABSORBED && _particle->_index == 12) {
#ifndef MULTICORE
        if (_Monitor3_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Monitor3_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Monitor3_var._position_relative, _Monitor3_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN
        class_TOF_monitor_trace(&_Monitor3_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // between_chop2_and_chop3
    if (!ABSORBED && _particle->_index == 13) {
#ifndef MULTICORE
        if (_between_chop2_and_chop3_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _between_chop2_and_chop3_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_between_chop2_and_chop3_var._position_relative, _between_chop2_and_chop3_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_between_chop2_and_chop3_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // LET_Chopper3
    if (!ABSORBED && _particle->_index == 14) {
#ifndef MULTICORE
        if (_LET_Chopper3_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper3_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_LET_Chopper3_var._position_relative, _LET_Chopper3_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_DiskChopper_trace(&_LET_Chopper3_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // Monitor4
    if (!ABSORBED && _particle->_index == 15) {
#ifndef MULTICORE
        if (_Monitor4_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Monitor4_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Monitor4_var._position_relative, _Monitor4_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN
        class_TOF_monitor_trace(&_Monitor4_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // between_chop3_and_chop4
    if (!ABSORBED && _particle->_index == 16) {
#ifndef MULTICORE
        if (_between_chop3_and_chop4_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _between_chop3_and_chop4_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_between_chop3_and_chop4_var._position_relative, _between_chop3_and_chop4_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_between_chop3_and_chop4_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // LET_Chopper4
    if (!ABSORBED && _particle->_index == 17) {
#ifndef MULTICORE
        if (_LET_Chopper4_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper4_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_LET_Chopper4_var._position_relative, _LET_Chopper4_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_DiskChopper_trace(&_LET_Chopper4_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // Monitor5
    if (!ABSORBED && _particle->_index == 18) {
#ifndef MULTICORE
        if (_Monitor5_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Monitor5_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Monitor5_var._position_relative, _Monitor5_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN
        class_TOF_monitor_trace(&_Monitor5_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // between_chop4_and_movable
    if (!ABSORBED && _particle->_index == 19) {
#ifndef MULTICORE
        if (_between_chop4_and_movable_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _between_chop4_and_movable_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_between_chop4_and_movable_var._position_relative, _between_chop4_and_movable_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_between_chop4_and_movable_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // moveable_front_PSDmon
    if (!ABSORBED && _particle->_index == 20) {
#ifndef MULTICORE
        if (_moveable_front_PSDmon_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _moveable_front_PSDmon_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_moveable_front_PSDmon_var._position_relative, _moveable_front_PSDmon_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.movable_monitors == 1 ))) // conditional WHEN
        class_PSD_monitor_trace(&_moveable_front_PSDmon_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // moveable_front_Divmon
    if (!ABSORBED && _particle->_index == 21) {
#ifndef MULTICORE
        if (_moveable_front_Divmon_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _moveable_front_Divmon_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_moveable_front_Divmon_var._position_relative, _moveable_front_Divmon_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.movable_monitors == 1 ))) // conditional WHEN
        class_Divergence_monitor_trace(&_moveable_front_Divmon_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // moveable_guide
    if (!ABSORBED && _particle->_index == 22) {
#ifndef MULTICORE
        if (_moveable_guide_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _moveable_guide_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_moveable_guide_var._position_relative, _moveable_guide_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_moveable_guide_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // moveable_back_PSDmon
    if (!ABSORBED && _particle->_index == 23) {
#ifndef MULTICORE
        if (_moveable_back_PSDmon_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _moveable_back_PSDmon_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_moveable_back_PSDmon_var._position_relative, _moveable_back_PSDmon_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.movable_monitors == 1 ))) // conditional WHEN
        class_PSD_monitor_trace(&_moveable_back_PSDmon_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // moveable_back_Divmon
    if (!ABSORBED && _particle->_index == 24) {
#ifndef MULTICORE
        if (_moveable_back_Divmon_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _moveable_back_Divmon_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_moveable_back_Divmon_var._position_relative, _moveable_back_Divmon_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.movable_monitors == 1 ))) // conditional WHEN
        class_Divergence_monitor_trace(&_moveable_back_Divmon_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // funnel
    if (!ABSORBED && _particle->_index == 25) {
#ifndef MULTICORE
        if (_funnel_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _funnel_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_funnel_var._position_relative, _funnel_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_funnel_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // LET_Chopper5_Disk1
    if (!ABSORBED && _particle->_index == 26) {
#ifndef MULTICORE
        if (_LET_Chopper5_Disk1_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper5_Disk1_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_LET_Chopper5_Disk1_var._position_relative, _LET_Chopper5_Disk1_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_DiskChopper_trace(&_LET_Chopper5_Disk1_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // LET_Chopper5_Disk2
    if (!ABSORBED && _particle->_index == 27) {
#ifndef MULTICORE
        if (_LET_Chopper5_Disk2_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _LET_Chopper5_Disk2_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_LET_Chopper5_Disk2_var._position_relative, _LET_Chopper5_Disk2_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_DiskChopper_trace(&_LET_Chopper5_Disk2_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // Monitor6
    if (!ABSORBED && _particle->_index == 28) {
#ifndef MULTICORE
        if (_Monitor6_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Monitor6_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Monitor6_var._position_relative, _Monitor6_var._rotation_relative, _particle);
        _particle_save = *_particle;
        if ((( _instrument_var._parameters.monitors_on == 1 ))) // conditional WHEN
        class_TOF_monitor_trace(&_Monitor6_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // tanksection
    if (!ABSORBED && _particle->_index == 29) {
#ifndef MULTICORE
        if (_tanksection_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _tanksection_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_tanksection_var._position_relative, _tanksection_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_tanksection_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // snout
    if (!ABSORBED && _particle->_index == 30) {
#ifndef MULTICORE
        if (_snout_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _snout_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_snout_var._position_relative, _snout_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Guide_channeled_trace(&_snout_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // sample
    if (!ABSORBED && _particle->_index == 31) {
        _particle->_index++;
      }

      // sample_PSDmon
    if (!ABSORBED && _particle->_index == 32) {
#ifndef MULTICORE
        if (_sample_PSDmon_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_PSDmon_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_PSDmon_var._position_relative, _sample_PSDmon_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_trace(&_sample_PSDmon_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // sample_Divmon
    if (!ABSORBED && _particle->_index == 33) {
#ifndef MULTICORE
        if (_sample_Divmon_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_Divmon_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_Divmon_var._position_relative, _sample_Divmon_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Divergence_monitor_trace(&_sample_Divmon_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // sample_tof
    if (!ABSORBED && _particle->_index == 34) {
#ifndef MULTICORE
        if (_sample_tof_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_tof_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_tof_var._position_relative, _sample_tof_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_TOF_monitor_trace(&_sample_tof_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // sample_Emon
    if (!ABSORBED && _particle->_index == 35) {
#ifndef MULTICORE
        if (_sample_Emon_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_Emon_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_Emon_var._position_relative, _sample_Emon_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_E_monitor_trace(&_sample_Emon_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // iso_samp
    if (!ABSORBED && _particle->_index == 36) {
#ifndef MULTICORE
        if (_iso_samp_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _iso_samp_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_iso_samp_var._position_relative, _iso_samp_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Isotropic_Sqw_trace(&_iso_samp_var, _particle); /* contains EXTEND code */
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // detectorArm
    if (!ABSORBED && _particle->_index == 37) {
        _particle->_index++;
      }

      // Banana_1
    if (!ABSORBED && _particle->_index == 38) {
#ifndef MULTICORE
        if (_Banana_1_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Banana_1_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Banana_1_var._position_relative, _Banana_1_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Monitor_nD_trace(&_Banana_1_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

    }

    // jump to next viable seed
    seed = seed + gpu_innerloop;
  } // outer loop / particle batches

  free(particles);
  free(pbuffer);

  printf("\n");
} /* raytrace_all_funnel */
#endif // FUNNEL

#undef x
#undef y
#undef z
#undef vx
#undef vy
#undef vz
#undef t
#undef sx
#undef sy
#undef sz
#undef p
#undef mcgravitation
#undef mcMagnet
#undef allow_backprop
#undef _mctmp_a
#undef _mctmp_b
#undef _mctmp_c
#ifdef OPENACC
#undef strlen
#undef strcmp
#undef exit
#undef printf
#undef sprintf
#undef fprintf
#endif
#undef SCATTERED
#undef RESTORE
#undef RESTORE_NEUTRON
#undef STORE_NEUTRON
#undef ABSORBED
#undef ABSORB
#undef ABSORB0
/* *****************************************************************************
* instrument 'ISIS_LET_generated' and components SAVE
***************************************************************************** */

_class_TOF_monitor *class_TOF_monitor_save(_class_TOF_monitor *_comp
) {
  #define nt (_comp->_parameters.nt)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define tmin (_comp->_parameters.tmin)
  #define tmax (_comp->_parameters.tmax)
  #define dt (_comp->_parameters.dt)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define TOF_N (_comp->_parameters.TOF_N)
  #define TOF_p (_comp->_parameters.TOF_p)
  #define TOF_p2 (_comp->_parameters.TOF_p2)
  #define t_min (_comp->_parameters.t_min)
  #define t_max (_comp->_parameters.t_max)
  #define delta_t (_comp->_parameters.delta_t)
  SIG_MESSAGE("[_Monitor1_save] component Monitor1=TOF_monitor() SAVE [TOF_monitor:0]");

  if (!nowritefile) {
    DETECTOR_OUT_1D ("Time-of-flight monitor", "Time-of-flight [\\gms]", "Intensity", "t", t_min, t_max, nt, &TOF_N[0], &TOF_p[0], &TOF_p2[0], filename);
  }
  #undef nt
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef tmin
  #undef tmax
  #undef dt
  #undef restore_neutron
  #undef nowritefile
  #undef TOF_N
  #undef TOF_p
  #undef TOF_p2
  #undef t_min
  #undef t_max
  #undef delta_t
  return(_comp);
} /* class_TOF_monitor_save */

_class_PSD_monitor *class_PSD_monitor_save(_class_PSD_monitor *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_moveable_front_PSDmon_save] component moveable_front_PSDmon=PSD_monitor() SAVE [PSD_monitor:0]");

  if (!nowritefile) {
    DETECTOR_OUT_2D ("PSD monitor", "X position [cm]", "Y position [cm]", xmin * 100.0, xmax * 100.0, ymin * 100.0, ymax * 100.0, nx, ny, &PSD_N[0][0],
                     &PSD_p[0][0], &PSD_p2[0][0], filename);
  }
  #undef nx
  #undef ny
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef restore_neutron
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_save */

_class_Divergence_monitor *class_Divergence_monitor_save(_class_Divergence_monitor *_comp
) {
  #define nh (_comp->_parameters.nh)
  #define nv (_comp->_parameters.nv)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define maxdiv_h (_comp->_parameters.maxdiv_h)
  #define maxdiv_v (_comp->_parameters.maxdiv_v)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define nz (_comp->_parameters.nz)
  #define Div_N (_comp->_parameters.Div_N)
  #define Div_p (_comp->_parameters.Div_p)
  #define Div_p2 (_comp->_parameters.Div_p2)
  SIG_MESSAGE("[_moveable_front_Divmon_save] component moveable_front_Divmon=Divergence_monitor() SAVE [Divergence_monitor:0]");

  if (!nowritefile) {
    DETECTOR_OUT_2D ("Divergence monitor", "X divergence [deg]", "Y divergence [deg]", -maxdiv_h, maxdiv_h, -maxdiv_v, maxdiv_v, nh, nv, &Div_N[0][0],
                     &Div_p[0][0], &Div_p2[0][0], filename);
  }
  #undef nh
  #undef nv
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef nowritefile
  #undef xwidth
  #undef yheight
  #undef maxdiv_h
  #undef maxdiv_v
  #undef restore_neutron
  #undef nx
  #undef ny
  #undef nz
  #undef Div_N
  #undef Div_p
  #undef Div_p2
  return(_comp);
} /* class_Divergence_monitor_save */

_class_E_monitor *class_E_monitor_save(_class_E_monitor *_comp
) {
  #define nE (_comp->_parameters.nE)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define Emin (_comp->_parameters.Emin)
  #define Emax (_comp->_parameters.Emax)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define E_N (_comp->_parameters.E_N)
  #define E_p (_comp->_parameters.E_p)
  #define E_p2 (_comp->_parameters.E_p2)
  #define S_p (_comp->_parameters.S_p)
  #define S_pE (_comp->_parameters.S_pE)
  #define S_pE2 (_comp->_parameters.S_pE2)
  SIG_MESSAGE("[_sample_Emon_save] component sample_Emon=E_monitor() SAVE [E_monitor:0]");

  if (!nowritefile) {
    DETECTOR_OUT_1D ("Energy monitor", "Energy [meV]", "Intensity", "E", Emin, Emax, nE, &E_N[0], &E_p[0], &E_p2[0], filename);
    if (S_p)
      printf ("<E> : %g meV , E-width : %g meV \n", S_pE / S_p, sqrt (S_pE2 / S_p - S_pE * S_pE / (S_p * S_p)));
  }
  #undef nE
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef nowritefile
  #undef xwidth
  #undef yheight
  #undef Emin
  #undef Emax
  #undef restore_neutron
  #undef E_N
  #undef E_p
  #undef E_p2
  #undef S_p
  #undef S_pE
  #undef S_pE2
  return(_comp);
} /* class_E_monitor_save */

_class_Monitor_nD *class_Monitor_nD_save(_class_Monitor_nD *_comp
) {
  #define user1 (_comp->_parameters.user1)
  #define user2 (_comp->_parameters.user2)
  #define user3 (_comp->_parameters.user3)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define zmin (_comp->_parameters.zmin)
  #define zmax (_comp->_parameters.zmax)
  #define bins (_comp->_parameters.bins)
  #define min (_comp->_parameters.min)
  #define max (_comp->_parameters.max)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define radius (_comp->_parameters.radius)
  #define options (_comp->_parameters.options)
  #define filename (_comp->_parameters.filename)
  #define geometry (_comp->_parameters.geometry)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define nexus_bins (_comp->_parameters.nexus_bins)
  #define username1 (_comp->_parameters.username1)
  #define username2 (_comp->_parameters.username2)
  #define username3 (_comp->_parameters.username3)
  #define DEFS (_comp->_parameters.DEFS)
  #define Vars (_comp->_parameters.Vars)
  #define detector (_comp->_parameters.detector)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_Banana_1_save] component Banana_1=Monitor_nD() SAVE [Monitor_nD:0]");

  if (!nowritefile) {
    /* save results, but do not free pointers */
    detector = Monitor_nD_Save (&DEFS, &Vars);
  }
  #undef user1
  #undef user2
  #undef user3
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef zmin
  #undef zmax
  #undef bins
  #undef min
  #undef max
  #undef restore_neutron
  #undef radius
  #undef options
  #undef filename
  #undef geometry
  #undef nowritefile
  #undef nexus_bins
  #undef username1
  #undef username2
  #undef username3
  #undef DEFS
  #undef Vars
  #undef detector
  #undef offdata
  return(_comp);
} /* class_Monitor_nD_save */



int save(FILE *handle) { /* called by mccode_main for ISIS_LET_generated:SAVE */
  if (!handle) siminfo_init(NULL);

  /* call iteratively all components SAVE */





  class_TOF_monitor_save(&_Monitor1_var);



  class_TOF_monitor_save(&_Monitor2_var);



  class_TOF_monitor_save(&_Monitor3_var);



  class_TOF_monitor_save(&_Monitor4_var);



  class_TOF_monitor_save(&_Monitor5_var);


  class_PSD_monitor_save(&_moveable_front_PSDmon_var);

  class_Divergence_monitor_save(&_moveable_front_Divmon_var);


  class_PSD_monitor_save(&_moveable_back_PSDmon_var);

  class_Divergence_monitor_save(&_moveable_back_Divmon_var);




  class_TOF_monitor_save(&_Monitor6_var);




  class_PSD_monitor_save(&_sample_PSDmon_var);

  class_Divergence_monitor_save(&_sample_Divmon_var);

  class_TOF_monitor_save(&_sample_tof_var);

  class_E_monitor_save(&_sample_Emon_var);



  class_Monitor_nD_save(&_Banana_1_var);

  if (!handle) siminfo_close(); 

  return(0);
} /* save */

/* *****************************************************************************
* instrument 'ISIS_LET_generated' and components FINALLY
***************************************************************************** */

_class_TOF_monitor *class_TOF_monitor_finally(_class_TOF_monitor *_comp
) {
  #define nt (_comp->_parameters.nt)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define tmin (_comp->_parameters.tmin)
  #define tmax (_comp->_parameters.tmax)
  #define dt (_comp->_parameters.dt)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define TOF_N (_comp->_parameters.TOF_N)
  #define TOF_p (_comp->_parameters.TOF_p)
  #define TOF_p2 (_comp->_parameters.TOF_p2)
  #define t_min (_comp->_parameters.t_min)
  #define t_max (_comp->_parameters.t_max)
  #define delta_t (_comp->_parameters.delta_t)
  SIG_MESSAGE("[_Monitor1_finally] component Monitor1=TOF_monitor() FINALLY [TOF_monitor:0]");

  destroy_darr1d (TOF_N);
  destroy_darr1d (TOF_p);
  destroy_darr1d (TOF_p2);
  #undef nt
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef tmin
  #undef tmax
  #undef dt
  #undef restore_neutron
  #undef nowritefile
  #undef TOF_N
  #undef TOF_p
  #undef TOF_p2
  #undef t_min
  #undef t_max
  #undef delta_t
  return(_comp);
} /* class_TOF_monitor_finally */

_class_PSD_monitor *class_PSD_monitor_finally(_class_PSD_monitor *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_moveable_front_PSDmon_finally] component moveable_front_PSDmon=PSD_monitor() FINALLY [PSD_monitor:0]");

  destroy_darr2d(PSD_N);
  destroy_darr2d(PSD_p);
  destroy_darr2d(PSD_p2);
  #undef nx
  #undef ny
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef restore_neutron
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_finally */

_class_Divergence_monitor *class_Divergence_monitor_finally(_class_Divergence_monitor *_comp
) {
  #define nh (_comp->_parameters.nh)
  #define nv (_comp->_parameters.nv)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define maxdiv_h (_comp->_parameters.maxdiv_h)
  #define maxdiv_v (_comp->_parameters.maxdiv_v)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define nz (_comp->_parameters.nz)
  #define Div_N (_comp->_parameters.Div_N)
  #define Div_p (_comp->_parameters.Div_p)
  #define Div_p2 (_comp->_parameters.Div_p2)
  SIG_MESSAGE("[_moveable_front_Divmon_finally] component moveable_front_Divmon=Divergence_monitor() FINALLY [Divergence_monitor:0]");

  destroy_darr2d (Div_N);
  destroy_darr2d (Div_p);
  destroy_darr2d (Div_p2);
  #undef nh
  #undef nv
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef nowritefile
  #undef xwidth
  #undef yheight
  #undef maxdiv_h
  #undef maxdiv_v
  #undef restore_neutron
  #undef nx
  #undef ny
  #undef nz
  #undef Div_N
  #undef Div_p
  #undef Div_p2
  return(_comp);
} /* class_Divergence_monitor_finally */

_class_E_monitor *class_E_monitor_finally(_class_E_monitor *_comp
) {
  #define nE (_comp->_parameters.nE)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define Emin (_comp->_parameters.Emin)
  #define Emax (_comp->_parameters.Emax)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define E_N (_comp->_parameters.E_N)
  #define E_p (_comp->_parameters.E_p)
  #define E_p2 (_comp->_parameters.E_p2)
  #define S_p (_comp->_parameters.S_p)
  #define S_pE (_comp->_parameters.S_pE)
  #define S_pE2 (_comp->_parameters.S_pE2)
  SIG_MESSAGE("[_sample_Emon_finally] component sample_Emon=E_monitor() FINALLY [E_monitor:0]");

  destroy_darr1d (E_N);
  destroy_darr1d (E_p);
  destroy_darr1d (E_p2);
  #undef nE
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef nowritefile
  #undef xwidth
  #undef yheight
  #undef Emin
  #undef Emax
  #undef restore_neutron
  #undef E_N
  #undef E_p
  #undef E_p2
  #undef S_p
  #undef S_pE
  #undef S_pE2
  return(_comp);
} /* class_E_monitor_finally */

_class_Isotropic_Sqw *class_Isotropic_Sqw_finally(_class_Isotropic_Sqw *_comp
) {
  #define powder_format (_comp->_parameters.powder_format)
  #define Sqw_coh (_comp->_parameters.Sqw_coh)
  #define Sqw_inc (_comp->_parameters.Sqw_inc)
  #define geometry (_comp->_parameters.geometry)
  #define radius (_comp->_parameters.radius)
  #define thickness (_comp->_parameters.thickness)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define threshold (_comp->_parameters.threshold)
  #define order (_comp->_parameters.order)
  #define T (_comp->_parameters.T)
  #define verbose (_comp->_parameters.verbose)
  #define d_phi (_comp->_parameters.d_phi)
  #define concentric (_comp->_parameters.concentric)
  #define rho (_comp->_parameters.rho)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_coh (_comp->_parameters.sigma_coh)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define classical (_comp->_parameters.classical)
  #define powder_Dd (_comp->_parameters.powder_Dd)
  #define powder_DW (_comp->_parameters.powder_DW)
  #define powder_Vc (_comp->_parameters.powder_Vc)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define p_interact (_comp->_parameters.p_interact)
  #define norm (_comp->_parameters.norm)
  #define powder_barns (_comp->_parameters.powder_barns)
  #define quantum_correction (_comp->_parameters.quantum_correction)
  #define VarSqw (_comp->_parameters.VarSqw)
  #define columns (_comp->_parameters.columns)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_iso_samp_finally] component iso_samp=Isotropic_Sqw() FINALLY [Isotropic_Sqw:0]");

  int k;

  if (VarSqw.s_coh > 0 || VarSqw.s_inc > 0)
    for (k = 0; k < 2; k++) {
      struct Sqw_Data_struct Data_sqw;

      Data_sqw = (k == 0 ? VarSqw.Data_coh : VarSqw.Data_inc);
      /* Data_sqw->Sqw has already been freed at end of INIT */
      Table_Free (&(Data_sqw.iqSq));

      if (Data_sqw.SW)
        free (Data_sqw.SW);
      if (Data_sqw.SQW)
        free (Data_sqw.SQW);
      if (Data_sqw.SW_lookup)
        free (Data_sqw.SW_lookup);
      if (Data_sqw.QW_lookup)
        free (Data_sqw.QW_lookup);
    } /* end for */

  #ifdef USE_MPI
  if (mpi_node_count > 1) {
    double tmp;
    tmp = (double)VarSqw.neutron_removed;
    mc_MPI_Sum (&tmp, 1);
    VarSqw.neutron_removed = (long)tmp;
    tmp = (double)VarSqw.neutron_exit;
    mc_MPI_Sum (&tmp, 1);
    VarSqw.neutron_exit = (long)tmp;
    tmp = (double)VarSqw.neutron_pmult;
    mc_MPI_Sum (&tmp, 1);
    VarSqw.neutron_pmult = (long)tmp;
    mc_MPI_Sum (&VarSqw.mean_scatt, 1);
    mc_MPI_Sum (&VarSqw.psum_scatt, 1);
    mc_MPI_Sum (&VarSqw.mean_abs, 1);
    mc_MPI_Sum (&VarSqw.single_coh, 1);
    mc_MPI_Sum (&VarSqw.single_inc, 1);
    mc_MPI_Sum (&VarSqw.multi, 1);
  }
  #endif
  MPI_MASTER(
    if (VarSqw.neutron_removed)
      printf("Isotropic_Sqw: %s: %li neutron events (out of %li) that should have\n"
             "               scattered were transmitted because scattering conditions\n"
             "WARNING        could not be satisfied after %i tries.\n",
            NAME_CURRENT_COMP, VarSqw.neutron_removed,
            VarSqw.neutron_exit+VarSqw.neutron_removed, VarSqw.maxloop);
    if (VarSqw.neutron_pmult)
      printf("Isotropic_Sqw: %s: %li neutron events (out of %li) reached\n"
             "WARNING        unrealistic weight. The S(q,w) norm might be too high.\n",
            NAME_CURRENT_COMP, VarSqw.neutron_pmult, VarSqw.neutron_exit);

    if (VarSqw.verbose_output >= 1 && VarSqw.psum_scatt > 0) {
      printf ("Isotropic_Sqw: %s: Scattering fraction=%g of incoming intensity\n"
	      "               Absorption fraction           =%g\n",
	      NAME_CURRENT_COMP, VarSqw.mean_scatt / VarSqw.psum_scatt, VarSqw.mean_abs / VarSqw.psum_scatt);
      printf ("               Single   scattering intensity =%g (coh=%g inc=%g)\n"
	      "               Multiple scattering intensity =%g\n",
	      VarSqw.single_coh + VarSqw.single_inc, VarSqw.single_coh, VarSqw.single_inc, VarSqw.multi);
    }
  );
  /* end FINALLY */
  #undef powder_format
  #undef Sqw_coh
  #undef Sqw_inc
  #undef geometry
  #undef radius
  #undef thickness
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef threshold
  #undef order
  #undef T
  #undef verbose
  #undef d_phi
  #undef concentric
  #undef rho
  #undef sigma_abs
  #undef sigma_coh
  #undef sigma_inc
  #undef classical
  #undef powder_Dd
  #undef powder_DW
  #undef powder_Vc
  #undef density
  #undef weight
  #undef p_interact
  #undef norm
  #undef powder_barns
  #undef quantum_correction
  #undef VarSqw
  #undef columns
  #undef offdata
  return(_comp);
} /* class_Isotropic_Sqw_finally */

_class_Monitor_nD *class_Monitor_nD_finally(_class_Monitor_nD *_comp
) {
  #define user1 (_comp->_parameters.user1)
  #define user2 (_comp->_parameters.user2)
  #define user3 (_comp->_parameters.user3)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define zmin (_comp->_parameters.zmin)
  #define zmax (_comp->_parameters.zmax)
  #define bins (_comp->_parameters.bins)
  #define min (_comp->_parameters.min)
  #define max (_comp->_parameters.max)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define radius (_comp->_parameters.radius)
  #define options (_comp->_parameters.options)
  #define filename (_comp->_parameters.filename)
  #define geometry (_comp->_parameters.geometry)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define nexus_bins (_comp->_parameters.nexus_bins)
  #define username1 (_comp->_parameters.username1)
  #define username2 (_comp->_parameters.username2)
  #define username3 (_comp->_parameters.username3)
  #define DEFS (_comp->_parameters.DEFS)
  #define Vars (_comp->_parameters.Vars)
  #define detector (_comp->_parameters.detector)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_Banana_1_finally] component Banana_1=Monitor_nD() FINALLY [Monitor_nD:0]");

  /* free pointers */
  Monitor_nD_Finally (&DEFS, &Vars);
  #undef user1
  #undef user2
  #undef user3
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef zmin
  #undef zmax
  #undef bins
  #undef min
  #undef max
  #undef restore_neutron
  #undef radius
  #undef options
  #undef filename
  #undef geometry
  #undef nowritefile
  #undef nexus_bins
  #undef username1
  #undef username2
  #undef username3
  #undef DEFS
  #undef Vars
  #undef detector
  #undef offdata
  return(_comp);
} /* class_Monitor_nD_finally */



int finally(void) { /* called by mccode_main for ISIS_LET_generated:FINALLY */
#pragma acc update host(_Origin_var)
#pragma acc update host(_SourceMantid_var)
#pragma acc update host(_shutter_var)
#pragma acc update host(_insert_var)
#pragma acc update host(_after_insert_var)
#pragma acc update host(_Monitor1_var)
#pragma acc update host(_LET_Chopper1_disk1_var)
#pragma acc update host(_LET_Chopper1_disk2_var)
#pragma acc update host(_Monitor2_var)
#pragma acc update host(_between_chop1_and_chop2_var)
#pragma acc update host(_LET_Chopper2_var)
#pragma acc update host(_Monitor3_var)
#pragma acc update host(_between_chop2_and_chop3_var)
#pragma acc update host(_LET_Chopper3_var)
#pragma acc update host(_Monitor4_var)
#pragma acc update host(_between_chop3_and_chop4_var)
#pragma acc update host(_LET_Chopper4_var)
#pragma acc update host(_Monitor5_var)
#pragma acc update host(_between_chop4_and_movable_var)
#pragma acc update host(_moveable_front_PSDmon_var)
#pragma acc update host(_moveable_front_Divmon_var)
#pragma acc update host(_moveable_guide_var)
#pragma acc update host(_moveable_back_PSDmon_var)
#pragma acc update host(_moveable_back_Divmon_var)
#pragma acc update host(_funnel_var)
#pragma acc update host(_LET_Chopper5_Disk1_var)
#pragma acc update host(_LET_Chopper5_Disk2_var)
#pragma acc update host(_Monitor6_var)
#pragma acc update host(_tanksection_var)
#pragma acc update host(_snout_var)
#pragma acc update host(_sample_var)
#pragma acc update host(_sample_PSDmon_var)
#pragma acc update host(_sample_Divmon_var)
#pragma acc update host(_sample_tof_var)
#pragma acc update host(_sample_Emon_var)
#pragma acc update host(_iso_samp_var)
#pragma acc update host(_detectorArm_var)
#pragma acc update host(_Banana_1_var)
#pragma acc update host(_instrument_var)

  siminfo_init(NULL);
  save(siminfo_file); /* save data when simulation ends */

  /* Instrument 'ISIS_LET_generated' FINALLY */
  SIG_MESSAGE("[ISIS_LET_generated] FINALLY [(null):-1]");
  #define Ei (instrument->_parameters.Ei)
  #define dE (instrument->_parameters.dE)
  #define Ch3_speed (instrument->_parameters.Ch3_speed)
  #define Ch5_speed (instrument->_parameters.Ch5_speed)
  #define Ch2_phase (instrument->_parameters.Ch2_phase)
  #define pha_offset (instrument->_parameters.pha_offset)
  #define res (instrument->_parameters.res)
  #define snout (instrument->_parameters.snout)
  #define monitors_on (instrument->_parameters.monitors_on)
  #define movable_monitors (instrument->_parameters.movable_monitors)
  #define sample_coh (instrument->_parameters.sample_coh)
  #define sample_inc (instrument->_parameters.sample_inc)
{
// Start of finally for generated ISIS_LET_generated
}
  #undef Ei
  #undef dE
  #undef Ch3_speed
  #undef Ch5_speed
  #undef Ch2_phase
  #undef pha_offset
  #undef res
  #undef snout
  #undef monitors_on
  #undef movable_monitors
  #undef sample_coh
  #undef sample_inc
  /* call iteratively all components FINALLY */





  class_TOF_monitor_finally(&_Monitor1_var);



  class_TOF_monitor_finally(&_Monitor2_var);



  class_TOF_monitor_finally(&_Monitor3_var);



  class_TOF_monitor_finally(&_Monitor4_var);



  class_TOF_monitor_finally(&_Monitor5_var);


  class_PSD_monitor_finally(&_moveable_front_PSDmon_var);

  class_Divergence_monitor_finally(&_moveable_front_Divmon_var);


  class_PSD_monitor_finally(&_moveable_back_PSDmon_var);

  class_Divergence_monitor_finally(&_moveable_back_Divmon_var);




  class_TOF_monitor_finally(&_Monitor6_var);




  class_PSD_monitor_finally(&_sample_PSDmon_var);

  class_Divergence_monitor_finally(&_sample_Divmon_var);

  class_TOF_monitor_finally(&_sample_tof_var);

  class_E_monitor_finally(&_sample_Emon_var);

  class_Isotropic_Sqw_finally(&_iso_samp_var);


  class_Monitor_nD_finally(&_Banana_1_var);

  siminfo_close(); 

  return(0);
} /* finally */

/* *****************************************************************************
* instrument 'ISIS_LET_generated' and components DISPLAY
***************************************************************************** */

  #define magnify     mcdis_magnify
  #define line        mcdis_line
  #define dashed_line mcdis_dashed_line
  #define multiline   mcdis_multiline
  #define rectangle   mcdis_rectangle
  #define box         mcdis_box
  #define circle      mcdis_circle
  #define cylinder    mcdis_cylinder
  #define sphere      mcdis_sphere
  #define cone        mcdis_cone
  #define polygon     mcdis_polygon
  #define polyhedron  mcdis_polyhedron
_class_Arm *class_Arm_display(_class_Arm *_comp
) {
  SIG_MESSAGE("[_Origin_display] component Origin=Arm() DISPLAY [Arm:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  /* A bit ugly; hard-coded dimensions. */

  line (0, 0, 0, 0.2, 0, 0);
  line (0, 0, 0, 0, 0.2, 0);
  line (0, 0, 0, 0, 0, 0.2);

  cone (0.2, 0, 0, 0.01, 0.02, 1, 0, 0);
  cone (0, 0.2, 0, 0.01, 0.02, 0, 1, 0);
  cone (0, 0, 0.2, 0.01, 0.02, 0, 0, 1);
  return(_comp);
} /* class_Arm_display */

_class_Commodus_I3 *class_Commodus_I3_display(_class_Commodus_I3 *_comp
) {
  #define Face (_comp->_parameters.Face)
  #define E0 (_comp->_parameters.E0)
  #define E1 (_comp->_parameters.E1)
  #define modPosition (_comp->_parameters.modPosition)
  #define dist (_comp->_parameters.dist)
  #define verbose (_comp->_parameters.verbose)
  #define beamcurrent (_comp->_parameters.beamcurrent)
  #define modXsize (_comp->_parameters.modXsize)
  #define modZsize (_comp->_parameters.modZsize)
  #define xw (_comp->_parameters.xw)
  #define yh (_comp->_parameters.yh)
  #define p_in (_comp->_parameters.p_in)
  #define Tnpts (_comp->_parameters.Tnpts)
  #define scaleSize (_comp->_parameters.scaleSize)
  #define angleArea (_comp->_parameters.angleArea)
  #define Nsim (_comp->_parameters.Nsim)
  #define Ncount (_comp->_parameters.Ncount)
  #define TS (_comp->_parameters.TS)
  #define fullAngle (_comp->_parameters.fullAngle)
  #define rtE0 (_comp->_parameters.rtE0)
  #define rtE1 (_comp->_parameters.rtE1)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define focus_xw (_comp->_parameters.focus_xw)
  #define focus_yh (_comp->_parameters.focus_yh)
  SIG_MESSAGE("[_SourceMantid_display] component SourceMantid=Commodus_I3() DISPLAY [Commodus_I3:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  double cirp = 0.0, cirq = 0.3, pi = 3.141592654;
  int pp = 0; /* circle drawing parameter*/

  magnify ("xy");
  multiline (5, -0.5 * TS.XAxis, -0.5 * TS.ZAxis, 0.0, 0.5 * TS.XAxis, -0.5 * TS.ZAxis, 0.0, 0.5 * TS.XAxis, 0.5 * TS.ZAxis, 0.0, -0.5 * TS.XAxis, 0.5 * TS.ZAxis,
             0.0, -0.5 * TS.XAxis, -0.5 * TS.ZAxis, 0.0);
  /* circle("xy",0.0,0.0,0.0,cos(cirp)); */

  /*line(0.5*sin(cirp),0.0,0.5*cos(cirp),0.5*sin(cirq),0.0,0.5*cos(cirq));*/

  /*line(-0.5,0.0,0.0,0.0,0.0,0.5);*/

  for (pp = 0; pp <= 20; pp = pp + 2) {
    cirp = (pp * (pi / 21.0)) - (0.5 * pi);
    cirq = ((pp + 1) * (pi / 21.0)) - (0.5 * pi);
    line (0.5 * sin (cirp), 0.0, 0.5 * cos (cirp), 0.5 * sin (cirq), 0.0, 0.5 * cos (cirq));
  }
  #undef Face
  #undef E0
  #undef E1
  #undef modPosition
  #undef dist
  #undef verbose
  #undef beamcurrent
  #undef modXsize
  #undef modZsize
  #undef xw
  #undef yh
  #undef p_in
  #undef Tnpts
  #undef scaleSize
  #undef angleArea
  #undef Nsim
  #undef Ncount
  #undef TS
  #undef fullAngle
  #undef rtE0
  #undef rtE1
  #undef xwidth
  #undef yheight
  #undef focus_xw
  #undef focus_yh
  return(_comp);
} /* class_Commodus_I3_display */

_class_Guide_channeled *class_Guide_channeled_display(_class_Guide_channeled *_comp
) {
  #define w1 (_comp->_parameters.w1)
  #define h1 (_comp->_parameters.h1)
  #define w2 (_comp->_parameters.w2)
  #define h2 (_comp->_parameters.h2)
  #define l (_comp->_parameters.l)
  #define R0 (_comp->_parameters.R0)
  #define Qc (_comp->_parameters.Qc)
  #define alpha (_comp->_parameters.alpha)
  #define m (_comp->_parameters.m)
  #define nslit (_comp->_parameters.nslit)
  #define d (_comp->_parameters.d)
  #define Qcx (_comp->_parameters.Qcx)
  #define Qcy (_comp->_parameters.Qcy)
  #define alphax (_comp->_parameters.alphax)
  #define alphay (_comp->_parameters.alphay)
  #define W (_comp->_parameters.W)
  #define mx (_comp->_parameters.mx)
  #define my (_comp->_parameters.my)
  #define nu (_comp->_parameters.nu)
  #define phase (_comp->_parameters.phase)
  #define w1c (_comp->_parameters.w1c)
  #define w2c (_comp->_parameters.w2c)
  #define ww (_comp->_parameters.ww)
  #define hh (_comp->_parameters.hh)
  #define whalf (_comp->_parameters.whalf)
  #define hhalf (_comp->_parameters.hhalf)
  #define lwhalf (_comp->_parameters.lwhalf)
  #define lhhalf (_comp->_parameters.lhhalf)
  SIG_MESSAGE("[_shutter_display] component shutter=Guide_channeled() DISPLAY [Guide_channeled:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  int i;

  /* Draw the vertial slit-planes along each channel */
  for (i = 0; i < nslit; i++) {
    polygon (4, i * w1c - w1 / 2.0, -h1 / 2.0, 0.0, i * w2c - w2 / 2.0, -h2 / 2.0, (double)l, i * w2c - w2 / 2.0, h2 / 2.0, (double)l, i * w1c - w1 / 2.0,
             h1 / 2.0, 0.0);
    polygon (4, (i + 1) * w1c - d - w1 / 2.0, -h1 / 2.0, 0.0, (i + 1) * w2c - d - w2 / 2.0, -h2 / 2.0, (double)l, (i + 1) * w2c - d - w2 / 2.0, h2 / 2.0,
             (double)l, (i + 1) * w1c - d - w1 / 2.0, h1 / 2.0, 0.0);
  }
  /* Add "bottom" and "lid" */
  polygon (4, -w1 / 2.0, -h1 / 2.0, 0.0, w1 / 2.0, -h1 / 2.0, 0.0, w2 / 2.0, -h2 / 2.0, (double)l, -w2 / 2.0, -h2 / 2.0, (double)l);
  polygon (4, -w1 / 2.0, h1 / 2.0, 0.0, w1 / 2.0, h1 / 2.0, 0.0, w2 / 2.0, h2 / 2.0, (double)l, -w2 / 2.0, h2 / 2.0, (double)l);

  if (nu || phase) {
    double radius = sqrt (w1 * w1 + l * l);
    /* cylinder top/center/bottom  */
    circle ("xz", 0, -h1 / 2, l / 2, radius);
    circle ("xz", 0, 0, l / 2, radius);
    circle ("xz", 0, h1 / 2, l / 2, radius);
  }
  #undef w1
  #undef h1
  #undef w2
  #undef h2
  #undef l
  #undef R0
  #undef Qc
  #undef alpha
  #undef m
  #undef nslit
  #undef d
  #undef Qcx
  #undef Qcy
  #undef alphax
  #undef alphay
  #undef W
  #undef mx
  #undef my
  #undef nu
  #undef phase
  #undef w1c
  #undef w2c
  #undef ww
  #undef hh
  #undef whalf
  #undef hhalf
  #undef lwhalf
  #undef lhhalf
  return(_comp);
} /* class_Guide_channeled_display */

_class_TOF_monitor *class_TOF_monitor_display(_class_TOF_monitor *_comp
) {
  #define nt (_comp->_parameters.nt)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define tmin (_comp->_parameters.tmin)
  #define tmax (_comp->_parameters.tmax)
  #define dt (_comp->_parameters.dt)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define TOF_N (_comp->_parameters.TOF_N)
  #define TOF_p (_comp->_parameters.TOF_p)
  #define TOF_p2 (_comp->_parameters.TOF_p2)
  #define t_min (_comp->_parameters.t_min)
  #define t_max (_comp->_parameters.t_max)
  #define delta_t (_comp->_parameters.delta_t)
  SIG_MESSAGE("[_Monitor1_display] component Monitor1=TOF_monitor() DISPLAY [TOF_monitor:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  multiline (5, (double)xmin, (double)ymin, 0.0, (double)xmax, (double)ymin, 0.0, (double)xmax, (double)ymax, 0.0, (double)xmin, (double)ymax, 0.0, (double)xmin,
             (double)ymin, 0.0);
  #undef nt
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef tmin
  #undef tmax
  #undef dt
  #undef restore_neutron
  #undef nowritefile
  #undef TOF_N
  #undef TOF_p
  #undef TOF_p2
  #undef t_min
  #undef t_max
  #undef delta_t
  return(_comp);
} /* class_TOF_monitor_display */

_class_DiskChopper *class_DiskChopper_display(_class_DiskChopper *_comp
) {
  #define theta_0 (_comp->_parameters.theta_0)
  #define radius (_comp->_parameters.radius)
  #define yheight (_comp->_parameters.yheight)
  #define nu (_comp->_parameters.nu)
  #define nslit (_comp->_parameters.nslit)
  #define jitter (_comp->_parameters.jitter)
  #define delay (_comp->_parameters.delay)
  #define isfirst (_comp->_parameters.isfirst)
  #define n_pulse (_comp->_parameters.n_pulse)
  #define abs_out (_comp->_parameters.abs_out)
  #define phase (_comp->_parameters.phase)
  #define xwidth (_comp->_parameters.xwidth)
  #define verbose (_comp->_parameters.verbose)
  #define Tg (_comp->_parameters.Tg)
  #define To (_comp->_parameters.To)
  #define delta_y (_comp->_parameters.delta_y)
  #define height (_comp->_parameters.height)
  #define omega (_comp->_parameters.omega)
  SIG_MESSAGE("[_LET_Chopper1_disk1_display] component LET_Chopper1_disk1=DiskChopper() DISPLAY [DiskChopper:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  int j;
  /* Arrays for storing geometry of slit/beamstop */

  circle ("xy", 0, -delta_y, 0, radius);

  /* Drawing the slit(s) */
  for (j = 0; j < nslit; j++) {
    /* Angular start/end of slit */
    double tmin = j * (2.0 * PI / nslit) - theta_0 / 2.0 + phase;
    double tmax = tmin + theta_0;
    /* Draw lines for each slit. */

    line (radius * sin (tmin), radius * cos (tmin) - delta_y, 0, (radius - height) * sin (tmin), (radius - height) * cos (tmin) - delta_y, 0);
    line ((radius - height) * sin (tmin), (radius - height) * cos (tmin) - delta_y, 0, (radius - height) * sin (tmax), (radius - height) * cos (tmax) - delta_y,
          0);
    line ((radius - height) * sin (tmax), (radius - height) * cos (tmax) - delta_y, 0, radius * sin (tmax), radius * cos (tmax) - delta_y, 0);
  }
  #undef theta_0
  #undef radius
  #undef yheight
  #undef nu
  #undef nslit
  #undef jitter
  #undef delay
  #undef isfirst
  #undef n_pulse
  #undef abs_out
  #undef phase
  #undef xwidth
  #undef verbose
  #undef Tg
  #undef To
  #undef delta_y
  #undef height
  #undef omega
  return(_comp);
} /* class_DiskChopper_display */

_class_PSD_monitor *class_PSD_monitor_display(_class_PSD_monitor *_comp
) {
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define PSD_N (_comp->_parameters.PSD_N)
  #define PSD_p (_comp->_parameters.PSD_p)
  #define PSD_p2 (_comp->_parameters.PSD_p2)
  SIG_MESSAGE("[_moveable_front_PSDmon_display] component moveable_front_PSDmon=PSD_monitor() DISPLAY [PSD_monitor:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  multiline (5, (double)xmin, (double)ymin, 0.0, (double)xmax, (double)ymin, 0.0, (double)xmax, (double)ymax, 0.0, (double)xmin, (double)ymax, 0.0, (double)xmin,
             (double)ymin, 0.0);
  #undef nx
  #undef ny
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef xwidth
  #undef yheight
  #undef restore_neutron
  #undef nowritefile
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_display */

_class_Divergence_monitor *class_Divergence_monitor_display(_class_Divergence_monitor *_comp
) {
  #define nh (_comp->_parameters.nh)
  #define nv (_comp->_parameters.nv)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define maxdiv_h (_comp->_parameters.maxdiv_h)
  #define maxdiv_v (_comp->_parameters.maxdiv_v)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define nx (_comp->_parameters.nx)
  #define ny (_comp->_parameters.ny)
  #define nz (_comp->_parameters.nz)
  #define Div_N (_comp->_parameters.Div_N)
  #define Div_p (_comp->_parameters.Div_p)
  #define Div_p2 (_comp->_parameters.Div_p2)
  SIG_MESSAGE("[_moveable_front_Divmon_display] component moveable_front_Divmon=Divergence_monitor() DISPLAY [Divergence_monitor:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  multiline (5, (double)xmin, (double)ymin, 0.0, (double)xmax, (double)ymin, 0.0, (double)xmax, (double)ymax, 0.0, (double)xmin, (double)ymax, 0.0, (double)xmin,
             (double)ymin, 0.0);
  #undef nh
  #undef nv
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef nowritefile
  #undef xwidth
  #undef yheight
  #undef maxdiv_h
  #undef maxdiv_v
  #undef restore_neutron
  #undef nx
  #undef ny
  #undef nz
  #undef Div_N
  #undef Div_p
  #undef Div_p2
  return(_comp);
} /* class_Divergence_monitor_display */

_class_E_monitor *class_E_monitor_display(_class_E_monitor *_comp
) {
  #define nE (_comp->_parameters.nE)
  #define filename (_comp->_parameters.filename)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define Emin (_comp->_parameters.Emin)
  #define Emax (_comp->_parameters.Emax)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define E_N (_comp->_parameters.E_N)
  #define E_p (_comp->_parameters.E_p)
  #define E_p2 (_comp->_parameters.E_p2)
  #define S_p (_comp->_parameters.S_p)
  #define S_pE (_comp->_parameters.S_pE)
  #define S_pE2 (_comp->_parameters.S_pE2)
  SIG_MESSAGE("[_sample_Emon_display] component sample_Emon=E_monitor() DISPLAY [E_monitor:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  multiline (5, (double)xmin, (double)ymin, 0.0, (double)xmax, (double)ymin, 0.0, (double)xmax, (double)ymax, 0.0, (double)xmin, (double)ymax, 0.0, (double)xmin,
             (double)ymin, 0.0);
  #undef nE
  #undef filename
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef nowritefile
  #undef xwidth
  #undef yheight
  #undef Emin
  #undef Emax
  #undef restore_neutron
  #undef E_N
  #undef E_p
  #undef E_p2
  #undef S_p
  #undef S_pE
  #undef S_pE2
  return(_comp);
} /* class_E_monitor_display */

_class_Isotropic_Sqw *class_Isotropic_Sqw_display(_class_Isotropic_Sqw *_comp
) {
  #define powder_format (_comp->_parameters.powder_format)
  #define Sqw_coh (_comp->_parameters.Sqw_coh)
  #define Sqw_inc (_comp->_parameters.Sqw_inc)
  #define geometry (_comp->_parameters.geometry)
  #define radius (_comp->_parameters.radius)
  #define thickness (_comp->_parameters.thickness)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define threshold (_comp->_parameters.threshold)
  #define order (_comp->_parameters.order)
  #define T (_comp->_parameters.T)
  #define verbose (_comp->_parameters.verbose)
  #define d_phi (_comp->_parameters.d_phi)
  #define concentric (_comp->_parameters.concentric)
  #define rho (_comp->_parameters.rho)
  #define sigma_abs (_comp->_parameters.sigma_abs)
  #define sigma_coh (_comp->_parameters.sigma_coh)
  #define sigma_inc (_comp->_parameters.sigma_inc)
  #define classical (_comp->_parameters.classical)
  #define powder_Dd (_comp->_parameters.powder_Dd)
  #define powder_DW (_comp->_parameters.powder_DW)
  #define powder_Vc (_comp->_parameters.powder_Vc)
  #define density (_comp->_parameters.density)
  #define weight (_comp->_parameters.weight)
  #define p_interact (_comp->_parameters.p_interact)
  #define norm (_comp->_parameters.norm)
  #define powder_barns (_comp->_parameters.powder_barns)
  #define quantum_correction (_comp->_parameters.quantum_correction)
  #define VarSqw (_comp->_parameters.VarSqw)
  #define columns (_comp->_parameters.columns)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_iso_samp_display] component iso_samp=Isotropic_Sqw() DISPLAY [Isotropic_Sqw:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  if (VarSqw.s_coh > 0 || VarSqw.s_inc > 0) {

    if (VarSqw.shape == 1) {
      double xmin = -0.5 * xwidth;
      double xmax = 0.5 * xwidth;
      double ymin = -0.5 * yheight;
      double ymax = 0.5 * yheight;
      double zmin = -0.5 * zdepth;
      double zmax = 0.5 * zdepth;
      multiline (5, xmin, ymin, zmin, xmax, ymin, zmin, xmax, ymax, zmin, xmin, ymax, zmin, xmin, ymin, zmin);
      multiline (5, xmin, ymin, zmax, xmax, ymin, zmax, xmax, ymax, zmax, xmin, ymax, zmax, xmin, ymin, zmax);
      line (xmin, ymin, zmin, xmin, ymin, zmax);
      line (xmax, ymin, zmin, xmax, ymin, zmax);
      line (xmin, ymax, zmin, xmin, ymax, zmax);
      line (xmax, ymax, zmin, xmax, ymax, zmax);

      if (thickness) {
        xmin = -0.5 * xwidth + thickness;
        xmax = -xmin;
        ymin = -0.5 * yheight + thickness;
        ymax = -ymin;
        zmin = -0.5 * zdepth + thickness;
        zmax = -zmin;
        multiline (5, xmin, ymin, zmin, xmax, ymin, zmin, xmax, ymax, zmin, xmin, ymax, zmin, xmin, ymin, zmin);
        multiline (5, xmin, ymin, zmax, xmax, ymin, zmax, xmax, ymax, zmax, xmin, ymax, zmax, xmin, ymin, zmax);
        line (xmin, ymin, zmin, xmin, ymin, zmax);
        line (xmax, ymin, zmin, xmax, ymin, zmax);
        line (xmin, ymax, zmin, xmin, ymax, zmax);
        line (xmax, ymax, zmin, xmax, ymax, zmax);
      }
    } else if (VarSqw.shape == 0) {
      circle ("xz", 0, yheight / 2.0, 0, radius);
      circle ("xz", 0, -yheight / 2.0, 0, radius);
      line (-radius, -yheight / 2.0, 0, -radius, +yheight / 2.0, 0);
      line (+radius, -yheight / 2.0, 0, +radius, +yheight / 2.0, 0);
      line (0, -yheight / 2.0, -radius, 0, +yheight / 2.0, -radius);
      line (0, -yheight / 2.0, +radius, 0, +yheight / 2.0, +radius);
      if (thickness) {
        double radius_i = radius - thickness;
        circle ("xz", 0, yheight / 2.0, 0, radius_i);
        circle ("xz", 0, -yheight / 2.0, 0, radius_i);
        line (-radius_i, -yheight / 2.0, 0, -radius_i, +yheight / 2.0, 0);
        line (+radius_i, -yheight / 2.0, 0, +radius_i, +yheight / 2.0, 0);
        line (0, -yheight / 2.0, -radius_i, 0, +yheight / 2.0, -radius_i);
        line (0, -yheight / 2.0, +radius_i, 0, +yheight / 2.0, +radius_i);
      }
    } else if (VarSqw.shape == 2) {
      if (thickness) {
        double radius_i = radius - thickness;
        circle ("xy", 0, 0, 0, radius_i);
        circle ("xz", 0, 0, 0, radius_i);
        circle ("yz", 0, 0, 0, radius_i);
      }
      circle ("xy", 0, 0, 0, radius);
      circle ("xz", 0, 0, 0, radius);
      circle ("yz", 0, 0, 0, radius);
    } else if (VarSqw.shape == 3) { /* OFF file */
      off_display (offdata);
    }
  }
  /* end MCDISPLAY */
  #undef powder_format
  #undef Sqw_coh
  #undef Sqw_inc
  #undef geometry
  #undef radius
  #undef thickness
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef threshold
  #undef order
  #undef T
  #undef verbose
  #undef d_phi
  #undef concentric
  #undef rho
  #undef sigma_abs
  #undef sigma_coh
  #undef sigma_inc
  #undef classical
  #undef powder_Dd
  #undef powder_DW
  #undef powder_Vc
  #undef density
  #undef weight
  #undef p_interact
  #undef norm
  #undef powder_barns
  #undef quantum_correction
  #undef VarSqw
  #undef columns
  #undef offdata
  return(_comp);
} /* class_Isotropic_Sqw_display */

_class_Monitor_nD *class_Monitor_nD_display(_class_Monitor_nD *_comp
) {
  #define user1 (_comp->_parameters.user1)
  #define user2 (_comp->_parameters.user2)
  #define user3 (_comp->_parameters.user3)
  #define xwidth (_comp->_parameters.xwidth)
  #define yheight (_comp->_parameters.yheight)
  #define zdepth (_comp->_parameters.zdepth)
  #define xmin (_comp->_parameters.xmin)
  #define xmax (_comp->_parameters.xmax)
  #define ymin (_comp->_parameters.ymin)
  #define ymax (_comp->_parameters.ymax)
  #define zmin (_comp->_parameters.zmin)
  #define zmax (_comp->_parameters.zmax)
  #define bins (_comp->_parameters.bins)
  #define min (_comp->_parameters.min)
  #define max (_comp->_parameters.max)
  #define restore_neutron (_comp->_parameters.restore_neutron)
  #define radius (_comp->_parameters.radius)
  #define options (_comp->_parameters.options)
  #define filename (_comp->_parameters.filename)
  #define geometry (_comp->_parameters.geometry)
  #define nowritefile (_comp->_parameters.nowritefile)
  #define nexus_bins (_comp->_parameters.nexus_bins)
  #define username1 (_comp->_parameters.username1)
  #define username2 (_comp->_parameters.username2)
  #define username3 (_comp->_parameters.username3)
  #define DEFS (_comp->_parameters.DEFS)
  #define Vars (_comp->_parameters.Vars)
  #define detector (_comp->_parameters.detector)
  #define offdata (_comp->_parameters.offdata)
  SIG_MESSAGE("[_Banana_1_display] component Banana_1=Monitor_nD() DISPLAY [Monitor_nD:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  if (geometry && strlen (geometry) && strcmp (geometry, "0") && strcmp (geometry, "NULL")) {
    off_display (offdata);
  } else {
    Monitor_nD_McDisplay (&DEFS, &Vars);
  }
  #undef user1
  #undef user2
  #undef user3
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef zmin
  #undef zmax
  #undef bins
  #undef min
  #undef max
  #undef restore_neutron
  #undef radius
  #undef options
  #undef filename
  #undef geometry
  #undef nowritefile
  #undef nexus_bins
  #undef username1
  #undef username2
  #undef username3
  #undef DEFS
  #undef Vars
  #undef detector
  #undef offdata
  return(_comp);
} /* class_Monitor_nD_display */


  #undef magnify
  #undef line
  #undef dashed_line
  #undef multiline
  #undef rectangle
  #undef box
  #undef circle
  #undef cylinder
  #undef sphere

int display(void) { /* called by mccode_main for ISIS_LET_generated:DISPLAY */
  printf("MCDISPLAY: start\n");

  /* call iteratively all components DISPLAY */
  class_Arm_display(&_Origin_var);

  class_Commodus_I3_display(&_SourceMantid_var);

  class_Guide_channeled_display(&_shutter_var);

  class_Guide_channeled_display(&_insert_var);

  class_Guide_channeled_display(&_after_insert_var);

  class_TOF_monitor_display(&_Monitor1_var);

  class_DiskChopper_display(&_LET_Chopper1_disk1_var);

  class_DiskChopper_display(&_LET_Chopper1_disk2_var);

  class_TOF_monitor_display(&_Monitor2_var);

  class_Guide_channeled_display(&_between_chop1_and_chop2_var);

  class_DiskChopper_display(&_LET_Chopper2_var);

  class_TOF_monitor_display(&_Monitor3_var);

  class_Guide_channeled_display(&_between_chop2_and_chop3_var);

  class_DiskChopper_display(&_LET_Chopper3_var);

  class_TOF_monitor_display(&_Monitor4_var);

  class_Guide_channeled_display(&_between_chop3_and_chop4_var);

  class_DiskChopper_display(&_LET_Chopper4_var);

  class_TOF_monitor_display(&_Monitor5_var);

  class_Guide_channeled_display(&_between_chop4_and_movable_var);

  class_PSD_monitor_display(&_moveable_front_PSDmon_var);

  class_Divergence_monitor_display(&_moveable_front_Divmon_var);

  class_Guide_channeled_display(&_moveable_guide_var);

  class_PSD_monitor_display(&_moveable_back_PSDmon_var);

  class_Divergence_monitor_display(&_moveable_back_Divmon_var);

  class_Guide_channeled_display(&_funnel_var);

  class_DiskChopper_display(&_LET_Chopper5_Disk1_var);

  class_DiskChopper_display(&_LET_Chopper5_Disk2_var);

  class_TOF_monitor_display(&_Monitor6_var);

  class_Guide_channeled_display(&_tanksection_var);

  class_Guide_channeled_display(&_snout_var);

  class_Arm_display(&_sample_var);

  class_PSD_monitor_display(&_sample_PSDmon_var);

  class_Divergence_monitor_display(&_sample_Divmon_var);

  class_TOF_monitor_display(&_sample_tof_var);

  class_E_monitor_display(&_sample_Emon_var);

  class_Isotropic_Sqw_display(&_iso_samp_var);

  class_Arm_display(&_detectorArm_var);

  class_Monitor_nD_display(&_Banana_1_var);

  printf("MCDISPLAY: end\n");

  return(0);
} /* display */

void* _getvar_parameters(char* compname)
/* enables settings parameters based use of the GETPAR macro */
{
  #ifdef OPENACC
    #define strcmp(a,b) str_comp(a,b)
  #endif
  if (!strcmp(compname, "Origin")) return (void *) &(_Origin_var._parameters);
  if (!strcmp(compname, "SourceMantid")) return (void *) &(_SourceMantid_var._parameters);
  if (!strcmp(compname, "shutter")) return (void *) &(_shutter_var._parameters);
  if (!strcmp(compname, "insert")) return (void *) &(_insert_var._parameters);
  if (!strcmp(compname, "after_insert")) return (void *) &(_after_insert_var._parameters);
  if (!strcmp(compname, "Monitor1")) return (void *) &(_Monitor1_var._parameters);
  if (!strcmp(compname, "LET_Chopper1_disk1")) return (void *) &(_LET_Chopper1_disk1_var._parameters);
  if (!strcmp(compname, "LET_Chopper1_disk2")) return (void *) &(_LET_Chopper1_disk2_var._parameters);
  if (!strcmp(compname, "Monitor2")) return (void *) &(_Monitor2_var._parameters);
  if (!strcmp(compname, "between_chop1_and_chop2")) return (void *) &(_between_chop1_and_chop2_var._parameters);
  if (!strcmp(compname, "LET_Chopper2")) return (void *) &(_LET_Chopper2_var._parameters);
  if (!strcmp(compname, "Monitor3")) return (void *) &(_Monitor3_var._parameters);
  if (!strcmp(compname, "between_chop2_and_chop3")) return (void *) &(_between_chop2_and_chop3_var._parameters);
  if (!strcmp(compname, "LET_Chopper3")) return (void *) &(_LET_Chopper3_var._parameters);
  if (!strcmp(compname, "Monitor4")) return (void *) &(_Monitor4_var._parameters);
  if (!strcmp(compname, "between_chop3_and_chop4")) return (void *) &(_between_chop3_and_chop4_var._parameters);
  if (!strcmp(compname, "LET_Chopper4")) return (void *) &(_LET_Chopper4_var._parameters);
  if (!strcmp(compname, "Monitor5")) return (void *) &(_Monitor5_var._parameters);
  if (!strcmp(compname, "between_chop4_and_movable")) return (void *) &(_between_chop4_and_movable_var._parameters);
  if (!strcmp(compname, "moveable_front_PSDmon")) return (void *) &(_moveable_front_PSDmon_var._parameters);
  if (!strcmp(compname, "moveable_front_Divmon")) return (void *) &(_moveable_front_Divmon_var._parameters);
  if (!strcmp(compname, "moveable_guide")) return (void *) &(_moveable_guide_var._parameters);
  if (!strcmp(compname, "moveable_back_PSDmon")) return (void *) &(_moveable_back_PSDmon_var._parameters);
  if (!strcmp(compname, "moveable_back_Divmon")) return (void *) &(_moveable_back_Divmon_var._parameters);
  if (!strcmp(compname, "funnel")) return (void *) &(_funnel_var._parameters);
  if (!strcmp(compname, "LET_Chopper5_Disk1")) return (void *) &(_LET_Chopper5_Disk1_var._parameters);
  if (!strcmp(compname, "LET_Chopper5_Disk2")) return (void *) &(_LET_Chopper5_Disk2_var._parameters);
  if (!strcmp(compname, "Monitor6")) return (void *) &(_Monitor6_var._parameters);
  if (!strcmp(compname, "tanksection")) return (void *) &(_tanksection_var._parameters);
  if (!strcmp(compname, "snout")) return (void *) &(_snout_var._parameters);
  if (!strcmp(compname, "sample")) return (void *) &(_sample_var._parameters);
  if (!strcmp(compname, "sample_PSDmon")) return (void *) &(_sample_PSDmon_var._parameters);
  if (!strcmp(compname, "sample_Divmon")) return (void *) &(_sample_Divmon_var._parameters);
  if (!strcmp(compname, "sample_tof")) return (void *) &(_sample_tof_var._parameters);
  if (!strcmp(compname, "sample_Emon")) return (void *) &(_sample_Emon_var._parameters);
  if (!strcmp(compname, "iso_samp")) return (void *) &(_iso_samp_var._parameters);
  if (!strcmp(compname, "detectorArm")) return (void *) &(_detectorArm_var._parameters);
  if (!strcmp(compname, "Banana_1")) return (void *) &(_Banana_1_var._parameters);
  return 0;
}

void* _get_particle_var(char *token, _class_particle *p)
/* enables setpars based use of GET_PARTICLE_DVAR macro and similar */
{
  return 0;
}

int _getcomp_index(char* compname)
/* Enables retrieving the component position & rotation when the index is not known.
 * Component indexing into MACROS, e.g., POS_A_COMP_INDEX, are 1-based! */
{
  if (!strcmp(compname, "Origin")) return 1;
  if (!strcmp(compname, "SourceMantid")) return 2;
  if (!strcmp(compname, "shutter")) return 3;
  if (!strcmp(compname, "insert")) return 4;
  if (!strcmp(compname, "after_insert")) return 5;
  if (!strcmp(compname, "Monitor1")) return 6;
  if (!strcmp(compname, "LET_Chopper1_disk1")) return 7;
  if (!strcmp(compname, "LET_Chopper1_disk2")) return 8;
  if (!strcmp(compname, "Monitor2")) return 9;
  if (!strcmp(compname, "between_chop1_and_chop2")) return 10;
  if (!strcmp(compname, "LET_Chopper2")) return 11;
  if (!strcmp(compname, "Monitor3")) return 12;
  if (!strcmp(compname, "between_chop2_and_chop3")) return 13;
  if (!strcmp(compname, "LET_Chopper3")) return 14;
  if (!strcmp(compname, "Monitor4")) return 15;
  if (!strcmp(compname, "between_chop3_and_chop4")) return 16;
  if (!strcmp(compname, "LET_Chopper4")) return 17;
  if (!strcmp(compname, "Monitor5")) return 18;
  if (!strcmp(compname, "between_chop4_and_movable")) return 19;
  if (!strcmp(compname, "moveable_front_PSDmon")) return 20;
  if (!strcmp(compname, "moveable_front_Divmon")) return 21;
  if (!strcmp(compname, "moveable_guide")) return 22;
  if (!strcmp(compname, "moveable_back_PSDmon")) return 23;
  if (!strcmp(compname, "moveable_back_Divmon")) return 24;
  if (!strcmp(compname, "funnel")) return 25;
  if (!strcmp(compname, "LET_Chopper5_Disk1")) return 26;
  if (!strcmp(compname, "LET_Chopper5_Disk2")) return 27;
  if (!strcmp(compname, "Monitor6")) return 28;
  if (!strcmp(compname, "tanksection")) return 29;
  if (!strcmp(compname, "snout")) return 30;
  if (!strcmp(compname, "sample")) return 31;
  if (!strcmp(compname, "sample_PSDmon")) return 32;
  if (!strcmp(compname, "sample_Divmon")) return 33;
  if (!strcmp(compname, "sample_tof")) return 34;
  if (!strcmp(compname, "sample_Emon")) return 35;
  if (!strcmp(compname, "iso_samp")) return 36;
  if (!strcmp(compname, "detectorArm")) return 37;
  if (!strcmp(compname, "Banana_1")) return 38;
  return -1;
}

/* embedding file "metadata-r.c" */

/** --- Contents of  metadata-r.c ---------------------------------------------------------------------------------- */
// Created by Gregory Tucker, Data Management Software Centre, European Spallation Source ERIC on 07/07/23.
#ifndef MCCODE_NAME
#include "metadata-r.h"
#endif

char * metadata_table_key_component(char* key){
  if (strlen(key) == 0) return NULL;
  char sep[2] = ":\0"; // matches any number of repeated colons
  // look for the separator in the provided key; strtok is allowed to modify the string, so copy it
  char * tok = malloc((strlen(key) + 1) * sizeof(char));
  if (!tok) {
    fprintf(stderr,"Error allocating token\n");
    exit(-1);
  }
  strcpy(tok, key);
  char * pch = strtok(tok, sep); // this *is* the component name (if provided) -- but we need to move the pointer
  char * comp = malloc((1 + strlen(pch)) * sizeof(char));
  if (!comp) {
    fprintf(stderr,"Error allocating comp\n");
    exit(-1);
  }
  strcpy(comp, pch);
  if (tok) free(tok);
  return comp;
}
char * metadata_table_key_literal(char * key){
  if (strlen(key) == 0) return NULL;
  char sep[3] = ":\0";
  char * tok = malloc((strlen(key) + 1 ) * sizeof(char));
  if (!tok) {
    fprintf(stderr,"Error allocating token\n");
    exit(-1);
  }
  strcpy(tok, key);
  char * pch = strtok(tok, sep); // this *is* the component name (if provided)
  if (pch) pch = strtok(NULL, sep); // either NULL or the literal name
  char * name = NULL;
  if (pch) {
    name = malloc((1 + strlen(pch)) * sizeof(char));
    if (!name) {
      fprintf(stderr,"Error allocating name\n");
	exit(-1);
    }
    strcpy(name, pch);
  }
  if (tok) free(tok);
  return name;
}
int metadata_table_defined(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0){
    /* This is 0 instead of `no` independent of any wildcard-matching logic
     * because a caller _already_ knows `no` and can verify
     * that `key` is not "" at call-time. So returning `no` is useless.
     */
    return 0;
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  // look through the table for the matching component and literal names
  int number = 0;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source)){
      if (name == NULL || !strcmp(name, tab[i].name)) ++number;
    }
  }
  if (comp) free(comp);
  if (name) free(name);
  return number;
}

char * metadata_table_name(int no, metadata_table_t * tab, char *key){
    if (strlen(key) == 0){
        return NULL;
    }
    char * comp = metadata_table_key_component(key);
    char * name = metadata_table_key_literal(key);
    if (name == NULL) {
        for (int i=0; i<no; ++i){
            if (!strcmp(comp, tab[i].source)){
                name = malloc((strlen(tab[i].name) + 1) * sizeof(char));
		if (!name) {
		  fprintf(stderr,"Error allocating metadata_table_name\n");
		  exit(-1);
		}
                strcpy(name, tab[i].name);
                break;
            }
        }
    } else {
        int found=0;
        for (int i=0; i<no; ++i){
            if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) {
                found = 1;
                break;
            }
        }
        if (!found) free(name);
    }
    free(comp);
    return name;
}

char * metadata_table_type(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0) {
    fprintf(stderr, "Unable to check type of non-existent key\n");
    exit(1);
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  if (name == NULL){
    fprintf(stderr, "Unable to check type of literal for component %s without its name\n", comp);
    free(comp);
    exit(1);
  }
  char * type = NULL;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) type = tab[i].type;
  }
  if (comp) free(comp);
  if (name) free(name);
  return type;
}

char * metadata_table_literal(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0) {
    fprintf(stderr, "Unable to retrieve literal for non-existent key\n");
    exit(1);
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  if (name == NULL){
    fprintf(stderr, "Unable to retrieve literal for component %s without its name\n", comp);
    free(comp);
    exit(1);
  }
  char * type = NULL;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) type = tab[i].value;
  }
  if (comp) free(comp);
  if (name) free(name);
  return type;
}
void metadata_table_print_all_keys(int no, metadata_table_t * tab){
  for (int i=0; i<no; ++i){
    printf("%s::%s ", tab[i].source, tab[i].name);
  }
  printf("\n");
}
int metadata_table_print_all_components(int no, metadata_table_t * tab){
  int count = 0;
  char ** known = malloc(no * sizeof(char*));
  if (!known) {
    fprintf(stderr,"Error allocating table of known metadata\n");
    exit(-1);
  }
  for (int i=0; i<no; ++i){
    int unknown = 1;
    for (int j=0; j<count; ++j) if (!strcmp(tab[i].source, known[j])) unknown = 0;
    if (unknown) known[count++] = tab[i].source;
  }
  size_t nchar = 0;
  for (int i=0; i<count; ++i) nchar += strlen(known[i]) + 1;
  char * line = malloc((nchar + 1) * sizeof(char));
  char * linetmp = malloc((nchar + 1) * sizeof(char));
  if (!line || !linetmp) {
    fprintf(stderr,"Error allocating metadata print arrays\n");
    exit(-1);
  }
  line[0] = '\0';
  for (int i=0; i<count; ++i) sprintf(linetmp, "%s%s ", line, known[i]);
  line=linetmp;
  line[strlen(line)] = '\0'; // eat the trailing space
  printf("%s\n", line);
  free(line);
  free(linetmp);
  free(known);
  return count;
}
int metadata_table_print_component_keys(int no, metadata_table_t * tab, char * key){
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  int count = 0;
  for (int i=0; i<no; ++i) if (!strcmp(tab[i].source, comp) && (name == NULL || !strcmp(tab[i].name, name))) {
    if (name == NULL) printf("%s ", tab[i].name);
    ++count;
  }
  if (name != NULL) printf("%d", count); // replace count by strlen(tab[i].value)?
  printf("\n");
  return count;
}
/* -------------------------------------------------------------------------------------Contents of  metadata-r.c --- */
/* End of file "metadata-r.c". */

/* embedding file "mccode_main.c" */

/*******************************************************************************
* mccode_main: McCode main() function.
*******************************************************************************/
int mccode_main(int argc, char *argv[])
{
  /*  double run_num = 0; */
  time_t  t;
  clock_t ct;

#ifdef USE_MPI
  char mpi_node_name[MPI_MAX_PROCESSOR_NAME];
  int  mpi_node_name_len;
#endif /* USE_MPI */

#ifdef MAC
  argc = ccommand(&argv);
#endif

#ifdef USE_MPI
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &mpi_node_count); /* get number of nodes */
  MPI_Comm_rank(MPI_COMM_WORLD, &mpi_node_rank);
  MPI_Comm_set_name(MPI_COMM_WORLD, instrument_name);
  MPI_Get_processor_name(mpi_node_name, &mpi_node_name_len);
#endif /* USE_MPI */

  ct = clock();

  // device and host functional RNG seed
  struct timeval tm;
  gettimeofday(&tm, NULL);
  mcseed = (long) tm.tv_sec*1000000 + tm.tv_usec;
  mcstartdate = (long)tm.tv_sec;  /* set start date before parsing options and creating sim file */
  // init global _particle.randstate for random number use
  // during init(), finally() and display(). NOTE: during trace, a local
  // "_particle" variable is present and thus used instead.
  //
  // PW: srandom deferred until init() since we did not read seed input from commandline
  //srandom(_hash(mcseed-1));

#ifdef USE_MPI
  /* *** print number of nodes *********************************************** */
  if (mpi_node_count > 1) {
    MPI_MASTER(
    printf("Simulation '%s' (%s): running on %i nodes (master is '%s', MPI version %i.%i).\n",
      instrument_name, instrument_source, mpi_node_count, mpi_node_name, MPI_VERSION, MPI_SUBVERSION);
    );
    /* share the same seed, then adapt random seed for each node */
    MPI_Bcast(&mcseed, 1, MPI_LONG, 0, MPI_COMM_WORLD); /* root sends its seed to slaves */
    mcseed += mpi_node_rank; /* make sure we use different seeds per noe */
  }
#endif /* USE_MPI */

#ifdef OPENACC
#ifdef USE_MPI
  int num_devices = acc_get_num_devices(acc_device_nvidia);
  if(num_devices>0){
    int my_device = mpi_node_rank % num_devices;
    acc_set_device_num( my_device, acc_device_nvidia );
    printf("Have found %d GPU devices on rank %d. Will use device %d.\n", num_devices, mpi_node_rank, my_device);
  }else{
    printf("There was an issue probing acc_get_num_devices, fallback to host\n");
    acc_set_device_type( acc_device_host );
  }
#endif
#endif

  /* *** parse options ******************************************************* */
  SIG_MESSAGE("[" __FILE__ "] main START");
  mcformat = getenv(FLAVOR_UPPER "_FORMAT") ?
             getenv(FLAVOR_UPPER "_FORMAT") : FLAVOR_UPPER;
  instrument_exe = argv[0]; /* store the executable path */
  /* read simulation parameters and options */
  mcparseoptions(argc, argv); /* sets output dir and format */


#ifdef USE_MPI
  if (mpi_node_count > 1) {
    /* share the same seed, then adapt random seed for each node */
    MPI_Bcast(&mcseed, 1, MPI_LONG, 0, MPI_COMM_WORLD); /* root sends its seed to slaves */
    mcseed += mpi_node_rank; /* make sure we use different seeds per node */
  }
#endif


/* *** install sig handler, but only once !! after parameters parsing ******* */
#ifndef NOSIGNALS
#ifdef SIGQUIT
  if (signal( SIGQUIT ,sighandler) == SIG_IGN)
    signal( SIGQUIT,SIG_IGN);   /* quit (ASCII FS) */
#endif
#ifdef SIGABRT
  if (signal( SIGABRT ,sighandler) == SIG_IGN)
    signal( SIGABRT,SIG_IGN);   /* used by abort, replace SIGIOT in the future */
#endif
#ifdef SIGTERM
  if (signal( SIGTERM ,sighandler) == SIG_IGN)
    signal( SIGTERM,SIG_IGN);   /* software termination signal from kill */
#endif
#ifdef SIGUSR1
  if (signal( SIGUSR1 ,sighandler) == SIG_IGN)
    signal( SIGUSR1,SIG_IGN);   /* display simulation status */
#endif
#ifdef SIGUSR2
  if (signal( SIGUSR2 ,sighandler) == SIG_IGN)
    signal( SIGUSR2,SIG_IGN);
#endif
#ifdef SIGHUP
  if (signal( SIGHUP ,sighandler) == SIG_IGN)
    signal( SIGHUP,SIG_IGN);
#endif
#ifdef SIGILL
  if (signal( SIGILL ,sighandler) == SIG_IGN)
    signal( SIGILL,SIG_IGN);    /* illegal instruction (not reset when caught) */
#endif
#ifdef SIGFPE
  if (signal( SIGFPE ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);    /* floating point exception */
#endif
#ifdef SIGBUS
  if (signal( SIGBUS ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);    /* bus error */
#endif
#ifdef SIGSEGV
  if (signal( SIGSEGV ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);   /* segmentation violation */
#endif
#endif /* !NOSIGNALS */


  // init executed by master/host
  siminfo_init(NULL); /* open SIM */
  SIG_MESSAGE("[" __FILE__ "] main INITIALISE");
  init();


#ifndef NOSIGNALS
#ifdef SIGINT
  if (signal( SIGINT ,sighandler) == SIG_IGN)
    signal( SIGINT,SIG_IGN);    /* interrupt (rubout) only after INIT */
#endif
#endif /* !NOSIGNALS */

/* ================ main particle generation/propagation loop ================ */
#ifdef USE_MPI
  /* sliced Ncount on each MPI node */
  mcncount = mpi_node_count > 1 ?
    floor(mcncount / mpi_node_count) :
    mcncount; /* number of rays per node */
#endif

// MT specific init, note that per-ray init is empty
#if RNG_ALG == 2
  mt_srandom(mcseed);
#endif


// main raytrace work loop
#ifndef FUNNEL
  // legacy version
  raytrace_all(mcncount, mcseed);
#else
  MPI_MASTER(
  // "funneled" version in which propagation is more parallelizable
  printf("\nNOTE: CPU COMPONENT grammar activated:\n 1) \"FUNNEL\" raytrace algorithm enabled.\n 2) Any SPLIT's are dynamically allocated based on available buffer size. \n");
	     );
  raytrace_all_funnel(mcncount, mcseed);
#endif


#ifdef USE_MPI
 /* merge run_num from MPI nodes */
  if (mpi_node_count > 1) {
  double mcrun_num_double = (double)mcrun_num;
  mc_MPI_Sum(&mcrun_num_double, 1);
  mcrun_num = (unsigned long long)mcrun_num_double;
  }
#endif


  // save/finally executed by master node/thread/host
  finally();


#ifdef USE_MPI
  MPI_Finalize();
#endif /* USE_MPI */


  return 0;
} /* mccode_main */
/* End of file "mccode_main.c". */

/* end of generated C code ./ISIS_LET_generated.c */
