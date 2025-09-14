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
        int res = INT_MAX;
        vector<int> v;
        for (const auto& s : timePoints) {
            int t = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
            v.push_back(t);
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); ++i) {
            res = min(res, v[i] - v[i-1]);
        }
        res = min(res, v[0] + 1440 - v.back());
        return res;
    }
};