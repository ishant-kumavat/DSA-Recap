// LeetCode 31 => ** Next Permutation **

// Optimal Solution => Pivot + Reverse
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        for(int i = n - 1; i >= 1; i--){
            if(nums[i] > nums[i - 1]){
                pivot = i - 1;
                break;
            }
        }
        if(pivot == -1) return reverse(nums.begin(), nums.end());
        for(int i = n - 1; i > pivot; i--){
            if(nums[pivot] < nums[i]){
                swap(nums[pivot], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
// Find the first index (pivot) from the right
// such that nums[pivot] < nums[pivot + 1].
// If no such index exists,
// the current permutation is the largest,
// so reverse the entire array.
// Otherwise, swap the pivot with the
// next greater element on its right.
// Finally, reverse the suffix
// to get the next lexicographical permutation.