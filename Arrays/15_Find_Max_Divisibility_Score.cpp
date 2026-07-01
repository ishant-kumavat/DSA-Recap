// LeetCode 2644 => ** Find the Maximum Divisibility Score **

// 1). Solution :
//     Time Complexity : O(n * m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int m = nums.size();
        int n = divisors.size();
        int ans = INT_MAX, count = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < m; j++){
                if((nums[j] % divisors[i]) == 0) cnt ++;
            }
            if(cnt == count) ans = min(ans, divisors[i]);
            else if(cnt > count){
                count = cnt; 
                ans = divisors[i];
            }
        }
        return ans;
    }
};

// Traverse every divisor and count how many elements of nums
// are divisible by it.
// Keep track of the maximum count.
// If multiple divisors have the same score,
// choose the smaller divisor.