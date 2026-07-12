// LeetCode 493 => ** Reverse Pairs **

// Optimal Solution => Modified Merge Sort (Divide and Conquer)
// Time Complexity : O(n log n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high){
        int left = low, right = mid + 1, cnt = 0;
        while(left <= mid && right <= high){
            if(nums[left] > (long long)(2 * (long long)nums[right])){
                cnt += ((mid + 1) - left);
                right ++;
            }
            else left ++;
        }
        vector<int> temp;
        left = low, right = mid + 1;
        while(left <= mid && right <= high){
            if(nums[left] > nums[right]) temp.push_back(nums[right++]);
            else temp.push_back(nums[left++]);
        }
        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= high) temp.push_back(nums[right++]);
        int j = 0;
        for(int i = low; i <= high ; i++){
            nums[i] = temp[j++];
        }
        return cnt;
    }
    int mergesort(vector<int>& nums, int low, int high){
        int cnt = 0;
        if(low == high) return cnt;
        int mid = low + (high - low) / 2;  
        cnt += mergesort(nums, low, mid);
        cnt += mergesort(nums, mid + 1, high);
        cnt += merge(nums, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
};
// Divide the array into two parts.
// Count reverse pairs before merging.
// Since both parts are already sorted,
// if nums[left] > 2 * nums[right],
// then all elements from left to mid
// will also satisfy the condition.
// Finally, merge the two sorted parts.