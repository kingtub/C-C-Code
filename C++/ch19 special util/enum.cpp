#include<iostream>

using namespace std;

//C++��������ö�����ͣ��޶�������ĺͲ��޶�������ġ�
// ���޶��������ö�������У�ö�ٳ�Ա��������ѭ�����������׼�򣬲�����ö�����͵����������ǲ��ɷ��ʵġ���֮�෴���ڲ��޶��������ö�������У�ö�ٳ�Ա����������
//ö�����ͱ������������ͬ��

//�޶��������ö��
enum struct open_modes{
 	input, output, append
 }; 
 
 //���޶��������ö��
 enum color {
 	red, green, blue, purple, pink
 };
 
/*enum goodcolor { // ���󣬱������ظ����� 
 	red, green, blue, purple, pink
 }; */ 
 
 enum struct open_modes_advan{ // ��ȷ 
 	input, output, append
 }; 
 color aCol = green;//��ȷ 
 color bCol = color::pink;//��ȷ 
 //open_modes om = output;// ���� 
 open_modes om = open_modes::output;
 
 // δ�����ġ����޶��������ö��
 enum {
 	A=8, B=2, C= 5
 } obj; 
 
 // Ĭ������£�ö��ֵ��0��ʼ�����μ�1����������Ҳ��Ϊһ���򼸸�ö�ٳ�Աָ��ר�ŵ�ֵ�������ָ����ǰֵ�������ǰһ��ֵ��1��
 enum class intTypes {
 	charTyp = 8, shortTyp = 16, intTyp = 16, longTyp = 32,
 	longlongTyp = 64
 };
 // ö�ٳ�Ա��const 
 constexpr intTypes charBits = intTypes::charTyp; 

void test1();
int main()
{
	test1();
	return 0;
} 

void test1()
{
	intTypes t = intTypes::longlongTyp;
	switch(t) {
		case intTypes::longlongTyp:
			cout<<64<<endl;
			break;
		case intTypes::shortTyp:
			cout<<16<<endl;
			break;
		default:
			cout<<16<<endl;
			break;
	}
	//���޶��������ö�ٳ�Ա �Զ�תΪ����
	int r = color::red; // ��ȷ 
	//int om = open_modes::append; // ���� 
	
	enum class Types:unsigned long long/* default int */ {
		A = 11332342443543545,
		B =20
	};
}