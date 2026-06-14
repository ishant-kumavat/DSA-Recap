// LeetCode 75 -> ** Sort Colors **

// 1). Brute Force Approach I => Using any Sorting Technique
//     Time Complexity : O(n * log n)
//     Space Complexity : O(log n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

// 2). Brute Force Approach II => Using Nested Loops
//     Time Complexity : O(n^2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1]) swap(nums[j],nums[j+1]);
            }
        }
    }
};

// 3). Better Approach => Using Additional variable and Separate Colors
//     Time Complexity : O(2*n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) a++;
            else if(nums[i]==1) b++;
            else c++;
        }
        for(int i=0;i<a;i++) nums[i]=0;
        for(int i=a;i<(a+b);i++) nums[i]=1;
        for(int i=(a+b);i<n;i++) nums[i]=2;
        
    }
};

// 4). Optimal Solution => Using Dutch National Flag Algorithm
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;low++;
            }
            else if(nums[mid]==1) mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

// [0...low-1] = 0
// [low...mid-1] = 1
// [mid...high] = unsorted
// [high+1...n-1] = 2