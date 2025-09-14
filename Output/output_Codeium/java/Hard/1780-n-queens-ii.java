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
class Solution {
    public int totalNQueens(int n) {
        int count = 0;
        boolean[] cols = new boolean[n];
        boolean[] mainDiagonal = new boolean[2 * n - 1];
        boolean[] antiDiagonal = new boolean[2 * n - 1];
        dfs(0, cols, mainDiagonal, antiDiagonal, n, count);
        return count;
    }

    private void dfs(int row, boolean[] cols, boolean[] mainDiagonal, boolean[] antiDiagonal, int n, int count) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || mainDiagonal[row + col] || antiDiagonal[row - col + n - 1]) continue;
            cols[col] = mainDiagonal[row + col] = antiDiagonal[row - col + n - 1] = true;
            dfs(row + 1, cols, mainDiagonal, antiDiagonal, n, count);
            cols[col] = mainDiagonal[row + col] = antiDiagonal[row - col + n - 1] = false;
        }
    }
}