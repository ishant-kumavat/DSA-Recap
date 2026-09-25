// LeetCode 338 => ** Counting Bits **

// 1). Brute Force Approach =>
//     Time Complexity : O(n log n)
//     Space Complexity : O(n) output space
//     Auxiliary Space : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            int one = __builtin_popcount(i);
            ans.push_back(one);
        }
        return ans;
    }
};

// 2). Better Approach =>
//     Time Complexity : O(n log n)
//     Space Complexity : O(n) output space
//     Auxiliary Space : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find_bin_and_count_one(int x){
        int one = 0;
        while(x != 0){
            if(x % 2 == 1) one ++;
            x /= 2;
        }
        return one;
    }
    vector<int> countBits(int n) {
        vector<int> ans((n + 1), 0);
        for(int i = 0; i <= n; i++){
            ans[i] = find_bin_and_count_one(i);
        }
        return ans;
    }
};

// 3). Optimal Approach =>
//     Time Complexity : O(n)
//     Space Complexity : O(n) output space
//     Auxiliary Space : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans((n + 1), 0);
        for(int i = 0; i <= n; i++){
            if(i % 2 == 0) ans[i] = ans[i / 2]; 
            else ans[i] = ans[i / 2] + 1;
        }
        return ans;
    }
};

// For every i:
// - If i is even, i/2 has the same number of set bits.
// - If i is odd, i/2 has one less set bit.
//
// Example:
// 6 = 110  -> 3 = 11  -> same set bits
// 7 = 111  -> 3 = 11  -> one extra set bit