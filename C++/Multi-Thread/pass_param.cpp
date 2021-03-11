#include<iostream>
#include<string>
#include<thread>


using namespace std;

class AO {
  public:
  explicit AO(const string &n, double sco):name(n), score(sco) {
  	
  }
  
  operator()() {
  	cout<<"name: "<<name<<endl;
	cout<<"score: "<<score<<endl;
  }
  private:
  string name;
  double score;
};

void f(int i, const string &s)
{
	cout<<"i is "<<i<<endl;
	cout<<"s is "<<s<<endl;
}

void test1();
void test2();

int main(int argc, char *argv[])
{
	test1();
	test2();
	return 0;
}

void test1()
{
	thread t(f, 3, "piihhggfdsaa");
	t.join();
}

void test2()
{
	AO ao("qwjipljf;", 5.0);
	thread t(ao);
	t.join();
}