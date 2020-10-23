#include<iostream>

using namespace std;

int main()
{
	cout<<"Enter 'o' to terminate:"<<endl;
	char c;
	while((cin >> c) && c != 'o')
	  ;
	return 0;
} 