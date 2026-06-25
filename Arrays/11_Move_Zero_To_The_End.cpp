// LeetCode 283 => ** Move Zeroes **

// 1). Better Approach => Using extra Space
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        vector<int>ans;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) cnt++;
            else ans.push_back(nums[i]);
        }
        for(int i = 0; i < cnt; i++) ans.push_back(0);
        nums = ans;
    }
};

// 2). Optimal Approach => 2 pointer Approach 
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0, idx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) count++;
            else{
                swap(nums[idx], nums[i]);
                idx++;
            }
        }
    }
};

// idx points to the position where next non-zero
// element should be placed.