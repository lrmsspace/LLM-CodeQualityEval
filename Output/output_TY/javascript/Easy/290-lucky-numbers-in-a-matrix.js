/**https://leetcode.com/problems/lucky-numbers-in-a-matrix/ */
//Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
//A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
// 
//Example 1:
//Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
//Output: [15]
//Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
//Example 2:
//Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
//Output: [12]
//Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
//Example 3:
//Input: matrix = [[7,8],[1,2]]
//Output: [7]
//Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= n, m <= 50
//	1 <= matrix[i][j] <= 105.
//	All elements in the matrix are distinct.
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers = function(matrix) {
    let row = matrix.length;
    let col = matrix[0].length;
    let min = [];
    let max = [];
    for(let i=0;i<row;i++){
        min.push(Math.min(...matrix[i]));
    }
    for(let i=0;i<col;i++){
        let temp = [];
        for(let j=0;j<row;j++){
            temp.push(matrix[j][i]);
        }
        max.push(Math.max(...temp));
    }
    let ans = [];
    for(let i=0;i<row;i++){
        for(letj=0;j<col;j++){
            if(matrix[i][j]==min[i]&&matrix[i][j]==max[j]){
                ans.push(matrix[i][j]);
            }
        }
    }
    return ans;
};