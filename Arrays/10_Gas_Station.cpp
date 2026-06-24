// LeetCode 134 => ** Gas Station **

// 1). Brute Force Approach => Naive Solution
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        long long SumGas = 0;
        long long SumCost = 0;
        for(auto it : gas){
            SumGas += it;
        }
        for(auto it : cost){
            SumCost += it;
        }
        if(SumGas < SumCost) return -1;

        long long sum = 0;
        int idx = 0, i = 0; 
        while(i < n){
            if(i == n - 1) return (n - 1);
            else if(sum + (gas[i] - cost[idx]) < 0){
                sum = 0;
                idx ++;
                i ++;
            }
            else{
                int j = i, idxx = idx;
                sum += (gas[j] - cost[idxx]);
                j++;idxx++;
                if(j >= n && idxx >= cost.size()) j = 0, idxx = 0;
                while(sum + (gas[j] - cost[idxx]) > 0){
                    sum += (gas[j] - cost[idxx]);
                    j++;idxx++;
                    if(j >= n && idxx >= cost.size()) j = 0, idxx = 0;
                    if(i == (j + 1) || (i == 0 && j == (n - 1))) return i;
                }
                sum = 0;
                i++;idx++;
            }
        }
        return -1;
    }
};

// 2). Optimal Greedy Approach
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long long SumGas = 0;
        long long SumCost = 0;
        for(auto it : gas){
            SumGas += it;
        }
        for(auto it : cost){
            SumCost += it;
        }
        if(SumGas < SumCost) return -1;
        long long start = 0, curSum = 0;
        for(int i = 0; i < gas.size(); i++){
            curSum += (gas[i] - cost[i]);
            if(curSum < 0){
                start = i + 1;
                curSum = 0;
            }
        }
        return (int)start;
    }
};

// 3). Single Pass Greedy Approach
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long long SumGas = 0;
        long long SumCost = 0;
        long long start = 0, curSum = 0;
        for(int i = 0; i < gas.size(); i++){
            SumGas += gas[i];
            SumCost += cost[i];
            curSum += (gas[i] - cost[i]);
            if(curSum < 0){
                start = i + 1;
                curSum = 0;
            }
        }
        if(SumGas < SumCost) return -1;
        return (int)start;
    }
};

// If current fuel becomes negative,
// none of the stations between start and i
// can be a valid starting point.