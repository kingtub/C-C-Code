#include<iostream>
#include<new>
#include<memory> 
#include<vector> 

using namespace std;

class A {
	public:
	A() {
		cout<<"Create A"<<endl;
	}
	~A() {
		cout<<"Destroy A"<<endl;
	}
};

void test1();
void test2();

int main()
{
	//A *a = new A; 
	//delete a;
	
	//int *pi = new int(5);
	//cout<< *pi <<endl; 
	
	//test1();
	
	test2();
	
	return 0;
} 

void test1()
{
    vector<int*> vip;
	for(int i = 0; i != 10000; i++) {
		int* p2 = new (nothrow) int; 
		//cout<< "分配" <<i<<endl;
		if(p2 == nullptr) {
			cout<< "内存耗尽" <<endl; 
			break;
		}
	}
	for(auto &ip:vip) {
				delete ip; 
				}
	cout<< "退出" <<endl; 
}

void test2()
{
	int *pi(new int(42));
	// pi2对对象的引用计数为0时，pi指向的对象会被销毁，这时若使用*pi会出错，pi已成为空悬指针。
	// pi所指向的对象 的生命周期已被 shared_ptr管理 
	shared_ptr<int> pi2(pi); 
	int *ii = pi2.get();
	cout<< *ii<<endl;
	
	// pi2对对象的引用计数为0时，它管理的对象会被销毁
	pi2.reset();
	cout<< *pi<<endl; // *pi是未定义的 
	cout<< *ii<<endl; // *ii是未定义的
	
}