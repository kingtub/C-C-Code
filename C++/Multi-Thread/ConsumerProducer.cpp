#include<iostream>
#include<mutex>
#include<condition_variable>
#include<string>
#include<deque>
#include<random>
#include<thread>
#include<future>

using namespace std;

struct request {
	string data;
	int no;
};
ostream& operator<<(ostream &o, const request & req) {
	o<<"{"<<req.data<<", "<<req.no<<"}";
	return o;
}

template<typename T>
class SyncBag {
	public:
	explicit SyncBag(int fixedSize):fixedSize(fixedSize) {
		
	}
	void addLast(const T & t);
	T removeFirst(); 
	private:
	int fixedSize;
	mutex mut;
	condition_variable cond;
	deque<T> q;
};

template<typename T>
void SyncBag<T>::addLast(const T &t) {
	unique_lock<mutex> um(mut);
	while(q.size() >= fixedSize) {
		cout<<"Full, wait, size="<<q.size()<<endl;
		cond.wait(um);
	}
	q.push_back(t);
	um.unlock();
	cond.notify_all();
}

template<typename T>
T SyncBag<T>::removeFirst() {
	unique_lock<mutex> um(mut);
	while(q.empty()) {
		cout<<"Empty, wait"<<endl;
		cond.wait(um);
	}
	T t = q.front();
	q.pop_front();
	um.unlock();
	cond.notify_all();
	return t;
}

SyncBag<request> bag(5);
void produder_thread() {
	thread::id myid = this_thread::get_id();
    // 产生随机数通常需要 随机数引擎类对象 和 随机数分布类对象来配合 
	chrono::system_clock::time_point tp = chrono::high_resolution_clock::now();
	chrono::system_clock::duration dtn = tp.time_since_epoch();
	unsigned long seed = dtn.count() + 5;
	
	//  随机数引擎类对象
	default_random_engine generator(seed);
	long min = 10, max = 100;
	// 生成10到100（包含）之间的均匀分布的随机数 
	uniform_int_distribution<long> uid(min, max); // 随机数分布类 
	for(size_t	i = 0; i<200; i++) {
		// 将uid作为随机数源
		// 每个调用产生在指定范围内服从均匀分布的随机数 
		long lo = uid(generator);
		request req;
		string s = "data ";
		req.data = s + to_string(i); 
		req.no = i;
		cout<<"thread "<<myid<<" produced "<<req<<endl;
		bag.addLast(req);
		//this_thread::sleep_for(chrono::milliseconds(lo));
	}
}

void consumer_thread() {
	thread::id myid = this_thread::get_id();
    // 产生随机数通常需要 随机数引擎类对象 和 随机数分布类对象来配合 
    //返回系统时钟的当前时间
	chrono::system_clock::time_point tp = chrono::high_resolution_clock::now();
	chrono::system_clock::duration dtn = tp.time_since_epoch();
	unsigned long seed = dtn.count();
	
	//  随机数引擎类对象
	default_random_engine generator(seed);
	long min = 10, max = 100;
	// 生成10到100（包含）之间的均匀分布的随机数 
	uniform_int_distribution<long> uid(min, max); // 随机数分布类 
	for(size_t	i = 0; i<200; i++) {
		// 将uid作为随机数源
		// 每个调用产生在指定范围内服从均匀分布的随机数 
		long lo = uid(generator);
		request req = bag.removeFirst();
		cout<<"thread "<<myid<<" consumed "<<req<<endl;
		this_thread::sleep_for(chrono::milliseconds(lo));
	}
	
}


int main()
{
	future<void> t1  = async(launch::async, produder_thread);
	future<void> t2  = async(launch::async, consumer_thread);
	// 等到它们运行完成才结束
	t1.get();
	t2.get(); 
	
	return 0;
}