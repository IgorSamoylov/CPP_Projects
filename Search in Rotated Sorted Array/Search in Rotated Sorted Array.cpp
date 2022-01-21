#include "Header.h"


int main()
{
    
    vector<int> nums { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;
    Solution solution;

    //for_each(nums.begin(), nums.end(), [](int n) {cout << n << endl; });

    cout << solution.search(nums, target) << endl;

    
    nums = { 8, 9, 10, 11, 12, 13, 14, 0, 1, 2, 3, 4, 5, 6, 7 };

    //for_each(nums.begin(), nums.end(), [](int n) {cout << n << endl; });

    cout << solution.search(nums, target) << endl;
    
    nums = { 3, 1, 2 };
    cout << solution.search(nums, target) << endl;

    nums = { 1 };
    target = 1;
    cout << solution.search(nums, target) << endl;

    nums = { 4, 5, 6, 7, 0, 1, 2 };
    target = 2;
    cout << solution.search(nums, target) << endl;

    nums = { 4, 5, 6, 7, 0, 1, 2 };
    target = 5;
    cout << solution.search(nums, target) << endl;

    nums = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
    target = 1;
    cout << solution.search(nums, target) << endl;

    nums = { 2, 3, 4, 5, 6, 7, 8, 9, 1 };
    target = 3;
    cout << solution.search(nums, target) << endl;

    nums = { 5, 6, 7, 8, 9, 1, 2, 3, 4 };
    target = 2;
    cout << solution.search(nums, target) << endl;

    nums = { 1, 3, 5};
    target = 0;
    cout << solution.search(nums, target) << endl;

    nums = { 7, 8, 1, 2, 3, 4, 5, 6 };
    target = 2;
    cout << solution.search(nums, target) << endl;

    nums = { 8, 1, 2, 3, 4, 5, 6, 7 };
    target = 6;
    cout << solution.search(nums, target) << endl;

    nums = { 9, 1, 2, 3, 4 };
    target = 5;
    cout << solution.search(nums, target) << endl;

    nums = { 4, 5, 6, 7, 8, 1, 2, 3 };
    target = 8;
    cout << solution.search(nums, target) << endl;

    nums = { 9, 1, 2, 3, 4, 5, 6, 7, 8 };
    target = 5;
    cout << solution.search(nums, target) << endl;

    nums = { 0, 1, 3, 4, 6, 8, 9 };
    target = 5;
    cout << solution.search(nums, target) << endl;

    nums = { 1, 2, 3, 4, 5, 6 };
    target = 4;
    cout << solution.search(nums, target) << endl;

    nums = { 4, 5, 6, 7, 0, 1, 2 };
    target = 6;
    cout << solution.search(nums, target) << endl;

    nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    target = 3;
    cout << solution.search(nums, target) << endl;
}
