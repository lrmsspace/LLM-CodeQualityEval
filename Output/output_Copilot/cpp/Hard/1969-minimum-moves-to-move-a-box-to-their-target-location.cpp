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
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int sx, sy, bx, by, tx, ty;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (grid[i][j] == 'B') {
                    bx = i;
                    by = j;
                } else if (grid[i][j] == 'T') {
                    tx = i;
                    ty = j;
                }
            }
        }
        auto canMove = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
        };
        auto bfs = [&](int x, int y) {
            vector<vector<int>> dist(m, vector<int>(n, -1));
            queue<pair<int, int>> q;
            q.push({x, y});
            dist[x][y] = 0;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (canMove(nx, ny) && dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
            return dist;
        };
        auto canPush = [&](int x, int y, int bx, int by) {
            if (x == bx && y == by) {
                return false;
            }
            vector<vector<int>> dist = bfs(x, y);
            return dist[bx][by] != -1;
        };
        auto canReach = [&](int x, int y, int bx, int by, int tx, int ty) {
            if (x == tx && y == ty) {
                return true;
            }
            vector<vector<int>> dist  = bfs(tx, ty);
            return dist[x][y] != -1;}     ;
        queue<tuple<int, int, int, int>> q;
        q.push({sx, sy, bx, by});
        vector<vector<vector<vector<int>>> dist(m, vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(n, -1))));
        dist[sx][sy][bx][by] = 0;
            while (!q.empty()) {
                auto [px, py, bx, by] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                int nbx = bx + dx[i];
                int nby = by + dy[i];
                int pxBehind = bx - dx[i];
                int pyBehind = by - dy[i];
                if (canMove(nbx, nby) && canMove(pxBehind, pyBehind) && canPush(px, py, pxBehind, pyBehind)) {
                    if (dist[pxBehind][pyBehind][nbx][nby] == -1) {
                    dist[pxBehind][pyBehind][nbx][nby] = dist[px][py][bx][by] + 1;
                    q.push({pxBehind, pyBehind, nbx, nby});
                    if (nbx == tx && nby == ty) {
                        return dist[pxBehind][pyBehind][nbx][nby];
                    }
                    }
                }
                }
            }
            return -1;  
    }
};