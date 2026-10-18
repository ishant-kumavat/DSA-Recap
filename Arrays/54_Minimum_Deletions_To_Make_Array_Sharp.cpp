// LeetCode 4083 => ** Minimum Deletions to Make Array Sharp **

// Optimal Solution => 
// Time Complexity : O(n)
// Space Complexity : O(1) Auxiliary

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = i + 1;
        int ans = 0;
        while(j < n){
            if(nums[i] == nums[j]) ans ++;
            else i = j;
            j++;
        }
        return ans;
    }
};

// Adjacent elements have XOR equal to zero
// only when both elements are equal.
//
// Use two pointers:
// - `i` points to the last kept element.
// - `j` checks the next element.
//
// If nums[i] == nums[j], delete the current element
// by increasing the deletion count.
//
// Otherwise, keep the current element
// and move `i` to `j`.
//
// Return the total number of deletions.