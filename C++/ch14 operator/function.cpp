#include<iostream>
#include<functional>
#include<map>
#include<string>

using namespace std;

int add(int i, int j) {
	return i + j;
}
class Divide {
	public:
	int operator()(int i, int j) {
		return i / j;
	}
};


int main()
{
	function<int(int, int)> f1(add);
	function<int(int, int)> f2 = Divide();
	function<int(int, int)> f3 = [](int i, int j) {
		return i * j;
	};
	
	cout<<f1(4, 2)<<endl;
	cout<<f2(4, 2)<<endl;
	cout<<f3(4, 2)<<endl;
	
	cout<<endl<<endl;
	
	map<string, function<int(int, int)>> tp;
	tp.insert(pair<string, function<int(int, int)>>("+", f1));
	tp.insert(pair<string, function<int(int, int)>>("/", f2));
	tp.insert(pair<string, function<int(int, int)>>("*", f3));
	cout<<tp["+"](4, 2)<<endl;
	cout<<tp["/"](4, 2)<<endl;
	cout<<tp["*"](4, 2)<<endl;
	return 0;
} 