/*
 Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
 grid[0][0]
 an equal frequency of 'X' and 'Y'.
 at least one 'X'.
 Example 1:
 Input: grid = [["X","Y","."],["Y",".","."]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [["X","X"],["X","Y"]]
 Output: 0
 Explanation:
 No submatrix has an equal frequency of 'X' and 'Y'.
 Example 3:
 Input: grid = [[".","."],[".","."]]
 Output: 0
 Explanation:
 No submatrix has at least one 'X'.
 Constraints:
 1 <= grid.length, grid[i].length <= 1000
 grid[i][j] is either 'X', 'Y', or '.'.
*/

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numberOfSubmatrices = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let dp = Array.from({length: m+1}, () => Array(n+1).fill(0));
    let count = Array.from({length: 26}, () => Array(m*n+1).fill(0));
    
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            count[grid[i-1].charCodeAt(j-1) - 'A'][dp[i][j]]++;
        }
    }   
    let ans = 0;    
    for (let left = 1; left <= n; left++) {
        for (let right = left; right <= n; right++) {
            let freq = {};
            for (let k = 0; k < 26; k++) {
                freq[k] = count[k][right] - count[k][left-1];
            }
            for (let i = 0; i < m*n; i++) {
                if (freq[grid[0].charCodeAt(0) - 'A'] === freq[grid[0].charCodeAt(1) - 'A'] && freq[grid[0].charCodeAt(0) - 'A'] > 0) {
                    ans += freq[grid[0].charCodeAt(0) - 'A'];
                }
            }
        }
    }
    return ans;
    
};