#include<chrono>
#include<iostream>

using namespace std;

void test1();

int main()
{
	test1();
	return 0;
}

void test1()
{
	//����ϵͳʱ�ӵĵ�ǰʱ��
	chrono::system_clock::time_point tp = chrono::system_clock::now();
	chrono::system_clock::duration dtn = tp.time_since_epoch();
    cout<< "current time since epoch, expressed in:" << std::endl;
    cout<< "periods: " << dtn.count() << std::endl;
    cout<< "seconds: " << dtn.count() * chrono::system_clock::period::num / chrono::system_clock::period::den;
    cout<< std::endl;
	// cout<<"now is "<< tp<<endl; ������� 
	
	
	// �������ӵ�ʱ��Ҫ����short������ʱ������д��
	chrono::duration<short, std::ratio<60, 1>> d1(80); // 80���� 
	// ��Ϊ60����1����
	cout<<d1.count()<<endl; // 80
	
	//����Ҫ�����뼶��������double������ʱ������д��
	chrono::duration<double, std::ratio<1, 1000>> d2(2000); // 2000���� 
	// ��Ϊ1�����1000����
	cout<<d2.count()<<endl;  //2000
	
	// ת������ 
	chrono::seconds s1 =
       chrono::duration_cast<chrono::seconds>(d1);
   	chrono::seconds s2 =
	   chrono::duration_cast<chrono::seconds>(d2);
    cout<<s1.count()<<endl;  //4800
    cout<<s2.count()<<endl;  //2
}