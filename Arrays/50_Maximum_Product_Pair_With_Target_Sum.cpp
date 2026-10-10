// LeetCode Biweekly Contest 193 problem => ** Maximum Product Pair With Target Sum **

// Optimal Solution => Hash Map
// Time Complexity : O(n) average
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> ans(2, -1);
        long long product = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            int x = target - nums[i];
            if(mpp.find(x) != mpp.end()) {
                long long currProduct = 1LL * x * nums[i];
                if(x != nums[i] && product < currProduct) {
                    if(nums[i] > x) {ans[0] = i; ans[1] = mpp[x];}
                    else {ans[0] = mpp[x]; ans[1] = i;}
                    product = currProduct;
                }
            }
            mpp[nums[i]] = i;
        }
        
        return ans;
    }
};

// Store each number and its index in a hash map.
//
// For each element nums[i]:
// - Calculate the complement: target - nums[i].
// - Check whether the complement exists in the map.
// - If found, calculate the product of both numbers.
// - Update the answer if the product is greater
//   than the previously found maximum product.
//
// Store the current number and its index in the map.
//
// Return {-1, -1} if no valid pair is found.