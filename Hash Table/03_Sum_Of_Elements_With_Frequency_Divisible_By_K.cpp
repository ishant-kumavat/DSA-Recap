// LeetCode 3712 => ** Sum of Elements With Frequency Divisible by K **

// Approach 1
// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        if(n == 0) return 0;
        unordered_map<int, int> mpp;

        for(int &it : nums) mpp[it] ++;

        for(auto &it : mpp){
            if(it.second % k == 0) ans += (it.first * it.second);
        }

        return ans;
    }
};

// Approach 2
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        if(n == 0) return 0;
        vector<int> hasharr(101, 0);

        for(int &it : nums) hasharr[it] ++;

        for(int i = 1; i <= 100; i++){
            if(hasharr[i] % k == 0) ans += (hasharr[i] * i);
        }

        return ans;
    }
};

// Use a frequency array to count occurrences of each element.
//
// Traverse the frequency array.
// If an element's frequency is divisible by k,
// add (element * frequency) to the answer.
//
// Return the total sum.
//
// Time Complexity : O(n + 100) = O(n)
// Space Complexity : O(1)