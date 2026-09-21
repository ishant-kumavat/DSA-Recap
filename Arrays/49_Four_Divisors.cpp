// LeetCode 1390 => ** Four Divisors **

// 1). Brute Force Approach => Divisor Enumeration
//     Time Complexity : O(n * M)
//     Space Complexity : O(1)
//     where M is the maximum value in nums.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check_divisible(int x){
        int cnt = 0;
        int sum = 0;
        for(int i = 1; i <= x; i++){
            if(x % i == 0){cnt ++; sum += i;}
        }
        return (cnt == 4) ? sum : 0; 
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto it : nums){
            ans += check_divisible(it);
        }
        return ans;
    }
};

// 2). Optimal Approach => Divisor Pair Enumeration
//     Time Complexity : O(n * √M)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check_divisible(int x){
        int cnt = 0;
        int sum = 0;
        for(int i = 1; 1LL * i * i <= x; i++){
            if(x % i == 0){
                sum += i;
                int a = x / i;
                if(a == i) {cnt ++; continue;}
                sum += a;
                cnt += 2;
            }
        }
        return (cnt == 4) ? sum : 0; 
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto it : nums){
            ans += check_divisible(it);
        }
        return ans;
    }
};