#include<future>
#include<chrono>
#include<thread>
#include<iostream>

using namespace std;

int func(int i) {
	for(int j = 0; j < 50; j++) {
		this_thread::sleep_for(chrono::milliseconds(200));
		cout<<"thread id="<<this_thread::get_id()<<", execute step "<< j <<endl;
	}
	
	return i*i*i;
}
int main()
{ 

    /*
	auto f6=std::async(std::launch::async,Y(),1.2);  // 在新线程上执行
	auto f7=std::async(std::launch::deferred,baz,std::ref(x));  // 在wait()或get()调用时执行
	auto f8=std::async(
	              std::launch::deferred | std::launch::async,
	              baz,std::ref(x));  // 实现选择执行方式
	auto f9=std::async(baz,std::ref(x));
	f7.wait();  //  调用延迟函数
	*/

	//future<int> result = async(func, 10); // 并不开启新线程执行 
	future<int> result = async(launch::async, func, 10);
    for(int j = 0; j < 20; j++) {
		this_thread::sleep_for(chrono::milliseconds(200));
		cout<<"main thread id="<<this_thread::get_id()<<", things "<< j <<endl;
	}
	
	cout<<"The result is "<<result.get()<<endl; // 调用get()方法会阻塞当前线程 
	return 0;
}