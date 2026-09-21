// LeetCode 881 => ** Boats to Save People **

// Optimal Solution => Sorting + Two Pointers
// Time Complexity : O(n log n)
// Space Complexity : O(1) auxiliary

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int n = people.size();
        int i = 0, j = n - 1;
        while(i <= j){
            if(people[i] + people[j] <= limit) {i++; j--;}
            else j--;
            ans ++; 
        } 
        
        return ans;
    }
};

// Sort people in ascending order.
//
// Use two pointers:
// `i` -> lightest person
// `j` -> heaviest person.
//
// If the lightest and heaviest people
// can fit together within the limit,
// put them in the same boat.
//
// Otherwise, the heaviest person
// must go alone.
//
// Move the corresponding pointers
// after assigning each boat.
//
// Count the total number of boats used.