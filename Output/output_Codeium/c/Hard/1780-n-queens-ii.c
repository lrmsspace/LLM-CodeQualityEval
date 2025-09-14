/**https://leetcode.com/problems/n-queens-ii/ */
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return the number of distinct solutions to the n-queens puzzle.
// 
//Example 1:
//Input: n = 4
//Output: 2
//Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 9
int totalNQueens(int n) {
    int result = 0;
    int *columns = (int*)malloc(n * sizeof(int));
    int *mainDiagonal = (int*)malloc((2 * n - 1) * sizeof(int));
    int *antiDiagonal = (int*)malloc((2 * n - 1) * sizeof(int));
    memset(columns, 0, n * sizeof(int));
    memset(mainDiagonal, 0, (2 * n - 1) * sizeof(int));
    memset(antiDiagonal, 0, (2 * n - 1) * sizeof(int));
    backtrack(n, 0, columns, mainDiagonal, antiDiagonal, &result);
    free(columns);
    free(mainDiagonal);
    free(antiDiagonal);
    return result;
    
}