#include<iostream>

using namespace std;

class A {
	public:
	A() = default;
	~A() {
		cout<<"A ����������ִ��"<<endl;
	}
}; 
class Foo {
	public:
	Foo() = default;
	Foo(const string &s, int i):name(s), k(i){
		cout<<"Cons 2"<<endl; 
	}
	//�������캯������һ�����캯���������Լ�����Ϊ��������������������Ĭ��ֵʱ��
	// ���ǿ������캯�� 
	Foo(const Foo &o) {
		cout<<"Copy cons"<<endl;
		name = o.name;
		k = o.k;
	}
	
	~Foo() {
		// �����Ĺ��̺͹�����������Ƶģ���Ϊ2���֣������岿�ֺ���������
		// ��ִ�к����岿�֣���ִ����������
		// ������ʱ�ܹ��� ����Ա���Ƶģ�������һЩ������
		// ������������ʽ�ģ�����Ա���Ʋ��� ��ϵͳ�Զ�ִ��
		
		// ����������£�ϵͳ���Զ����� ��Աname �� ai����������
		cout<<"Foo ����������ִ��"<<endl;
	} 
	
	// copy-assignment operator,������ֵ�����
	Foo& operator=(const Foo &a); 
	private:
	string name;
	int k; 
	A ai;
};

Foo& Foo::operator=(const Foo &a)
{
	name = a.name;
	k = a.k;
	
	cout<<"copy-assignment operator,������ֵ�����"<<endl;
	
	return *this;
}

void test1(); 
void test2();

int main()
{
	//test1();
	
	test2();
	return 0;
}

void test1() {
    Foo f1("Hi", 6);//ֱ�ӳ�ʼ�� 
	Foo f2 = f1; // ������ʼ�� 
	
	
	string dots(10, '.') ; //ֱ�ӳ�ʼ�� 
	string s(dots);        //ֱ�ӳ�ʼ�� 
	string s2 = dots;      // ������ʼ�� 
	string null_book = "Iso-999";  // ������ʼ�� 
	string nines = string(100, '9');  // ������ʼ�� 
	
	// ������ʼ�� �����������¼��������
	// 1����һ��������Ϊʵ�Σ����������еķ��������͵��β� 
	// 2����һ����������Ϊ���������͵ĺ����з���һ������ 
	// 3���û������б��ʼ��һ�������һ���ۺ���ĳ�Ա 
}

void test2() {
	Foo f;
	Foo f2("Good", 3);
	f = f2;
}

