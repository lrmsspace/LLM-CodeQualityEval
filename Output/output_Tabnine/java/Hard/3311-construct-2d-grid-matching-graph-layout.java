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

        // Step 1: Create a boolean array to keep track of visited nodes
        boolean[] visited = new boolean[n];
        // Step 2: Create a 2D grid with n rows and n columns
        int[][] grid = new int[n][n];
        // Step 3: Create a list to store the nodes that have not been visited yet
        List<Integer> unvisitedNodes = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            unvisitedNodes.add(i);
        }
        // Step 4: Randomly select a node to start the grid construction
        int startNode = unvisitedNodes.get(new Random().nextInt(unvisitedNodes.size()));
        // Step 5: Add the start node to the grid and mark it as visited
        grid[0][0] = startNode;
        visited[startNode] = true;
        unvisitedNodes.remove(Integer.valueOf(startNode));
        // Step 6: Construct the grid using the edges
        for (int[] edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            // Step 7: Add the connected nodes to the grid
            grid[node1][node2] = node2;
            grid[node2][node1] = node1;
            // Step 8: Mark the connected nodes as visited
            visited[node1] = true;
            visited[node2] = true;
            // Step 9: Remove the connected nodes from the unvisited nodes list
            unvisitedNodes.remove(Integer.valueOf(node1));
            unvisitedNodes.remove(Integer.valueOf(node2));
    
            // Step 10: Check if the grid is fully constructed
            if (unvisitedNodes.isEmpty()) {
                break;
            }
        }
        // Step 11: Fill the remaining cells of the grid with unvisited nodes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    grid[i][j] = unvisitedNodes.get(new Random().nextInt(unvisitedNodes.size()));
                }
            }
        }
        // Step 12: Return the constructed grid
        return grid;
        
    }
}