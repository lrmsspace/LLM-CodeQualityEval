/**https://leetcode.com/problems/strange-printer-ii/ */
//There is a strange printer with the following two special requirements:
//	On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
//	Once the printer has used a color for the above operation, the same color cannot be used again.
//You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
//Return true if it is possible to print the matrix targetGrid, otherwise, return false.
// 
//Example 1:
//Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
//Output: true
//Example 2:
//Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
//Output: true
//Example 3:
//Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
//Output: false
//Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.
// 
//Constraints:
//	m == targetGrid.length
//	n == targetGrid[i].length
//	1 <= m, n <= 60
//	1 <= targetGrid[row][col] <= 60
/**
 * @param {number[][]} targetGrid
 * @return {boolean}
 */
var isPrintable = function(targetGrid) {
    const m = targetGrid.length, n = targetGrid[0].length;
    const colorToBox = {};
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const color = targetGrid[i][j];
            if (!colorToBox[color]) colorToBox[color] = [i, j, i, j];
            else {
                colorToBox[color][0] = Math.min(colorToBox[color][0], i);
                colorToBox[color][1] = Math.min(colorToBox[color][1], j);
                colorToBox[color][2] = Math.max(colorToBox[color][2], i);
                colorToBox[color][3] = Math.max(colorToBox[color][3], j);
            }
        }
    }
    const boxes = Object.values(colorToBox).sort((a, b) => a[2] - b[2]);
    const dp = new Array(1 << m).fill(false);
    dp[0] = true;
    for (const box of boxes) {
        const mask = (1 << (box[2] + 1)) - (1 << box[0]);
        for (let i = (1 << m) - 1; i >= 0; i--) {
            if (dp[i]) dp[i | mask] = true;
        }
    }
    return dp[(1 << m) - 1];
};