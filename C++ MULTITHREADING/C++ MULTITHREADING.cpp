
#include <iostream>
#include <thread>
#include <array>
#include <memory> // Для unique_ptr
#include <chrono>


#include "C++ Multithreading.h"



int main() {
	setlocale(LC_ALL, "rus");
	std::mutex mutex1;
	

	std::array<std::thread, 10> threadPool; // Для array нужно указывать размер)

	for (int i = 0; i < 10; ++i) {

		//ПРОСТОЙ СИНТАКСИС СОЗДАНИЯ КЛАССА В ПОТОКЕ - В БЛОКЕ ИНИЦИАЛИЗАЦИИ!
		//std::thread newThread{ BasicClass(i, "CAT") }; 
		//threadPool[i] = std::move(newThread);

		//СИНТАКСИС С ОТДЕЛЬНЫМ СОЗДАНИЕМ ОБЪЕКТА И ПЕРЕДАЧЕЙ УКАЗАТЕЛЯ НА НЕГО В ПОТОК
		// Созданный класс нужно привести к типу unique_ptr 
		std::unique_ptr<BasicClass> newPtr =
			(std::unique_ptr<BasicClass>) new BasicClass(i, "CAT", mutex1);

		/*std::ref обёртывает ссылку объектом для передачи через копирование параметров,
		которое новый поток всегда делает при создании */	


		/*А здесь в конструктор класса потока передаём разыменованный умный указатель на наш класс,
		в котором переопределён оператор (), который и запускается автоматически при
		передаче класса в поток */
		std::thread newThread(*newPtr);
		/* std::move позволяет использовать семантику перемещение, изменяя переданное
		l-value на r-value, иначе, при наполнении массива производилась бы попытка копирования
		значения */
		threadPool[i] = std::move(newThread);		
	}

	//В качестве типа элемента для цикла выступает ссылка на объект thread, а не сам класс!
	for (std::thread& currentThread : threadPool) {
		/*Отсоединяем потоки от основного потока main (нужно вызвать или join или detach,
		иначе новые потоки будут уничтожены вместе с завершением главного) */
		currentThread.detach();
	}

	//Ожидание в течение 3 секунд для потока main, иначе закроется консоль
	std::this_thread::sleep_for(std::chrono::seconds(3));

}