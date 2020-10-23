#include<iostream>
#include<string>

using namespace std;

string* f1();

int sum(int m[][10], int rowSize);

int main()
{
	//string *s = f1();
	//cout<<*s<<endl;
	//delete s;
	
	int a[2][10] = {
		{
			0, 1, 2,3,4,
		5,6,7,8,9
		},
		{
			0, 1, 2,3,4,
		5,6,7,8,9
		}
	};
	cout<<"sum is "<<sum(a, 2)<<endl;
	return 0;
}

string* f1() {
	string* s = new string("Hello");
	return s;
}

int sum(int m[][10], const int rowSize) {
	int sum = 0;
	for(int i = 0; i < rowSize; i++) {
		for(int j = 0; j < 10; j++) {
			sum += m[i][j];
			cout<<m[i][j]<<" "<<endl;
		} 
	}
	
	return sum;
}