/**https://leetcode.com/problems/shortest-path-with-alternating-colors/ */
//You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.
//You are given two arrays redEdges and blueEdges where:
//	redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
//	blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
//Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.
// 
//Example 1:
//Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
//Output: [0,1,-1]
//Example 2:
//Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
//Output: [0,1,-1]
// 
//Constraints:
//	1 <= n <= 100
//	0 <= redEdges.length, blueEdges.length <= 400
//	redEdges[i].length == blueEdges[j].length == 2
//	0 <= ai, bi, uj, vj < n
/**
 * @param {number} n
 * @param {number[][]} redEdges
 * @param {number[][]} blueEdges
 * @return {number[]}
 */
var shortestAlternatingPaths = function(n, redEdges, blueEdges) {
    const graph = Array(n).fill(null).map(() => new Map());
    redEdges.forEach(([a, b]) => graph[a].set(b, 1));
    blueEdges.forEach(([a, b]) => graph[a].set(b, -1));
    
    const queue = [[0, 0]];
    const visited = new Set([0]);
    const dist = Array(n).fill(Infinity);
    dist[0] = 0;
    
    while (queue.length) {
        const [node, color] = queue.shift();
        for (const [neighbor, edgeColor] of graph[node]) {
            const newColor = edgeColor === color? -color : color;
            if (!visited.has(neighbor)) {
                visited.add(neighbor);
                dist[neighbor] = Math.min(dist[neighbor], dist[node] + 1);
                queue.push([neighbor, newColor]);
            }
        }
    }
    return dist.map(d => d === Infinity? -1 : d);
    
};