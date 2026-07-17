// LeetCode 217 => ** Contains Duplicate **

// 1). Using Sorting
//     Time Complexity : O(n log n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};
// Sort the array.
// If any two adjacent elements are equal,
// a duplicate exists.

// 2). Using unordered_set
//     Time Complexity : O(n) // Average case   
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i = 0; i < n; i++){
            if(st.find(nums[i]) != st.end()) return true;
            st.insert(nums[i]);
        }   
        return false;
    }
};
// Traverse the array once.
// Store each element in a hash set.
// If an element already exists in the set,
// a duplicate is found.