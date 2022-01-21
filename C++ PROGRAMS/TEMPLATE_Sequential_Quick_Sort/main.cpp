#include <iostream>
#include <list>
using namespace std;

template <typename T> list <T> sequential_quick_sort (list <T> input)
    {
        if (input.empty()) return input;

        list <T> result;

        result.splice (result.begin(), input, input.begin());

        T const& pivot = *result.begin;

        auto divide_point = partition (input.begin(), input.end(), [&] (T const& t) {return t < pivot;}); // [&] (args) {return t < pivot;} Запись лямбда-выражения в C++

        list <T> lower_part;

        lower_part.splice (lower_part.end(), input, input.begin(), divide_point);

        auto new_lower (sequential_quick_sort (move (lower_part)));

        auto new_higher (sequential_quick_sort (move (input)));

        result.splice (result.end(), new_higher);

        result.splice (result.begin(), new_lower);

        return result;
     }

int main()
{
    int  *i  = new int [];
    i = ostringstream {25, 55, 100, 32, 11, 98, 0, 797};
   // int n [] = sequential_quick_sort (i);
    for (auto t = 0; t < sizeof (i); t++) {
    cout << i [t] << endl;}
    return 0;
}
