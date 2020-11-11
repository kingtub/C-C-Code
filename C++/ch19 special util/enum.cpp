#include<iostream>

using namespace std;

//C++包含两种枚举类型：限定作用域的和不限定作用域的。
// 在限定作用域的枚举类型中，枚举成员的名字遵循常规的作用域准则，并且在枚举类型的作用域外是不可访问的。与之相反，在不限定作用域的枚举类型中，枚举成员的作用域与
//枚举类型本身的作用域相同：

//限定作用域的枚举
enum struct open_modes{
 	input, output, append
 }; 
 
 //不限定作用域的枚举
 enum color {
 	red, green, blue, purple, pink
 };
 
/*enum goodcolor { // 错误，变量名重复定义 
 	red, green, blue, purple, pink
 }; */ 
 
 enum struct open_modes_advan{ // 正确 
 	input, output, append
 }; 
 color aCol = green;//正确 
 color bCol = color::pink;//正确 
 //open_modes om = output;// 错误 
 open_modes om = open_modes::output;
 
 // 未命名的、不限定作用域的枚举
 enum {
 	A=8, B=2, C= 5
 } obj; 
 
 // 默认情况下，枚举值从0开始，依次加1。不过我们也能为一个或几个枚举成员指定专门的值。如果不指定当前值，则等于前一个值加1。
 enum class intTypes {
 	charTyp = 8, shortTyp = 16, intTyp = 16, longTyp = 32,
 	longlongTyp = 64
 };
 // 枚举成员是const 
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
	//不限定作用域的枚举成员 自动转为整型
	int r = color::red; // 正确 
	//int om = open_modes::append; // 错误 
	
	enum class Types:unsigned long long/* default int */ {
		A = 11332342443543545,
		B =20
	};
}