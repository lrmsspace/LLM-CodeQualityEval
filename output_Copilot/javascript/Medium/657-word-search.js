/**https://leetcode.com/problems/word-search/ */
//Given an m x n grid of characters board and a string word, return true if word exists in the grid.
//The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
// 
//Example 1:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
//Output: true
//Example 2:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
//Output: true
//Example 3:
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
//Output: false
// 
//Constraints:
//	m == board.length
//	n = board[i].length
//	1 <= m, n <= 6
//	1 <= word.length <= 15
//	board and word consists of only lowercase and uppercase English letters.
// 
//Follow up: Could you use search pruning to make your solution faster with a larger board?
/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const rows = board.length;
    const cols = board[0].length;
    const visited = Array.from({ length: rows }, () => Array(cols).fill(false));

    const dfs = (r, c, index) => {
        if (index === word.length) return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || board[r][c] !== word[index]) return false;

        visited[r][c] = true;

        const found = dfs(r + 1, c, index + 1) ||
                      dfs(r - 1, c, index + 1) ||
                      dfs(r, c + 1, index + 1) ||
                      dfs(r, c - 1, index + 1);

        visited[r][c] = false; // backtrack
        return found;
    };

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (dfs(i, j, 0)) return true;
        }
    }

    return false;    
};