/**https://leetcode.com/problems/grid-illumination/ */
//There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.
//You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.
//When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.
//You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].
//Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.
// 
//Example 1:
//Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
//Output: [1,0]
//Explanation: We have the initial grid with all lamps turned off. In the above picture we see the grid after turning on the lamp at grid[0][0] then turning on the lamp at grid[4][4].
//The 0th query asks if the lamp at grid[1][1] is illuminated or not (the blue square). It is illuminated, so set ans[0] = 1. Then, we turn off all lamps in the red square.
//The 1st query asks if the lamp at grid[1][0] is illuminated or not (the blue square). It is not illuminated, so set ans[1] = 0. Then, we turn off all lamps in the red rectangle.
//Example 2:
//Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
//Output: [1,1]
//Example 3:
//Input: n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
//Output: [1,1,0]
// 
//Constraints:
//	1 <= n <= 109
//	0 <= lamps.length <= 20000
//	0 <= queries.length <= 20000
//	lamps[i].length == 2
//	0 <= rowi, coli < n
//	queries[j].length == 2
//	0 <= rowj, colj < n
class Solution {
    public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
        int[] ans = new int[queries.length];
        boolean[][] lamp = new boolean[n][n];
        int[][] count = new int[n][n];
        
        for (int[] lampPos : lamps) {
            int row = lampPos[0], col = lampPos[1];
            lamp[row][col] = true;
            count[row][col]++;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    int x = row + i, y = col + j;
                    if (0 <= x && x < n && 0 <= y && y < n) {
                        count[x][y]++;
                    }
                }
            }
        }
        
        for (int i = 0; i < queries.length; i++) {
            int row = queries[i][0], col = queries[i][1];
            if (lamp[row][col]) {
                ans[i] = 1;
                for (int i1 = -1; i1 <= 1; i1++) {
                    for (int j1 = -1; j1 <= 1; j1++) {
                        if (i1 == 0 && j1 == 0) continue;
                        int x = row + i1, y = col + j1;
                        if (0 <= x && x < n && 0 <= y && y < n) {
                            count[x][y]--;
                            if (count[x][y] == 0) {
                                lamp[x][y] = false;
                            }
                        }
                    }
                }
            } else {
                ans[i] = 0;
            }
        }
        
        return ans;
        
    }
}