/**https://leetcode.com/problems/domino-and-tromino-tiling/ */
//You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
//Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.
//In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.
// 
//Example 1:
//Input: n = 3
//Output: 5
//Explanation: The five different ways are show above.
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 1000
/**
 * @param {number} n
 * @return {number}
 */
var numTilings = function(n) {
    let dp = [0, 1, 2, 5];
    for(let i = 4; i <= n; i++){
        dp[i % 4] = (dp[(i - 1) % 4] + dp[(i - 2) % 4] + dp[(i - 3) % 4] * 2) % 1000000007;
    }
    return dp[n % 4];
};