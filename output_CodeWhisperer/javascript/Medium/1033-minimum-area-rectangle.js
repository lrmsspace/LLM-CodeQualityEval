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
    let set = new Set();
    for (let point of points) {
        set.add(point[0] + "," + point[1]);
    }
    let minArea = Number.MAX_SAFE_INTEGER;
    for (let i = 0; i < points.length; i++) {
        for (let j = i + 1; j < points.length; j++) {
            if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                if (set.has(points[i][0] + "," + points[j][1]) && set.has(points[j][0] + "," + points[i][1])) {
                    minArea = Math.min(minArea, Math.abs(points[j][0] - points[i][0]) * Math.abs(points[j][1] - points[i][1]));
                }
            }
        }
    }
    return minArea == Number.MAX_SAFE_INTEGER ? 0 : minArea;
};