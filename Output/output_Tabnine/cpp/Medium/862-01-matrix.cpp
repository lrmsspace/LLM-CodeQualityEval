/**https://leetcode.com/problems/01-matrix/ */
//Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//The distance between two adjacent cells is 1.
// 
//Example 1:
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]
//Example 2:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//Output: [[0,0,0],[0,1,0],[1,2,1]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	mat[i][j] is either 0 or 1.
//	There is at least one 0 in mat.
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return dist;
        
    }
};