#include<iterator>
#include<iostream>
#include<vector>
#include<list>
#include<string>

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
	vector<int> vi = {
		0,1, 9, 8,3 ,6,0, 5
	};
	
	replace(vi.begin(), vi.end(), 0, 88);
	print_container(vi, " ");
	
	vector<int> v6 = {
		0,1, 9, 8,3 ,6,0, 5
	};
	vector<int> v2;
	replace_copy(v6.cbegin(), v6.cend(), back_inserter(v2), 0, 77);
	print_container(v6, " ");
	print_container(v2, " ");
}