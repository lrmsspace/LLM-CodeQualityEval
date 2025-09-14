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
        int n = points.size();
        double res = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    int x4 = x2 + x3 - x1, y4 = y2 + y3 - y1;
                    if (find(points.begin(), points.end(), vector<int>{x4, y4}) != points.end()) {
                        int a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                        int b = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
                        res = min(res, sqrt(a) * sqrt(b));
                    }
                }
            }
        }
        return res == 1e9 ?        
    }
};