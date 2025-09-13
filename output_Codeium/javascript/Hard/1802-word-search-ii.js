/**https://leetcode.com/problems/word-search-ii/ */
//Given an m x n board of characters and a list of strings words, return all words on the board.
//Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
// 
//Example 1:
//Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
//Output: ["eat","oath"]
//Example 2:
//Input: board = [["a","b"],["c","d"]], words = ["abcb"]
//Output: []
// 
//Constraints:
//	m == board.length
//	n == board[i].length
//	1 <= m, n <= 12
//	board[i][j] is a lowercase English letter.
//	1 <= words.length <= 3 * 104
//	1 <= words[i].length <= 10
//	words[i] consists of lowercase English letters.
//	All the strings of words are unique.
/**
 * @param {character[][]} board
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function(board, words) {
    const result = [];
    const dfs = (i, j, k, word) => {
        if (board[i][j] !== word[k]) return;
        if (k === word.length - 1) {
            result.push(word);
            return;
        }
        const temp = board[i][j];
        board[i][j] = '*';
        for (const [x, y] of [[-1, 0], [1, 0], [0, -1], [0, 1]]) {
            const ni = i + x, nj = j + y;
            if (ni >= 0 && ni < board.length && nj >= 0 && nj < board[0].length) {
                dfs(ni, nj, k + 1, word);
            }
        }
        board[i][j] = temp;
    };
    for (const word of words) {
        for (let i = 0; i < board.length; i++) {
            for (let j = 0; j < board[0].length; j++) {
                dfs(i, j, 0, word);
            }
        }
    }
    return result;
};