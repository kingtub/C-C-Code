#include<iostream>
#include<utility>

using namespace std;

// 我们可以销毁一个移后源对象，也可以给它赋新值，
// 但不能使用一个移后源对象的值 
void add(int &i);
void add(int &&i);

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
	
	// 移动构造函数 
	Foo(Foo &&o)noexcept {
		cout<<"Move constructor"<<endl;
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
	
	// copy-assignment operator, 拷贝赋值运算符
	Foo& operator=(const Foo &a); 
	// move-assignment operator, 移动赋值运算符
	Foo& operator=(Foo &&a) noexcept;
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

Foo& Foo::operator=(Foo &&a) noexcept
{
	
	if(this != &a) {
		name = a.name;
		k = a.k;
		cout<<"move-assignment operator,移动赋值运算符"<<endl;
	}
	
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

void test1()
{
    int i = 8; 
	//变量是左值 
	add(i);
	// 表达式、字面值是右值、move之后是右值 
	add(10); 
	add(i + 1); 
	add(move(i)); 
}

void test2()
{
	Foo f1("aa", 3);
	Foo f2(move(f1));
	
	Foo f3("bb", 123);
	Foo f4;
	f4 = move(f3);
}

void add(int &i)
{
	cout<<"传入左值引用"<<i<<endl; 
}
void add(int &&i)
{
	cout<<"传入右值引用"<<i<<endl;
}