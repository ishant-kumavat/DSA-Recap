// LeetCode 905 => ** Sort Array By Parity **

// 1). Brute Force Approach =>
// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;

        for(int it : nums) if(it % 2 == 0) ans.push_back(it);

        for(int it : nums) if(it % 2 != 0) ans.push_back(it);
    
        return ans;
    }
};