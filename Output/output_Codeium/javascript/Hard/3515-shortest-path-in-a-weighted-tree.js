/*
 You are given an integer n and an undirected, weighted tree rooted at node 1 with n nodes numbered from 1 to n. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates an undirected edge from node ui to vi with weight wi.
 You are also given a 2D integer array queries of length q, where each queries[i] is either:
 [1, u, v, w'] – Update the weight of the edge between nodes u and v to w', where (u, v) is guaranteed to be an edge present in edges.
 [2, x] – Compute the shortest path distance from the root node 1 to node x.
 Return an integer array answer, where answer[i] is the shortest path distance from node 1 to x for the ith query of [2, x].
 Example 1:
 Input: n = 2, edges = [[1,2,7]], queries = [[2,2],[1,1,2,4],[2,2]]
 Output: [7,4]
 Explanation:
 Query [2,2]: The shortest path from root node 1 to node 2 is 7.
 Query [1,1,2,4]: The weight of edge (1,2) changes from 7 to 4.
 Query [2,2]: The shortest path from root node 1 to node 2 is 4.
 Example 2:
 Input: n = 3, edges = [[1,2,2],[1,3,4]], queries = [[2,1],[2,3],[1,1,3,7],[2,2],[2,3]]
 Output: [0,4,2,7]
 Explanation:
 Query [2,1]: The shortest path from root node 1 to node 1 is 0.
 Query [2,3]: The shortest path from root node 1 to node 3 is 4.
 Query [1,1,3,7]: The weight of edge (1,3) changes from 4 to 7.
 Query [2,2]: The shortest path from root node 1 to node 2 is 2.
 Query [2,3]: The shortest path from root node 1 to node 3 is 7.
 Example 3:
 Input: n = 4, edges = [[1,2,2],[2,3,1],[3,4,5]], queries = [[2,4],[2,3],[1,2,3,3],[2,2],[2,3]]
 Output: [8,3,2,5]
 Explanation:
 Query [2,4]: The shortest path from root node 1 to node 4 consists of edges (1,2), (2,3), and (3,4) with weights 2 + 1 + 5 = 8.
 Query [2,3]: The shortest path from root node 1 to node 3 consists of edges (1,2) and (2,3) with weights 2 + 1 = 3.
 Query [1,2,3,3]: The weight of edge (2,3) changes from 1 to 3.
 Query [2,2]: The shortest path from root node 1 to node 2 is 2.
 Query [2,3]: The shortest path from root node 1 to node 3 consists of edges (1,2) and (2,3) with updated weights 2 + 3 = 5.
 Constraints:
 1 <= n <= 105
 edges.length == n - 1
 edges[i] == [ui, vi, wi]
 1 <= ui, vi <= n
 1 <= wi <= 104
 The input is generated such that edges represents a valid tree.
 1 <= queries.length == q <= 105
 queries[i].length == 2 or 4
 queries[i] == [1, u, v, w'] or,
 queries[i] == [2, x]
 1 <= u, v, x <= n
 (u, v) is always an edge from edges.
 1 <= w' <= 104
*/

/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[][]} queries
 * @return {number[]}
 */
var treeQueries = function(n, edges, queries) {
    let adj = new Array(n).fill(0).map(() => []);
    for (let e of edges) {
        adj[e[0] - 1].push([e[1] - 1, e[2]]);
        adj[e[1] - 1].push([e[0] - 1, e[2]]);
    }
    
    let res = [];
    for (let q of queries) {
        if (q[0] === 1) {
            let u = q[1] - 1, v = q[2] - 1, w = q[3];
            for (let i = 0; i < adj[u].length; ++i) {
                if (adj[u][i][0] === v) {
                    adj[u][i][1] = w;
                    break;
                }
            }
            for (let i = 0; i < adj[v].length; ++i) {
                if (adj[v][i][0] === u) {
                    adj[v][i][1] = w;
                    break;
                }
            }
        } else {
            let x = q[1] - 1;
            let dist = 0;
            let q = [0];
            let vis = new Array(n).fill(false);
            while (q.length) {
                let now = q.shift();
                if (vis[now]) continue;
                vis[now] = true;
                for (let e of adj[now]) {
                    if (e[0] === x) {
                        dist += e[1];
                        break;
                    }
                    if (!vis[e[0]]) {
                        q.push(e[0]);
                    }
                }
            }
            res.push(dist);
        }
    }
    return res;
};