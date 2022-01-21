#include <Windows.h>
#include <iostream>

// Пример шаблонного класса

template <typename T, typename V>
class Account {
private:
    T name;
    T surname;
    V money;

public:
    Account(T name, T surname, V money) : name(name), surname(surname), money(money)
    {}
// Укороченная форма конструктора с присвоением переданных ему значений переменным-членам класса


    T getInfoName() {
        return name;
    }

    T getInfoSurname() {
        return surname;
    }
    
    V getInfoMoney() {
        return money;
    }
};


// Пример шаблонной функции

template <typename T>
T findMaxFunction(T input1, T input2) {
    return input1 > input2 ? input1 : input2;
}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Account<std::string, int> account1("Василий", "Иванович", 1000);

    std::cout << account1.getInfoName() << " " << account1.getInfoSurname() << " " << account1.getInfoMoney() << std::endl;

    std::cout << findMaxFunction(222, 999) << std::endl;
    
    std::cout << findMaxFunction(1.787976, 5.777e10) << std::endl;

    std::cout << findMaxFunction("КОТ", "ВАСЯ") << std::endl;

    // Нам не нужно явно указывать тип передаваемых значений (часть <int> в findMaxFunction<int>),
    // компилятор вычислит это самостоятельно.
}