#include "Header.h"

int main() {
    ifstream ifs("C:/Users/A12/Desktop/PYTHON/PROGRAMMS/largeUF.txt");
    int N;
    ifs >> N;
    //unique_ptr<UF> uf = make_unique<WeightedQuickUnionUF>(N);
    unique_ptr<UF> uf = make_unique<SimpleQuickUnion>(N);

    stringstream ss;
    ss << ifs.rdbuf();
    
    int p, q;
    while (ss >> p >> q) 
        uf->union_elem(p, q);
    
    cout << "Find components: " << uf->count_components() << endl;
}