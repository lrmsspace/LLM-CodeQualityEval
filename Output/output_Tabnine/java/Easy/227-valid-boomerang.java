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
class Solution {
    public boolean isBoomerang(int[][] points) {
        int x1 = points[0][0];
        int y1 = points[0][1];
        int x2 = points[1][0];
        int y2 = points[1][1];
        int x3 = points[2][0];
        int y3 = points[2][1];
        
        // Calculate the slope of the line connecting the first two points
        double slope1 = (double)(y2 - y1) / (x2 - x1);
        
        // Calculate the slope of the line connecting the first point and the third point
        double slope2 = (double)(y3 - y1) / (x3 - x1);
        
        // If the slopes are equal, the points are not on a distinct line
        return slope1!= slope2;
        
    }
}