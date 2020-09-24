#include<iostream>
#include<new>
#include<memory> 
#include<vector> 

using namespace std;

class A {
	public:
	A() {
		cout<<"Create A"<<endl;
	}
	~A() {
		cout<<"Destroy A"<<endl;
	}
};

void test1();
void test2();

int main()
{
	//A *a = new A; 
	//delete a;
	
	//int *pi = new int(5);
	//cout<< *pi <<endl; 
	
	//test1();
	
	test2();
	
	return 0;
} 

void test1()
{
    vector<int*> vip;
	for(int i = 0; i != 10000; i++) {
		int* p2 = new (nothrow) int; 
		//cout<< "����" <<i<<endl;
		if(p2 == nullptr) {
			cout<< "�ڴ�ľ�" <<endl; 
			break;
		}
	}
	for(auto &ip:vip) {
				delete ip; 
				}
	cout<< "�˳�" <<endl; 
}

void test2()
{
	int *pi(new int(42));
	// pi2�Զ�������ü���Ϊ0ʱ��piָ��Ķ���ᱻ���٣���ʱ��ʹ��*pi�����pi�ѳ�Ϊ����ָ�롣
	// pi��ָ��Ķ��� �����������ѱ� shared_ptr���� 
	shared_ptr<int> pi2(pi); 
	int *ii = pi2.get();
	cout<< *ii<<endl;
	
	// pi2�Զ�������ü���Ϊ0ʱ��������Ķ���ᱻ����
	pi2.reset();
	cout<< *pi<<endl; // *pi��δ����� 
	cout<< *ii<<endl; // *ii��δ�����
	
}