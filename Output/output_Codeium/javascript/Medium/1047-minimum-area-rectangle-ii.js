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
    let minArea = Infinity;
    for (let i = 0; i < points.length; i++) {
        for (let j = i + 1; j < points.length; j++) {
            for (let k = j + 1; k < points.length; k++) {
                for (let l = k + 1; l < points.length; l++) {
                    const [x1, y1] = points[i];
                    const [x2, y2] = points[j];
                    const [x3, y3] = points[k];
                    const [x4, y4] = points[l];
                    if (x1 + x4 === x2 + x3 && y1 + y4 === y2 + y3) {
                        const dx = Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
                        const dy = Math.sqrt(Math.pow(x1 - x4, 2) + Math.pow(y1 - y4, 2));
                        minArea = Math.min(minArea, dx * dy);
                    }
                }
            }
        }
    }
    return minArea === Infinity ? 0 : minArea;
};