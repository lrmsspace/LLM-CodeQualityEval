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
    // Step 1: Create an adjacency list representation of the graph
    const graph = Array.from({ length: n }, () => new Set());
    for (const [a, b, weight] of edges) {
        graph[a].add(b);
        graph[b].add(a);
    }
    
    // Step 2: Calculate the minimum spanning tree (MST) weight
    let mstWeight = 0;
    const visited = new Set();
    const parent = new Array(n).fill(-1);
    const dfs = (node) => {
        visited.add(node);
        for (const neighbor of graph[node]) {
            if (!visited.has(neighbor)) {
                parent[neighbor] = node;
                dfs(neighbor);
            }
        }
    };
    dfs(0);
    for (let i = 1; i < n; i++) {
        mstWeight += edges[parent[i]][2];
    }
    
    // Step 3: Find critical and pseudo-critical edges
    const criticalEdges = [];
    const pseudoCriticalEdges = [];
    for (let i = 0; i < edges.length; i++) {
        const [a, b, weight] = edges[i];
        const originalWeight = weight;
        
        // Try removing edge i and see if the MST weight increases
        const tempParent = [...parent];
        const tempGraph = [...graph];
        tempGraph[a].delete(b);
        tempGraph[b].delete(a);
        parent.fill(-1);
        dfs(0);
        let newMstWeight = 0;
        for (let j = 1; j < n; j++) {
            newMstWeight += tempGraph[tempParent[j]][j];
        }
        
        if (newMstWeight > mstWeight) {
            // Edge i is critical
            criticalEdges.push(i);
        } else if (newMstWeight < mstWeight) {
            // Edge i is pseudo-critical
            pseudoCriticalEdges.push(i);
        }
        
        // Restore the original graph
        tempGraph[a].add(b);
        tempGraph[b].add(a);
        parent.forEach((p, j) => {
            if (p === a || p === b) {
                parent[j] = tempParent[j];
            }
        });
    }
    
    return [criticalEdges, pseudoCriticalEdges];
    
};