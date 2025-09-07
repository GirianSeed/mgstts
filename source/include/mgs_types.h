#ifndef __MGSTTS_MGS_TYPES_H__
#define __MGSTTS_MGS_TYPES_H__

#include <stddef.h>     // for size_t
#include <limits.h>     // for MIN/MAX
#include <stdint.h>
#include "mgs_defs.h"

// from <sys/types.h>
typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef unsigned int    u_int;
typedef unsigned long   u_long;

/*---------------------------------------------------------------------------*/

typedef int8_t          int8;           /*  8-bit signed integer    */
typedef uint8_t         u_int8;         /*  8-bit unsigned integer  */
typedef int16_t         int16;          /* 16-bit signed integer    */
typedef uint16_t        u_int16;        /* 16-bit unsigned integer  */
typedef int32_t         int32;          /* 32-bit signed integer    */
typedef uint32_t        u_int32;        /* 32-bit unsigned integer  */
typedef int64_t         int64;          /* 64-bit signed integer    */
typedef uint64_t        u_int64;        /* 64-bit unsigned integer  */
typedef int64_t         long64;         /* 64-bit signed long       */
typedef uint64_t        u_long64;       /* 64-bit unsigned long     */

#if (defined(__GNUC__) && defined(__SIZEOF_INT128__))
// https://gcc.gnu.org/onlinedocs/gcc/_005f_005fint128.html
// https://gcc.gnu.org/onlinedocs/gccint/Machine-Modes.html

// Originally from <eetypes.h>
typedef int long128 __attribute__((mode(TI)));
typedef unsigned int u_long128 __attribute__((mode(TI)));
#else
// One of several ways to make a fake 128-bit integer.
typedef struct { uint64_t hi,lo; } long128;
typedef struct { uint64_t hi,lo; } u_long128;
#endif

typedef long128         int128;         /* 128-bit signed integer   */
typedef u_long128       u_int128;       /* 128-bit unsigned integer */

/*---------------------------------------------------------------------------*/

typedef struct CVECTOR {
    u_char r, g, b, a;
} CVECTOR;

typedef struct SVECTOR {
    short vx;
    short vy;
    short vz;
    short vw;
} /*ALIGN8*/ SVECTOR;

typedef struct IVECTOR {
    int vx;
    int vy;
    int vz;
    int vw;
} /*ALIGN16*/ IVECTOR;

typedef struct FVECTOR {
    float vx;
    float vy;
    float vz;
    float vw;
} /*ALIGN16*/ FVECTOR;

typedef struct FMATRIX {
    float m[4][4];
} /*ALIGN16*/ FMATRIX;

#endif // {{{ END OF FILE }}}
