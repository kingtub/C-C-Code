#include<iostream>
#include<random>
#include<cmath>
#include<map>

using namespace std;

void test1();
void test2();
void test3();

int main()
{
	//test1();
		
	//test2();
	
	test3();
	return 0;
} 

void test1()
{
	// 随机数引擎是函数对象类。不接受参数的那种。 
	default_random_engine e;
	for(size_t i = 0; i < 10; i++) {
		cout<<e()<<"  ";
	} 
	cout<<endl;
	default_random_engine d(108); // 108是随机数种子 
	for(size_t i = 0; i < 10; i++) {
		cout<<d()<<"  ";
	} 
	cout<<endl;
}

void test2()
{
	// 产生随机数通常需要 随机数引擎类对象 和 随机数分布类对象来配合 
	unsigned seed = 268;
	//  随机数引擎类对象
	default_random_engine generator(seed);
	long min = 10, max = 100;
	// 生成10到100（包含）之间的均匀分布的随机数 
	uniform_int_distribution<long> uid(min, max); // 随机数分布类 
	for(size_t	i = 0; i<10; i++) {
		// 将uid作为随机数源
		// 每个调用产生在指定范围内服从均匀分布的随机数 
		cout<<uid(generator)<<endl; 
	} 
}

void test3()
{
	default_random_engine generator(157);
	// 正态分布，均值为4，标准差为1.5 
	normal_distribution<> nd(4, 1.5);
	map<int, size_t> m;
	for(size_t i = 0; i < 200; i++) {
		int k = lround(nd(generator));
		m[k]++;
	}
	for(auto begin = m.cbegin(), e = m.cend(); begin != e; begin++) {
		cout<<begin->first<<"  :  "<<begin->second<<endl;
	}
}