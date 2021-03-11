#include<iostream>
#include<atomic>

using namespace std;

void test1();
int main()
{
	test1();
	return 0;
}

void test1()
{
    atomic<bool> ab(true);
	bool before = bool(ab);
	bool after = (ab = false);
	cout<<boolalpha;
	cout<<"before:"<<before<<" , after:"<<after<<endl;
	cout<<noboolalpha;
}