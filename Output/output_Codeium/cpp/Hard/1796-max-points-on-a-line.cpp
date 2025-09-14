/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
// 
//Example 1:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 3
//Example 2:
//Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
// 
//Constraints:
//	1 <= points.length <= 300
//	points[i].length == 2
//	-104 <= xi, yi <= 104
//	All the points are unique.
class Solution {
public:
int maxPoints(vector<vector<int>>& points) {
    if (points.size() <= 2) return points.size();
    int max_points = 0;
    for (int i = 0; i < points.size(); ++i) {
        unordered_map<double, int> slope_count;
        int duplicate = 1;
        for (int j = i + 1; j < points.size(); ++j) {
            if (points[i] == points[j]) {
                ++duplicate;
            } else {
                double slope = (points[j][1] - points[i][1]) == 0 ? 
                    std::numeric_limits<double>::infinity() : 
                    static_cast<double>(points[j][0] - points[i][0]) / (points[j][1] - points[i][1]);
                ++slope_count[slope];
            }
        }
        int current_max = duplicate;
        for (const auto& pair : slope_count) {
            current_max = max(current_max, pair.second + duplicate);
        }
        max_points = max(max_points, current_max);
    }
    return max_points;
}   

};