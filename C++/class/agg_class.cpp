#include<iostream>

using namespace std;

// �ۺ��࣬���г�Ա�ǹ����ģ��޹��캯�����޳�ʼֵ���޻��࣬��virtual���� 
class A{
	public:
		int i;
		string s;
};

struct B {
	string name;
	double score;
};

int main()
{
	A a = {3, "abc"} ;
	cout<<a.i<<endl;
	cout<<a.s<<endl;
	
	B b = {"mars", 75.5};
	cout<<b.name<<endl;
	cout<<b.score<<endl;
	return 0;
}