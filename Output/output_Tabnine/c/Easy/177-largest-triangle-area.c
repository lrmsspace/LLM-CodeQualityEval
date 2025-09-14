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
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double area = 0;
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                double side1 = distance(points[i], points[j]);
                double side2 = distance(points[i], points[k]);
                double side3 = distance(points[j], points[k]);
                double s = (side1 + side2 + side3) / 2;
                area = fmax(area, sqrt(s * (s - side1) * (s - side2) * (s - side3)));
            }
        }
    }
    return area;
}