// LeetCode 4024 => ** Nearest Available Drone **

// Optimal Solution => Linear Scan + Manhattan Distance
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = INT_MAX;
        int me = -1;
        for(int i = 0; i < drones.size(); i++){
            int distance = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if(distance <= drones[i][2] && ans > distance){
                ans = distance;
                me = i;
            }
        }
        return me;
    }
};

// Calculate the Manhattan distance
// between each drone and the target.
//
// Check whether the drone
// is within its available range.
//
// Keep track of the drone
// with the minimum distance.
//
// Return its index.