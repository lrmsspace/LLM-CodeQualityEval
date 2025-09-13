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
    let n = darts.length;
    let ans = 1;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            let [x1, y1] = darts[i];
            let [x2, y2] = darts[j];
            let dx = x2 - x1;
            let dy = y2 - y1;
            let d = Math.sqrt(dx * dx + dy * dy);
            if (d > 2 * r) continue;
            let midX = (x1 + x2) / 2;
            let midY = (y1 + y2) / 2;
            let h = Math.sqrt(r * r - d * d / 4);
            let centerX = midX + h * (y1 - y2) / d;
            let centerY = midY - h * (x1 - x2) / d;
            let count = 0;
            for (let k = 0; k < n; k++) {
                let [x, y] = darts[k];
                let dx = x - centerX;
                let dy = y - centerY;
                let d = Math.sqrt(dx * dx + dy * dy);
                if (d <= r) count++;
            }
            ans = Math.max(ans, count);
        }
    }
    return ans;  
};