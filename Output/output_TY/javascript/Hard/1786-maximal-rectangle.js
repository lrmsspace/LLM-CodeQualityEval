/**https://leetcode.com/problems/maximal-rectangle/ */
//Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// 
//Example 1:
//Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//Output: 6
//Explanation: The maximal rectangle is shown in the above picture.
//Example 2:
//Input: matrix = [["0"]]
//Output: 0
//Example 3:
//Input: matrix = [["1"]]
//Output: 1
// 
//Constraints:
//	rows == matrix.length
//	cols == matrix[i].length
//	1 <= row, cols <= 200
//	matrix[i][j] is '0' or '1'.
/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(matrix) {
    let maxArea = 0;
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            if (matrix[i][j] === "1") {
                let width = 1;
                let height = 1;
                let k = i;
                while (k > 0 && matrix[k - 1][j] === "1") {
                    k--;
                    height++;
                }
                let l = j;
                while (l > 0 && matrix[i][l - 1] === "1") {
                    l--;
                    width++;
                }
            }
        }
    }
    return maxArea;

};