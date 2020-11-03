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

	multimap<string, string> mm;
	multimap<string, string>::iterator it0 = mm.insert({
		"good", "company"
	});
	multimap<string, string>::iterator it2 = mm.insert({
		"good", "school"
	});
	multimap<string, string>::iterator it3 = mm.insert({
		"good", "car"
	});
	multimap<string, string>::iterator it4 = mm.insert({
		"good", "house"
	});
	multimap<string, string>::iterator it5 = mm.insert({
		"good", "food"
	});
	
	
	// 如果一个multimap或multiset中有多个元素具有给定关键字，则这些元素在容器中会相邻存储。
	
    multimap<string, string>::iterator it = mm.find("good"); // first element =="good"
    size_t n = mm.count("good"); // how many items == "good"
    while(n > 0) {
    	cout<<it->second<<endl;
    	n--;
    	it++;
    }
    
    cout<<endl<<"2:"<<endl;
    
    // 方案2
    // 如果lower_bound 和 upper_bound返回相同的迭代器，则给定关键字不在容器中。
	multimap<string, string>::iterator k = mm.lower_bound("good");
	multimap<string, string>::iterator p = mm.upper_bound("good");
	while(k != p) {
		cout<<k->second<<endl;
		k++;
	}
	
	cout<<endl<<"3:"<<endl;
	//方案3
	// 若关键字存在，则第一个迭代器指向第一个与关键字匹配的元素，第二个迭代器指向最后一个匹配元素之后的位置。若未找到匹配元素，则两个迭代器都指向关键字可以插入的位置。 
	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> wp = mm.equal_range("good");
	while(wp.first != wp.second) {
		cout<<wp.first->second<<endl;
		wp.first++;
	}
} 