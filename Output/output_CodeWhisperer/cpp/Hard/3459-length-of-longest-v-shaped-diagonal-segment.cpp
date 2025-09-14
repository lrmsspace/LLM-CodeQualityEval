/*
 You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.
 A V-shaped diagonal segment is defined as:
 The segment starts with 1.
 The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
 The segment:
 Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
 Continues the sequence in the same diagonal direction.
 Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.
 Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.
 Example 1:
 Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
 Output: 5
 Explanation:
 The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at (2,4), and continues as (3,3) → (4,2).
 Example 2:
 Input: grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
 Output: 4
 Explanation:
 The longest V-shaped diagonal segment has a length of 4 and follows these coordinates: (2,3) → (3,2), takes a 90-degree clockwise turn at (3,2), and continues as (2,1) → (1,0).
 Example 3:
 Input: grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]
 Output: 5
 Explanation:
 The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,0) → (1,1) → (2,2) → (3,3) → (4,4).
 Example 4:
 Input: grid = [[1]]
 Output: 1
 Explanation:
 The longest V-shaped diagonal segment has a length of 1 and follows these coordinates: (0,0).
 Constraints:
 n == grid.length
 m == grid[i].length
 1 <= n, m <= 500
 grid[i][j] is either 0, 1 or 2.
*/

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int maxLen = 0;
    
    // 8 possible directions for diagonal movement
    vector<pair<int,int>> dirs = {{1,1}, {1,-1}, {-1,1}, {-1,-1}};
    
    // Try each cell as starting point
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != 1) continue;
            
            // Try each direction
            for(int d = 0; d < 4; d++) {
                int x = i, y = j;
                int len = 1;
                bool turned = false;
                int expect = 2; // Next expected number in sequence
                
                // Keep moving in current direction
                while(true) {
                    int nx = x + dirs[d].first;
                    int ny = y + dirs[d].second;
                    
                    // Check if next position is valid
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != expect) {
                        // Try turning if not turned yet
                        if(!turned) {
                            turned = true;
                            // Try other directions after turning
                            for(int nd = 0; nd < 4; nd++) {
                                if(nd == d || nd == (d^1)) continue; // Skip same or opposite direction
                                
                                int tx = x + dirs[nd].first;
                                int ty = y + dirs[nd].second;
                                
                                if(tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == expect) {
                                    d = nd;
                                    x = tx;
                                    y = ty;
                                    len++;
                                    expect = expect == 2 ? 0 : 2;
                                    goto CONTINUE;
                                }
                            }
                        }
                        break;
                    }
                    
                    x = nx;
                    y = ny;
                    len++;
                    expect = expect == 2 ? 0 : 2;
                    
                    CONTINUE:;
                }
                
                maxLen = max(maxLen, len);
            }
        }
    }
    
    return maxLen;
}             
};