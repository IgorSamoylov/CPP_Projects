#include "3SUM CLOSEST.h"


int main()
{
    vector<int> test1{ 11, -76, 899, 4, -666 };
    vector<int> test2{ 1, 1, 1, 0, 0 };

    Solution2 solution;

    //int result = solution.threeSumClosest(test1, 100);
    //assert(result == 157);

    int result = solution.threeSumClosest(test1, 100);
    //assert(result == 3);
    
    cout << result;
}


int Solution::threeSumClosest(vector<int>& nums, int target) {

        bool first = true;
        int current_nearest = fabs(nums[0] + nums[1] + nums[2] - target);
        cout << current_nearest << endl;
        int m, n, p;

        auto check3Sum = [&](int i, int k, int l) {
            int sum = nums[i] + nums[k] + nums[l];
            cout << nums[i] << " " << nums[k] << " " << nums[l] << " " << fabs(sum - target) << " " << current_nearest <<  endl;
            if (fabs(sum - target) < current_nearest) {
                current_nearest = fabs(sum - target);
                first = false;
                m = i; n = k; p = l;
                
            }
        };

        size_t nums_size = nums.size();

        for (size_t i = 0; i < nums_size - 2; ++i) {
            for (size_t k = i + 1; k < nums_size - 1; ++k) {
                for (size_t l = k + 1; l < nums_size; ++l) {
                    check3Sum(i, k, l);
                }
            }
        }
        if (first) return nums[0] + nums[1] + nums[2];
        
        return nums[m] + nums[n] + nums[p];
 }


int Solution2::threeSumClosest(vector<int>& nums, int target) {

        int m, n, p, current_nearest = INT_MAX, sum, output_sum = 0, sumAbs;
        int nums_size = nums.size();
        //if (nums_size == 3) return nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < nums_size - 2; ++i) {
            for (int k = i + 1; k < nums_size - 1; ++k) {
                for (int l = k + 1; l < nums_size; ++l) {

                    sum = nums[i] + nums[k] + nums[l];
                    sumAbs = abs(sum - target);
                    if (sumAbs == 0) return sum;
                    
                    if (sumAbs < current_nearest) {
                        current_nearest = sumAbs;
                        output_sum = sum;
                    }
                }
            }
        }
        return output_sum;
    }

int Solution3::threeSumClosest(vector<int>& nums, int target) {

        bool first = true;
        int m, n, p, current_nearest, sum, output_sum = 0, sumAbs;
        int nums_size = nums.size();
        if (nums_size == 3) return nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        int nums_center;
        if (nums_size % 2 == 0)  nums_center = nums_size / 2 + 1;
        else nums_center = nums_size / 2;
        
        
        for (int i = 0; i < nums_center; ++i) {
            for (int k = nums_size - 1; k > nums_center + 1; --k) {
                for (int l = i + 1; l < k - 1; ++l) {

                    sum = nums[i] + nums[k] + nums[l];
                    sumAbs = abs(sum - target);
                    if (sumAbs == 0) return sum;
                    if (first) {
                        current_nearest = sumAbs; output_sum = sum; first = false;                                   continue;
                    }

                    if (sumAbs < current_nearest) {
                        current_nearest = sumAbs;
                        first = false;
                        output_sum = sum;
                    }
                }
            }
        }
        return output_sum;
    }



