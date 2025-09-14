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
        queue<pair<pair<int, int>, int>> q;
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(n * m, false)));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'C') {
                    q.push({ { i, j }, 0 });
                    dp[i][j][i * m + j] = true;
                }
            }
        }
        
        int dx[4] = { -1, 1, 0, 0 };
        int dy[4] = { 0, 0, -1, 1 };
        
        while (!q.empty()) {
            auto [pos, time] = q.front();
            q.pop();
            
            int x = pos.first, y = pos.second;
            int cat = x * m + y;
            
            if (time == 1000) {
                return false;
            }
            
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k] * catJump;
                int ny = y + dy[k] * catJump;
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') {
                    continue;
                }
                
                int mouse = nx * m + ny;
                if (dp[nx][ny][mouse]) {
                    continue;
                }
                
                dp[nx][ny][mouse] = true;
                
                if (grid[nx][ny] == 'F') {
                    return true;
                }
                
                q.push({ { nx, ny }, time + 1 });
            }
            
            for (int k = 0; k < 4; ++k) {
                int mx = x + dx[k] * mouseJump;
                int my = y + dy[k] * mouseJump;
                
                if (mx < 0 || mx >= n || my < 0 || my >= m || grid[mx][my] == '#') {
                    continue;
                }
                
                int cat = mx * m + my;
                if (dp[x][y][cat]) {
                    continue;
                }
                
                dp[x][y][cat] = true;
                
                if (grid[mx][my] == 'F') {
                    return false;
                }
                
                q.push({ { mx, my }, time + 1 });
            }
            
            if (dp[x][y][cat]) {
                return true;
            }
            
            if (grid[x][y] == 'F') {
                return false;
            }
            
            for (int k = 0; k < 4; ++k) {
                int mx = x + dx[k] * mouseJump;
                int my = y + dy[k] * mouseJump;
                
                if (mx < 0 || mx >= n || my < 0 || my >= m || grid[mx][my] == '#') {
                    continue;
                }
                
                int cat = mx * m + my;
                if (dp[x][y][cat]) {
                    continue;
                }
                
                dp[x][y][cat] = true;
                
                if (grid[mx][my] == 'F') {
                    return false;
                }
                
                q.push({ { mx, my }, time + 1 });
            }
            
            if (dp[x][y][cat]) {
                return true;
            }
            
            if (grid[x][y] == 'F') {
                return false;
            }

        }
        
        return false;
        
    }
};