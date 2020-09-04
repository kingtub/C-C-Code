#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

vector<string> f1();
int main()
{
	vector<string> v1 = f1();
	
	for(auto &o:v1) {
		cout<<o<<" ";
	}
	cout<<endl;
	
	return 0;
} 

vector<string> f1()
{
	return {
		"v1", "v2", "v3"
	};
}
