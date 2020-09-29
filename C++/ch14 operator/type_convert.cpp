#include<iostream>

using namespace std;

class SmallInt {
	public:
	SmallInt(int i = 0):val(i) {
		
	}
	
	/*explicit*/ operator int() const {
		return val;
	}
	private:
	int val;
};

int main()
{
	SmallInt si;
	si = 4; //调用带有整型的构造函数创建类4，再调用拷贝赋值运算符 
	cout<< si + 3 <<endl; // 调用operator int() 
	//cout<< int(si) + 3 <<endl; // 若是explicit，需要这样调用，上句是错误的 
	return 0;
}

