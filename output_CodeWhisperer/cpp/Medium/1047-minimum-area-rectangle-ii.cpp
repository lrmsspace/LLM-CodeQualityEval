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
                    int x1 = points[j][0] - points[i][0];
                    int y1 = points[j][1] - points[i][1];
                    int x2 = points[k][0] - points[i][0];
                    int y2 = points[k][1] - points[i][1];
                    if (x1 * x2 + y1 * y2 == 0) {
                        for (int l = 0; l < n; l++) {
                            if (l != i && l != j && l != k) {
                                int x3 = points[l][0] - points[i][0];
                                int y3 = points[l][1] - points[i][1];
                                if (x3 * x2 + y3 * y2 == 0 && x1 * x3 + y1 * y3 == 0) {
                                    double area = sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2);
                                    res = min(res, area);
                                }
                            }
                        }
                    }
                }
            }
        }
        return res == 1e9 ? 0 : res;      
    }
};