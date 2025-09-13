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
class Solution {
    public int countCombinations(String[] pieces, int[][] positions) {

    int n = pieces.length;
    int[][] directions = new int[n][];
    for (int i = 0; i < n; i++) {
        if (pieces[i].equals("rook")) {
        directions[i] = new int[]{0, 1, 0, -1, 1, 0, -1, 0};
        } else if (pieces[i].equals("queen")) {
        directions[i] = new int[]{0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
        } else if (pieces[i].equals("bishop")) {
        directions[i] = new int[]{1, 1, 1, -1, -1, 1, -1, -1};
        }
    }

    return dfs(pieces, positions, directions, new int[n], 0);
    }

    private int dfs(String[] pieces, int[][] positions, int[][] directions, int[] moves, int index) {
    if (index == pieces.length) {
        return isValid(pieces, positions, directions, moves) ? 1 : 0;
    }

    int count = 0;
    for (int i = 0; i < directions[index].length / 2; i++) {
        moves[index] = i;
        count += dfs(pieces, positions, directions, moves, index + 1);
    }
    return count;
    }

    private boolean isValid(String[] pieces, int[][] positions, int[][] directions, int[] moves) {
    int n = pieces.length;
    int[][] currentPositions = new int[n][2];
    for (int i = 0; i < n; i++) {
        currentPositions[i] = positions[i].clone();
    }

    for (int t = 0; t < 8; t++) {
        boolean[] moved = new boolean[n];
        for (int i = 0; i < n; i++) {
        if (moves[i] < directions[i].length / 2) {
            currentPositions[i][0] += directions[i][moves[i] * 2];
            currentPositions[i][1] += directions[i][moves[i] * 2 + 1];
            moved[i] = true;
        }
        }

        for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (currentPositions[i][0] == currentPositions[j][0] &&
            currentPositions[i][1] == currentPositions[j][1]) {
            return false;
            }
        }
        }

        if (!anyMoved(moved)) {
        break;
        }
    }
    return true;
    }

    private boolean anyMoved(boolean[] moved) {
    for (boolean m : moved) {
        if (m) {
        return true;
        }
    }
    return false;
    }
        
}