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
    let row = board.length;
    let col = board[0].length;
    let visited = new Array(row).fill(0).map(() => new Array(col).fill(false));
    
    for(let i = 0; i < row; i++){
        for(let j = 0; j < col; j++){
            if(board[i][j] === word[0]){
                if(dfs(i, j, 0)) return true;
            }
        }
    }
    
    return false;
    
    function dfs(i, j, index){
        if(index === word.length) return true;
        if(i <0 || j < 0 || i >= row || j >= col || visited[i][j] || board[i][j] !== word[index]) return false;
    }
};