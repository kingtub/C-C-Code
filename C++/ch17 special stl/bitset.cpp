#include<iostream>
#include<bitset>
#include<string>
#include"..\common_util.hpp"

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
	bitset<64> b64;
	bitset<32> b32(1u);
	string s = "sstttssssttttss";
	bitset<32> b30(s, 0, s.size(), 't', 's');
	
	cout<<b64<<endl;
	cout<<b32<<endl;
	cout<<b30<<endl;
}

void test2()
{
	bitset<32> b1;
	bitset<32> b2(1u);
	cout<<to_bool_str(b1.any())<<endl;
	cout<<to_bool_str(b2.any())<<endl;
	cout<<to_bool_str(b2.none())<<endl;
	cout<<to_bool_str(b1.none())<<endl;
	
	cout<<"\n"<<b2<<endl;
	cout<<"flip(0):"<<endl;
	b2.flip(0);
	cout<<b2<<endl;
	
	cout<<"flip all:"<<endl;
	b2.flip();
	cout<<b2<<endl;
	
	b2.reset();// 将所有位复位，即置为0；
	cout<<b2<<endl; 
	b2.set(); // 将所有位置位，即置为1；
	cout<<b2<<endl;
}