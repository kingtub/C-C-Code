#include<iostream>
#include<string>

using namespace std;

void find_op();
void to_number();

int main()
{
	//find_op();
	
	to_number();
	return 0;
}

void find_op()
{
	string s;
	cout<<"Input origin:"<<endl;
	cin >> s;
	string temp;
	
	while(cin >> temp) {
		if(temp == "exit") {
			break;
		}
		
		string::size_type i = s.find(temp);
		if(i == string::npos) {
			// 没找到 
			cout<<"Not found"<<endl;
		} else {
			// 找到了 
			cout<<"Found it, index="<<i<<endl;
		}
	}
}

void to_number()
{
	double p = 3.14;
	string s = to_string(p);
	cout<<s<<endl;
	
	double d2 = stod(s) + 5;
	cout<<d2<<endl;
	
	string ks = "389good";
	size_t m;
	int num = stoi(ks, &m);
	cout<<num<<" "<<m<<endl;
}