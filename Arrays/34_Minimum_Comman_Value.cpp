// LeetCode 2540 => ** Minimum Common Value **

// Optimal Approach => Two Pointer 
// Time Complexity : O(n + m)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(nums1[i] == nums2[j]) return nums1[i];
            else if(nums1[i] > nums2[j]) j++;
            else i++;
        }
        return -1;
    }
};
// Use two pointers,
// one for each sorted array.
// Compare the current elements.
// If they are equal,
// return the common value.
// Otherwise, move the pointer
// of the smaller element.
// If no common value exists,
// return -1.