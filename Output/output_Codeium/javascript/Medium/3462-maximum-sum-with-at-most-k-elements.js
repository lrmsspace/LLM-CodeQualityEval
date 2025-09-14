/*
 You are given a 2D integer matrix grid of size n x m, an integer array limits of length n, and an integer k. The task is to find the maximum sum of at most k elements from the matrix grid such that:
 The number of elements taken from the ith row of grid does not exceed limits[i].
 Return the maximum sum.
 Example 1:
 Input: grid = [[1,2],[3,4]], limits = [1,2], k = 2
 Output: 7
 Explanation:
 From the second row, we can take at most 2 elements. The elements taken are 4 and 3.
 The maximum possible sum of at most 2 selected elements is 4 + 3 = 7.
 Example 2:
 Input: grid = [[5,3,7],[8,2,6]], limits = [2,2], k = 3
 Output: 21
 Explanation:
 From the first row, we can take at most 2 elements. The element taken is 7.
 From the second row, we can take at most 2 elements. The elements taken are 8 and 6.
 The maximum possible sum of at most 3 selected elements is 7 + 8 + 6 = 21.
 Constraints:
 n == grid.length == limits.length
 m == grid[i].length
 1 <= n, m <= 500
 0 <= grid[i][j] <= 105
 0 <= limits[i] <= m
 0 <= k <= min(n * m, sum(limits))
*/

/**
 * @param {number[][]} grid
 * @param {number[]} limits
 * @param {number} k
 * @return {number}
 */
var maxSum = function(grid, limits, k) {
    let rowSum = new Array(grid.length).fill(0);
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            rowSum[i] += grid[i][j];
        }
    }
    let dp = new Array(k + 1).fill(0).map(() => new Array(limits.length + 1).fill(0));
    for (let i = 1; i <= k; i++) {
        for (let j = 1; j <= limits.length; j++) {
            let maxCur = 0;
            for (let m = 0; m <= limits[j - 1] && m <= i; m++) {
                maxCur = Math.max(maxCur, dp[i - m][j - 1] + rowSum[j - 1] * m);
            }
            dp[i][j] = Math.max(dp[i][j - 1], maxCur);
        }
    }
    return dp[k][limits.length];
};