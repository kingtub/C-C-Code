#include<iostream>
#include<string>

using namespace std;

// 普通类的成员模板
class A {
	public:
	template <typename T> const T& bigger(const T &a, const T &b) {
		if(a < b) {
			return b;
		} else {
			return a;
		}
	}
};

// 类模板的成员模板
// 对于类模板，我们也可以为其定义成员模板。在此情况下，类和成员各自有自己的、独立的模板参数。
template <typename T> class B {
	public:
	// 构造函数是函数模板 
	template <typename K> B(const K &k);
	
	template <typename P> const P& smaller(const P &a, const P &b);
}; 
template<typename T>
template<typename K>
B<T>::B(const K &k) {
	cout<<k<<endl;
}

template<typename T>
template<typename I> 
const I& B<T>::smaller(const I &a, const I &b) {
	if(a < b) {
		return a;
	} else {
		return b;
	}
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
	A a;
	cout<<a.bigger(3, 5)<<endl;
	cout<<a.bigger("vector", "string")<<endl;
}

void test2()
{
	// 编译器根据 函数模板的实参来推断它的实参类型； 
	B<int> b(5.0);
	// 将实参传递给带模板类型的函数形参时，
	// 能够自动应用的类型转换只有const转换及数组或函数到指针的转换。 
	cout<<b.smaller("hhu", "kkk")<<endl; // 字符指针地址的大小比较，有歧义？ 
	cout<<b.smaller(string("hhu"), string("kkk"))<<endl; 
}