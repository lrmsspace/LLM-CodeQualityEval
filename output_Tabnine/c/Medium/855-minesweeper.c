/**https://leetcode.com/problems/minesweeper/ */
//Let's play the minesweeper game (Wikipedia, online game)!
//You are given an m x n char matrix board representing the game board where:
//	'M' represents an unrevealed mine,
//	'E' represents an unrevealed empty square,
//	'B' represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
//	digit ('1' to '8') represents how many mines are adjacent to this revealed square, and
//	'X' represents a revealed mine.
//You are also given an integer array click where click = [clickr, clickc] represents the next click position among all the unrevealed squares ('M' or 'E').
//Return the board after revealing this position according to the following rules:
//	If a mine 'M' is revealed, then the game is over. You should change it to 'X'.
//	If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively.
//	If an empty square 'E' with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
//	Return the board when no more squares will be revealed.
// 
//Example 1:
//Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
//Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
//Example 2:
//Input: board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]], click = [1,2]
//Output: [["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
// 
//Constraints:
//	m == board.length
//	n == board[i].length
//	1 <= m, n <= 50
//	board[i][j] is either 'M', 'E', 'B', or a digit from '1' to '8'.
//	click.length == 2
//	0 <= clickr < m
//	0 <= clickc < n
//	board[clickr][clickc] is either 'M' or 'E'.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes) {
    int m = boardSize, n = boardColSize[0];
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    *returnSize = m;
    *returnColumnSizes = malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i) (*returnColumnSizes)[i] = n;
    
    char** result = malloc(sizeof(char*) * m);
    for (int i = 0; i < m; ++i) {
        result[i] = malloc(sizeof(char) * n);
        for (int j = 0; j < n; ++j) result[i][j] = board[i][j];
    }
    
    int clickr = click[0], clickc = click[1];
    if (result[clickr][clickc] == 'M') {
        result[clickr][clickc] = 'X';
        *returnSize = 0;
        return result;
    }
    
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int x = clickr + i, y = clickc + j;
            if (x >= 0 && x < m && y >= 0 && y < n && result[x][y] == 'M') ++count;
        }
    }
    
    if (count > 0) {
        result[clickr][clickc] = '0' + count;
        *returnSize = 0;
        return result;
    }
    
    result[clickr][clickc] = 'B';
    for (int i = 0; i < 4; ++i) {
        int x = clickr + directions[i][0], y = clickc + directions[i][1];
        if (x >= 0 && x < m && y >= 0 && y < n && result[x][y] == 'E') dfs(result, m, n, x, y);
    }
    
    return result;
    
}