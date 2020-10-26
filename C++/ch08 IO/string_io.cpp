#include<sstream>
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

// string ��
// sstreamͷ�ļ�����������������֧���ڴ�IO, ��Щ���Ϳ�����stringд�����ݣ���string��ȡ���ݣ�����string��һ��IO��һ����
// istringstream��string��ȡ���ݣ�ostringstream��stringд�����ݣ�������stringstream�ȿɴ�string������Ҳ����stringд���ݡ�

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
