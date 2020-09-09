#include<iostream>
#include<string>

using namespace std;

class B {
	public:
	// ������Ĭ�ϳ�ʼ������ֵ��ʼ��ʱ��Ĭ�Ϲ��캯�������� 
   	B(int i=1):k(i) {
   		// �ṩĬ�ϳ�ʼֵ�������βΣ����൱��Ĭ�Ϲ��캯�� 
	   	cout<<"B Default constructor"<<endl;
	   }
    int getK() {
    	return k;
    }
   	private:
   	int k;
};

class C {
	public:
	C(string s):name(s) {
		cout<<"C Normal constructor"<<endl;
	}
	explicit C(int k): n(k){
		cout<<"C Normal constructor int k"<<endl;
	} 

	string& getName() {
		return name;
	}
	
	private:
	string name;
	int n;
}; 

void outC(C c);

int main()
{
	B b1 = 3;
	B b2;
	cout<<"k1="<<b1.getK()<<endl; 
	cout<<"k2="<<b2.getK()<<endl; 
	
	string s = "A ";
	C c=s;  
	//C c2 = " aa";// ������Ϊ������ֻ��һ����ת�� 
	c.getName() += "hello";
	cout<<"name="<<c.getName()<<endl;
	
	string temp = "zhang buddy";
	outC(temp); // ��ʽ��������ת����ֻ������һ�������Ĺ��캯�� 
	//C c3 = 5;//���󣬹��캯��ʱexplicit�ģ�ֻ��ֱ�ӳ�ʼ�� 
	return 0;
} 

void outC(C c) {
	cout<<"print C, name="<<c.getName()<<endl;
}