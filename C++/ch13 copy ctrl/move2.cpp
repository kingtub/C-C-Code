#include<iostream>
#include<utility>
#include<string> 

using namespace std;


// ֻ�е�һ����û�ж����κ��Լ��汾�Ŀ������Ƴ�Ա�������ÿ����static���ݳ�Ա�������ƶ�ʱ���������Ż�Ϊ���ϳ��ƶ����캯�����ƶ���ֵ�������
// �����������ƶ��������͵ĳ�Ա�����һ����Ա��
// �����ͣ��Ҹ����ж�Ӧ���ƶ�������������Ҳ���ƶ������Ա��
class A {
	public:
	A() = default;
	~A() {
		//cout<<"A ����������ִ��"<<endl;
	}
	
	// ע�͵���������������Ǻϳɣ���Ϊ������������ 
	/*A(A &&a)noexcept {
		i = a.i;
		s = a.s;
		cout<<"Move constructor"<<endl;
	}
	A& operator=(A &&a) noexcept {
		if(this != &a) {
			i = a.i;
			s = a.s;
		}
	    cout<<"move-assignment operator,�ƶ���ֵ�����"<<endl;
		return *this;
    }*/
    
	private:
	int i;
	string s; // string �����Լ����ƶ����� 
}; 


void test1();
 
int main()
{
	test1();
	return 0;
} 


void test1()
{
	A a1;
	A a2 = move(a1); // ʹ��A���ƶ����캯�� ���ɶ���a2 
	A a3;
	a3 = move(a2);  // ʹ���ƶ���ֵ����� 
}