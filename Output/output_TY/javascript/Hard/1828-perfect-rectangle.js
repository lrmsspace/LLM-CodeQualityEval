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
    let xMin = Number.MAX_SAFE_INTEGER;
    let xMax = Number.MIN_SAFE_INTEGER;
    let yMin = Number.MAX_SAFE_INTEGER;
    let yMax = Number.MIN_SAFE_INTEGER;
    let area = 0;
    let map = {};
    for (let i = 0; i < rectangles.length; i++) {
        let [x1, y1, x2, y2] = rectangles[i];
        xMin = Math.min(xMin, x1);
        xMax = Math.max(xMax, x2);
        yMin = Math.min(yMin, y1);
        yMax = Math.max(yMax, y2);
    }
    for (let i = 0; i < rectangles.length; i++) {
        let [x1, y1, x2, y2] = rectangles[i];
        let key = x1 + ',' + y1 + ',' + x2 + ',' + y2;
        if (map[key]) {
            map[key]++;
        } else {
            map[key] = 1;
        }
    }
    for (let i = 0; i < rectangles.length; i++) {
        let [x1, y1, x2, y2] = rectangles[i];
        let key = x1 + ',' + y1 + ',' + x2 + ',' + y2;
        if (map[key] !== 1) {
            return false;
        }
    }
    return true;
};