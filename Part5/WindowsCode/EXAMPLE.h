//////////////////////////
// Example.h
// A header file which will help the application
// programmer to write code for multiple platform
//
//
#ifndef _EXAMPLE_DOT_H
#define _EXAMPLE_DOT_H
#include <stdio.h>
#include <stdlib.h>

#ifdef _WINDOWS   // if we are compiling for Windows
#include <windows.h>
////////////////////////////////////////////////////////
//Comparison function for qsort under Windows should use 
//__cdecl calling convention ( The parameters are 
//pushed from Right to Left and callee pops the stack )
//
#define CALL_CONV_FOR_QSORT  __cdecl 
///////////////////////////////
//Functions to be exported should using 
//__stdcall function ( The parameters are pushed from 
//Right to Leftand callee pops the stack )
//
#define STDCALL_CONV __stdcall
///////////////////////////////////
// Directive for Exporting the function from a DLL
#define EXPORTED_FUNC __declspec(dllexport) 

/////////////////////////////////////
// Windows Function for Loading a DLL
//       LoadLibrary 
// Windows Function for retrieved a function address
//       GetProcAddress
// Windows Function for Unloading the DLL
//       FreeLibrary
//

#define LOAD_DLL(hmodule,str) \
 ( ( hmodule = LoadLibrary((str)) ) != INVALID_HANDLE_VALUE )
#define GET_FUNC_PTR(hmodule,str) \
 (GetProcAddress(hmodule,(str)))
#define UNLOAD_DLL(hmodule) FreeLibrary(hmodule);

#else

#include <dlfcn.h>   // for GNU Linux and MAC OS X
#define CALL_CONV_FOR_QSORT  
#define EXPORTED_FUNC
#define STDCALL_CONV 

/////////////////////////////////////
// UNIX Function for Loading a DLL
//       dlopen 
// UNIX Function for retrieved a function address
//       dlsym
// UNIX Function for Unloading the DLL
//       dlclose
//
#define LOAD_DLL(hmodule,str) \
( ( hmodule = dlopen((str),RTLD_LAZY) ) != 0 )

#define GET_FUNC_PTR(hmodule,str) dlsym(hmodule,(str));
#define UNLOAD_DLL(hmodule) dlclose(hmodule);

#endif

//////////////////////////////////////////////////
// Function Pointer for our exported function 
typedef int ( STDCALL_CONV *QSORT_FUNC)(double *,int);

#endif
