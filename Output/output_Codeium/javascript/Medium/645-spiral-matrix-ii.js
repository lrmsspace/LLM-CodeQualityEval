/**https://leetcode.com/problems/spiral-matrix-ii/ */
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// 
//Example 1:
//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= n <= 20
/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    let matrix = Array(n).fill(0).map(() => Array(n).fill(0));
    let num = 1;
    let directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    let direction = 0;
    let row = 0, col = 0;
    while (num <= n * n) {
        matrix[row][col] = num++;
        let newRow = row + directions[direction][0];
        let newCol = col + directions[direction][1];
        if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || matrix[newRow][newCol] !== 0) {
            direction = (direction + 1) % 4;
        }
        row += directions[direction][0];
        col += directions[direction][1];
    }
    return matrix;
};