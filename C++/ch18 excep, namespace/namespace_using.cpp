#include<iostream>

using namespace std;

// 命名空间可以是不连续的。
namespace A {
	int aI = 15;
	namespace B {
		double pi = 3.14;
	}
	inline namespace C { // C++ 11 新增的 
		double huangjin = 0.618;
	} 
	// 关键字inline必须出现在命名空间第一次定义的地方，后续再打开命名空间的时候可以写inline，也可以不写。
	void p1() {
		//cout<<pi<<endl;//出错
        cout<<B::pi<<endl;
        cout<<huangjin<<endl;
	}
	
}

namespace A {
	void printI() {
		cout<<aI<<endl;
	}
}

// 定义在未命名的命名空间中的名字可以直接使用，毕竟我们找不到什么命名空间的名字来限定它们；
// 同样的，不能对它的成员使用作用域运算符。
namespace {
	double  ki = 0.888;
}

//命名空间别名
namespace A2 = A;
namespace B2 = A::B;

void test1();

int main()
{
	test1();
	return 0;
}

void test1()
{
	A::printI();
	A::p1();
	cout<<ki<<endl;
	
	A2::p1();
	cout<<B2::pi<<endl;
}