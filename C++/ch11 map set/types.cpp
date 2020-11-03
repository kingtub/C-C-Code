#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<typeinfo>

using namespace std;

void test1();
int main()
{
	test1();
	return 0;
}


void test1()
{
	map<string, int>::key_type k = "Hello"; // string
	map<string, int>::mapped_type m = 10; // int
	map<string, int>::value_type v = make_pair("GOGogo", 10); // pair<const string, int>
	
	string s = "fdfdf";
	set<string>::key_type sk = s; // string
	set<string>::value_type sv = s;// same to key_type,  string
	
	cout<<typeid(map<string, int>::value_type).name()<<endl;
}