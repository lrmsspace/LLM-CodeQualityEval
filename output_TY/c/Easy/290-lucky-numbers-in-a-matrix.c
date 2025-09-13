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
int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int* res = (int*)malloc(sizeof(int)*matrixSize);
    int* minRow = (int*)malloc(sizeof(int)*matrixSize);
    int* maxCol = (int*)malloc(sizeof(int)*matrixColSize[0]);
    memset(minRow, 0x7f, sizeof(int)*matrixSize);
    memset(maxCol, 0, sizeof(int)*matrixColSize[0]);
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<matrixColSize[0]; j++){
            minRow[i] = min(minRow[i], matrix[i][j]);
            maxCol[j] = max(maxCol[j], matrix[i][j]);
        }
    }
    int count = 0;
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<matrixColSize[0]; j++){
            if(matrix[i][j]==minRow[i] && matrix[i][j]==maxCol[j]){
                res[count++] = matrix[i][j];
            }
        }
    }
    *returnSize = count;
    return res;
}