#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans=nums[0];
        int sum=nums[0];
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