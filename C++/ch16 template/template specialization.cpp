#include<iostream> 
#include<string>
#include<vector>

using namespace std;

// 函数模板特例化 start 
template <typename T> 
int compare(const T &left, const T &right) {
	if(left < right) {
		return -1;
	} else if(right < left) {
		return 1;
	} else {
		return 0;
	}
}

template <>
int compare(const int &left, const int &right) {
	// 这是函数模板特例化
	// 特例化的本质是实例化一个模板，而非重载它。因此，特例化不影响函数匹配。 
	cout<<"compare(const int &left, const int &right)"<<endl;
	
	if(left < right) {
		return -1;
	} else if(right < left) {
		return 1;
	} else {
		return 0;
	}
}
// 函数模板特例化 end 

// 类模板特例化 start
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


template <>
class Stack<string> {
    public:
	void push(const string &e); 
	string& pop() {
		cout<<"template <> class Stack<string> pop()"<<endl;
		size_t s = elements.size();
		string& t = elements[s-1];
		elements.pop_back();
		return t;
	}
	
	string top() const {
		cout<<"template <> class Stack<string> top()"<<endl;
		size_t s = elements.size();
		string t = elements[s-1];
		return t;
	}
	
	bool empty()const {
		cout<<"template <> class Stack<string> empty()"<<endl;
		return elements.empty();
	}
	
	private:
	static int ins_count;
	vector<string> elements;
}; 

void Stack<string>::push(const string &e) {
	cout<<"template <> class Stack<string> push"<<endl;
	elements.push_back(e);
}

// 只能部分特例化类模板，不能部分特例化函数模板。
template <typename T, typename P>
class A {
	public:
	A(const T &t, const P &p):t(t), p(p) {
		
	}
	P& getP() const {
		return p;
	}
	T& getT() {
		return t;
	}
	private:
	T t;
	P p;
};

// 类模板特例化 end 

void test1();
void test2();
int main()
{
	//test1();
	
	test2();
	return 0;
}

void test1()
{
	cout<<compare(3,8)<<endl;
}
 
void test2()
{
    Stack<string> ss;
	ss.push("const ");
	ss.push("oki");
	cout<<ss.pop()<<endl;
}