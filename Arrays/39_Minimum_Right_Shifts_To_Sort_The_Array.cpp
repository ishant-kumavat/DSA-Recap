// LeetCode 2855 => ** Minimum Right Shifts to Sort the Array **

// 1). Brute Force Approach => 
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool IsArraySorted(vector<int>& nums){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
    void right_shift(vector<int>& nums){
        for(int i = nums.size() - 1; i > 0; i--){
            swap(nums[i], nums[i - 1]);
        }
    }
    int minimumRightShifts(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i <= nums.size() - 1; i++){
            bool flag = IsArraySorted(nums);
            if(flag) break;
            right_shift(nums);
            count ++;
        }
        return count;
    }
};

// 2). 