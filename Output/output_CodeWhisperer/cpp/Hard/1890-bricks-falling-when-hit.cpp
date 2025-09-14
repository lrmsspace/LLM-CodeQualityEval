/**https://leetcode.com/problems/bricks-falling-when-hit/ */
//You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if:
//	It is directly connected to the top of the grid, or
//	At least one other brick in its four adjacent cells is stable.
//You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks).
//Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.
//Note that an erasure may refer to a location with no brick, and if it does, no bricks drop.
// 
//Example 1:
//Input: grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
//Output: [2]
//Explanation: Starting with the grid:
//[[1,0,0,0],
// [1,1,1,0]]
//We erase the underlined brick at (1,0), resulting in the grid:
//[[1,0,0,0],
// [0,1,1,0]]
//The two underlined bricks are no longer stable as they are no longer connected to the top nor adjacent to another stable brick, so they will fall. The resulting grid is:
//[[1,0,0,0],
// [0,0,0,0]]
//Hence the result is [2].
//Example 2:
//Input: grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
//Output: [0,0]
//Explanation: Starting with the grid:
//[[1,0,0,0],
// [1,1,0,0]]
//We erase the underlined brick at (1,1), resulting in the grid:
//[[1,0,0,0],
// [1,0,0,0]]
//All remaining bricks are still stable, so no bricks fall. The grid remains the same:
//[[1,0,0,0],
// [1,0,0,0]]
//Next, we erase the underlined brick at (1,0), resulting in the grid:
//[[1,0,0,0],
// [0,0,0,0]]
//Once again, all remaining bricks are still stable, so no bricks fall.
//Hence the result is [0,0].
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 200
//	grid[i][j] is 0 or 1.
//	1 <= hits.length <= 4 * 104
//	hits[i].length == 2
//	0 <= xi <= m - 1
//	0 <= yi <= n - 1
//	All (xi, yi) are unique.    
class Solution {
    public:
        vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
            int m = grid.size();
            int n = grid[0].size();
            int numHits = hits.size();
            
            // Step 1: Create a copy of the grid and mark all bricks that will be hit
            vector<vector<int>> workGrid = grid;
            for (auto& hit : hits) {
                // Mark the brick as "to be removed" (set to 2)
                // This way we can distinguish between "no brick" (0) and "removed brick" (2)
                if (workGrid[hit[0]][hit[1]] == 1) {
                    workGrid[hit[0]][hit[1]] = 2;
                }
            }
            
            // Step 2: Connect all stable bricks (ignoring the ones that will be hit)
            DSU dsu(m * n + 1);  // +1 for the virtual "roof" node
            int roof = m * n;
            
            // Process the grid, ignoring bricks that will be hit
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (workGrid[i][j] != 1) continue;  // Skip empty cells and bricks to be removed
                    
                    // Connect to the roof if in the top row
                    if (i == 0) {
                        dsu.unite(getIndex(i, j, n), roof);
                    }
                    
                    // Connect to adjacent bricks
                    if (i > 0 && workGrid[i-1][j] == 1) {
                        dsu.unite(getIndex(i, j, n), getIndex(i-1, j, n));
                    }
                    if (j > 0 && workGrid[i][j-1] == 1) {
                        dsu.unite(getIndex(i, j, n), getIndex(i, j-1, n));
                    }
                }
            }
            
            // Step 3: Add bricks back in reverse order and count falling bricks
            vector<int> result(numHits, 0);
            vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            
            for (int k = numHits - 1; k >= 0; k--) {
                int row = hits[k][0];
                int col = hits[k][1];
                
                // Skip if there was no brick at this position
                if (grid[row][col] == 0) continue;
                
                // Count stable bricks before adding this brick back
                int beforeCount = dsu.size(roof);
                
                // Add the brick back
                workGrid[row][col] = 1;
                
                // If this brick is in the top row, connect it to the roof
                if (row == 0) {
                    dsu.unite(getIndex(row, col, n), roof);
                }
                
                // Connect to adjacent bricks
                for (auto& dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;
                    
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && 
                        workGrid[newRow][newCol] == 1) {
                        dsu.unite(getIndex(row, col, n), getIndex(newRow, newCol, n));
                    }
                }
                
                // Count stable bricks after adding this brick back
                int afterCount = dsu.size(roof);
                
                // Calculate how many new bricks became stable
                // Subtract 1 for the brick we just added (if it became stable)
                int addedBrick = dsu.find(getIndex(row, col, n)) == dsu.find(roof) ? 1 : 0;
                result[k] = max(0, afterCount - beforeCount - addedBrick);
            }
            
            return result;
        }
        
    private:
        // Helper function to convert 2D coordinates to 1D index
        int getIndex(int row, int col, int n) {
            return row * n + col;
        }
        
        // Disjoint Set Union data structure with size tracking
        class DSU {
        public:
            DSU(int n) {
                parent.resize(n);
                size.resize(n, 1);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }
            
            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }
            
            void unite(int x, int y) {
                int rootX = find(x);
                int rootY = find(y);
                
                if (rootX != rootY) {
                    parent[rootX] = rootY;
                    size[rootY] += size[rootX];
                }
            }
            
            int size(int x) {
                return size[find(x)];
            }
            
        private:
            vector<int> parent;
            vector<int> size;
        };
    };
    