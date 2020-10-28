#include<iostream>
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
    string s = "abcdefghij";
    string::iterator it = s.begin();
    cout<<*(it + 8)<<endl;
    it += 8;
    it -= 2;
    cout<<*it<<endl;
    
    string::const_iterator cit = s.cbegin();
    cit += 3;
    bool b = cit <= it;
    cout<<(b?"yes":"no")<<endl;
}

void test2()
{
	string s = "abcdefghij";
	for(string::iterator b = s.begin(); b != s.end(); b++) {
		cout<<*b<<" ";
	}
	cout<<endl;
}
