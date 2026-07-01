// LeetCode 26 => ** Remove Duplicates from Sorted Array **

// 1.  Naive Approach => Using Extra Space
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != ans.back()) ans.push_back(nums[i]);
        }
        nums = ans;
        return ans.size();
    }
};

// 2. Brute Force Approach => Using Set DS
//     Time Complexity : O(n * log n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(int i = 0; i < nums.size(); i++) st.insert(nums[i]);
        int i = 0;
        for(auto it : st){
            nums[i] = it;
            i++;
        }
        return st.size();
    }
};

// 3). Optimal Approach => Use Two Pointer Technique
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[j]){
                j++;
                swap(nums[i], nums[j]);
            }
        }
        return (j + 1);
    }
};

// j points to the last unique element.
// Traverse the array and whenever a new unique element is found,
// move it to the next position.
