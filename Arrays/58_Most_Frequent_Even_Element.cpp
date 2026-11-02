// LeetCode 2404 => ** Most Frequent Even Element **

// Optimal Solution => Hash Map (Frequency Counting)
// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mpp;
        
        for(auto &it : nums) mpp[it] ++;

        int ans = -1, me = -1;

        for(auto &it : mpp){
            if(it.first % 2 == 0 && it.second > me) {
                me = it.second;
                ans = it.first;
            }
            if(it.first % 2 == 0 && it.second == me && it.first < ans) ans = it.first;
        }

        return ans;
    }
};

// Use an unordered_map to store the frequency of each element.
//
// Traverse the map and consider only even numbers.
//
// If an even number has a higher frequency, update the answer.
// If frequencies are equal, choose the smaller even number.
//
// If no even number exists, return -1.