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
    const n = board.length;
    let rowCount = 0, colCount = 0;
    let rowSum = 0, colSum = 0;
    let rowDiff = 0, colDiff = 0;

    for (let i = 0; i < n; i++) {
        rowSum += board[0][i];
        colSum += board[i][0];
        if (board[0][i] !== board[i][0]) {
            rowDiff++;
        }
        if (board[i][0] === 1) {
            rowCount++;
        }
        if (board[0][i] === 1) {
            colCount++;
        }
    }

    if (rowCount !== Math.floor(n / 2) && rowCount !== Math.ceil(n / 2)) return -1;
    if (colCount !== Math.floor(n / 2) && colCount !== Math.ceil(n / 2)) return -1;

    for (let i = 1; i < n; i++) {
        if ((board[i][0] === board[0][0]) !== (board[i][i] === board[0][i])) {
            rowDiff++;
        }
        if ((board[0][i] === board[0][0]) !== (board[i][i] === board[i][0])) {
            colDiff++;
        }
    }

    if (rowDiff % 2 !== 0 || colDiff % 2 !== 0) return -1;

    return Math.min(rowDiff, n - rowDiff) + Math.min(colDiff, n - colDiff);    
};