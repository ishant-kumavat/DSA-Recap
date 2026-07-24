// LeetCode 229 => ** Majority Element II **

// 1). Brute Force Approach => Using Unordered Set and Nested Loops
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]) cnt++;
            }
            if(cnt > n / 3) st.insert(nums[i]);
        }
        vector<int>ans(st.begin(), st.end());
        return ans;
    }
};

// 2). Better Approach => Using Unordered Map 
//     Time Complexity : O(n)
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        vector<int>ans;
        for(auto it : mpp){
            if(it.second > n / 3) ans.push_back(it.first); 
        }
        return ans;
    }
};