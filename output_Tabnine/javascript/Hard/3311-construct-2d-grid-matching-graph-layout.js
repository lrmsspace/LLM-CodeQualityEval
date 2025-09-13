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

/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[][]}
 */
var constructGridLayout = function(n, edges) {

    // Step 1: Create a 2D grid of size n x n with all nodes initialized to -1
    let grid = Array.from({length: n}, () => Array(n).fill(-1));
    
    // Step 2: Create a set to store the nodes that have been visited
    let visited = new Set();
    
    // Step 3: Iterate through the edges and mark the nodes in the grid
    for (let edge of edges) {
        let [u, v] = edge;
        grid[u][v] = u;
        grid[v][u] = v;
        visited.add(u);
        visited.add(v);
    }
    // Step 4: Find a starting node that has not been visited
    let startNode = -1;
    for (let i = 0; i < n; i++) {
        if (!visited.has(i)) {
            startNode = i;
            break;
        }
    }
    
    // Step 5: Perform a depth-first search (DFS) from the starting node to fill the grid

    // Helper function to perform DFS
    function dfs(node, row, col) {
        if (row < 0 || row >= n || col < 0 || col >= n || grid[row][col]!== -1) {
            return;
        }
        grid[row][col] = node;
        visited.add(node);
        dfs(node, row + 1, col); // Down
        dfs(node, row - 1, col); // Up
        dfs(node, row, col + 1); // Right
        dfs(node, row, col - 1); // Left
    }
    
    dfs(startNode, 0, 0); // Start DFS from the starting node
    
    // Step 6: Return the filled grid
    return grid;
    
};