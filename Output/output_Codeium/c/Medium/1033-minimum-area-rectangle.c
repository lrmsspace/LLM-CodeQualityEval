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
    int x[50000] = {0}, y[50000] = {0};
    int area = INT_MAX;
    for (int i = 0; i < pointsSize; i++) {
        x[points[i][0]] = 1;
        y[points[i][1]] = 1;
    }
    for (int i = 0; i < pointsSize; i++) {
        for (int j = 0; j < pointsSize; j++) {
            if (i != j && x[points[j][0]] && y[points[j][1]]) {
                area = min(area, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
            }
        }
    }
    return area == INT_MAX ? 0 : area;
}