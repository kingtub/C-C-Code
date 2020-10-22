#include<iostream>
#include <bitset>
#include<vector>

using namespace std;

void test1();
void test2();
void test3();
void test4();

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
} 


void test1()
{
	int grade = 0;
	cout<< (grade < 60) ? "fail" : "pass"; // 有问题 
	cout<< ((grade < 60) ? "fail" : "pass"); 
}

void test2()
{
	unsigned long u = 1;
	//设置第27位为1
	u = u<<26;
	cout<<bitset<8*sizeof(u)>(u)<<endl; 
}

void test3()
{
	//sizeof运算符返回一条表达式或一个类型名字所占的字节数。其所得的值是一个size_t类型的常量表达式。
    //运算符的运算对象有两种形式：
    //sizeof (type)
    //sizeof expr（返回表达式结果类型的大小）
    
    long data, *p;
    size_t t1 = sizeof(long); // 存储类型的空间大小
    size_t t2 = sizeof data; //data的类型的大小，即sizeof(long);
    size_t t3 = sizeof p;  // 指针所占的空间大小
    size_t t4 = sizeof *p; // p所指类型的空间大小，即sizeof(long);
    
    // sizeof不去求运算对象的值，只要知道它的类型，即使指针p从未初始化也行。 
    
    cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
    
    int ia[10];
	size_t t5 = sizeof ia; //sizeof 不会把数组转成指针来处理
	cout<<t5<<endl; 
	//因为执行sizeof运算能得到整个数组的大小，所以可以用数组的大小除以单个元素的大小得到数组中元素的个数：
	cout<<"arr len="<<sizeof(ia)/sizeof(ia[0])<<endl;
	
	
	//对string对象或vector对象执行sizeof运算只返回该类型固定部分的大小，不会计算对象中的元素占用了多少空间。
    vector<int> vi;
    cout<<"vi = "<<sizeof(vi)<<endl;
    vi.push_back(10);
    vi.push_back(9);
    vi.push_back(8);
    cout<<"vi = "<<sizeof(vi)<<endl;
}

void test4()
{
	int ia[10];
	// 当数组作为关键字decltype、sizeof运算符，取地址&运算符、typeid的运算对象时,
	// 不会把数组转成指针来处理 
	size_t t5 = sizeof ia; //sizeof 不会把数组转成指针来处理
}