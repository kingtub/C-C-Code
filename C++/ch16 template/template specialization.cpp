#include<iostream> 
#include<string>
#include<vector>

using namespace std;

// ����ģ�������� start 
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
	// ���Ǻ���ģ��������
	// �������ı�����ʵ����һ��ģ�壬��������������ˣ���������Ӱ�캯��ƥ�䡣 
	cout<<"compare(const int &left, const int &right)"<<endl;
	
	if(left < right) {
		return -1;
	} else if(right < left) {
		return 1;
	} else {
		return 0;
	}
}
// ����ģ�������� end 

// ��ģ�������� start
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
// �����ⲿ�����Ա������ʾ�������캯��Ҳһ����ֻ��û�з���ֵ�� 
template <typename T>
void Stack<T>::push(const T &e) {
	elements.push_back(e);
}

// static ��Ա���� 
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

// ֻ�ܲ�����������ģ�壬���ܲ�������������ģ�塣
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

// ��ģ�������� end 

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