//---- fifth.cpp
// ------------------ How to write your own malloc
//------------------ https://github.com/pradeep-subrahmanion/TraceMalloc
// Another allocator @ https://github.com/miguelperes/custom-malloc

#include <stdio.h>
#include <stdlib.h>
//------ Program to demonstrate swapping values with pointers
//---------------- Pass by Pointer
void Swap( int * x, int *y )
{
     //---- Swap logic goes here
     int temp = *x;
     *x = *y;
     *y = temp;
}
//----------------- Pass by Refence C++ intrinsic pointer
void Swap( int& x, int& y )
{
     //---- Swap logic goes here
     int temp = x;
     x = y;
     y = temp;
}
int main( int argc , char **argv )

{
            if ( argc !=3 )
               return -1;

           int a = atoi(argv[1]);
           int b = atoi(argv[2]);

           printf("Before Swap : %d\t%d\n", a , b );
           Swap(a,b);  //           Swap(&a, &b );
           printf("After Swap : %d\t%d\n", a , b );
}
