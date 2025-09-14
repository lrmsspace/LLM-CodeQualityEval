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
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < *boardColSize; j++) {
            for (k = 0; k < wordsSize; k++) {
                for (l = 0; l < strlen(words[k]); l++) {
                    if (board[i][j] == words[k][l]) {
                        for (m = 0; m < 8; m++) {
                            if (i + dir[m][0] >= 0 && i + dir[m][0] < boardSize && j + dir[m][1] >= 0 && j + dir[m][1] < *boardColSize) {
                                if (board[i + dir[m][0]][j + dir[m][1]] == words[k][l + 1]) {
                                    board[i][j] = '*';
                                }
                            }
                         }
                    }
                }
            }
        }
    }
    return res;
}