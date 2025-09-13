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
        for (auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        vector<int> depth(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> res;
        function<void(int, int)> dfs = [&](int x, int parent) {
            depth[x] = low[x] = ++timer;
            for (int y : graph[x]) {
                if (y == parent) continue;
                if (depth[y] == -1) {
                    dfs(y, x);
                    low[x] = min(low[x], low[y]);
                    if (low[y] > depth[x]) {
                        res.push_back({x, y});
                    }
                } else {
                    low[x] = min(low[x], depth[y]);
                }
            }
        };
        int timer = 0;
        dfs(0, -1);
        return res;
    }
};