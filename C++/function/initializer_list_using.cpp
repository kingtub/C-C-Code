#include<initializer_list>
#include<string>
#include<iostream>
 
using namespace std;
 
int sum(initializer_list<int> elements);
void printErr(initializer_list<string> errs);
 
int main()
{
 	cout<<sum({1, 2, 2})<<endl;
 	cout<<sum({5, 5})<<endl;
 	
 	printErr({"bad", "compiledError"});
 	printErr({"good", "better", "best"});
 	printErr({});
}
 
int sum(initializer_list<int> elements) {
	int sum = 0;
	for(auto begin = elements.begin(); begin != elements.end(); begin++) {
		sum += *begin;
	}
	
	return sum;
}

void printErr(initializer_list<string> errs) {
	for(auto &s:errs) {
		cout<<s<<" ";
	}
	cout<<endl;
}