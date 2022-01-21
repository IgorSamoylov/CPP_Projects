#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    float D = b * b - 4 * a * c;
    if (D > 0) {
        float x1 = (-b + sqrt(D)) / (2 * a);
        float x2 = (-b - sqrt(D)) / (2 * a);
        if (x1 > x2) {
            swap(x1, x2);
        }
        cout << x1 << " " << x2;
    }
    if (D == 0) {
        float x1 = -b / (2 * a);
        cout << x1;
    }

    return 0;
}