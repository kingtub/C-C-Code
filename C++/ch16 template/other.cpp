#include<iostream>

using namespace std;

int count(const int (&arr)[10]) {
	cout<<"count(const int (&arr)[10]):"<<endl;
	int k = 0;
	for(int i = 0; i< 10; i++) {
		k += arr[i];
	}
	return k;
}

double count(double (&arr)[10]) {
	cout<<"count(double (&arr)[10]):"<<endl;
	double k = 0;
	for(int i = 0; i< 10; i++) {
		k += arr[i];
	}
	return k;
}
int main()
{
	int a[] = {
		0,1,2,3,4,5,6,7,8,9
	};
	cout<<count(a)<<endl;
	
	double da[] = {
		0,1,2,3,4,5,6,7,8,9
	};
	cout<<count(da)<<endl;
	return 0;
} 