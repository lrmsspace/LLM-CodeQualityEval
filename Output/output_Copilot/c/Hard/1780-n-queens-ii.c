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
    int count = 0;
    int *queen = (int *)malloc(sizeof(int) * n);
    memset(queen, -1, sizeof(int) * n);
    dfs(queen, n, 0, &count);
    free(queen);
    return count;    
}