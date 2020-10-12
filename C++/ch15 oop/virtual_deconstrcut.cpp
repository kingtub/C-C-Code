#include<iostream>

using namespace std;

class A {
	public:
	// 和其他函数一样，虚析构函数的属性是会被继承的。 
	// 只要基类的析构函数是虚函数，就能确保当我们delete基类指针时将运行正确的析构函数版本。 
	
	// 如果基类的析构函数不是虚函数，则delete一个指向派生类对象的基类指针将产生未定义的行为。 
	virtual ~A() {
		cout<<"A::~A()"<<endl;
	}
};

class B : public A {
	public:
	~B() {
		cout<<"B::~B()"<<endl;
	} 
};

int main()
{
	B *b = new B;
	delete b;
	
	A a;
	// 合成的拷贝构造函数 
	A a2(a); 
	return 0;
} 