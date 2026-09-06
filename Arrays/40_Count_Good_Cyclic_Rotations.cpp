// LeetCode 4044 => ** Count Good Cyclic Rotations **

// 1). Brute Force Approach => Simulation + Running Sum
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void leftshift(vector<int>& nums){
        for(int i = 0; i < nums.size() - 1; i++){
            swap(nums[i], nums[i + 1]);
        }
    }
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size(); 
        int count = 0;
        long long x = 0, y = 0, a = nums[0], b = nums[n / 2];
        for(int i = 0; i < n; i++){
            if(i < n / 2) x += nums[i];
            else y += nums[i];
        }
        if(x > y) count ++;
        for(int i = 0; i < n - 1; i++){
            leftshift(nums);
            x = x - a + b;
            y = y - b + a;
            if(x > y) count ++;
            a = nums[0];
            b = nums[n / 2];
        }
        return count;
    }
};

// 2). Optimal Approach =>  Running Sum + Index Tracking
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size(); 
        int count = 0;
        long long x = 0, y = 0, a = nums[0], b = nums[n / 2];
        int p = 0, q = n / 2;
        for(int i = 0; i < n; i++){
            if(i < n / 2) x += nums[i];
            else y += nums[i];
        }
        if(x > y) count ++;
        for(int i = 0; i < n - 1; i++){
            x = x - a + b;
            y = y - b + a;
            if(x > y) count ++;
            p++; q++;
            if(q == n) q = 0;
            a = nums[p];
            b = nums[q];
        }
        return count;
    }
};

// Optimal Idea:
//
// Instead of physically rotating the array,
// maintain the two running sums.
//
// After each rotation, only two elements
// change their groups, so update both sums
// in O(1) time.
//
// Use cyclic indices `p` and `q` to track
// the required elements without modifying
// the original array.
//
// Check `x > y` after every rotation and
// count the good rotations.