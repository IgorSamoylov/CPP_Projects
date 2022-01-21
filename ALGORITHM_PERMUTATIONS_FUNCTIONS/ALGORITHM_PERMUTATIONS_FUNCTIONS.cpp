

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    vector<int> my_vector {1, 2, 3, 4, 5};
    //reverse(my_vector.begin(), my_vector.end());

    int n = 0;
    /* Функция bool next_permutation() совершает перестановку 1 пары в 
    *  отсортированном по возрастанию контейнере 
    *  и возвращает true, когда такая перестановка возможна */
    while (next_permutation(my_vector.begin(), my_vector.end())) {

        cout << "Permutation # " << ++n << endl;
        for_each(my_vector.begin(), my_vector.end(), [](auto i) { cout << i << " "; });
        cout << endl;
    }

    my_vector = { 1, 2, 3, 4, 5 };
    reverse(my_vector.begin(), my_vector.end());
    n = 0;
    // Обратные перестановки в отсортированном по убыванию контейнере
    while (prev_permutation(my_vector.begin(), my_vector.end())) {

        cout << "Back Permutation # " << ++n << endl;
        for_each(my_vector.begin(), my_vector.end(), [](auto i) { cout << i << " "; });
        cout << endl;
    }



}

