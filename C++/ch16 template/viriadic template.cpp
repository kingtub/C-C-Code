#include<iostream>

using namespace std;

template <typename T, typename... Args>
// Args��ʾ�������ģ�����Ͳ���
void foo(const T &t, const Args & ... rest) {
	// rest ��ʾ��������������� 
	cout<<t<<endl;
	cout<<sizeof...(Args)<<endl;  // ���Ͳ�������Ŀ 
	cout<<sizeof...(rest)<<endl;  // ������������Ŀ 
}


int main()
{
	int a[1];
	foo(1, 0.5, 6, 8, "", a);
	return 0;
}