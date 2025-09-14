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
    const graph = new Map();
    const degree = new Array(n).fill(0);
    
    for (const [u, v] of edges) {
        if (!graph.has(u)) {
            graph.set(u, []);
        }
        if (!graph.has(v)) {
            graph.set(v, []);
        }
        graph.get(u).push(v);
        graph.get(v).push(u);
        degree[u]++;
        degree[v]++;
    }
    
    const nodes = Array.from({ length: n }, (_, i) => i);
    nodes.sort((a, b) => degree[b] - degree[a]);
    
    const result = Array.from({ length: n }, () => new Array(n));
    const row = Math.floor(Math.sqrt(n));
    const col = Math.ceil(n / row);
    
    for (let i = 0; i < n; i++) {
        const x = Math.floor(i / col);
        const y = i % col;
        const node = nodes[i];
        result[x][y] = node;
        
        if (graph.has(node)) {
            for (const neighbor of graph.get(node)) {
                if (x > 0 && result[x - 1][y] === neighbor) {
                    [result[x][y], result[x - 1][y]] = [result[x - 1][y], result[x][y]];
                } else if (y > 0 && result[x][y - 1] === neighbor) {
                    [result[x][y], result[x][y - 1]] = [result[x][y - 1], result[x][y]];
                }
            }
        }
    }
    
    return result;
        
};