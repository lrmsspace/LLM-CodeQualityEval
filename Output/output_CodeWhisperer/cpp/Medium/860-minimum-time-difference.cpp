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
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes(n);
        for (int i = 0; i < n; i++) {
            string time = timePoints[i];
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            minutes[i] = hour * 60 + minute;
        }
        sort(minutes.begin(), minutes.end());
        int minDiff = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, minutes[i + 1] - minutes[i]);
        }
        minDiff = min(minDiff, minutes[0] + 1440 - minutes[n - 1]);
        return minDiff;     
    }
};