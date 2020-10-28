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
	// 顺序容器（array除外）还定义了一个名为assign的成员，允许我们从一个不同但相容的类型赋值，或者从容器的一个子序列赋值。assign操作用参数所指定的元素（的拷贝）替换左边容器中的
    // 所有元素。
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