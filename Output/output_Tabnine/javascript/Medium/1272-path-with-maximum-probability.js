/**https://leetcode.com/problems/path-with-maximum-probability/ */
//You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
//Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
//If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
// 
//Example 1:
//Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
//Output: 0.25000
//Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
//Example 2:
//Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
//Output: 0.30000
//Example 3:
//Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
//Output: 0.00000
//Explanation: There is no path between 0 and 2.
// 
//Constraints:
//	2 <= n <= 10^4
//	0 <= start, end < n
//	start != end
//	0 <= a, b < n
//	a != b
//	0 <= succProb.length == edges.length <= 2*10^4
//	0 <= succProb[i] <= 1
//	There is at most one edge between every two nodes.
/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} succProb
 * @param {number} start_node
 * @param {number} end_node
 * @return {number}
 */
var maxProbability = function(n, edges, succProb, start_node, end_node) {
    // Create adjacency list
    let graph = Array.from({ length: n }, () => new Map());
    for (let [a, b] of edges) {
        graph[a].set(b, succProb.shift());
        graph[b].set(a, succProb.shift());
    }
    
    // Initialize distances from start_node to all other nodes
    let dist = Array.from({ length: n }, () => Infinity);
    dist[start_node] = 1;
    
    // Dijkstra's algorithm
    while (true) {
        let current = -1;
        let minDist = Infinity;
        for (let i = 0; i < n; i++) {
            if (dist[i] < minDist &&!visited[i]) {
                current = i;
                minDist = dist[i];
            }
        }
        if (current === -1) break;
        visited[current] = true;
        
        for (let [neighbor, weight] of graph[current]) {
            let newDist = minDist * weight;
            if (newDist > dist[neighbor]) {
                dist[neighbor] = newDist;
            }
        }
        
        // If we reach the end_node, return the probability
        if (current === end_node) {
            return dist[current];
        }
    }
    
    // If no path exists, return 0
    return 0;

    
};