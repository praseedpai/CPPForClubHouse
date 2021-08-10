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

       typedef int (__stdcall *BIN_FUNC)(int , int );
       BIN_FUNC padd, psub, pmul, pdiv;

       HMODULE h = (HMODULE)LoadLibrary("MathSub.dll");
       if ( h == INVALID_HANDLE_VALUE ) {
	printf("Failed to Load the DLL\n");
	return -1;
       }

       padd = (BIN_FUNC)GetProcAddress(h, "_Add@8");
       psub = (BIN_FUNC)GetProcAddress(h, "_Sub@8");
       pmul = (BIN_FUNC)GetProcAddress(h, "_Mul@8");
       pdiv = (BIN_FUNC)GetProcAddress(h, "_Div@8");

       if ( padd == 0 || psub == 0 || pmul == 0 || pdiv == 0 )
       {
                     fprintf(stderr,"Failed to retrieve Function pointer\n");
                     return (-2);
        }
      

       
       printf("The Output is %d\n", (*padd) (a,b));
       printf("The Output of Sub is %d\n", psub(a,b));
       printf("The Output of Mul is %d\n",(*pmul)(a,b));
       printf("The Output of Div is %d\n",(*pdiv)(a,b));
       FreeLibrary(h);
       return 0; //finished without error

}