/**https://leetcode.com/problems/check-if-move-is-legal/ */
//You are given a 0-indexed 8 x 8 grid board, where board[r][c] represents the cell (r, c) on a game board. On the board, free cells are represented by '.', white cells are represented by 'W', and black cells are represented by 'B'.
//Each move in this game consists of choosing a free cell and changing it to the color you are playing as (either white or black). However, a move is only legal if, after changing it, the cell becomes the endpoint of a good line (horizontal, vertical, or diagonal).
//A good line is a line of three or more cells (including the endpoints) where the endpoints of the line are one color, and the remaining cells in the middle are the opposite color (no cells in the line are free). You can find examples for good lines in the figure below:
//Given two integers rMove and cMove and a character color representing the color you are playing as (white or black), return true if changing cell (rMove, cMove) to color color is a legal move, or false if it is not legal.
// 
//Example 1:
//Input: board = [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]], rMove = 4, cMove = 3, color = "B"
//Output: true
//Explanation: '.', 'W', and 'B' are represented by the colors blue, white, and black respectively, and cell (rMove, cMove) is marked with an 'X'.
//The two good lines with the chosen cell as an endpoint are annotated above with the red rectangles.
//Example 2:
//Input: board = [[".",".",".",".",".",".",".","."],[".","B",".",".","W",".",".","."],[".",".","W",".",".",".",".","."],[".",".",".","W","B",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".","B","W",".","."],[".",".",".",".",".",".","W","."],[".",".",".",".",".",".",".","B"]], rMove = 4, cMove = 4, color = "W"
//Output: false
//Explanation: While there are good lines with the chosen cell as a middle cell, there are no good lines with the chosen cell as an endpoint.
// 
//Constraints:
//	board.length == board[r].length == 8
//	0 <= rMove, cMove < 8
//	board[rMove][cMove] == '.'
//	color is either 'B' or 'W'.
/**
 * @param {character[][]} board
 * @param {number} rMove
 * @param {number} cMove
 * @param {character} color
 * @return {boolean}
 */
var checkMove = function(board, rMove, cMove, color) {
    const n = board.length;
    const m = board[0].length;
    const directions = [
        [1, 0], // down
        [0, 1], // right
        [1, 1], // diagonal down right
        [1, -1], // diagonal down left
        [-1, 0], // up
        [0, -1], // left
        [-1, -1], // diagonal up left
        [-1, 1] // diagonal up right
    ];

    for (const [dx, dy] of directions) {
        let x = rMove + dx;
        let y = cMove + dy;
        let count = 0;

        while (x >= 0 && x < n && y >= 0 && y < m) {
            if (board[x][y] === color) {
                count++;
                break;
            } else if (board[x][y] === '.') {
                break;
            } else {
                count++;
            }
            x += dx;
            y += dy;
        }

        if (count >= 3) {
            return true;
        }
    }

    return false;    
};