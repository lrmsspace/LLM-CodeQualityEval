/**https://leetcode.com/problems/minimum-area-rectangle-ii/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
//Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: points = [[1,2],[2,1],[1,0],[0,1]]
//Output: 2.00000
//Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
//Example 2:
//Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
//Output: 1.00000
//Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
//Example 3:
//Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
//Output: 0
//Explanation: There is no possible rectangle to form from these points.
// 
//Constraints:
//	1 <= points.length <= 50
//	points[i].length == 2
//	0 <= xi, yi <= 4 * 104
//	All the given points are unique.
/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaFreeRect = function(points) {
    const map = new Map();
    const set = new Set();
    
    for (let [x, y] of points) {
        map.set(x, (map.get(x) || 0) + 1);
        set.add(y);
    }
    
    let minArea = Infinity;
    const dy = [0, 1, 0, -1];
    const dx = [1, 0, -1, 0];
    
    for (let [x, y] of points) {
        for (let i = 0; i < 4; i++) {
            const dyi = y + dy[i];
            const dxi = x + dx[i];
            
            if (set.has(dyi) && map.has(dxi)) {
                const area = Math.abs(dxi - x) * Math.abs(dyi - y);
                
                if (area < minArea) {
                    minArea = area;
                }
            }
        }
    }
    
    return minArea === Infinity? 0 : minArea.toFixed(5);
    
};