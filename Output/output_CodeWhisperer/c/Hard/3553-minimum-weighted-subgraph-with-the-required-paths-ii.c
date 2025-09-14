/*
 You are given an undirected weighted tree with n nodes, numbered from 0 to n - 1. It is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates that there is an edge between nodes ui and vi with weight wi.​
 Additionally, you are given a 2D integer array queries, where queries[j] = [src1j, src2j, destj].
 Return an array answer of length equal to queries.length, where answer[j] is the minimum total weight of a subtree such that it is possible to reach destj from both src1j and src2j using edges in this subtree.
 A subtree here is any connected subset of nodes and edges of the original tree forming a valid tree.
 Example 1:
 Input: edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], queries = [[2,3,4],[0,2,5]]
 Output: [12,11]
 Explanation:
 The blue edges represent one of the subtrees that yield the optimal answer.
 answer[0]: The total weight of the selected subtree that ensures a path from src1 = 2 and src2 = 3 to dest = 4 is 3 + 5 + 4 = 12.
 answer[1]: The total weight of the selected subtree that ensures a path from src1 = 0 and src2 = 2 to dest = 5 is 2 + 3 + 6 = 11.
 Example 2:
 Input: edges = [[1,0,8],[0,2,7]], queries = [[0,1,2]]
 Output: [15]
 Explanation:
 answer[0]: The total weight of the selected subtree that ensures a path from src1 = 0 and src2 = 1 to dest = 2 is 8 + 7 = 15.
 Constraints:
 3 <= n <= 105
 edges.length == n - 1
 edges[i].length == 3
 0 <= ui, vi < n
 1 <= wi <= 104
 1 <= queries.length <= 105
 queries[j].length == 3
 0 <= src1j, src2j, destj < n
 src1j, src2j, and destj are pairwise distinct.
 The input is generated such that edges represents a valid tree.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minimumWeight(int** edges, int edgesSize, int* edgesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Create adjacency list representation
    int n = edgesSize + 1;
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    int** weights = (int**)malloc(n * sizeof(int*));
    
    // Count number of neighbors for each node
    for(int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }
    
    // Allocate memory for adjacency lists
    for(int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        weights[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0; // Reset to use as index
    }
    
    // Build adjacency lists
    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        adj[u][adjSize[u]] = v;
        weights[u][adjSize[u]++] = w;
        adj[v][adjSize[v]] = u;
        weights[v][adjSize[v]++] = w;
    }
    
    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));
    
    // Process each query
    for(int q = 0; q < queriesSize; q++) {
        int src1 = queries[q][0];
        int src2 = queries[q][1];
        int dest = queries[q][2];
        
        // Use DFS to find paths and minimum weight
        int* visited = (int*)calloc(n, sizeof(int));
        int minWeight = INT_MAX;
        
        // Helper function for DFS
        void dfs(int node, int parent, int weight) {
            visited[node] = 1;
            
            if(node == dest) {
                minWeight = weight < minWeight ? weight : minWeight;
                return;
            }
            
            for(int i = 0; i < adjSize[node]; i++) {
                int next = adj[node][i];
                if(!visited[next] && next != parent) {
                    dfs(next, node, weight + weights[node][i]);
                }
            }
        }
        
        // Find paths from both sources
        dfs(src1, -1, 0);
        int weight1 = minWeight;
        
        // Reset for second source
        minWeight = INT_MAX;
        memset(visited, 0, n * sizeof(int));
        
        dfs(src2, -1, 0);
        int weight2 = minWeight;
        
        result[q] = weight1 + weight2;
        free(visited);
    }
    
    // Free allocated memory
    for(int i = 0; i < n; i++) {
        free(adj[i]);
        free(weights[i]);
    }
    free(adj);
    free(weights);
    free(adjSize);
    
    return result;
}      