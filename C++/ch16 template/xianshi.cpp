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
	// ��ʵ�δ��ݸ���ģ�����͵ĺ����β�ʱ���ܹ��Զ�Ӧ�õ�����ת��ֻ��constת�������������ָ���ת����
	
	// ������ʽָ��ʵ�����͵ģ����Խ�����������ת�� 
	long ll = add<double, int, long>(2.0, 10);
	cout<<ll<<endl;
	int i = add<int, int, int>(2.0, 3.0);
	cout<<i<<endl;
	
	//check(1, 3.0);// ������Ϊ���Ͳ�ͬ���������ƶϲ���Ҫ�ĸ����� 
	check(0.0, 0.5);
	return 0;
}