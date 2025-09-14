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
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (auto& connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        vector<int> low(n, -1);
        vector<int> dfn(n, -1);
        vector<vector<int>> res;
        int time = 0;
        function<void(int, int)> dfs = [&](int u, int parent) {
            low[u] = dfn[u] = time++;
            for (auto& v : graph[u]) {
                if (v == parent) continue;
                if (dfn[v] == -1) {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > dfn[u]) {
                        res.push_back({u, v});
                    }
                } else {
                    low[u] = min(low[u], dfn[v]);
                }
            }
        };
        dfs(0, -1);
        return res;      
    }
};