/*
 There is an undirected tree with n nodes labeled from 1 to n. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree.
 Return the number of valid paths in the tree.
 A path (a, b) is valid if there exists exactly one prime number among the node labels in the path from a to b.
 Note that:
 The path (a, b) is a sequence of distinct nodes starting with node a and ending with node b such that every two adjacent nodes in the sequence share an edge in the tree.
 Path (a, b) and path (b, a) are considered the same and counted only once.
 Example 1:
 Input: n = 5, edges = [[1,2],[1,3],[2,4],[2,5]]
 Output: 4
 Explanation: The pairs with exactly one prime number on the path between them are: 
 - (1, 2) since the path from 1 to 2 contains prime number 2. 
 - (1, 3) since the path from 1 to 3 contains prime number 3.
 - (1, 4) since the path from 1 to 4 contains prime number 2.
 - (2, 4) since the path from 2 to 4 contains prime number 2.
 It can be shown that there are only 4 valid paths.
 Example 2:
 Input: n = 6, edges = [[1,2],[1,3],[2,4],[3,5],[3,6]]
 Output: 6
 Explanation: The pairs with exactly one prime number on the path between them are: 
 - (1, 2) since the path from 1 to 2 contains prime number 2.
 - (1, 3) since the path from 1 to 3 contains prime number 3.
 - (1, 4) since the path from 1 to 4 contains prime number 2.
 - (1, 6) since the path from 1 to 6 contains prime number 3.
 - (2, 4) since the path from 2 to 4 contains prime number 2.
 - (3, 6) since the path from 3 to 6 contains prime number 3.
 It can be shown that there are only 6 valid paths.
 Constraints:
 1 <= n <= 105
 edges.length == n - 1
 edges[i].length == 2
 1 <= ui, vi <= n
 The input is generated such that edges represent a valid tree.
*/

long long countPaths(int n, int** edges, int edgesSize, int* edgesColSize) {

    // Step 1: Create an adjacency list to store the edges
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Step 2: Find the prime numbers in the tree
    vector<bool> isPrime(n + 1, true);
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // Step 3: Count the valid paths using dynamic programming
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int v = adj[i][j];
            if (isPrime[v]) {
                dp[i] += dp[v];
            }
        }
    }
    
    // Step 4: Return the total number of valid paths
    return dp[n];
    
}