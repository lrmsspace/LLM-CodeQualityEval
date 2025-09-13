/**https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/ */
//There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.
//A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.
//The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.
//Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
//Output: 3
//Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
//1) 1 --> 2 --> 5
//2) 1 --> 2 --> 3 --> 5
//3) 1 --> 3 --> 5
//Example 2:
//Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
//Output: 1
//Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.
// 
//Constraints:
//	1 <= n <= 2 * 104
//	n - 1 <= edges.length <= 4 * 104
//	edges[i].length == 3
//	1 <= ui, vi <= n
//	ui != vi
//	1 <= weighti <= 105
//	There is at most one edge between any two nodes.
//	There is at least one path between any two nodes.
int countRestrictedPaths(int n, int** edges, int edgesSize, int* edgesColSize) {
    int MOD = 1000000007;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    
    // Initialize the dp array with 1 for each node
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Build the adjacency list
    int adj[n][n];
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        int weight = edges[i][2];
        adj[u][v] = adj[v][u] = weight;
    }
    
    // Perform Dijkstra's algorithm to calculate distanceToLastNode
    int dist[n];
    memset(dist, INT_MAX, sizeof(dist));
    dist[n - 1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, n - 1});
    
    while (!pq.empty()) {
        int curr = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] > 0) {
                int newDist = dist[curr] + adj[curr][i];
                if (newDist < dist[i]) {
                    dist[i] = newDist;
                    pq.push({newDist, i});
                }
            }
        }
    }
    
    // Calculate the number of restricted paths
    for (int k = n - 2; k >= 0; k--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] > 0 && dist[i] > dist[j]) {
                    dp[i][k] = (dp[i][k] + dp[j][k + 1]) % MOD;
                }
            }
        }
    }
    
    return dp[0][0];
    
}