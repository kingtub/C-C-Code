#include<iostream>

using namespace std;

void test1();

int main()
{
    test1();
	return 0;
} 

void outState()
{
	bool failbit = cin.fail();
    bool eofbit = cin.eof();
    bool badbit = cin.bad();
    bool goodbit = cin.good();
    
    
	cout<<"failbit is:"<<(failbit ? "true" : "false")<<endl;
    cout<<"eofbit is:"<<(eofbit ? "true" : "false")<<endl;
    cout<<"badbit is:"<<(badbit ? "true" : "false")<<endl;
    cout<<"goodbit is:"<<(goodbit ? "true" : "false")<<endl;
}
void test1()
{
    int j = 0;
   
    cin>>j;
    
    outState();
    
    if(!cin) {
    	cin.clear();
		cout<<endl<<"After clear:"<<endl;
		outState();
    }
    
}