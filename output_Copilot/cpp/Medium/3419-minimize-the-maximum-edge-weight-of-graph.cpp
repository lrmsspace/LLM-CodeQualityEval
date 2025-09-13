/*
 You are given two integers, n and threshold, as well as a directed weighted graph of n nodes numbered from 0 to n - 1. The graph is represented by a 2D integer array edges, where edges[i] = [Ai, Bi, Wi] indicates that there is an edge going from node Ai to node Bi with weight Wi.
 You have to remove some edges from this graph (possibly none), so that it satisfies the following conditions:
 Node 0 must be reachable from all other nodes.
 The maximum edge weight in the resulting graph is minimized.
 Each node has at most threshold outgoing edges.
 Return the minimum possible value of the maximum edge weight after removing the necessary edges. If it is impossible for all conditions to be satisfied, return -1.
 Example 1:
 Input: n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2
 Output: 1
 Explanation:
 Remove the edge 2 -> 0. The maximum weight among the remaining edges is 1.
 Example 2:
 Input: n = 5, edges = [[0,1,1],[0,2,2],[0,3,1],[0,4,1],[1,2,1],[1,4,1]], threshold = 1
 Output: -1
 Explanation: 
 It is impossible to reach node 0 from node 2.
 Example 3:
 Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[3,4,2],[4,0,1]], threshold = 1
 Output: 2
 Explanation: 
 Remove the edges 1 -> 3 and 1 -> 4. The maximum weight among the remaining edges is 2.
 Example 4:
 Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[4,0,1]], threshold = 1
 Output: -1
 Constraints:
 2 <= n <= 105
 1 <= threshold <= n - 1
 1 <= edges.length <= min(105, n * (n - 1) / 2).
 edges[i].length == 3
 0 <= Ai, Bi < n
 Ai != Bi
 1 <= Wi <= 106
 There may be multiple edges between a pair of nodes, but they must have unique weights.
*/

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // Create adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }

        // Binary search for the minimum possible maximum edge weight
        int left = 1, right = 1e6, result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReachAllNodes(graph, n, mid, threshold)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

private:
    bool canReachAllNodes(const vector<vector<pair<int, int>>>& graph, int n, int maxWeight, int threshold) {
        vector<int> outDegree(n, 0);
        vector<vector<int>> adj(n);
        for (int u = 0; u < n; u++) {
            for (const auto& [v, w] : graph[u]) {
                if (w <= maxWeight) {
                    adj[u].push_back(v);
                    outDegree[u]++;
                }
            }
        }

        // Check if all nodes can reach node 0
        vector<bool> visited(n, false);
        dfs(0, adj, visited);
        for (int i = 1; i < n; i++) {
            if (!visited[i]) return false;
        }

        // Check if out-degree constraint is satisfied
        for (int i = 0; i < n; i++) {
            if (outDegree[i] > threshold) return false;
        }

        return true;
    }

    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
};