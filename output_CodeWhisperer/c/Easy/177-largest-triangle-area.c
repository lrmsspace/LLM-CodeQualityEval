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
    double maxArea = 0.0;
    
    // Try all possible combinations of three points
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                // Calculate the area of the triangle formed by points i, j, and k
                double area = triangleArea(
                    points[i][0], points[i][1],
                    points[j][0], points[j][1],
                    points[k][0], points[k][1]
                );
                
                // Update maxArea if the current triangle has a larger area
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }
    
    return maxArea;
}   
