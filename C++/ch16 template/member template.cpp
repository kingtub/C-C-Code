#include<iostream>

using namespace std;

// ��ͨ��ĳ�Աģ��
class A {
	public:
	template <typename T> const T& bigger(const T &a, const T &b) {
		if(a < b) {
			return b;
		} else {
			return a;
		}
	}
};

// ��ģ��ĳ�Աģ��
// ������ģ�壬����Ҳ����Ϊ�䶨���Աģ�塣�ڴ�����£���ͳ�Ա�������Լ��ġ�������ģ�������
template <typename T> class B {
	public:
	// ���캯���Ǻ���ģ�� 
	template <typename K> B(const K &k);
	
	template <typename P> const P& smaller(const P &a, const P &b);
}; 
template<typename T>
template<typename K>
B<T>::B(const K &k) {
	cout<<k<<endl;
}

template<typename T>
template<typename I> 
const I& B<T>::smaller(const I &a, const I &b) {
	if(a < b) {
		return a;
	} else {
		return b;
	}
}


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
	A a;
	cout<<a.bigger(3, 5)<<endl;
	cout<<a.bigger("vector", "string")<<endl;
}

void test2()
{
	// ���������� ����ģ���ʵ�����ƶ�����ʵ�����ͣ� 
	B<int> b(5.0);
	cout<<b.smaller("hhu", "kkk")<<endl;
}