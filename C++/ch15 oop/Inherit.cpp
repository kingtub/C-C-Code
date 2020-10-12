#include<iostream>
#include<string>

using namespace std;

class Base {
	public:
	friend ostream& operator<<(ostream &out, const Base &b);
	Base(const string &s, int d):name(s), score(d){
		
	}
	private:
	string name;
	int score;
};

class Derived : public Base {
	public:
	friend ostream& operator<<(ostream &out, const Derived &d);
	Derived(double salary, int r, const string &s, int d):
	Base(s, d), salary(salary), rank(r){
		
	}
	private:
	double salary;
	int rank;
};

ostream& operator<<(ostream &out, const Derived &d) {
	const Base &b = d;
	out<<b;
	out<<d.salary<<" "<<d.rank<<" ";
	return out;
}

ostream& operator<<(ostream &out, const Base &b) {
	out<<b.name<<" "<<b.score<<" ";
	return out;
}

int main()
{
	Derived d(25000, 50, "zhang", 300);
	
	cout<<d<<endl;
	return 0;
} 