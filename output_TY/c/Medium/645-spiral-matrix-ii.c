/**https://leetcode.com/problems/spiral-matrix-ii/ */
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// 
//Example 1:
//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= n <= 20
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int** matrix = malloc(n * sizeof(int*));
    *returnColumnSizes = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }
    int i = 0, j = 0, k = 0;
    int left = 0, right = n - 1, top = 0, bottom =

        n - 1;
        while (k < n * n) {
            while (j <= right) {
                matrix[i][j++] = ++k;
            }
            j--;
            i++;
            top++;
            while (i <= bottom) {
                matrix[i++][j] = ++k;
            }
            i--;
            j--;
            right--;
            while (j >= left) {
                matrix[i][j--] = ++k;
           }
        }
        j++;
        i--;
        bottom--;
        while (i >= top) {
            matrix[i--][j] = ++k;
        }
        return matrix;
}