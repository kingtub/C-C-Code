#include<iostream>
#include<string>

using namespace std;

template <typename T> void aa(const T &t) {
	cout<<"aa(const T &t)"<<endl;
}

template <typename T> void aa(T *t) {
	cout<<"aa(T *t)"<<endl;
}

void aa(string *t) {
	cout<<"aa(string *t)"<<endl;
}

int main()
{
	aa(3);
	int i;
	aa(&i);
	
	string s = "";
	const string *sp = &s; 
	// ���ж������ģ���һ�������ṩͬ���õ�ƥ��ʱ��
    // Ӧѡ�����������İ汾 
	aa(sp);
	
	string *sp2 = &s; 
	// ��ģ�庯����ģ�庯����ȣ�����ѡ���ģ�� 
	aa(sp2); 
	
	// ���ǣ�����Ҫ����ת������const char * ת��string�����粻��ת����ģ���� 
	aa("abc"); 
	return 0;
}