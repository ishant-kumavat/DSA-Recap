// LeetCode 1512 => ** Number of Good Pairs **

// 1). Brute Force Approach => Pair Comparison
//     Time Complexity : O(n ^ 2) 
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] == nums[j]) ans ++;
            }
        }
        return ans;
    }
};

// 2). Optimal Approach => Frequency Counting
//     Time Complexity : O(n) 
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0; 
        vector<int> freq(101, 0);
        for(auto it : nums) freq[it]++;
        for(auto it : freq){
            ans += (it * (it - 1)) / 2;
        }
        return ans;
    }
};

// Count the frequency of each number.
//
// If a number appears `k` times,
// the number of good pairs formed by it is:
//
// k * (k - 1) / 2
//
// Calculate this for every number
// and add all pairs to the answer.