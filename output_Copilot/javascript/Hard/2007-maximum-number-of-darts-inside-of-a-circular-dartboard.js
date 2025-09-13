/**https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/ */
//Alice is throwing n darts on a very large wall. You are given an array darts where darts[i] = [xi, yi] is the position of the ith dart that Alice threw on the wall.
//Bob knows the positions of the n darts on the wall. He wants to place a dartboard of radius r on the wall so that the maximum number of darts that Alice throws lie on the dartboard.
//Given the integer r, return the maximum number of darts that can lie on the dartboard.
// 
//Example 1:
//Input: darts = [[-2,0],[2,0],[0,2],[0,-2]], r = 2
//Output: 4
//Explanation: Circle dartboard with center in (0,0) and radius = 2 contain all points.
//Example 2:
//Input: darts = [[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]], r = 5
//Output: 5
//Explanation: Circle dartboard with center in (0,4) and radius = 5 contain all points except the point (7,8).
// 
//Constraints:
//	1 <= darts.length <= 100
//	darts[i].length == 2
//	-104 <= xi, yi <= 104
//	All the darts are unique
//	1 <= r <= 5000
/**
 * @param {number[][]} darts
 * @param {number} r
 * @return {number}
 */
var numPoints = function(darts, r) {
    let n = darts.length, ans = 1;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            let x1 = darts[i][0], y1 = darts[i][1], x2 = darts[j][0], y2 = darts[j][1];
            let d = Math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2);
            if (d > 2 * r) continue;
            let h = Math.sqrt(r ** 2 - (d / 2) ** 2);
            let cx = (x1 + x2) / 2, cy = (y1 + y2) / 2;
            let dx = (y1 - y2) * h / d, dy = (x2 - x1) * h / d;
            let center1 = [cx + dx, cy - dy], center2 = [cx - dx, cy + dy];
            ans = Math.max(ans, countDarts(darts, center1, r), countDarts(darts, center2, r));
        }
    }
    return ans;    
};