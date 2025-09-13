/*
 There exists an undirected tree rooted at node 0 with n nodes labeled from 0 to n - 1. You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given a 0-indexed array coins of size n where coins[i] indicates the number of coins in the vertex i, and an integer k.
 Starting from the root, you have to collect all the coins such that the coins at a node can only be collected if the coins of its ancestors have been already collected.
 Coins at nodei can be collected in one of the following ways:
 Collect all the coins, but you will get coins[i] - k points. If coins[i] - k is negative then you will lose abs(coins[i] - k) points.
 Collect all the coins, but you will get floor(coins[i] / 2) points. If this way is used, then for all the nodej present in the subtree of nodei, coins[j] will get reduced to floor(coins[j] / 2).
 Return the maximum points you can get after collecting the coins from all the tree nodes.
 Example 1:
 Input: edges = [[0,1],[1,2],[2,3]], coins = [10,10,3,3], k = 5
 Output: 11                        
 Explanation: 
 Collect all the coins from node 0 using the first way. Total points = 10 - 5 = 5.
 Collect all the coins from node 1 using the first way. Total points = 5 + (10 - 5) = 10.
 Collect all the coins from node 2 using the second way so coins left at node 3 will be floor(3 / 2) = 1. Total points = 10 + floor(3 / 2) = 11.
 Collect all the coins from node 3 using the second way. Total points = 11 + floor(1 / 2) = 11.
 It can be shown that the maximum points we can get after collecting coins from all the nodes is 11. 
 Example 2:
 Input: edges = [[0,1],[0,2]], coins = [8,4,4], k = 0
 Output: 16
 Explanation: 
 Coins will be collected from all the nodes using the first way. Therefore, total points = (8 - 0) + (4 - 0) + (4 - 0) = 16.
 Constraints:
 n == coins.length
 2 <= n <= 105
 0 <= coins[i] <= 104
 edges.length == n - 1
 0 <= edges[i][0], edges[i][1] < n
 0 <= k <= 104
*/

int maximumPoints(int** edges, int edgesSize, int* edgesColSize, int* coins, int coinsSize, int k) {
    int n = coinsSize;
    int* dp = (int*)calloc(n, sizeof(int));
    int* subtreeCoins = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));
    
    // Build adjacency list
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = -1; // Initialize with -1
        }
    }
    
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    // DFS function to calculate maximum points
    void dfs(int node, int parent) {
        visited[node] = 1;
        subtreeCoins[node] = coins[node];
        
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && i != parent && !visited[i]) {
                dfs(i, node);
                subtreeCoins[node] += subtreeCoins[i];
            }
        }
        
        if (subtreeCoins[node] >= k) {
            dp[node] = subtreeCoins[node] - k;
        } else {
            dp[node] = -(k - subtreeCoins[node]);
        }
        
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && i != parent) {
                dp[node] += dp[i];
            }
        }
        
        if (subtreeCoins[node] > 0) {
            dp[node] += subtreeCoins[node] / 2;
        }
    }
    
    dfs(0, -1);
    
    int result = dp[0];
    
    free(dp);
    free(subtreeCoins);
    free(visited);
    
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    
    return result;    
}