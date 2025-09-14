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
/**
 * @param {number[][]} board
 * @return {number}
 */
var movesToChessboard = function(board) {
    let n = board.length;
    let total = n * n;
    let rowXor = 0, colXor = 0;
    
    for (let i = 0; i < n; i++) {
        rowXor ^= board[i].reduce((a, b) => a ^ b, 0);
        colXor ^= board[0][i];
    }
    
    if ((rowXor | colXor) & 1) return -1;
    
    let rowDiff = 0, colDiff = 0;
    for (let i = 0; i < n; i++) {
        if (board[i][0]) rowDiff++;
        if (board[0][i]) colDiff++;
    }
    
    return Math.min(rowDiff + (total - rowDiff) / 2, colDiff + (total - colDiff) / 2);
    
};