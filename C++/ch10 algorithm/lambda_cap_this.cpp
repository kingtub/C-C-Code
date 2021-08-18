#include<iostream>

using namespace std;

class A {
public:
    A()=default;
    A(int i_, double d_):i(i_), d(d_){}
    void aa();
private:
    void bb();
    int i;
    double d;
};

void A::aa()
{
    // 捕获 this 指针: 在成员函数中的 Lambda 表达式可以捕获当前对象的 this 指针，
    // 让 Lambda 表达式拥有和当前类成员同样的访问权限，可以修改类的成员变量，使用类的成员函数。
    auto lam = [this](){
        cout<<"i is "<<i<<endl;
        cout<<"d is "<<d<<endl;
        bb();
    };
    // 最后，this 指针只能按值捕获 [this] ，不能按引用捕获 [&this] 。
    lam();
}

void A::bb()
{
    cout<<"execute bb"<<endl;
}

int main(int argc, char** argv)
{
    A clsA(2, 3.14159);
    clsA.aa();
    return 0;
}
