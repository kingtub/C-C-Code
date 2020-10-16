#include<iostream>
#include<string>

using namespace std;


// 模板定义以关键字template开始，后跟一个模板参数列表，
// 这是一个逗号分割的一个或多个模板参数的列表，用尖括号包围起来。
template <typename T> // 其中，模板类型参数关键字使用typename 或 class 
int compare(const T &left, const T &right) {
	if(left < right) {
		return -1;
	} else if(right < left) {
		return 1;
	} else {
		return 0;
	}
}

// 模板非类型参数，是一个常量值，例如数组大小。 
template <size_t N, size_t M>
int count(const int (&a)[N], const int (&b)[M]) {// 参数a是数组int s[N]的一个引用，b同理。 
	int count = 0;
	for(size_t j = 0; j != N; j++) {
		count += a[j];
	}
	for(size_t j = 0; j != M; j++) {
		count += b[j];
	}
	
	return count;
}

void test1();
void test2();
void test3();

int main()
{
	//test1();
	
	//test2();
	
	test3();
	
	return 0;
}


void test1()
{
	// 当我们调用一个函数模板时，编译器（通常）用函数实参来为我们推断模板实参。
	cout<<compare(1, 0)<<endl;
	cout<<compare(-3.5, -2.0)<<endl;
	cout<<compare(string("Hello"), string("good"))<<endl; 
}

void test2()
{
	//此种情况下，实参必须为常量表达式
	int a[] = {
		1, 2, 3
	};
	
	int b[] = {
		4, 5, 6, 7, 8, 9
	};
	
	cout<<count(a, b)<<endl;
}

void test3()
{
  class A {
		private:
		int i;
		public:
		A(int i):i(i){
			
		}
		bool operator<(const A &o) const {
			if(i < o.i) {
				return true;
			} else {
				return false;
			}
		}
	};
	
	A a1(5), a2(3);
	cout<<compare(a1, a2)<<endl;
}