#include<iostream>
#include<fstream>

using namespace std;

void test1();
void test2();
void test3();
void test4();
int main()
{
	//test1();
	
	//test2();
	
	//test3();
	
	test4();
	return 0;
}

void test1()
{
	bool b1 = true, b2 = false;
	cout<<"default: "<<b1<<" "<<b2<<endl;
	cout<<"boolalpha: "<<boolalpha<<b1<<" "<<b2<<endl;
	cout<<noboolalpha<<b1<<" "<<b2<<endl;
}

void test2()
{
	cout<<"default:"<<20<<" "<<1024<<endl;
	cout<<"�˽���:"<<oct<<20<<" "<<1024<<endl;
	cout<<"ʮ������:"<<hex<<20<<" "<<1024<<endl;
	cout<<"ʮ����:"<<dec<<20<<" "<<1024<<endl;
	// ���ݷ�hex��oct��decֻӰ������������󣬸���ֵ�ı�ʾ��ʽ����Ӱ�졣
	cout<<showbase;
	cout<<"default:"<<20<<" "<<1024<<endl;
	cout<<"�˽���:"<<oct<<20<<" "<<1024<<endl;
	cout<<"ʮ������:"<<hex<<20<<" "<<1024<<endl;
	cout<<"ʮ����:"<<dec<<20<<" "<<1024<<endl;
	cout<<noshowbase;
}

void test3()
{
	// ���������ʽ
	char ch;
	ifstream fin("input.txt");
	while(fin >> ch) 
	     cout<<ch;
    fin.close();
    cout<<"\n"<<endl;
    
    ifstream f2in("input.txt");
    f2in>>noskipws;
    while(f2in >> ch) 
	     cout<<ch;
    f2in>>skipws;
    f2in.close();
    cout<<endl;
}

void test4()
{
	// δ��ʽ�������롢�������
    // ��ĿǰΪֹ�����ǵĳ���ֻʹ�ù���ʽ��IO���������������������<<��>>�����ݶ�ȡ��д���������������ʽ�����ǡ�������������Կհ׷�����������Ӧ�ò��ס����ȵȹ���
    // ��ʵ���еͲ������
    char ch;
    while(cin.get(ch)) {
    	cout.put(ch);
    	if(ch == '1')
    	    break;
    }
    cout<<endl;
    
	int b;
	ifstream fin("input.txt");   
	while((b = fin.get()) != EOF) {
		cout.put(b);
	}
}

void test5()
{
	// ��������ʣ�ֻ֧��fstream �� sstream 
}
