#include<iostream>
using namespace std;

class A {
	public:
	A() {
		myId = ++ins_count;
		cout<< "Create instance " << myId << endl;
	}
	// ¿½±´¹¹Ôìº¯Êý 
	A(const A &a) {
		cout<< "Copy Constructor " << endl;
	} 
	~A() {
		cout<< "destroy instance " << myId << endl;
	}
	private:
	static int ins_count;
	int myId;
};

int A::ins_count;

int main()
{
	A a, b, c, d;
	A a1 = a;
	cout<< "------------------------------"<<endl;
	const char* s = &a1==&a ? "same instance":"NOT same instance";
	cout<< s <<endl;
	return 0;
}
