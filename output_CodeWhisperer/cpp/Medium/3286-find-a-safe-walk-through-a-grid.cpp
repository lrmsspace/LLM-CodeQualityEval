/*
 You are given an m x n binary matrix grid and an integer health.
 You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).
 You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.
 Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.
 Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.
 Example 1:
 Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
 Output: true
 Explanation:
 The final cell can be reached safely by walking along the gray cells below.
 Example 2:
 Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3
 Output: false
 Explanation:
 A minimum of 4 health points is needed to reach the final cell safely.
 Example 3:
 Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5
 Output: true
 Explanation:
 The final cell can be reached safely by walking along the gray cells below.
 Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.
 Constraints:
 m == grid.length
 n == grid[i].length
 1 <= m, n <= 50
 2 <= m * n
 1 <= health <= m + n
 grid[i][j] is either 0 or 1.
*/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int m = grid.size();
    int n = grid[0].size();
    
    // visited array to store health at each position
    vector<vector<int>> visited(m, vector<int>(n, -1));
    
    // queue to store position and remaining health
    queue<pair<pair<int,int>, int>> q;
    q.push({{0,0}, health - grid[0][0]});
    visited[0][0] = health - grid[0][0];
    
    // directions array for up, down, left, right movement
    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        int x = curr.first.first;
        int y = curr.first.second;
        int currHealth = curr.second;
        
        // if reached destination with health > 0
        if(x == m-1 && y == n-1 && currHealth > 0) {
            return true;
        }
        
        // try all 4 directions
        for(auto dir : dirs) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            
            // check if new position is valid
            if(newX >= 0 && newX < m && newY >= 0 && newY < n) {
                int newHealth = currHealth - grid[newX][newY];
                
                // if new health is better than previously visited health
                if(newHealth > 0 && newHealth > visited[newX][newY]) {
                    visited[newX][newY] = newHealth;
                    q.push({{newX,newY}, newHealth});
                }
            }
        }
    }
    
    return false;
}                    
    
};