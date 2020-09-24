#include<iostream>
#include<utility>
#include<string> 

using namespace std;


// 只有当一个类没有定义任何自己版本的拷贝控制成员，且类的每个非static数据成员都可以移动时，编译器才会为它合成移动构造函数或移动赋值运算符。
// 编译器可以移动内置类型的成员。如果一个成员是
// 类类型，且该类有对应的移动操作，编译器也能移动这个成员。
class A {
	public:
	A() = default;
	~A() {
		//cout<<"A 的析构函数执行"<<endl;
	}
	
	// 注释掉，编译器会帮我们合成，因为这个类符合条件 
	/*A(A &&a)noexcept {
		i = a.i;
		s = a.s;
		cout<<"Move constructor"<<endl;
	}
	A& operator=(A &&a) noexcept {
		if(this != &a) {
			i = a.i;
			s = a.s;
		}
	    cout<<"move-assignment operator,移动赋值运算符"<<endl;
		return *this;
    }*/
    
	private:
	int i;
	string s; // string 定义自己的移动操作 
}; 


void test1();
 
int main()
{
	test1();
	return 0;
} 


void test1()
{
	A a1;
	A a2 = move(a1); // 使用A的移动构造函数 生成对象a2 
	A a3;
	a3 = move(a2);  // 使用移动赋值运算符 
}