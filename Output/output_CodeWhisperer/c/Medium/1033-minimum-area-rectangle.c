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
int minAreaRect(int** points, int pointsSize, int* pointsColSize) {
    int minArea = INT_MAX;
    int n = pointsSize;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    int x4 = points[l][0], y4 = points[l][1];
                    if ((x1 == x2 && y1 == y3) && (x2 == x4 && y2 == y4) && (x3 == x4 && y3 == y1)) {
                        int area = abs(x1 - x2) * abs(y1 - y3);
                        minArea = min(minArea, area);
                    }
                }
            }
        }
    }
    return minArea == INT_MAX ? 0 : minArea;
}