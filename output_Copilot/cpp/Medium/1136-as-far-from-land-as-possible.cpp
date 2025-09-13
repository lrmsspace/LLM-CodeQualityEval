/**https://leetcode.com/problems/as-far-from-land-as-possible/ */
//Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
//The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
// 
//Example 1:
//Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
//Output: 2
//Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
//Example 2:
//Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
//Output: 4
//Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 100
//	grid[i][j] is 0 or 1
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    q.push({i, j});
        if(q.size() == n * n || q.empty())
            return -1;
        int res = 0;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [x, y] = q.front();
                q.pop();
                for(auto dir : dirs) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny] == 1)
                        continue;
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            res++;
        }
        return res - 1;        
    }
};