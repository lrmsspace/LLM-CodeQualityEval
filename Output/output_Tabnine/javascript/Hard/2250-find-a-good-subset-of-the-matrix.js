/**https://leetcode.com/problems/find-a-good-subset-of-the-matrix/ */
//You are given a 0-indexed m x n binary matrix grid.
//Let us call a non-empty subset of rows good if the sum of each column of the subset is at most half of the length of the subset.
//More formally, if the length of the chosen subset of rows is k, then the sum of each column should be at most floor(k / 2).
//Return an integer array that contains row indices of a good subset sorted in ascending order.
//If there are multiple good subsets, you can return any of them. If there are no good subsets, return an empty array.
//A subset of rows of the matrix grid is any matrix that can be obtained by deleting some (possibly none or all) rows from grid.
// 
//Example 1:
//Input: grid = [[0,1,1,0],[0,0,0,1],[1,1,1,1]]
//Output: [0,1]
//Explanation: We can choose the 0th and 1st rows to create a good subset of rows.
//The length of the chosen subset is 2.
//- The sum of the 0th column is 0 + 0 = 0, which is at most half of the length of the subset.
//- The sum of the 1st column is 1 + 0 = 1, which is at most half of the length of the subset.
//- The sum of the 2nd column is 1 + 0 = 1, which is at most half of the length of the subset.
//- The sum of the 3rd column is 0 + 1 = 1, which is at most half of the length of the subset.
//Example 2:
//Input: grid = [[0]]
//Output: [0]
//Explanation: We can choose the 0th row to create a good subset of rows.
//The length of the chosen subset is 1.
//- The sum of the 0th column is 0, which is at most half of the length of the subset.
//Example 3:
//Input: grid = [[1,1,1],[1,1,1]]
//Output: []
//Explanation: It is impossible to choose any subset of rows to create a good subset.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m <= 104
//	1 <= n <= 5
//	grid[i][j] is either 0 or 1.
/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var goodSubsetofBinaryMatrix = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    
    const dp = Array.from({length: m + 1}, () => Array(1 << n).fill(false));
    dp[0][0] = true;
    
    for (let i = 1; i <= m; i++) {
        for (let j = 0; j < 1 << n; j++) {
            if (dp[i - 1][j]) {
                for (let k = 0; k < n; k++) {
                    if ((j & (1 << k)) === 0 && grid[i - 1][k] === 1) {
                        dp[i][j | (1 << k)] = true;
                    }
                }
            }
        }
    }
    
    let maxLen = 0;
    for (let i = 0; i < 1 << n; i++) {
        if (__builtin_popcount(i) > maxLen && dp[m][i]) {
            maxLen = __builtin_popcount(i);
        }
    }
    
    if (maxLen === 0) {
        return [];
    }
    
    const result = [];
    for (let i = m - 1; i >= 0; i--) {
        for (let j = 0; j < 1 << n; j++) {
            if (dp[i][j] && __builtin_popcount(j) === maxLen) {
                for (let k = 0; k < n; k++) {
                    if ((j & (1 << k))!== 0 && grid[i][k] === 1) {
                        result.push(i);
                        break;
                    }
                }
                break;
            }
        }
    }
    
    return result.sort((a, b) => a - b);
    
};