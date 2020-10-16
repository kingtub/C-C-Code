#include<iostream>
#include<string>
#include<utility>
#include<vector>

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


//模板类型别名
typedef Stack<string> SS; // 不能用 typedef Stack<T> SS;
template <typename T> using twin = pair<T, T>;

// 也可以固定部分参数 
template <typename T> using partNO = pair<T, unsigned>;

int main()
{
	SS ss;
	ss.push("Hello");
	ss.push("OK");
	cout<<ss.pop()<<endl;
	
	twin<string> ts;
	partNO<int> iu; 
	
	Stack<> s;
	s.push(10);
	
	return 0;
}