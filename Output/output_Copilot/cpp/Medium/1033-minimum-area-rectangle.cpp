/**https://leetcode.com/problems/minimum-area-rectangle/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
// 
//Example 1:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
//Output: 4
//Example 2:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
//Output: 2
// 
//Constraints:
//	1 <= points.length <= 500
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> x2y;
        for (const auto& p : points) {
            x2y[p[0]].insert(p[1]);
        }
        int minArea = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] || points[i][1] == points[j][1]) {
                    continue;
                }
                if (x2y[points[i][0]].count(points[j][1]) && x2y[points[j][0]].count(points[i][1])) {
                    minArea = min(minArea, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;        
    }
};