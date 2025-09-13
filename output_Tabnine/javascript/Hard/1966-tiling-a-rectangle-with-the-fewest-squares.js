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
    // Initialize a 2D array dp[i][j] to store the minimum number of squares needed to tile rectangle of size i x j
    const dp = Array(n + 1).fill().map(() => Array(m + 1).fill(0));
    
    // Iterate over possible values of i and j from 1 to n and m
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            // Initialize the minimum number of squares to cover the rectangle as the maximum possible value
            dp[i][j] = Math.max(i, j);
            
            // Iterate over possible values of k from 1 to Math.min(i, j)
            for (let k = 1; k <= Math.min(i, j); k++) {
                // Update the minimum number of squares needed to cover the rectangle
                dp[i][j] = Math.min(dp[i][j], dp[i - k][k] + dp[k][j - k] + 1);
            }
        }
    }
    
    // Return the minimum number of squares needed to cover the rectangle of size n x m
    return dp[n][m];
    
};