// LeetCode 3925 => ** Concatenate Array With Reverse **

// Optimal Solution => Append Reverse
// Time Complexity : O(n)
// Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
// Store the original size of the array.
// Traverse the original array
// from last to first.
// Append each element
// to the end of the array.
// The final array contains
// the original array
// followed by its reverse.