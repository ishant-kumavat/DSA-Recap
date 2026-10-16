// LeetCode 1394 => ** Find Lucky Integer in an Array **

// 1). Approach 1 => Frequency Array
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> hasharr(501, 0);
        for(auto &it : arr) hasharr[it] ++;
        int ans = -1;
        for(int i = 1; i <= 500; i++){
            if(hasharr[i] != 0 && i == hasharr[i]) ans = i;
        } 
        return ans;
    }
};

// Count the frequency of each number using
// a fixed-size frequency array.
//
// Traverse from 1 to 500 in increasing order.
//
// If a number's frequency equals the number itself,
// it is a lucky integer.
//
// Update `ans` whenever a lucky integer is found.
// Since we traverse in increasing order,
// the last lucky integer will be the largest.
//
// If no lucky integer exists, return -1.

// 2). Approach 2 => Unordered Map
//     Time Complexity : O(n) average
//     Space Complexity : O(n) average

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for(auto &it : arr) mpp[it] ++;
        int ans = -1;
        for(auto &it : mpp){
            if(it.first == it.second && it.first > ans){
                ans = it.first;
            }
        }
        return ans;
    }
};

// Count the frequency of each number
// using an unordered map.
//
// Each map entry contains:
// - First  -> Number
// - Second -> Frequency of that number
//
// A number is lucky if its value equals its frequency.
//
// Check every map entry and update `ans`
// whenever a larger lucky integer is found.
//
// If no lucky integer exists, return -1.