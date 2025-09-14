/**https://leetcode.com/problems/valid-boomerang/ */
//Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, return true if these points are a boomerang.
//A boomerang is a set of three points that are all distinct and not in a straight line.
// 
//Example 1:
//Input: points = [[1,1],[2,3],[3,2]]
//Output: true
//Example 2:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: false
// 
//Constraints:
//	points.length == 3
//	points[i].length == 2
//	0 <= xi, yi <= 100
bool isBoomerang(int** points, int pointsSize, int* pointsColSize) {
    int x0 = points[0][0], y0 = points[0][1];
    int x1 = points[1][0], y1 = points[1][1];
    int x2 = points[2][0], y2 = points[2][1];
    
    return (x1 - x0) * (y2 - y1) != (x2 - x1) * (y1 - y0);
    
}