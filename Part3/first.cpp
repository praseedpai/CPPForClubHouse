#include <stdio.h>

extern "C"  int Add(int a, int b ); // function prototype
extern "C"  int Mul(int a, int b ); 
int main( int argc, char **argv )
{
      printf("The Value is %d\t %d\n", Add(3,4),Mul(2*3, 4));

}
