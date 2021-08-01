

// C/C++ language pushes parameters from right to left 
// C program to demonstrate working of 
// variable arguments to find average
// of multiple numbers.
#include <stdarg.h>
#include <stdio.h>
  
int average(int num, ...)
{
    va_list valist;
  
    int sum = 0, i;
  
    //=== initialize the variable length parameter processing
    va_start(valist, num);
    for (i = 0; i < num; i++) 
        sum += va_arg(valist, int);  // retrieve the next argument
  
    va_end(valist);  //---- finish the variable length processing 
  
    return sum / num;
}
  
// Driver code
int main()
{
    printf("Average of {2, 3, 4} = %d\n",
                         average(2, 3, 4));
    printf("Average of {3, 5, 10, 15} = %d\n",
                      average(3, 5, 10, 15));
    return 0;
}
