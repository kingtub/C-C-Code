#include<iostream>
#include<string>

using namespace std;

class A {
	public:
	friend A operator+(const A &a1, const A &a2);
	A()=default;
	A(int i, const string &s):i(i), s(s){
		
	}
	A(const A &o):i(o.i), s(o.s){
		
	}

	void print() {
		cout<<"i is "<<i<<endl;
		cout<<"s is "<<s<<endl;
	}
	private:
	int i;
	string s;
};

A operator+(const A &a1, const A &a2) {
	A r;
	r.i = a1.i + a2.i;
	r.s = a1.s + a2.s;
	return r;
} 

int main()
{
	A a1(2, "hello ");
	A a2(3, "good");
	A a3 = a1 + a2;
	a3.print();
	
	string ss;
	string s = "as" + ss;
}