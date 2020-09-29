#include<iostream>
#include<initializer_list>

using namespace std;

class A {
	public:
	A(initializer_list<int> ili) {
		elements = new int[ili.size()];
		int *t = elements;
		for(const int* s = ili.begin(); s != ili.end();) {
			*t++ = *s++;
		}
	}
	~A() {
		delete[] elements;
	}
	int& operator[](size_t i) {
		cout<<"not const, index="<<i<<endl;
		return elements[i];
	}
	
	const int& operator[](size_t i) const {
		cout<<"Const, index="<<i<<endl;
		return elements[i];
	}
	private:
	int *elements;
};


int main()
{
	A a({
		3,4, 6,8, 10
	});
	
	cout<< a[1]<<endl;
	a[2] = 9;
	cout<< a[2]<<endl;
	
	const A ca({
		13,4, 6,8, 20
	});
	
	cout<< ca[0]<<endl;
	//ca[4] = 15; error
	cout<< ca[4]<<endl;
	
	return 0;
}