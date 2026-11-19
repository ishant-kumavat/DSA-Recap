// LeetCode 1748 => ** Sum of Unique Elements **

// 1). Brute Force Approach => Nested Loops
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] == nums[j]) cnt ++;
                if(cnt > 1) break;
            }
            if(cnt == 1) ans += nums[i];
        }

        return ans;
    }
};

// 2). Better Approach => Hash Map
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mpp;

        for(auto it : nums) mpp[it]++;

        for(auto it : mpp){
            if(it.second == 1) ans += it.first;
        }

        return ans;
    }
};

// 3). Optimal Approach => Frequency Array
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        vector<int> hasharr(101, 0);

        for(auto it : nums) hasharr[it]++;

        for(int i = 1; i <= 100; i++){
            if(hasharr[i] == 1) ans += i;
        }

        return ans;
    }
};

// Use a frequency array to count occurrences of each element.
//
// Traverse the input array and update the frequency
// of every element.
//
// Traverse the frequency array.
// If an element occurs exactly once, add it to the answer.
//
// Return the sum of all unique elements.
//
// Time Complexity : O(n + 100) = O(n)
// Space Complexity : O(1)