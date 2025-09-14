/**https://leetcode.com/problems/n-queens/ */
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
// 
//Example 1:
//Input: n = 4
//Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
//Example 2:
//Input: n = 1
//Output: [["Q"]]
// 
//Constraints:
//	1 <= n <= 9
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int* queens = (int*)malloc(sizeof(int) * n);
    char*** result = (char***)malloc(sizeof(char**) * 100);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 100);
    int* columnSizes = *returnColumnSizes;
    int* column = (int*)malloc(sizeof(int) * n);
    int* left = (int*)malloc(sizeof(int) * 2 * n);
    int* right = (int*)malloc(sizeof(int) * 2 * n);
    for (int i = 0; i < 2 * n; i++) {
        left[i] = 0;
        right[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        queens[i] = -1;
    }
    int i = 0;
    while (i >= 0) {
        if (i == n) {
            result[*returnSize] = (char**)malloc(sizeof(char*) * n);
            for (int j = 0; j < n; j++) {
                result[*returnSize][j] = (char*)malloc(sizeof(char) * (n + 1));
                for (int k = 0; k < n; k++) {
                    result[*returnSize][j][k] = '.';
                }
                result[*returnSize][j][queens[j]] = 'Q';
                result[*returnSize][j][n] = '\0';
            }
            columnSizes[*returnSize] = n;
            (*returnSize)++;
            i--;
            continue;
        }
        int j = queens[i] + 1;
        for (; j < n; j++) {
            if (column[j] == 0 && left[i + j] == 0 && right[i - j + n] == 0) {
                queens[i] = j;
                column[j] = 1;
                left[i + j] = 1;
                right[i - j + n] = 1;
                i++;
                break;
            }
        }
        if (j == n) {
            queens[i] = -1;
            i--;
        }
    }
    free(queens);
    free(column);
    free(left);
    free(right);
    return result;    
}