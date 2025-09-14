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
    const m = board.length;
    const n = board[0].length;
    const visited = Array.from({ length: m }, () => Array(n).fill(false));
    const result = [];
    
    const dfs = (row, col, word, index) => {
        if (index === word.length) {
            result.push(word);
            return;
        }
        
        if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || board[row][col]!== word[index]) {
            return;
        }
        
        visited[row][col] = true;
        dfs(row - 1, col, word, index + 1); // up
        dfs(row + 1, col, word, index + 1); // down
        dfs(row, col - 1, word, index + 1); // left
        dfs(row, col + 1, word, index + 1); // right
        visited[row][col] = false;
    };
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            for (const word of words) {
                dfs(i, j, word, 0);
            }
        }
    }
    
    return result;
    
};