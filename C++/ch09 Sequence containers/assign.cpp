#include<iostream>
#include<string>
#include<list>
#include<vector>
#include"my_util.hpp"

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
	// ˳��������array���⣩��������һ����Ϊassign�ĳ�Ա���������Ǵ�һ����ͬ�����ݵ����͸�ֵ�����ߴ�������һ�������и�ֵ��assign�����ò�����ָ����Ԫ�أ��Ŀ������滻��������е�
    // ����Ԫ�ء�
	list<string> ls;
	vector<const char*> v = {
		"abc", "iop", "l;'"
	};
	ls.assign(v.cbegin() + 1, v.cend());
	
	print_container(ls);
}

void test2()
{
	list<string> ls(1);
	print_container(ls);
	
	ls.assign(10, "Hila!");
	print_container(ls);
}