/**https://leetcode.com/problems/largest-submatrix-with-rearrangements/ */
//You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
//Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.
// 
//Example 1:
//Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
//Output: 4
//Explanation: You can rearrange the columns as shown above.
//The largest submatrix of 1s, in bold, has an area of 4.
//Example 2:
//Input: matrix = [[1,0,1,0,1]]
//Output: 3
//Explanation: You can rearrange the columns as shown above.
//The largest submatrix of 1s, in bold, has an area of 3.
//Example 3:
//Input: matrix = [[1,1,0],[1,0,1]]
//Output: 2
//Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m * n <= 105
//	matrix[i][j] is either 0 or 1.
/**
 * @param {number[][]} matrix
 * @return {number}
 */
var largestSubmatrix = function(matrix) {
    const m = matrix.length, n = matrix[0].length;
    const heights = Array.from({ length: m }, () => Array(n).fill(0));
    let maxArea = 0;

    for (let j = 0; j < n; j++) {
        for (let i = 0; i < m; i++) {
            heights[i][j] = matrix[i][j] === 1 ? (i === 0 ? 1 : heights[i - 1][j] + 1) : 0;
        }
    }

    for (let i = 0; i < m; i++) {
        const sortedHeights = [...heights[i]].sort((a, b) => b - a);
        for (let j = 0; j < n; j++) {
            maxArea = Math.max(maxArea, sortedHeights[j] * (j + 1));
        }
    }

    return maxArea;    
};