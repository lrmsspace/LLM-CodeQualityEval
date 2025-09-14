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
    char*** solutions = (char***)malloc(0);
    *returnColumnSizes = NULL;
    
    // Helper function to check if a queen can be placed
    bool isSafe(int row, int col, int* queens) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == col || queens[i] - i == col - row || queens[i] + i == col + row) {
                return false;
            }
        }
        return true;
    }
    
    // Helper function to solve N-Queens using backtracking
    void solve(int row, int n, int* queens, char*** solutions, int* returnSize, int** returnColumnSizes) {
        if (row == n) {
            (*returnSize)++;
            solutions = (char***)realloc(solutions, (*returnSize) * sizeof(char**));
            solutions[*returnSize - 1] = (char**)malloc(n * sizeof(char*));
            for (int i = 0; i < n; i++) {
                solutions[*returnSize - 1][i] = (char*)malloc((n + 1) * sizeof(char));
                for (int j = 0; j < n; j++) {
                    solutions[*returnSize - 1][i][j] = (queens[i] == j) ? 'Q' : '.';
                }
                solutions[*returnSize - 1][i][n] = '\0';
            }
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize) * sizeof(int));
            (*returnColumnSizes)[*returnSize - 1] = n;
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, queens)) {
                queens[row] = col;
                solve(row + 1, n, queens, solutions, returnSize, returnColumnSizes);
            }
        }
    }
    
    int* queens = (int*)malloc(n * sizeof(int));
    solve(0, n, queens, solutions, returnSize, returnColumnSizes);
    free(queens);
    return solutions;
}   