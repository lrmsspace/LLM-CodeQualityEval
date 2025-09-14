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
        vector<int> hours(n), minutes(n);
        for (int i = 0; i < n; ++i) {
            istringstream iss(timePoints[i]);
            string h, m;
            iss >> h >> m;
            hours[i] = stoi(h) * 60 + stoi(m);
        }
        
        sort(hours.begin(), hours.end());
        
        int ans = INT_MAX;
        for (int i = 1; i < n; ++i) {
            ans = min(ans, hours[i] - hours[i - 1]);
        }
        
        ans = min(ans, 24 * 60 - hours[n - 1] + hours[0]);
        
        return ans;
        
    }
};