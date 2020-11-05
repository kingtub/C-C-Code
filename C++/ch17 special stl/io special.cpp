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
	cout<<"八进制:"<<oct<<20<<" "<<1024<<endl;
	cout<<"十六进制:"<<hex<<20<<" "<<1024<<endl;
	cout<<"十进制:"<<dec<<20<<" "<<1024<<endl;
	// 操纵符hex、oct和dec只影响整型运算对象，浮点值的表示形式不受影响。
	cout<<showbase;
	cout<<"default:"<<20<<" "<<1024<<endl;
	cout<<"八进制:"<<oct<<20<<" "<<1024<<endl;
	cout<<"十六进制:"<<hex<<20<<" "<<1024<<endl;
	cout<<"十进制:"<<dec<<20<<" "<<1024<<endl;
	cout<<noshowbase;
}

void test3()
{
	// 控制输入格式
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
	// 未格式化的输入、输出操作
    // 到目前为止，我们的程序只使用过格式化IO操作。输入和输出运算符（<<和>>）根据读取或写入的数据类型来格式化它们。输入运算符忽略空白符，输出运算符应用补白、精度等规则。
    // 其实还有低层操作。
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
	// 流随机访问，只支持fstream 和 sstream 
}
