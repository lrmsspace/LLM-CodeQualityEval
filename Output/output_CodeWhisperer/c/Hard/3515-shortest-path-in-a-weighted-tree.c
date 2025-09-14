/*
 You are given an integer n and an undirected, weighted tree rooted at node 1 with n nodes numbered from 1 to n. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates an undirected edge from node ui to vi with weight wi.
 You are also given a 2D integer array queries of length q, where each queries[i] is either:
 [1, u, v, w'] – Update the weight of the edge between nodes u and v to w', where (u, v) is guaranteed to be an edge present in edges.
 [2, x] – Compute the shortest path distance from the root node 1 to node x.
 Return an integer array answer, where answer[i] is the shortest path distance from node 1 to x for the ith query of [2, x].
 Example 1:
 Input: n = 2, edges = [[1,2,7]], queries = [[2,2],[1,1,2,4],[2,2]]
 Output: [7,4]
 Explanation:
 Query [2,2]: The shortest path from root node 1 to node 2 is 7.
 Query [1,1,2,4]: The weight of edge (1,2) changes from 7 to 4.
 Query [2,2]: The shortest path from root node 1 to node 2 is 4.
 Example 2:
 Input: n = 3, edges = [[1,2,2],[1,3,4]], queries = [[2,1],[2,3],[1,1,3,7],[2,2],[2,3]]
 Output: [0,4,2,7]
 Explanation:
 Query [2,1]: The shortest path from root node 1 to node 1 is 0.
 Query [2,3]: The shortest path from root node 1 to node 3 is 4.
 Query [1,1,3,7]: The weight of edge (1,3) changes from 4 to 7.
 Query [2,2]: The shortest path from root node 1 to node 2 is 2.
 Query [2,3]: The shortest path from root node 1 to node 3 is 7.
 Example 3:
 Input: n = 4, edges = [[1,2,2],[2,3,1],[3,4,5]], queries = [[2,4],[2,3],[1,2,3,3],[2,2],[2,3]]
 Output: [8,3,2,5]
 Explanation:
 Query [2,4]: The shortest path from root node 1 to node 4 consists of edges (1,2), (2,3), and (3,4) with weights 2 + 1 + 5 = 8.
 Query [2,3]: The shortest path from root node 1 to node 3 consists of edges (1,2) and (2,3) with weights 2 + 1 = 3.
 Query [1,2,3,3]: The weight of edge (2,3) changes from 1 to 3.
 Query [2,2]: The shortest path from root node 1 to node 2 is 2.
 Query [2,3]: The shortest path from root node 1 to node 3 consists of edges (1,2) and (2,3) with updated weights 2 + 3 = 5.
 Constraints:
 1 <= n <= 105
 edges.length == n - 1
 edges[i] == [ui, vi, wi]
 1 <= ui, vi <= n
 1 <= wi <= 104
 The input is generated such that edges represents a valid tree.
 1 <= queries.length == q <= 105
 queries[i].length == 2 or 4
 queries[i] == [1, u, v, w'] or,
 queries[i] == [2, x]
 1 <= u, v, x <= n
 (u, v) is always an edge from edges.
 1 <= w' <= 104
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* treeQueries(int n, int** edges, int edgesSize, int* edgesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Create adjacency list representation
    int** adj = (int**)malloc(sizeof(int*) * (n + 1));
    int* adjSize = (int*)calloc(n + 1, sizeof(int));
    int** weights = (int**)malloc(sizeof(int*) * (n + 1));
    
    for(int i = 0; i <= n; i++) {
        adj[i] = (int*)malloc(sizeof(int) * n);
        weights[i] = (int*)malloc(sizeof(int) * n);
    }
    
    // Build adjacency list with weights
    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        adj[u][adjSize[u]] = v;
        weights[u][adjSize[u]] = w;
        adjSize[u]++;
        adj[v][adjSize[v]] = u;
        weights[v][adjSize[v]] = w;
        adjSize[v]++;
    }
    
    // Count number of type 2 queries
    int count = 0;
    for(int i = 0; i < queriesSize; i++) {
        if(queries[i][0] == 2) count++;
    }
    
    *returnSize = count;
    int* result = (int*)malloc(sizeof(int) * count);
    int idx = 0;
    
    // Process each query
    for(int i = 0; i < queriesSize; i++) {
        if(queries[i][0] == 1) {
            // Update weight
            int u = queries[i][1], v = queries[i][2], w = queries[i][3];
            for(int j = 0; j < adjSize[u]; j++) {
                if(adj[u][j] == v) {
                    weights[u][j] = w;
                    break;
                }
            }
            for(int j = 0; j < adjSize[v]; j++) {
                if(adj[v][j] == u) {
                    weights[v][j] = w;
                    break;
                }
            }
        } else {
            // Find shortest path using DFS
            int target = queries[i][1];
            int* visited = (int*)calloc(n + 1, sizeof(int));
            int* dist = (int*)malloc(sizeof(int) * (n + 1));
            for(int j = 0; j <= n; j++) dist[j] = INT_MAX;
            dist[1] = 0;
            
            int* stack = (int*)malloc(sizeof(int) * (n + 1));
            int top = 0;
            stack[top++] = 1;
            
            while(top > 0) {
                int curr = stack[--top];
                visited[curr] = 1;
                
                for(int j = 0; j < adjSize[curr]; j++) {
                    int next = adj[curr][j];
                    if(!visited[next]) {
                        dist[next] = dist[curr] + weights[curr][j];
                        stack[top++] = next;
                    }
                }
            }
            
            result[idx++] = dist[target];
            free(visited);
            free(dist);
            free(stack);
        }
    }
    
    // Free memory
    for(int i = 0; i <= n; i++) {
        free(adj[i]);
        free(weights[i]);
    }
    free(adj);
    free(weights);
    free(adjSize);
    
    return result;
}     