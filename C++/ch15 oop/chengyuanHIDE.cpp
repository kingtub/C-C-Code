#include<iostream>

using namespace std;
// �ؼ��� struct��class ������ֻ��Ĭ�Ϸ������� ����Ĭ���������ԣ������ĺ������� 
struct A {
	void fun() {
		cout<<"A::fun()"<<endl;
	}
}; 

struct B : A {
	// ��Ȼ�β��б�һ����fun(int)���fun()���� 
	void fun(int i) {
		cout<<"B::fun(int)"<<endl;
	}
};

 
int main()
{
	A a;
	B b;
	a.fun();
	b.fun(10);
	// b.fun();// ���� // ��Ȼ�β��б�һ����fun(int)���fun()���� 
	//��ȷ
	b.A::fun(); 
	
	return 0;
}