

#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <codecvt>

using namespace std;

void notepad_formatter(string path) {
    wifstream w_input_file_stream(path.c_str()); // Преобразование в c-строку в указании пути!
    w_input_file_stream.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>)); // Так устанавливается кодировка для чтения в wifstream
    wstringstream w_string_stream;
    w_string_stream << w_input_file_stream.rdbuf(); // Чтение в буфер
    wstring file_str = w_string_stream.str(); // Преобразование потока в w_строку
    //wcout << file_str;
    w_input_file_stream.close();

    wstring pattern = wstring(L"\n+=+\n+"); // Так преобразуется литерал в wstring
    wstring replace = wstring(L"\n\n\n======================================================================================================\n\n\n\n");
    wstring w_output_file_str = regex_replace(file_str, wregex(pattern), replace);
    //wcout << w_output_file_str;

    string new_path = "C:/Users/A12/Desktop/C++1.txt";
    wofstream w_output_file_stream(new_path.c_str());
    w_output_file_stream.imbue(locale(locale::empty(), new codecvt_utf8<wchar_t>));
    w_output_file_stream << w_output_file_str;
    w_output_file_stream.close();
    

}

int main()
{
    setlocale(LC_ALL, "Russian"); // Без установки локали не работает!

    string path = "C:/Users/A12/Desktop/БЛОКНОТЫ ПРОГРАММИРОВАНИЕ/C++.txt";
    notepad_formatter(path);
}

