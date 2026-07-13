// LeetCode 128 => ** Longest Consecutive Sequence **

// 1). Brute Force Approach => Using Nested Loops
//     Time Complexity : O(n ^ 2) 
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ls(vector<int> &nums, int x){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == x) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        int mx = 1;
        for(int i = 0; i < n; i++){
            int cnt = 1;
            int x  = nums[i] + 1;
            while(ls(nums, x)){
                x++;
                cnt++;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};
// Start from every element and keep searching
// for the next consecutive number.
// Update the maximum sequence length.

// 2). Better Approach : Use Set
//     Time Complexity : O(n log n)
//     Space Complexity :O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        set<int>st;
        int cnt = 1, ans = 1;
        for(auto it : nums) st.insert(it);
        for(auto it = st.begin(); it != st.end(); it++){
            auto nxt = next(it);
            if(nxt != st.end() && *nxt == *it + 1){
                cnt ++;
                ans = max(ans, cnt);
            }
            else cnt = 1;
        }
        return ans;
    }
};
// Store all unique elements in a sorted set.
// Traverse the set and count consecutive elements.
// Reset the count whenever the sequence breaks.
// Keep track of the maximum sequence length.

// 3). Better Approach : Use Sorting
//     Time Complexity : O(n log n)
//     Space Complexity :O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        sort(nums.begin(), nums.end());
        int cnt = 1, mx = 1, me = nums[0];
        for(int i = 1; i < n; i++){
            if(me == nums[i]) continue;
            else if((me + 1) == nums[i]){
                cnt++;
                me = nums[i];
            }
            else{
                mx = max(mx, cnt);
                cnt = 1;
                me = nums[i];
            }
        }
        mx = max(mx, cnt);
        return mx;
    }
};
// Sort the array.
// Ignore duplicate elements.
// Count consecutive numbers.
// Reset the count when the sequence breaks.
// Update the maximum sequence length.

// 4). Optimal Solution => Using Hash Set
//     Time Complexity : O(n) average
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        for(int i = 0; i < n; i++) st.insert(nums[i]);
        int cnt, mx = 1;
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int x = (it + 1);
                cnt = 1;
                while(st.find(x) != st.end()){
                    cnt++;
                    x++;
                }
                mx = max(mx, cnt);
            }
            else continue;
        }
        return mx;
    }
};
// Store all elements in a hash set.
// Start only from elements that have no predecessor
// (element - 1 is not present).
// Extend the sequence forward and
// update the maximum sequence length.