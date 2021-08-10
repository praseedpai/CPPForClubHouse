//Adds two numbers
//_Add
extern "C"  __declspec(dllexport)  int    __stdcall Mul( int a, int b ) { return a*b ; }
//_Sub@8
extern "C"  __declspec(dllexport)  int __stdcall Div(int  a, int  b ) { return a /  b; }