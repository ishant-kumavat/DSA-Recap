// LeetCode 1636 => ** Sort Array by Increasing Frequency **

// Using unordered_map and STL sort
// Time Complexity : O(n log n)   // Worst case
// Space Complexity : O(n)        // Worst case
// where k = number of distinct elements
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        for(int i = 0; i < n; i++) mpp[nums[i]]++;
        vector<pair<int, int>>vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        int j = n - 1;
        for(auto it : vec){
            for(int i = 0; i < it.second; i++){
                nums[j] = it.first;
                j--;
            }
        }
        return nums;
    }
};
// Count the frequency of each element.
// Sort elements by decreasing frequency.
// If frequencies are equal, sort by increasing value.
// Fill the answer from the end,
// so the final array has increasing frequency and,
// for equal frequencies, decreasing values.