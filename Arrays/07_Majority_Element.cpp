// LeetCode 169 => ** Majority Element **

// 1). Brute Force Approach => Using nested loops
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size();
       int maj = n/2;
       for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = i; j < n; j++){
            if(nums[i] == nums[j]) count++;
        }
        if(count > maj) return nums[i];
       }
       return -1;
    }
};

// 2). Better Approach => Sorting
//     Time Complexity : O( n lon n + n )
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maj = n/2;
        if(n == 1) return nums[0];
        int j = 0,count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[j]) count++;
            if(nums[i] != nums[j]){
                j = i;
                count = 1;
            }
            if(count > maj) return nums[j];
        }
        return -1;
    }
};

// 3). Optimal Solution : Moore's Voting Algorithm 
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int me = 0;
        for(int i = 0; i < n; i++){
            if(count == 0)
            me = nums[i];

        if(nums[i]==me)
            count++;
        else
            count--;
        }
        return me;
    }
};

// Moore's Voting Algorithm
// Majority element survives after cancelling all other elements.