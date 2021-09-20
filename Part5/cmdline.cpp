///////////////////////////////
//nine.cpp
//A simple program which spits the
//command line arguments in a form
//which C/C++ startup code stores
//command line argument in an array.
//This program is to be run with 
//various command line arguments. 
//  g++ -o nine.exe nine.cpp   
//  cl /Fenine.exe nine.cpp
#include <stdio.h>
int main( int argc , char **argv ){
  for(int i=0;i<argc;++i ){
     char *temp = argv[i];
     printf("argv[%d]--> ",i);
     char *itemp = temp;
     while (*itemp != 0 ){
         printf("[%c]",*itemp);
         itemp++;         
     } // end while
     printf("[\\0]\n");
   }  // end for 
}