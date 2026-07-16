// LeetCode 2149 => ** Rearrange Array Elements by Sign **

// 1). Brute Force Approach => Separate Positive & Negative Arrays
//     Time Complexity : O(n)
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pos_ele;
        vector<int>neg_ele;
        for(auto it : nums){
            if(it > 0) pos_ele.push_back(it);
            else neg_ele.push_back(it);
        }
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) nums[i] = pos_ele[i / 2];
            else nums[i] = neg_ele[i / 2];
        }
        return nums;
    }
};
// Store all positive and negative numbers separately.
// Fill the original array alternately
// using the positive and negative arrays.

// 2). Optimal Approach => Direct Index Placement
//     Time Complexity : O(n)
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int pos = 0, neg = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};
// Traverse the array once.
// Place positive numbers at even indices
// and negative numbers at odd indices
// using two separate pointers.
// This preserves the relative order
// of positive and negative elements.