#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <mutex>
using namespace std; 

class MultiThread {

private: 

	vector<int> Val = { 42 };
	vector<thread> Threads; 
	mutex cout_mtx; 
	mutex Val_mtx; 

private: 
	void joinThreads(); 
	void CreateThreads(); 
	void Func(const int& ID); 
	int randGen(const int& min, const int& max); 
public: 

	MultiThread(); 

};

void MultiThread::CreateThreads(){
	for (int x = 0; x < 5; x++) {
		Threads.push_back(thread([this, x]() {Func(x); }));
	}
}

void MultiThread::joinThreads() {
	for (int x = 0; x < Threads.size(); x++) {
		Threads[x].join(); 
	}
}

MultiThread::MultiThread() {
	
	CreateThreads();

	joinThreads(); 
}

void MultiThread::Func(const int& ID) {
	cout_mtx.lock(); 
	cout << "Starting thread: " << ID << "\n"; 
	cout_mtx.unlock(); 

	Val_mtx.lock(); 
	int val = this->Val[0]; 
	Val_mtx.unlock(); 
	
	int RandomValue = randGen(0, 10); 
	val += RandomValue; 
	cout_mtx.lock(); 
	cout << "Thread: " << ID << " adding: " << RandomValue << ". New Value: " << val << ".\n"; 
	cout_mtx.unlock(); 

}

int MultiThread::randGen(const int& min, const int& max) {
	static thread_local mt19937 generator(hash<thread::id>()(this_thread::get_id())); 
	uniform_int_distribution<int> distribution(min, max); 
	return distribution(generator); 
}