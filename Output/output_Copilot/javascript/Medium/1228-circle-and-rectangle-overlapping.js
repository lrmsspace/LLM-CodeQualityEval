/**https://leetcode.com/problems/circle-and-rectangle-overlapping/ */
//You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.
//Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.
// 
//Example 1:
//Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
//Output: true
//Explanation: Circle and rectangle share the point (1,0).
//Example 2:
//Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
//Output: false
//Example 3:
//Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
//Output: true
// 
//Constraints:
//	1 <= radius <= 2000
//	-104 <= xCenter, yCenter <= 104
//	-104 <= x1 < x2 <= 104
//	-104 <= y1 < y2 <= 104
/**
 * @param {number} radius
 * @param {number} xCenter
 * @param {number} yCenter
 * @param {number} x1
 * @param {number} y1
 * @param {number} x2
 * @param {number} y2
 * @return {boolean}
 */
var checkOverlap = function(radius, xCenter, yCenter, x1, y1, x2, y2) {
    // Check if the circle's center is inside the rectangle
    if (xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2) {
        return true;
    }

    // Check if the circle's center is outside the rectangle
    if (xCenter < x1 || xCenter > x2 || yCenter < y1 || yCenter > y2) {
        // Calculate the distance from the circle's center to the rectangle's edges
        let dx = Math.max(x1 - xCenter, 0, xCenter - x2);
        let dy = Math.max(y1 - yCenter, 0, yCenter - y2);
        // Check if the distance is less than or equal to the radius
        return dx * dx + dy * dy <= radius * radius;
    }
    return false;    
};