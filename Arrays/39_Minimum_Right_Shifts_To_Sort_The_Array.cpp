// LeetCode 2855 => ** Minimum Right Shifts to Sort the Array **

// 1). Brute Force Approach => Repeated Right Shift + Sorting Check
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
            if(IsArraySorted(nums)) break;
            right_shift(nums);
            count ++;
        }
        return count;
    }
};

// 2). Optimal Solution => Find Breakpoint
//     Time Complexity : O(n)
//     Space Complexity : O(1)

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int breakpoint = -1;
        for(int i = 1; i < n; i++){
            if(nums[i - 1] > nums[i]){
                if(breakpoint == -1) breakpoint = i;
                count ++;
            }
        }
        if(count == 0) return 0;
        if(count >= 2 || nums[0] < nums[n - 1]) return -1;
        return (n - breakpoint);
    }
};

// Find the positions where the sorted order breaks.
//
// A sorted rotated array can have only one
// such breaking point.
//
// If there is no breaking point,
// the array is already sorted.
//
// If there are multiple breaking points,
// the array cannot be sorted by rotation.
//
// Also check the first and last elements
// to verify the circular ordering.
//
// If valid, the answer is the number of
// right shifts needed to bring the smallest
// element to the front.