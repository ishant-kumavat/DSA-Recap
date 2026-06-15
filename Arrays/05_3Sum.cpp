// LeetCode 15 -> ** 3 Sum **

// 1). Brute Force Approach => Using 3 nested loops
//     Time Complexity : O(n³ log m)
//     where m = number of unique triplets
//     Space Complexity : O(2 * number of triplet)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>arr(ans.begin(),ans.end());
        return arr;
    }
};

// 2). Better Solution => Using Map Data Structure
//     Time Complexity : O(n²(log n + log m))
//     Space Complexity : Space Complexity : O(n + m)
//     where, m = number of unique triplets.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>arr;
        for(int i=0;i<n-2;i++){
            unordered_set<int>st;
            for(int j=i+1;j<n;j++){
                int a=-1 * (nums[i] + nums[j]);
                if(st.find(a) != st.end()){
                    vector<int>temp={nums[i],nums[j],a};
                    sort(temp.begin(),temp.end());
                    arr.insert(temp);
                }
                st.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(arr.begin(),arr.end());
        return ans;
    }
};

// 3). Optimal Solution => Using 2 pointer and sorting
//     Time Complexity : O(n²)
//     Space Complexity :  O(number of triplets)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};

// Fix one element, then use two pointers
// on remaining sorted array