#include<iostream>

using namespace std;

class A {
	public:
	A() {
		countIns++;
		id = countIns;
		cout<<"A default constructor, id="<<id<<endl;
	}
	
	// Îö¹¹º¯Êý 
	~A() {
		cout<<"DeInit, id="<<id<<endl;
	} 
	
	A(int n):num(n) {
		countIns++;
		id = countIns;
		cout<<"A constructor 2, id="<<id<<endl;
	}
	
	A(const A& other) {
		countIns++;
		id = countIns;
		cout<<"A copy constructor, id="<<id<<endl;
	}
	
	int getNum() const {
		return num;
	}
	
	int& getNum() {
		
		return num;
	} 
	private:
	static unsigned int countIns;
	int num = 2;
	const static char c = 'C';
	int id;
};
unsigned int A::countIns = 0;

A getA();
A getA2(int num);

int main()
{	
	A a = getA();
	cout<<"getA() num="<<a.getNum()<<endl;
	
	A b = getA2(5);
	cout<<"getA2() num="<<b.getNum()<<endl;
	
	A c = b;
	cout<<"assign num="<<c.getNum()<<endl;
	return 0;
} 

A getA() {
	A a;
	return a;
}

A getA2(int num) {
	A a(num);
	return a;
}
