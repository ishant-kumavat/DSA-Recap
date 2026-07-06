// LeetCode 11 => ** Container With Most Water **

// 1). Brute Force Approach => Using Nested Loops 
//     Time Complexity : O(n^2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1;j < n; j++){
                int area = (min(height[i], height[j]) * (j - i));
                ans = max(ans, area);
            }
        }
        return ans;
    }
};

// 2). Optimal Solution => Using Two Pointer Technique
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int ans = 0;
        while(i < j){
            int area = (min(height[i], height[j]) * (j - i));
            ans = max(ans, area);
            if(height[i] > height[j]) j--;
            else i++;
        }
        return ans;
    }
};
// Observation:
// The area is limited by the shorter line.
// Therefore, always move the pointer with the smaller height,
// as moving the taller line cannot increase the maximum area.