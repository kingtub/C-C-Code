#include<iostream>
#include<string>
#include<vector>

using namespace std;


template <typename T>
class Stack {
	public:
	void push(const T &e); 
	T& pop() {
		size_t s = elements.size();
		T& t = elements[s-1];
		elements.pop_back();
		return t;
	}
	
	T top() const {
		size_t s = elements.size();
		T t = elements[s-1];
		return t;
	}
	
	bool empty()const {
		return elements.empty();
	}
	
	private:
	static int ins_count;
	vector<T> elements;
};

// 在类外部定义成员函数的示例。构造函数也一样，只是没有返回值。 
template <typename T>
void Stack<T>::push(const T &e) {
	elements.push_back(e);
}

// static 成员定义 
template <typename T> int Stack<T>::ins_count = 0; 

int main()
{
	Stack<int> si;
	si.push(10);
	si.push(5);
	si.push(2);
	cout<<si.pop()<<endl;
	cout<<si.pop()<<endl;
	int t = si.top();
	cout<<t<<endl;
	cout<<si.pop()<<endl;
	
	Stack<string> ss;
	ss.push("const ");
	ss.push("oki");
	cout<<ss.pop()<<endl;
	return 0;
}