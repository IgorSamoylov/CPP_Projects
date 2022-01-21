#include "Header.h"

void Reader_private_field::read_private(TestClass obj) {
        cout << obj.cat_name2 << endl;
}


void read_private_field(TestClass obj) {

    cout << obj.cat_name << endl;
}


class Reader_friendly {
public:
    Reader_friendly() {
        cout << TestClass::n << endl;

        TestClass::my_static();

        cout << TestClass::cat_name3 << endl;

        cout << TestClass::cat_name4 << endl;
    }
};

/*Статические переменные класса могут быть объявлены в заголовке,
но должны быть определены в файле .cpp.
Это происходит потому, что существует только один экземпляр статической переменной,
и компилятор не может решить, в какой сгенерированный объектный файл поместить ее,
поэтому вам придется принять решение вместо этого.*/

const char* TestClass::cat_name4 = "CAT SNEJOK";


int main()
{
    TestClass testClass;

    read_private_field(testClass);

    Reader_private_field reader1;

    reader1.read_private(testClass);

    Reader_friendly reader_friendly;

    // Обратить внимание, что объявление примитивного массива в C++ отличается от принятого в JAVA
    int array[20];
    int* array2;

}

