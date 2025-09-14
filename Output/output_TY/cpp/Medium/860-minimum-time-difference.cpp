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
        vector<int> times(n);
        for(int i = 0; i < n; i++){
            times[i] = stoi(timePoints[i].substr(0,2))*60 + stoi(timePoints[i].substr(3,2));
        }
        sort(times.begin(), times.end());
        int minDiff = INT_MAX;
        for(int i = 0; i < n-1; i++){
            minDiff = min(minDiff, times[i+1] - times[i]);
        }
        return min(minDiff, 1440 + times[0] - times[n-1]);
    }
};