#include <iostream>
#include <deque>
#include <forward_list>
#include <list>

using namespace std;


int main()
{
    deque<int> myDeque{ 111, 222, 333 }; // r-value конструктор инициализации

    //cout << myDeque[0] << endl; // deque поддерживает обращение по индексу благодаря перегруженному оператору []

    myDeque.pop_back(); // Удалить последний (крайний правый элемент)
    
    myDeque.push_back(888); // Добавить элемент справа

    myDeque.pop_front(); // Удалить элемент сначала

    myDeque.push_front(334); //Добавить элемент в начало

    myDeque.emplace_front(333); // Вставить элемент в начало

    myDeque.emplace_back(999); // Вставить элемент в конец

    myDeque.emplace(myDeque.begin() + 1, 787); // Вставить на указанную (2-ю) позицию, определённую итератором

    auto iter = myDeque.cend(); //Получить константный итератор на конец очереди

    myDeque.insert(iter - 1, 555); // Вставить на предпоследнюю позицию

    myDeque.shrink_to_fit(); // Урезать выделенную память
    
    for (int n : myDeque) {
        cout << "myDeque: " << n << endl;
    }


    forward_list<int> myList{ 54, 55, 56, 57 };

    myList.push_front(53); //В forward_list можно добавлять только спереди

    // Итератор может быть только константым (не допускает арифм. операций) на начало
    myList.insert_after(myList.cbefore_begin(), 999); 

    

    for (int n : myList) {
        cout << "myList: " << n << endl;
    }
    

}

