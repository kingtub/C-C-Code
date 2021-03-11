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
	//返回系统时钟的当前时间
	chrono::system_clock::time_point tp = chrono::system_clock::now();
	chrono::system_clock::duration dtn = tp.time_since_epoch();
    cout<< "current time since epoch, expressed in:" << std::endl;
    cout<< "periods: " << dtn.count() << std::endl;
    cout<< "seconds: " << dtn.count() * chrono::system_clock::period::num / chrono::system_clock::period::den;
    cout<< std::endl;
	// cout<<"now is "<< tp<<endl; 编译出错 
	
	
	// 当几分钟的时间要存在short类型中时，可以写成
	chrono::duration<short, std::ratio<60, 1>> d1(80); // 80分钟 
	// 因为60秒是1分钟
	cout<<d1.count()<<endl; // 80
	
	//当需要将毫秒级计数存在double类型中时，可以写成
	chrono::duration<double, std::ratio<1, 1000>> d2(2000); // 2000毫秒 
	// 因为1秒等于1000毫秒
	cout<<d2.count()<<endl;  //2000
	
	// 转换成秒 
	chrono::seconds s1 =
       chrono::duration_cast<chrono::seconds>(d1);
   	chrono::seconds s2 =
	   chrono::duration_cast<chrono::seconds>(d2);
    cout<<s1.count()<<endl;  //4800
    cout<<s2.count()<<endl;  //2
}