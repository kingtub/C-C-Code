#include<iostream>
#include<string>

using namespace std;

class A {
	public:
	friend A operator+(const A &a1, const A &a2);
	friend bool operator==(const A &a1, const A &a2);
	friend bool operator!=(const A &a1, const A &a2);
	A()=default;
	A(int i, const string &s):i(i), s(s){
		
	}
	A(const A &o):i(o.i), s(o.s){
		
	}
	
	A& operator=(const int &i) {
		this->i = i;
		return *this;
	}
	
	A& operator=(const string &s) {
		this->s = s;
		return *this;
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

bool operator==(const A &a1, const A &a2)
{
	return (a1.i == a2.i) && (a1.s == a2.s);
}

bool operator!=(const A &a1, const A &a2)
{
	return !(a1 == a2);
}

void test1();
void test2();
void test3();
int main()
{
	test3();
	return 0;
}

void test1()
{
    A a1(2, "hello ");
	A a2(3, "good");
	A a3 = a1 + a2;
	a3.print();
}

void test2()
{
	A a1(2, "hello ");
	A a2(3, "good");
    cout<<(a1==a2)<<endl;
	cout<<(a1!=a2)<<endl;
	A o(2, "hello ");
	cout<<(o==a1)<<endl;
	cout<<(o!=a1)<<endl;
}

void test3()
{
	A a1(2, "hello ");
	a1.print();
	a1 = 3;
	a1.print();
	a1 = "goo";
	a1.print();
}