#include<iostream>

using namespace std;

class A {
	public:
	void pubM() {
		cout<<"A::pubM"<<endl;
	}
	protected:
	void asProtected() {
		cout<<"asProtected"<<endl;
	}
	
	private:
	void As_private() {
		cout<<"As_private"<<endl;
	}
	
};

class B:public A {
	public:
	void Bpub() {
		asProtected();
	}
};

class C:private A {
	public:
	void CPub() {
		asProtected();
	}
};

// 使用using改变可访问性 
class D:private A {
	public:
	void CPub() {
		asProtected();
	}
	// 使用using改变可访问性 
	using A::pubM;
};

int main()
{
	// 派生访问说明符： 对于派生类成员（及友元）能否访问其直接基类的成员没有影响。公有继承或私有继承时，派生类成员函数，都可访问直接基类的protected、public成员，都不可访问private成员。
    // 派生访问说明符的目的是控制派生类用户（包括派生类的派生类）对基类成员的访问权限。
	B b;
	C c;
	b.Bpub();
	c.CPub(); 
	
	b.pubM();
	//c.pubM();// error, private 继承 
	
	D d;
	d.pubM();
}