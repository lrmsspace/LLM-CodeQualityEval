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
    public int[] hitBricks(int[][] grid, int[][] hits) {
        int m = grid.length, n = grid[0].length;
        int[] result = new int[hits.length];
        UnionFind uf = new UnionFind(m * n + 1); // +1 for the virtual top node

        // Mark all hits in the grid
        for (int[] hit : hits) {
            int x = hit[0], y = hit[1];
            if (grid[x][y] == 1) {
                grid[x][y] = 0; // Mark as hit
            }
        }

        // Connect stable bricks to the virtual top node
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                uf.union(0, j + 1); // Connect to virtual top node
            }
        }

        // Connect remaining bricks in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    connect(grid, uf, i, j);
                }
            }
        }

        // Process hits in reverse order
        for (int i = hits.length - 1; i >= 0; i--) {
            int x = hits[i][0], y = hits[i][1];
            if (grid[x][y] == 0) { // If it was a hit
                grid[x][y] = 1; // Restore the brick
                if (x == 0) {
                    uf.union(0, y + 1); // Connect to virtual top node
                }
                connect(grid, uf, x, y); // Connect to adjacent bricks
                result[i] = uf.getCount() - 1; // Count the number of bricks that fell
            }
        }

        return result;
    }
}