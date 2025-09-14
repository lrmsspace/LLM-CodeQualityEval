/**https://leetcode.com/problems/frog-position-after-t-seconds/ */
//Given an undirected tree consisting of n vertices numbered from 1 to n. A frog starts jumping from vertex 1. In one second, the frog jumps from its current vertex to another unvisited vertex if they are directly connected. The frog can not jump back to a visited vertex. In case the frog can jump to several vertices, it jumps randomly to one of them with the same probability. Otherwise, when the frog can not jump to any unvisited vertex, it jumps forever on the same vertex.
//The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi.
//Return the probability that after t seconds the frog is on the vertex target. Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
//Output: 0.16666666666666666 
//Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 probability to the vertex 2 after second 1 and then jumping with 1/2 probability to vertex 4 after second 2. Thus the probability for the frog is on the vertex 4 after 2 seconds is 1/3 * 1/2 = 1/6 = 0.16666666666666666. 
//Example 2:
//Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
//Output: 0.3333333333333333
//Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7 after second 1. 
// 
//Constraints:
//	1 <= n <= 100
//	edges.length == n - 1
//	edges[i].length == 2
//	1 <= ai, bi <= n
//	1 <= t <= 50
//	1 <= target <= n
double frogPosition(int n, int** edges, int edgesSize, int* edgesColSize, int t, int target) {
    // Initialize a 2D dp array to store the probability of reaching the target vertex at each second
    double** dp = (double**)malloc(sizeof(double*) * t);
    for (int i = 0; i < t; i++) {
        dp[i] = (double*)malloc(sizeof(double) * n);
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0.0;
        }
    }
    
    // Initialize a boolean visited array to keep track of visited vertices
    bool* visited = (bool*)malloc(sizeof(bool) * n);
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    // Create an adjacency list to store the edges
    int** adj = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    // Build the adjacency list
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    // Set the initial probability of reaching the target vertex at the first second
    dp[0][target - 1] = 1.0;
    
    // Perform dynamic programming to calculate the probability of reaching the target vertex at each second
    for (int i = 1; i < t; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (adj[j][k] == 1 &&!visited[k]) {
                    dp[i][j] += dp[i - 1][k] / (double)adj[j][k];
                }
            }
        }
        
        // Mark the visited vertices
        for (int j = 0; j < n; j++) {
            if (dp[i][j] > 0) {
                visited[j] = true;
            }
        }
    }
    
    // Return the probability of reaching the target vertex at the last second
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += dp[t - 1][i];
    }
    
    // Free the allocated memory
    for (int i = 0; i < t; i++) {
        free(dp[i]);
    }
    free(dp);
    
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    
    free(visited);
    
    return result;
    
}