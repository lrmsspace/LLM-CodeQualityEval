/*
 You are given two strings, coordinate1 and coordinate2, representing the coordinates of a square on an 8 x 8 chessboard.
 Below is the chessboard for reference.
 Return true if these two squares have the same color and false otherwise.
 The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first (indicating its column), and the number second (indicating its row).
 Example 1:
 Input: coordinate1 = "a1", coordinate2 = "c3"
 Output: true
 Explanation:
 Both squares are black.
 Example 2:
 Input: coordinate1 = "a1", coordinate2 = "h3"
 Output: false
 Explanation:
 Square "a1" is black and "h3" is white.
 Constraints:
 coordinate1.length == coordinate2.length == 2
 'a' <= coordinate1[0], coordinate2[0] <= 'h'
 '1' <= coordinate1[1], coordinate2[1] <= '8'
*/

/**
 * @param {string} coordinate1
 * @param {string} coordinate2
 * @return {boolean}
 */
var checkTwoChessboards = function(coordinate1, coordinate2) {
    let row1 = parseInt(coordinate1[1]) - 1;
    let row2 = parseInt(coordinate2[1]) - 1;
    
    let col1 = coordinate1[0].charCodeAt(0) - 'a'.charCodeAt(0);
    let col2 = coordinate2[0].charCodeAt(0) - 'a'.charCodeAt(0);
    
    let board1 = new Array(8).fill(null).map(() => new Array(8).fill(null));
    let board2 = new Array(8).fill(null).map(() => new Array(8).fill(null));
    
    for (let i = 0; i < 8; i++) {
        board1[row1][i] = i % 2 === 0? 'W' : 'B';
        board2[row2][i] = i % 2 === 0? 'B' : 'W';
    }
    for (let i = 0; i < 8; i++) {
        board1[i][col1] = col1 % 2 === 0? 'W' : 'B';
        board2[i][col2] = col2 % 2 === 0? 'B' : 'W';
    }
    return board1.toString() === board2.toString(); 
    
};