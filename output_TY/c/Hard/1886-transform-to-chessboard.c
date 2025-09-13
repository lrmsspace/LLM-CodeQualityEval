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
int movesToChessboard(int** board, int boardSize, int* boardColSize){
    int n = boardSize;
    int row_sum[n], col_sum[n], row_cnt[n], col_cnt[n];
    memset(row_sum, 0, sizeof(row_sum));
    memset(col_sum, 0, sizeof(col_sum));
    memset(row_cnt, 0, sizeof(row_cnt));
    memset(col_cnt, 0, sizeof(col_cnt));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            row_sum[i] += board[i][j];
            col_sum[j] += board[i][j];
            row_cnt[i] += board[i][j] == i % 2;
            col_cnt[j] += board[i][j] == j % 2;
        }
    }
    return (row_sum[0] == row_sum[n - 1] && col_sum[0] == col_sum[n - 1] && row_cnt[0] == row_cnt[n - 1] && col_cnt[0] == col_cnt[n - 1]) ? 1 : 2;
}