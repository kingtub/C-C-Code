#include<iostream>

using namespace std;

template <typename T, typename... Args>
// Args表示零个或多个模板类型参数
void foo(const T &t, const Args & ... rest) {
	// rest 表示零个或多个函数参数 
	cout<<t<<endl;
	cout<<sizeof...(Args)<<endl;  // 类型参数的数目 
	cout<<sizeof...(rest)<<endl;  // 函数参数的数目 
}


int main()
{
	int a[1];
	foo(1, 0.5, 6, 8, "", a);
	return 0;
}