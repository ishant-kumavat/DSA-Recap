// LeetCode 1351 => ** Count Negative Numbers in a Sorted Matrix **

// 1). Brute Force Approach => 
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] < 0) count ++;
            }
        }
        return count;
    }
};

// 2). Better Approach => 
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++){
            int low = 0, high = m - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(grid[i][mid] < 0) high = mid - 1;
                else low = mid + 1;
            }
            count += (m - low);
        }
        return count;
    }
};

// 3). Optimal Approach => 
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;