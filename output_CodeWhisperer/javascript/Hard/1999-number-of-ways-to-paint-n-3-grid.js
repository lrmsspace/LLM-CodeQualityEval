/**https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/ */
//You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
//Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 12
//Explanation: There are 12 possible way to paint the grid as shown.
//Example 2:
//Input: n = 5000
//Output: 30228214
// 
//Constraints:
//	n == grid.length
//	1 <= n <= 5000
/**
 * @param {number} n
 * @return {number}
 */
var numOfWays = function(n) {
    const MOD = 1000000007;
    let a121 = 6, a123 = 6;
    for (let i = 2; i <= n; i++) {
        let b121 = (2 * a121 + 2 * a123) % MOD;
        let b123 = (2 * a121 + 3 * a123) % MOD;
        a121 = b121;
        a123 = b123;
    }
    return (a121 + a123) % MOD;
};