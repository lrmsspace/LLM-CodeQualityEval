/**https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/ */
//Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
//Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
//Note that you can return the indices of the edges in any order.
// 
//Example 1:
//Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
//Output: [[0,1],[2,3,4,5]]
//Explanation: The figure above describes the graph.
//The following figure shows all the possible MSTs:
//Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
//The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.
//Example 2:
//Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
//Output: [[],[0,1,2,3]]
//Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
// 
//Constraints:
//	2 <= n <= 100
//	1 <= edges.length <= min(200, n * (n - 1) / 2)
//	edges[i].length == 3
//	0 <= ai < bi < n
//	1 <= weighti <= 1000
//	All pairs (ai, bi) are distinct.
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[][]}
 */
var findCriticalAndPseudoCriticalEdges = function(n, edges) {
    edges = edges.map((e, i) => [...e, i]); // Add index to each edge
    edges.sort((a, b) => a[2] - b[2]); // Sort edges by weight

    const find = (parent, x) => {
        if (parent[x] !== x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    };

    const union = (parent, rank, x, y) => {
        const rootX = find(parent, x);
        const rootY = find(parent, y);
        if (rootX !== rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    };

    const kruskal = (edgesToInclude) => {
        const parent = Array.from({ length: n }, (_, i) => i);
        const rank = Array(n).fill(0);
        let totalWeight = 0;
        let count = 0;

        for (const [u, v, w] of edgesToInclude) {
            union(parent, rank, u, v);
            totalWeight += w;
            count++;
        }

        return { totalWeight, count };
    };

    const mstInfo = kruskal(edges); // Get MST info with all edges
    const mstWeight = mstInfo.totalWeight;

    const criticalEdges = [];
    const pseudoCriticalEdges = [];

    for (let i = 0; i < edges.length; i++) {
        const [u, v, w, index] = edges[i];

        // Check if the edge is critical
        const withoutEdgeInfo = kruskal(edges.filter((_, j) => j !== i));
        if (withoutEdgeInfo.count < n - 1 || withoutEdgeInfo.totalWeight > mstWeight) {
            criticalEdges.push(index);
        } else {
            // Check if the edge is pseudo-critical
            const withEdgeInfo = kruskal([edges[i], ...edges.filter((_, j) => j !== i)]);
            if (withEdgeInfo.totalWeight === mstWeight) {
                pseudoCriticalEdges.push(index);
            }  
        }
    }
    return [criticalEdges, pseudoCriticalEdges];  
};