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
    let matrix = [];
    for(let i = 0; i < n; i++){
        matrix.push([]);
        for(let j = 0; j < n; j++){
            matrix[i].push(0);
        }
    }
    let count = 1;
    let row = 0;
    let col = 0;
    while(count <= n * n){
        while(col < n && matrix[row][col] === 0){
            matrix[row][col] = count++;
            col++;
        }
    }
    col--;
    row++;
    while(row < n && matrix[row][col] === 0){
        matrix[row][col] = count++;
        row++;
    }
        row--;
    col--;
    while(col >= 0 && matrix[row][col] === 0){
        matrix[row][col] = count++;
        col--;
    }
    col++;
    row--;
    while(row >= 0 && matrix[row][col] === 0){
        matrix[row][col] = count++;
        row--;
    }
    return matrix;
};