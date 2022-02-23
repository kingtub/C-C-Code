#include <iostream> 

using namespace std;
enum struct EA:int
{
    A=1,
    B=3
};
int main ()
{
  int i = 3;
  EA k = static_cast<EA>(i);
  if(k == EA::B) {
      cout << "yes"<<endl;
  } else {
      cout<< "no"<<endl;
  }
  
  return 0;
}
