/**https://leetcode.com/problems/shortest-bridge/ */
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//You may change 0's to 1's to connect the two islands to form one island.
//Return the smallest number of 0's you must flip to connect the two islands.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 1
//Example 2:
//Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
//Output: 2
//Example 3:
//Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//Output: 1
// 
//Constraints:
//	n == grid.length == grid[i].length
//	2 <= n <= 100
//	grid[i][j] is either 0 or 1.
//	There are exactly two islands in grid.
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny])
                            if(grid[nx][ny] == 1){
                                return 0;
                            }else if(grid[nx][ny] == 0){
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};