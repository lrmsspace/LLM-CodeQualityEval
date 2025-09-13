/**https://leetcode.com/problems/reachable-nodes-with-restrictions/ */
//There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.
//Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.
//Note that node 0 will not be a restricted node.
// 
//Example 1:
//Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
//Output: 4
//Explanation: The diagram above shows the tree.
//We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.
//Example 2:
//Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
//Output: 3
//Explanation: The diagram above shows the tree.
//We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.
// 
//Constraints:
//	2 <= n <= 105
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	edges represents a valid tree.
//	1 <= restricted.length < n
//	1 <= restricted[i] < n
//	All the values of restricted are unique.
/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} restricted
 * @return {number}
 */
var reachableNodes = function(n, edges, restricted) {
    const graph = Array.from({ length: n }, () => new Set());
    const indegree = Array(n).fill(0);
    const outdegree = Array(n).fill(0);
    
    for (const [a, b] of edges) {
        graph[a].add(b);
        graph[b].add(a);
        indegree[b]++;
        outdegree[a]++;
    }
    
    let reachable = 0;
    const queue = new Set(restricted);
    
    while (queue.size > 0) {
        const node = queue.poll();
        reachable++;
        
        for (const neighbor of graph[node]) {
            if (!queue.has(neighbor)) {
                if (indegree[neighbor] > 0) {
                    queue.add(neighbor);
                    indegree[neighbor]--;
                } else {
                    outdegree[neighbor]--;
                    reachable++;
                }
            }
        }
    }
    
    return reachable + outdegree.reduce((sum, count) => sum + count, 0);
    
};