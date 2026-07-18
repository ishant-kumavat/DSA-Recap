// LeetCode 2433 => ** Find The Original Array of Prefix Xor **

// Approach 1 => Running Prefix XOR
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n, 0);
        ans[0] = pref[0];
        int xr = pref[0]; 
        for(int i = 1; i < n; i++){
            ans[i] = xr ^ pref[i];
            xr ^= ans[i];
        }
        return ans;
    }
};
// The first element remains unchanged.
// Maintain the XOR of the original array
// seen so far.
// XOR it with the current prefix XOR
// to recover the next original element.

// Approach 2 => Prefix XOR Property
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int>ans(n, 0);
        ans[0] = pref[0];
        for(int i = 1; i < n; i++){
            ans[i] = pref[i] ^ pref[i - 1];
        }
        return ans;
    }
};
// The first element is the same
// as the first prefix XOR.
// Every next element equals
// pref[i] XOR pref[i - 1],
// because common prefix values cancel out.