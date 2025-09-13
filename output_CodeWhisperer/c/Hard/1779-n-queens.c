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
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    char*** result = (char***)malloc(sizeof(char**) * 1000);
    int* board = (int*)malloc(sizeof(int) * n);
    int i, j;
    for (i = 0; i < n; i++) {
        board[i] = -1;
    }
    int* row = (int*)malloc(sizeof(int) * n);
    int* col = (int*)malloc(sizeof(int) * n);
    int* diag1 = (int*)malloc(sizeof(int) * (2 * n - 1));
    int* diag2 = (int*)malloc(sizeof(int) * (2 * n - 1));
    for (i = 0; i < n; i++) {
        row[i] = col[i] = diag1[i] = diag2[i] = 0;
    }
    for (i = 0; i < n / 2; i++) {
        row[0] = col[i] = diag1[i] = diag2[n - 1 - i] = 1;
        board[0] = i;
        solveNQueensHelper(board, n, 1, row, col, diag1, diag2, returnSize, returnColumnSizes, result);
        row[0] = col[i] = diag1[i] = diag2[n - 1 - i] = 0;
    }
    if (n % 2 == 1) {
        row[0] = col[n / 2] = diag1[n / 2] = diag2[n - 1 - n / 2] = 1;
        board[0] = n / 2;
        solveNQueensHelper(board, n, 1, row, col, diag1, diag2, returnSize, returnColumnSizes, result);
        row[0] = col[n / 2] = diag1[n / 2] = diag2[n - 1 - n / 2] = 0;
    }
    free(board);
    free(row);
    free(col);
    free(diag1);
    free(diag2);
    return result;
    
}