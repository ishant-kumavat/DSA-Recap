// LeetCode 3678 => ** Smallest Absent Positive Greater Than Average **

// Approach 1 => Sorting + Linear Search
// Time Complexity : O(n log n)
// Space Complexity :O(log n) auxiliary space typically for std::sort() recursion stack.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        sort(nums.begin(), nums.end());

        for(auto &it : nums)
            sum += it;

        int ans = max(1, sum / n + 1);

        for(auto &it : nums){
            if(it == ans) ans ++;
            else if(it > ans) break;
        }

        return ans;
    }
};

// Approach 2 => Hash Set
// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0;
        int n = nums.size();

        for(int num : nums) {
            sum += num;
            st.insert(num);
        }

        int ans = max(1, sum / n + 1);

        while(st.count(ans)) {
            ans++;
        }

        return ans;
    }
};

// Use an unordered_set to store all array elements
// and calculate their sum.
//
// Calculate the average and find the smallest positive
// integer greater than the average.
//
// Check whether the answer exists in the set.
// If it exists, increment the answer and check again.
//
// Return the first positive integer that is absent.