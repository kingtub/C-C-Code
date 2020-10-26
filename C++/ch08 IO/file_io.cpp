#include<iostream>
#include<fstream>
#include<stdexcept> 

// 头文件fstream定义了三个类型来支持文件IO: ifstream从一个给定文件读取数据，
// ofstream向一个给定文件写入数据，以及fstream可以读写给定文件。

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
	//当一个fstream对象离开其作用域时，与之关联的文件会自动关闭。
	// 当一个fstream对象被销毁时，close会自动被调用。
	ouF.close();
	inStr.close();
}