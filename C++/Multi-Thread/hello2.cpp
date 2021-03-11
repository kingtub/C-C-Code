#include<iostream>
#include<thread>

using namespace std;

//void do_some_work();
//std::thread my_thread(do_some_work);

//Or

/* class background_task
{
public:
  void operator()() const
  {
    do_something();
    do_something_else();
  }
};
background_task f;
std::thread my_thread(f); */



// 错误写法, 这里相当与声明了一个名为my_thread的函数，这个函数带有一个参数(函数指针指向没有参数并返回background_task对象的函数)，
// 返回一个std::thread对象的函数，而非启动了一个线程。
//std::thread my_thread(background_task()); 
// 参考 https://www.bookstack.cn/read/CPP-Concurrency-In-Action-2ed-2019/content-chapter2-2.1-chinese.md

void aa() {
	
}

int main()
{
	thread t(aa);
    t.detach();
    cout<<boolalpha<<t.joinable()<<noboolalpha<<endl;
	return 0;
}