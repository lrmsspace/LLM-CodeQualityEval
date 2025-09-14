/**https://leetcode.com/problems/shortest-path-visiting-all-nodes/ */
//You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
//Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
// 
//Example 1:
//Input: graph = [[1,2,3],[0],[0],[0]]
//Output: 4
//Explanation: One possible path is [1,0,2,0,3]
//Example 2:
//Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
//Output: 4
//Explanation: One possible path is [0,1,4,2,3]
// 
//Constraints:
//	n == graph.length
//	1 <= n <= 12
//	0 <= graph[i].length < n
//	graph[i] does not contain i.
//	If graph[a] contains b, then graph[b] contains a.
//	The input graph is always connected.
/**
 * @param {number[][]} graph
 * @return {number}
 */
var shortestPathLength = function(graph) {
    const n = graph.length;
    const queue = [];
    const seen = new Array(n).fill(0).map(() => new Array(1 << n).fill(false));
    for (let i = 0; i < n; i++) {
        queue.push([i, 1 << i, 0]);
        seen[i][1 << i] = true;
    }
    let ans = 0;
    while (queue.length) {
        let [u, mask, dist] = queue.shift();
        if (mask === (1 << n) - 1) {
            ans = dist;
            break;
        }
        for (let v of graph[u]) {
            let maskV = mask | (1 << v);
            if (!seen[v][maskV]) {
                queue.push([v, maskV, dist + 1]);
                seen[v][maskV] = true;
            }
        }
    }
    return ans; 
};