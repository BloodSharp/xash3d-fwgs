#include "common.h"
#include "client.h"

#ifdef DLLEXPORT
#undef DLLEXPORT
#endif//DLLEXPORT

#ifdef EXPORT
#undef EXPORT
#endif//EXPORT

#ifndef EXPORTDEF_H
#define EXPORTDEF_H
#if defined _WIN32 || defined __CYGWIN__
	#ifdef __GNUC__
		#define EXPORT __attribute__ ((dllexport))
	#else
		#define EXPORT __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
	#endif
#else
  #if __GNUC__ >= 4
	#define EXPORT __attribute__ ((visibility ("default")))
   #else
	#define EXPORT
  #endif
#endif
#define DLLEXPORT EXPORT
#define _DLLEXPORT EXPORT
#endif // EXPORTDEF_H

extern int g_iCommandsToIncreaseBy;

void DLLEXPORT XashEngineExportForMods(
    void** pClientState,
    void** pClientStatic,
    void** pGameStatic,
    int* pCommandsToIncreaseBy,
    void** pCL_WriteUserCmd,
    void** pHostParameters
)
{
    if (pClientState)
        *pClientState = (void*)&cl;
    if (pClientStatic)
        *pClientStatic = (void*)&cls;
    if (pGameStatic)
        *pGameStatic = (void*)&clgame;
    if (pCommandsToIncreaseBy)
        *pCommandsToIncreaseBy = &g_iCommandsToIncreaseBy;
    if (pCL_WriteUserCmd)
        *pCL_WriteUserCmd = (void*)&CL_WriteUsercmd;
    if (pHostParameters)
        *pHostParameters = (void*)&host;
}