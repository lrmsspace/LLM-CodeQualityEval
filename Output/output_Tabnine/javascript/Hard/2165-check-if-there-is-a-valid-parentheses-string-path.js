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
    const m = grid.length;
    const n = grid[0].length;
    const dp = Array.from({length: m}, () => Array.from({length: n}, () => Array(3).fill(false)));
    
    function isValid(x, y, prev) {
        if (x < 0 || x >= m || y < 0 || y >= n) return false;
        
        if (grid[x][y] === ')') {
            if (prev === '(') return true;
            else return dp[x][y][1];
        } else {
            if (prev === ')') return true;
            else return dp[x][y][0];
        }
    }
    
    dp[0][0][0] = true;
    dp[0][0][1] = true;
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === '(') {
                dp[i][j][0] = isValid(i - 1, j, ')') || isValid(i, j - 1, ')');
                dp[i][j][1] = isValid(i - 1, j, '(') || isValid(i, j - 1, '(');
            } else {
                dp[i][j][0] = isValid(i - 1, j, '(') || isValid(i, j - 1, '(');
                dp[i][j][1] = isValid(i - 1, j, ')') || isValid(i, j - 1, ')');
            }
        }
    }
    
    return dp[m - 1][n - 1][0] || dp[m - 1][n - 1][1];
    
};