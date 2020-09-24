#include<iostream>
#include<memory> 

using namespace std;


void del_intp(int *p);

int main()
{
	unique_ptr<int, void (*)(int *)> up(new int(20), del_intp);
	up.reset();
	return 0;
}

void del_intp(int *p)
{
	cout<<"delete "<<*p<<endl;
	delete p;
}