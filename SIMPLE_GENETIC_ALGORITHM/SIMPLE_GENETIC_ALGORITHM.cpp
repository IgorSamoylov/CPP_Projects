// SIMPLE_GENETIC_ALGORITHM.cpp: определяет точку входа для приложения.
//

#include "SIMPLE_GENETIC_ALGORITHM.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    srand((unsigned int)time(NULL));
    const size_t N = 1000;
    int a[N] = {};

    const int steps = 1000;

    for (int i = 0; i < steps; ++i) {
        //мутация в случайную сторону каждого элемента:
        for (size_t i = 0; i < N; ++i)
            a[i] += ((rand() % 2 == 1) ? 1 : -1);

        //теперь выбираем лучших, отсортировав по возрастанию
        sort(a, a + N);
        //и тогда лучшие окажутся во второй половине массива.
        //скопируем лучших в первую половину, куда они оставили потомство, а первые умерли:
        copy(a + N / 2, a + N, a);
        //теперь посмотрим на среднее состояние популяции. Как видим, оно всё лучше и лучше.
        cout << accumulate(a, a + N, 0) / N << endl;
    }
}
