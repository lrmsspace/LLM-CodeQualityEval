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
    let maxX = 0, maxY = 0;
    let minX = Number.MAX_SAFE_INTEGER, minY = Number.MAX_SAFE_INTEGER;
    let maxColor = 0;
    for (let i = 0; i < targetGrid.length; i++) {
        for (let j = 0; j < targetGrid[i].length; j++) {
            maxX = Math.max(maxX, j);
            maxY = Math.max(maxY, i);
            minX = Math.min(minX, j);
            minY = Math.min(minY, i);
            maxColor = Math.max(maxColor, targetGrid[i][j]);
        }
    }
    let dp = new Array(maxColor + 1).fill(0).map(() => new Array(maxY + 1).fill(0).map(() => new Array(maxX + 1).fill(0)));
    for (let color = 1; color <= maxColor; color++) {
        for (let y = 0; y <= maxY; y++) {
            for (let x = 0; x <= maxX; x++) {
                if (targetGrid[y][x] === color) {
                    dp[color][y][x] = Math.min(dp[color - 1][y][x - 1] || Infinity, dp[color - 1][y][x]|| Infinity, dp[color - 1][y][x + 1])
                }
            }
        }
    }
    return dp[maxColor][maxY][maxX] + 1;
};