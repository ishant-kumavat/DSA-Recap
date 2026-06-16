// LeetCode 18 => ** 4 Sum **

// 1). Brute Force Approach => Using 4 nested loops
//     Time Complexity : O( n ^ 4 * log m )
//     Space Complexity : O( 2 * n )
//     where, m = number of unique quadruplets in set

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set <vector<int> > ans;
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                for(int k = j + 1; k < n - 1; k++){
                    for(int l = k + 1; l < n; l++){
                        long long a = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                        if(a == target){
                            vector<int>a = {nums[i] , nums[j] , nums[k] , nums[l]};
                            sort(a.begin() , a.end());
                            ans.insert(a);
                        }
                    }
                }
            }
        } 
        vector<vector<int>> arr(ans.begin(), ans.end());
        return arr;
    }
};

// 2). Better Solution => 
//     Time Complexity : O( n ^ 3 * log m )
//     Space Comlexity : O ( n + m )
//     where m = unique quadruplets

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set <vector<int>> ans;
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                set<long long>st;
                for(int k = j + 1; k < n; k++){
                    long long a = target - (1LL * nums[i] + nums[j] + nums[k]);
                    if(st.find(a) != st.end()){
                        vector<int> temp {nums[i], nums[j], nums[k], (int)a};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                    st.insert((long long)nums[k]);
                }
            }
        }
        vector <vector<int>> arr(ans.begin(), ans.end());
        return arr;
    }
};

// 3). Optimal Solution => Using two pointer technique
//     Time Complexity : O( n ^ 3 )
//     Space Complexity : O( m )
//     where m = unique quadruplets

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n - 3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;//note
                int k = j + 1, l = n - 1;
                while(k < l){
                    long long x = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                    if(target == x){
                        vector<int>temp ={nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;l--;
                        while(k < l && nums[k] == nums[k - 1]) k++;
                        while(k < l && nums[l] == nums[l + 1]) l--; 
                    }
                    else if(target < x) l--;
                    else k++;
                }
            }
        }
        return ans;
    }
};