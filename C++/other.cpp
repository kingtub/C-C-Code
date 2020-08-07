#include<iostream>

using namespace std;

void test1();
void test2();
void test3();

int main()
{
	//test1();
	// test2();
	test3();
	return 0;
}

void test1() {
		int a[] = {
		1, 2, 3,4, 5
	};
	
	for(int i:a)
        cout<<i<<" ";
	cout<<endl;
}

void test2() {
	int i(5);
	cout<< i<<endl;
}

void test3() {
	for(int i = 1; i <= 0x7F; i++)
	cout<<(char)i<<" ";
}
