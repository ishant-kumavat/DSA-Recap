// LeetCode 53 => ** Maximum Subarray **

// 1). Brute Force Approach => Using Nested Loops
//     Time Complexity : O(n^2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n ==1 ) return nums[0];
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

// 2). Kadane's Algorithm (Standard)
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int ans = nums[0], sum = nums[0];
        for(int i = 1; i < n; i++){
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < nums[i]){
                ans = max(ans, nums[i]);
                sum = nums[i];
            }
        }
        return ans;
    }
};

// 3). Kadane's Algorithm (Classic Reset-to-Zero)
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};
// Reset the current sum whenever it becomes negative,
// because a negative prefix can never increase the maximum subarray sum.

// 4). Kadane's Algorithm (With Index Tracking)
// Kadane's Algorithm with index tracking.
// Returns the starting and ending indices of the maximum sum subarray.
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, mx = INT_MIN;
        int temp_idx = 0, st_idx = -1, ed_idx = -1;
        for(int i = 0; i < n; i++){
            if(sum == 0) temp_idx = i;
            sum += nums[i];
            if(mx < sum){
                mx = sum;
                st_idx = temp_idx;
                ed_idx = i;
            }
            if(sum < 0) sum = 0;
        }
        return {st_idx, ed_idx};
    }
};
// temp_idx stores the possible starting index of the current subarray.
// Whenever a larger sum is found,
// update the starting and ending indices.
