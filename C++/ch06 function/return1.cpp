#include<iostream>
#include<vector>

using namespace std;

string getMsg();
vector<string> f1();

class A {
	public:
	A() {
		countIns++;
		cout<<"A default constructor, countIns="<<countIns<<endl;
	}
	
	A(int n):num(n) {
		countIns++;
		cout<<"A constructor 2, countIns="<<countIns<<endl;
	}
	
	A(const A& other) {
		countIns++;
		cout<<"A copy constructor, countIns="<<countIns<<endl;
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
};
unsigned int A::countIns = 0;

A getA();
A getA2(int num);

int main()
{
	vector<string> v1 = f1();
	
	for(auto &o:v1) {
		cout<<o<<" ";
	}
	cout<<endl;
	
    string s = getMsg();
	cout<<s<<endl;
	
	A a = getA();
	cout<<"getA() num="<<a.getNum()<<endl;
	
	A b = getA2(5);
	cout<<"getA2() num="<<b.getNum()<<endl;
	
	A c = b;
	cout<<"assign num="<<c.getNum()<<endl;
	return 0;
} 

vector<string> f1()
{
	return {
		"v1", "v2", "v3"
	};
}

string getMsg()
{
	string s = "abc";
	return s;
}

A getA() {
	A a;
	return a;
}

A getA2(int num) {
	A a(num);
	return a;
}
