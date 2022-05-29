#include <iostream>
#include <ranges>

using namespace std;

int main()
{
    //auto evens = [](int n) { return 0 == n % 2; };
    auto evens = [](int n) { 
      bool result = (n % 2 == 0)? true : false;
      return result;
    };

    for (int i : views::iota(10, 20) | views::filter(evens))
        cout << i << " ";

    return 0;
}
