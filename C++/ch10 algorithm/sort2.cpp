#include<iterator>
#include<iostream>
#include<vector>
#include<list>
#include<string>

#include<algorithm>
#include"..\ch09 Sequence containers\my_util.hpp"

using namespace std;

struct A {
	A(string s, int a):name(s), age(a){
		
	}
	string name;
	int age;
};
ostream& operator<<(ostream &os, const A &a) {
	os<<"("<<a.name<<", "<<a.age<<")";
	return os;
}

bool isSmaller(const A &a1, const A &a2) {
	if(a1.name == a2.name) {
		return a1.age < a2.age;
	} else {
		return a1.name < a2.name;
	}
}

void test1();

int main()
{
	test1(); 
	
	return 0;
}

void test1()
{
	vector<A> vi;
	vi.emplace_back("li", 32);
	vi.emplace_back("aw", 35);
	vi.emplace_back("li", 35);
	vi.emplace_back("zhang", 30);
	vi.emplace_back("zheng", 39);
	
	//sort(vi.begin(), vi.end(), isSmaller);
	// Or
	sort(vi.begin(), vi.end(), [](const A &a1, const A &a2) -> bool {
		if(a1.name == a2.name) {
			return a1.age < a2.age;
		} else {
			return a1.name < a2.name;
		}
	}
	);
	print_container(vi, " ");
}

