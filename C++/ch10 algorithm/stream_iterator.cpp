#include<iterator>
#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<string>

#include<algorithm>
#include"..\ch09 Sequence containers\my_util.hpp"


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

// iostream µü´úÆ÷ 

void test1()
{
	ifstream in("nums.txt");
	istream_iterator<int> iit(in);
	istream_iterator<int> end;

	vector<int> vec(iit, end);  
	print_container(vec, " ");
}

void test2()
{
	istream_iterator<int> iit(cin);
	istream_iterator<int> end;
	
	
	vector<int> vec(iit, end);  
	print_container(vec, " ");
	
	// cout<<accumulate(iit,end, 0)<<endl;
}

void test3()
{
	ostream_iterator<int> o(cout, " ");
	vector<int> v = {
		4,5,60, 4,6,821, 6
	};
	for(int &r:v) {
		*o++ = r;
	}
	cout<<endl;
	// Or
	copy(v.begin(), v.end(), o);
	cout<<endl;
}