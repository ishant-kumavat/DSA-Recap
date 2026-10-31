// LeetCode 674 => ** Longest Continuous Increasing Subsequence **

// Optimal Solution => 
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1, ans = 1;
        
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]) cnt ++;
            if(cnt != 1 && nums[i] <= nums[i - 1]){
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};

// Traverse the array and maintain the length of the
// current continuous increasing subsequence.
//
// If the current element is greater than the previous
// element, increment the count.
// Otherwise, reset the count to 1.
//
// Update the maximum length at every step.
//
// Return the maximum length.