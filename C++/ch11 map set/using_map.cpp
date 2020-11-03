#include<iostream>
#include<map>

using namespace std;

void test1();
int main()
{
	test1();
	return 0;
} 

void test1()
{
	map<string, size_t> word_count;
	string word;
	
	while(cin >> word) {
		if(word == "exit") {
			break;
		}
		
		word_count[word]++;
	}
	
	for(const auto &row:word_count) {
		cout<<row.first<<" occurs "<<row.second<<" time"<<endl;
	}
} 