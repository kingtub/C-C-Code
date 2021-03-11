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
	auto f6=std::async(std::launch::async,Y(),1.2);  // �����߳���ִ��
	auto f7=std::async(std::launch::deferred,baz,std::ref(x));  // ��wait()��get()����ʱִ��
	auto f8=std::async(
	              std::launch::deferred | std::launch::async,
	              baz,std::ref(x));  // ʵ��ѡ��ִ�з�ʽ
	auto f9=std::async(baz,std::ref(x));
	f7.wait();  //  �����ӳٺ���
	*/

	//future<int> result = async(func, 10); // �����������߳�ִ�� 
	future<int> result = async(launch::async, func, 10);
    for(int j = 0; j < 20; j++) {
		this_thread::sleep_for(chrono::milliseconds(200));
		cout<<"main thread id="<<this_thread::get_id()<<", things "<< j <<endl;
	}
	
	cout<<"The result is "<<result.get()<<endl; // ����get()������������ǰ�߳� 
	return 0;
}