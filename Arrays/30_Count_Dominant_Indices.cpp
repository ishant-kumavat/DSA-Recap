// LeetCode 3833 => ** Count Dominant Indices **

// 1). Brute Force Approach => Using Nested Loops
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n - 1; i++){
            int sum = 0;
            for(int j = i + 1; j < n; j++){
                sum += nums[j]; 
            }
            if(nums[i] > (sum /( n - i - 1))) cnt++;
        }
        return cnt;
    }
}; 
// For every index,
// calculate the average of all elements
// to its right using a nested loop.
// Count the index if its value
// is greater than that average.

// 2). Optimal Approach => Prefix Removal + Running Sum
//     Time Complexity : O(n)
//     Space Complexity : O(1)
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        for(int i = 0; i < n - 1; i++){
            sum -= nums[i];
            int avg = sum / (n - i - 1);
            if(nums[i] > avg) cnt++;
        }
        return cnt;
    }
};
// Compute the total sum of the array.
// For each index,
// subtract the current element from the running sum.
// The remaining sum is the sum
// of all elements to the right.
// Calculate their average and
// count the index if it is dominant.