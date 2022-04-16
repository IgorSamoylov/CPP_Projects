
#include <iostream>
#include <ranges>
#include <typeinfo>

using namespace std;

int main() {

    //auto const int_array = { 0, 1, 2, 3, 4, 5, 6 };
    ranges::iota_view<int, int> ints = views::iota(0, 6);
    auto even = [](int n) {if (n % 2 == 0) return n; };
    auto square = [](int n) { return n * n; };

    cout << typeid(ints).name() << endl;
    for (int i : ints | views::filter(even)| views::transform(square))
        cout << i << endl;
}

