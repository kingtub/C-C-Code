#include<iostream>
#include<list>
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
	list<int> il(10, 42);
	print_container(il, " ");
	il.resize(15);//在后面加5个 '0’ 
	print_container(il, " ");
	il.resize(25, -1); // 在后面加10个 -1 
	print_container(il, " ");
	il.resize(5); // 删得只剩下5个
	print_container(il, " "); 
}