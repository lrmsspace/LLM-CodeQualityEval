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
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        queue<tuple<int, int, int, int>> q; // (x, y, current steps, remaining k)
        q.push({0, 0, 0, k});
        visited[0][0][k] = 0;

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            auto [x, y, steps, rem_k] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) {
                return steps;
            }

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int new_k = rem_k - grid[nx][ny];

                    if (new_k >= 0 && visited[nx][ny][new_k] > steps + 1) {
                        visited[nx][ny][new_k] = steps + 1;
                        q.push({nx, ny, steps + 1, new_k});
                    }
                }
            }
        }

        return -1;

    }
};