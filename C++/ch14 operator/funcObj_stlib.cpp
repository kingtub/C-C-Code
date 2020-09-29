#include<iostream>
#include<functional>

using namespace std;

int main()
{
	plus<int> p;
	negate<double> nd;
	
	cout<<p(3, 5)<<endl;
	
	cout<<nd(-3.14)<<endl;
	
	cout<<nd(666)<<endl;
	return 0;
}