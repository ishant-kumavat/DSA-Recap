// LeetCode 4020 => ** Elevator Requests I **

// Optimal Solution =>
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int total_time = requests[0];
        int i = 1;
        while(i < requests.size()){
            total_time += abs(requests[i - 1] - requests[i]);
            i++;
        }
        return total_time;
    }
};

// Start from the ground floor (0)
// and move to the first requested floor.
//
// For each next request,
// add the distance from the previous floor.
//
// Return the total elevator travel time.