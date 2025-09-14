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
int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize == 1) {
        return 1;
    }
    int max = 0;
    for (int i = 0; i < pointsSize; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        for (int j = i + 1; j < pointsSize; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            int count = 0;
            for (int k = 0; k < pointsSize; k++) {
                int x3 = points[k][0];
                int y3 = points[k][1];
                if ((x1 - x2) * (y1 - y3) == (x1 - x3) * (y1 - y2)) {
                    count++;
                }
            }
            if (count > max) {
                max = count;
            }
        }
    }
    return max;    
}