// LeetCode 3550 => ** Smallest Index With Digit Sum Equal to Index **

// Optimal Solution : Digit Extraction
// Time Complexity : O(n * log m)
// Space Complexity : O(1)
// where:
// n = number of elements
// m = maximum value in nums

#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i], sum = 0;
            while(x != 0){
                sum += (x % 10); x /= 10; 
            }
            if(sum == i) return i;
        }
        return -1;
    }
};

// For each index, calculate the digit sum
// of nums[i] using `% 10` and `/ 10`.
//
// If the digit sum is equal to the index,
// return that index.
//
// Since we check indices from left to right,
// the first valid index is the smallest one.