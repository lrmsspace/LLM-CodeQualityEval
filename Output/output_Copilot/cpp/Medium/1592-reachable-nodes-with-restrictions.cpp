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
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], 1});
            graph[e[1]].push_back({e[0], 1});
        }
        for (int i = 0; i < restricted.size(); ++i) {
            int u = restricted[i];
            for (int j = 0; j < graph[u].size(); ++j) {
                graph[u][j].second = 0;
            }
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) {
                continue;
            }
            for (auto& [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] <= 2) {
                ++ans;
            }
        }
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (dist[u] + dist[v] >= 2) {
                ans += min(dist[u] + dist[v] - 1, e[2]);
            }
        }
        return ans;        
    }
};