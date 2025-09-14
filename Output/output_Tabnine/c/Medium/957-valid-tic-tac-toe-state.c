/**https://leetcode.com/problems/valid-tic-tac-toe-state/ */
//Given a Tic-Tac-Toe board as a string array board, return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
//The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The ' ' character represents an empty square.
//Here are the rules of Tic-Tac-Toe:
//	Players take turns placing characters into empty squares ' '.
//	The first player always places 'X' characters, while the second player always places 'O' characters.
//	'X' and 'O' characters are always placed into empty squares, never filled ones.
//	The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
//	The game also ends if all squares are non-empty.
//	No more moves can be played if the game is over.
// 
//Example 1:
//Input: board = ["O  ","   ","   "]
//Output: false
//Explanation: The first player always plays "X".
//Example 2:
//Input: board = ["XOX"," X ","   "]
//Output: false
//Explanation: Players take turns making moves.
//Example 3:
//Input: board = ["XOX","O O","XOX"]
//Output: true
// 
//Constraints:
//	board.length == 3
//	board[i].length == 3
//	board[i][j] is either 'X', 'O', or ' '.
bool validTicTacToe(char** board, int boardSize) {
    int xCount = 0, oCount = 0;
    int rowSum[3] = {0, 0, 0}, colSum[3] = {0, 0, 0}, diagSum = 0, antiDiagSum = 0;
    
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == 'X') {
                xCount++;
                rowSum[i] += 1;
                colSum[j] += 1;
                if (i == j) diagSum += 1;
                if (i + j == boardSize - 1) antiDiagSum += 1;
            } else if (board[i][j] == 'O') {
                oCount++;
                rowSum[i] -= 1;
                colSum[j] -= 1;
                if (i == j) diagSum -= 1;
                if (i + j == boardSize - 1) antiDiagSum -= 1;
            }
        }

    }
    
    for (int i = 0; i < 3; i++) {
        if (rowSum[i] == 3 || colSum[i] == 3 || diagSum == 3 || antiDiagSum == 3) return true;
        if (rowSum[i] == -3 || colSum[i] == -3 || diagSum == -3 || antiDiagSum == -3) return true;
    }
    
    return xCount == oCount + 1 || xCount == oCount;
    
}