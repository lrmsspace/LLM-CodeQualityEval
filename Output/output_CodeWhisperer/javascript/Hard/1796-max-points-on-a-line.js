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
    if (points.length <= 2) {
        return points.length;
    }
    let max = 2;
    for (let i = 0; i < points.length; i++) {
        let map = new Map();
        for (let j = i + 1; j < points.length; j++) {
            let [x1, y1] = points[i];
            let [x2, y2] = points[j];
            let slope = (y2 - y1) / (x2 - x1);
            let intercept = y1 - slope * x1;
            let key = `${slope},${intercept}`;
            map.set(key, (map.get(key) || 1) + 1);
            max = Math.max(max, map.get(key));
        }
    }
    return max;
};