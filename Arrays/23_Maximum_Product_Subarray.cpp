// LeetCode 152 => ** Maximum Product Subarray **

// 1). Brute Force Approach => Using Nested Loop
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int mul = 1;
            if(nums[i] > mx) mx = nums[i];
            for(int j = i ;j < nums.size(); j++){
                mul *= nums[j];
                mx = max(mx, mul);
            }
        }
        return mx;
    }
};

// 2). Optimal Solution => Prefix Product + Suffix Product
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int pre = 1, suf = 1;
        for(int i = 0; i < n; i++){
            if(pre == 0) pre = nums[i];
            if(suf == 0) suf = nums[n - i - 1];
            pre *= nums[i];
            suf *= nums[n - i - 1];
            ans = max(ans, max(pre, suf));
        }
        return ans;
    }
};
// Compute prefix and suffix products simultaneously.
// Reset the product after encountering 0.
// The maximum product subarray is obtained
// from either the prefix or the suffix traversal.