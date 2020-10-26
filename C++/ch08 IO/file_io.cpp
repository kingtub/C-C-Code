#include<iostream>
#include<fstream>
#include<stdexcept> 

// ͷ�ļ�fstream����������������֧���ļ�IO: ifstream��һ�������ļ���ȡ���ݣ�
// ofstream��һ�������ļ�д�����ݣ��Լ�fstream���Զ�д�����ļ���

using namespace std;

void test1();

int main()
{
	test1();
	return 0;
}

void test1()
{
	ifstream inStr("file_io.cpp");
	char buf[1024];
	ofstream ouF;
	ouF.open("file_io.cpp.copy.txt");
	
	if(!inStr.is_open() || !ouF.is_open()) {
		throw runtime_error("File open error");
	}
	
	while(!inStr.eof()) {
		inStr.getline(buf, 1024);
		cout<<buf<<endl;
		ouF<<buf<<endl;
	}
	//��һ��fstream�����뿪��������ʱ����֮�������ļ����Զ��رա�
	// ��һ��fstream��������ʱ��close���Զ������á�
	ouF.close();
	inStr.close();
}