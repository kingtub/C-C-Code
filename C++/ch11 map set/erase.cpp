#include<iostream>
#include<utility>
#include<string>
#include<map>
#include<set>
#include<vector>
#include"..\common_util.hpp"

using namespace std;

void test1();

int main()
{
	test1();
	return 0;
}

void test1()
{
	map<string, int> m;
	pair<map<string, int>::iterator, bool> r1 = m.insert({ "hi", 5});
	pair<map<string, int>::iterator, bool> r5 = m.insert({ "hi", 6});
	pair<map<string, int>::iterator, bool> r2 = m.insert(pair<string, int>("ki", 6));
	pair<map<string, int>::iterator, bool> r3 = m.insert(make_pair("sass", 1));
	pair<map<string, int>::iterator, bool> r4 = m.insert(map<string, int>::value_type("eddd", 10));
	
	multimap<string, string> mm;
	multimap<string, string>::iterator it0 = mm.insert({
		"good", "company"
	});
	multimap<string, string>::iterator it2 = mm.insert({
		"good", "school"
	});
	
	map<string, int>::size_type n1 = m.erase("hi");
	map<string, int>::size_type n2 = m.erase("company");
	multimap<string, string>::size_type n3 = mm.erase("good");
	cout<<n1<<" "<<n2<<" "<<n3<<endl;
	
	map<string, int>::iterator it = m.erase(m.begin());
	cout<<it->first<<endl;
	map<string, int>::iterator end = m.erase(m.begin(), m.end());
	cout<<m.size()<<endl;
} 