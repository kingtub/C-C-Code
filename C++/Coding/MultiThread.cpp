#include<iostream>
#include<thread>
#include<chrono>
#include<sstream>

using namespace std;

void aa() 
{
	for(int i = 0; i < 100; i++) {
		cout<<"Thread aa out "<<i<<" "<<endl;
		this_thread::sleep_for(chrono::milliseconds(1));
	}
	cout<<"Thread aa finished"<<endl;
} 

void bb() 
{
	for(int i = 0; i < 100; i++) {
		cout<<"Thread bb out "<<i<<" "<<endl;
	    this_thread::sleep_for(chrono::milliseconds(1));
	}
	cout<<"Thread bb finished"<<endl;
} 

void test1()
{
	thread t1(aa);
	thread t2(bb);
	this_thread::sleep_for(chrono::milliseconds(1000));
}

int main()
{
	test1();
	return 0;
}