#include<sstream>
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

// string 流
// sstream头文件定义了三个类型来支持内存IO, 这些类型可以向string写入数据，从string读取数据，就像string是一个IO流一样。
// istringstream从string读取数据，ostringstream向string写入数据，而类型stringstream既可从string读数据也可向string写数据。

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
	ifstream in("string_io.cpp");
	ostringstream oss;
	char buf[1024];
	while(!in.eof()) {
		in.getline(buf, 1024);
		oss<<buf<<endl;
	}
	
	cout<<oss.str();
}

void test2()
{
	ifstream in("input.txt");
	
	string line;
	
	while(!in.eof()) {
	
		getline(in, line);
		
		istringstream iss;
		iss.str(line);
		
		string s;
		unsigned long long num;
		iss>>s;
		iss>>num;
		cout<<s<<" "<<num<<endl;
	}
}
