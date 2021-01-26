#include<iostream>
#include<iterator>


using namespace std;

int main(int argc, const char **argv) 
{
	cout<<"Input num of arguments:"<< argc<<endl;
	
	cout<<"Input strings:"<<endl; 
	for(unsigned i = 0; i < argc; i++) {
		cout<<argv[i]<<endl;
	}
	return 0;
}