// LeetCode 3683 => ** Earliest Time to Finish One Task **

// 1). Optimal Solution => Minimum Completion Time
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX;
        int n = tasks.size();
        for(int i = 0; i < n; i++){
            int sum = tasks[i][0] + tasks[i][1];
            ans = min(ans, sum);
        }
        return ans;
    }
};

// For each task, calculate its completion time
// using:
//
// start time + duration
//
// Keep track of the minimum completion time.
//
// Return the earliest time at which
// any task can be finished.