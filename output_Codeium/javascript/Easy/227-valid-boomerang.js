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
/**
 * @param {number[][]} points
 * @return {boolean}
 */
var isBoomerang = function(points) {
    const [p1, p2, p3] = points;
    const [x1, y1] = p1;
    const [x2, y2] = p2;
    const [x3, y3] = p3;

    // Check if all points are distinct
    if ((x1 === x2 && y1 === y2) || (x1 === x3 && y1 === y3) || (x2 === x3 && y2 === y3)) {
        return false;
    }

    // Check if the points are not in a straight line using the slope formula
    // Slope of p1p2 != Slope of p1p3
    return (y2 - y1) * (x3 - x1) !== (y3 - y1) * (x2 - x1);
};