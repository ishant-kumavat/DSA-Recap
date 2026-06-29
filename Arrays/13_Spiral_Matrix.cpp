// LeetCode 54 => ** Spiral Matrix **

// 1). Optimal Solution =>
//     Time Complexity : O(n * m)
//     Space Complexity : O(1)
// The output vector is not considered in the auxiliary space complexity
// because it is used only to store the final answer.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        vector<int> ans;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
            bottom--;
            }
            if(left <= right){   
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

// Traverse the matrix layer by layer.
// In each layer, move in the following order:
// 1. Left to Right
// 2. Top to Bottom
// 3. Right to Left
// 4. Bottom to Top
// After completing one layer, shrink the boundaries
// and repeat until all elements are visited.