#include<iostream>
#include<memory> 
#include<vector>

using namespace std;

/*
内存的分类：静态内存、栈内存、堆内存（动态内存） 。 
静态内存用来保存局部static对象、类static数据成员、以及定义在任何函数之外的变量。
栈内存用来保存定义在函数内的非static对象。 
静态内存和栈内存中的对象由编译器自动创建和销毁。 

动态内存需要程序员显式地分配和销毁。 
*/

void test1();
void test2();

class StrBlob {
	public:
	StrBlob(const vector<string>& d) {
		data = make_shared<vector<string>>(d);
	}
	void printStrs() {
		for(auto &s:*data) {
			cout<< s << endl;
		}
	}
	~StrBlob() {
		cout<<"~StrBlob: data use_count="<<data.use_count()<<endl;
	}
	private:
	shared_ptr<vector<string>> data;
};
void test3();

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}

void test1()
{
	// 智能指针有2种：shared_ptr, unique_ptr
	shared_ptr<string> sp;
	unique_ptr<string> up; 
	
	shared_ptr<int> p1 = make_shared<int>(42);
	shared_ptr<string> p2 = make_shared<string>(10, 'a'); // 函数的参数列表必须匹配类型的某一个构造函数 
	shared_ptr<int> p3 = make_shared<int>();
	
	if(p1) {
		// 代码P1有指向一个对象 
		cout<<*p1<<endl;
	}
	cout<<*p2<<endl;
	cout<<*p3<<endl;
}

void test2()
{
	auto p = make_shared<string>("Hello");
	auto q(p);
	cout<<p.use_count()<<endl;
	cout<<q.use_count()<<endl;
} 

void test3() 
{
	StrBlob s(vector<string>({"a", "abc", "gg"}));
	s.printStrs();
	StrBlob s2 = s;
	s2.printStrs();
}