
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    
    int n;
    cin >> n; // Ввод количества элементов
    vector<int> my_vector(n); // Создание вектора с заданной емкостью

    // наполнение вектора
    for (int i = 0; i < n; i++) {
        cin >> my_vector[i];
    }
    // чтение вектора
    for (int i = n - 1; i >= 0; i--) {
        cout << my_vector[i] << " ";
    }
    
  

}

