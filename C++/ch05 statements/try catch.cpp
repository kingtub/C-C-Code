#include<iostream>
#include<stdexcept> 
#include<exception>

using namespace std;

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
	//异常类型只定义了一个名为what的成员函数，该函数没有任何参数，返回值是一个指向C风格字符串的const char*。
	// 该字符串的目的是提供关于异常的一些文本信息。
	try {
		int i = 3, b = 0;
		//cout<<(i/b)<<endl;
		throw exception();
	} catch(const exception	&e) {
		cout<<"I catch:"<<endl;
		cout<<e.what()<<endl;
	}
}

void test2()
{
		int i;
		cout<<"Input 0-3:"<<endl;
		while(cin>>i) {
			
			if(i == 0) {
				break;
			}
			
			try {
					switch(i)
					{
						case 1:
						   throw length_error("Length Error Test");
						case 2:
						   throw domain_error("Domain Error Test");
						case 3:
						   throw runtime_error("Runtime Error Test");
					}
		
			} catch(const runtime_error &re) {
			    cout<<"I catch const runtime_error &re:"<<endl;
				cout<<re.what()<<endl;
			} catch(const length_error &e2) {
				cout<<"I catch const length error &e2:"<<endl;
				cout<<e2.what()<<endl;
			} catch(const exception	&e) {
				cout<<"I catch const exception	&e:"<<endl;
				cout<<e.what()<<endl;
			} 
		}
}