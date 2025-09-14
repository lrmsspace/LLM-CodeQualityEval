/**https://leetcode.com/problems/minimum-area-rectangle/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
// 
//Example 1:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
//Output: 4
//Example 2:
//Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
//Output: 2
// 
//Constraints:
//	1 <= points.length <= 500
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaRect = function(points) {
    let map = new Map();
    let minArea = Number.MAX_SAFE_INTEGER;
    
    // Build a map from x-coordinates to a set of y-coordinates
    for (let [x, y] of points) {
        map.set(x, (map.get(x) || new Set()).add(y));
    }
    
    for (let [x1, ys1] of map) {
        for (let y1 of ys1) {
            for (let y2 of ys1) {
                if (y1 > y2) {
                    let x2 = points.find(([x, y]) => y === y1 && x > x1)[0];
                    if (x2) {
                        minArea = Math.min(minArea, (x2 - x1) * (y1 - y2));
                    }
                }
            }
        }
    }
    
    return minArea === Number.MAX_SAFE_INTEGER? 0 : minArea;
    
};