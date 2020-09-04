#include<iostream>

using namespace std;

 void test1();
 void test2();
 void error1();
 void test3(); 
 
 int main()
 {
 	//test1();
 	//test2();
 	//error1();
 	test3();
 	return 0;
 } 
 
 void test1() {
 	bool b = 42;
 	cout<<b<<endl;
 	int i = b;
 	cout<<i<<endl;
 	i = 3.42;
 	cout<<i<<endl;
 	double p = i;
 	cout<<p<<endl;
 	
 	unsigned char c = -1;
 	signed char c2 = 256;
 	
 	cout<<c<<endl;
 	cout<<c2<<endl;
 }
 
 void test2() {
 	bool b1 = -2;
 	bool b2 = 3;
 	
 	bool b3 = 0;
 	
 	
    cout<<(b1?"yes":"no")<<endl;
    cout<<(b2?"yes":"no")<<endl;
    cout<<(b3?"yes":"no")<<endl;
 }
 
 void error1() {
 	int i = -42;
 	unsigned int u = 10;
 	
 	cout<<(i + i)<<endl;
 	cout<<(i + u)<<endl;
 	
 	unsigned int uc1 = 10, uc2 = 42;
 	cout<<(uc2 - uc1)<<endl;
 	// 警告 无符号数不会小于0 
 	cout<<(uc1 - uc2)<<endl;
 }
 
 void test3() {
 	int i = 20;
	int j = 024;
	int k = 0x14;
	cout<< i << endl; 
	cout<< j << endl; 
	cout<< k << endl; 	
 }