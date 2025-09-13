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

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {}

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        UnionFind uf(n + m);

        for (const auto& edge : edges1) {
            uf.merge(edge[0], edge[1]);
        }

        for (const auto& edge : edges2) {
            uf.merge(edge[0] + n, edge[1] + n);
        }

        int maxDistance = 0;
        unordered_map<int, vector<int>> graph;

        for (const auto& edge : edges1) {
            graph[uf.find(edge[0])].push_back(uf.find(edge[1]));
            graph[uf.find(edge[1])].push_back(uf.find(edge[0]));
        }

        for (const auto& edge : edges2) {
            graph[uf.find(edge[0] + n)].push_back(uf.find(edge[1] + n));
            graph[uf.find(edge[1] + n)].push_back(uf.find(edge[0] + n));
        }

        for (const auto& pair : graph) {
            int root = pair.first;
            for (int neighbor : pair.second) {
                if (uf.find(root) != uf.find(neighbor)) {
                    int distance = abs(root - neighbor);
                    maxDistance = max(maxDistance, distance);
                }
            }
        }

        return maxDistance;
    }
};
