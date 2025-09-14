/*
 There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
 You must connect one node from the first tree with another node from the second tree with an edge.
 Return the minimum possible diameter of the resulting tree.
 The diameter of a tree is the length of the longest path between any two nodes in the tree.
 Example 1:
 Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
 Output: 3
 Explanation:
 We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.
 Example 2:
 Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
 Output: 5
 Explanation:
 We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.
 Constraints:
 1 <= n, m <= 105
 edges1.length == n - 1
 edges2.length == m - 1
 edges1[i].length == edges2[i].length == 2
 edges1[i] = [ai, bi]
 0 <= ai, bi < n
 edges2[i] = [ui, vi]
 0 <= ui, vi < m
 The input is generated such that edges1 and edges2 represent valid trees.
*/

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // Function to find the maximum diameter of a tree given its edges
        auto findDiameter = [](const vector<vector<int>>& edges, int n) {
            vector<int> dist(n, -1);
            vector<vector<int>> adj(n);
            for (const auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }

            auto bfs = [&](int start) {
                queue<int> q;
                q.push(start);
                dist[start] = 0;
                int farthest = start;
                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    for (int neighbor : adj[node]) {
                        if (dist[neighbor] == -1) {
                            dist[neighbor] = dist[node] + 1;
                            q.push(neighbor);
                            if (dist[neighbor] > dist[farthest]) {
                                farthest = neighbor;
                            }
                        }
                    }
                }
                return farthest;
            };

            // Run BFS from any node, then run BFS again from the farthest node found
            int start = 0;
            int farthest = bfs(start);
            fill(dist.begin(), dist.end(), -1);
            int opposite = bfs(farthest);
            return dist[opposite];
        };

        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        int diameter1 = findDiameter(edges1, n1);
        int diameter2 = findDiameter(edges2, n2);

        // The minimum diameter after merging is the maximum of the two diameters plus one
        return max(diameter1, diameter2) + 1;

    }
};