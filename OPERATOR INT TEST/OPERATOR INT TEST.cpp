#include <iostream>

class Operator {

public:
    operator int() {

        //return *this; //бесконечный цикл рекурсивного вызова объекта и попытка выпонить оператор int для main

        return 111;// переопределённый опрератор int всегда возвращает 111
    }
};

int main()
{
    Operator op1;
    int i = op1;
    std::cout << i;
}

