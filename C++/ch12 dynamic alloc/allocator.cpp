#include<iostream>
#include<memory>
#include<string> 

using namespace std;

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

int main()
{
	// allocator类帮助我们把内存分配和对象构造分离开来。
	// 它分配的内存是原始的、未构造的 
	
	test1();
	return 0;
} 

void test1()
{
	allocator<A> alloc;
	int n = 8;
	A* const p = alloc.allocate(n); // step 1 分配内存 
	A *q = p;
	while(q-p < 8) {
		alloc.construct(q); // step 2 调用构造函数 
		q++;
	}
	
	while(q != p) {
		alloc.destroy(--q); // step 3 调用析构函数 
	}
	
	// 重复利用内存一次 
	while(q-p < 8) {
		alloc.construct(q); // step 2 调用构造函数 
		q++;
	}
	
	while(q != p) {
		alloc.destroy(--q); // step 3 调用析构函数 
	}
	
	
	alloc.deallocate(p, n); // step 4 回收内存 
	
}