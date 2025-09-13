/*
 There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
 Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
 The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
 Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.
 Since the answer may be large, return it modulo 109 + 7.
 Note: Ignore all edges not in the path from node 1 to x.
 Example 1:
 Input: edges = [[1,2]]
 Output: 1
 Explanation:
 The path from Node 1 to Node 2 consists of one edge (1 → 2).
 Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
 Example 2:
 Input: edges = [[1,2],[1,3],[3,4],[3,5]]
 Output: 2
 Explanation:
 The maximum depth is 2, with nodes 4 and 5 at the same depth. Either node can be selected for processing.
 For example, the path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4).
 Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
 Constraints:
 2 <= n <= 105
 edges.length == n - 1
 edges[i] == [ui, vi]
 1 <= ui, vi <= n
 edges represents a valid tree.
*/

int assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize) {
    // Create adjacency list representation
    int n = edgesSize + 1;
    int* adj[100001];
    int adjSize[100001] = {0};
    
    // Allocate memory for adjacency lists
    for(int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }
    
    // Build adjacency list
    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }
    
    // Find leaf node at maximum depth using DFS
    int maxDepth = 0;
    int leafNode = 1;
    int visited[100001] = {0};
    
    void dfs(int node, int depth) {
        visited[node] = 1;
        if(depth > maxDepth) {
            maxDepth = depth;
            leafNode = node;
        }
        for(int i = 0; i < adjSize[node]; i++) {
            int next = adj[node][i];
            if(!visited[next]) {
                dfs(next, depth + 1);
            }
        }
    }
    
    dfs(1, 0);
    
    // Find path from root to leaf node
    int path[100001];
    int pathLen = 0;
    int found = 0;
    
    void findPath(int node, int parent) {
        path[pathLen++] = node;
        if(node == leafNode) {
            found = 1;
            return;
        }
        for(int i = 0; i < adjSize[node]; i++) {
            int next = adj[node][i];
            if(next != parent && !found) {
                findPath(next, node);
            }
        }
        if(!found) pathLen--;
    }
    
    memset(visited, 0, sizeof(visited));
    findPath(1, 0);
    
    // Count ways to assign weights to get odd sum
    const int MOD = 1000000007;
    int ways = 0;
    int len = pathLen - 1;  // number of edges in path
    
    // If path length is odd, need odd number of 1s
    // If path length is even, need even number of 1s
    if(len % 2 == 0) {
        // Need odd number of 1s for odd sum
        for(int i = 1; i <= len; i += 2) {
            long long comb = 1;
            for(int j = 0; j < i; j++) {
                comb = (comb * (len - j)) / (j + 1);
            }
            ways = (ways + comb) % MOD;
        }
    } else {
        // Need even number of 1s for odd sum  
        for(int i = 0; i <= len; i += 2) {
            long long comb = 1;
            for(int j = 0; j < i; j++) {
                comb = (comb * (len - j)) / (j + 1);
            }
            ways = (ways + comb) % MOD;
        }
    }
    
    // Free allocated memory
    for(int i = 1; i <= n; i++) {
        free(adj[i]);
    }
    
    return ways;
}            
