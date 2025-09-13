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

    // Check if the board is valid
    int rowSum = 0, colSum = 0;

    for (int i = 0; i < n; i++) {
        rowSum += board[0][i];
        colSum += board[i][0];

        for (int j = 1; j < n; j++) {
            if (board[i][j] != board[i][0] || board[j][i] != board[0][i]) {
                return -1;
            }
        }
    }

    if (rowSum != n / 2 && rowSum != (n + 1) / 2) {
        return -1;
    }

    if (colSum != n / 2 && colSum != (n + 1) / 2) {
        return -1;
    }


    // Calculate the minimum number of moves
    int rowDiff = 0, colDiff = 0;
    int rowOneCount = 0, colOneCount = 0;

    for (int i = 0; i < n; i++) {
        if (board[0][i] == i % 2) {
            rowDiff++;
        }

        if (board[i][0] == i % 2) {
            colDiff++;
        }

        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                rowOneCount++;
                colOneCount++;
            }
        }
    }

    rowDiff = n - rowDiff;

    if (rowDiff % 2 != 0) {
        return -1;
    }

    colDiff = n - colDiff;

    if (colDiff % 2 != 0) {
        return -1;
    }

    rowOneCount = n * n / 2 - rowOneCount;

    if (rowOneCount % 2 != 0) {
        return -1;
    }

    colOneCount = n * n / 2 - colOneCount;
    if (colOneCount % 2 != 0) {
        return -1;
    }

    return (rowDiff + colDiff) / 2 + (rowOneCount + colOneCount) / 2;
}