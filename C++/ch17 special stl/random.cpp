#include<iostream>
#include<random>
#include<cmath>
#include<map>

using namespace std;

void test1();
void test2();
void test3();

int main()
{
	//test1();
		
	//test2();
	
	test3();
	return 0;
} 

void test1()
{
	// ����������Ǻ��������ࡣ�����ܲ��������֡� 
	default_random_engine e;
	for(size_t i = 0; i < 10; i++) {
		cout<<e()<<"  ";
	} 
	cout<<endl;
	default_random_engine d(108); // 108����������� 
	for(size_t i = 0; i < 10; i++) {
		cout<<d()<<"  ";
	} 
	cout<<endl;
}

void test2()
{
	// ���������ͨ����Ҫ �������������� �� ������ֲ����������� 
	unsigned seed = 268;
	//  ��������������
	default_random_engine generator(seed);
	long min = 10, max = 100;
	// ����10��100��������֮��ľ��ȷֲ�������� 
	uniform_int_distribution<long> uid(min, max); // ������ֲ��� 
	for(size_t	i = 0; i<10; i++) {
		// ��uid��Ϊ�����Դ
		// ÿ�����ò�����ָ����Χ�ڷ��Ӿ��ȷֲ�������� 
		cout<<uid(generator)<<endl; 
	} 
}

void test3()
{
	default_random_engine generator(157);
	// ��̬�ֲ�����ֵΪ4����׼��Ϊ1.5 
	normal_distribution<> nd(4, 1.5);
	map<int, size_t> m;
	for(size_t i = 0; i < 200; i++) {
		int k = lround(nd(generator));
		m[k]++;
	}
	for(auto begin = m.cbegin(), e = m.cend(); begin != e; begin++) {
		cout<<begin->first<<"  :  "<<begin->second<<endl;
	}
}