// LeetCode 2169 => ** Count Operations to Obtain Zero **

// 1). Brute Force Approach =>
//     Time Complexity :  O(max(num1, num2))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        while(num1 > 0 && num2 > 0){
            if(num1 > num2) num1 -= num2;
            else num2 -= num1;
            cnt++;
        }
        return cnt;
    }
};

// 2). Optimal Solution =>
//     Time Complexity : O(log(max(num1, num2)))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        if(num1 < num2) swap(num1, num2);
        while(num1 > 0 && num2 > 0){
            cnt += (num1 / num2);
            num1 %= num2;
            swap(num1, num2);
        }
        return cnt;
    }
};
// Instead of subtracting one by one,
// count all possible subtractions using division.
// Replace the larger number with its remainder.
// This is an optimized form of the Euclidean Algorithm.