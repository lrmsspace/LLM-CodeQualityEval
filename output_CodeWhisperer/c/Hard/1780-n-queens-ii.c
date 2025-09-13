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
    int* column = (int*)malloc(sizeof(int) * n);
    int* left = (int*)malloc(sizeof(int) * (2 * n - 1));
    int* right = (int*)malloc(sizeof(int) * (2 * n - 1));
    for (int i = 0; i < n; i++) {
        column[i] = 0;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        left[i] = 0;
        right[i] = 0;
    }
    int result = 0;
    dfs(n, 0, column, left, right, &result);
    return result;

    
}