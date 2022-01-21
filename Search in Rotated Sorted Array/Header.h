#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    vector<int> nums;
    int target;
    int length;
    int find_critical_point();
    int easySearch();
    int binary_search(int begin, int end);
public:
    int search(vector<int>& nums, int target);
};