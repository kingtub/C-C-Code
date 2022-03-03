#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
struct A {
	int  i=5;
};

struct B {
	B(double d, string s){}
	int  b=10;
};
int main()
{
   unordered_map<int, A&> m;
   A dddd;
   m.emplace(std::piecewise_construct, std::forward_as_tuple(1), std::forward_as_tuple(dddd));
   A & a = m.at(1);
   cout<<a.i<<endl;
	
   unordered_map<int, B> mb;
   mb.emplace(std::piecewise_construct, std::forward_as_tuple(2), std::forward_as_tuple(0, ""));
   B & b = mb.at(2);
   cout<<b.b<<endl;
   return 0;
}
