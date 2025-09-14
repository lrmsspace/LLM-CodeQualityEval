/**https://leetcode.com/problems/perfect-rectangle/ */
//Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
//Return true if all the rectangles together form an exact cover of a rectangular region.
// 
//Example 1:
//Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
//Output: true
//Explanation: All 5 rectangles together form an exact cover of a rectangular region.
//Example 2:
//Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
//Output: false
//Explanation: Because there is a gap between the two rectangular regions.
//Example 3:
//Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
//Output: false
//Explanation: Because two of the rectangles overlap with each other.
// 
//Constraints:
//	1 <= rectangles.length <= 2 * 104
//	rectangles[i].length == 4
//	-105 <= xi < ai <= 105
//	-105 <= yi < bi <= 105
/**
 * @param {number[][]} rectangles
 * @return {boolean}
 */
var isRectangleCover = function(rectangles) {
    let area = 0, minX = Number.MAX_SAFE_INTEGER, minY = Number.MAX_SAFE_INTEGER, maxX = Number.MIN_SAFE_INTEGER, maxY = Number.MIN_SAFE_INTEGER;
    let corners = new Set();
    for (let rect of rectangles) {
        minX = Math.min(minX, rect[0]);
        minY = Math.min(minY, rect[1]);
        maxX = Math.max(maxX, rect[2]);
        maxY = Math.max(maxY, rect[3]);
        area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
        let corner1 = rect[0] + " " + rect[1];
        let corner2 = rect[0] + " " + rect[3];
        let corner3 = rect[2] + " " + rect[3];
        let corner4 = rect[2] + " " + rect[1];
        if (corners.has(corner1)) corners.delete(corner1);
        else corners.add(corner1);
        if (corners.has(corner2)) corners.delete(corner2);
        else corners.add(corner2);
        if (corners.has(corner3)) corners.delete(corner3);
        else corners.add(corner3);
        if (corners.has(corner4)) corners.delete(corner4);
        else corners.add(corner4);
    }
    if (corners.has(minX + " " + minY) && corners.has(minX + " " + maxY) && corners.has(maxX + " " + minY) && corners.has(maxX + " " + maxY) && corners.size === 4) {
        return area === (maxX - minX) * (maxY - minY);
    }
    return false;
};