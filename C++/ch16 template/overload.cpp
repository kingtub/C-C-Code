#include<iostream>
#include<string>

using namespace std;

template <typename T> void aa(const T &t) {
	cout<<"aa(const T &t)"<<endl;
}

template <typename T> void aa(T *t) {
	cout<<"aa(T *t)"<<endl;
}

void aa(string *t) {
	cout<<"aa(string *t)"<<endl;
}

int main()
{
	aa(3);
	int i;
	aa(&i);
	
	string s = "";
	const string *sp = &s; 
	// 当有多个重载模板对一个调用提供同样好的匹配时，
    // 应选择最特例化的版本 
	aa(sp);
	
	string *sp2 = &s; 
	// 非模板函数和模板函数相比，优先选择非模板 
	aa(sp2); 
	
	// 但是，若需要类型转换，如const char * 转成string，则不如不需转换的模板优 
	aa("abc"); 
	return 0;
}