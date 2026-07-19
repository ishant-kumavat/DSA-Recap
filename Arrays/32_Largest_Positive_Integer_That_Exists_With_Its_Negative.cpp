// LeetCode 2441 => ** Largest Positive Integer That Exists With Its Negative **

// 1). Brute Force Approach => Using Sorting + Two Pointer
//     Time Complexity : O(n log n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int idx = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                idx = i;break;
            }
        }
        if(idx == -1) return -1;
        int i = idx - 1, j = idx, ans = -1;
        while(i >= 0 && j < n){
            if(-nums[i] == nums[j]){
                ans = max(ans, nums[j++]); i--;
            }
            else if(-nums[i] > nums[j]) j++;
            else i--;
        }
        return ans;
    }
};
// Sort the array.
// Use two pointers:
// one for negative numbers
// and one for positive numbers.
// Move the pointers to find
// pairs like (-x, x).
// Keep track of the largest
// positive value found.

// 2). Optimal Approach =>  Using Unordered Set (2 Passes)
//     Time Complexity : O(n)
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(auto it : nums) st.insert(it);
        int ans = -1;
        for(auto it : st){
            if(st.find(-it) != st.end()){ 
                ans = max(ans, -it);
                if(it < 0) ans = max(ans, -it);
                else ans = max(ans, it);
            }
        }
        return ans;
    }
};
// Insert all elements into a hash set.
// Traverse the set and check
// whether the negative of
// the current element exists.
// Update the answer with
// the largest positive value.

// 3). Optimal Approach => Using Unordered Set + 1 Loop
//     Time Complexity : O(n)
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int>st;
        for(auto it : nums){
            st.insert(it);
            if(st.find(-it) != st.end()) 
                ans = max(ans, max(it, -it));
        }
        return ans;
    }
};
// Traverse the array once.
// Insert each element into a hash set.
// If its negative already exists,
// update the answer with the
// largest positive value.