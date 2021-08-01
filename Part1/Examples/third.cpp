#include <stdio.h>
#include <iostream>
using namespace std; 
int main( int argc, char **argv )
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

}