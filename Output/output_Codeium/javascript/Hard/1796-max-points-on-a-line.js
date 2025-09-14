/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
// 
//Example 1:
//Input: points = [[1,1],[2,2],[3,3]]
//Output: 3
//Example 2:
//Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
// 
//Constraints:
//	1 <= points.length <= 300
//	points[i].length == 2
//	-104 <= xi, yi <= 104
//	All the points are unique.
/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
    let max = 0;
    for (let i = 0; i < points.length; i++) {
        let map = {};
        let same = 1;
        let localMax = 0;
        for (let j = i + 1; j < points.length; j++) {
            let slope = getSlape(points[i], points[j]);
            if (slope == 'same') {
                same++;
            } else {
                map[slope] = (map[slope] || 0) + 1;
                localMax = Math.max(localMax, map[slope]);
            }
        }
        max = Math.max(max, localMax + same);
    }
    return max;

    function getSlape(point1, point2) {
        let x1 = point1[0];
        let y1 = point1[1];
        let x2 = point2[0];
        let y2 = point2[1];
        if (x1 === x2) {
            return 'same';
        }
        let slope = (y2 - y1) / (x2 - x1);
        slope = slope.toFixed(5);
        return slope;
    }
};