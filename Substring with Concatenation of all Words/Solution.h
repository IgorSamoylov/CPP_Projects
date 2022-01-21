#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string_view>
#include <unordered_set>
#include <cmath>
#include <unordered_map>

using namespace std;



class Solution {
public:
    
    vector<int> findSubstring(string s, vector<string>& words);
};

class Solution0 {
public:

    vector<int> findSubstring(string s, vector<string>& words);
    bool checkAll(string s, vector<string> words, size_t deepth);
};

class SolutionBest {
public:
    vector<int> findSubstring(string s, vector<string>& words);
};