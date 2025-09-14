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
public:
    bool isBoomerang(vector<vector<int>>& points) {
        double slope1 = (points[1][1] - points[0][1]) / (points[1][0] - points[0][0]);
        double slope2 = (points[2][1] - points[1][1]) / (points[2][0] - points[1][0]);
        return slope1!= slope2; // If the slopes are different, the points are not in a straight line. Otherwise, they are.  // O(1) time complexity, O(1) space complexity.  // This solution uses the slope formula to calculate the slope of the two line segments connecting the three points. If the slopes are different, the points are not in a straight line. Otherwise, they are.  // This solution uses the slope formula to calculate the
        
    }
};