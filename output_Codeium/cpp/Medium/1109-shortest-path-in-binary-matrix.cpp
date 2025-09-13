/**https://leetcode.com/problems/shortest-path-in-binary-matrix/ */
//Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
//A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
//	All the visited cells of the path are 0.
//	All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
//The length of a clear path is the number of visited cells of this path.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 2
//Example 2:
//Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
//Output: 4
//Example 3:
//Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
//Output: -1
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int step = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int _ = 0; _ < sz; ++_) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x == n-1 && y == n-1) return step;
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        int nx = x + i;
                        int ny = y + j;
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny] == 1) continue;
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};