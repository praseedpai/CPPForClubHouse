////////////////////////////////////
// rt.cpp
// A Simple Visual C/C++ program to demonstrate
// the realloc function can be used as a kernel
// for implementing malloc , calloc , free etc.
//
// The program is written for demonstration purporse
// only 
//
//
// Written by Praseed Pai K.T.
//            http://praseedp.blogspot.com
//
// cl rt.cpp 
// rt
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////
//
//
//  This is a wrapper over realloc function...
//
//
void *t_realloc( void *ptr , int size ) {
   return realloc(ptr,size);
}

//////////////////////
//
// malloc implemented using realloc
//
//

void *t_malloc(  int size )
{
   return t_realloc( 0 , size );

}

/////////////////////////////////////
//
// free implemented using realloc
//
//
void *t_free( void *ptr )
{
    return t_realloc(ptr,0);
}

///////////////////////////
//
//
// calloc implemented using t_malloc (in turn calls t_realloc )
//
void *t_calloc( int elem , int elemsize ) {

   char *ptr = (char *)t_malloc(elem*elemsize);
   memset(ptr,0,elem*elemsize); 
   return ptr;
}

///////////////////////////////
//
//
//  The Entry point ...
//
//
int main( int argc , char **argv )
{

     long *ptr = (long *)t_calloc( 5,4 );
     long i=0;
     long *tptr = ptr;

     if ( tptr == 0 )
            return -1;

     


     while (i<5 )
     {
    *tptr ++ = i++;
     }     


     for( int j=0; j<5; ++j )
        printf("%d\n",ptr[j] );
     #undef realloc
     #define realloc t_realloc
     ptr = (long *)realloc( ptr , 40 );
     #define realloc realloc
     for( int j=0; j<10; ++j )
        ptr[j] = j ;    

     for( int j=0; j<10; ++j )
        printf("%d\n",ptr[j] ); 

      t_free(ptr);

}

