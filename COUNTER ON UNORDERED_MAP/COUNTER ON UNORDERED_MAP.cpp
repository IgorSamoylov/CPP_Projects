

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> word_vector{"trtt","trtr", "rrr", "rrr", "yyyy", "x", "x", "i", "x"};
    unordered_map<string, int> word_count;

    for (string word : word_vector) 
        word_count[word]++;

    for_each(word_count.begin(), word_count.end(),
        [](pair<string, int> pair) {cout << pair.first << "  " << pair.second << endl; });
}

