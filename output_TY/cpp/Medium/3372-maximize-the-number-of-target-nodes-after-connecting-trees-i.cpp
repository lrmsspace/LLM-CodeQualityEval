/*
 There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.
 You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.
 Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.
 Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.
 Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
 Example 1:
 Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2
 Output: [9,7,9,8,8]
 Explanation:
 For i = 0, connect node 0 from the first tree to node 0 from the second tree.
 For i = 1, connect node 1 from the first tree to node 0 from the second tree.
 For i = 2, connect node 2 from the first tree to node 4 from the second tree.
 For i = 3, connect node 3 from the first tree to node 4 from the second tree.
 For i = 4, connect node 4 from the first tree to node 4 from the second tree.
 Example 2:
 Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1
 Output: [6,3,3,3,3]
 Explanation:
 For every i, connect node i of the first tree with any node of the second tree.
 Constraints:
 2 <= n, m <= 1000
 edges1.length == n - 1
 edges2.length == m - 1
 edges1[i].length == edges2[i].length == 2
 edges1[i] = [ai, bi]
 0 <= ai, bi < n
 edges2[i] = [ui, vi]
 0 <= ui, vi < m
 The input is generated such that edges1 and edges2 represent valid trees.
 0 <= k <= 1000
*/
class Solution {
public:
    // 构建邻接表
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return graph;
    }

    // 计算每个节点在 depth 范围内能到达的节点数
    vector<int> bfs(vector<vector<int>>& graph, int n, int depth) {
        vector<int> count(n, 0);
        for (int i = 0; i < n; ++i) {
            queue<pair<int, int>> q;
            vector<bool> visited(n, false);
            q.push({i, 0});
            visited[i] = true;
            int res = 0;
            while (!q.empty()) {
                auto [node, d] = q.front();
                q.pop();
                if (d > depth) break;
                res++;
                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, d + 1});
                    }
                }
            }
            count[i] = res;
        }
        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // 构建两棵树的邻接表
        vector<vector<int>> tree1 = buildGraph(n, edges1);
        vector<vector<int>> tree2 = buildGraph(m, edges2);

        // 计算每棵树中每个节点在 k 和 k-1 范围内的可达节点数
        vector<int> count1 = bfs(tree1, n, k);
        vector<int> count2 = bfs(tree2, m, k);
        vector<int> count2_with_extra = bfs(tree2, m, k - 1);

        // 找到第二棵树中最大的 count2_with_extra 值
        int max_extra = *max_element(count2_with_extra.begin(), count2_with_extra.end());

        // 结果数组
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = count1[i] + max_extra;
        }

        return result;
    }
};