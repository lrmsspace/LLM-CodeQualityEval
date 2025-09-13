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
    if (pointsSize <= 2) {
        return pointsSize;
    }
    int max = 2;
    for (int i = 0; i < pointsSize; i++) {
        int* p1 = points[i];
        for (int j = i + 1; j < pointsSize; j++) {
            int* p2 = points[j];
            int count = 2;
            for (int k = j + 1; k < pointsSize; k++) {
                int* p3 = points[k];
                int x1 = p1[0] - p2[0];
                int y1 = p1[1] - p2[1];
                int x2 = p1[0] - p3[0];
                int y2 = p1[1] - p3[1];
                if (x1 * y2 == x2 * y1) {
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