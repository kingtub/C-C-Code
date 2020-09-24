#include<iostream>
#include<memory> 
#include<vector>
#include<string> 

using namespace std;

void del_vect_str(vector<string> *vs);
void del_vect_str2(vector<string> *vs);
int main()
{
	vector<string> *vsp = new vector<string>;
	vsp->push_back("ABC");
	vsp->push_back("Hello");
	
	shared_ptr<vector<string>> spvsp(vsp, del_vect_str);
	
	vector<string> vs;
	vs.push_back("Not P ABC");
	vs.push_back("Not P Hello");
	
	shared_ptr<vector<string>> spvs(&vs, del_vect_str2);
	return 0;
}

void del_vect_str(vector<string> *vs)
{
	for(auto &o:*vs) {
		cout<<o<<endl;
	}
	delete vs;
}

void del_vect_str2(vector<string> *vs)
{
	for(auto &o:*vs) {
		cout<<o<<endl;
	}
}