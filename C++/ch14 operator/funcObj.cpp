#include<iostream>

using namespace std;

class Cube {
	public:
	int operator()(int i) {
        return i*i*i;
	} 
};

int main()
{
	Cube cube;
	cout<<cube(2)<<endl;
	cout<<cube(-2)<<endl;
	cout<<cube(3)<<endl;
	return 0;
} 