#include<iostream>

using namespace std;

class A {
	public:
	A() = default;
	~A() {
		cout<<"A 的析构函数执行"<<endl;
	}
}; 
class Foo {
	public:
	Foo() = default;
	Foo(const string &s, int i):name(s), k(i){
		cout<<"Cons 2"<<endl; 
	}
	//拷贝构造函数，当一个构造函数是以类自己类型为参数，且其他参数已有默认值时，
	// 它是拷贝构造函数 
	Foo(const Foo &o) {
		cout<<"Copy cons"<<endl;
		name = o.name;
		k = o.k;
	}
	
	~Foo() {
		// 析构的过程和构造过程是类似的，分为2部分：函数体部分和析构部分
		// 先执行函数体部分，在执行析构部分
		// 函数体时能够由 程序员控制的，用来做一些清理工作
		// 析构部分是隐式的，程序员控制不到 ，系统自动执行
		
		// 在所有情况下，系统会自动调用 成员name 和 ai的析构函数
		cout<<"Foo 的析构函数执行"<<endl;
	} 
	
	// copy-assignment operator,拷贝赋值运算符
	Foo& operator=(const Foo &a); 
	private:
	string name;
	int k; 
	A ai;
};

Foo& Foo::operator=(const Foo &a)
{
	name = a.name;
	k = a.k;
	
	cout<<"copy-assignment operator,拷贝赋值运算符"<<endl;
	
	return *this;
}

void test1(); 
void test2();

int main()
{
	//test1();
	
	test2();
	return 0;
}

void test1() {
    Foo f1("Hi", 6);//直接初始化 
	Foo f2 = f1; // 拷贝初始化 
	
	
	string dots(10, '.') ; //直接初始化 
	string s(dots);        //直接初始化 
	string s2 = dots;      // 拷贝初始化 
	string null_book = "Iso-999";  // 拷贝初始化 
	string nines = string(100, '9');  // 拷贝初始化 
	
	// 拷贝初始化 还发生在以下几种情况：
	// 1、把一个对象作为实参，传给函数中的非引用类型的形参 
	// 2、从一个返回类型为非引用类型的函数中返回一个对象 
	// 3、用花括号列表初始化一个数组或一个聚合类的成员 
}

void test2() {
	Foo f;
	Foo f2("Good", 3);
	f = f2;
}

