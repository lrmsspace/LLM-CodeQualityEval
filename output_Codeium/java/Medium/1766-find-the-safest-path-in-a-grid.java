/**https://leetcode.com/problems/find-the-safest-path-in-a-grid/ */
//You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
//	A cell containing a thief if grid[r][c] = 1
//	An empty cell if grid[r][c] = 0
//You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
//The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
//Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
//An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
//The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.
// 
//Example 1:
//Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
//Output: 0
//Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
//Example 2:
//Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
//Output: 2
//Explanation: The path depicted in the picture above has a safeness factor of 2 since:
//- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
//It can be shown that there are no other paths with a higher safeness factor.
//Example 3:
//Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
//Output: 2
//Explanation: The path depicted in the picture above has a safeness factor of 2 since:
//- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
//- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
//It can be shown that there are no other paths with a higher safeness factor.
// 
//Constraints:
//	1 <= grid.length == n <= 400
//	grid[i].length == n
//	grid[i][j] is either 0 or 1.
//	There is at least one thief in the grid.
class Solution {
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        int[][] distance = new int[n][n];
        
        for (int[] row : distance) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        
        Queue<int[]> queue = new LinkedList<>();
        
        // Add all thief positions to the queue and set their distance to 0
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid.get(r).get(c) == 1) {
                    queue.add(new int[]{r, c});
                    distance[r][c] = 0;
                }
            }
        }
        
        // Directions for moving up, down, left, right
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // BFS to calculate minimum distance to a thief for each cell
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int r = cell[0], c = cell[1];
            
            for (int[] d : directions) {
                int nr = r + d[0], nc = c + d[1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && distance[nr][nc] == Integer.MAX_VALUE) {
                    distance[nr][nc] = distance[r][c] + 1;
                    queue.add(new int[]{nr, nc});
                }
            }
        }
        
        // Binary search for maximum safeness factor
        int left = 0, right = 2 * n;
        
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canReachEnd(grid, distance, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
    
    private boolean canReachEnd(List<List<Integer>> grid, int[][] distance, int safenessFactor) {
        int n = grid.size();
        boolean[][] visited = new boolean[n][n];
        Queue<int[]> queue = new LinkedList<>();
        
        if (distance[0][0] < safenessFactor) {
            return false;
        }
        
        queue.add(new int[]{0, 0});
        visited[0][0] = true;
        
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int r = cell[0], c = cell[1];
            
            if (r == n - 1 && c == n - 1) {
                return true;
            }
            
            for (int[] d : directions) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && distance[nr][nc] >= safenessFactor) {
                    visited[nr][nc] = true;
                    queue.add(new int[]{nr, nc});
                }
            }
        }
        
        return false;
    }   
}