#include<iostream>

using namespace std;

template <typename A, typename B, typename C>
C add(const A& a, const B &b) {
	return a + b;
} 

template <typename T>
void check(const T&t, const T& p) {
	
}

int main()
{
	// 将实参传递给带模板类型的函数形参时，能够自动应用的类型转换只有const转换及数组或函数到指针的转换。
	
	// 但是显式指定实参类型的，可以进行正常类型转换 
	long ll = add<double, int, long>(2.0, 10);
	cout<<ll<<endl;
	int i = add<int, int, int>(2.0, 3.0);
	cout<<i<<endl;
	
	//check(1, 3.0);// 错误，因为类型不同，编译器推断不出要哪个类型 
	check(0.0, 0.5);
	return 0;
}