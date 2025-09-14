/**https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/ */
//You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
//Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.
// 
//Example 1:
//Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
//Output: 6
//Explanation: 
//The shortest path without eliminating any obstacle is 10.
//The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
//Example 2:
//Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
//Output: -1
//Explanation: We need to eliminate at least two obstacles to find such a walk.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 40
//	1 <= k <= m * n
//	grid[i][j] is either 0 or 1.
//	grid[0][0] == grid[m - 1][n - 1] == 0
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if(m == 1 && n == 1) return 0;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        dist[0][0] = 0;
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            int i = curr[0], j = curr[1], d = curr[2], k = curr[3];
            if(i == m - 1 && j == n - 1) return d;
            for(int x = -1; x<= 1; x++){
                for(int y = -1; y <= 1; y++){
                    if(abs(x) != abs(y) && i + x >= 0 && i + x < m && j + y >= 0 && j + y < n){
                        int new_k = k - grid[i + x][j + y];
                        if(new_k >= 0 && d + 1 < dist[i + x][j + y]){
                            dist[i + x][j + y] = d + 1;
                            q.push({i + x, j + y, d + 1, new_k});
                        }
                    }
                }
            }
        }
        return -1;
    }
};