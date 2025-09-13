/**https://leetcode.com/problems/minimum-time-difference/ */
//Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
// 
//Example 1:
//Input: timePoints = ["23:59","00:00"]
//Output: 1
//Example 2:
//Input: timePoints = ["00:00","23:59","00:00"]
//Output: 0
// 
//Constraints:
//	2 <= timePoints.length <= 2 * 104
//	timePoints[i] is in the format "HH:MM".
int findMinDifference(char** timePoints, int timePointsSize) {
    int minDiff = INT_MAX;
    int minHour = 0, minMinute = 0;
    
    // Convert each time point to minutes
    for (int i = 0; i < timePointsSize; i++) {
        int hour = (timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0');
        int minute = (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
        
        if (i > 0) {
            int diff = (hour * 60 + minute) - ((minHour * 60) + minMinute);
            minDiff = min(minDiff, abs(diff));
        }
        
        if (hour > minHour || (hour == minHour && minute < minMinute)) {
            minHour = hour;
            minMinute = minute;
        }
    }
    
    // Handle the case when the list ends with the same time point
    int diff = (23 * 60 + 59) - ((minHour * 60) + minMinute);
    minDiff = min(minDiff, abs(diff));
    
    return minDiff;
    
}