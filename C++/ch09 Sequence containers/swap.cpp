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
	// swap操作交换两个相同类型容器的内容。调用swap之后，两个容器中的元素将会交换。
	// 除array外，swap不对任何元素进行拷贝、删除或插入操作，因此可以保证在常数时间内完成。
	swap(v1, v2);
	cout<<"v1:"<<endl;
	print_container(v1);
	cout<<"v2:"<<endl;
	print_container(v2);
	
	cout<<v2.at(2)<<endl;
}