#include<iostream>
#include<string>
#include<memory>

using namespace std;

void test1();
void test2();
void test3();

int main()
{
   //test1();
   test2();
   return 0;
}

void test1()
{
   shared_ptr<string> sps(new string("I am good"));
   shared_ptr<string> s2;
   
   // 条件判断
   if(sps) {
     cout<<"sps is not null"<<endl;
   }
   
   if(s2) {
     cout<<"s2 is not null"<<endl;
   } else {
     cout<<"s2 is null"<<endl;
   }
}

void test2()
{
   shared_ptr<string> sps(new string("I am good"));
   
   // 像普通指针一样使用智能指针
   cout<<sps->substr(0, 3)<<endl;
   // 解引用得到对象引用
   cout<<(*sps).substr((*sps).length() - 4)<<endl;
   
}

void test3()
{
  shared_ptr<string> sps(new string("I am good"));
  
  string *obj = sps.get();
  // 说明，若sps已经把string对象释放了，指针obj将不可再用，否则发生未定义行为
  
}
