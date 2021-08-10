#include <windows.h>
#include <stdio.h>


//----------------
//------- Ourclass.h
extern "C" {
     int    __stdcall Add( int a, int b ) ;
     int __stdcall Sub(int  a, int  b );
      int    __stdcall Mul( int a, int b ); 
      int __stdcall Div(int  a, int  b ) ;
}


int main(int argc, char **argv )
{

      if ( argc != 3 ) {
            fprintf(stdout, "Usage: first <number> <number> \n");
            fprintf(stdout, " first 2 4   or  first 1 4 \n");
            return -1;
      }

       int a = atoi(argv[1]);
       int b = atoi(argv[2]);

       printf("The Output is %d\n",Add(a,b));
       printf("The Output of Sub is %d\n",Sub(a,b));
       printf("The Output of Mul is %d\n",Mul(a,b));
       printf("The Output of Div is %d\n",Div(a,b));
       return 0; //finished without error

}