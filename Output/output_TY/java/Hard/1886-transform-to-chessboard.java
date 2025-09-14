/**https://leetcode.com/problems/transform-to-chessboard/ */
//You are given an n x n binary grid board. In each move, you can swap any two rows with each other, or any two columns with each other.
//Return the minimum number of moves to transform the board into a chessboard board. If the task is impossible, return -1.
//A chessboard board is a board where no 0's and no 1's are 4-directionally adjacent.
// 
//Example 1:
//Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
//Output: 2
//Explanation: One potential sequence of moves is shown.
//The first move swaps the first and second column.
//The second move swaps the second and third row.
//Example 2:
//Input: board = [[0,1],[1,0]]
//Output: 0
//Explanation: Also note that the board with 0 in the top left corner, is also a valid chessboard.
//Example 3:
//Input: board = [[1,0],[1,0]]
//Output: -1
//Explanation: No matter what sequence of moves you make, you cannot end with a valid chessboard.
// 
//Constraints:
//	n == board.length
//	n == board[i].length
//	2 <= n <= 30
//	board[i][j] is either 0 or 1.
class Solution {
    public int movesToChessboard(int[][] board) {
        int n = board.length;
        int row0 = 0, col0 = 0;
        for (int i = 0; i < n; i++) {
            row0 += board[0][i] == i % 2 ? 1 : 0;
            col0 += board[i][0] == i % 2 ? 1 : 0;
        }
        if (row0 % n != 0 || col0 % n != 0 || Math.abs(row0 - (n - row0)) > n / 2 || Math.abs(col0 - (n - col0)) > n / 2) return -1;
        int row1 = 0, col1 = 0;
        for (int i = 0; i < n; i++) {
            row1 += board[i][0] == i % 2 ? 1 : 0;
        } 
        for (int i = 0; i < n; i++) {
            col1 += board[0][i] == i % 2 ? 1 : 0;
        }
        return Math.abs(row1 - (n - row1)) + Math.abs(col1 - (n - col1));
    }
}