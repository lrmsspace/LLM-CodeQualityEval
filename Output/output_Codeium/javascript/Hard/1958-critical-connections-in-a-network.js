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
    const graph = Array(n).fill(null).map(() => []);
    for (const [a, b] of connections) {
        graph[a].push(b);
        graph[b].push(a);
    }
    const low = Array(n).fill(0);
    const disc = Array(n).fill(0);
    const visited = Array(n).fill(false);
    const result = [];
    let time = 0;
    const dfs = (node, parent) => {
        low[node] = disc[node] = ++time;
        visited[node] = true;
        for (const next of graph[node]) {
            if (next === parent) {
                continue;
            }
            if (!visited[next]) {
                dfs(next, node);
                low[node] = Math.min(low[node], low[next]);
                if (low[next] > disc[node]) {
                    result.push([node, next]);
                }
            } else {
                low[node] = Math.min(low[node], disc[next]);
            }
        }
    };
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
      
        }
    }
    return result;
};