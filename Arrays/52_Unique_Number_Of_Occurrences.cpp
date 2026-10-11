// LeetCode 1207 => ** Unique Number of Occurrences **

// Approach => Hash Map + Hash Set
// Time Complexity : O(n) average
// Space Complexity : O(n)         

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(auto &it : arr) mpp[it] ++;
        
        unordered_set<int> st;
        for(auto &it : mpp){
            int x = it.second;
            if(st.count(x)) return false;
            st.insert(x);
        }
        
        return true;
    }
};

// Count the frequency of each element using a hash map.
//
// Store each frequency in a hash set.
// If a frequency already exists in the set,
// two elements have the same occurrence count,
// so return false.
//
// If all frequencies are unique, return true.