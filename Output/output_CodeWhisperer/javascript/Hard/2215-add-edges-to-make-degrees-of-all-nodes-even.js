/**https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/ */
//There is an undirected graph consisting of n nodes numbered from 1 to n. You are given the integer n and a 2D array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi. The graph can be disconnected.
//You can add at most two additional edges (possibly none) to this graph so that there are no repeated edges and no self-loops.
//Return true if it is possible to make the degree of each node in the graph even, otherwise return false.
//The degree of a node is the number of edges connected to it.
// 
//Example 1:
//Input: n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
//Output: true
//Explanation: The above diagram shows a valid way of adding an edge.
//Every node in the resulting graph is connected to an even number of edges.
//Example 2:
//Input: n = 4, edges = [[1,2],[3,4]]
//Output: true
//Explanation: The above diagram shows a valid way of adding two edges.
//Example 3:
//Input: n = 4, edges = [[1,2],[1,3],[1,4]]
//Output: false
//Explanation: It is not possible to obtain a valid graph with adding at most 2 edges.
// 
//Constraints:
//	3 <= n <= 105
//	2 <= edges.length <= 105
//	edges[i].length == 2
//	1 <= ai, bi <= n
//	ai != bi
//	There are no repeated edges.
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {boolean}
 */
var isPossible = function(n, edges) {
    let graph = new Array(n + 1).fill(0).map(() => new Array());
    let degree = new Array(n + 1).fill(0);
    for (let [a, b] of edges) {
        graph[a].push(b);
        graph[b].push(a);
        degree[a]++;
        degree[b]++;
    }
    let odd = new Array();
    for (let i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1) odd.push(i);
    }
    if (odd.length > 4 || odd.length % 2 == 1) return false;
    if (odd.length == 0) return true;
    if (odd.length == 2) {
        let [a, b] = odd;
        if (!graph[a].includes(b)) return true;
        for (let i = 1; i <= n; i++) {
            if (!graph[a].includes(i) && !graph[b].includes(i)) return true;
        }
        return false;
    }
    let [a, b, c, d] = odd;
    if (!graph[a].includes(b) && !graph[c].includes(d)) return true;
    if (!graph[a].includes(c) && !graph[b].includes(d)) return true;
    if (!graph[a].includes(d) && !graph[b].includes(c)) return true;
    return false;
};