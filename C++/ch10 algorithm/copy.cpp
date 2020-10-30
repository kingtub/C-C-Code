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
	test1();
	
	test2();
	return 0;
}

void test1()
{
	int ia[] = {
		15,1,2,3,4,5,6,7,8,9
	};
	int r[sizeof(ia)/ sizeof(ia[0])];
	
	auto k = copy(begin(ia), end(ia), begin(r));
	if(k == end(r)) {
		cout<<"yes"<<endl;
	}
	
	for(size_t i = 0; i != sizeof(r)/ sizeof(r[0]); i++)
	      cout<<r[i]<<" ";
    cout<<endl;
}

void test2()
{
	// ���ݸ�copy��Ŀ����������Ҫ��������������һ�����Ԫ�أ���һ�����Ҫ��
	vector<string> vs(10, "");
	list<string> ls = {
		"ab", "cd", "ef", "gh", "ij", "kl", "mn", "op", "qr", "st", 
	};
	
	auto it = copy(ls.cbegin(), ls.cend(), vs.begin());
	print_container(vs, "   ");
	if(it == vs.end()) {
		cout<<"yes"<<endl;
	}
}