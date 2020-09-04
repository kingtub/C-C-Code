#include<iostream>
 
 using namespace std;
 
 typedef int I;
 
 using D = double;
 
 unsigned int getNum(); 
 void test1();
 void test2();
 
 int main()
 {
// 	test1();
    test2();
 	return 0;
 }
 
 unsigned int getNum() {
 	return 0;
 }
 
void test1() {
    I i = 0;
 	D s = 3.14159;
 	cout<<i<<endl;
 	cout<<s<<endl;
}

void test2() {
	decltype(getNum()) ui;
	ui = -1;
	cout<<ui<<endl;
	
	auto b = ui;
	b = -2;
	cout<<b<<endl;
}