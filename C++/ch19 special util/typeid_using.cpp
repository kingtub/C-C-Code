#include<iostream>
#include<typeinfo>

// typeid����������Ľ����һ��������������ã��ö���������Ǳ�׼������type_info����type_info�Ĺ����������͡�type_info�ඨ����typeinfoͷ�ļ��С�
using namespace std;

class A {
	public:
	virtual void print() {
		cout<<"It's A"<<endl;
	}
};

class B:public A {
	public:
	void print() {
		cout<<"It's B"<<endl;
	}
};

class C {
	public:
	void pC() {
		cout<<"It's C"<<endl;
	}
};

class D:public C {
	public:
	void pC() {
		cout<<"It's D"<<endl;
	}
};


void test1();
void test2();

int main()
{
	test1();
	
	test2();
	return 0;
} 

void test1()
{
	int i, a[10];
	const type_info &ti = typeid(i), &tia = typeid(a);
	A ac;
	B b;
	cout<<ti.name()<<endl;
	cout<<tia.name()<<endl;
	cout<<typeid(ac).name()<<endl;
	cout<<typeid(b).name()<<endl;
}

void test2() {
	B *b = new B;
	A *a = b;
	
	cout<<boolalpha;
	
	// ע�⣬typeidӦ�������ڶ����������ʹ��*b����b��
	if(typeid(*a) == typeid(*b)) {
		cout<<"typeid(*a) == typeid(*b) is "<<(typeid(*a) == typeid(*b))<<endl;
	} else {
		cout<<"Not same type:"<<(typeid(*a) == typeid(*b))<<endl;
	}
	
	if(typeid(*a) == typeid(B)) {
		cout<<"typeid(*a) == typeid(B) is "<<(typeid(*a) == typeid(B))<<endl;
	} else {
		cout<<"Not same type:"<<(typeid(*a) == typeid(B))<<endl;
	}
	
	//ֻ�е������ͺ����麯��ʱ���������Ż�Ա��ʽ��ֵ����֮����������Ͳ������麯������typeid���ر��ʽ�ľ�̬���͡�
	D *d = new D;
	C *c = d;
	cout<<(typeid(*d) == typeid(*c))<<endl;
	
	cout<<noboolalpha;
}