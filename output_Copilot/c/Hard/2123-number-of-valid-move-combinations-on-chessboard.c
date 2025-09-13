/**https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/ */
//There is an 8 x 8 chessboard containing n pieces (rooks, queens, or bishops). You are given a string array pieces of length n, where pieces[i] describes the type (rook, queen, or bishop) of the ith piece. In addition, you are given a 2D integer array positions also of length n, where positions[i] = [ri, ci] indicates that the ith piece is currently at the 1-based coordinate (ri, ci) on the chessboard.
//When making a move for a piece, you choose a destination square that the piece will travel toward and stop on.
//	A rook can only travel horizontally or vertically from (r, c) to the direction of (r+1, c), (r-1, c), (r, c+1), or (r, c-1).
//	A queen can only travel horizontally, vertically, or diagonally from (r, c) to the direction of (r+1, c), (r-1, c), (r, c+1), (r, c-1), (r+1, c+1), (r+1, c-1), (r-1, c+1), (r-1, c-1).
//	A bishop can only travel diagonally from (r, c) to the direction of (r+1, c+1), (r+1, c-1), (r-1, c+1), (r-1, c-1).
//You must make a move for every piece on the board simultaneously. A move combination consists of all the moves performed on all the given pieces. Every second, each piece will instantaneously travel one square towards their destination if they are not already at it. All pieces start traveling at the 0th second. A move combination is invalid if, at a given time, two or more pieces occupy the same square.
//Return the number of valid move combinations​​​​​.
//Notes:
//	No two pieces will start in the same square.
//	You may choose the square a piece is already on as its destination.
//	If two pieces are directly adjacent to each other, it is valid for them to move past each other and swap positions in one second.
// 
//Example 1:
//Input: pieces = ["rook"], positions = [[1,1]]
//Output: 15
//Explanation: The image above shows the possible squares the piece can move to.
//Example 2:
//Input: pieces = ["queen"], positions = [[1,1]]
//Output: 22
//Explanation: The image above shows the possible squares the piece can move to.
//Example 3:
//Input: pieces = ["bishop"], positions = [[4,3]]
//Output: 12
//Explanation: The image above shows the possible squares the piece can move to.
// 
//Constraints:
//	n == pieces.length 
//	n == positions.length
//	1 <= n <= 4
//	pieces only contains the strings "rook", "queen", and "bishop".
//	There will be at most one queen on the chessboard.
//	1 <= ri, ci <= 8
//	Each positions[i] is distinct.
int countCombinations(char** pieces, int piecesSize, int** positions, int positionsSize, int* positionsColSize) {
    int rook[8][8] = {0};
    int queen[8][8] = {0};
    int bishop[8][8] = {0};
    for (int i = 0; i < positionsSize; i++) {
        int r = positions[i][0] - 1;
        int c = positions[i][1] - 1;
        rook[r][c] = queen[r][c] = bishop[r][c] = 1;
    }
    for (int i = 0; i < piecesSize; i++) {
        int r = positions[i][0] - 1;
        int c = positions[i][1] - 1;
        if (strcmp(pieces[i], "rook") == 0) {
            for (int j = r + 1; j < 8; j++) {
                if (rook[j][c] == 0) {
                    rook[j][c] = 2;
                } else if (rook[j][c] == 1) {
                    break;
                }
            }
            for (int j = r - 1; j >= 0; j--) {
                if (rook[j][c] == 0) {
                    rook[j][c] = 2;
                } else if (rook[j][c] == 1) {
                    break;
                }
            }
            for (int j = c + 1; j < 8; j++) {
                if (rook[r][j] == 0) {
                    rook[r][j] = 2;
                } else if (rook[r][j] == 1) {
                    break;
                }
            }
            for (int j = c - 1; j >= 0; j--) {
                if (rook[r][j] == 0) {
                    rook[r][j] = 2;
                } else if (rook[r][j] == 1) {
                    break;
                }
            }
        } else if (strcmp(pieces[i], "queen") == 0) {
            for (int j = r + 1; j < 8; j++) {
                if (queen[j][c] == 0) {
                    queen[j][c] = 2;
                } else if (queen
[j][c] == 1) {
                    break;
                }
            }
            for (int j = r - 1; j >= 0; j--) {
                if (queen[j][c] == 0) {
                    queen[j][c] = 2;
                } else if (queen[j][c] == 1) {
                    break;
                }
            }
            for (int j = c + 1; j < 8; j++) {
                if (queen[r][j] == 0) {
                    queen[r][j] = 2;
                } else if (queen[r][j] == 1) {
                    break;
                }
            }
            for (int j = c - 1; j >= 0; j--) {
                if (queen[r][j] == 0) {
                    queen[r][j] = 2;
                } else if (queen[r][j] == 1) {
                    break;
                }
            }
            for (int j = 1; r + j < 8 && c + j < 8; j++) {
                if (queen[r + j][c + j] == 0) {
                    queen[r + j][c + j] = 2;
                } else if (queen[r + j][c + j] == 1) {
                    break;
                }
            }
            for (int j = 1; r + j < 8 && c - j >= 0; j++) {
                if (queen[r + j][c - j] == 0) {
                    queen[r + j][c - j] = 2;
                } else if (queen[r + j][c - j] == 1) {
                    break;
                }
            }
            for (int j = 1; r - j >= 0 && c + j < 8; j++) {
                if (queen[r - j][c + j] == 0) {
                    queen[r - j][c + j] = 2;
                } else if (queen[r - j][c + j] == 1) {
                    break;
                }
            }
            for (int j = 1; r - j >= 0 && c - j >= 0; j++) {
                if (queen[r - j][c - j] == 0) {
                    queen[r - j][c - j] = 2;
                } else if (queen[r - j][c - j] == 1) {
                    break;
                }
            }
        } else if (strcmp(pieces[i], "bishop") == 0) {
            for (int j = 1; r + j < 8 && c + j < 8; j++) {
                if (bishop[r + j][c + j] == 0) {
                    bishop[r + j][c + j] = 2;
                } else if (bishop[r + j][c + j] == 1) {
                    break;
                }
            }
            for (int j = 1; r + j < 8 && c - j >= 0; j++) {
                if (bishop[r + j][c - j] == 0) {
                    bishop[r + j][c - j] = 2;
                } else if (bishop[r + j][c - j] == 1) {
                    break;
                }
            }
            for (int j = 1; r - j >= 0 && c + j < 8; j++) {
                if (bishop[r - j][c + j] == 0) {
                    bishop[r - j][c + j] = 2;
                } else if (bishop[r - j][c + j] == 1) {
                    break;
                }
            }
            for (int j = 1; r - j >= 0 && c - j >= 0; j++) {
                if (bishop[r - j][c - j] == 0) {
                    bishop[r - j][c - j] = 2;
                } else if (bishop[r - j][c - j] == 1) {
                    break;
                }
            }
        }
    }
    // Logic to calculate valid move combinations goes here
    return 0; // Placeholder return value   
}