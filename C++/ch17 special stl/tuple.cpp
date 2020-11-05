#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<tuple>

using namespace std;

void test1();

typedef tuple<int, string> tis;
tis f(int i, const string &s);

void test2();

int main()
{
	//test1();
	
	test2();
	return 0;
} 

void test1()
{
	tuple<size_t, size_t, size_t> threeD;
	tuple<string, vector<double>, int, list<int>> someVal("Consstean", 
		{3.14, 1.59, 3.68}, 10, { 2, 3,4,5,6});
		
	tuple<double, string> t3 = make_tuple(3.14, "Hell");
	
	string &s0 = get<0>(someVal);
	vector<double> &d = get<1>(someVal);
	int &i = get<2>(someVal);
	list<int> &li = get<3>(someVal);
	cout<<s0<<endl;
	cout<<d[0]<<endl;
	cout<<i<<endl;
	
	const size_t st = 1; // st必须是常量表达式 
	cout<<get<st>(t3)<<endl;
	
	
	typedef decltype(someVal) t_ty;
	//查看tuple 成员数量
	size_t cnt = tuple_size<t_ty>::value;
	// 查看第几个元素的类型
	tuple_element<1, t_ty>::type &p = get<1>(someVal);
	cout<<cnt<<endl;
	cout<<p[1]<<endl;
}

tis f(int i, const string &s) {
	return tis(i, s);
}

void test2()
{
	tis t = f(3, "Hello");
	int i = get<0>(t);
	string &s = get<1>(t);
	cout<<i<<" "<<s<<endl;
}