#ifndef __MGSTTS_LIBFS_H__
#define __MGSTTS_LIBFS_H__

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char *name;             /* +0x00 */
    u_int pos;              /* +0x04 */
    unsigned char media;    /* +0x08 */
    unsigned char layer;    /* +0x09 */
    unsigned char alt;      /* +0x0a */
    unsigned char pad;      /* +0x0b */
} FS_FILE_INFO;

extern FS_FILE_INFO fs_file_info[]; /* in file.cnf */

#define FS_FILEID_STAGE         (0)     // stage.dat
#define FS_FILEID_CODEC         (1)     // shared/codec.dat
#define FS_FILEID_FACE          (2)     // shared/face.dat
#define FS_FILEID_MOVIE         (3)     // shared/movie.dat
#define FS_FILEID_VOX           (4)     // shared/vox.dat
#define FS_FILEID_DEMO          (5)     // demo.dat
#define FS_MAX_FILEID           (6)

/* select.c */
void FS_StartDaemon( void );

#ifdef __cplusplus
}
#endif
#endif // {{{ END OF FILE }}}
