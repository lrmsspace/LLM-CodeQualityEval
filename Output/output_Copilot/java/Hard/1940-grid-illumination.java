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
        Set<Long> lampSet = new HashSet<>();
        Map<Long, Integer> rowMap = new HashMap<>();
        Map<Long, Integer> colMap = new HashMap<>();
        Map<Long, Integer> diag1Map = new HashMap<>();
        Map<Long, Integer> diag2Map = new HashMap<>();

        for (int[] lamp : lamps) {
            long row = lamp[0], col = lamp[1];
            long key = row * n + col;
            lampSet.add(key);
            rowMap.put(row, rowMap.getOrDefault(row, 0) + 1);
            colMap.put(col, colMap.getOrDefault(col, 0) + 1);
            diag1Map.put(row - col, diag1Map.getOrDefault(row - col, 0) + 1);
            diag2Map.put(row + col, diag2Map.getOrDefault(row + col, 0) + 1);
        }

        for (int i = 0; i < queries.length; i++) {
            int row = queries[i][0], col = queries[i][1];
            if (rowMap.containsKey((long) row) || colMap.containsKey((long) col)
                    || diag1Map.containsKey((long) (row - col)) || diag2Map.containsKey((long) (row + col))) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
            for (int r = row - 1; r <= row + 1; r++) {
                for (int c = col - 1; c <= col + 1; c++) {
                    long key = (long) r * n + c;
                    if (lampSet.remove(key)) {
                        rowMap.put(r, rowMap.get(r) - 1);
                        if (rowMap.get(r) == 0) {
                            rowMap.remove(r);
                        }
                        colMap.put(c, colMap.get(c) - 1);
                        if (colMap.get(c) == 0) {
                            colMap.remove(c);
                        }
                        diag1Map.put(r - c, diag1Map.get(r - c) - 1);
                        if (diag1Map.get(r - c) == 0) {
                            diag1Map.remove(r - c);
                        }
                        diag2Map.put(r + c, diag2Map.get(r + c) - 1);
                        if (diag2Map.get(r + c) == 0) {
                            diag2Map.remove(r + c);
                        }
    }
                    }
                }
            }
             return ans;
        }   
}