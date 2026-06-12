// 1). Brute Force Approach => Using Nested Loops
//     Time Complexity : O(n^2) and TLE in Leetcode
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};

// 2). Optimal Solution I => Using Kadane's Algorithm.
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans=nums[0], sum=nums[0];
        for(int i=1;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<nums[i]){
                ans=max(ans,nums[i]);
                sum=nums[i];
            }
        }
        return ans;
    }
};

// 3). Optimal Solution II => Using Kadane's Algorithm.
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }
        return ans;
    }
};