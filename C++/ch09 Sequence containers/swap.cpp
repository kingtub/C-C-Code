#include<iostream>
#include<string>
#include<list>
#include<vector>
#include"my_util.hpp"

using namespace std;

void test1();
int main()
{
	test1();
	return 0;
}

void test1()
{
	vector<string> v1 = {
		"asd", "fgh", "jkl"
	};
	
	vector<string> v2 = {
		"qwe", "rty", "uiop"
	};
	
	cout<<"before"<<endl;
	cout<<"v1:"<<endl;
	print_container(v1);
	cout<<"v2:"<<endl;
	print_container(v2);
	
		
	cout<<"\n\nThen"<<endl;
	// swap��������������ͬ�������������ݡ�����swap֮�����������е�Ԫ�ؽ��ύ����
	// ��array�⣬swap�����κ�Ԫ�ؽ��п�����ɾ��������������˿��Ա�֤�ڳ���ʱ������ɡ�
	swap(v1, v2);
	cout<<"v1:"<<endl;
	print_container(v1);
	cout<<"v2:"<<endl;
	print_container(v2);
	
	cout<<v2.at(2)<<endl;
}