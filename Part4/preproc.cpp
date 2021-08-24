

//-------------- We are pasting string here
//--------------- Before the type system starts it work
#define MAX_CUSTOM(x,y)  ( (x) < (y) ? y : x )

//----------------- This is part of the language proper
//------------------ Type system aware
template <class T> 
const T& max (const T& a, const T& b) {
  return (a<b)?b:a;     
}
int main( int argc, char *argv )
{
      printf("%d\n", MAX_CUSTOM(2*4 + 5 , 34 ));
      printf("%d\n", max(2*4 + 5 , 34 ));

}