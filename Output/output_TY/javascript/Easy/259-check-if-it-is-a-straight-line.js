/**https://leetcode.com/problems/check-if-it-is-a-straight-line/ */
//You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
// 
// 
//Example 1:
//Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
//Output: true
//Example 2:
//Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
//Output: false
// 
//Constraints:
//	2 <= coordinates.length <= 1000
//	coordinates[i].length == 2
//	-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
//	coordinates contains no duplicate point.
/**
 * @param {number[][]} coordinates
 * @return {boolean}
 */
var checkStraightLine = function(coordinates) {
    let [x1, y1] = coordinates[0];
    let [x2, y2] = coordinates[1];
    let m = (y2 - y1) / (x2 - x1);
    for (let i = 2; i < coordinates.length; i++) {
        let [x, y] = coordinates[i];
        if (m * (x - x1) !== y - y1) return false;
    }
    return true;
};