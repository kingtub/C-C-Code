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



// ����д��, �����൱��������һ����Ϊmy_thread�ĺ����������������һ������(����ָ��ָ��û�в���������background_task����ĺ���)��
// ����һ��std::thread����ĺ���������������һ���̡߳�
//std::thread my_thread(background_task()); 
// �ο� https://www.bookstack.cn/read/CPP-Concurrency-In-Action-2ed-2019/content-chapter2-2.1-chinese.md

void aa() {
	
}

int main()
{
	thread t(aa);
    t.detach();
    cout<<boolalpha<<t.joinable()<<noboolalpha<<endl;
	return 0;
}