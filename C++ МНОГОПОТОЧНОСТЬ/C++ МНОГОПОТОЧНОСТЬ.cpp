
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

int t = 0;

// Мьютекс универсальный, подходит ко всем потокам, в которых он лочиться
std::mutex myMutex;

void test1(int n) {
	for (int i = 0; i < 1000; ++i) { 
		n = i * 2; 	
	};
	t = n;
}


int main()
{
	/* Функция thread::hardware_concurrency() возвращает максимальное число потоков,
	физически выполняемых на данной машине */

	unsigned int threads = std::thread::hardware_concurrency();
	std::cout << "Number of physical threads: " << threads << std::endl;


	auto Lambda = [] (std::string threadName) {
		for (int i = 0; i < 100; ++i) {
			//Функция this_thread::get_id() возвращает id текущего потока
			std::thread::id id = std::this_thread::get_id();

			myMutex.lock();
			std::cout << id << std::endl;

			std::string output = "Thread:" + threadName + " i:" + std::to_string(i) + '\n';
			std::cout << output;
			myMutex.unlock();

			std::this_thread::sleep_for(std::chrono::milliseconds(250));
		}
	};

	auto Lambda2 = [](int n) {for (int i = 0; i < 100; ++i) { n = i * 2; } return n; };

	// Аргументы для вызова функции передаются через запятую (и копируются по умолчанию)
	std::thread ThreadA(Lambda, "A");
	std::thread ThreadB(Lambda, "B");

	ThreadA.join();
	ThreadB.join();

	//Thread3.join();
	//std::thread Thread3(test1, 100); 
	//std::cout << " T = " << t << std::endl;


}

