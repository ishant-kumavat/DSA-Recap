// 1). Optimal Solution =>
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestElement(vector<int>& nums) {
        int mxx=INT_MIN;
        for(int i=0;i<nums.size();i++) mxx=max(mxx,nums[i]);
        return mxx;
    }
};