

#include <iostream>
#include <map>
#include <unordered_map>

#include <algorithm>

using namespace std;

int main()

{   // Упорядоченная map на основе дерева. 
    map<int, string> myMap; 

    // Класс pair не требует предварителного подключения какой-либо библиотеки
    pair<int, string> pair1{ 1, "VASIA" };

    // Основной метод добавления в C++ map - insert, принимает std::pair
    myMap.insert(pair1);

    // Использование uniform-инициализации позволяет компилятору сразу распознать переданные pair
    myMap.insert({ 2, "BARSIK" });

    /* map поддерживает метод at получения по ключу, не вызывающий ошибок и
    перегруженный опреатор [], выбрасывающий исключение в случае отсутствия элемента */
    cout << "Easy map values: " << myMap.at(1) << " " << myMap[2] << endl; ;


    /*Третьим параметром в map может быть передана функция сравнения (перегрузкой оператора () в структуре)
     bool Оператор () должен быть обозначен как const - метод  */
    struct comparator {
        bool operator () (int n1, int n2) const {

            return n2 < n1;
        }
    };

    map<int, string, comparator> myMapAdvanced;
    myMapAdvanced.insert({ 24, "PUSHOK" });
    myMapAdvanced.insert({ 38, "SNEJOK" });

    /* Функция emplace принимает первым аргументом - ключ и вторым аргументом - значение. В отличие от insert
    сама создаёт в памяти объект для помещения в map (поэтому нет {} )     */
    myMapAdvanced.emplace(3, "KOTIK");

   // Так можно попросить итератор у самой map и установить его на начало нашей map
    map<int, string, comparator>::iterator myIterator = myMapAdvanced.begin();

    //Итераторы поддерживают разыменование как указатели, перегружая оператор *
    pair<int, string> output_pair = *myIterator;

    cout << "Advanced map first item " << output_pair.first << " " << output_pair.second << endl;



    // Итератор поддерживает инкрементацию и декрементацию, перегружая соответствующие операторы
    myIterator++;

    // Способ с обращением к классу pair через указатель на итератор
    cout << "Advanced map second item " << myIterator->first << " " << myIterator->second << endl;


    // Использование цикла for-each с map

    for (pair<int, string> itemPair : myMapAdvanced) {

        cout << "for-each cycle: " << itemPair.first << " " << itemPair.second << endl;
    }

    // C++ 17 Использование встроенной функции библиотеки <algorithm> -  for-each и Lambda - выражения в нём.  

    for_each(myMapAdvanced.begin(), myMapAdvanced.end(), [](pair<int, string> itemPair) {

        cout << "for_each from <algorithm>: " << itemPair.first << " " << itemPair.second << endl;
        });

   
}

