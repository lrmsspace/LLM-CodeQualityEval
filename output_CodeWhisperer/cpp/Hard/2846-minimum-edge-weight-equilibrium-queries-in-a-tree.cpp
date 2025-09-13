/*
 There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates that there is an edge between nodes ui and vi with weight wi in the tree.
 You are also given a 2D integer array queries of length m, where queries[i] = [ai, bi]. For each query, find the minimum number of operations required to make the weight of every edge on the path from ai to bi equal. In one operation, you can choose any edge of the tree and change its weight to any value.
 Note that:
 Queries are independent of each other, meaning that the tree returns to its initial state on each new query.
 The path from ai to bi is a sequence of distinct nodes starting with node ai and ending with node bi such that every two adjacent nodes in the sequence share an edge in the tree.
 Return an array answer of length m where answer[i] is the answer to the ith query.
 Example 1:
 Input: n = 7, edges = [[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]], queries = [[0,3],[3,6],[2,6],[0,6]]
 Output: [0,0,1,3]
 Explanation: In the first query, all the edges in the path from 0 to 3 have a weight of 1. Hence, the answer is 0.
 In the second query, all the edges in the path from 3 to 6 have a weight of 2. Hence, the answer is 0.
 In the third query, we change the weight of edge [2,3] to 2. After this operation, all the edges in the path from 2 to 6 have a weight of 2. Hence, the answer is 1.
 In the fourth query, we change the weights of edges [0,1], [1,2] and [2,3] to 2. After these operations, all the edges in the path from 0 to 6 have a weight of 2. Hence, the answer is 3.
 For each queries[i], it can be shown that answer[i] is the minimum number of operations needed to equalize all the edge weights in the path from ai to bi.
 Example 2:
 Input: n = 8, edges = [[1,2,6],[1,3,4],[2,4,6],[2,5,3],[3,6,6],[3,0,8],[7,0,2]], queries = [[4,6],[0,4],[6,5],[7,4]]
 Output: [1,2,2,3]
 Explanation: In the first query, we change the weight of edge [1,3] to 6. After this operation, all the edges in the path from 4 to 6 have a weight of 6. Hence, the answer is 1.
 In the second query, we change the weight of edges [0,3] and [3,1] to 6. After these operations, all the edges in the path from 0 to 4 have a weight of 6. Hence, the answer is 2.
 In the third query, we change the weight of edges [1,3] and [5,2] to 6. After these operations, all the edges in the path from 6 to 5 have a weight of 6. Hence, the answer is 2.
 In the fourth query, we change the weights of edges [0,7], [0,3] and [1,3] to 6. After these operations, all the edges in the path from 7 to 4 have a weight of 6. Hence, the answer is 3.
 For each queries[i], it can be shown that answer[i] is the minimum number of operations needed to equalize all the edge weights in the path from ai to bi.
 Constraints:
 1 <= n <= 104
 edges.length == n - 1
 edges[i].length == 3
 0 <= ui, vi < n
 1 <= wi <= 26
 The input is generated such that edges represents a valid tree.
 1 <= queries.length == m <= 2 * 104
 queries[i].length == 2
 0 <= ai, bi < n
*/
class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> parent;
    vector<vector<vector<int>>> count;
    vector<int> depth;
    int maxBit;
    
    void dfs(int u, int p, vector<int>& cnt) {
        parent[u][0] = p;
        count[u][0] = cnt;
        
        for(int i = 1; i <= maxBit; i++) {
            parent[u][i] = parent[parent[u][i-1]][i-1];
            count[u][i] = count[u][i-1];
            for(int j = 0; j < 27; j++) {
                count[u][i][j] += count[parent[u][i-1]][i-1][j];
            }
        }
        
        for(auto [v, w] : adj[u]) {
            if(v != p) {
                depth[v] = depth[u] + 1;
                vector<int> newCnt(27);
                newCnt[w] = 1;
                dfs(v, u, newCnt);
            }
        }
    }
    
    pair<int, vector<int>> getLCA(int u, int v) {
        vector<int> cnt(27);
        if(depth[u] < depth[v]) swap(u, v);
        
        int diff = depth[u] - depth[v];
        for(int i = 0; i <= maxBit; i++) {
            if(diff & (1 << i)) {
                for(int j = 0; j < 27; j++) {
                    cnt[j] += count[u][i][j];
                }
                u = parent[u][i];
            }
        }
        
        if(u == v) return {u, cnt};
        
        for(int i = maxBit; i >= 0; i--) {
            if(parent[u][i] != parent[v][i]) {
                for(int j = 0; j < 27; j++) {
                    cnt[j] += count[u][i][j] + count[v][i][j];
                }
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        
        for(int j = 0; j < 27; j++) {
            cnt[j] += count[u][0][j] + count[v][0][j];
        }
        
        return {parent[u][0], cnt};
    }
    
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        maxBit = 32 - __builtin_clz(n);
        adj.resize(n);
        parent = vector<vector<int>>(n, vector<int>(maxBit + 1));
        count = vector<vector<vector<int>>>(n, vector<vector<int>>(maxBit + 1, vector<int>(27)));
        depth.resize(n);
        
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> initCnt(27);
        dfs(0, 0, initCnt);
        
        vector<int> answer;
        for(auto& q : queries) {
            auto [lca, cnt] = getLCA(q[0], q[1]);
            int pathLen = depth[q[0]] + depth[q[1]] - 2 * depth[lca];
            int maxFreq = 0;
            for(int i = 1; i <= 26; i++) {
                maxFreq = max(maxFreq, cnt[i]);
            }
            answer.push_back(pathLen - maxFreq);
        }
        
        return answer;
    }
};                    
   