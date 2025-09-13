/**https://leetcode.com/problems/available-captures-for-rook/ */
//You are given an 8 x 8 matrix representing a chessboard. There is exactly one white rook represented by 'R', some number of white bishops 'B', and some number of black pawns 'p'. Empty squares are represented by '.'.
//A rook can move any number of squares horizontally or vertically (up, down, left, right) until it reaches another piece or the edge of the board. A rook is attacking a pawn if it can move to the pawn's square in one move.
//Note: A rook cannot move through other pieces, such as bishops or pawns. This means a rook cannot attack a pawn if there is another piece blocking the path.
//Return the number of pawns the white rook is attacking.
// 
//Example 1:
//Input: board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
//Output: 3
//Explanation:
//In this example, the rook is attacking all the pawns.
//Example 2:
//Input: board = [[".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
//Output: 0
//Explanation:
//The bishops are blocking the rook from attacking any of the pawns.
//Example 3:
//Input: board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
//Output: 3
//Explanation:
//The rook is attacking the pawns at positions b5, d6, and f5.
// 
//Constraints:
//	board.length == 8
//	board[i].length == 8
//	board[i][j] is either 'R', '.', 'B', or 'p'
//	There is exactly one cell with board[i][j] == 'R'
int numRookCaptures(char** board, int boardSize, int* boardColSize) {
    
    int count = 0;
    int rookRow = -1;
    int rookCol = -1;
    
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == 'R') {
                rookRow = i;
                rookCol = j;
                break;
            }
        }
    }
    
    // Check up
    for (int i = rookRow - 1; i >= 0; i--) {
        if (board[i][rookCol] == 'B') {
            break;
        } else if (board[i][rookCol] == 'p') {
            count++;
            break;
        }
    }
    
    // Check down
    for (int i = rookRow + 1; i < boardSize; i++) {
        if (board[i][rookCol] == 'B') {
            break;
        } else if (board[i][rookCol] == 'p') {
            count++;
            break;
        }
    }
    
    // Check left
    for (int j = rookCol - 1; j >= 0; j--) {
        if (board[rookRow][j] == 'B') {
            break;
        } else if (board[rookRow][j] == 'p') {
            count++;
            break;
        }
    }
    
    // Check right
    for (int j = rookCol + 1; j < boardColSize[rookRow]; j++) {
        if (board[rookRow][j] == 'B') {
            break;
        } else if (board[rookRow][j] == 'p') {
            count++;
            break;
        }
    }
    
    // Check up-left
    for (int i = rookRow - 1, j = rookCol - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'B') {
            break;
        } else if (board[i][j] == 'p') {
            count++;
            break;
        }
    }
    
    // Check up-right
    for (int i = rookRow - 1, j = rookCol + 1; i >= 0 && j < boardColSize[rookRow]; i--, j++) {
        if (board[i][j] == 'B') {
            break;
        } else if (board[i][j] == 'p') {
            count++;
            break;
        }
    }
    
    // Check down-left
    for (int i = rookRow + 1, j = rookCol - 1; i < boardSize && j >= 0; i++, j--) {
        if (board[i][j] == 'B') {
            break;
        } else if (board[i][j] == 'p') {
            count++;
            break;
        }
    }
    
    // Check down-right
    for (int i = rookRow + 1, j = rookCol + 1; i < boardSize && j < boardColSize[rookRow]; i++, j++) {
        if (board[i][j] == 'B') {
            break;
        } else if (board[i][j] == 'p') {
            count++;
            break;
        }
    }
    
    return count;
}