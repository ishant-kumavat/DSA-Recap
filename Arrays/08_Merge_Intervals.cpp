// LeetCode 56 => ** Merge Intervals **

// 1). Alternative Merging Method => 
//     Time Complexity : O(n log n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if(n==1) return {{intervals[0][0],intervals[0][1]}};
        vector<vector<int>> arr;
        int k = -1;
        for(int i = 0; i < n; i++){
             if(arr.size() == 0 && (i + 1) < n){
                if(intervals[i][1] >= intervals[i+1][0]){
                    arr.push_back({intervals[i][0],max(intervals[i+1][1], intervals[i][1])});
                    k++;
                    continue;
                } 
                else {
                    arr.push_back({intervals[i][0],intervals[i][1]});
                    arr.push_back({intervals[i+1][0],intervals[i+1][1]});
                    k+=2;
                    continue;
                }
            }
            else{
                if(intervals[i][0] <= arr[k][1]){
                    arr[k][1] = max (intervals[i][1], arr[k][1]);
                    continue;
                }
                else{
                    arr.push_back({intervals[i][0], intervals[i][1]});
                    k++;
                    continue;
                }
            }
        }
        return arr;
    }
};

// 2). Optimal Approach => 
//     Time Complexity : O(n log n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        int k = 0;
        for(int i = 1; i < n; i++){
            if(ans[k][1] >= intervals[i][0]){
                ans[k][1] = max(ans[k][1], intervals[i][1]);
            }
            else{
                ans.push_back({intervals[i][0], intervals[i][1]});
                k++;
            }
        }
        return ans;
    }
};

// Here We are also use ans.back()[1] to access ans 2D vector element 
// instead of using extra varaible for index trash.