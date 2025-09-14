/*
 You are given two integers, n and threshold, as well as a directed weighted graph of n nodes numbered from 0 to n - 1. The graph is represented by a 2D integer array edges, where edges[i] = [Ai, Bi, Wi] indicates that there is an edge going from node Ai to node Bi with weight Wi.
 You have to remove some edges from this graph (possibly none), so that it satisfies the following conditions:
 Node 0 must be reachable from all other nodes.
 The maximum edge weight in the resulting graph is minimized.
 Each node has at most threshold outgoing edges.
 Return the minimum possible value of the maximum edge weight after removing the necessary edges. If it is impossible for all conditions to be satisfied, return -1.
 Example 1:
 Input: n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2
 Output: 1
 Explanation:
 Remove the edge 2 -> 0. The maximum weight among the remaining edges is 1.
 Example 2:
 Input: n = 5, edges = [[0,1,1],[0,2,2],[0,3,1],[0,4,1],[1,2,1],[1,4,1]], threshold = 1
 Output: -1
 Explanation: 
 It is impossible to reach node 0 from node 2.
 Example 3:
 Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[3,4,2],[4,0,1]], threshold = 1
 Output: 2
 Explanation: 
 Remove the edges 1 -> 3 and 1 -> 4. The maximum weight among the remaining edges is 2.
 Example 4:
 Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[4,0,1]], threshold = 1
 Output: -1
 Constraints:
 2 <= n <= 105
 1 <= threshold <= n - 1
 1 <= edges.length <= min(105, n * (n - 1) / 2).
 edges[i].length == 3
 0 <= Ai, Bi < n
 Ai != Bi
 1 <= Wi <= 106
 There may be multiple edges between a pair of nodes, but they must have unique weights.
*/

/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} threshold
 * @return {number}
 */
var minMaxWeight = function(n, edges, threshold) {
    // Create an adjacency list for the graph
    const graph = Array.from({ length: n }, () => []);
    for (const [u, v, w] of edges) {
        graph[u].push([v, w]);
    }

    // Function to check if we can reach node 0 with a maximum edge weight of maxWeight
    const canReachWithMaxWeight = (maxWeight) => {
        const visited = new Array(n).fill(false);
        const stack = [0];
        visited[0] = true;

        while (stack.length > 0) {
            const node = stack.pop();
            for (const [neighbor, weight] of graph[node]) {
                if (!visited[neighbor] && weight <= maxWeight) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }

        return visited.every((v, i) => v || i === 0); // All nodes except 0 must be reachable
    };

    // Binary search for the minimum maximum edge weight
    let left = 1, right = 1e6; // Edge weights are between 1 and 10^6
    let result = -1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (canReachWithMaxWeight(mid)) {
            result = mid; // Found a valid maximum weight
            right = mid - 1; // Try to find a smaller maximum weight
        } else {
            left = mid + 1; // Increase the maximum weight
        }
    }

    return result;
        
};