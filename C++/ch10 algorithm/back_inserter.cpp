#include<iterator>
#include<iostream>
#include<vector>

#include<algorithm>
#include"..\ch09 Sequence containers\my_util.hpp"

using namespace std;

void test1();
int main()
{
	test1();
	return 0;
}

void test1()
{
	vector<int> vi;
	// it 是一个（尾后）插入迭代器 
	auto it = back_inserter(vi);
	*it = 42;
	print_container(vi);
	
	vector<double> vd;
	fill_n(back_inserter(vd), 10, 3.14);
	print_container(vd, " ");
}