/**https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/ */
//Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.
// 
//Example 1:
//Input: n = 2, m = 3
//Output: 3
//Explanation: 3 squares are necessary to cover the rectangle.
//2 (squares of 1x1)
//1 (square of 2x2)
//Example 2:
//Input: n = 5, m = 8
//Output: 5
//Example 3:
//Input: n = 11, m = 13
//Output: 6
// 
//Constraints:
//	1 <= n, m <= 13
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var tilingRectangle = function(n, m) {
    const dp = Array.from({length: n + 1}, () => Array(m + 1).fill(Infinity));
    dp[0][0] = 0;
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            for (let k = 1; k <= Math.min(i, j); k++) {
                dp[i][j] = Math.min(dp[i][j], dp[i - k][j] + dp[k][j - k] + 1);
            }
        }
    }
    return dp[n][m];    
};