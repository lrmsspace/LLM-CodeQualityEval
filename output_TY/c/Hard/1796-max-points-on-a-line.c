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
int maxPoints(int** points, int pointsSize, int* pointsColSize){
    if (pointsSize < 3) return pointsSize;
    int max = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            int same = 0;
            int diff = 0;
            for (int k = 0; k < pointsSize; k++) {
                if (k == i || k == j) continue;
                int dx = points[j][0] - points[i][0];
            }
        }
    }
    return max;
}