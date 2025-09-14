/**https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/ */
//You are given a 0-indexed m x n integer matrix grid. The width of a column is the maximum length of its integers.
//	For example, if grid = [[-10], [3], [12]], the width of the only column is 3 since -10 is of length 3.
//Return an integer array ans of size n where ans[i] is the width of the ith column.
//The length of an integer x with len digits is equal to len if x is non-negative, and len + 1 otherwise.
// 
//Example 1:
//Input: grid = [[1],[22],[333]]
//Output: [3]
//Explanation: In the 0th column, 333 is of length 3.
//Example 2:
//Input: grid = [[-15,1,3],[15,7,12],[5,6,-2]]
//Output: [3,1,2]
//Explanation: 
//In the 0th column, only -15 is of length 3.
//In the 1st column, all integers are of length 1. 
//In the 2nd column, both 12 and -2 are of length 2.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 100 
//	-109 <= grid[r][c] <= 109
/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var findColumnWidth = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const maxDigits = Array(n).fill(0);
    const ans = Array(n).fill(0);
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const num = grid[i][j];
            const digits = Math.floor(Math.log10(Math.abs(num)) + 1);
            maxDigits[j] = Math.max(maxDigits[j], digits);
        }
    }
    
    for (let j = 0; j < n; j++) {
        ans[j] = Math.pow(10, maxDigits[j]) - Math.pow(10, maxDigits[j] - 1);
    }
    
    return ans;
    
};