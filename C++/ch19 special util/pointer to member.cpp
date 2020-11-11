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
	// ���ݳ�Աָ�� 
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
	// ��Ա����ָ��
	 void (A::*pf)();
	 pf = &A::pA;
	 A a;
	 (a.*pf)();
	 
	 auto pf2 = &A::pB;
	 (a.*pf2)();
}