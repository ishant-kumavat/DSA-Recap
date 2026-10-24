// LeetCode 4088 => ** Difference Between Peaks and Valleys **

// Optimal Solution => Single Traversal
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peak = 0;
        int valley = 0;
        int n = nums.size();
        for(int i = 1; i < n - 1; i++){
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) peak += nums[i];
            if(nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) valley += nums[i];
        }
        return (peak - valley); 
    }
};

// Traverse the array from index 1 to n-2,
// because the first and last elements cannot be peaks or valleys.
//
// Peak: Current element is greater than both neighbours.
// Valley: Current element is smaller than both neighbours.
//
// Add peak values to `peak` and valley values to `valley`.
//
// Return the difference between the total peak and valley values.