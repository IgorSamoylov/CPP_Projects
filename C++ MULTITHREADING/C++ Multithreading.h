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
								//����� ��������� - ���� ������������� ������
	{
		/* lock_guard - ������ syncronized �� JAVA. ����� ��� ������ ������, �� �������� �������� �������
		(������� lock()), � ����� ������ ���������, �� �������������
		����������� �������(������� unlock()).*/
		//std::lock_guard<std::mutex> guard(class_mutex);
	} 

	/*������������ ��� C++ �������� ��������������� ���������� ������������ ��� ������� ������
	������� �� ����� �������� ������ */
	void operator () () { 
		getMax();
	}

	
	
	long long getMax() {
		//std::mt19937_64 randomEngine;
		//randomEngine.seed(std::time(nullptr));

		max = long long(std::pow(n, 10));
		std::string output = std::to_string(n) + " � ������� 10 = " + std::to_string(max) + "\n";

		
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