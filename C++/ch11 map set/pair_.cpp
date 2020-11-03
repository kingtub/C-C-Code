#include<iostream>
#include<utility>
#include<string>
#include<map>
#include<fstream>

using namespace std;

void test1();
void test2();
int main()
{
	//test1();
	
	const char c = 'u';
	cout<<c<<endl;
	test2();
	
	return 0;
}

void test1()
{
	pair<int, int> pt;
	pair<int, double> pd{
		2, 3.14
	};
	pair<string, double> psd{
		"hello", 8.88
	};
	
	const pair<int, string>& mp = make_pair(10, "good");
	
	cout<<pt.first<<", "<<pt.second<<endl;
	cout<<pd.first<<", "<<pd.second<<endl;
	cout<<psd.first<<", "<<psd.second<<endl;
	cout<<mp.first<<", "<<mp.second<<endl;
}

void test2()
{
	ifstream fi("pair_.cpp");
	map<char, int> m;
	char c;
	while(!fi.eof()) {
		if(fi>>c) {
			m[c]++;
			//cout<<c;
		}
	}
	fi.close();
	
	// 遍历map 1
	/*for(const auto &row:m) {
		cout.clear(); // 因为有的字符输出错误 
		cout<<row.first<<" occurs "<<row.second<<" time"<<endl;
	}*/
	
	
	// 遍历map 2
	map<char, int>::iterator itb = m.begin();
	map<char, int>::iterator end = m.end();
	while(itb != m.end()) {
		// pair<const char, int>  
		pair<const char, int> &rp = *itb;
		cout.clear(); // 因为有的字符输出错误 
		cout<< rp.first<<"  "<< rp.second <<endl;
		++itb;
	}
}