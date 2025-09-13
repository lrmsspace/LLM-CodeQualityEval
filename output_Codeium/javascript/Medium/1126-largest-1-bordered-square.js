/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 9
//Example 2:
//Input: grid = [[1,1,0,0]]
//Output: 1
// 
//Constraints:
//	1 <= grid.length <= 100
//	1 <= grid[0].length <= 100
//	grid[i][j] is 0 or 1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var largest1BorderedSquare = function(grid) {
    let maxLen = 0;
    const m = grid.length;
    const n = grid[0].length;
    const left = Array.from({length: m}, () => new Array(n).fill(0));
    const right = Array.from({length: m}, () => new Array(n).fill(0));
    const top = Array.from({length: m}, () => new Array(n).fill(0));
    const bottom = Array.from({length: m}, () => new Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 1) {
                left[i][j] = j === 0 ? 1 : left[i][j - 1] + 1;
                top[i][j] = i === 0 ? 1 : top[i - 1][j] + 1;
            }
        }
    }

    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            if (grid[i][j] === 1) {
                right[i][j] = j === n - 1 ? 1 : right[i][j + 1] + 1;
                bottom[i][j] = i === m - 1 ? 1 : bottom[i + 1][j] + 1;
            }
        }
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            maxLen = Math.max(maxLen, Math.min(left[i][j], right[i][j], top[i][j], bottom[i][j]));
        }
    }

    return maxLen * maxLen;
};