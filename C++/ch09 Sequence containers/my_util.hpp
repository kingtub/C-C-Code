#include<iostream>
using namespace std;

template <typename T>
void print_container(const T& t, const char * white_space = "\n") {
	typename T::const_iterator cb = t.begin();
	typename T::const_iterator ce = t.end();
	for(; cb != ce; cb++) {
		cout<<*cb<<white_space;
	}
	cout<<endl;
}