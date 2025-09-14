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
        int si, sj, bi, bj, ti, tj;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'S') {
                    si = i;
                    sj = j;
                } else if (grid[i][j] == 'B') {
                    bi = i;
                    bj = j;
                } else if (grid[i][j] == 'T') {
                    ti = i;
                    tj = j;
                }
            }
        }

        queue<pair<int, int>> q;
        q.push({si, sj});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[si][sj] = true;
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front();
                q.pop();
                if (x == ti && y == tj) return step;
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') continue;
                    if (nx == bi && ny == bj) {
                        for (int l = 0; l < 4; ++l) {
                            int nnx = nx + dx[l], nny = ny + dy[l];
                            if (nnx < 0 || nnx >= m || nny < 0 || nny >= n || grid[nnx][nny] == '#') continue;
                            if (visited[nnx][nny]) continue;
                            visited[nnx][nny] = true;
                            q.push({nnx, nny});
                        }
                    } else if (visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            ++step;
        }
        return -1;
    }
};