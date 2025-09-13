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
    const m = targetGrid.length;
    const n = targetGrid[0].length;
    const colors = new Set();
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            colors.add(targetGrid[i][j]);
        }
    }
    const colorMap = new Map();
    for (const color of colors) {
        let minRow = Infinity;
        let minCol = Infinity;
        let maxRow = -Infinity;
        let maxCol = -Infinity;
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (targetGrid[i][j] === color) {
                    minRow = Math.min(minRow, i);
                    minCol = Math.min(minCol, j);
                    maxRow = Math.max(maxRow, i);
                    maxCol = Math.max(maxCol, j);
                }
            }
        }
        colorMap.set(color, [minRow, minCol, maxRow, maxCol]);
    }
    const graph = new Map();
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const color = targetGrid[i][j];
            if (!graph.has(color)) {
                graph.set(color, new Set());
            }
            for (const [otherColor, [minRow, minCol, maxRow, maxCol]] of colorMap) {
                if (otherColor === color) {
                    continue;
                }
                if (i >= minRow && i <= maxRow && j >= minCol && j <= maxCol) {
                    graph.get(color).add(otherColor);
                }
            }
        }
    }
    const visited = new Set();
    const dfs = (color) => {
        if (visited.has(color)) {
            return false;
        }
        visited.add(color);
        for (const otherColor of graph.get(color)) {
            if (!dfs(otherColor)) {
                return false;
            }
        }
        visited.delete(color);
        return true;
    };
    for (const color of colors) {
        if (!dfs(color)) {
            return false;
        }
    }
    return true;
};