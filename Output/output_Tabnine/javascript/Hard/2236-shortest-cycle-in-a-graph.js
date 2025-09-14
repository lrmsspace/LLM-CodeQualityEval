/**https://leetcode.com/problems/shortest-cycle-in-a-graph/ */
//There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
//Return the length of the shortest cycle in the graph. If no cycle exists, return -1.
//A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.
// 
//Example 1:
//Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
//Output: 3
//Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 
//Example 2:
//Input: n = 4, edges = [[0,1],[0,2]]
//Output: -1
//Explanation: There are no cycles in this graph.
// 
//Constraints:
//	2 <= n <= 1000
//	1 <= edges.length <= 1000
//	edges[i].length == 2
//	0 <= ui, vi < n
//	ui != vi
//	There are no repeated edges.
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var findShortestCycle = function(n, edges) {
    // Initialize the adjacency list
    const adjList = Array.from({length: n}, () => []);
    for (const [u, v] of edges) {
        adjList[u].push(v);
        adjList[v].push(u);
    }
    
    // Initialize the visited array
    const visited = Array.from({length: n}, () => false);
    
    // Initialize the parent array
    const parent = Array.from({length: n}, () => -1);
    
    // Function to find the shortest cycle
    function dfs(node, prevNode) {
        visited[node] = true;
        
        for (const neighbor of adjList[node]) {
            if (!visited[neighbor]) {
                parent[neighbor] = node;
                const cycleLength = dfs(neighbor, node);
                
                // If a cycle is found, return the length
                if (cycleLength > 0) {
                    return cycleLength + 1;
                }
            } else if (neighbor!== prevNode) {
                // If the neighbor is visited and not the previous node, it means we have found a cycle
                return neighbor === parent[node]? neighbor : -1;
            }
        }
        
        visited[node] = false;
        return 0;
    }
    
    // Find the shortest cycle
    let shortestCycle = Infinity;
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            const cycleLength = dfs(i, -1);
            shortestCycle = Math.min(shortestCycle, cycleLength);
        }
    }
    
    return shortestCycle === Infinity? -1 : shortestCycle;
    
};