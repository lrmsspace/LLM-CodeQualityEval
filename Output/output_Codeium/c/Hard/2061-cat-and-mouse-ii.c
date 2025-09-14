/**https://leetcode.com/problems/cat-and-mouse-ii/ */
//A game is played by a cat and a mouse named Cat and Mouse.
//The environment is represented by a grid of size rows x cols, where each element is a wall, floor, player (Cat, Mouse), or food.
//	Players are represented by the characters 'C'(Cat),'M'(Mouse).
//	Floors are represented by the character '.' and can be walked on.
//	Walls are represented by the character '#' and cannot be walked on.
//	Food is represented by the character 'F' and can be walked on.
//	There is only one of each character 'C', 'M', and 'F' in grid.
//Mouse and Cat play according to the following rules:
//	Mouse moves first, then they take turns to move.
//	During each turn, Cat and Mouse can jump in one of the four directions (left, right, up, down). They cannot jump over the wall nor outside of the grid.
//	catJump, mouseJump are the maximum lengths Cat and Mouse can jump at a time, respectively. Cat and Mouse can jump less than the maximum length.
//	Staying in the same position is allowed.
//	Mouse can jump over Cat.
//The game can end in 4 ways:
//	If Cat occupies the same position as Mouse, Cat wins.
//	If Cat reaches the food first, Cat wins.
//	If Mouse reaches the food first, Mouse wins.
//	If Mouse cannot get to the food within 1000 turns, Cat wins.
//Given a rows x cols matrix grid and two integers catJump and mouseJump, return true if Mouse can win the game if both Cat and Mouse play optimally, otherwise return false.
// 
//Example 1:
//Input: grid = ["####F","#C...","M...."], catJump = 1, mouseJump = 2
//Output: true
//Explanation: Cat cannot catch Mouse on its turn nor can it get the food before Mouse.
//Example 2:
//Input: grid = ["M.C...F"], catJump = 1, mouseJump = 4
//Output: true
//Example 3:
//Input: grid = ["M.C...F"], catJump = 1, mouseJump = 3
//Output: false
// 
//Constraints:
//	rows == grid.length
//	cols = grid[i].length
//	1 <= rows, cols <= 8
//	grid[i][j] consist only of characters 'C', 'M', 'F', '.', and '#'.
//	There is only one of each character 'C', 'M', and 'F' in grid.
//	1 <= catJump, mouseJump <= 8
bool canMouseWin(char** grid, int gridSize, int catJump, int mouseJump) {
    int rows = gridSize;
    int cols = strlen(grid[0]);
    int catPos[2], mousePos[2], foodPos[2];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 'C') {
                catPos[0] = i;
                catPos[1] = j;
            } else if (grid[i][j] == 'M') {
                mousePos[0] = i;
                mousePos[1] = j;
            } else if (grid[i][j] == 'F') {
                foodPos[0] = i;
                foodPos[1] = j;
            }
        }
    }

    int memo[(1 << 14) + 5][1005];
    memset(memo, -1, sizeof(memo));
    function<bool(int, int, int, int)> dfs = [&](int state, int catDist, int mouseDist, int turn) {
        if (turn >= 1000) {
            return 0;
        }
        if (memo[state][turn] != -1) {
            return memo[state][turn];
        }
        int catRow = state >> 7 & 7;
        int catCol = state >> 4 & 7;
        int mouseRow = state >> 1 & 7;
        int mouseCol = state & 1;
        if (catRow == mouseRow && catCol == mouseCol) {
            return memo[state][turn] = 0;
        }
        if (mouseRow == foodPos[0] && mouseCol == foodPos[1]) {
            return memo[state][turn] = 1;
        }
        int nextCatDist = abs(catRow - mouseRow) + abs(catCol - mouseCol);
        int nextMouseDist = abs(mouseRow - foodPos[0]) + abs(mouseCol - foodPos[1]);
        if (turn % 2 == 0) {
            for (int i = 0; i < 8; ++i) {
                int nrow = mouseRow + "01101001"[i] - '1';
                int ncol = mouseCol + "10102030"[i] - '0';
                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && grid[nrow][ncol] != '#') {
                    int nstate = (nrow << 7) | (ncol << 4) | (catRow << 1) | catCol;
                    if (!dfs(nstate, nextCatDist, nextMouseDist, turn + 1)) {
                        return memo[state][turn] = 1;
                    }
                }
            }
            return memo[state][turn] = 0;
        } else {
            for (int i = 0; i < 8; ++i) {
                int nrow = catRow + "01101001"[i] - '1';
                int ncol = catCol + "10102030"[i] - '0';
                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && grid[nrow][ncol] != '#' && nextCatDist > catJump) {
                    int nstate = (mouseRow << 7) | (mouseCol << 4) | (nrow << 1) | ncol;
                    if (!dfs(nstate, nextCatDist, nextMouseDist, turn + 1)) {
                        return memo[state][turn] = 1;
                    }
                }
            }
            return memo[state][turn] = 0;
        }
    };
    return dfs((mousePos[0] << 7) | (mousePos[1] << 4) | (catPos[0] << 1) | catPos[1], 0, 0, 0);
}
