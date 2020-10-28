#include<string>
#include<vector>
#include<iostream>

using namespace std;

void test1();

int main()
{
	test1();
	return 0;
}

void test1()
{
	string s = "abcdefghijklmnopqrst";
	vector<char> v(s.begin(), s.end());
	vector<char>::size_type size = v.size();
	for(vector<char>::size_type k = 0; k != size; k++) {
		cout<<v[k]<<" ";
	}
	
	cout<<endl;
}
