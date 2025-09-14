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
    const graph = new Map();
    for (const [a, b] of edges) {
        if (!graph.has(a)) graph.set(a, []);
        graph.get(a).push(b);
    }

    const memo = new Map();
    function dfs(node, seen, colorCounts) {
        if (seen.has(node)) return -1;
        seen.add(node);
        if (memo.has(node)) return memo.get(node);
        const result = 0;
        for (const neighbor of graph.get(node) || []) {
            const count = dfs(neighbor, seen, colorCounts);
            if (count === -1) return -1;
            result = Math.max(result, count);
        }
        result = Math.max(result, colorCounts[colors[node]]);
        memo.set(node, result);
        seen.delete(node);
        return result;
    }

    let result = 0;
    for (let i = 0; i < colors.length; i++) {
        const colorCounts = {};
        for (const color of colors) colorCounts[color] = (colorCounts[color] || 0) + 1;
        const count = dfs(i, new Set(), colorCounts);
        if (count === -1) return -1;
        result = Math.max(result, count);
    }   
    return result;
};
