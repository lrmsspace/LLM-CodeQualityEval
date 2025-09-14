/**https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/ */
//Given a rectangular pizza represented as a rows x cols matrix containing the following characters: 'A' (an apple) and '.' (empty cell) and given the integer k. You have to cut the pizza into k pieces using k-1 cuts. 
//For each cut you choose the direction: vertical or horizontal, then you choose a cut position at the cell boundary and cut the pizza into two pieces. If you cut the pizza vertically, give the left part of the pizza to a person. If you cut the pizza horizontally, give the upper part of the pizza to a person. Give the last piece of pizza to the last person.
//Return the number of ways of cutting the pizza such that each piece contains at least one apple. Since the answer can be a huge number, return this modulo 10^9 + 7.
// 
//Example 1:
//Input: pizza = ["A..","AAA","..."], k = 3
//Output: 3 
//Explanation: The figure above shows the three ways to cut the pizza. Note that pieces must contain at least one apple.
//Example 2:
//Input: pizza = ["A..","AA.","..."], k = 3
//Output: 1
//Example 3:
//Input: pizza = ["A..","A..","..."], k = 1
//Output: 1
// 
//Constraints:
//	1 <= rows, cols <= 50
//	rows == pizza.length
//	cols == pizza[i].length
//	1 <= k <= 10
//	pizza consists of characters 'A' and '.' only.
/**
 * @param {string[]} pizza
 * @param {number} k
 * @return {number}
 */
var ways = function(pizza, k) {
    const MOD = 1000000007;
    const m = pizza.length;
    const n = pizza[0].length;
    const apples = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    const dp = new Array(k).fill(0).map(() => new Array(m).fill(0).map(() => new Array(n).fill(0)));
    for (let r = m - 1; r >= 0; r--) {
        for (let c = n - 1; c >= 0; c--) {
            apples[r][c] = (pizza[r][c] == 'A' ? 1 : 0) + apples[r][c + 1] + apples[r + 1][c] - apples[r + 1][c + 1];
            dp[0][r][c] = apples[r][c] > 0 ? 1 : 0;
        }
    }
    for (let remain = 1; remain < k; remain++) {
        for (let r = 0; r < m; r++) {
            for (let c = 0; c < n; c++) {
                for (let nextR = r + 1; nextR < m; nextR++) {
                    if (apples[r][c] > apples[nextR][c]) {
                        dp[remain][r][c] += dp[remain - 1][nextR][c];
                    }
                }
                for (let nextC = c + 1; nextC < n; nextC++) {
                    if (apples[r][c] > apples[r][nextC]) {
                        dp[remain][r][c] += dp[remain - 1][r][nextC];
                    }
                }
                dp[remain][r][c] %= MOD;
            }
        }
    }
    return dp[k - 1][0][0];
};