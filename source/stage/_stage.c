#include <stddef.h>     // for NULL
#include "chara.h"      // for NEWCHARA

/* gcl chara */
extern NEWCHARA NewGclAbs;
extern NEWCHARA NewGclCos;
extern NEWCHARA NewGclSin;
extern NEWCHARA NewGclAtan;
extern NEWCHARA NewStreamStopAll;
extern NEWCHARA NewPolygonDemoStart;
extern NEWCHARA NewReadSavedVariable;
extern NEWCHARA NewRand;
extern NEWCHARA NewForeach;
extern NEWCHARA NewStreamStart;
extern NEWCHARA NewStreamSet;
extern NEWCHARA ComStoreLoadedVariable;
extern NEWCHARA NewLoadRestart;
extern NEWCHARA NewSoundTest;
/* gcl chara end */

CHARA _StageCharacterEntries[] = {
#if VERSION_099
#include "_stage.debug.h"
#elif VERSION_US
#include "_stage.us.h"
#elif VERSION_JP
#include "_stage.jp.h"
#elif VERSION_EU
#include "_stage.eu.h"
#endif
};
