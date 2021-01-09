#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

int shared_memory(0);	// ���� �����尡 shared_memory�� ����

mutex mtx;

int main(void)
{
	atomic<int> shared_memory(0);	// ���� �����尡 shared_memory�� ����
	auto count_func = [&shared_memory] {
		for (int i = 0; i < 1000; ++i)
		{
			this_thread::sleep_for(chrono::microseconds(1));
			//mtx.lock()
			//std::lock_guard lock(mtx);
			//std::scoped_lock lock(mtx);
			shared_memory.fetch_add(1);
			//mtx.unlock()
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();

	cout << "After" << endl;
	cout << shared_memory << endl;

	return 0;
}