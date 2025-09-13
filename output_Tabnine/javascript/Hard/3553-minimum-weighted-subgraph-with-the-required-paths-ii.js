/*
 You are given an undirected weighted tree with n nodes, numbered from 0 to n - 1. It is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates that there is an edge between nodes ui and vi with weight wi.​
 Additionally, you are given a 2D integer array queries, where queries[j] = [src1j, src2j, destj].
 Return an array answer of length equal to queries.length, where answer[j] is the minimum total weight of a subtree such that it is possible to reach destj from both src1j and src2j using edges in this subtree.
 A subtree here is any connected subset of nodes and edges of the original tree forming a valid tree.
 Example 1:
 Input: edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], queries = [[2,3,4],[0,2,5]]
 Output: [12,11]
 Explanation:
 The blue edges represent one of the subtrees that yield the optimal answer.
 answer[0]: The total weight of the selected subtree that ensures a path from src1 = 2 and src2 = 3 to dest = 4 is 3 + 5 + 4 = 12.
 answer[1]: The total weight of the selected subtree that ensures a path from src1 = 0 and src2 = 2 to dest = 5 is 2 + 3 + 6 = 11.
 Example 2:
 Input: edges = [[1,0,8],[0,2,7]], queries = [[0,1,2]]
 Output: [15]
 Explanation:
 answer[0]: The total weight of the selected subtree that ensures a path from src1 = 0 and src2 = 1 to dest = 2 is 8 + 7 = 15.
 Constraints:
 3 <= n <= 105
 edges.length == n - 1
 edges[i].length == 3
 0 <= ui, vi < n
 1 <= wi <= 104
 1 <= queries.length <= 105
 queries[j].length == 3
 0 <= src1j, src2j, destj < n
 src1j, src2j, and destj are pairwise distinct.
 The input is generated such that edges represents a valid tree.
*/

/**
 * @param {number[][]} edges
 * @param {number[][]} queries
 * @return {number[]}
 */
var minimumWeight = function(edges, queries) {
    const n = edges.length + 1;
    const graph = Array.from({ length: n }, () => new Set());
    const dist = Array.from({ length: n }, () => Infinity);
    const parent = Array.from({ length: n }, () => -1);
    
    edges.forEach(([u, v, w]) => {
        graph[u].add(v);
        graph[v].add(u);
    });
    
    function dfs(node, prev) {
        dist[node] = 0;
        graph[node].forEach(neighbor => {
            if (neighbor === prev) return;
            dfs(neighbor, node);
            dist[node] = Math.min(dist[node], dist[neighbor] + 1);
        });
    }
    dfs(0, -1);
    parent[0] = -1;
    for (let i = 1; i < n; i++) {
        parent[i] = dist.reduce((max, curr, j) => curr > max &&!graph[i].has(j)? j : max, -1);
    }
    return queries.map(([src1, src2, dest]) => {
        let curr = dest;
        let totalWeight = 0;
        while (curr!== -1) {
            totalWeight += edges[curr][2];
            curr = parent[curr];
        }
        curr = dest;
        while (curr!== -1) {
            const next = parent[curr];
            const edgeWeight = edges[curr][2];
            if (graph[src1].has(curr) && graph[src2].has(curr)) {
                totalWeight -= edgeWeight;
                break;
            }
            curr = next;
        }
        return totalWeight;
    });  
    
};