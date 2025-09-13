/**https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/ */
//You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:
//	1 which means a street connecting the left cell and the right cell.
//	2 which means a street connecting the upper cell and the lower cell.
//	3 which means a street connecting the left cell and the lower cell.
//	4 which means a street connecting the right cell and the lower cell.
//	5 which means a street connecting the left cell and the upper cell.
//	6 which means a street connecting the right cell and the upper cell.
//You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.
//Notice that you are not allowed to change any street.
//Return true if there is a valid path in the grid or false otherwise.
// 
//Example 1:
//Input: grid = [[2,4,3],[6,5,2]]
//Output: true
//Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
//Example 2:
//Input: grid = [[1,2,1],[1,2,1]]
//Output: false
//Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
//Example 3:
//Input: grid = [[1,1,2]]
//Output: false
//Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 300
//	1 <= grid[i][j] <= 6
class Solution {
public:
bool hasValidPath(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    // Define possible directions for each street type
    // For each street type, store which directions are connected
    // 0: left, 1: right, 2: up, 3: down
    vector<vector<bool>> connections = {
        {},  // placeholder for 0
        {true, true, false, false},    // type 1: left-right
        {false, false, true, true},    // type 2: up-down
        {true, false, false, true},    // type 3: left-down
        {false, true, false, true},    // type 4: right-down
        {true, false, true, false},    // type 5: left-up
        {false, true, true, false}     // type 6: right-up
    };
    
    // Direction vectors: left, right, up, down
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    
    // Opposite directions: right, left, down, up
    vector<int> opposite = {1, 0, 3, 2};
    
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        // If we reached the destination
        if (x == m - 1 && y == n - 1) {
            return true;
        }
        
        int streetType = grid[x][y];
        
        // Try all four directions
        for (int dir = 0; dir < 4; dir++) {
            // Check if current street connects in this direction
            if (!connections[streetType][dir]) {
                continue;
            }
            
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            // Check if next cell is valid
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
                continue;
            }
            
            int nextStreetType = grid[nx][ny];
            
            // Check if next street connects back to current cell
            if (connections[nextStreetType][opposite[dir]]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    return false;
}
    
};
