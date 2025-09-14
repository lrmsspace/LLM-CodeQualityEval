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
    let minX = Infinity, maxX = -Infinity, minY = Infinity, maxY = -Infinity;
    let totalArea = 0, areaCount = 0;
    const rectMap = new Map();
    
    for (const [x1, y1, x2, y2] of rectangles) {
        minX = Math.min(minX, x1, x2);
        maxX = Math.max(maxX, x1, x2);
        minY = Math.min(minY, y1, y2);
        maxY = Math.max(maxY, y1, y2);
        
        const area = (x2 - x1) * (y2 - y1);
        totalArea += area;
        
        const [key, count] = rectMap.get([x1, y1]) || [null, 0];
        rectMap.set([x1, y1], [key, count + 1]);
        
        const [key2, count2] = rectMap.get([x2, y2]) || [null, 0];
        rectMap.set([x2, y2], [key2, count2 - 1]);
        
        if (count + count2!== 2) {
            return false;
        }

        areaCount += 2;
    }
    
    return totalArea === (maxX - minX) * (maxY - minY) && areaCount === totalArea;
};