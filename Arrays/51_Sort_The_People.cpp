// LeetCode 2418 => ** Sort the People **

// 1). Ordered Map
//     Time Complexity : O(n log n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        map<int, string> mpp;
        for(int i = 0; i < heights.size(); i++){
            mpp[heights[i]] = names[i];
        }
        for(auto &it : mpp){
            ans.push_back(it.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Store each person's height and name in an ordered map.
// The map sorts heights in ascending order.
// Reverse the result to get people from tallest to shortest.

// 2). Vector + Sort
//     Time Complexity : O(n log n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;
        for(int i = 0; i < heights.size(); i++) {
            people.push_back({heights[i], names[i]});
        }
        
        sort(people.rbegin(), people.rend());
        vector<string> ans;
        for(auto &it : people){
            ans.push_back(it.second);
        }
        return ans;
    }
};

// Store each person's height and name as a pair.
// Sort the pairs in descending order of height.
// Extract the names in the sorted order.