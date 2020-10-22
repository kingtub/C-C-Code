#include<iostream> 

using namespace std;

// һ��������ǿ������ת������������ʽ��
// cast-name<type>(expression);
// cast-name��static_cast, dynamic_cast, const_cast��reinterpret_cast�е�һ�֡�


void test1();
void test2();
void test3(); 
void old();

int main()
{
	//test1();
	
	//test2();
	//test3();
	
	old();
	
	return 0;
} 


void test1()
{
	// static_cast
    // �κξ�����ȷ���������ת����ֻҪ�������ײ�const��������ʹ��static_cast.
    int i = 8, j = 3;
    cout<<i/j<<endl;
    
    double d = static_cast<double>(i) / j;
    cout<<d<<endl;
    
    int m = 12345678;
	short s = m;
	short s2 = static_cast<short>(m);
	cout<<s<<" "<<s2<<endl;
	
	
	void *pd = &d;
	double *p2 = static_cast<double*>(pd);
	cout<<*p2<<endl;
}


void t1(const char *p) {
	cout<<"t1(const char *p)"<<endl; 
}

void t1(char *p) {
	cout<<"t1(char *p)"<<endl; 
}
void test2()
{
    // const_castֻ�ܸı��������ĵײ�const.
	const char *cp = "asdfghjkl";
	char * cp2p = const_cast<char*>(cp);
	t1(cp);
	t1(cp2p);
	
	char a = 'O';
	char *p = &a;
	const char *p2cp = const_cast<const char*>(p);
	t1(p);
	t1(p2cp);
}

void test3()
{
	//reinterpret_castͨ��Ϊ��������λģʽ�ṩ�ϵͲ���ϵ����½��͡� �ٸ����ӣ����������µ�ת��
    int *ip;
    // ��Ȼ�ǺϷ��ģ�����������Ϊ��Σ�յ�
    char *pc = reinterpret_cast<char*>(ip); 
    // ����
	// string s(pc); 
}

void old()
{
    int i = 8, j = 3;
    
    double d = static_cast<double>(i) / j;
    cout<<d<<endl;
    
    // ��ʽ������ת�� 
    
    // C���ת�� 
    double d2 = (double)i/j;
    cout<<d2<<endl;
    // ������ʽת�� 
    int di = int(d2);
    cout<<di<<endl;
    
	const char *cp = "asdfghjkl";
	// C���ת�� 
	char * cp2p = (char*)cp;
	t1(cp);
	t1(cp2p);
	
	char a = 'O';
	char *p = &a;
	// C���ת�� 
	const char *p2cp = (const char*)(p);
	t1(p);
	t1(p2cp);
    
    int *ip;
    // ��Ȼ�ǺϷ��ģ�����������Ϊ��Σ�յ�
    // C���ת�� 
    char *pc = (char*)ip;
    
    
}