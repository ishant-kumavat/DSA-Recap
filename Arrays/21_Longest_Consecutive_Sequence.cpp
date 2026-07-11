// LeetCode 128 => ** Longest Consecutive Sequence **

// 1). Brute Force Approach :
//     Time Complexity : O(n logn)
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

// 2). Optimal Solution =>
//     Time Complexity :
//     Space Complexity :
#include <bits/stdc++.h>
using namespace std;