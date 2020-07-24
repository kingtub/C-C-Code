#include<iostream>
using namespace std;

int main()
{
	int a = 8;
	int &b = a;
	b = 18;
	cout << a<<endl;
	cout<< &a<<endl;
	cout<< &b<<endl;
	
	return 0;
}
