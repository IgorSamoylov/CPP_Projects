
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <math.h>

using namespace std;

// Используется как аргумент вызовов методов в задаче
template <class T>
struct function {
	void operator() () {
		//sync_printer("Atom released! ", this_thread::get_id());
	}
};


// Функция потокобезопасной печати в консоль
mutex print_mutex;
void sync_printer(string str, thread::id thread_id) {
	print_mutex.lock();
	cout << str << thread_id << endl;
	print_mutex.unlock();
}

// Класс, обеспечивающий потокобезопасный int-счетчик
class SynchroCounter {
public:
	mutex sync;
	int n = 0;

	SynchroCounter() {}
	SynchroCounter(const SynchroCounter& sc) = delete; // Удаление штатного конструктора копирования C++
	SynchroCounter operator= (const SynchroCounter& sc) = delete; // Удаление штатного копирования присваиванием объектов C++??

	void operator= (int&& n) {
		sync.lock();
		this->n = n;
		sync.unlock();
	}

	void operator++ (int) { // Нужен неиспользуемый аргумент int для перегрузки постфиксной формы оператора ++
		sync.lock();
		this->n++;
		sync.unlock();
	}

	int operator() () {
		sync.lock();
		int count = n;
		sync.unlock();
		return count;
	}
};

// Класс, синхронизированный на основе потокобезопасного int-счетчика
class H2O {
public:
	mutex h_mutex, o_mutex;
	SynchroCounter counter;

	H2O() {
		//cout << "Creating class H2O instance!" << endl;
		counter = 0;
	}

	void hydrogen(function<void()> releaseHydrogen) {

		h_mutex.lock();
		// releaseHydrogen() outputs "H". Do not change or remove this line.
		releaseHydrogen();
		counter++;
		while (counter() == 2) {}
		h_mutex.unlock();
	}

	void oxygen(function<void()> releaseOxygen) {

		o_mutex.lock();
		while (counter() != 2) {};
		// releaseOxygen() outputs "O". Do not change or remove this line.
		releaseOxygen();
		counter = 0;
		o_mutex.unlock();
	}
};

class H2O_simple_count { // Из-за непотокобезопасного count неправильно синхронизирует! 
public:
	mutex h_mutex, o_mutex;
	int count = 0;

	H2O_simple_count() {
		cout << "Creating class H2O instance!" << endl;
	}

	void hydrogen(function<void()> releaseHydrogen) {

		h_mutex.lock();
		// releaseHydrogen() outputs "H". Do not change or remove this line.
		releaseHydrogen();
		count++;
		while (count == 2) {}
		h_mutex.unlock();
	}

	void oxygen(function<void()> releaseOxygen) {

		o_mutex.lock();
		while (count != 2) {};
		// releaseOxygen() outputs "O". Do not change or remove this line.
		releaseOxygen();
		count = 0;
		o_mutex.unlock();
	}

};

class H2O_cond_variable {
public:
	mutex h_mutex, o_mutex, h2o_mutex;
	unique_lock<mutex>* uniq_lock;
	condition_variable cv_h2o;
	int count = 0;

	H2O_cond_variable()  {
		unique_lock<mutex> lock(h2o_mutex);
		uniq_lock = &lock;
		cout << "Creating class H2O instance!" << endl;
	}

	void hydrogen(function<void()> releaseHydrogen) {

		h_mutex.lock();
		releaseHydrogen();
		count++;
		if (count == 2) cv_h2o.wait(uniq_lock);
		h_mutex.unlock();
	}

	void oxygen(function<void()> releaseOxygen) {

		o_mutex.lock();
		while (count != 2) {};
		releaseOxygen();
		cv_h2o.notify_all();
		count = 0;
		o_mutex.unlock();
	}

	~H2O_cond_variable() {

		uniq_lock.unlock();
	}

};




int main()
{
	H2O h2o;
	//H2O_simple_count h2o;
	//H2O_cond_variable h2o;

	auto runH = [&]() {
		sync_printer("Run H! ", this_thread::get_id());
		function<void()> func;
		h2o.hydrogen(func);
		sync_printer("H released!", this_thread::get_id());
	};

	auto runO = [&]() {
		sync_printer("Run O! ", this_thread::get_id());
		function<void()> func;
		h2o.oxygen(func);
		sync_printer("O released!", this_thread::get_id());
	};

	/* Запускаем 20 потоков со случайным выбором H и O
	constexpr int rand_middle = RAND_MAX / 2;
	for (int i = 0; i < 10; i++) {

		int random = rand();
		if (random > rand_middle) { thread threadH(runH); threadH.detach(); }
		else { thread threadO(runO); threadO.detach(); }
	}
	*/
	// Последовательный запуск 10 потоков H и 5 потоков О
	for (int i = 0; i < 10; i++) {
		thread threadH(runH); threadH.detach();
	}

	for (int i = 0; i < 5; i++) {
		thread threadO(runO); threadO.detach();
	}


	// Ожидаем завершения в основном потоке
	this_thread::sleep_for(chrono::seconds(15));

}

