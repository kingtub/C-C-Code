#include<iostream>

using namespace std;

namespace my
{
	void print()
	{
		cout<<"Hello, this is my namespace"<<endl;
	}
}

int main()
{
	my::print();
	return 0;
}
