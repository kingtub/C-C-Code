#include<iostream>
#include<memory> 
#include<vector>

using namespace std;

/*
�ڴ�ķ��ࣺ��̬�ڴ桢ջ�ڴ桢���ڴ棨��̬�ڴ棩 �� 
��̬�ڴ���������ֲ�static������static���ݳ�Ա���Լ��������κκ���֮��ı�����
ջ�ڴ��������涨���ں����ڵķ�static���� 
��̬�ڴ��ջ�ڴ��еĶ����ɱ������Զ����������١� 

��̬�ڴ���Ҫ����Ա��ʽ�ط�������١� 
*/

void test1();
void test2();

class StrBlob {
	public:
	StrBlob(const vector<string>& d) {
		data = make_shared<vector<string>>(d);
	}
	void printStrs() {
		for(auto &s:*data) {
			cout<< s << endl;
		}
	}
	~StrBlob() {
		cout<<"~StrBlob: data use_count="<<data.use_count()<<endl;
	}
	private:
	shared_ptr<vector<string>> data;
};
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
	// ����ָ����2�֣�shared_ptr, unique_ptr
	shared_ptr<string> sp;
	unique_ptr<string> up; 
	
	shared_ptr<int> p1 = make_shared<int>(42);
	shared_ptr<string> p2 = make_shared<string>(10, 'a'); // �����Ĳ����б����ƥ�����͵�ĳһ�����캯�� 
	shared_ptr<int> p3 = make_shared<int>();
	
	if(p1) {
		// ����P1��ָ��һ������ 
		cout<<*p1<<endl;
	}
	cout<<*p2<<endl;
	cout<<*p3<<endl;
}

void test2()
{
	auto p = make_shared<string>("Hello");
	auto q(p);
	cout<<p.use_count()<<endl;
	cout<<q.use_count()<<endl;
} 

void test3() 
{
	StrBlob s(vector<string>({"a", "abc", "gg"}));
	s.printStrs();
	StrBlob s2 = s;
	s2.printStrs();
}