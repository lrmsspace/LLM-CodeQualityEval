/**https://leetcode.com/problems/largest-triangle-area/ */
//Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
//Output: 2.00000
//Explanation: The five points are shown in the above figure. The red triangle is the largest.
//Example 2:
//Input: points = [[1,0],[0,0],[0,1]]
//Output: 0.50000
// 
//Constraints:
//	3 <= points.length <= 50
//	-50 <= xi, yi <= 50
//	All the given points are unique.
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    int i, j, k;
    double maxArea = 0;
    for (i = 0; i < pointsSize - 2; i++) {
        for (j = i + 1; j < pointsSize - 1; j++) {
            for (k = j + 1; k < pointsSize; k++) {
                double a = points[i][0] * (points[j][1] - points[k][1])+ points[j][0] * (points[k][1] - points[i][1])
                + points[k][0] * (points[i][1] - points[j][1]);
                maxArea = fmax(maxArea, fabs(a) / 2);
                if (maxArea == 1) return maxArea;
                if (maxArea > 1) return maxArea;
                if (maxArea < 0.0000000001) return maxArea;
                continue;
            }
        }
    }
}