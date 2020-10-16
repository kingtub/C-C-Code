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

// �����ⲿ�����Ա������ʾ�������캯��Ҳһ����ֻ��û�з���ֵ�� 
template <typename T>
void Stack<T>::push(const T &e) {
	elements.push_back(e);
}


//ģ�����ͱ���
typedef Stack<string> SS; // ������ typedef Stack<T> SS;
template <typename T> using twin = pair<T, T>;

// Ҳ���Թ̶����ֲ��� 
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