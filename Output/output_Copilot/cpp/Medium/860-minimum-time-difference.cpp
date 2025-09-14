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
        vector<int> time;
        for (string timePoint : timePoints) {
            int hour = stoi(timePoint.substr(0, 2));
            int minute = stoi(timePoint.substr(3, 2));
            time.push_back(hour * 60 + minute);
        }
        sort(time.begin(), time.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < time.size(); i++) {
            minDiff = min(minDiff, time[i] - time[i - 1]);
        }
        minDiff = min(minDiff, time[0] + 24 * 60 - time.back());
        return minDiff;        
    }
};