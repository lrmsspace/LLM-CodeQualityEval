/**https://leetcode.com/problems/diagonal-traverse/ */
//Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,4,7,5,3,6,8,9]
//Example 2:
//Input: mat = [[1,2],[3,4]]
//Output: [1,2,3,4]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	-105 <= mat[i][j] <= 105
/**
 * @param {number[][]} mat
 * @return {number[]}
 */
var findDiagonalOrder = function(mat) {
    let row = mat.length;
    let col = mat[0].length;
    let result = [];
    let i = 0;
    let j = 0;
    let k = 0;
    let flag = true;
    while(k < row * col){
        result.push(mat[i][j]);
        if(flag){
            if(j === col - 1){
                i++;
                flag = false;
            }else if(i === 0){
                j++;
                flag = false;
            }else{
                i--;
                j++;
            }
        }else{
            if(i === row -1){
                j++;
                flag = true;
            }else if(j === 0){
                i++;
                flag = true;
            }else{
                i++;
                j--;
            }
        }
    }
    return result;
};