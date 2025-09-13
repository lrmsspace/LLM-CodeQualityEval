/**https://leetcode.com/problems/network-delay-time/ */
//You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
//We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
// 
//Example 1:
//Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
//Output: 2
//Example 2:
//Input: times = [[1,2,1]], n = 2, k = 1
//Output: 1
//Example 3:
//Input: times = [[1,2,1]], n = 2, k = 2
//Output: -1
// 
//Constraints:
//	1 <= k <= n <= 100
//	1 <= times.length <= 6000
//	times[i].length == 3
//	1 <= ui, vi <= n
//	ui != vi
//	0 <= wi <= 100
//	All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
/**
 * @param {number[][]} times
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var networkDelayTime = function(times, n, k) {
    const graph = Array.from({ length: n + 1 }, () => Array(n + 1).fill(Infinity));
    const dist = Array(n + 1).fill(Infinity);
    
    times.forEach(([u, v, w]) => graph[u][v] = w);
    dist[k] = 0;
    
    for (let i = 1; i <= n - 1; i++) {
        let minDist = Infinity;
        let u;
        
        for (let j = 1; j <= n; j++) {
            if (dist[j] < minDist && dist[j]!== Infinity) {
                minDist = dist[j];
                u = j;
            }
        }
        
        for (let v = 1; v <= n; v++) {
            if (graph[u][v]!== Infinity && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    let maxDist = Math.max(...dist.slice(1));
    return maxDist === Infinity? -1 : maxDist;
    
};