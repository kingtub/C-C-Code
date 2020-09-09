#include<iostream>

using namespace std;

// 聚合类，所有成员是公共的，无构造函数，无初始值，无基类，无virtual函数 
class A{
	public:
		int i;
		string s;
};

struct B {
	string name;
	double score;
};

int main()
{
	A a = {3, "abc"} ;
	cout<<a.i<<endl;
	cout<<a.s<<endl;
	
	B b = {"mars", 75.5};
	cout<<b.name<<endl;
	cout<<b.score<<endl;
	return 0;
}