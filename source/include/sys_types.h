/* Copied and modified from MGS2 */
#ifndef __MGSTTS_SYS_TYPES_H__
#define __MGSTTS_SYS_TYPES_H__

// Apparently CodeWarrior for GameCube doesn't have this?
#ifndef __MWERKS__
#include <sys/types.h>
#endif
#include "gcctest.h"

// MSVC's <sys/types.h> doesn't have any of these.
// NOTE: sizeof(long) differs between ILP32/LLP64 and LP64 systems.
// ...and the Emotion Engine's IP32L64 data model.

#if !defined(_SYS_TYPES_H) || __GNUC_PREREQ(2, 96)
// NOTE: Apparently GCC versions before 2.96 can't cope with typedefs
// being duplicately defined, so we're not defining anything if the
// compiler isn't new enough.
//
// Because <eetypes.h> defines the four BSD-style u_types locally and
// only checks that _SYS_TYPES_H is not already defined, <sys/types.h>
// MUST be included before <eetypes.h> when using ee-gcc versions earlier
// than 2.96. This problem was fixed in SDK Release 3.0.

#if !defined(_POSIX_SOURCE)
#if !defined(_BSDTYPES_DEFINED) && !defined(_WINSOCK_H)
typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef unsigned int    u_int;
typedef unsigned long   u_long;
#define _BSDTYPES_DEFINED
#endif

// NOTE: ee-gcc's <sys/types.h> does NOT define unchar or ulong.
// I've added them here just because, but let's stick to BSD.

typedef unsigned char   unchar;         /* System V compatibility */
typedef unsigned short  ushort;         /* System V compatibility */
typedef unsigned int    uint;           /* System V compatibility */
typedef unsigned long   ulong;          /* System V compatibility */
#endif // !_POSIX_SOURCE
#endif // !_SYS_TYPES_H

#endif // {{{ END OF FILE }}}
