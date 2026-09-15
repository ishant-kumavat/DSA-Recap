// LeetCode 4052 => ** Cyclically Shift Rows and Columns **

// 1). Brute Force Approach => Repeated Adjacent Swapping
//     Time Complexity : O(n ^ 3)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shift_row_col(vector<vector<int>>& grid, int k, int i, int n, int flag){
        k %= n;
        for(int j = 0; j < k; j ++){
            for(int k = 0; k < n - 1; k++){
                if(flag == 0) swap(grid[i][k], grid[i][k+1]);
                    else swap(grid[k][i], grid[k+1][i]);
            }
        }
        return;
    }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i = 0; i < n; i++){
            shift_row_col(grid, rowShift[i], i, n, 0);
        }
        for(int i = 0; i < n; i++){
            shift_row_col(grid, colShift[i], i, n, 1);
        }
        return grid;
    }
};

// 2). Better Approach => Direct Shift + Temporary Storage 
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void shift_row_col(vector<vector<int>>& grid, int k, int i, int n, int flag){
        k %= n;
        vector<int> shifted;
        for(int j = 0; j < k; j++){
            if(flag == 0) shifted.push_back(grid[i][j]);
            else shifted.push_back(grid[j][i]);
        }
        int l = 0;
        for(int j = k; j < n; j++){
            if(flag == 0) grid[i][l] = grid[i][j];
            else grid[l][i] = grid[j][i];
            l++;
        }
        for(int j = 0; j < shifted.size(); j++){
            if(flag == 0) grid[i][l] = shifted[j];
            else grid[l][i] = shifted[j];
            l++;
        }
        return;
    }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i = 0; i < n; i++){
            shift_row_col(grid, rowShift[i], i, n, 0);
        }
        for(int i = 0;i < n; i++){
            shift_row_col(grid, colShift[i], i, n, 1);
        }
        return grid;
    }
};