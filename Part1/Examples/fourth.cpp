#include <stdio.h>
#include <iostream>
using namespace std; 
int main( int argc, char **argv , char **envp )
{
     //------- 
     printf("Hello World....\n");
     try {
     cout << "Hello World...\n";
     }
     catch(...)
     {
           printf("Exception caught\n");
      }

      //------------ C/C++ supports variable length arguments
      // environment variable  is encoded as : = "Key1=Value1\0Key2=Value2\0Key3=Value3\0\0"
      // char *tempenv = "Key1=Value1\0Key2=Value2\0Key3=Value3\0\0"
      // char **tempenv =[ "Key1=Value1\0" , "Key2=\0Value2\0" , "Key3=Value3\0", "\0\0"]
      
      char **tempenv = envp;

      while (  *(tempenv +1 ) != 0)
       {
                puts( *tempenv);
                tempenv++;
        }

}