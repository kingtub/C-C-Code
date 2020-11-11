#include<iostream>
#include<stdexcept> 
#include<exception>
#include<string>

using namespace std; 

void test1();
void test2();
void test3();

void recoup(int) noexcept; // ���˲��׳��쳣˵��
class A {
	public:
	A(const string &s, int i) try: // ���Ǻ���try���� 
	// �����try������catch���ܴ����캯�����׳����쳣��Ҳ�ܴ����Ա��ʼ���б��׳����쳣��
	name(s), d(i) {
		
	} catch(const exception &e) {
		// �쳣������� 
	}
	private:
	string name;
	int d;
}; 

int main()
{
	/*try {
		test1();
	} catch(const logic_error &re) {
		cout<<"Catch "<<re.what()<<" in main"<<endl;
	}*/
	
	//test2();
	
	test3();
	return 0;
}

void test1() 
{
	int i;
	while(cin>>i) {
		if(i == -1) {
			break;
		}
		
		try {
			switch(i) {
				case 1:
					throw length_error("Length error");
				case 2:
					throw domain_error("Domain Error");
				}
	
		} catch(const length_error &le) {
			cout<<le.what()<<endl;
		} catch(const domain_error &de) {
			cout<<de.what()<<endl;
			// �����׳�
			throw; 
		}

	}
}

void test2()
{
	int i;
	while(cin >> i) {
		if(i == -1) {
			break;
		}
		// ���������쳣 
		try {
			switch(i) {
				case 0:
				throw invalid_argument("Invalid argument");
				case 1:
				throw out_of_range("Out of range error");
				case 2:
				throw overflow_error("Overflow Error");
			}
		} catch(...) {
			cout<<"Catch All: i is "<<i<<endl;
		}
	}

}

void recoup(int) noexcept
{
	cout<<"This is noexcept func"<<endl;
}

void test3()
{
	// noexcept�����
	cout<<boolalpha<<noexcept(test1())<<endl; 
	cout<<noexcept(test2())<<endl;
	cout<<noexcept(recoup(1))<<endl;
	cout<<noboolalpha; 
}