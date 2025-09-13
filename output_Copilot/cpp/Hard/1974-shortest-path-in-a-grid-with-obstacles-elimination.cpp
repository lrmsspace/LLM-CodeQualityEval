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
        if (m == 1 && n == 1) return 0;
        if (m + n - 2 <= k) return m + n - 2;
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0});
        visited[0][0] = 0;
        int steps = 0;
        while (!q.empty()) {
            steps++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto cur = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int x = cur[0] + dirs[j], y = cur[1] + dirs[j + 1];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    int ob = cur[2] + grid[x][y];
                    if (ob > k || (visited[x][y] != -1 && visited[x][y] <= ob)) continue;
                    if (x == m - 1 && y == n - 1) return steps;
                    visited[x][y] = ob;
                    q.push({x, y, ob});
                }
            }
        }
        return -1;        
    }
};