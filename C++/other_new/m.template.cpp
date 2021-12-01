#include <iostream>  
#include <map>

using namespace std;
int main()
{
    map<int, long> m;
    m[3] = 5;
    cout<<m.template count(3)<<" Hello"<<endl;
    return 0;
}
