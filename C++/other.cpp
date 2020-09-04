#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

void test1();
void test2();
void test3();
void test4(); 

int main()
{
	//test1();
	// test2();
	// test3();
	test4();
	return 0;
}

void test1() {
		int a[] = {
		1, 2, 3,4, 5
	};
	
	for(int i:a)
        cout<<i<<" ";
	cout<<endl;
}

void test2() {
	int i(5);
	cout<< i<<endl;
}

void test3() {
	for(int i = 1; i <= 0x7F; i++)
	cout<<(char)i<<" ";
}

void test4() {
	int i;
	vector<float> vf;
	
	long long vpi = (long long) (&i);
	long long vpvf = (long long) (&vf);
	
	cout<<"vpi="<<vpi<<endl;
	cout<<"vpvf="<<vpvf<<endl;
	
	printf("&i=%d\n", &i);
	printf("&vf=%d\n", &vf);
	printf("sizeof(long long)=%d\n", sizeof(long long));
	printf("sizeof(long)=%d\n", sizeof(long));
	
	auto pof = &i;
	cout<<"pof="<<pof<<endl;
	printf("&i=%x\n", &i);
}

