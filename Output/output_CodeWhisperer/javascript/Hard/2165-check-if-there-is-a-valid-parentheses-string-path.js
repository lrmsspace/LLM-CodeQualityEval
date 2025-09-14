/**https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/ */
//A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
//	It is ().
//	It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
//	It can be written as (A), where A is a valid parentheses string.
//You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:
//	The path starts from the upper left cell (0, 0).
//	The path ends at the bottom-right cell (m - 1, n - 1).
//	The path only ever moves down or right.
//	The resulting parentheses string formed by the path is valid.
//Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.
// 
//Example 1:
//Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
//Output: true
//Explanation: The above diagram shows two possible paths that form valid parentheses strings.
//The first path shown results in the valid parentheses string "()(())".
//The second path shown results in the valid parentheses string "((()))".
//Note that there may be other valid parentheses string paths.
//Example 2:
//Input: grid = [[")",")"],["(","("]]
//Output: false
//Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 100
//	grid[i][j] is either '(' or ')'.
/**
 * @param {character[][]} grid
 * @return {boolean}
 */
var hasValidPath = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(' || (m + n - 1) % 2 == 1) return false;
    let dp = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0).map(() => new Set()));
    dp[0][0].add(0);
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            let c = grid[i][j] == '(' ? 1 : -1;
            for (let k of dp[i][j]) {
                if (k + c >= 0) dp[i + 1][j + 1].add(k + c);
                if (k + c - 1 >= 0) dp[i][j + 1].add(k + c - 1);
            }
        }
    }
    return dp[m][n - 1].has(0);
};