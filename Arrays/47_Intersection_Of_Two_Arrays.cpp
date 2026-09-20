// LeetCode 349 => ** Intersection of Two Arrays **

// 1). Hash Set Approach
//     Time Complexity : O(n1 + n2) average
//     Space Complexity : O(n1 + n2)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_set<int> st;
        unordered_set<int> stt;
        for(auto it : nums1) st.insert(it);
        for(auto it : nums2){
            if(st.count(it)) stt.insert(it);
        }
        vector<int> ans(stt.begin(), stt.end());
        return ans;
    }
};

// 2). Sorting + Two Pointers
//     Time Complexity : O(n1 log n1 + n2 log n2) 
//     Space Complexity : O(1) auxiliary

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        while(i < n1 && j < n2){
            if(nums1[i] == nums2[j] ) {
                if((ans.size() == 0) || (ans.size() != 0 && ans.back() != nums1[i])) ans.push_back(nums1[i]); 
                i ++, j ++;
            }
            else if(nums1[i] > nums2[j]) j++;
            else i++;
        }
        return ans;
    }
};

// 3). Frequency Array
//     Time Complexity : O(n1 + n2 + M)
//     Space Complexity : O(M)
//     where M is the maximum value/range used for the frequency array.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find_max(vector<int>& nums){
        int mx = INT_MIN;
        for(auto it : nums) mx = max(mx, it);
        return mx;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int mx1 = find_max(nums1) + 1;
        int mx2 = find_max(nums2) + 1;
        vector<int> vec1(mx1, 0);
        vector<int> vec2(mx2, 0);
        int n1 = nums1.size(), n2 = nums2.size();
        for(auto it : nums1) vec1[it] ++;
        for(auto it : nums2) vec2[it] ++;
        vector<int> ans;
        for(int i = 0; i < vec1.size(); i++){
            if(vec1[i] == 0) continue;
            else{
                if(i < vec2.size() && vec2[i] != 0) ans.push_back(i);
            }
        }
        return ans;
    }
};