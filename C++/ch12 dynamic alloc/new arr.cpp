#include<iostream>
#include<string> 

using namespace std;

unsigned int get_size(unsigned ui);

class A {
	public:
	A(){
		id = ++count;
		cout<<"Create A, id="<<id<<endl;
	}
	~A() {
		cout<<"Destroy A, id="<<id<<endl;
	}
	private:
	static unsigned int count;
	unsigned id;
};
unsigned int A::count = 0;

void test1();
void test2();

int main()
{
	//test1();
	
	test2(); 
	return 0;
}

unsigned int get_size(unsigned ui)
{
	return ui;
}

void test1()
{
    unsigned size = 19;
    // ������ڴ�ip�������������ͣ���˲��ܶԶ�̬�ڴ�ipʹ��begin��end����
	// Ҳ�����÷�Χfor����̬�����е�Ԫ�� ��
	// ��֮����̬���鲻���������� 
	int *ip = new int[get_size(size)];
	for(int i = 0; i!=size; i++) {
		ip[i] = i+1;
	}
	
	int count = 0;
	for(int i = 0; i!=size; i++) {
		count += ip[i];
	}
	cout<<count<<endl;
}

void test2()
{
	unsigned size = 10;
	int *ia1 = new int[size]; // δ��ʼ����10������
	int *ia2 = new int[size](); // 10��������ʼΪ0
	string *sa1 = new string[size];// 10��string��ʼΪ"" 
	string *sa2 = new string[size]();// 10��string��ʼΪ""
	
	// �±�׼��
	int *ia3 = new int[size]{1,2,3}; 
	string *sa3 = new string[size]{
		"a", "abc", "the", string(10, 'c')
	};
	
	for(unsigned i = 0; i != size; i++) {
		cout<<ia1[i]<<"  "<<ia2[i]<<"  "<<sa1[i]<<"  "<<sa2[i]<<"  "
		<<ia3[i]<<"  "<<sa3[i]<<endl;
	}
	
	A* ao1 = new A[size];// 10����ʼ���õ�A
	//delete ao1; // ��������ֻ�������׸�Ԫ�� 
	delete[] ao1; 
}