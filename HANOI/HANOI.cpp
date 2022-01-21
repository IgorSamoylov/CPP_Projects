
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int TOWER_SIZE = 8;

vector<int> tower1(TOWER_SIZE);
vector<int> tower2;
vector<int> tower3;
vector<vector<int>> vectors{ tower1, tower2, tower3 };

void move_disk(vector<int>& whereTower, vector<int>& toTower) {
    int disk = *whereTower.begin();
    cout << "Move disk " << disk << endl;
    whereTower.erase(whereTower.begin());
    toTower.insert(toTower.begin(), disk);
}

void print_towers() {
    for (int i = 1; i < vectors.size() ;  ++i ) {
        cout << "------------------------------------" << endl;
        //cout << "Tower #" << i << endl;
        for_each(vector.begin(), vector.end(), [](int n) {cout << n << " "; });
        cout << endl << "------------------------------------" << endl;
    }
}

void hanoi(int n, int i, int k) {
    print_towers();
    if (n == 1) {
        cout << "Move disk from #" << i << " to " << k << endl;
        move_disk(vectors[i], vectors[k]);
    }
    else {
        int tmp = 3 - i - k;
        hanoi(n - 1, i, tmp);
        cout << "Move last disk from #" << i << " to " << k << endl;
        move_disk(vectors[i], vectors[k]);
        hanoi(n - 1, tmp, k);
    }

}

int main()
{
	 iota(tower1.begin(), tower1.end(), 1);  
	hanoi(TOWER_SIZE, 0, 1);
    	print_towers();
}

