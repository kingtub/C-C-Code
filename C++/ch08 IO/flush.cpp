#include<iostream>

using namespace std;

void test1();
void test2();

int main()
{
	//test1();
	test2();
	return 0;
} 

void test1()
{
	cout<<"hi!"<<endl; // ���hi��һ�����У�Ȼ��ˢ�»�����
	cout<<"hi!"<<flush; // ���hi��Ȼ��ˢ�»��������������κζ����ַ�
	cout<<"hi!"<<ends; // ���hi��һ�����ַ���Ȼ��ˢ�»�����
}

void test2()
{
	cout<<unitbuf; // ������������󶼻�����ˢ�»��������κ����������ˢ�£��޻���.
	cout<<nounitbuf; // �ص������Ļ��巽ʽ
}