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
	
	// ֻ�ܶ�map��unordered_map ʹ���±����㣬���ܶ�multimap��unordered_multimapʹ���±꣬��Ϊ�ж������ֵ
	// ���word��δ��map�У��±�������ᴴ��һ����Ԫ�أ���ؼ���Ϊword��ֵΪ0.  
	string word = "hi"; 
	cout<<m[word]<<endl;
	// �����±���������ܲ���һ����Ԫ�أ�����ֻ���ԶԷ�const��mapʹ���±������
	// �ܵ�˵�� �±��at����ֻ�����ڷ�const��map��unordered_map.
	const map<string, int> &cm = m;
	//cout<<cm[word]<<endl; // error 
	
	cout<<m.at("eddd")<<endl;
	try {
		cout<<m.at("hello")<<endl;
	} catch(const out_of_range &e) {
		cout<<e.what()<<endl;
	}
	
}