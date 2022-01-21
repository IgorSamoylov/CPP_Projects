

#include <iostream>
#include <stack>

#include <string>



template <typename T>
class StackNode {

private: T CONTENT;
         StackNode<T> *POINTER;

public:
    StackNode(T input, StackNode<T> *previous_elem) {
        this->CONTENT = input;
        POINTER = previous_elem;
    }

    T ReturnTop() {
        return CONTENT;
    }
};



template <typename T>
class HomeMadeStack {

private: StackNode<T> *PREVIOUS_POINTER;
         T id;

public:
    template <typename T>
    HomeMadeStack(T id) { //HomeMadeStack(T id) : id(id)
        PREVIOUS_POINTER = NULL;
        this->id = id;
    }

    void PUSH(T input) {

        static StackNode<T> stackNode(input, PREVIOUS_POINTER);//static создает объект, к-ры не уничтожается
        PREVIOUS_POINTER = &stackNode;                       // после выхода из функции
    }

    T ReturnTop() {
        return (*PREVIOUS_POINTER).ReturnTop(); //Постфиксный вызов функции имеет бОльший приоритет,
    }                                           // чем унарный оператор * разадресации объекта
                                                // поэтому должен быть заключен в скобки для задания приоритета

    

};


int main()
{

    std::stack <int> myStack; // Объявляем стек тип int

    for (int i = 0; i < 10000; i++) myStack.push(i); //Добавляем элемент в стек

    std::cout << myStack.top() << std::endl; // Возвращаем "верхний" элемент

    myStack.pop(); // Удаляем "верхний" элемент

    std::cout << myStack.top() << std::endl; // Возвращаем новый "верхний" элемент

    //HomeMadeStack<int> myNewStack = new HomeMadeStack<int>();
    HomeMadeStack<int> myNewStack(0);
    myNewStack.PUSH(777);
    myNewStack.PUSH(888);
    myNewStack.PUSH(1000);
    std::cout << myNewStack.ReturnTop() << std::endl;



}





