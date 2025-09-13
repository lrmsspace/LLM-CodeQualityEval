/**https://leetcode.com/problems/max-area-of-island/ */
//You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//The area of an island is the number of cells with a value 1 in the island.
//Return the maximum area of an island in grid. If there is no island, return 0.
// 
//Example 1:
//Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
//Output: 6
//Explanation: The answer is not 11, because the island must be connected 4-directionally.
//Example 2:
//Input: grid = [[0,0,0,0,0,0,0,0]]
//Output: 0
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	grid[i][j] is either 0 or 1.
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        int x = p.first;
                        int y = p.second;
                        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0){
                            continue;
                        }
                        area++;
                        grid[x][y] = 0;
                        q.push({x-1, y});
                        q.push({x+1, y});
                        q.push({x, y-1});
                        q.push({x, y+1});
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};