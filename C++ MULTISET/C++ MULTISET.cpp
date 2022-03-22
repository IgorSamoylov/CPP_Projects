
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){

    multiset<int> ms { 0, 0, 0, 1, 1, 1, 2, 2, 4, 4, 5, 6, 7, 8, 9 };

    pair<multiset<int>::iterator, multiset<int>::iterator> ms_iter;

    // first в pair указывает на первый элемент диапазона равных заданному чисел,
    // а second - на upper bound, т.е. первый элемент, больший заданного
    ms_iter = ms.equal_range(2);
    cout << *ms_iter.first << " " << *ms_iter.second << endl;

    ms.insert(3);
    ms.emplace_hint(ms_iter.first, 1);
    ms.erase(4); // удаляет все соотв. элементы

    cout << "1'th count: " << ms.count(1) << endl;

    ms_iter = ms.equal_range(2);
    cout << *ms_iter.first << " " << *ms_iter.second << endl;

    for_each(ms.begin(), ms.end(), [](auto n) { cout << n << endl; });
}

