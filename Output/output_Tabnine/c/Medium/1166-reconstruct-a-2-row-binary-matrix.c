/**https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/ */
//Given the following details of a matrix with n columns and 2 rows :
//	The matrix is a binary matrix, which means each element in the matrix can be 0 or 1.
//	The sum of elements of the 0-th(upper) row is given as upper.
//	The sum of elements of the 1-st(lower) row is given as lower.
//	The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum is given as an integer array with length n.
//Your task is to reconstruct the matrix with upper, lower and colsum.
//Return it as a 2-D integer array.
//If there are more than one valid solution, any of them will be accepted.
//If no valid solution exists, return an empty 2-D array.
// 
//Example 1:
//Input: upper = 2, lower = 1, colsum = [1,1,1]
//Output: [[1,1,0],[0,0,1]]
//Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct answers.
//Example 2:
//Input: upper = 2, lower = 3, colsum = [2,2,1,1]
//Output: []
//Example 3:
//Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
//Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
// 
//Constraints:
//	1 <= colsum.length <= 10^5
//	0 <= upper, lower <= colsum.length
//	0 <= colsum[i] <= 2
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructMatrix(int upper, int lower, int* colsum, int colsumSize, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(2 * sizeof(int*));
    *returnSize = 2;
    result[0] = malloc(colsumSize * sizeof(int));
    result[1] = malloc(colsumSize * sizeof(int));
    *returnColumnSizes = malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = colsumSize;
    (*returnColumnSizes)[1] = colsumSize;
    
    int sum = upper + lower;
    int left = 0;
    int right = colsumSize - 1;
    for (int i = 0; i < colsumSize; i++) {
        if (colsum[i] == 2) {
            result[0][left] = result[1][right] = 1;
            left++;
            right--;
        } else if (colsum[i] == 1) {
            if (upper > lower) {
                result[0][left] = 1;
                upper--;
                left++;
            } else {
                result[1][right] = 1;
                lower--;
                right--;
            }
        }
    }
    
    if (sum!= upper + lower) {
        free(result[0]);
        free(result[1]);
        free(result);
        free(*returnColumnSizes);
        *returnSize = 0;
        return NULL;
    }
    
    return result;
    
}