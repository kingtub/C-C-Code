#include<iostream>
#include<utility>
#include<string>
#include<map>
#include<set>
#include<vector>
#include"..\common_util.hpp"

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

void test1()
{
	vector<int> vi = {
		1, 3, 4,7,9,9, 1, 3, 4,7,9,9
	};
	
	set<int> si;
	// 插入一个已存在的元素对容器没有任何影响。
	si.insert(vi.cbegin(), vi.cend()); // si现在有5个元素
	cout<<si.size()<<endl;
	si.insert( {3, 10, 15, 20, 25, 30} ); // si现在有10个元素
	// set 有 2个版本的insert方法，接受一对迭代器范围或一个初始化列表。 
	cout<<si.size()<<endl;
}

void test2()
{
	// 对一个map进行insert操作时，必须记住元素类型是pair。
	map<string, int> m;
	pair<map<string, int>::iterator, bool> r1 = m.insert({ "hi", 5});
	pair<map<string, int>::iterator, bool> r5 = m.insert({ "hi", 6});
	pair<map<string, int>::iterator, bool> r2 = m.insert(pair<string, int>("ki", 6));
	pair<map<string, int>::iterator, bool> r3 = m.insert(make_pair("sass", 1));
	pair<map<string, int>::iterator, bool> r4 = m.insert(map<string, int>::value_type("eddd", 10));
	
	cout<<r1.second<<" "<<(r1.first)->first<<endl;
	cout<<r5.second<<" "<<(r5.first)->first<<endl;
	cout<<r2.second<<" "<<(r2.first)->first<<endl;
	cout<<r3.second<<" "<<(r3.first)->first<<endl;
	cout<<r4.second<<" "<<(r4.first)->first<<endl;
	
	print_map(m);
}

void test3()
{
	multimap<string, string> mm;
	multimap<string, string>::iterator it = mm.insert({
		"good", "company"
	});
	multimap<string, string>::iterator it2 = mm.insert({
		"good", "school"
	});
	
	cout<<it->first<<" "<<it->second<<endl;
	cout<<it2->first<<" "<<it2->second<<endl;
}