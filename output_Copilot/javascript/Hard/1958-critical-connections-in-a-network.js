/**https://leetcode.com/problems/critical-connections-in-a-network/ */
//There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
//A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
//Return all critical connections in the network in any order.
// 
//Example 1:
//Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
//Output: [[1,3]]
//Explanation: [[3,1]] is also accepted.
//Example 2:
//Input: n = 2, connections = [[0,1]]
//Output: [[0,1]]
// 
//Constraints:
//	2 <= n <= 105
//	n - 1 <= connections.length <= 105
//	0 <= ai, bi <= n - 1
//	ai != bi
//	There are no repeated connections.
/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number[][]}
 */
var criticalConnections = function(n, connections) {
    const graph = Array.from({ length: n }, () => []);
    for (const [a, b] of connections) {
        graph[a].push(b);
        graph[b].push(a);
    }

    const low = Array(n).fill(0);
    const disc = Array(n).fill(-1);
    const result = [];
    let time = 0;

    function dfs(node, parent) {
        disc[node] = low[node] = time++;
        for (const neighbor of graph[node]) {
            if (neighbor === parent) continue;
            if (disc[neighbor] === -1) {
                dfs(neighbor, node);
                low[node] = Math.min(low[node], low[neighbor]);
                if (low[neighbor] > disc[node]) {
                    result.push([node, neighbor]);
                }
            } else {
                low[node] = Math.min(low[node], disc[neighbor]);
            }
        }
    }

    for (let i = 0; i < n; i++) {
        if (disc[i] === -1) {
            dfs(i, -1);
        }
    }

    return result;    
};