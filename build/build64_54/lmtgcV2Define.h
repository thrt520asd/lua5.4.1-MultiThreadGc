#ifndef lmtgcV2Define_h
#define lmtgcV2Define_h
#include "lua.h"
#if defined(_WIN32) || defined(_WIN64)
//#define _STDCALL __stdcall
#define _STDCALL  
#else
#define _STDCALL
#endif

typedef void (*gc_thread_stepCall)(lua_State* L);
typedef void (_STDCALL* CreateGcThreadCall)(gc_thread_stepCall gc_step);
typedef void (_STDCALL* FreeGcThreadCall)();

typedef void (_STDCALL* PlatformWriteBarrier)();
// gc 线程挂起
typedef void (_STDCALL* LockGcThreadCall)(lua_State * L);
// 通知gc线程
typedef void (_STDCALL* PulseGcThreadCall)(lua_State* L);


#endif