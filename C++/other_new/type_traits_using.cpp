#include <iostream>
#include <type_traits>
using namespace std;

int main()
{
        cout<<boolalpha;
        
	// 判断int和const int类型
	cout<<"判断int和const int类型"<<endl;
	std::cout << "int: " << std::is_const<int>::value << std::endl;
	std::cout << "const int:" << std::is_const<const int>::value << std::endl;

    cout<<"判断类型是否相同"<<endl;
	// 判断类型是否相同
	std::cout << std::is_same<int, int>::value << "\n";
	std::cout << std::is_same<int, unsigned int>::value << "\n";

	// 添加/移除const
	cout<<"添加/移除const"<<endl;
	std::cout << std::is_same<const int, add_const<int>::type>::value << std::endl;
	std::cout << std::is_same<int, remove_const<const int>::type>::value << std::endl;

	//添加引用
	cout<<"添加引用"<<endl;
	std::cout << std::is_same<int&, add_lvalue_reference<int>::type>::value << std::endl;
	std::cout << std::is_same<int&&, add_rvalue_reference<int>::type>::value << std::endl;

	// 取公共类型
	cout<<"取公共类型"<<endl;
	typedef std::common_type<unsigned char, short, int>::type NumericType;
	std::cout << std::is_same<int, NumericType>::value << std::endl;
	
	cout<<noboolalpha;
	return 0;
}
