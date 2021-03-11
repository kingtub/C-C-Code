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

template <typename T>
class SyncQueue {
	public:
	SyncQueue() = default;
	void addLast(const T &t);
	T removeFirst();
	
	private:
	deque<T> q;
	mutex mut;
	condition_variable cond;
};

template<typename T>
void SyncQueue<T>::addLast(const T &t) {
	lock_guard<mutex> lm(mut);
	q.push_back(t);
	cond.notify_all();
}

template<typename T>
T SyncQueue<T>::removeFirst() {
	unique_lock<mutex> ul(mut);
	while(q.empty()) {
		cond.wait(ul);
	} 
	//cond.wait(ul, [q]{return !q.empty();});
	T result = q.front();
	q.pop_front();
	ul.unlock();
	return result;
}

SyncQueue<request> que;
void make_thread()
{
	thread::id myid = this_thread::get_id();
    // ���������ͨ����Ҫ �������������� �� ������ֲ����������� 
	unsigned seed = 268;
	//  ��������������
	default_random_engine generator(seed);
	long min = 10, max = 100;
	// ����10��100��������֮��ľ��ȷֲ�������� 
	uniform_int_distribution<long> uid(min, max); // ������ֲ��� 
	for(size_t	i = 0; i<200; i++) {
		// ��uid��Ϊ�����Դ
		// ÿ�����ò�����ָ����Χ�ڷ��Ӿ��ȷֲ�������� 
		long lo = uid(generator);
		request req;
		string s = "data ";
		req.data = s + to_string(i); 
		req.no = i;
		cout<<"thread "<<myid<<" requests "<<req<<endl;
		que.addLast(req);
		this_thread::sleep_for(chrono::milliseconds(lo));
	}
}

void consumer_thread() {
	thread::id myid = this_thread::get_id();
    // ���������ͨ����Ҫ �������������� �� ������ֲ����������� 
	unsigned seed = 268;
	//  ��������������
	default_random_engine generator(seed);
	long min = 10, max = 100;
	// ����10��100��������֮��ľ��ȷֲ�������� 
	uniform_int_distribution<long> uid(min, max); // ������ֲ��� 
	for(size_t	i = 0; i<200; i++) {
		// ��uid��Ϊ�����Դ
		// ÿ�����ò�����ָ����Χ�ڷ��Ӿ��ȷֲ�������� 
		long lo = uid(generator);
		request req = que.removeFirst();
		cout<<"thread "<<myid<<" Processes "<<req<<endl;
		this_thread::sleep_for(chrono::milliseconds(lo));
	}
}

int main() {
	
	//thread t1(make_thread);
	//thread t2(consumer_thread);
	
	future<void> t1 = async(launch::async, make_thread);
	future<void> t2 = async(launch::async, consumer_thread);
	// ���������������ٽ��� 
	t1.get();
	t2.get();

	return 0;
}