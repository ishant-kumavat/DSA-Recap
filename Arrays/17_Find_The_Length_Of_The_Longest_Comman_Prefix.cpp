// LeetCode 3043 => ** Find the Length of the Longest Common Prefix **

// 1). Optimal Solution => Using set Data Structure
//     Time Complexity : O((n + m) * d)
//     Space Complexity : O(n * d) 
//     where, d = maximum number of digits

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        int n = arr1.size();
        int m = arr2.size();
        for(int i = 0; i < n; i++){
            int x = arr1[i];
            while(x != 0){
                if(!st.count(x)) st.insert(x);
                x /= 10;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            int x = arr2[i]; 
            while(x != 0){
                if(st.count(x)){
                    string s = to_string(x);
                    ans = max(ans, (int)s.size());
                    break;
                }
                x /= 10;
            }
        }
        return ans;
    }
};

// Store every possible prefix of each number in arr1.
// For every number in arr2, keep removing the last digit
// until a matching prefix is found.
// Update the maximum prefix length.