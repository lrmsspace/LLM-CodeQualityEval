/**https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/ */
//A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.
//The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
//Your task is to move the box 'B' to the target position 'T' under the following rules:
//	The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
//	The character '.' represents the floor which means a free cell to walk.
//	The character '#' represents the wall which means an obstacle (impossible to walk there).
//	There is only one box 'B' and one target cell 'T' in the grid.
//	The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
//	The player cannot walk through the box.
//Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.
// 
//Example 1:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T","#","#","#","#"],
//               ["#",".",".","B",".","#"],
//               ["#",".","#","#",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: 3
//Explanation: We return only the number of times the box is pushed.
//Example 2:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T","#","#","#","#"],
//               ["#",".",".","B",".","#"],
//               ["#","#","#","#",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: -1
//Example 3:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T",".",".","#","#"],
//               ["#",".","#","B",".","#"],
//               ["#",".",".",".",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: 5
//Explanation: push the box down, left, left, up and up.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 20
//	grid contains only characters '.', '#', 'S', 'T', or 'B'.
//	There is only one character 'S', 'B', and 'T' in the grid.
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {


        int m = grid.size(), n = grid[0].size();
        int sx, sy, bx, by, tx, ty;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                if(grid[i][j] == 'B'){
                    bx = i;
                    by = j;
                }
                if(grid[i][j] == 'T'){
                    tx = i;
                    ty = j;
                }
            }
        }
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n*m, INT_MAX)));
        dp[bx][by][bx*n+by] = 0;
        queue<pair<int, int>> q;
        q.push({bx, by});
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto& dir : dirs){
                int nx = x + dir[0], ny = y + dir[1];
                int px = x - dir[0], py = y - dir[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') continue;
                if(px < 0 || px >= m || py < 0 || py >= n || grid[px][py] == '#') continue;
                if(nx == sx && ny == sy) continue;
                if(dp[nx][ny][x*n+y] > dp[x][y][x*n+y] + 1){
                    dp[nx][ny][x*n+y] = dp[x][y][x*n+y] + 1;
                    if(nx == tx && ny == ty) return dp[nx][ny][x*n+y];
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }   
};