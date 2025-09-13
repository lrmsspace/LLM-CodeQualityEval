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
    let m = matrix.length, n = matrix[0].length;
    let height = new Array(n).fill(0);
    let result = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === '1') height[j]++;
            else height[j] = 0;
        }
        let stack = [-1];
        for (let j = 0; j < n; j++) {
            while (height[stack[stack.length - 1]] > height[j]) {
                let h = height[stack.pop()];
                let w = j - stack[stack.length - 1] - 1;
                result = Math.max(result, h * w);
            }
            stack.push(j);
        }
        while (stack[stack.length - 1] !== -1) {
            let h = height[stack.pop()];
            let w = n - stack[stack.length - 1] - 1;
            result = Math.max(result, h * w);
        }
    }
    return result;
};