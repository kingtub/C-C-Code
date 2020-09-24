#include<iostream>
#include<string> 

using namespace std;

unsigned int get_size(unsigned ui);

class A {
	public:
	A(){
		id = ++count;
		cout<<"Create A, id="<<id<<endl;
	}
	~A() {
		cout<<"Destroy A, id="<<id<<endl;
	}
	private:
	static unsigned int count;
	unsigned id;
};
unsigned int A::count = 0;

void test1();
void test2();

int main()
{
	//test1();
	
	test2(); 
	return 0;
}

unsigned int get_size(unsigned ui)
{
	return ui;
}

void test1()
{
    unsigned size = 19;
    // 分配的内存ip并不是数组类型，因此不能对动态内存ip使用begin和end函数
	// 也不能用范围for处理动态数组中的元素 。
	// 总之，动态数组不是数组类型 
	int *ip = new int[get_size(size)];
	for(int i = 0; i!=size; i++) {
		ip[i] = i+1;
	}
	
	int count = 0;
	for(int i = 0; i!=size; i++) {
		count += ip[i];
	}
	cout<<count<<endl;
}

void test2()
{
	unsigned size = 10;
	int *ia1 = new int[size]; // 未初始化的10个整型
	int *ia2 = new int[size](); // 10个整数初始为0
	string *sa1 = new string[size];// 10个string初始为"" 
	string *sa2 = new string[size]();// 10个string初始为""
	
	// 新标准下
	int *ia3 = new int[size]{1,2,3}; 
	string *sa3 = new string[size]{
		"a", "abc", "the", string(10, 'c')
	};
	
	for(unsigned i = 0; i != size; i++) {
		cout<<ia1[i]<<"  "<<ia2[i]<<"  "<<sa1[i]<<"  "<<sa2[i]<<"  "
		<<ia3[i]<<"  "<<sa3[i]<<endl;
	}
	
	A* ao1 = new A[size];// 10个初始化好的A
	//delete ao1; // 错误，这样只会销毁首个元素 
	delete[] ao1; 
}