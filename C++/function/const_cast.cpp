#include<iostream>
#include<string>

using namespace std;

int main()
{
	
	const string& s = "abc";
	string &s2 = const_cast<string&>(s);
	cout<<s2<<endl;
	const string& s3 = const_cast<const string&>(s2);
	cout<<s3<<endl;
	return 0;
}