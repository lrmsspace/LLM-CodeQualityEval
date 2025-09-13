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
    int rows = gridSize, cols = grid[0].length;
    vector<vector<vector<bool>>> dp(rows, vector<vector<bool>>(cols, vector<bool>(rows, cols, false)));
    
    // Initialize the dp table
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 'C') {
                dp[i][j][i] = true;
            } else if (grid[i][j] == 'M') {
                dp[i][j][rows - 1] = true;
            }
        }
    }
    
    // Build the dp table
    for (int k = 0; k < 1000; ++k) {
        vector<vector<vector<bool>>> newDp(rows, vector<vector<bool>>(cols, vector<bool>(rows, false)));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (int ni = max(0, i - catJump); ni <= min(rows - 1, i + catJump); ++ni) {
                    for (int nj = max(0, j - catJump); nj <= min(cols - 1, j + catJump); ++nj) {
                        if (grid[ni][nj]!= '#') {
                            newDp[i][j][ni] |= dp[ni][nj][j];
                        }
                    }
                }
        
                for (int mi = max(0, i - mouseJump); mi <= min(rows - 1, i + mouseJump); ++mi) {
                    for (int mj = max(0, j - mouseJump); mj <= min(cols - 1, j + mouseJump); ++mj) {
                        if (grid[mi][mj]!= '#' &&!newDp[i][j][mi]) {
                            newDp[i][j][mi] |= dp[i][j][mi];
                        }
                    }
                }

    // Swap dp table for the next iteration
                dp = newDp;
            }
        }
        
        // If Cat can win, return true
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dp[i][j][rows - 1]) {
                    return true;
                }
            }
        }
    }
    
    // If Cat cannot win, return false
    return false;
    
}