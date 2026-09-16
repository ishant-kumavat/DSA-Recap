// LeetCode 57 => ** Insert Interval **

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int idx = 0;
        for(int i = 1; i < n; i++){
            if(intervals[idx][1] < intervals[i][0]){
                idx++;
                intervals[idx] = intervals[i];
            }
            else{
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
            }
        }

        intervals.resize(idx + 1);
        return intervals;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        intervals = merge(intervals);
        return intervals;
    }
};