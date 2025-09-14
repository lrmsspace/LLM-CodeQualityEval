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
int minPushBox(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = *gridColSize;
    int sx, sy, tx, ty, bx, by;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'S') { sx = i; sy = j; }
            if (grid[i][j] == 'B') { bx = i; by = j; }
            if (grid[i][j] == 'T') { tx = i; ty = j; }
        }
    }
    
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(26, INT_MAX)));
    dist[sx][sy][grid[sx][sy] - 'A'] = 0;
    
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second, k = q.front().third;
        q.pop();
        
        if (x == tx && y == ty) return dist[x][y][k];
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') continue;
            
            int nextK = k;
            if (grid[nx][ny] == 'B') {
                for (int j = 0; j < 26; ++j) {
                    if (dist[nx][ny][j]!= INT_MAX) {
                        nextK = j;
                        break;
                    }
                }
            }
            
            if (dist[x][y][k] + 1 < dist[nx][ny][nextK]) {
                dist[nx][ny][nextK] = dist[x][y][k] + 1;
                q.push({nx, ny, nextK});
            }
        }

    }
    return -1;
    
}