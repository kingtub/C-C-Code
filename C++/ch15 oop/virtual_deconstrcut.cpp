#include<iostream>

using namespace std;

class A {
	public:
	// ����������һ���������������������ǻᱻ�̳еġ� 
	// ֻҪ����������������麯��������ȷ��������delete����ָ��ʱ��������ȷ�����������汾�� 
	
	// ���������������������麯������deleteһ��ָ�����������Ļ���ָ�뽫����δ�������Ϊ�� 
	virtual ~A() {
		cout<<"A::~A()"<<endl;
	}
};

class B : public A {
	public:
	~B() {
		cout<<"B::~B()"<<endl;
	} 
};

int main()
{
	B *b = new B;
	delete b;
	
	A a;
	// �ϳɵĿ������캯�� 
	A a2(a); 
	return 0;
} 