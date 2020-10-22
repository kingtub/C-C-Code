#include<iostream>
#include <bitset>
#include<vector>

using namespace std;

void test1();
void test2();
void test3();
void test4();

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
} 


void test1()
{
	int grade = 0;
	cout<< (grade < 60) ? "fail" : "pass"; // ������ 
	cout<< ((grade < 60) ? "fail" : "pass"); 
}

void test2()
{
	unsigned long u = 1;
	//���õ�27λΪ1
	u = u<<26;
	cout<<bitset<8*sizeof(u)>(u)<<endl; 
}

void test3()
{
	//sizeof���������һ�����ʽ��һ������������ռ���ֽ����������õ�ֵ��һ��size_t���͵ĳ������ʽ��
    //����������������������ʽ��
    //sizeof (type)
    //sizeof expr�����ر��ʽ������͵Ĵ�С��
    
    long data, *p;
    size_t t1 = sizeof(long); // �洢���͵Ŀռ��С
    size_t t2 = sizeof data; //data�����͵Ĵ�С����sizeof(long);
    size_t t3 = sizeof p;  // ָ����ռ�Ŀռ��С
    size_t t4 = sizeof *p; // p��ָ���͵Ŀռ��С����sizeof(long);
    
    // sizeof��ȥ����������ֵ��ֻҪ֪���������ͣ���ʹָ��p��δ��ʼ��Ҳ�С� 
    
    cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
    
    int ia[10];
	size_t t5 = sizeof ia; //sizeof ���������ת��ָ��������
	cout<<t5<<endl; 
	//��Ϊִ��sizeof�����ܵõ���������Ĵ�С�����Կ���������Ĵ�С���Ե���Ԫ�صĴ�С�õ�������Ԫ�صĸ�����
	cout<<"arr len="<<sizeof(ia)/sizeof(ia[0])<<endl;
	
	
	//��string�����vector����ִ��sizeof����ֻ���ظ����͹̶����ֵĴ�С�������������е�Ԫ��ռ���˶��ٿռ䡣
    vector<int> vi;
    cout<<"vi = "<<sizeof(vi)<<endl;
    vi.push_back(10);
    vi.push_back(9);
    vi.push_back(8);
    cout<<"vi = "<<sizeof(vi)<<endl;
}

void test4()
{
	int ia[10];
	// ��������Ϊ�ؼ���decltype��sizeof�������ȡ��ַ&�������typeid���������ʱ,
	// ���������ת��ָ�������� 
	size_t t5 = sizeof ia; //sizeof ���������ת��ָ��������
}