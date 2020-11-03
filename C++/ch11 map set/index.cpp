#include<iostream>
#include<utility>
#include<string>
#include<map>
#include<set>
#include<vector>
#include"..\common_util.hpp"
#include<stdexcept>

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
	
	// 只能对map或unordered_map 使用下标运算，不能对multimap或unordered_multimap使用下标，因为有多个关联值
	// 如果word还未在map中，下标运算符会创建一个新元素，其关键字为word，值为0.  
	string word = "hi"; 
	cout<<m[word]<<endl;
	// 由于下标运算符可能插入一个新元素，我们只可以对非const的map使用下标操作。
	// 总的说， 下标和at操作只适用于非const的map和unordered_map.
	const map<string, int> &cm = m;
	//cout<<cm[word]<<endl; // error 
	
	cout<<m.at("eddd")<<endl;
	try {
		cout<<m.at("hello")<<endl;
	} catch(const out_of_range &e) {
		cout<<e.what()<<endl;
	}
	
}