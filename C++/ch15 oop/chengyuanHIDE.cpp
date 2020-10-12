#include<iostream>

using namespace std;
// 关键字 struct和class 的区别，只有默认访问属性 ，和默认派生属性，其他的毫无区别 
struct A {
	void fun() {
		cout<<"A::fun()"<<endl;
	}
}; 

struct B : A {
	// 虽然形参列表不一样，fun(int)会把fun()隐藏 
	void fun(int i) {
		cout<<"B::fun(int)"<<endl;
	}
};

 
int main()
{
	A a;
	B b;
	a.fun();
	b.fun(10);
	// b.fun();// 错误， // 虽然形参列表不一样，fun(int)会把fun()隐藏 
	//正确
	b.A::fun(); 
	
	return 0;
}