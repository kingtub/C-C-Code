#include<iostream>
#include<string>
using namespace std;

template <typename T>
void print_container(const T& t, const char * white_space = " ") {
	typename T::const_iterator cb = t.begin();
	typename T::const_iterator ce = t.end();
	for(; cb != ce; cb++) {
		cout<<*cb<<white_space;
	}
	cout<<endl;
}


template <typename T>
void print_map(const T &t, const char *white="\n")
{
	typename T::const_iterator cb = t.cbegin(), ce = t.cend();
	while(cb != ce) {
		const typename T::value_type &h = *cb;
		cout<<h.first<<" "<<h.second<<white;
		
		cb++;
	}
}

string to_bool_str(bool b) {
	return b ? "true":"false";
}