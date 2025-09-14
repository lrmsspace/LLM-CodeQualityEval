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
int movesToChessboard(int** board, int boardSize, int* boardColSize) {

    int n = boardSize;
    int moves = 0;
    int rowSum = 0, colSum = 0;
    
    for (int i = 0; i < n; i++) {
        rowSum ^= board[0][i];
        colSum ^= board[i][0];
    }
    
    if (rowSum == 0 && colSum == 0) return moves;
    
    if (rowSum == 1) {
        for (int i = 0; i < n; i++) {
            board[0][i] ^= 1;
            moves++;
        }
    }
    
    if (colSum == 1) {
        for (int i = 0; i < n; i++) {
            board[i][0] ^= 1;
            moves++;
        }
    }
    
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]!= board[n - 1 - i][n - 1 - j]) {
                moves++;
                int temp = board[i][j];
                board[i][j] = board[n - 1 - i][n - 1 - j];
                board[n - 1 - i][n - 1 - j] = temp;
            }
        }
    }
    
    return moves == 0? -1 : moves;
    
}