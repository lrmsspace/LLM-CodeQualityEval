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
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        res[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            res[top][i] = num++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            res[i][right] = num++;
        }
        right--;
        for (int i = right; i >= left; i--) {
            res[bottom][i] = num++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--) {
            res[i][left] = num++;
        }
        left++;
    }
    *returnSize = n;
    return res;    
}