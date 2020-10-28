#include<iostream>
#include<list>
#include"my_util.hpp"

using namespace std;

void test1();
void delOdd();
 
int main()
{
	//test1();
	
	delOdd();
	return 0; 
} 

void test1()
{
	list<int> li;
	
	for(int i = 0; i < 10; i++) {
		li.push_back(i);
	}
	
	cout<<"All:"<<endl;
	print_container(li, " ");
	
	cout<<"back:"<<li.back()<<endl;
	li.pop_back();
	print_container(li, " ");
	
	cout<<"front:"<<li.front()<<endl;
	li.pop_front();
	print_container(li, " ");
}

void delOdd()
{
	list<int> li;
	
	for(int i = 0; i < 10; i++) {
		li.push_back(i);
	}
	
	cout<<"All:"<<endl;
	print_container(li, " ");
	// É¾³ýËùÓÐÆæÊý 
	list<int>::iterator b = li.begin(), e = li.end();
	while(b != e) {
		if(*b % 2 != 0) {
			b = li.erase(b);
		} else {
			++b;
		}
	}
	
	cout<<"Then:"<<endl;
	print_container(li, " ");
}