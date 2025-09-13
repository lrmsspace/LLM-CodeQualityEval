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
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> graph1(n);
        vector<vector<int>> graph2(m);
        for(auto& edge: edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        for(auto& edge: edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            vector<int> visited1(n, 0);
            vector<int> visited2(m, 0);
            queue<int> q;
            q.push(i);
            visited1[i] = 1;
            int count = 0;
            while(!q.empty()) {
                int size = q.size();
                for(int j = 0; j < size; j++) {
                    int node = q.front();
                    q.pop();
                    for(auto& next: graph1[node]) {
                        if(!visited1[next]) {
                            visited1[next] = 1;
                            q.push(next);
                        }
                    }
                    for(auto& next: graph2[node]) {
                        if(!visited2[next]) {
                            visited2[next] = 1;
                            q.push(next);
                        }
                    }
                }
                count++;
                if(count > k) break;
            }
            res[i] = visited1[0] + visited2[0] - 1;
            for(int j = 1; j < n; j++) {
                if(visited1[j]) res[i]++;
            }
            for(int j = 1; j < m; j++) {
                if(visited2[j]) res[i]++;
            }
        }
        return res;       
    }
};