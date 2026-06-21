// LeetCode 73 => ** Set Matrix Zeroes **

// 1). Better Approach => Using Extra Space
//     Time Complexity : O(m * n)
//     Space Complexity : O(m + n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i] == 1 || col[j] == 1) matrix[i][j] = 0;
            }
        }
    }
};

// 2). Optimal Approach =>
//     Time Complexity : O (m * n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col = 1, row = 1;
        for(int i = 0; i < n; i++){
            if(i == 0) row = 0;
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    if(j == 0) col = 0;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(row == 0){
            for(int i = 0; i < m; i++) matrix[0][i] = 0;
        }
        if(col == 0){
            for(int i = 0; i < n; i++) matrix[i][0] = 0;
        }
        
    }
};