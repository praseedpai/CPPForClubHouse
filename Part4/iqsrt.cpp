#include <stdio.h>
#include <stdlib.h>


//---- A comparitor for the double ....
 int __cdecl cmp_double( const void *a , const void *b ){
          double *pa = (double *) a; // casting void * to double *
          double *pb = (double *) b; // casting void * to double *
          //----- signum function 
          return ( (*pa > *pb) ? 1 : (*pa < *pb )? -1 : 0 );
}

//---- A comparitor for the int ....
 int __cdecl cmp_int( const void *a , const void *b ){
          int *pa = (int *) a; // casting void * to int *
          int *pb = (int *) b; // casting void * to int *
          //----- signum function 
          return ( (*pa > *pb) ? 1 : (*pa < *pb )? -1 : 0 );
}
///////////////////////////////////////
//
// Main is the user entry point ...
// Think about this ..Who calls main ?
//
//
int main( int argc , char **argv ) {
                  //----- in some languages , argv[0] is from where actual argument starts
                  // in C/C++ - name of the executable file is stored @ argv[0]
	if ( argc == 1 ){
		fprintf(stdout,"No command line arguments\n");
		return -1;
	}
                  //---------------- find out the number of arguments
	int num = argc-1;
                  //-------------- malloc, realloc , calloc , free etc forms the backbone of C/C++ memory management
                  //  double [] arr = new double[ num ];
                  //  sizeof(<datatype>) is a compile time unary operator 
	int*arr = (int *) malloc(num*sizeof(int)); // returns void * , we need to cast it
	if ( arr == 0 ) { fprintf(stdout, "Memory Allocation failure\n"); return -1; }
                 // ----- parr stores the pointer to newly allocated buffer (arr)
	int *parr = arr;
                  //------------ point to the start of the actual arguments
	char **nums = &argv[1];  // & is the address of operator

                  //----- move through the command line arguments
	while (num--)  { *parr++ = atoi(*nums++); }   // atoi => ascii to int

                  //------------------ Sort the values --- use qsort routine..
                  qsort(arr,argc-1,sizeof(int), cmp_int);
	//------------- Let us spit the content of the array 
	num = 0;
	while (num < argc-1 ) { printf("%d\n",arr[num++]); }

                  //------------- Free the dynamic array 
	free(arr);
	return 0;
     
} // EOF main


