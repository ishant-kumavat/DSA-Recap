// LeetCode 189 => ** Rotate Array **

// 1). Brute Force Approach => One-Step Rotation
//     Time Complexity : O(n * k)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate_step(vector<int>& nums){
        for(int i = nums.size() - 1; i >= 1; i--){
            swap(nums[i], nums[i - 1]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        for(int i = 1; i <= k; i++){
            rotate_step(nums);
        }
    }
};
// Rotate the array one step at a time.
// Repeat the one-step rotation k times.

// 2). Better Approach => Using Extra Array
//     Time Complexity : O(n)
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        k %= n;
        int j = n - k;
        for(int i = j; i < n; i++){
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < j; i++){
            ans.push_back(nums[i]);
        }
        nums = ans;
    }
};
// Store the last k elements in a new array.
// Then append the first (n - k) elements.
// Copy the new array back to the original array.

// 3). Optimal Approach => Reversal Algorithm
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverse_portion(vector<int>& nums, int st, int ed){
        while(st < ed){
            swap(nums[st++], nums[ed--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse_portion(nums, 0, n - 1);
        reverse_portion(nums, 0, k - 1);
        reverse_portion(nums, k, n - 1);
    }
};
// Reverse the entire array.
// Reverse the first k elements.
// Reverse the remaining elements.
// The array becomes rotated by k positions.