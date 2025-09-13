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
    int rowSum = 0, colSum = 0, rowSwap = 0, colSwap = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) != 0) {
                return -1;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        rowSum += board[i][0];
        colSum += board[0][i];
        if (board[i][0] == i % 2) rowSwap++;
        if (board[0][i] == i % 2) colSwap++;
    }
    
    if (rowSum != n / 2 && rowSum != (n + 1) / 2) return -1;
    if (colSum != n / 2 && colSum != (n + 1) / 2) return -1;
    
    if (n % 2 == 0) {
        rowSwap = n / 2 - rowSwap < rowSwap ? n / 2 - rowSwap : rowSwap;
        colSwap = n / 2 - colSwap < colSwap ? n / 2 - colSwap : colSwap;
    } else {
        if (rowSwap % 2 != 0) rowSwap = n - rowSwap;
        if (colSwap % 2 != 0) colSwap = n - colSwap;
    }
    
    return (rowSwap + colSwap) / 2;
}
    
    