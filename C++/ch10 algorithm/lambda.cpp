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
	int n = 5;
	vector<string> vs = {
		"avb", "eef", "qwnc", "dhaa", "aa", "ddddskskwl"
	};
	
	vector<string>::iterator it = find_if(vs.begin(), vs.end(), [n](const string &s) {
		return s.size() >= n;
	});
	
	if(it != vs.end()) {
		cout<<it->size()<<"          "<<*it<<endl;
	}
	
	int k = 4;
	for_each(vs.begin(), vs.end(), [k](const string &s) {
		if(k == s.size()) {
			cout<<s<<endl;
		}
	});
}