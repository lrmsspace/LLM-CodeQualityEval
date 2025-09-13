/**https://leetcode.com/problems/count-unguarded-cells-in-the-grid/ */
//You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
//A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
//Return the number of unoccupied cells that are not guarded.
// 
//Example 1:
//Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
//Output: 7
//Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
//There are a total of 7 unguarded cells, so we return 7.
//Example 2:
//Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
//Output: 4
//Explanation: The unguarded cells are shown in green in the above diagram.
//There are a total of 4 unguarded cells, so we return 4.
// 
//Constraints:
//	1 <= m, n <= 105
//	2 <= m * n <= 105
//	1 <= guards.length, walls.length <= 5 * 104
//	2 <= guards.length + walls.length <= m * n
//	guards[i].length == walls[j].length == 2
//	0 <= rowi, rowj < m
//	0 <= coli, colj < n
//	All the positions in guards and walls are unique.
class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        boolean[][] visited = new boolean[m][n];
        for (int[] guard : guards) {
            dfs(guard[0], guard[1], visited, 0, 1, m, n);
            dfs(guard[0], guard[1], visited, 0, -1, m, n);
            dfs(guard[0], guard[1], visited, 1, 0, m, n);
            dfs(guard[0], guard[1], visited, -1, 0, m, n);
        }
        for (int[] wall : walls) {
            visited[wall[0]][wall[1]] = true;
        }
        int res = 0;
        for (boolean[] row : visited) {
            for (boolean v : row) {
                if (!v) {
                    res++;
                }
            }
        }
        return res;
    }

    private void dfs(int i, int j, boolean[][] visited, int di, int dj, int m, int n) {
        int ni = i + di;
        int nj = j + dj;
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj]) {
            visited[ni][nj] = true;
            dfs(ni, nj, visited, di, dj, m, n);
        }
    }
}