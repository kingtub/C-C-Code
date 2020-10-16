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

// �����ⲿ�����Ա������ʾ�������캯��Ҳһ����ֻ��û�з���ֵ�� 
template <typename T>
void Stack<T>::push(const T &e) {
	elements.push_back(e);
}

// �ڶ���ļ��У�ʵ������ͬ�������������ͻᵼ���˷ѵĿ�������Ϊ����ʵ����
// ����ͬ�����͡���ʾʵ�������Ա���������⡣
// ʵ�������� 
extern template class Stack<string>;

int main()
{
	return 0;
}