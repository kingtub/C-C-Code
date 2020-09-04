#include<iostream>
#include<vector>
#include<string>

using namespace std;

void test1(); 
void test2(); 

int main()
{
	//test1();
	test2();
	return 0;
}

void test1() {
	vector<int> v = {
		42,65,100, 39, 67
	};
	
	vector<int> vc(11, 0);
	for(int i:v) {
		vc[i/10]++;
	}
	
	cout<<"size="<<v.size()<<endl;
	for(int i:v) {
		cout<<i<<" ";
	}
	cout<<endl;
	cout<<"各个分数段为:";
	for(int i:vc) {
		cout<<i<<" ";
	}
	cout<<endl;
}

void test2() {
	vector<string> ss/*
(const string &a)*/;
	
	ss.push_back("he");
	ss.push_back("llo");
	cout<<ss.back()<<endl;
} 

