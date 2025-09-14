/**https://leetcode.com/problems/minimum-area-rectangle-ii/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
//Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: points = [[1,2],[2,1],[1,0],[0,1]]
//Output: 2.00000
//Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
//Example 2:
//Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
//Output: 1.00000
//Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
//Example 3:
//Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
//Output: 0
//Explanation: There is no possible rectangle to form from these points.
// 
//Constraints:
//	1 <= points.length <= 50
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<double, unordered_map<double, set<pair<int, int>>>> slope_map;
        double min_area = numeric_limits<double>::max();
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                double x1 = points[i][0], y1 = points[i][1];
                double x2 = points[j][0], y2 = points[j][1];
                double dx = x2 - x1, dy = y2 - y1;
                if (dx == 0 && dy == 0) continue;
                double slope = dy / dx;
                double key = (dx > 0? slope : -slope) + 0.5;
                slope_map[key][dx > 0? dy : -dy].insert({x1, y1});
                slope_map[key][dx > 0? dy : -dy].insert({x2, y2});
            }
        }
        for (auto& [key, slope_map_y] : slope_map) {
            for (auto& [dy, points_x] : slope_map_y) {
                if (points_x.size() < 2) continue;
                for (int i = 0; i < points_x.size() - 1; ++i) {
                    for (int j = i + 1; j < points_x.size(); ++j) {
                        double x1 = points_x[i].first, y1 = points_x[i].second;
                        double x2 = points_x[j].first, y2 = points_x[j].second;
                        double area = abs(x1 * y2 - x2 * y1);
                        min_area = min(min_area, area);
                    }
                }
            }
        }
        return min_area == numeric_limits<double>::max()? 0 : min_area;
    }
};