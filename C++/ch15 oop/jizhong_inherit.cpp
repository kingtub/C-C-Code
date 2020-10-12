#include<iostream>

using namespace std;

class A {
	public:
	void pubM() {
		cout<<"A::pubM"<<endl;
	}
	protected:
	void asProtected() {
		cout<<"asProtected"<<endl;
	}
	
	private:
	void As_private() {
		cout<<"As_private"<<endl;
	}
	
};

class B:public A {
	public:
	void Bpub() {
		asProtected();
	}
};

class C:private A {
	public:
	void CPub() {
		asProtected();
	}
};

// ʹ��using�ı�ɷ����� 
class D:private A {
	public:
	void CPub() {
		asProtected();
	}
	// ʹ��using�ı�ɷ����� 
	using A::pubM;
};

int main()
{
	// ��������˵������ �����������Ա������Ԫ���ܷ������ֱ�ӻ���ĳ�Աû��Ӱ�졣���м̳л�˽�м̳�ʱ���������Ա���������ɷ���ֱ�ӻ����protected��public��Ա�������ɷ���private��Ա��
    // ��������˵������Ŀ���ǿ����������û�������������������ࣩ�Ի����Ա�ķ���Ȩ�ޡ�
	B b;
	C c;
	b.Bpub();
	c.CPub(); 
	
	b.pubM();
	//c.pubM();// error, private �̳� 
	
	D d;
	d.pubM();
}