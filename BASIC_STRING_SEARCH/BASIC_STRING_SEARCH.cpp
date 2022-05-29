

#include <iostream>
#include <regex>
using namespace std;

int main()
{
    const string test_string = "Для condition_variable нужен unique_lock и mutex. mutex \
                          создается единый на всю программу, а unique_lock этого мьютекса\
                          осществляется каждый раз внутри функции.";

    // Формат: .find(подстрока для поиска, индекс в строке с которого начинается поиск,
    // правый "срез" подстроки(!), который может содержать пустые символы)
    size_t result = test_string.find("нужен", 10, 5);
    if (result != string::npos) cout << result << endl; // string::npos - просто size_t число
    else cout << "Not found!" << endl;

    regex substr1("единый");
    regex_iterator<const char*>::regex_type reg_iter(substr1);
    regex_iterator<const char*> next(test_string, test_string.end(), reg_iter);
   
   
   
 
}

