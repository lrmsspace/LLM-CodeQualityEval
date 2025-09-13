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
        Map<Integer, Set<Integer>> rowMap = new HashMap<>();
        Map<Integer, Set<Integer>> colMap = new HashMap<>();
        Map<Integer, Set<Integer>> diaMap = new HashMap<>();
        Map<Integer, Set<Integer>> antiDiaMap = new HashMap<>();
        
        for (int[] lamp : lamps) {
            int row = lamp[0];
            int col = lamp[1];
            int dia = row + col;
            int antiDia = row - col;
            
            rowMap.computeIfAbsent(row, k -> new HashSet<>()).add(col);
            colMap.computeIfAbsent(col, k -> new HashSet<>()).add(row);
            diaMap.computeIfAbsent(dia, k -> new HashSet<>()).add(row);
            antiDiaMap.computeIfAbsent(antiDia, k -> new HashSet<>()).add(row);
        }
        
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int row = queries[i][0];
            int col = queries[i][1];
            int dia = row + col;
            int antiDia = row - col;
            
            if (rowMap.getOrDefault(row, Collections.emptySet()).contains(col) || 
                colMap.getOrDefault(col, Collections.emptySet()).contains(row) || 
                diaMap.getOrDefault(dia, Collections.emptySet()).contains(row) || 
                antiDiaMap.getOrDefault(antiDia, Collections.emptySet()).contains(row)) {
                result[i] = 1;
            }
            
            for (int r = row - 1; r <= row + 1; r++) {
                for (int c = col - 1; c <= col + 1; c++) {
                    if (r >= 0 && r < n && c >= 0 && c < n) {
                        int d = r + c;
                        int antiD = r - c;
                        rowMap.computeIfAbsent(r, k -> new HashSet<>()).remove(c);
                        colMap.computeIfAbsent(c, k -> new HashSet<>()).remove(r);
                        diaMap.computeIfAbsent(d, k -> new HashSet<>()).remove(r);
                        antiDiaMap.computeIfAbsent(antiD, k -> new HashSet<>()).remove(r);
                    }
                }
            }
        }
        
        return result;
    }
}