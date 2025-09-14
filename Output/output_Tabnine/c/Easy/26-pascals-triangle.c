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
    if (numRows == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int** triangle = malloc(numRows * sizeof(int*));
    *returnSize = numRows;  
    *returnColumnSizes = malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        triangle[i] = malloc((i + 1) * sizeof(int));
        triangle[i][0] = triangle[i][i] = 1;
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle; 
}