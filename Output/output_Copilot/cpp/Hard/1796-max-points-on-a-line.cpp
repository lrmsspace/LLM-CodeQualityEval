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
        int n = points.size();
        if (n <= 2) return n;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (res >= n - i || res > n / 2) break;
            unordered_map<double, int> map;
            for (int j = i + 1; j < n; j++) {
                double k = (points[j][0] == points[i][0]) ? DBL_MAX : (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                map[k]++;
            }
            for (auto& p : map) {
                res = max(res, p.second + 1);
            }
        }
        return res;        
    }
};