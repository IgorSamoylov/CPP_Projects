#pragma once

#include <string>
#include <random>
#include <ctime>
#include <chrono>
#include <cmath>
#include <mutex>


class BasicClass {

public:
	BasicClass(int n, std::string name, std::mutex& class_mutex)
								: n(n), name(name), class_mutex(class_mutex)
								//Через двоеточие - блок инициализации класса
	{
		/* lock_guard - аналог syncronized из JAVA. Когда его объект создан, он пытается получить мьютекс
		(вызывая lock()), а когда объект уничтожен, он автоматически
		освобождает мьютекс(вызывая unlock()).*/
		//std::lock_guard<std::mutex> guard(class_mutex);
	} 

	/*Традиционный для C++ механизм переопределения операторов используется для запуска данной
	функции во время создания потока */
	void operator () () { 
		getMax();
	}

	
	
	long long getMax() {
		//std::mt19937_64 randomEngine;
		//randomEngine.seed(std::time(nullptr));

		max = long long(std::pow(n, 10));
		std::string output = std::to_string(n) + " в степени 10 = " + std::to_string(max) + "\n";

		
		class_mutex.lock();
		std::cout << output << std::endl;
		class_mutex.unlock();

		return max;
	}

	~BasicClass() {
		//std::cout << "Object destroyed!" << std::endl;
	}

private:
	int n;
	long long max = 0;
	std::string name;
	std::mutex& class_mutex;
	
};