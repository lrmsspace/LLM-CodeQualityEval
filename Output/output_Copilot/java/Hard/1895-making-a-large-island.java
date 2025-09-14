/**https://leetcode.com/problems/making-a-large-island/ */
//You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
//Return the size of the largest island in grid after applying this operation.
//An island is a 4-directionally connected group of 1s.
// 
//Example 1:
//Input: grid = [[1,0],[0,1]]
//Output: 3
//Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
//Example 2:
//Input: grid = [[1,1],[1,0]]
//Output: 4
//Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
//Example 3:
//Input: grid = [[1,1],[1,1]]
//Output: 4
//Explanation: Can't change any 0 to 1, only one island with area = 4.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 500
//	grid[i][j] is either 0 or 1.
class Solution {
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        int[][] area = new int[n][n];
        int maxArea = 0;
        int islandId = 2; // Start from 2 to avoid confusion with 0 and 1

        // First pass: calculate areas of all islands and mark them
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int areaSize = dfs(grid, i, j, islandId);
                    maxArea = Math.max(maxArea, areaSize);
                    islandId++;
                }
            }
        }

        // Second pass: check each 0 and calculate potential area if we change it to 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    Set<Integer> uniqueIslands = new HashSet<>();
                    int potentialArea = 1; // Change this 0 to a 1

                    // Check all four directions
                    for (int[] dir : new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                        int ni = i + dir[0], nj = j + dir[1];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            uniqueIslands.add(grid[ni][nj]);
                        }
                    }

                    // Calculate the total area by adding the areas of unique islands
                    for (int id : uniqueIslands) {
                        potentialArea += area[id - 2][i]; // id - 2 to get the correct index in area array
                    }

                    maxArea = Math.max(maxArea, potentialArea);
                }
            }
        }

        return maxArea;        
    }
}