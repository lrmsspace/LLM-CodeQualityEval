/**https://leetcode.com/problems/maximal-square/ */
//Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
// 
//Example 1:
//Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//Output: 4
//Example 2:
//Input: matrix = [["0","1"],["1","0"]]
//Output: 1
//Example 3:
//Input: matrix = [["0"]]
//Output: 0
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 300
//	matrix[i][j] is '0' or '1'.
/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalSquare = function(matrix) {
    let max = 0;
    for(let i=0;i<matrix.length;i++){
        for(let j=0;j<matrix[i].length;j++){
            if(matrix[i][j]==='1'){
                let k=1;
                while(i+k<matrix.length && j+k<matrix[i].length && matrix[i+k][j]==='1' && matrix[i][j+k]==='1'){
                    k++;
                }
                max = Math.max(max,k);
            }
        }
    }
    return max*max;
};