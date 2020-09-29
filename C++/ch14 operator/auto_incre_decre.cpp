#include<iostream>

using namespace std;

class A {
	public:
	friend ostream & operator<<(ostream &out, const A &a);
	A(int i):i(i) {
		
	}
	
	// ǰ�õ�  
	A& operator++() {
	    i++;
	    return *this;
	}
	// ǰ�õ� 
	A& operator--() {
		i--;
		return *this;
	}
	
	// ���õ� 
	A operator++(int) {
		A a = *this;
	    i++;
	    return a;
	}
	// ���õ� 
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