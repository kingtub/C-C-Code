#include<iostream> 

using namespace std;

// 一个命名的强制类型转换具有如下形式：
// cast-name<type>(expression);
// cast-name是static_cast, dynamic_cast, const_cast和reinterpret_cast中的一种。


void test1();
void test2();
void test3(); 
void old();

int main()
{
	//test1();
	
	//test2();
	//test3();
	
	old();
	
	return 0;
} 


void test1()
{
	// static_cast
    // 任何具有明确定义的类型转换，只要不包含底层const，都可以使用static_cast.
    int i = 8, j = 3;
    cout<<i/j<<endl;
    
    double d = static_cast<double>(i) / j;
    cout<<d<<endl;
    
    int m = 12345678;
	short s = m;
	short s2 = static_cast<short>(m);
	cout<<s<<" "<<s2<<endl;
	
	
	void *pd = &d;
	double *p2 = static_cast<double*>(pd);
	cout<<*p2<<endl;
}


void t1(const char *p) {
	cout<<"t1(const char *p)"<<endl; 
}

void t1(char *p) {
	cout<<"t1(char *p)"<<endl; 
}
void test2()
{
    // const_cast只能改变运算对象的底层const.
	const char *cp = "asdfghjkl";
	char * cp2p = const_cast<char*>(cp);
	t1(cp);
	t1(cp2p);
	
	char a = 'O';
	char *p = &a;
	const char *p2cp = const_cast<const char*>(p);
	t1(p);
	t1(p2cp);
}

void test3()
{
	//reinterpret_cast通常为运算对象的位模式提供较低层次上的重新解释。 举个例子，假设有如下的转换
    int *ip;
    // 虽然是合法的，但是这种行为是危险的
    char *pc = reinterpret_cast<char*>(ip); 
    // 例如
	// string s(pc); 
}

void old()
{
    int i = 8, j = 3;
    
    double d = static_cast<double>(i) / j;
    cout<<d<<endl;
    
    // 旧式的类型转换 
    
    // C风格转换 
    double d2 = (double)i/j;
    cout<<d2<<endl;
    // 函数形式转换 
    int di = int(d2);
    cout<<di<<endl;
    
	const char *cp = "asdfghjkl";
	// C风格转换 
	char * cp2p = (char*)cp;
	t1(cp);
	t1(cp2p);
	
	char a = 'O';
	char *p = &a;
	// C风格转换 
	const char *p2cp = (const char*)(p);
	t1(p);
	t1(p2cp);
    
    int *ip;
    // 虽然是合法的，但是这种行为是危险的
    // C风格转换 
    char *pc = (char*)ip;
    
    
}