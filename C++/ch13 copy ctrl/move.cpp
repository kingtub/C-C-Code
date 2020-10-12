#include<iostream>
#include<utility>

using namespace std;

// ���ǿ�������һ���ƺ�Դ����Ҳ���Ը�������ֵ��
// ������ʹ��һ���ƺ�Դ�����ֵ 
void add(int &i);
void add(int &&i);

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
	
	// �ƶ����캯�� 
	Foo(Foo &&o)noexcept {
		cout<<"Move constructor"<<endl;
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
	
	// copy-assignment operator, ������ֵ�����
	Foo& operator=(const Foo &a); 
	// move-assignment operator, �ƶ���ֵ�����
	Foo& operator=(Foo &&a) noexcept;
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

Foo& Foo::operator=(Foo &&a) noexcept
{
	
	if(this != &a) {
		name = a.name;
		k = a.k;
		cout<<"move-assignment operator,�ƶ���ֵ�����"<<endl;
	}
	
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

void test1()
{
    int i = 8; 
	//��������ֵ 
	add(i);
	// ���ʽ������ֵ����ֵ��move֮������ֵ 
	add(10); 
	add(i + 1); 
	add(move(i)); 
}

void test2()
{
	Foo f1("aa", 3);
	Foo f2(move(f1));
	
	Foo f3("bb", 123);
	Foo f4;
	f4 = move(f3);
}

void add(int &i)
{
	cout<<"������ֵ����"<<i<<endl; 
}
void add(int &&i)
{
	cout<<"������ֵ����"<<i<<endl;
}