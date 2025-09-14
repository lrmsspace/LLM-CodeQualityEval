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
    const n = points.length;
    let minArea = Infinity;
    const pointSet = new Set(points.map(point => point.join(',')));

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const x1 = points[i][0], y1 = points[i][1];
            const x2 = points[j][0], y2 = points[j][1];
            const midX = (x1 + x2) / 2;
            const midY = (y1 + y2) / 2;

            const dx = (x2 - x1) / 2;
            const dy = (y2 - y1) / 2;

            const p3 = [midX - dy, midY + dx];
            const p4 = [midX + dy, midY - dx];

            if (pointSet.has(p3.join(',')) && pointSet.has(p4.join(','))) {
                const area = Math.abs(dx * dy * 4);
                minArea = Math.min(minArea, area);
            }
        }
    }

    return minArea === Infinity ? 0 : minArea;    
};