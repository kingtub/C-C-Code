#include<iostream>
#include<string>
#include<cctype>

using namespace std;

void test1();
void test2();
void test3();
void test4();
void test5();
void testFor();
void testChange(); 
void testChange2(); 

int main()
{
	//test1();
	//test2();
	//test3();
	
	//test4();
	
	// 陷阱 
	//test5();
	
	//testFor();
	
	//testChange();
	
	testChange2();
	
	return 0;
}

void test1() {
	cout<<"test1 start"<<endl;
	string s;
	cout<< "请输入一行：";
	cin>>s;
	cout<< "你的输入是："<< s <<endl;
	cout<<"test1 end"<<endl<<endl;
}

void test2() {
	cout<<"test2 start"<<endl;
	string s;
	while(cin>>s) {
		cout<<s<<endl;
	}
	cout<<"test2 end"<<endl<<endl;
}

void test3() {
	string s;
	cout<<"s.empty()="<<(s.empty()?"true":"false")<<endl;
	cout<< "请输入一行：";
	cin>>s;
	cout<< "你的输入是："<< s <<endl;
	cout<<"s.size()="<<s.size()<<endl;
	int n = s.size();
	if(n > 0)
	cout<<"s[n-1]="<<s[n-1]<<endl;
}

void test4() {
	string line;
	while(getline(cin, line)) {
		cout<< line << endl;
	}
}

// 陷阱 
void test5() {
	string s = "abcde";
	// unsigned int len = s.size();  error
	auto len = s.size();
	int k = -1;
	cout<< (len<k?"true":"false")<<endl;
} 


void testFor() {
	string s = "fhijk";
	for(char o:s)
	   cout<<o<<endl;
}

void testChange()
{
	string s = "abcdef";
	s[2] = 'o';
	cout<<s<<endl;
	for(auto &c:s) {
		c = toupper(c);
	}
	cout<<s<<endl;
}

void testChange2()
{
	string s = "abcdef";
	auto i = s.begin();
	cout<<s<<endl;
	while(i != s.end()) {
		*i = toupper(*i);
		i++;
	}
	
	cout<<s<<endl;
}



