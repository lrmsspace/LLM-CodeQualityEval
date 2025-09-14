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
class Solution {
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1))));
        vector<vector<vector<vector<int>>>> dp2(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1)));
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> cat, mouse, food;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'C') cat = {i, j};
                if (grid[i][j] == 'M') mouse = {i, j};
                if (grid[i][j] == 'F') food = {i, j};
            }
        }
        function<int(int, int, int, int)> dfs = [&](int x1, int y1, int x2, int y2) {
            if (x1 == food[0] && y1 == food[1]) return 1;
            if (x1 == x2 && y1 == y2) return 0;
            if (x2 == food[0] && y2 == food[1]) return 2;
            if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
            int res = 0;
            for (auto& dir : dirs) {
                for (int i = 1; i <= catJump; i++) {
                    int nx1 = x1 + dir[0] * i, ny1 = y1 + dir[1] * i;
                    if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= m || grid[nx1][ny1] == '#') break;
                    if (dfs(nx1, ny1, x2, y2) == 2) return dp[x1][y1][x2][y2] = 1;
                    if (dfs(nx1, ny1, x2, y2) == 0) res = 1;   
                        }
                    }
                    for (auto& dir : dirs) {
                        for (int i = 1; i <= mouseJump; i++) {
                            int nx2 = x2 + dir[0] * i, ny2 = y2 + dir[1] * i;
                            if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= m || grid[nx2][ny2] == '#') break;
                            if (dfs(x1, y1, nx2, ny2) == 1) return dp[x1][y1][x2][y2] = 2;
                            if (dfs(x1, y1, nx2, ny2) == 0) res = 2;
                        }
                    }
                    return dp[x1][y1][x2][y2] = res;
                };
                return dfs(cat[0], cat[1], mouse[0], mouse[1]) == 2;    
    }
};