using System;

using System.Runtime.InteropServices;

class Test
{
       [DllImport("MathSub.dll")]
       static extern int Add(int a, int b );

       public static void Main(String [] args )
       {
                  int n = Add(10,10);
	Console.WriteLine("Value is {0}",n);
         }


}