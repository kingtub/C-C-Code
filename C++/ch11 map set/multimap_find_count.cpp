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
	
	
	// ���һ��multimap��multiset���ж��Ԫ�ؾ��и����ؼ��֣�����ЩԪ���������л����ڴ洢��
	
    multimap<string, string>::iterator it = mm.find("good"); // first element =="good"
    size_t n = mm.count("good"); // how many items == "good"
    while(n > 0) {
    	cout<<it->second<<endl;
    	n--;
    	it++;
    }
    
    cout<<endl<<"2:"<<endl;
    
    // ����2
    // ���lower_bound �� upper_bound������ͬ�ĵ�������������ؼ��ֲ��������С�
	multimap<string, string>::iterator k = mm.lower_bound("good");
	multimap<string, string>::iterator p = mm.upper_bound("good");
	while(k != p) {
		cout<<k->second<<endl;
		k++;
	}
	
	cout<<endl<<"3:"<<endl;
	//����3
	// ���ؼ��ִ��ڣ����һ��������ָ���һ����ؼ���ƥ���Ԫ�أ��ڶ���������ָ�����һ��ƥ��Ԫ��֮���λ�á���δ�ҵ�ƥ��Ԫ�أ���������������ָ��ؼ��ֿ��Բ����λ�á� 
	pair<multimap<string, string>::iterator, multimap<string, string>::iterator> wp = mm.equal_range("good");
	while(wp.first != wp.second) {
		cout<<wp.first->second<<endl;
		wp.first++;
	}
} 