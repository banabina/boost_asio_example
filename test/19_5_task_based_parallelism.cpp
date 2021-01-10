#include <iostream>
#include <future>
#include <thread>

using namespace std;

int main(void)
{
	//// multi-threading
	//{
	//	int result;
	//	std::thread t([&] {result = 1 + 2;});
	//	t.join();
	//	cout << result << endl;
	//}

	//// task-based parallelism ( thread base 방법 보다 더 선호 )
	//{
	//	// std::future<int> fut = ...
	//	auto fut = std::async([] {return 1 + 2;});
	//	cout << fut.get() << endl;
	//}

	//// future and promise
	//{
	//	std::promise<int> prom;
	//	auto fut = prom.get_future();

	//	auto t = std::thread([](std::promise<int>&& prom)
	//	{
	//		prom.set_value(1 + 2);
	//	}, std::move(prom));
	//	cout << fut.get() << endl;
	//	t.join();
	//}

	{
		auto f1 = std::async([] {
			cout << "async1 start " << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
		});

		auto f2 = std::async([] {
			cout << "async2 start " << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
			});

		std::cout << "Main function" << endl;
	}
}