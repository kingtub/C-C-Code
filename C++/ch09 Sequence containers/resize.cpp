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
	il.resize(15);//�ں����5�� '0�� 
	print_container(il, " ");
	il.resize(25, -1); // �ں����10�� -1 
	print_container(il, " ");
	il.resize(5); // ɾ��ֻʣ��5��
	print_container(il, " "); 
}