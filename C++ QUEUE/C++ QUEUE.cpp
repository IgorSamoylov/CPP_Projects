#include <iostream>
#include <queue>
#include <random>
#include <ctime>
#include <list>


void main() {

    std::queue <int, std::list<int>> myQueue; //Переопределение реализации очереди с deque на list

    std::mt19937 engine; //Инициализация одного из встроенных в C++ генераторо рандома
    engine.seed(std::time(nullptr));

    int i = 0;
    while (i++ < 10) {
        int random = engine();
        myQueue.push(random); //Метод добавляет элемент в конец
        
    }

    size_t queue_size = myQueue.size(); //Размер очереди нужно получить заранее

    for (size_t i = 0; i < queue_size; ++i) {
        std::cout << myQueue.front() << std::endl; //Метод возвращает первый элемент
        myQueue.pop(); //Метод только удаляет первый элемент
    }

//ПРИОРИТЕТНАЯ ОЧЕРЕДЬ АВТОМАТИЧЕСКИ СОРИТРУЕТСЯ ПО МЕРЕ ПОСТУПЛЕНИЯ НОВЫХ ЭЛЕМЕНТОВ ПО УБЫВАНИЮ
std:std::priority_queue <int> myPriorityQueue;

    i = 0;
    while (i++ < 10) {
        int random = std::rand();
        myPriorityQueue.push(random);
    }

    size_t pr_queue_size = myPriorityQueue.size(); 

    for (size_t i = 0; i < pr_queue_size; ++i) {
        std::cout << myPriorityQueue.top() << std::endl; //Метод возвращает максимальный верхний элемент
        myPriorityQueue.pop(); //Метод удаляет максимальный верхний элемент
    }
}
