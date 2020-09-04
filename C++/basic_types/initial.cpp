#include<iostream>

using namespace std;

void test1();
int main()
{
	test1();
	return 0;
} 

void test1() {
	int a = 3;
	int b(3);
	int c = {
		3
	};
	
	int d{
		3
	};
	
	cout<<a<<b<<c<<d<<endl;
}
