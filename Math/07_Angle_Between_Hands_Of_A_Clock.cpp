// LeetCode 1344 => Angle Between Hands of a Clock **

// Optimal Solution => Clock Hand Angle Calculation
// Time Complexity : O(1)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Hour hand moves 30° per hour
        // and 0.5° per minute.
        double hourAngle = (hour * 30) + (minutes * 0.5);

        // Minute hand moves 6° per minute.
        double minuteAngle = (minutes * 6);

        // Find the absolute angle
        // between the two hands.
        double angle = abs(hourAngle - minuteAngle);

        // Return the smaller angle.
        if(angle > 180) angle = 360 - angle;

        return angle;
    }
};
// Calculate the angle
// of the hour hand
// and the minute hand.
//
// Find the absolute
// difference between them.
//
// If the angle is
// greater than 180°,
// subtract it from 360°
// to get the smaller angle.
//
// Return the result.