// LeetCode 3115 => ** Maximum Prime Difference **

// 1). Brute Force Approach => Two Pointers + Prime Checking
//     Time Complexity : O(n * m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool isprime(int x){
        if(x <= 1) return false;

        for(int i = 2; i < x; i++){
            if(x % i == 0) return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;

        while(i <= j){
            if(isprime(nums[i]) && isprime(nums[j])) return (j - i);
            else if(isprime(nums[i])) j --;
            else if(isprime(nums[j])) i++;
            else {i++; j--;}
        }

        return -1;
    }
};