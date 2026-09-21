    // LeetCode 3668 => ** Restore Finishing Order **

    // 1). Binary Search Approach
    //     Time Complexity : O(n log m)
    //     Space Complexity : O(1)

    #include <bits/stdc++.h>
    using namespace std;
    class Solution {
    public:
        bool IsExistOrder(int x, vector<int>& nums){
            int low = 0, high = nums.size() - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(nums[mid] == x) return true;
                else if(nums[mid] > x) high = mid - 1;
                else low = mid + 1;
            }
            return false;
        }
        vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
            vector<int> ans;
            for(int i = 0; i < order.size();i++){
                if(IsExistOrder(order[i], friends)) ans.push_back(order[i]);
            }
            return ans;
        }
    };

    // 2). Frequency Array
    //     Time Complexity : O(n + m)
    //     Space Complexity : O(M)
    //     where M = maximum value in friends.

    #include <bits/stdc++.h>
    using namespace std;
    class Solution {
    public:
        int find_mx(vector<int>& nums){
            int mx = INT_MIN;
            for(auto it : nums) mx = max(it, mx);
            return mx; 
        }
        vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
            vector<int> ans;
            int mx = find_mx(friends);
            vector<int> hasharr(mx + 1, 0);
            for(auto it : friends) hasharr[it] ++;
            for(auto it : order){
                if(it <= mx && hasharr[it] >= 1) ans.push_back(it);
            }   
            return ans;
        }
    };

    // 3). Hash Set
    //     Time Complexity : O(n + m) average
    //     Space Complexity : O(m)

    #include <bits/stdc++.h>
    using namespace std;
    class Solution {
    public:
        vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
            vector<int> ans;
            unordered_set<int> st;
            for(auto it : friends) st.insert(it);
            for(auto it : order){
                if(st.count(it)) ans.push_back(it);
            }   
            return ans;
        }
    };