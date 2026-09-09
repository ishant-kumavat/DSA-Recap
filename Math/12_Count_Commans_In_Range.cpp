// LeetCode 3870 => ** Count Commas in Range **

// 1). Better Approach => Traversal + Counting
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCommas(int n) {
        if(n >= 1 && n <= 999) return 0;
        int count = 0;
        for(int i = 1000; i <= 1e5 + 1; i++){
            if(i > n) return count;
            count ++;
        }
        return -1;
    }
};


// 2). Optimal Approach => Mathematical Counting
//     Time Complexity : O(1) 
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCommas(int n) {
        if(n <= 999) return 0;
        return (n - 1000 + 1); // return (n - 999);
    }
};

// Numbers from 1 to 999 contain no commas.
//
// Starting from 1000, every number contains
// exactly one comma because n <= 10^5.
//
// So, count the numbers from 1000 to n.
//
// Count = n - 1000 + 1
//       = n - 999