// LeetCode 27 => ** Remove Element **

// 1). Brute Force Approach => Using Extra Space
//     Time Complexity : O(n)
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        vector<int>temp(n, 0);
        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != val) temp[j++] = nums[i];
        }
        nums = temp;
        return j;
    }
};
// Copy all elements except the target value
// into a temporary array.
// Copy the result back and
// return the new length.

// 2). Optimal Approach => Two Pointers + Swapping
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0, k = n - 1;
        while(i < n && i <= k){
            if(nums[i] == val){
                swap(nums[i], nums[k]);
                k--;
            }
            else i++;
        }
        return (k + 1);
    }
};
// Use two pointers.
// Scan the array from the front.
// If the current element equals the target,
// swap it with the last valid element
// and shrink the valid range.
// Since the order of elements does not matter,
// this gives the required result in-place.