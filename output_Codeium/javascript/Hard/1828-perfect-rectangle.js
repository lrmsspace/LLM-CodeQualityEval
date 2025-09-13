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
    let area = 0;
    let x1 = Infinity;
    let y1 = Infinity;
    let x2 = -Infinity;
    let y2 = -Infinity;
    let set = new Set();
    
    for (let rect of rectangles) {
        const [xi, yi, ai, bi] = rect;
        const currArea = (ai - xi) * (bi - yi);
        area += currArea;
        if (!set.has(`${xi},${yi}`)) set.add(`${xi},${yi}`);
        if (!set.has(`${ai},${bi}`)) set.add(`${ai},${bi}`);
        if (!set.has(`${xi},${bi}`)) set.add(`${xi},${bi}`);
        if (!set.has(`${ai},${yi}`)) set.add(`${ai},${yi}`);
        x1 = Math.min(x1, xi);
        y1 = Math.min(y1, yi);
        x2 = Math.max(x2, ai);
        y2 = Math.max(y2, bi);
    }
    
    if (set.size !== 4 || area !== (x2 - x1) * (y2 - y1)) return false;
    return true;
};