#include<iostream>
#include<vector>
#include<array> 
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

void test1()
{
	vector<int> v;
	vector<int> v2(v);
	vector<int> v3 = v;
	vector<int> v4{2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v5 = {2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v6(v5.begin(), v5.end());
	
	// 只有顺序容器才有。关联容器没有。 
	vector<int> v7(10);
	vector<int> v8(10, 8);
	
	for(vector<int>::size_type k = 0; k != v7.size(); k++) {
		cout<<v7[k]<<" ";
	}
	cout<<endl; 
	for(vector<int>::size_type k = 0; k != v8.size(); k++) {
		cout<<v8[k]<<" ";
	}
	cout<<endl; 
}

void test2()
{
	array<string, 30> as;
	array<int, 20> ai = {0, 1, 3, 4,5,8,9};
	array<int, 20> kk = ai;
}