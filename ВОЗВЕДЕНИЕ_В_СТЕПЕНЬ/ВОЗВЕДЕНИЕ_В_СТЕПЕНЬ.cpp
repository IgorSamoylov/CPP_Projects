
#include <iostream>
using namespace std;

unsigned long long power(unsigned long long x, int n) {
    
    if (n == 0) return 1;
    //if (x * x >= UINT64_MAX) throw invalid_argument("Overloading of long long");

    if (n & 1) return x * power(x, n - 1);
    else return power(x * x, n >> 1); // Деление степени на 2 для четной степени сокращает сложность до log(n)

}

int main()
{
    int x, n;

    while (true) {
        cout << " Input x in power n " << endl; // 10 ^ 19 - max
        cin >> x >> n; if (x == -1) break;
        
        cout << power(x, n) << endl;
    }
}

