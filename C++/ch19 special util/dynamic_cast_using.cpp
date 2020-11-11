#include<iostream>
#include<typeinfo>

using namespace std;

class A {
	public:
	void printMe() {
		cout<<"I am A"<<endl;
	}
	// A ���ٺ���һ���麯�����ſ���dynamic_cast 
	virtual void someFun() {
		
	}
	/*virtual*/ ~A() { // ������û��virtual������ 
		cout<<"A Is destroy"<<endl;
	}
};

class B :public A {
	public:
	void printMe() {
		cout<<"I am B"<<endl;
	}
	~B() {
		cout<<"B Is destroy"<<endl;
	}
};

void test1();
void test2();
void const_test();

int main()
{
	test1();
	
	//test2();
	
	const_test();
	return 0;
}

void test1()
{
	A *a = new B;
	a->printMe();
	if(	B *bp = dynamic_cast<B*>(a)) {
		// bp ��Ϊ0����ʾת���ɹ� 
		bp->printMe();
		a->printMe();
		delete bp; 
	} else {
		// bp Ϊ0����ʾת��ʧ�� 
	} 
	
	A *kk = nullptr;
	B *mm = dynamic_cast<B*>(kk);// ����ת��ָ�� 
	
	cout<<"\n"<<endl;
	
	try{
		B b; 
		A &ra = b;
		B &rb = dynamic_cast<B&>(ra); // ��ת�����ɹ����׳��쳣bad_cast 
		rb.printMe();
		
		ostream &os = dynamic_cast<ostream &>(cin);
	} catch(const bad_cast &bc) {
		cout<<bc.what()<<endl;
	}
}

void test2()
{
	A *a2 = new B;
	delete a2;
}

class C {
	public:
	void cc() {
		cout<<"I am C"<<endl;
	}
	
	void cc() const {
		cout<<"const, I am C"<<endl;
	}
};

class D {
	public:
	void dd() const {
		cout<<"I am dd"<<endl;
	}
};
void const_test()
{
    cout<<"\n"<<endl;
    
	const C c;
	c.cc();
	C c2;
	c2.cc();
	
	D d;
	d.dd();
}