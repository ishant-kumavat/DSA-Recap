// LeetCode 88 => ** Merge Sorted Array **

// 1). Brute Force Approach => Copy + Sort
//     Time Complexity : O((m + n) log (m + n))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i = m; i < nums1.size(); i++){
            nums1[i] = nums2[j];
            j++;
        }
        sort(nums1.begin(), nums1.end());
    }
};
// Copy all elements of nums2 into the unused positions of nums1.
// Then sort the entire array.

// 2). Optimal Approach => Two Pointers (Reverse Merge)
//     Time Complexity : O(m + n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = nums1.size() - 1;
        int i = m - 1, j = n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]) nums1[idx--] = nums1[i--];
            else nums1[idx--] = nums2[j--]; 
        }
        while(i >= 0){
            nums1[idx--] = nums1[i--];
        }
        while(j >= 0){
            nums1[idx--] = nums2[j--];
        }
    }
};
// Start merging from the end of both arrays.
// Place the larger element at the last available position.
// Continue until all elements are merged.