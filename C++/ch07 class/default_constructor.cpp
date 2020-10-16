#include<iostream>
#include<string>

using namespace std;

class B {
	public:
	// 当对象被默认初始化，或值初始化时，默认构造函数被调用 
   	B(int i=1):k(i) {
   		// 提供默认初始值给所有形参，即相当于默认构造函数 
	   	cout<<"B Default constructor"<<endl;
	   }
    int getK() {
    	return k;
    }
   	private:
   	int k;
};

class C {
	public:
	C(string s):name(s) {
		cout<<"C Normal constructor"<<endl;
	}
	explicit C(int k): n(k){
		cout<<"C Normal constructor int k"<<endl;
	} 

	string& getName() {
		return name;
	}
	
	private:
	string name;
	int n;
}; 

void outC(C c);

int main()
{
	B b1 = 3;
	B b2;
	cout<<"k1="<<b1.getK()<<endl; 
	cout<<"k2="<<b2.getK()<<endl; 
	
	string s = "A ";
	C c=s;  
	//C c2 = " aa";// 错误，因为编译器只做一步的转换 
	c.getName() += "hello";
	cout<<"name="<<c.getName()<<endl;
	
	string temp = "zhang buddy";
	outC(temp); // 隐式的类类型转换，只可用于一个参数的构造函数 
	//C c3 = 5;//错误，构造函数时explicit的，只能直接初始化 
	return 0;
} 

void outC(C c) {
	cout<<"print C, name="<<c.getName()<<endl;
}