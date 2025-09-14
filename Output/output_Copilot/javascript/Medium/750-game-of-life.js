/**https://leetcode.com/problems/game-of-life/ */
//According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
//	Any live cell with fewer than two live neighbors dies as if caused by under-population.
//	Any live cell with two or three live neighbors lives on to the next generation.
//	Any live cell with more than three live neighbors dies, as if by over-population.
//	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.
//Given the current state of the board, update the board to reflect its next state.
//Note that you do not need to return anything.
// 
//Example 1:
//Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
//Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
//Example 2:
//Input: board = [[1,1],[1,0]]
//Output: [[1,1],[1,1]]
// 
//Constraints:
//	m == board.length
//	n == board[i].length
//	1 <= m, n <= 25
//	board[i][j] is 0 or 1.
// 
//Follow up:
//	Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
//	In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    const m = board.length;
    const n = board[0].length;
    const directions = [
        [-1, -1], [-1, 0], [-1, 1],
        [0, -1],          [0, 1],
        [1, -1], [1, 0], [1, 1]
    ];

    // Create a copy of the board to store the next state
    const nextState = JSON.parse(JSON.stringify(board));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            let liveNeighbors = 0;

            // Count live neighbors
            for (const [dx, dy] of directions) {
                const x = i + dx;
                const y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] === 1) {
                    liveNeighbors++;
                }
            }

            // Apply rules
            if (board[i][j] === 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    nextState[i][j] = 0; // Cell dies
                }
            } else {
                if (liveNeighbors === 3) {
                    nextState[i][j] = 1; // Cell becomes alive
                }
            }
        }
    }

    // Update the original board with the next state
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            board[i][j] = nextState[i][j];
        }
    }  
    return board; // Return the modified board (not necessary, but for clarity)  
};