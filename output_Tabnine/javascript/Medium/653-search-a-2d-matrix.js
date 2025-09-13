/**https://leetcode.com/problems/search-a-2d-matrix/ */
//You are given an m x n integer matrix matrix with the following two properties:
//	Each row is sorted in non-decreasing order.
//	The first integer of each row is greater than the last integer of the previous row.
//Given an integer target, return true if target is in matrix or false otherwise.
//You must write a solution in O(log(m * n)) time complexity.
// 
//Example 1:
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//Output: true
//Example 2:
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//Output: false
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 100
//	-104 <= matrix[i][j], target <= 104
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    // Find the row index where the target value could be
    const row = matrix.findIndex((row, rowIndex) => row[0] <= target && row[row.length - 1] >= target);
    
    // If the target value is not in the matrix, return false
    if (row === -1) return false;
    
    // Perform binary search on the found row to find the target value
    return binarySearch(matrix[row], target, 0, matrix[row].length - 1);
    
};