/*
 You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
 Each of the two resulting sections formed by the cut is non-empty.
 The sum of the elements in both sections is equal.
 Return true if such a partition exists; otherwise return false.
 Example 1:
 Input: grid = [[1,4],[2,3]]
 Output: true
 Explanation:
 A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.
 Example 2:
 Input: grid = [[1,3],[2,4]]
 Output: false
 Explanation:
 No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.
 Constraints:
 1 <= m == grid.length <= 105
 1 <= n == grid[i].length <= 105
 2 <= m * n <= 105
 1 <= grid[i][j] <= 105
*/

/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var canPartitionGrid = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    let totalSum = 0;

    // Calculate the total sum of the grid
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            totalSum += grid[i][j];
        }
    }

    // If the total sum is odd, we cannot partition it into two equal parts
    if (totalSum % 2 !== 0) {
        return false;
    }

    const targetSum = totalSum / 2;

    // Check horizontal cuts
    let rowSum = 0;
    for (let i = 0; i < m - 1; i++) {
        for (let j = 0; j < n; j++) {
            rowSum += grid[i][j];
        }
        if (rowSum === targetSum) {
            return true;
        }
    }

    // Check vertical cuts
    let colSum = new Array(n).fill(0);
    for (let j = 0; j < n; j++) {
        for (let i = 0; i < m; i++) {
            colSum[j] += grid[i][j];
        }
    }

    let currentColSum = 0;
    for (let j = 0; j < n - 1; j++) {
        currentColSum += colSum[j];
        if (currentColSum === targetSum) {
            return true;
        }
    }

    return false;
        
};