#include<iostream>
#include<string>

using namespace std;


// ģ�嶨���Թؼ���template��ʼ�����һ��ģ������б�
// ����һ�����ŷָ��һ������ģ��������б��ü����Ű�Χ������
template <typename T> // ���У�ģ�����Ͳ����ؼ���ʹ��typename �� class 
int compare(const T &left, const T &right) {
	if(left < right) {
		return -1;
	} else if(right < left) {
		return 1;
	} else {
		return 0;
	}
}

// ģ������Ͳ�������һ������ֵ�����������С�� 
template <size_t N, size_t M>
int count(const int (&a)[N], const int (&b)[M]) {// ����a������int s[N]��һ�����ã�bͬ�� 
	int count = 0;
	for(size_t j = 0; j != N; j++) {
		count += a[j];
	}
	for(size_t j = 0; j != M; j++) {
		count += b[j];
	}
	
	return count;
}

void test1();
void test2();
void test3();

int main()
{
	//test1();
	
	//test2();
	
	test3();
	
	return 0;
}


void test1()
{
	// �����ǵ���һ������ģ��ʱ����������ͨ�����ú���ʵ����Ϊ�����ƶ�ģ��ʵ�Ρ�
	cout<<compare(1, 0)<<endl;
	cout<<compare(-3.5, -2.0)<<endl;
	cout<<compare(string("Hello"), string("good"))<<endl; 
}

void test2()
{
	//��������£�ʵ�α���Ϊ�������ʽ
	int a[] = {
		1, 2, 3
	};
	
	int b[] = {
		4, 5, 6, 7, 8, 9
	};
	
	cout<<count(a, b)<<endl;
}

void test3()
{
  class A {
		private:
		int i;
		public:
		A(int i):i(i){
			
		}
		bool operator<(const A &o) const {
			if(i < o.i) {
				return true;
			} else {
				return false;
			}
		}
	};
	
	A a1(5), a2(3);
	cout<<compare(a1, a2)<<endl;
}