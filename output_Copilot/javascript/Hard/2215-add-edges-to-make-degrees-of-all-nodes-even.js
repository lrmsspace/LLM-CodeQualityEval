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
    let degree = new Array(n + 1).fill(0);
    for (let [a, b] of edges) {
        degree[a]++;
        degree[b]++;
    }
    let odd = [];
    for (let i = 1; i <= n; i++) {
        if (degree[i] % 2 === 1) {
            odd.push(i);
        }
    }
    if (odd.length === 0) return true;
    if (odd.length > 4) return false;
    if (odd.length === 2) {
        return !edges.some(([a, b]) => (a === odd[0] && b === odd[1]) || (a === odd[1] && b === odd[0]));
    }
    if (odd.length === 4) {
        return edges.some(([a, b]) => (a === odd[0] && b === odd[1]) || (a === odd[2] && b === odd[3]));
    }
    return false;    
};