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
double minAreaFreeRect(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    double min_area = DBL_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    int x4 = points[l][0], y4 = points[l][1];
                    double area = fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
                    if (area == 0) continue;
                    double cx = (x1 + x2 + x3 + x4) / 4.0;
                    double cy = (y1 + y2 + y3 + y4) / 4.0;
                    double dx = cx - x1, dy = cy - y1;
                    if (fabs((x2 - x1) * dx + (y2 - y1) * dy) > 1e-6) continue;
                    if (fabs((x3 - x1) * dx + (y3 - y1) * dy) > 1e-6) continue;
                    if (fabs((x4 - x1) * dx + (y4 - y1) * dy) > 1e-6) continue;
                    min_area = fmin(min_area, area);
                }
            }
        }
    }
    return min_area == DBL_MAX ? 0 : min_area;
}