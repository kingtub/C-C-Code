#include<iostream>
#include<string>

using namespace std;

class Singleton {
	private:
	static Singleton* ins;
	string describe;
	Singleton();
	public:
	static Singleton* getInstance();
	string getDescribe();
};

Singleton* Singleton::ins;
Singleton::Singleton()
{
	describe = "I am a singleton instance";
}

string Singleton::getDescribe()
{
	return describe;
}

Singleton* Singleton::getInstance() {
	if(NULL == ins) {
		ins = new Singleton();
	}
	return ins;
} 

int main()
{
	// Singleton s; error
	Singleton *ins = Singleton::getInstance();
	Singleton *in2 = Singleton::getInstance();
	cout<< ins->getDescribe() << endl;
	
	if(ins == in2) {
		cout<< "same" << endl;
	} else {
		cout<< "not same"<< endl;
	}
	return 0;
}
