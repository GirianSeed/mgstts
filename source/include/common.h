#ifndef __MGSTTS_COMMON_H__
#define __MGSTTS_COMMON_H__

#include <stddef.h>
#include <dolphin/types.h>

typedef unsigned char   u_char;         // from <sys/types.h>
typedef unsigned short  u_short;        // from <sys/types.h>
typedef unsigned int    u_int;          // from <sys/types.h>
typedef unsigned long   u_long;         // from <sys/types.h>

/*---------------------------------------------------------------------------*/

#ifndef MIN
#define MIN(x, y)       (((x) < (y)) ? (x) : (y))
#endif
#ifndef MAX
#define MAX(x, y)       (((x) > (y)) ? (x) : (y))
#endif
#ifndef ABS
#define ABS(x)          (((x) >= 0) ? (x) : -(x))
#endif

#ifndef CLAMP
#define CLAMP(x, min, max) (MAX(MIN(x, max), min))
#endif

#ifndef _countof
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif
#define countof(array)  _countof(array)
#define COUNTOF(array)  _countof(array)

#define ALIGN(_x)       __attribute__((aligned(_x)))
#define ALIGN8          ALIGN(8)
#define ALIGN16         ALIGN(16)
#define ALIGN64         ALIGN(64)
#define ALIGN128        ALIGN(128)

/*---------------------------------------------------------------------------*/

#define HANGUP()        (*(int *)1 = 0)

#ifdef _DEBUG

#define MGS_ASSERT(cond)                                        \
    if (!(cond)) {                                              \
        /* todo: decompile */                                   \
        HANGUP();                                               \
    }
#define MGS_XASSERT(cond, mesg ...)                             \
    if (!(cond)) {                                              \
        /* todo: decompile */                                   \
        printf( mesg );                                         \
        HANGUP();                                               \
    }

#else   // _DEBUG

#define MGS_ASSERT(cond)                ((void)0)
#define MGS_XASSERT(cond, mesg ...)     ((void)0)

#endif  // _DEBUG

/*---------------------------------------------------------------------------*/

/* RGBA8888 format */
#ifdef WORDS_BIGENDIAN
#define RGBA_R_SHIFT    (24)
#define RGBA_G_SHIFT    (16)
#define RGBA_B_SHIFT    ( 8)
#define RGBA_A_SHIFT    ( 0)
#else
#define RGBA_R_SHIFT    ( 0)
#define RGBA_G_SHIFT    ( 8)
#define RGBA_B_SHIFT    (16)
#define RGBA_A_SHIFT    (24)
#endif

#define MAKE_RGBA(_r,_g,_b,_a)                                  \
        ((unsigned int)((((_r) & 0xff) << RGBA_R_SHIFT)|        \
                        (((_g) & 0xff) << RGBA_G_SHIFT)|        \
                        (((_b) & 0xff) << RGBA_B_SHIFT)|        \
                        (((_a) & 0xff) << RGBA_A_SHIFT)))

#define MAKE_RGB0(_r,_g,_b)     MAKE_RGBA(_r,_g,_b,0x00)
#define MAKE_RGBX(_r,_g,_b)     MAKE_RGBA(_r,_g,_b,0xff)

#define GET_R_FROM_RGBA(_rgba)  (((_rgba) >> RGBA_R_SHIFT) & 0xff)
#define GET_G_FROM_RGBA(_rgba)  (((_rgba) >> RGBA_G_SHIFT) & 0xff)
#define GET_B_FROM_RGBA(_rgba)  (((_rgba) >> RGBA_B_SHIFT) & 0xff)
#define GET_A_FROM_RGBA(_rgba)  (((_rgba) >> RGBA_A_SHIFT) & 0xff)

/* ARGB8888 format */
#ifdef WORDS_BIGENDIAN
#define ARGB_A_SHIFT    (24)
#define ARGB_R_SHIFT    (16)
#define ARGB_G_SHIFT    ( 8)
#define ARGB_B_SHIFT    ( 0)
#else
#define ARGB_A_SHIFT    ( 0)
#define ARGB_R_SHIFT    ( 8)
#define ARGB_G_SHIFT    (16)
#define ARGB_B_SHIFT    (24)
#endif

#define MAKE_ARGB(_a,_r,_g,_b)                                  \
        ((unsigned int)((((_a) & 0xff) << ARGB_A_SHIFT)|        \
                        (((_r) & 0xff) << ARGB_R_SHIFT)|        \
                        (((_g) & 0xff) << ARGB_G_SHIFT)|        \
                        (((_b) & 0xff) << ARGB_B_SHIFT))

#define MAKE_0RGB(_r,_g,_b)     MAKE_ARGB(0x00,_r,_g,_b)
#define MAKE_XRGB(_r,_g,_b)     MAKE_ARGB(0xff,_r,_g,_b)

#define GET_A_FROM_ARGB(_argb)  (((_argb) >> ARGB_A_SHIFT) & 0xff)
#define GET_R_FROM_ARGB(_argb)  (((_argb) >> ARGB_R_SHIFT) & 0xff)
#define GET_G_FROM_ARGB(_argb)  (((_argb) >> ARGB_G_SHIFT) & 0xff)
#define GET_B_FROM_ARGB(_argb)  (((_argb) >> ARGB_B_SHIFT) & 0xff)

/* common colors */
#define COLOR_BLACK     MAKE_RGB0(  0,  0,  0)
#define COLOR_WHITE     MAKE_RGB0(255,255,255)
#define COLOR_GRAY      MAKE_RGB0(128,128,128)
#define COLOR_RED       MAKE_RGB0(255,  0,  0)
#define COLOR_GREEN     MAKE_RGB0(  0,255,  0)
#define COLOR_BLUE      MAKE_RGB0(  0,  0,255)
#define COLOR_CYAN      MAKE_RGB0(  0,255,255)
#define COLOR_MAGENTA   MAKE_RGB0(255,   ,255)
#define COLOR_YELLOW    MAKE_RGB0(255,255,  0)

/*---------------------------------------------------------------------------*/

typedef s8              int8;           /*  8-bit signed integer    */
typedef u8              u_int8;         /*  8-bit unsigned integer  */
typedef s16             int16;          /* 16-bit signed integer    */
typedef u16             u_int16;        /* 16-bit unsigned integer  */
typedef s32             int32;          /* 32-bit signed integer    */
typedef u32             u_int32;        /* 32-bit unsigned integer  */
typedef s64             int64;          /* 64-bit signed integer    */
typedef u64             u_int64;        /* 64-bit unsigned integer  */
typedef s64             long64;         /* 64-bit signed integer    */
typedef u64             u_long64;       /* 64-bit unsigned integer  */

typedef struct { u64 hi,lo; } long128;
typedef struct { u64 hi,lo; } u_long128;

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
