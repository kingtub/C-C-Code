#include<iostream>
#include<thread>

using namespace std;

class F {
	public:
	void operator()() {
		cout<<"func is called"<<endl;
	}
};

void test2();
int main()
{
	//F f;
	//f();
	//f();
	
	
	
	test2();
	
	return 0;
}

void test2()
{
	F f;
	thread th(f);
	th.join();
}