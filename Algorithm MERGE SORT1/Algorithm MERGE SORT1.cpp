// СОРТИРОВКА МАССИВА МЕТОДОМ РАЗДЕЛЕНИЯ И СЛИЯНИЯ С ИСПОЛЬЗОВАНИЕМ МНОГОПОТОЧНОСТИ ОТ OPEN MP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <omp.h>
#include <memory>
#include <vector>
#include <array>

template <typename Iterator>
void mergesort(Iterator from, Iterator to);


int main()
{
    int Array_Fixed [20]{ 1,23,43,12,32,54,76,878,56,45,34,23232,454,0,565,3,767,34,23,444 };
    
    std::array<int, 20> Array {1,23,43,12,32,54,76,878,56,45,34,23232,454,0,565,3,767,34,23,444};

    std::vector<int> Vector1 {1,23,43,12,32,54,76,878,56,45,34,23232,454,0,565,3,767,34,23,444 };

    //std::vector<int>::iterator V_iter = Vector1.begin();

    std::ostream_iterator<int> output (std::cout, " "); // Создаем итератор выходного потока типа int и присоединяем
                                                        // его к консольному выходному потоку
    copy(Vector1.begin(), Vector1.end(), output); // Копируем вектор с начала до конца через итератор вывода

    std::cout << std::endl;
    
    mergesort(Vector1.begin(), Vector1.end());

    copy(Vector1.begin(), Vector1.end(), output);

    std::cout << std::endl;

    mergesort(Array.begin(), Array.end());

    copy(Array.begin(), Array.end(), output);

   // std::cout << std::endl;

   // mergesort(&Array_Fixed [0], &Array_Fixed[20]);

   // copy(&Array_Fixed [0], &Array_Fixed [20], output);


}




template <typename Iterator>
void mergesort(Iterator from, Iterator to)
{
#pragma omp parallel
    {
#pragma omp single nowait
        static_assert(!std::is_same<typename std::iterator_traits<Iterator>::value_type, void>::value);

        auto n = std::distance(from, to);

        if (1 < n)
        {
#pragma omp task firstprivate (from, to, n)
            {
                Iterator l_from = from;
                Iterator l_to = l_from;
                //std::advance(l_to, n / 2);
                l_to += n / 2; // Заменили неудачную функцию advance на обычное сложение итератора с целым чилом
                mergesort(l_from, l_to);
            }
#pragma omp task firstprivate (from, to, n)
            {
                Iterator r_from = from;
                r_from += n / 2;
                Iterator r_to = r_from;              
                r_to += n - (n / 2);
                mergesort(r_from, r_to);
            }
#pragma omp taskwait

            auto tmp_array = std::make_unique<typename Iterator::value_type[]>(n);
            Iterator l_iter = from;
            Iterator l_end = l_iter;
            l_end += n / 2;
            Iterator r_iter = l_end;
            Iterator& r_end = to;

            auto tmp_iter = tmp_array.get();

            while (l_iter != l_end || r_iter != r_end)
            {
                if (*l_iter < *r_iter)
                {
                    *tmp_iter = std::move(*l_iter);
                    ++l_iter;
                    ++tmp_iter;
                }
                else
                {
                    *tmp_iter = std::move(*r_iter);
                    ++r_iter;
                    ++tmp_iter;
                }

                if (l_iter == l_end)
                {
                    std::copy(
                        std::make_move_iterator(r_iter),
                        std::make_move_iterator(r_end),
                        tmp_iter
                    );

                    break;
                }

                if (r_iter == r_end)
                {
                    std::copy(
                        std::make_move_iterator(l_iter),
                        std::make_move_iterator(l_end),
                        tmp_iter
                    );

                    break;
                }
            }
            //Функция copy переписывает входной контейнер временным tmp_array с начального итератора from
            std::copy(
                std::make_move_iterator(&tmp_array[0]),// tmp_array.get() Функция get возвращает ссылку на i-й элемент массива
                std::make_move_iterator(&tmp_array[n]),
                from
            );
        }
    }
}


