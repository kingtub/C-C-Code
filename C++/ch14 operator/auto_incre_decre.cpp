#include<iostream>

using namespace std;

class A {
	public:
	friend ostream & operator<<(ostream &out, const A &a);
	A(int i):i(i) {
		
	}
	
	// 前置的  
	A& operator++() {
	    i++;
	    return *this;
	}
	// 前置的 
	A& operator--() {
		i--;
		return *this;
	}
	
	// 后置的 
	A operator++(int) {
		A a = *this;
	    i++;
	    return a;
	}
	// 后置的 
	A operator--(int) {
		A a = *this;
		i--;
		return a;
	}
	
	int & getI() {
		return i;
	}
	
	private:
	int i;
}; 

ostream & operator<<(ostream &out, const A &a)
{
	out<<a.i;
	return out;
}

int main()
{
	A a(10);
	cout<<a++<<endl;
	cout<<a<<endl;
	cout<<++a<<endl;
	
	A a2(20);
	cout<<a2--<<endl;
	cout<<a2<<endl;
	cout<<--a2<<endl;
	return 0;
} 