#include<iostream>
#include<iterator>

using namespace std;

void test1();
void test2();
void test3();
void multi_dim_arr();
int main()
{
	//test3();
	
	int *u = nullptr;
	int *u2 = NULL;
	
	multi_dim_arr();
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
	int a[] = {
		8, 9,10, 1, 2, 3,4, 5
	};
	
	for(int *p = begin(a), *e=end(a); p != e; p++) {
		cout<<*p<<" ";
	}
	cout<<endl;  
	
	int *p = begin(a), *e=end(a);
	cout<< (e - p) << endl;  
}

void test3() {
	int a[] = {
		8, 9,10, 1, 2, 3,4, 5
	};
	
	int *p = a, *e= a+8;
	
	int *n = &a[2];
	cout<< "p < n is"<<(p<n)<<endl;
	while(p < e) {
		cout<<*p<<" ";
		p++;
	}
	cout<<endl;
}

void multi_dim_arr()
{
	int a[3][5] = {
		1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
	};
	
	for(auto &row:a) {
		for(auto &e:row) {
			cout<<e<<" ";
		}
		cout<<endl;
	}
	
	for(auto &row:a) {
		for(auto &e:row) {
			if(e % 5 == 0) {
				e = e * e;
			}
		}
	}
		
	for(auto &row:a) {
		for(auto &e:row) {
			cout<<e<<" ";
		}
		cout<<endl;
	}
}
