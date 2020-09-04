#include<iostream>
using namespace std;

void test1();
void test2();
 
int main()
{

	test2();
	return 0;
}

void test1() {
    int a = 8;
    int &b = a;
    b = 18;
	cout << a<<endl;
	cout<< &a<<endl;
	cout<< &b<<endl;
}

void test2() {
	int *p = nullptr;
	int i = 20;
	cout<< &p << endl;
	p = &i;
	cout<< &p << endl;
	
	int *&r = p;
	cout<< &r << endl;
}

