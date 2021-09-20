//------------------ Third.cpp
#include <stdio.h>

//  & - AddressOf Operator (Taking a Reference)
//  *  - How to Dereference a Pointer
// --- All allocations in this program is being done at the Stack level
//------- To do heap allocation , one needs to use "malloc , calloc , realloc, free etc"
int main( int argc, char **argv )
{
     //-------------- float takes 4 bytes
     float x[] = { 10.0 , 20.0 , 40.0 , 50.0 , 60.0 };

     //-------- Print the value 
     for( int i=0; i< sizeof(x)/sizeof(x[0]) ; ++i )
        printf("%f\n", x[i]);

     float *px = x;   // &(x[0])
     int j = 0;

     while ( j < sizeof(x)/sizeof(x[0])) {
           printf("%f \t %p \n ", *px , px );
           j++;
           px++;  
         //  px =     ( float *) ((char *) px  + sizeof(float) );
     }


}