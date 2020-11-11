#include<iostream>
#include<string>

using namespace std;

class A {
	public:
	A(const string &t=""):s(t){
		
	}
	
	void pA() {
		cout<<"pA()"<<endl;
	} 
	void pB() {
		cout<<"pB()"<<endl;
	} 
	string s;
};

void test1();
void test2();

int main()
{
	//test1();
	
	test2();
	return 0;
}

void test1() 
{
	// 数据成员指针 
	const string A::*ps;
	ps = &A::s;
	
	A a=string("Hello"), *pa = &a;
	
	const string& ks = a.*ps;
	const string& ns = pa->*ps;
	cout << ks<<endl;
	cout<< ns<<endl;
}

void test2()
{
	// 成员函数指针
	 void (A::*pf)();
	 pf = &A::pA;
	 A a;
	 (a.*pf)();
	 
	 auto pf2 = &A::pB;
	 (a.*pf2)();
}