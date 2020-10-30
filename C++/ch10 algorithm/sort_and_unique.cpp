#include<iterator>
#include<iostream>
#include<vector>
#include<list>
#include<string>

#include<algorithm>
#include"..\ch09 Sequence containers\my_util.hpp"

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
	vector<int> vi = {
		8, 9, 3, 0, 6, 14, 56, 0,2,8
	};
	
	sort(vi.begin(), vi.end());
	
	print_container(vi, " ");
}

void test2()
{
	// unique�㷨�����������У������ڵ��ظ����������������һ��ָ���ظ�ֵ��Χĩβ�ĵ�������
	vector<int> vi = {
		8, 9, 3, 0, 6, 14, 56, 0,2,8
	};
	sort(vi.begin(), vi.end());
	print_container(vi, " ");
	vector<int>::iterator end_unique = unique(vi.begin(), vi.end());
	vi.erase(end_unique, vi.end());
	print_container(vi, " ");
}