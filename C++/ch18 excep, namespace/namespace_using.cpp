#include<iostream>

using namespace std;

// �����ռ�����ǲ������ġ�
namespace A {
	int aI = 15;
	namespace B {
		double pi = 3.14;
	}
	inline namespace C { // C++ 11 ������ 
		double huangjin = 0.618;
	} 
	// �ؼ���inline��������������ռ��һ�ζ���ĵط��������ٴ������ռ��ʱ�����дinline��Ҳ���Բ�д��
	void p1() {
		//cout<<pi<<endl;//����
        cout<<B::pi<<endl;
        cout<<huangjin<<endl;
	}
	
}

namespace A {
	void printI() {
		cout<<aI<<endl;
	}
}

// ������δ�����������ռ��е����ֿ���ֱ��ʹ�ã��Ͼ������Ҳ���ʲô�����ռ���������޶����ǣ�
// ͬ���ģ����ܶ����ĳ�Աʹ���������������
namespace {
	double  ki = 0.888;
}

//�����ռ����
namespace A2 = A;
namespace B2 = A::B;

void test1();

int main()
{
	test1();
	return 0;
}

void test1()
{
	A::printI();
	A::p1();
	cout<<ki<<endl;
	
	A2::p1();
	cout<<B2::pi<<endl;
}