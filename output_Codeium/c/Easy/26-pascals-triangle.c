/**https://leetcode.com/problems/pascals-triangle/ */
//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// 
//Example 1:
//Input: numRows = 5
//Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//Example 2:
//Input: numRows = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= numRows <= 30
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    int** result = (int**)malloc(*returnSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = i + 1;
        result[i] = (int*)malloc((*returnColumnSizes)[i] * sizeof(int));
        result[i][0] = 1;
        result[i][(*returnColumnSizes)[i] - 1] = 1;
        if (i > 1) {
            for (int j = 1; j < (*returnColumnSizes)[i] - 1; ++j) {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
    }
    return result;
}