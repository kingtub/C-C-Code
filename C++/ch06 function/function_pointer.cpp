#include<iostream>
#include<string>
// ����ָ�� ʹ��ʾ�� 


using namespace std;

bool isShorter(const string &s1, const string &s2);
// ����ָ��---��ֻҪ�Ѻ������� �滻�ɣ�*����ָ��������������� 
bool (*pf)(const string &s1, const string &s2); 


// ����ָ���βΣ������β�д���Ǻ������ͻ��Զ�ת�ɺ������͵�ָ��
void process(int v, void (*callback)(const string &)); 
// �ȼ۵����� 
//void process(int v, void callback(const string &)); 
void printStr(const string &s); 

//�������ͱ���ʹ�� ����ָ��
// Ps �Ǻ���ָ������ void (*callback)(const string &)
typedef void (*Ps)(const string &s); 

typedef decltype(printStr) *Ps2;

typedef void Ps3T(const string &s); 
typedef decltype(printStr) Ps4T; 


// �������� ����ָ�� 
decltype(printStr)* getMethod(); 


int main()
{
	pf = isShorter;
	cout<<pf("a", "bc")<<endl;
	cout<<pf("vvv", "bc")<<endl;
	

	process(1, printStr);
	// ȡ��ַ���ǿ�ѡ�� 
	process(-1, &printStr);
	
	
	Ps p = printStr;
	p("Hello");
	
	Ps2 p2 = printStr;
	p2("Hello2");
	
	Ps3T* p3 = printStr;
	Ps4T* p4 = printStr;
	p3("P3");
	p4("P4");
	
	getMethod()("Function return function pointer");
	
	return 0;
} 

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size(); 
} 

void process(int v, void (*callback)(const string &)) 
{
	if(v > 0) {
		callback("Positive number");
	} else if(v < 0) {
		callback("Negative number");
	} else {
		callback("It is zero");
	}
}

void printStr(const string &s ) {
     cout<<s<<endl;
}

decltype(printStr)* getMethod() 
{
	return printStr;
}