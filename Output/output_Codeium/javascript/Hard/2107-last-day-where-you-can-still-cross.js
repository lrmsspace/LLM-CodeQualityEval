/**https://leetcode.com/problems/last-day-where-you-can-still-cross/ */
//There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
//Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
//You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
//Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.
// 
//Example 1:
//Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
//Output: 2
//Explanation: The above image depicts how the matrix changes each day starting from day 0.
//The last day where it is possible to cross from top to bottom is on day 2.
//Example 2:
//Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
//Output: 1
//Explanation: The above image depicts how the matrix changes each day starting from day 0.
//The last day where it is possible to cross from top to bottom is on day 1.
//Example 3:
//Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
//Output: 3
//Explanation: The above image depicts how the matrix changes each day starting from day 0.
//The last day where it is possible to cross from top to bottom is on day 3.
// 
//Constraints:
//	2 <= row, col <= 2 * 104
//	4 <= row * col <= 2 * 104
//	cells.length == row * col
//	1 <= ri <= row
//	1 <= ci <= col
//	All the values of cells are unique.
/**
 * @param {number} row
 * @param {number} col
 * @param {number[][]} cells
 * @return {number}
 */
var latestDayToCross = function(row, col, cells) {
    let matrix = Array(row).fill(0).map(() => Array(col).fill(0));
    for (let i = 0; i < cells.length; i++) {
        matrix[cells[i][0] - 1][cells[i][1] - 1] = 1;
        if (canCross(matrix)) {
            return i;
        }
    }
    return cells.length - 1;

    function canCross(matrix) {
        let visited = Array(row).fill(0).map(() => Array(col).fill(false));
        for (let i = 0; i < col; i++) {
            if (matrix[0][i] === 0 && canCrossHelper(matrix, 0, i, visited)) {
                return true;
            }
        }
        return false;
    }

    function canCrossHelper(matrix, r, c, visited) {
        if (r === row - 1) {
            return true;
        }
        if (visited[r][c] || matrix[r][c] === 1) {
            return false;
        }
        visited[r][c] = true;
        for (let i = -1; i <= 1; i++) {
            for (let j = -1; j <= 1; j++) {
                if (i === 0 && j === 0) continue;
                if (canCrossHelper(matrix, r + i, c + j, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};