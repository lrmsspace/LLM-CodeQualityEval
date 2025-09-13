/**https://leetcode.com/problems/find-the-safest-path-in-a-grid/ */
//You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
//	A cell containing a thief if grid[r][c] = 1
//	An empty cell if grid[r][c] = 0
//You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
//The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
//Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
//An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
//The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.
// 
//Example 1:
//Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
//Output: 0
//Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
//Example 2:
//Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
//Output: 2
//Explanation: The path depicted in the picture above has a safeness factor of 2 since:
//- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
//It can be shown that there are no other paths with a higher safeness factor.
//Example 3:
//Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
//Output: 2
//Explanation: The path depicted in the picture above has a safeness factor of 2 since:
//- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
//- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
//It can be shown that there are no other paths with a higher safeness factor.
// 
//Constraints:
//	1 <= grid.length == n <= 400
//	grid[i].length == n
//	grid[i][j] is either 0 or 1.
//	There is at least one thief in the grid.
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == INT_MAX) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({dist[0][0], {0, 0}});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        while (!pq.empty()) {
            auto [d, p] = pq.top();
            pq.pop();
            int x = p.first, y = p.second;
            if (x == n - 1 && y == n - 1) {
                return d;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({min(d, dist[nx][ny]), {nx, ny}});
                }
            }
        }
        return -1;       
    }
};