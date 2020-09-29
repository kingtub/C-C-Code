#include<iostream>
#include<string>


using namespace std;
class A {
	public:
	friend ostream& operator<<(ostream &o, const A &a);
	friend istream& operator>>(istream &is, A &a);
	A()=default;
	A(int i, const string &s):i(i), s(s){
		
	}
	A(const A &o):i(o.i), s(o.s){
		
	}

	void print() {
		cout<<"i is "<<i<<endl;
		cout<<"s is "<<s<<endl;
	}
	private:
	int i;
	string s;
};

// �������������������Ƿǳ�Ա���� 
ostream& operator<<(ostream &o, const A &a)
{
	o<<a.i<<" "<<a.s;
	
	return o;
}

// ��������������������Ƿǳ�Ա���� 
istream& operator>>(istream &is, A &a)
{
	is>>a.i>>a.s;
	if(!is) {
		// ����ʧ�ܣ���ԭ��Ĭ��״̬
		a = A(); 
	}
	return is; 
}

int main()
{
	A a(3, "hello");
	cout<<a<<endl;
	
	cin>>a;
	cout<<a<<endl;
	return 0;
}
