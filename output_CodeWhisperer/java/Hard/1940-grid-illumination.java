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
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.HashMap;
class Solution {
    public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
        Map<Integer, Integer> row = new HashMap<>(), col = new HashMap<>(), diag1 = new HashMap<>(), diag2 = new HashMap<>();
        Set<Long> points = new HashSet<>();
        
        for (int[] l : lamps) {
            int x = l[0], y = l[1];
            int a = x + y, b = x - y;
            row.put(x, row.getOrDefault(x, 0) + 1);
            col.put(y, col.getOrDefault(y, 0) + 1);
            diag1.put(a, diag1.getOrDefault(a, 0) + 1);
            diag2.put(b, diag2.getOrDefault(b, 0) + 1);
            points.add(x * (long)n + y);
        }
        
        int[] ans = new int[queries.length];
        int[][] dirs = {{0,0},{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1}};
        
        for (int i = 0; i < queries.length; i++) {
            int x = queries[i][0], y = queries[i][1];
            int a = x + y, b = x - y;
            if (row.getOrDefault(x, 0) > 0 || col.getOrDefault(y, 0) > 0 || diag1.getOrDefault(a, 0) > 0 || diag2.getOrDefault(b, 0) > 0)
                ans[i] = 1;
            
            for (int[] d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                int na = nx + ny, nb = nx - ny;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (points.remove(nx * (long)n + ny)) {
                    row.put(nx, row.get(nx) - 1);
                    col.put(ny, col.get(ny) - 1);
                    diag1.put(na, diag1.get(na) - 1);
                    diag2.put(nb, diag2.get(nb) - 1);
                }
            }
        }
        
        return ans;      
    }
}