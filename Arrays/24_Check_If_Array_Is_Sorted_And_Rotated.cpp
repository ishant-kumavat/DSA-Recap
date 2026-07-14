// LeetCode 1752 => ** Check if Array Is Sorted and Rotated **

// 1). Brute Force Approach => Sort + Rotate
//     Time Complexity : O(n^2)
//     Space Complexity :O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        if(temp == nums) return true;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[0];
            nums.erase(nums.begin());
            nums.push_back(x);
            if(nums == temp) return true;
        }
        return false;
    }
};

// 2). Better Approach => Reverse Rotation + Check
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int x = -1;
        int n = nums.size();
        for(int i = 0; i < n -1; i++){
            if(nums[i] > nums[i + 1]){
                x = i;break;
            }
        }
        if(x == -1) return true;
        reverse(nums.begin(), nums.begin() + x + 1);
        reverse(nums.begin() + x + 1, nums.end());
        reverse(nums.begin(), nums.end());
        for(int i = 0; i < n -1; i++){
            if(nums[i] > nums[i + 1]){
                return false;
            }
        }
        return true;
    }
};
// Find the rotation point.
// Rotate the array back using three reverses.
// Finally, check whether the array is sorted.

// 3). Optimal Solution => Count Inversion Points
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size(); 
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i + 1) % n]) cnt++;
        }
        if(cnt >= 2) return false;
        return true;
    }
};
// Count how many times an element
// is greater than its next element.
// A sorted and rotated array can have
// at most one such inversion.