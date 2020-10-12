#include<iostream>
#include<memory> 
#include<vector>


using namespace std; 

class Base {
	public:
	Base(const string &s, int d):name(s), score(d){
		
	}
	virtual	~Base() {
		cout<<"Base::~Base()"<<endl;
	}
	virtual void print() {
		cout<<"{Name:"<<name<<", Score:"<<score<<"}"<<endl;
	}
	
	string getName() {
		return name;
	}
	
	int getScore() {
		return score;
	}
	private:
	string name;
	int score;
};

class Derived : public Base {
	public:
	Derived(double salary, int r, const string &s, int d):
	Base(s, d), salary(salary), rank(r){
		
	}
	
	~Derived() {
		cout<<"Derived::~Derived()"<<endl;
	}
	
	void print() {
		cout<<"{Name:"<<getName()<<", Score:"<<getScore()<<", salary:"<<salary<<", rank:"<<rank<<"}"<<endl;
	}
	
	private:
	double salary;
	int rank;
};


int main()
{
	// 用容器存储继承体系的类时，最好用基类指针，特别是智能指针 
	vector<shared_ptr<Base>> v;
	v.push_back(make_shared<Derived>(25000, 50, "zhang", 300));
	v.push_back(make_shared<Base>("zhang", 300));
	
	v[0]->print();
	v[1]->print();
	
	return 0;
}