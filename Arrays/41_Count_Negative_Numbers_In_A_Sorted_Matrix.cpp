// LeetCode 1351 => ** Count Negative Numbers in a Sorted Matrix **

// 1). Brute Force Approach => Traversal
//     Time Complexity : O(n * m)
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

// 2). Better Approach => Binary Search on Each Row
//     Time Complexity : O(n * log m)
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

// 3). Optimal Approach => Staircase Traversal
//     Time Complexity : O(n + m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        int i = 0, j = m - 1;
        while(i < n && j >= 0){
            if(grid[i][j] < 0) {
                count += (n - i);
                j--;
            }
            else i++;
        }
        return count;
    }
};

// Start from the top-right corner.
//
// If the current element is negative,
// all elements below it in the same column
// are also negative.
// So, add (n - i) to the count
// and move left.
//
// If the current element is non-negative,
// all elements to its left in the same row
// are also non-negative.
// So, move down.
//
// This avoids checking every element.