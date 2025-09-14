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
    const MOD = 1e9 + 7;
    const m = pizza.length, n = pizza[0].length;
    const apples = Array(m + 1).fill().map(() => Array(n + 1).fill(0));
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            apples[i][j] = (pizza[i][j] === 'A') + apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1];
        }
    }
    const dp = Array(k).fill().map(() => Array(m).fill().map(() => Array(n).fill(-1)));
    const dfs = (k, i, j) => {
        if (k < 0) return Infinity;
        if (i >= m || j >= n) return Infinity;
        if (apples[i][j] <= 0) return Infinity;
        if (i === m - 1 && j === n - 1) return 0;
        if (dp[k][i][j] !== -1) return dp[k][i][j];
        let ans = Infinity;
        for (let x = i; x < m; x++) {
            for (let y = j + 1; y < n; y++) {
                ans = Math.min(ans, dfs(k - 1, x + 1, y) + (apples[x][y] > 0 ? 1 : 0))
            }
        }
    }
    return dfs(k, 0, 0) === Infinity ? -1 : dfs(k, 0, 0);
};