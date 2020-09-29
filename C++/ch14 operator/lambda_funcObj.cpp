#include<iostream>

using namespace std;

int main()
{
	auto bigger = [](int a, int b) {
		return a > b?a:b;
	};
	int a = 3, b= 5;
	cout<<bigger(a, b)<<endl;
	cout<<bigger(1, 2)<<endl;
	return 0;
}