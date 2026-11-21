// LeetCode 2677 => Chunk Array

// Optimal Approach => Simulation
// Time Complexity : O(n)
// Auxiliary Space Complexity : O(size)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> chunk(vector<int>& arr, int size) {
        vector<vector<int>> ans;

        for(int i = 0; i < arr.size(); i += size) {
            vector<int> temp;

            for(int j = i; j < min(i + size, (int)arr.size()); j++) {
                temp.push_back(arr[j]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

// Divide the array into chunks of the given size.
//
// Traverse the array in steps of `size`.
// Create a temporary vector for each chunk.
// Add elements until the chunk reaches the given size
// or the array ends.
//
// Push each completed chunk into the answer.