#include<iostream>

using namespace std;

void aa();
int main()
{
	aa();
	return 0;
}

void aa()
{
	cerr<<"func name is "<<__func__<<endl;
	cerr<<"file name is "<<__FILE__<<endl;
	cerr<<"LINE is "<<__LINE__<<endl;
	cerr<<"compiled TIME  is "<<__TIME__<<endl;
	cerr<<"Compiled DATE is "<<__DATE__<<endl;
}