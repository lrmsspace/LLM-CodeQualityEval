/**https://leetcode.com/problems/largest-color-value-in-a-directed-graph/ */
//There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
//You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
//A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
//Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
// 
//Example 1:
//Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
//Output: 3
//Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
//Example 2:
//Input: colors = "a", edges = [[0,0]]
//Output: -1
//Explanation: There is a cycle from 0 to 0.
// 
//Constraints:
//	n == colors.length
//	m == edges.length
//	1 <= n <= 105
//	0 <= m <= 105
//	colors consists of lowercase English letters.
//	0 <= aj, bj < n
/**

 * @param {string} colors

 * @param {number[][]} edges

 * @return {number}

 */

var largestPathValue = function(colors, edges) {
    const n = colors.length;
    const adj = Array.from({ length: n }, () => []);
    const inDeg = Array.from({ length: n }, () => 0);
    const maxColors = Array.from({ length: n }, () => 0);
    const maxColorsCount = Array.from({ length: n }, () => 0);
    for (const [a, b] of edges) {
        adj[a].push(b);
        inDeg[b]++;
    }
    const queue = [];

    for (let i = 0; i < n; i++) {
        if (inDeg[i] === 0) {
            queue.push(i);
            maxColors[i] = 1;
            maxColorsCount[i] = 1;
        }
    }
    while (queue.length) {
        const u = queue.shift();
        for (const v of adj[u]) {
            inDeg[v]--;
            maxColors[v] = Math.max(maxColors[v], maxColors[u] + 1);
            maxColorsCount[v] = Math.max(maxColorsCount[v], maxColors[u] + 1 === maxColors[v]? maxColorsCount[u] + 1 : 1);
            if (inDeg[v] === 0) {
                queue.push(v);
            }
        }
    }
    return Math.max(...maxColorsCount) * (colors.charCodeAt(0) - 'a'.charCodeAt(0) + 1);

};