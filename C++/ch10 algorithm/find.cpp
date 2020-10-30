#include<iterator>
#include<iostream>
#include<list>
#include<string>

#include<algorithm>

using namespace std; 

void test1();

int main()
{
	test1();
	return 0;
}

void test1()
{
	list<int> li = {
		2,5,1,6,7,12,58,35,69
	};
	
	list<int>::const_iterator k1 = find(li.cbegin(), li.cend(), 58);
	if(k1 == li.cend()) {
		cout<<"Not found"<<endl;
	} else{
		cout<<"Found it"<<endl;
	}
	
	list<int>::const_iterator k2 = find(li.cbegin(), li.cend(), 32);
	if(k2 == li.cend()) {
		cout<<"Not found"<<endl;
	} else{
		cout<<"Found it"<<endl;
	}
	
	list<string> ls = {
		"ldkdl", "hdufdfdjk", "lijinhua", "qweerfv", "hkkdeee"
	};
	list<string>::const_iterator c1 = find(ls.cbegin(), ls.cend(), "fdfdwww");
	list<string>::const_iterator c2 = find(ls.cbegin(), ls.cend(), "lijinhua");
	
	if(c1 == ls.cend()) {
		cout<<"Not found"<<endl;
	} else{
		cout<<"Found it"<<endl;
	}
	
	if(c2 == ls.cend()) {
		cout<<"Not found"<<endl;
	} else{
		cout<<"Found it"<<endl;
	}
	
	int ia[] = {
		1,4, 5,2, 0, 8, 10
	};
	int *ip1 = find(begin(ia), end(ia), 11);
	int *ip2 = find(begin(ia), end(ia), 10);
	
	if(ip1 == end(ia)) {
		cout<<"Not found"<<endl;
	} else{
		cout<<"Found it"<<endl;
	}
	
	if(ip2 == end(ia)) {
		cout<<"Not found"<<endl;
	} else{
		cout<<"Found it"<<endl;
	}
}