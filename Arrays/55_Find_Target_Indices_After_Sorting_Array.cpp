// LeetCode 2089 => ** Find Target Indices After Sorting Array **

// 1). Brute Force Approach => Sorting + Linear Search
//     Time Complexity : O(n log n)
//     Space Complexity : O(log n) auxiliary, typically
//                        for sorting recursion stack

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        bool flag = false;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) {flag = true; ans.push_back(i);}
            if(flag && nums[i] != target) break;
        }
        
        return ans;
    }
};

// 2). Better Approach => Sorting + Binary Search
//     Time Complexity : O(n log n)
//     Space Complexity : O(log n) auxiliary, typically
//                        for sorting recursion stack

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int low = 0, high = nums.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target) high = mid - 1;
            else low = mid + 1;
        }

        for(int i = high + 1; i < nums.size(); i++) {
            if(nums[i] != target) break;
            else ans.push_back(i); 
        }

        return ans;
    }
};

// 3). Optimal Approach => Counting + Index Calculation
//     Time Complexity : O(n)
//     Space Complexity : O(1) auxiliary, excluding output

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int idx = -1;
        int targetCount = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) targetCount++;
            if(nums[i] < target) idx++;
        }

        if(idx == -1 && targetCount == 0) return {};

        for(int i = 1; i <= targetCount; i++) {
            idx++;
            ans.push_back(idx);
        }

        return ans;
    }
};

// Count the occurrences of the target using `targetCount`.
//
// Count elements smaller than the target.
// `idx` represents this count minus one.
//
// In the sorted array, the target's first index
// equals the number of elements smaller than the target.
//
// Generate `targetCount` consecutive indices
// starting from `idx + 1`.
//
// Return the answer without sorting the array.