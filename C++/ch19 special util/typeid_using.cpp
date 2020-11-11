#include<iostream>
#include<typeinfo>

// typeid运算符操作的结果是一个常量对象的引用，该对象的类型是标准库类型type_info或者type_info的公有派生类型。type_info类定义在typeinfo头文件中。
using namespace std;

class A {
	public:
	virtual void print() {
		cout<<"It's A"<<endl;
	}
};

class B:public A {
	public:
	void print() {
		cout<<"It's B"<<endl;
	}
};

class C {
	public:
	void pC() {
		cout<<"It's C"<<endl;
	}
};

class D:public C {
	public:
	void pC() {
		cout<<"It's D"<<endl;
	}
};


void test1();
void test2();

int main()
{
	test1();
	
	test2();
	return 0;
} 

void test1()
{
	int i, a[10];
	const type_info &ti = typeid(i), &tia = typeid(a);
	A ac;
	B b;
	cout<<ti.name()<<endl;
	cout<<tia.name()<<endl;
	cout<<typeid(ac).name()<<endl;
	cout<<typeid(b).name()<<endl;
}

void test2() {
	B *b = new B;
	A *a = b;
	
	cout<<boolalpha;
	
	// 注意，typeid应该作用于对象，因此我们使用*b而非b。
	if(typeid(*a) == typeid(*b)) {
		cout<<"typeid(*a) == typeid(*b) is "<<(typeid(*a) == typeid(*b))<<endl;
	} else {
		cout<<"Not same type:"<<(typeid(*a) == typeid(*b))<<endl;
	}
	
	if(typeid(*a) == typeid(B)) {
		cout<<"typeid(*a) == typeid(B) is "<<(typeid(*a) == typeid(B))<<endl;
	} else {
		cout<<"Not same type:"<<(typeid(*a) == typeid(B))<<endl;
	}
	
	//只有当类类型含有虚函数时，编译器才会对表达式求值。反之，如果类类型不含有虚函数，则typeid返回表达式的静态类型。
	D *d = new D;
	C *c = d;
	cout<<(typeid(*d) == typeid(*c))<<endl;
	
	cout<<noboolalpha;
}