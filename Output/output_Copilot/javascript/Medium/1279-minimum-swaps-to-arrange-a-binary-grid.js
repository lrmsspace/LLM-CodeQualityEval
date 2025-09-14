/**https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/ */
//Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
//A grid is said to be valid if all the cells above the main diagonal are zeros.
//Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
//The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
// 
//Example 1:
//Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
//Output: 3
//Example 2:
//Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
//Output: -1
//Explanation: All rows are similar, swaps have no effect on the grid.
//Example 3:
//Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
//Output: 0
// 
//Constraints:
//	n == grid.length == grid[i].length
//	1 <= n <= 200
//	grid[i][j] is either 0 or 1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minSwaps = function(grid) {
    let n = grid.length, ans = 0, zeros = Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        for (let j = n - 1; j >= 0; j--) {
            if (grid[i][j] === 0) zeros[i]++;
            else break;
        }
    }
    for (let i = 0; i < n; i++) {
        let cnt = 0;
        for (let j = i; j < n; j++) {
            if (zeros[j] < n - i) cnt++;
        }
        if (cnt === 0) continue;
        ans += cnt;
        if (ans > n) return -1;
    }
    return ans;    
};