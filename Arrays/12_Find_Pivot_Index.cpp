// LeetCode 724 => ** Find Pivot Index **

// 1). Using Extra Space
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>preSum (n, 0);
        vector<int>sufSum (n, 0);
        for(int i = 1; i < n; i++){
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        for(int i = n - 2; i >= 0; i--){
            sufSum[i] = sufSum[i + 1] + nums[i + 1];
        }
        for(int i = 0; i < n; i++){
            if(preSum[i] == sufSum[i]) return i;
        }
        return -1;
    }
};

// 2). Optimized Prefix Sum
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int totalSum = 0;
        for(int i = 0; i < n; i++) totalSum += nums[i];
        for(int i = 0; i < n; i++){
            int right = totalSum - left - nums[i];
            if(left == right) return i;
            left += nums[i];
        }    
        return -1;
    }
};

// Formula => preSum[i] + sufSum[i] + nums[i] = totalSum;  