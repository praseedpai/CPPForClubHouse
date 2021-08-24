#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(push)
#pragma pack(1)
typedef struct
{
   char name[50];
   int age;
   double salary;
}FRIEND;

#pragma pack(pop)
typedef struct
{
   char name[50];
   int age;
   char buf[17];
   double salary;
  
}FRIEND2;


FRIEND  pglobal[] = { { "Sarath",31,78.23 },{ "Binu",35,84.23 },
                      { "Vysakh",33,79.33},
                       {"Akhilesh",20,100}};

//---- A comparitor for the double ....
 int __cdecl cmp_double( const void *a , const void *b ){
          double *pa = (double *) a; // casting void * to double *
          double *pb = (double *) b; // casting void * to double *
          //----- signum function 
          return ( (*pa > *pb) ? 1 : (*pa < *pb )? -1 : 0 );
}

//---- A comparitor for the int ....
 int __cdecl cmp_int( const void *a , const void *b ){
          int *pa = (int *) a; // casting void * to int *
          int *pb = (int *) b; // casting void * to int *
          //----- signum function 
          return ( (*pa > *pb) ? 1 : (*pa < *pb )? -1 : 0 );
}

//-------------------- Comparitor for FRIENDS
int __cdecl cmp_friend_byname( const void *a , const void *b ){
          FRIEND *pa = (FRIEND *) a; // casting void * to int *
          FRIEND *pb = (FRIEND *) b; // casting void * to int *
          //----- signum function 
          return ( strcmp(pa->name, pb->name));
}

int __cdecl cmp_friend_byage( const void *a , const void *b ){
          FRIEND *pa = (FRIEND *) a; // casting void * to int *
          FRIEND *pb = (FRIEND *) b; // casting void * to int *
          //----- signum function
          return ( ( pa->age  > pb->age)  ? 1 : (pa->age<pb->age)? -1 : 0);
}
///////////////////////////////////////
//
// Main is the user entry point ...
// Think about this ..Who calls main ?
//
//
int main( int argc , char **argv ) {
                 

                  printf("The size of struct is %d\t%d\n", sizeof(FRIEND),sizeof(FRIEND2));

                  //------------------ Sort the values --- use qsort routine..
                  qsort(pglobal,4, sizeof(FRIEND),cmp_friend_byname);
	//------------- Let us spit the content of the array 
	int num = 0;
	while (num < (sizeof(pglobal)/sizeof(pglobal[0]))) { printf("%s\n",pglobal[num].name); num++;}
                  printf("----------------------------------------------------\n");
                  qsort(pglobal,4, sizeof(FRIEND),cmp_friend_byage);
                  num = 0;
	while (num < 4 ) { printf("%s\t%d\n",pglobal[num].name,pglobal[num].age); num++;}

                  //------------------ Now , do the same thing with pointer
                  FRIEND *ptr = &pglobal[0];
                  num = 0;
	while (num < 4 ) { printf("%s\t%d\n",ptr->name,ptr->age); ptr++; num++;}



	return 0;
     
} // EOF main


