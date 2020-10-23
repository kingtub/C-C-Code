#include<iostream>
#include<string>
// 函数指针 使用示例 


using namespace std;

bool isShorter(const string &s1, const string &s2);
// 函数指针---》只要把函数名字 替换成（*函数指针变量名），即可 
bool (*pf)(const string &s1, const string &s2); 


// 函数指针形参，若是形参写的是函数类型会自动转成函数类型的指针
void process(int v, void (*callback)(const string &)); 
// 等价的声明 
//void process(int v, void callback(const string &)); 
void printStr(const string &s); 

//利用类型别名使用 函数指针
// Ps 是函数指针类型 void (*callback)(const string &)
typedef void (*Ps)(const string &s); 

typedef decltype(printStr) *Ps2;

typedef void Ps3T(const string &s); 
typedef decltype(printStr) Ps4T; 


// 函数返回 函数指针 
decltype(printStr)* getMethod(); 


int main()
{
	pf = isShorter;
	cout<<pf("a", "bc")<<endl;
	cout<<pf("vvv", "bc")<<endl;
	

	process(1, printStr);
	// 取地址符是可选的 
	process(-1, &printStr);
	
	
	Ps p = printStr;
	p("Hello");
	
	Ps2 p2 = printStr;
	p2("Hello2");
	
	Ps3T* p3 = printStr;
	Ps4T* p4 = printStr;
	p3("P3");
	p4("P4");
	
	getMethod()("Function return function pointer");
	
	return 0;
} 

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size(); 
} 

void process(int v, void (*callback)(const string &)) 
{
	if(v > 0) {
		callback("Positive number");
	} else if(v < 0) {
		callback("Negative number");
	} else {
		callback("It is zero");
	}
}

void printStr(const string &s ) {
     cout<<s<<endl;
}

decltype(printStr)* getMethod() 
{
	return printStr;
}