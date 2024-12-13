#include "gl_local.h"
//#include "../Common/common.h"
//#include "../engine/ref_api.h"

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

extern ref_interface_t gReffuncs;

void DLLEXPORT XashRefExportsForMods(
	void** pRefInterface,
	void** pMod_glBegin,
	void** pMod_glClear,
	void** pMod_glVertex3fv,
	void** pMod_glColor4f,
	void** pMod_glColor4ub)
{
    if (pRefInterface)
        *pRefInterface = &gReffuncs;
	if (pMod_glBegin)
		*pMod_glBegin = &pglBegin;
	if (pMod_glClear)
		*pMod_glClear = &pglClear;
	if (pMod_glVertex3fv)
		*pMod_glVertex3fv = &pglVertex3fv;
	if (pMod_glColor4f)
		*pMod_glColor4f = &pglColor4f;
	if (pMod_glColor4ub)
		*pMod_glColor4ub = &pglColor4ub;
}