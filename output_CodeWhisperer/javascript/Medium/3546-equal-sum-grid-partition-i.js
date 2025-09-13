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
    let sum = 0;
    for(let i = 0; i < m; i++) {
        for(let j = 0; j < n; j++) {
            sum += grid[i][j];
        }
    }
    if(sum % 2 !== 0) return false;
    const target = sum / 2;
    const memo = new Map();
    const dfs = (i, j, sum) => {
        if(i >= m || j >= n) return false;
        if(i === m - 1 && j === n - 1) return sum === target;
        const key = `${i}-${j}-${sum}`;
        if(memo.has(key)) return memo.get(key);
        const result = dfs(i + 1, j, sum + grid[i][j]) || dfs(i, j + 1, sum + grid[i][j]);
        memo.set(key, result);
        return result;
    }
    return dfs(0, 0, 0);    
};