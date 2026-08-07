// LeetCode 167 => ** Two Sum II - Input Array Is Sorted **

// 1). Brute Force Approach => Using Nested Loops
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1) 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] == target) return {(i + 1), (j + 1)};
            }
        }
        return {-1, -1};
    }
};
// Traverse every pair of elements.
// If their sum equals the target,
// return their 1-based indices.
// If no pair exists, return {-1, -1}.

// 2). Better Solution => Hash Map
//     Time Complexity : O(n) (Average)
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int x = target - nums[i];
            if(mpp.find(x) != mpp.end()) 
                return {mpp[x], (i + 1)};
            mpp[nums[i]] = i + 1;
        }
        return {-1, -1};
    }
};
// Traverse the array once.
// For each element,
// compute the required complement.
// If the complement already exists
// in the hash map, return both
// 1-based indices.
// Otherwise, store the current
// element and its index.

// 3). Optimal Solution => Two Pointer
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i < j){
            int x = nums[i] + nums[j];
            if(x == target) return {(i + 1), (j + 1)};
            else if(x < target) i++;
            else j--;
        }
        return {-1, -1};
    }
};
// Place one pointer at the beginning
// and one at the end.
// If their sum equals the target,
// return their 1-based indices.
// If the sum is smaller,
// move the left pointer.
// Otherwise, move the right pointer.