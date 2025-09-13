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
char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    int m = boardSize;
    int n = boardColSize[0];
    int l = wordsSize;
    char **ans = (char **)malloc((l + 1) * sizeof(char *));
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        int len = strlen(words[i]);
        int flag = 1;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (board[j][k] == words[i][0]) {
                    int vis[m][n] = {0};
                    int dx[] = {0, 1, 0, -1};
                    int dy[] = {1, 0, -1, 0};
                    int x = j, y = k;
                    int c = 1;
                    while (c < len) {
                        int f = 0;
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && board[nx][ny] == words[i][c]) {
                                vis[x][y] = 1;
                                x = nx;
                                y = ny;
                                c++;
                                f = 1;
                                break;
                            }
                        }
                        if (!f) break;
                    }
                    if (c == len) {
                        ans[cnt] = words[i];
                        cnt++;
                        flag = 0;
                        break;
                    }
                }
            }
            if (!flag) break;
        }
    }
    *returnSize = cnt;
    return ans;
}