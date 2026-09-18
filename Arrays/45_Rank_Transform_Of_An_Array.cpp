// LeetCode 1331 => ** Rank Transform of an Array **

// 1). Brute Force Solution => Set + Repeated Linear Search
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> find_idx(vector<int>& arr, int x){
        vector<int> nums;
        for(int i = 0; i < arr.size(); i++) if(arr[i] == x) nums.push_back(i);
        return nums;
    }
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        vector<int> ans(n, 0);
        for(auto it : arr) st.insert(it);
        int i = 1;
        for(auto it : st){
            vector<int>indices = find_idx(arr, it);
            for(int j = 0; j < indices.size(); j++) ans[indices[j]] = i;
            i++;
        }
        return ans;
    }
};

// 2). Optimal Solution => Sorting + Hash Map
//     Time Complexity : O(n log n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums(arr.begin(), arr.end());
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        int idx = 1;
        for(auto it : nums) if(mpp.find(it) == mpp.end()) {mpp[it] = idx; idx++;}
        for(auto it : arr){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};

// Copy the original array and sort it.
//
// Assign ranks to unique elements using a hash map.
//
// The smallest element gets rank 1.
// For duplicate elements, keep the same rank.
//
// Finally, traverse the original array
// and replace each element with its rank.
//
// Sorting helps determine the rank order,
// while the hash map provides average O(1)
// lookup for each element.