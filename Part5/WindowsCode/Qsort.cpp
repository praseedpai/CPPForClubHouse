/////////////////////////////////////////////////////////
// Qsort.cpp
// Written by Praseed Pai K.T.
//            http://praseedp.blogspot.com
//
// under Windows @ the Visual C/C++ command prompt
// -----------------------------------------------
// cl /D_WINDOWS /c Qsort.cpp
// link /DLL /out:QSORT.dll /DEF:QSort.def Qsort.obj 
//
// under GNU Linux @ the Terminal 
// ------------------------------
// g++ -c -o -fPIC Qsort.o Qsort.cpp
// g++ -shared -o libQSORT.so Qsort.o
//
// under MAC OS X @ the Terminal 
// ------------------------------
// g++ -c -o -fPIC Qsort.o Qsort.cpp
// g++ -dynamiclib -o libQSORT.so Qsort.o
//
#include "EXAMPLE.h"
////////////////////////////////////////////////
// Comparison function for qsort ANSI C/C++
// library function. Visual C/C++ mandates that 
// it should be __cdecl as the default calling 
// convention is __stdcall 
// static qualifier is to restrict the visibility 
// of CmpFn outside this source file.

static int CALL_CONV_FOR_QSORT CmpFn(const void *dblone,const void *dbltwo ){
	double a = *(double *)dblone;
	double b = *(double *)dbltwo;
	return ( a > b ) ? 1 : ( b > a ) ? -1 :0;
}

////////////////////////////////////////////////////
// QSORT - Sort a double array
// It just makes a call to qsort library function 
//

extern "C" EXPORTED_FUNC void STDCALL_CONV QSORT( double *arr , int nelem ) {
	qsort(arr,nelem,sizeof(double),CmpFn);
}


