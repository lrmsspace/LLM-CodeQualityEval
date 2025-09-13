/**https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/ */
//You are given an m x n matrix board, representing the current state of a crossword puzzle. The crossword contains lowercase English letters (from solved words), ' ' to represent any empty cells, and '#' to represent any blocked cells.
//A word can be placed horizontally (left to right or right to left) or vertically (top to bottom or bottom to top) in the board if:
//	It does not occupy a cell containing the character '#'.
//	The cell each letter is placed in must either be ' ' (empty) or match the letter already on the board.
//	There must not be any empty cells ' ' or other lowercase letters directly left or right of the word if the word was placed horizontally.
//	There must not be any empty cells ' ' or other lowercase letters directly above or below the word if the word was placed vertically.
//Given a string word, return true if word can be placed in board, or false otherwise.
// 
//Example 1:
//Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
//Output: true
//Explanation: The word "abc" can be placed as shown above (top to bottom).
//Example 2:
//Input: board = [[" ", "#", "a"], [" ", "#", "c"], [" ", "#", "a"]], word = "ac"
//Output: false
//Explanation: It is impossible to place the word because there will always be a space/letter above or below it.
//Example 3:
//Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], word = "ca"
//Output: true
//Explanation: The word "ca" can be placed as shown above (right to left). 
// 
//Constraints:
//	m == board.length
//	n == board[i].length
//	1 <= m * n <= 2 * 105
//	board[i][j] will be ' ', '#', or a lowercase English letter.
//	1 <= word.length <= max(m, n)
//	word will contain only lowercase English letters.
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var placeWordInCrossword = function(board, word) {
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length - word.length + 1; j++) {
            if (canPlaceWord(board, word, i, j, 0, 1)) return true;
        }
        for (let j = board[0].length - 1; j >= word.length - 1; j--) {
            if (canPlaceWord(board, word, i, j, 0, -1)) return true;
        }
    }
    for (let i = 0; i < board[0].length; i++) {
        for (let j = 0; j < board.length - word.length + 1; j++) {
            if (canPlaceWord(board, word, j, i, 1, 0)) return true;
        }
        for (let j = board.length - 1; j >= word.length - 1; j--) {
            if (canPlaceWord(board, word, j, i, -1, 0)) return true;
        }
    }
    return false;

    function canPlaceWord(board, word, x, y, dx, dy) {
        for (let i = 0; i < word.length; i++) {
            if (board[x + i * dx][y + i * dy] === '#' || board[x + i * dx][y + i * dy] !== word[i] && board[x + i * dx][y + i * dy] !== ' ') return false;
        }
        if (x - dx >= 0 && board[x - dx][y] !== '#') return false;
        if (x + dx * word.length < board.length && board[x + dx * word.length][y] !== '#') return false;
        if (y - dy >= 0 && board[x][y - dy] !== '#') return false;
        if (y + dy * word.length < board[0].length && board[x][y + dy * word.length] !== '#') return false;
        return true;
};