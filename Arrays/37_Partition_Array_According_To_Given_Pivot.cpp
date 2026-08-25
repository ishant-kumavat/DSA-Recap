// LeetCode 2161 => ** Partition Array According to Given Pivot **

// Optimal Solution => Three-Pass Stable Partition
// Time Complexity : O(n)
// Space Complexity : O(n) => Output Array

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) ans.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == pivot) ans.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > pivot) ans.push_back(nums[i]);
        }
        return ans;
    }
};

// Traverse the array three times.
//
// 1. First traversal:
//    Store all elements smaller than pivot.
//
// 2. Second traversal:
//    Store all elements equal to pivot.
//
// 3. Third traversal:
//    Store all elements greater than pivot.
//
// Since we traverse the original array
// from left to right in each pass,
// the relative order of elements
// is preserved within each group.
//
// Finally, return the constructed array.