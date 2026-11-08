// LeetCode 905 => ** Sort Array By Parity **

// 1). Brute Force Approach =>
// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;

        for(int it : nums) if(it % 2 == 0) ans.push_back(it);

        for(int it : nums) if(it % 2 != 0) ans.push_back(it);
    
        return ans;
    }
};

// Approach 2 => Two Pointers
// Time Complexity : O(n)
// Space Complexity : O(1) auxiliary space

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;

        while(i < j) {
            if(nums[i] % 2 == 0) {
                i++;
            }
            else if(nums[j] % 2 != 0) {
                j--;
            }
            else {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        return nums;
    }
};

// Use two pointers: i starts from the beginning
// and j starts from the end.
//
// If the left element is even, move i forward.
// If the right element is odd, move j backward.
// Otherwise, swap both elements and move both pointers.
//
// This places all even numbers before odd numbers.