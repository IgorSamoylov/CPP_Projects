#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

array<int, 5> a { 1, 2, 3, 4, 5 };
int n = 5;

bool next_permutation() {
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            int min_val = a[i + 1], min_id = i + 1;
            for (int j = i + 2; j < n; j++) {
                if (a[j] > a[i] && a[j] < min_val) {
                    min_val = a[j];
                    min_id = j;
                }
            }
            swap(a[i], a[min_id]);
            sort(a.begin() + i + 1, a.end());
            return 1;
        }
    }
    return 0;
}

int main()
{   
    //reverse(a.begin(), a.end());
    while (next_permutation()) {
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << endl;
    }
}

