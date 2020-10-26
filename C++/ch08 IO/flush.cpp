#include<iostream>

using namespace std;

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
	cout<<"hi!"<<endl; // 输出hi和一个换行，然后刷新缓冲区
	cout<<"hi!"<<flush; // 输出hi，然后刷新缓冲区，不附加任何额外字符
	cout<<"hi!"<<ends; // 输出hi和一个空字符，然后刷新缓冲区
}

void test2()
{
	cout<<unitbuf; // 所有输出操作后都会立即刷新缓冲区；任何输出都立即刷新，无缓冲.
	cout<<nounitbuf; // 回到正常的缓冲方式
}