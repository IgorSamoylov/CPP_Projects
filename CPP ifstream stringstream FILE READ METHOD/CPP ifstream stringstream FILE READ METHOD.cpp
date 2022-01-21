

#include <iostream>
#include <fstream>
#include <sstream>
#include <codecvt>

using namespace std;

wstring readFileToString(const string& path) {

    wifstream input_stream(path.c_str()); // входной поток тоже должен быть"широким"
    input_stream.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>)); // Так устанавливается кодировка для чтения в wifstream
    wstringstream string_stream; // У пустого конструктора stringstream не должно быть скобок!
    string_stream << input_stream.rdbuf(); // Читаем файл в буфер и переводим в string_stream
    input_stream.close(); // Не забыть закрыть input_stream
    
    return string_stream.str(); // Преобразуем string_stream в w-строку


}

void copyFile(const string& path1, const string& file_name, const string& path2) {

    ifstream input_stream(path1 + file_name, ios::binary); // !Требуется указать двоичный формат чтения и записи вторым аргументом
    ofstream output_stream(path2 + "Copy " + file_name, ios::binary);
    output_stream << input_stream.rdbuf();
    input_stream.close(); output_stream.close();
}

int main()
{
    setlocale(LC_ALL, "Russian"); // Без установки локали не работает!
    string path = "C:/Users/A12/Desktop/БЛОКНОТЫ ПРОГРАММИРОВАНИЕ/C++.txt";
    //wcout << readFileToString(path); 

    string path1 = "C:/Users/A12/Desktop/";
    string file_name = "Схема исключений JAVA.png";
    copyFile(path1, file_name, path1);
}

