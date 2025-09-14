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
    const sum = grid.reduce((acc, row) => acc + row.reduce((acc2, num) => acc2 + num, 0), 0);
    if (sum % 2!== 0) return false;
    
    const target = sum / 2;
    const dp = Array(target + 1).fill(false);
    dp[0] = true;
    
    for (let i = 0; i < grid.length; i++) {
        for (let j = target; j >= grid[i][0]; j--) {
            dp[j] = dp[j] || dp[j - grid[i][0]];
        }
    }
    
    return dp[target];  
    
};