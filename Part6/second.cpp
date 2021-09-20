//------------------ Second.cpp
#include <stdio.h>

//  & - AddressOf Operator (Taking a Reference)
//  *  - How to Dereference a Pointer
// --- All allocations in this program is being done at the Stack level
//------- To do heap allocation , one needs to use "malloc , calloc , realloc, free etc"
int main( int argc, char **argv )
{
    int i = 20;
    float y = 20.0;
    //--------------- Take the address of I and assign
    //-------------- it to X
    int * x =   &i;
    //----------------- Address of Y and assign it to py
    float *py = &y;
    printf("The Value is %d\t %d\t %f\n", i, *x,*py );
  
    //----------------- Now change the value ponted by py
   *py = 25.0;
   //----------------------------- %p - will print the address of the pointer
    printf("The Value is %d\t %d\t %f\t %p\n", i, *x,*py, py );


}