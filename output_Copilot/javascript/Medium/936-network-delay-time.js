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
    const graph = new Map();
    for (const [u, v, w] of times) {
        if (!graph.has(u)) graph.set(u, []);
        graph.get(u).push([v, w]);
    }
    
    const dist = new Array(n + 1).fill(Infinity);
    dist[k] = 0;
    
    const pq = [[0, k]]; // [time, node]
    
    while (pq.length) {
        const [time, node] = pq.shift();
        
        if (time > dist[node]) continue;
        
        for (const [neighbor, weight] of (graph.get(node) || [])) {
            const newTime = time + weight;
            if (newTime < dist[neighbor]) {
                dist[neighbor] = newTime;
                pq.push([newTime, neighbor]);
            }
        }
    }
    
    const maxTime = Math.max(...dist.slice(1));
    return maxTime === Infinity ? -1 : maxTime;    
};