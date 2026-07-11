// LeetCode 48 => ** Rotate Image **

// 1). Brute Force Approach => Using extra array.
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(n ^ 2)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[j][n - i - 1] = mat[i][j];
            }
        }
        mat = ans;
    }
};
// Place every element at its rotated position
// in a new matrix, then copy it back.

// 2). Optimal Approach => Transpose + Reverse
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
       int n = mat.size();
       for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i == j) continue;
            swap(mat[i][j], mat[j][i]);
        }
       }
       for(int i = 0; i < n; i++){
        int st = 0, ed = n - 1;
        while(st < ed) swap(mat[i][st++], mat[i][ed--]);
       }
    }
};
// First transpose the matrix.
// Then reverse every row.
// This rotates the matrix by 90° clockwise in-place.