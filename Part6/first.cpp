#include <stdio.h>

//  & - AddressOf Operator (Taking a Reference)
//  *  - How to Dereference a Pointer
int main( int argc, char **argv )
{
    int i = 20;
    //--------------- Take the address of I and assign
    //-------------- it to X
    int * x =   &i;

    printf("The Value is %d\t %d\n", i, *x );




}