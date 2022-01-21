#include <iostream>

using namespace std;

class ConstClass  {
public:
    const int i = 0b1111;
    volatile int n;
    ConstClass(int n) : n(n) {

    }

/* Константный метод - метод, который обязуется не менять переменные-члены класса. 
Константых классов, функций не бывает */

    void tryChange(int j) const { 
        //n += 200;
        cout << "HELLO! " << j << endl;;
    }

    void tryChange2(int j)  {
        n += 100;
        cout << "HI " << j << endl;;
    }

};


int main()
{
    // Создание константного объекта
    const ConstClass constClass(8);

    constClass.tryChange(777);

    cout << constClass.n << endl;

    const ConstClass* constClass2 = new ConstClass(999);

    constClass2->tryChange(66);

    //Попытка вызвать обычный неконстантый метод в константном объекте приводит к ошибке
    //constClass2->tryChange2(77);

    /* При создании ссылки на константный объект через разыменованный указатель
    компилятор также требует константности ссылки */ 
    const ConstClass& constClass2ref = *constClass2;
}