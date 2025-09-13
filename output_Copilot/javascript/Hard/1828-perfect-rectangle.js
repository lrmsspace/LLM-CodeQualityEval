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
    let x1 = Infinity, y1 = Infinity, x2 = -Infinity, y2 = -Infinity;
    const points = new Set();
    
    for (const [x1r, y1r, x2r, y2r] of rectangles) {
        area += (x2r - x1r) * (y2r - y1r);
        x1 = Math.min(x1, x1r);
        y1 = Math.min(y1, y1r);
        x2 = Math.max(x2, x2r);
        y2 = Math.max(y2, y2r);
        
        const corners = [
            `${x1r},${y1r}`, `${x1r},${y2r}`, `${x2r},${y1r}`, `${x2r},${y2r}`
        ];
        
        for (const corner of corners) {
            if (points.has(corner)) {
                points.delete(corner);
            } else {
                points.add(corner);
            }
        }
    }
    
    if (points.size !== 4) return false;
    
    const expectedCorners = new Set([
        `${x1},${y1}`, `${x1},${y2}`, `${x2},${y1}`, `${x2},${y2}`
    ]);
    
    for (const point of points) {
        if (!expectedCorners.has(point)) return false;
    }
    
    return area === (x2 - x1) * (y2 - y1);    
};