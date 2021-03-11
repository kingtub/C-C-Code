#include<iostream>
#include<thread>

using namespace std;
void f() {
	cout<<"f, tid="<<this_thread::get_id()<<endl;
}

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
    thread t(f);
	thread::id mytid = t.get_id();
	t.join();
	
	cout<<"tid="<<mytid<<endl;
	
	cout<<"main, tid="<<this_thread::get_id()<<endl;
	
	cout<<boolalpha<<(mytid == this_thread::get_id())<<noboolalpha<<endl;
}

void test2()
{
	thread t;
	thread::id myid = t.get_id();
	thread::id noid;
	if(myid == noid) {
		cout<<"不跟任何函数联系，无线程"<<endl; 
	}
}