#include<iostream>
#include<string>
 
using namespace std;

template <typename T=int>
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
	vector<T> elements;
};

// 在类外部定义成员函数的示例。构造函数也一样，只是没有返回值。 
template <typename T>
void Stack<T>::push(const T &e) {
	elements.push_back(e);
}

// 在多个文件中，实例化相同类名及参数类型会导致浪费的开销，因为它们实际上
// 是相同的类型。显示实例化可以避免这个问题。
// 实例化声明 
extern template class Stack<string>;

int main()
{
	return 0;
}