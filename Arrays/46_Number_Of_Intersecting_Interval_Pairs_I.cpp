// LeetCode 4056 => ** Number of Intersecting Interval Pairs I **

// 1). Better Solution => Sorting + Pair Comparison
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(intervals[i][1] >= intervals[j][0]) ans ++;
                else break;
            }
        }
        return ans;
    }
};

// 2). Optimal Solution => Binary Indexed Tree
//     Time Complexity : O(n log n)
//     Space Complexity : O(M), where M coordinate/value range