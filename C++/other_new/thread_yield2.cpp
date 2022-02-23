#include <iostream>  
#include <chrono>  
#include <thread> 
#include <atomic>
#include <mutex>

using namespace std;

atomic<bool> ready(false);

void pMsg()
{
    while(!ready.load()) {
    	this_thread::yield();
    }
    
    cout<<"PMsg print"<<endl;
}

int main(int argc, char **argv)
{
        thread t(pMsg);
        this_thread::sleep_for(chrono::seconds(10));
        ready = true;
        t.join();
	return 0;
}
