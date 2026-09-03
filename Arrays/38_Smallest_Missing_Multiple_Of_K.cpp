// LeetCode 3718 => ** Smallest Missing Multiple of K **

// Optimal Solution => Hash Set + Multiple Checking
// Time Complexity : O(n) average
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i = 1;
        while(st.count(k * i)) i++;
        return (k * i);
    }
};

// Store all elements of nums in an unordered_set
// for O(1) average-time lookup.
//
// Check multiples of k starting from k.
//
// If k is present, check 2k,
// then 3k, 4k and so on.
//
// The first multiple of k that is not
// present in the set is the answer.