/**https://leetcode.com/problems/number-of-enclaves/ */
//You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
//A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
//Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
// 
//Example 1:
//Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
//Output: 3
//Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
//Example 2:
//Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
//Output: 0
//Explanation: All 1s are either on the boundary or can reach the boundary.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 500
//	grid[i][j] is either 0 or 1.
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if(i == 0 || j == 0 || i == m - 1 || j == n - 1){
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
        }
        int dx[] = {0, 0, 1, -1}
        int dy[] = {1, -1, 0, 0};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
           }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]) ans++;
            }
        }
        return ans;
    }
};