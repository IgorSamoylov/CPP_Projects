
#include <compare>
using namespace std;

import <iostream>;

class Pidoras {
public:
    double* n;
    Pidoras(double* n_ptr) : n(n_ptr) {}
    
    auto operator <=> (const Pidoras&) const = default;
    
};

int main() {

    double a0[] {1.0, 2.23, 5.56};
    Pidoras a(a0);
    
    double b0[] { 1.1, 2.24, 5.56};
    Pidoras b(b0);

    cout << (a < b) << " " << (a  > b) << (a == b) << (a != b) << (a <= b) << (a >= b) << endl;
}
