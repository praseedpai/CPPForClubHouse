//////////////////////////////////////
// caller.cpp
//
// This program calls QSORT.dll or libQSORT.so
// depending on the platform
//
// Written by Praseed Pai K.T.
//            http://praseedp.blogspot.com
//
//
//  under Windows @ the Visual C/C++ command prompt
// -----------------------------------------------
// cl /D_WINDOWS caller.cpp 
//
// under GNU Linux and MAC OS X  @ the Terminal 
// --------------------------------------------
// g++ -o caller.exe caller.cpp -ldl
// ./caller.exe 10 -4 6 9
//
//

#include <stdio.h>
#include "EXAMPLE.h"


///////////////////////////////////////
//
// Main is the user entry point ...
// Think about this ..Who calls main ?
//
//

int main( int argc , char **argv )
{

	if ( argc == 1 ){
		fprintf(stdout,"No command line arguments\n");
		return -1;
	}

	int num = argc-1;
	double *arr = (double *) malloc(num*sizeof(double));

	if ( arr == 0 )
		return -1;

	double *parr = arr;
	char **nums = &argv[1];

	while (num--)
		*parr++ = atof(*nums++);

	QSORT_FUNC sorter;
	#ifdef _WINDOWS
		HMODULE hmodule;
		const char *dllname = "QSORT.dll";
	#else
		void *hmodule;
		const char *dllname = "./libQSORT.so";
	#endif
	if (!LOAD_DLL(hmodule,dllname))
	{
		fprintf(stdout,"Failed to load %s\n",dllname);
		return -1;
	}
	sorter = (QSORT_FUNC) GET_FUNC_PTR(hmodule,"QSORT");
	if ( sorter == 0 ) {

		fprintf(stdout,"failed to retrieve function pointer\n");
		return -2;
	}

	(*sorter)(arr,argc-1);
	num = 0;
	while (num < argc-1 )
		printf("%g\n",arr[num++]);

	free(arr); 

	UNLOAD_DLL(hmodule);

	return 0;

}

