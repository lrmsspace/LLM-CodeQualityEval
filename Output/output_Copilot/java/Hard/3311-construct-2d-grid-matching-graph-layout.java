/*
 You are given a 2D integer array edges representing an undirected graph having n nodes, where edges[i] = [ui, vi] denotes an edge between nodes ui and vi.
 Construct a 2D grid that satisfies these conditions:
 The grid contains all nodes from 0 to n - 1 in its cells, with each node appearing exactly once.
 Two nodes should be in adjacent grid cells (horizontally or vertically) if and only if there is an edge between them in edges.
 It is guaranteed that edges can form a 2D grid that satisfies the conditions.
 Return a 2D integer array satisfying the conditions above. If there are multiple solutions, return any of them.
 Example 1:
 Input: n = 4, edges = [[0,1],[0,2],[1,3],[2,3]]
 Output: [[3,1],[2,0]]
 Explanation:
 Example 2:
 Input: n = 5, edges = [[0,1],[1,3],[2,3],[2,4]]
 Output: [[4,2,3,1,0]]
 Explanation:
 Example 3:
 Input: n = 9, edges = [[0,1],[0,4],[0,5],[1,7],[2,3],[2,4],[2,5],[3,6],[4,6],[4,7],[6,8],[7,8]]
 Output: [[8,6,3],[7,4,2],[1,0,5]]
 Explanation:
 Constraints:
 2 <= n <= 5 * 104
 1 <= edges.length <= 105
 edges[i] = [ui, vi]
 0 <= ui < vi < n
 All the edges are distinct.
 The input is generated such that edges can form a 2D grid that satisfies the conditions.
*/

class Solution {
    public int[][] constructGridLayout(int n, int[][] edges) {
        int[][] grid = new int[n][n];
        boolean[][] visited = new boolean[n][n];
        int[] dx = {0, 1, 0, -1}; // Directions for right, down, left, up
        int[] dy = {1, 0, -1, 0};
        
        // Create a mapping of edges to adjacency list
        List<Integer>[] adjList = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adjList[i] = new ArrayList<>();
        }
        
        for (int[] edge : edges) {
            adjList[edge[0]].add(edge[1]);
            adjList[edge[1]].add(edge[0]);
        }
        
        // Start placing nodes in the grid
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            grid[x][y] = i;
            visited[x][y] = true;
            
            // Try to move to an adjacent cell based on the adjacency list
            boolean placed = false;
            for (int neighbor : adjList[i]) {
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 0) {
                        x = nx;
                        y = ny;
                        placed = true;
                        break;
                    }
                }
                if (placed) break;
            }
            
            // If no adjacent cell was found, move to the next row
            if (!placed) {
                x++;
                y = 0;
                if (x >= n) break; // Prevent going out of bounds
            }
        }
        
        return grid;
            
    }
}