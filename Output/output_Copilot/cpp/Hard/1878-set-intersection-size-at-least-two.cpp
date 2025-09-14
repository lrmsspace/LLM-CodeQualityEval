/**https://leetcode.com/problems/set-intersection-size-at-least-two/ */
//You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.
//A containing set is an array nums where each interval from intervals has at least two integers in nums.
//	For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
//Return the minimum possible size of a containing set.
// 
//Example 1:
//Input: intervals = [[1,3],[3,7],[8,9]]
//Output: 5
//Explanation: let nums = [2, 3, 4, 8, 9].
//It can be shown that there cannot be any containing array of size 4.
//Example 2:
//Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
//Output: 3
//Explanation: let nums = [2, 3, 4].
//It can be shown that there cannot be any containing array of size 2.
//Example 3:
//Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
//Output: 5
//Explanation: let nums = [1, 2, 3, 4, 5].
//It can be shown that there cannot be any containing array of size 4.
// 
//Constraints:
//	1 <= intervals.length <= 3000
//	intervals[i].length == 2
//	0 <= starti < endi <= 108
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        int n = intervals.size();
        vector<int> points = {intervals[0][1] - 1, intervals[0][1]};
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= points[points.size() - 2]) {
                continue;
            }
            if (intervals[i][0] <= points.back()) {
                points.push_back(intervals[i][1]);
            } else {
                points.push_back(intervals[i][1] - 1);
                points.push_back(intervals[i][1]);
            }
        }
        return points.size();        
    }
};