

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream output_file_stream; // Создаём объект выводного файлового потока 

    // Вызываем у объекта метод open и передаём туда адрес файла
    output_file_stream.open("D:/TEST C++ OUTPUT.txt");

    // Записываем в стрим строку, используя оператор передачи в поток <<
    output_file_stream << "CAT VASYA!!!";

    // Не забываем закрывать объект потока
    output_file_stream.close();



    ifstream input_file_stream;
    input_file_stream.open("D:/TEST C++ OUTPUT.txt");
    char buffer[50];
    input_file_stream >> buffer; // Так можно считать одно слово
    cout << buffer << endl;

    input_file_stream.getline(buffer, 50); // Считать строку из 50 элементов
    cout << buffer << endl;

    // Функция установки в нужную позицию, в данном случае - начало
    input_file_stream.seekg(ios_base::beg);  

    // Затираем массив буфера функцией memset
    memset(buffer, 0, 50);

    // read - то же самое, что и getline, но нельзя задать разделитель, используется для бинарников
    input_file_stream.read(buffer, 50); 
    cout << buffer << endl;

    input_file_stream.close();





    /* Использование старого способа работы с файлами - 
     Функция fopen возвращает указатель на структуру FILE */
    FILE** file{};
    fopen_s(file, "D:/TEST C++ OUTPUT.txt", "rw" );

    putc('F', *file); // Запись одного символа
    _putw(777, *file); // Запись одного числа

    string cat = "CAT IS VERY CLEVER!";
    string* cat_ptr = &cat;
    fwrite(cat_ptr, sizeof('C'), 20, *file); // Запись блока памяти, представленного указателем

    fclose(*file);
   
}

