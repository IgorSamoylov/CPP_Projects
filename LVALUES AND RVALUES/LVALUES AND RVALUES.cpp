#include "LVALUES AND RVALUES.h"

int main()
{
    int x = 10;
    int& lvalueReference = x;
    int&& rvalueReference = 10 + 10;
    lvalueReference = rvalueReference;

    std::cout << std::hex << &lvalueReference << "  " << &rvalueReference << " " << lvalueReference << std::endl;

    std::vector<int> inputVector { 1, 2, 3, 4, 5, 6, 7 };// Это rvalue -инициализация для конструктора vector'a
    std::vector<int> inputVector2 = { 9, 8, 7, 6, 5, 4, 3 }; // Это lvalue значение инициализатора для конструктора

    A&& a = A(inputVector);

    std::cout << a.getFirstElem() << std::endl;

    a.swaper(inputVector, inputVector2);

    std::cout << inputVector2[0] << std::endl;

    std::map<int, std::string, CustomCompare> map1{ {1, "CAT VASIA"}, {2, "CAT BARSIK"}, {3, "CAT PUSHOK"} };
    std::map<int, std::string, CustomCompare> map2{ {1, "DOG BARBOS"}, {2, "DOG BOBIK"}, {3, "DOG LAYKA"} };

    a.universalSwaper(map1, map2);

    for (std::pair<int, std::string> pairElem : map1) {
        std::cout << pairElem.first << " " << pairElem.second << std::endl;
    }

    // Новый способ перебора map из C++17:
    for (const auto& [key, value] : map1) {
        std::cout << key << " has value " << value << std::endl;

    }

    // Способ C++11:
    for (const auto& item : map2) {
        std::cout << item.first << " " << item.second << std::endl;
    }


}

