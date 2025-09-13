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
    const colorCount = new Array(61).fill(0);
    const colorBounds = new Array(61).fill(0).map(() => [m, n, -1, -1]);
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const color = targetGrid[i][j];
            colorCount[color]++;
            colorBounds[color][0] = Math.min(colorBounds[color][0], i);
            colorBounds[color][1] = Math.min(colorBounds[color][1], j);
            colorBounds[color][2] = Math.max(colorBounds[color][2], i);
            colorBounds[color][3] = Math.max(colorBounds[color][3], j);
        }
    }
    
    const visited = new Array(61).fill(false);
    
    function canPrint(color) {
        if (visited[color]) return true;
        visited[color] = true;
        
        const [top, left, bottom, right] = colorBounds[color];
        
        for (let i = top; i <= bottom; i++) {
            for (let j = left; j <= right; j++) {
                if (targetGrid[i][j] !== color) {
                    return false;
                }
            }
        }
        
        for (let i = top; i <= bottom; i++) {
            for (let j = left; j <= right; j++) {
                const nextColor = targetGrid[i][j];
                if (!visited[nextColor]) {
                    if (!canPrint(nextColor)) return false;
                }
            }
        }
        
        return true;
    }
    
    for (let color = 1; color <= 60; color++) {
        if (colorCount[color] > 0 && !canPrint(color)) {
            return false;
        }
    }
    
    return true;    
};