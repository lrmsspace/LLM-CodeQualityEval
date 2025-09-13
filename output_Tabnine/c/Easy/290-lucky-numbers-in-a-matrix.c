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
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* luckyNumbersArr = malloc(matrixSize * sizeof(int));
    *returnSize = 0;
    
    for (int i = 0; i < matrixSize; i++) {
        int minInRow = matrix[i][0];
        int maxInCol = matrix[0][i];
        
        for (int j = 1; j < matrixColSize[i]; j++) {
            if (matrix[i][j] < minInRow) minInRow = matrix[i][j];
        }
        
        for (int j = 0; j < matrixSize; j++) {
            if (matrix[j][i] > maxInCol) maxInCol = matrix[j][i];
        }
        
        if (minInRow == maxInCol) luckyNumbersArr[(*returnSize)++] = minInRow;
    }
    
    return luckyNumbersArr;
    
}