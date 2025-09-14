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
/**
 * @param {number[][]} points
 * @return {number}
 */
var largestTriangleArea = function(points) {
    let maxArea = 0;
    for (let i = 0; i < points.length; i++) {
        for (let j = i + 1; j < points.length; j++) {
            for (let k = j + 1; k < points.length; k++) {
                const x1 = points[i][0], y1 = points[i][1];
                const x2 = points[j][0], y2 = points[j][1];
                const x3 = points[k][0], y3 = points[k][1];
                const area = Math.abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
                maxArea = Math.max(maxArea, area);
            }
        }
    }

    return maxArea;
};