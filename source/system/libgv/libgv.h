#ifndef __MGSTTS_LIBGV_H__
#define __MGSTTS_LIBGV_H__

#ifdef __cplusplus
extern "C" {
#endif

/* gvd.c */
void GV_StartDaemon( void );

/* strcode.c */
int GV_StrCode( const char *string );

#ifdef __cplusplus
}
#endif
#endif // {{{ END OF FILE }}}
