#include<iostream>

using namespace std;

class SmallInt {
	public:
	SmallInt(int i = 0):val(i) {
		
	}
	
	/*explicit*/ operator int() const {
		return val;
	}
	private:
	int val;
};

int main()
{
	SmallInt si;
	si = 4; //���ô������͵Ĺ��캯��������4���ٵ��ÿ�����ֵ����� 
	cout<< si + 3 <<endl; // ����operator int() 
	//cout<< int(si) + 3 <<endl; // ����explicit����Ҫ�������ã��Ͼ��Ǵ���� 
	return 0;
}

