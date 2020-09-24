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
	// allocator��������ǰ��ڴ����Ͷ�������뿪����
	// ��������ڴ���ԭʼ�ġ�δ����� 
	
	test1();
	return 0;
} 

void test1()
{
	allocator<A> alloc;
	int n = 8;
	A* const p = alloc.allocate(n); // step 1 �����ڴ� 
	A *q = p;
	while(q-p < 8) {
		alloc.construct(q); // step 2 ���ù��캯�� 
		q++;
	}
	
	while(q != p) {
		alloc.destroy(--q); // step 3 ������������ 
	}
	
	// �ظ������ڴ�һ�� 
	while(q-p < 8) {
		alloc.construct(q); // step 2 ���ù��캯�� 
		q++;
	}
	
	while(q != p) {
		alloc.destroy(--q); // step 3 ������������ 
	}
	
	
	alloc.deallocate(p, n); // step 4 �����ڴ� 
	
}