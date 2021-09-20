//------------- fourth.cpp
#include <stdio.h>
#include <stdlib.h>

//------------ Demonstrates Heap Allocation
// & pointer arithmetic
int main( int argc, char **argv )
{
        //-------------- Detecting whether command line arguments exists or not
       // By default, argv[0] contains the Exe name
        if ( argc == 1 ) {
              fprintf(stdout, "No Command Line Arguments");
              return -1;
        }
         //------------- actual arguments is one less than the command line arguments
         int num_args = argc - 1;

         //------------ Allocate memory on the heap
         // malloc , allocates in bytes.... we need request memory chunks in bytes
         // returns a void *
         double *values = ( double *) malloc(num_args*sizeof(double));
         //------ temp contains actual number of arguments
         int temp = num_args;
         //--------------- pointer pvalues ....points at values array
         double *pvalues = values;
         int i = 1;
         char **lptr = &argv[1];
         while ( temp-- )
          {
                *pvalues =    atof(*lptr);  // atof(argv[i]);
              //  i++;
                 pvalues++;   
                 lptr++;  
           }
         ///---- resetting the pointers
         pvalues = values;
         i=0;
         while ( i <  num_args ) {
                 printf("%g\t %p\n", *pvalues , pvalues++);
                 i++;
          }
         free(values);


}