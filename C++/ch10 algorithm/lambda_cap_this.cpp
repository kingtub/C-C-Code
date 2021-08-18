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
    // ���� this ָ��: �ڳ�Ա�����е� Lambda ���ʽ���Բ���ǰ����� this ָ�룬
    // �� Lambda ���ʽӵ�к͵�ǰ���Աͬ���ķ���Ȩ�ޣ������޸���ĳ�Ա������ʹ����ĳ�Ա������
    auto lam = [this](){
        cout<<"i is "<<i<<endl;
        cout<<"d is "<<d<<endl;
        bb();
    };
    // ���this ָ��ֻ�ܰ�ֵ���� [this] �����ܰ����ò��� [&this] ��
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
