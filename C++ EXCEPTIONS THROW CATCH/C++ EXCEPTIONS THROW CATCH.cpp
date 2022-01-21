
#include "C++ EXCEPTIONS THROW CATCH.h"


int main()
{
    try {
        throw 1;
    } catch(int ex) { cout << ex << endl; }

    try {
        throw "This is const char error!";
    }
    catch (const char* ex) { cout << ex << endl; } // cout умеет выводить массивы

    try {
        //const MyException ex = MyException("This is error!");
        throw MyException("This is error!");
    }
    catch (const MyException) { cout << "MyException catched!" << endl; } // Можно не указывать переменную в параметрах catch, только тип
    
    
}

