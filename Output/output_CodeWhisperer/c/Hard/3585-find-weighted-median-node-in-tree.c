/*
 You are given an integer n and an undirected, weighted tree rooted at node 0 with n nodes numbered from 0 to n - 1. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates an edge from node ui to vi with weight wi.
 The weighted median node is defined as the first node x on the path from ui to vi such that the sum of edge weights from ui to x is greater than or equal to half of the total path weight.
 You are given a 2D integer array queries. For each queries[j] = [uj, vj], determine the weighted median node along the path from uj to vj.
 Return an array ans, where ans[j] is the node index of the weighted median for queries[j].
 Example 1:
 Input: n = 2, edges = [[0,1,7]], queries = [[1,0],[0,1]]
 Output: [0,1]
 Explanation:
 Query
 Path
 Edge
 			Weights
 Total
 			Path
 			Weight
 Half
 Explanation
 Answer
 [1, 0]
 1 → 0
 [7]
 7
 3.5
 Sum from 1 → 0 = 7 >= 3.5, median is node 0.
 0
 [0, 1]
 0 → 1
 [7]
 7
 3.5
 Sum from 0 → 1 = 7 >= 3.5, median is node 1.
 1
 Example 2:
 Input: n = 3, edges = [[0,1,2],[2,0,4]], queries = [[0,1],[2,0],[1,2]]
 Output: [1,0,2]
 Explanation:
 Query
 Path
 Edge
 			Weights
 Total
 			Path
 			Weight
 Half
 Explanation
 Answer
 [0, 1]
 0 → 1
 [2]
 2
 1
 Sum from 0 → 1 = 2 >= 1, median is node 1.
 1
 [2, 0]
 2 → 0
 [4]
 4
 2
 Sum from 2 → 0 = 4 >= 2, median is node 0.
 0
 [1, 2]
 1 → 0 → 2
 [2, 4]
 6
 3
 Sum from 1 → 0 = 2 < 3.
 			Sum from 1 → 2 = 2 + 4 = 6 >= 3, median is node 2.
 2
 Example 3:
 Input: n = 5, edges = [[0,1,2],[0,2,5],[1,3,1],[2,4,3]], queries = [[3,4],[1,2]]
 Output: [2,2]
 Explanation:
 Query
 Path
 Edge
 			Weights
 Total
 			Path
 			Weight
 Half
 Explanation
 Answer
 [3, 4]
 3 → 1 → 0 → 2 → 4
 [1, 2, 5, 3]
 11
 5.5
 Sum from 3 → 1 = 1 < 5.5.
 			Sum from 3 → 0 = 1 + 2 = 3 < 5.5.
 			Sum from 3 → 2 = 1 + 2 + 5 = 8 >= 5.5, median is node 2.
 2
 [1, 2]
 1 → 0 → 2
 [2, 5]
 7
 3.5
 Sum from 1 → 0 = 2 < 3.5.
 			Sum from 1 → 2 = 2 + 5 = 7 >= 3.5, median is node 2.
 2
 Constraints:
 2 <= n <= 105
 edges.length == n - 1
 edges[i] == [ui, vi, wi]
 0 <= ui, vi < n
 1 <= wi <= 109
 1 <= queries.length <= 105
 queries[j] == [uj, vj]
 0 <= uj, vj < n
 The input is generated such that edges represents a valid tree.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMedian(int n, int** edges, int edgesSize, int* edgesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Create adjacency list representation
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    
    // Count number of edges for each node
    for(int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }
    
    // Allocate memory for adjacency lists
    for(int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * 3 * sizeof(int));
        adjSize[i] = 0;
    }
    
    // Build adjacency lists with edges and weights
    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        adj[u][adjSize[u]*3] = v;
        adj[u][adjSize[u]*3+1] = w;
        adj[u][adjSize[u]*3+2] = i;
        adjSize[u]++;
        
        adj[v][adjSize[v]*3] = u;
        adj[v][adjSize[v]*3+1] = w;
        adj[v][adjSize[v]*3+2] = i;
        adjSize[v]++;
    }
    
    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));
    
    // Process each query
    for(int q = 0; q < queriesSize; q++) {
        int start = queries[q][0];
        int end = queries[q][1];
        
        // Use DFS to find path
        int* parent = (int*)malloc(n * sizeof(int));
        int* visited = (int*)calloc(n, sizeof(int));
        long long* pathWeight = (long long*)calloc(n, sizeof(long long));
        
        for(int i = 0; i < n; i++) parent[i] = -1;
        
        // DFS to find path from start to end
        int found = 0;
        int curr = start;
        visited[curr] = 1;
        
        while(!found) {
            found = 0;
            for(int i = 0; i < adjSize[curr]; i++) {
                int next = adj[curr][i*3];
                if(!visited[next]) {
                    parent[next] = curr;
                    pathWeight[next] = pathWeight[curr] + adj[curr][i*3+1];
                    if(next == end) {
                        found = 1;
                        break;
                    }
                    visited[next] = 1;
                    curr = next;
                    found = 1;
                    break;
                }
            }
            if(!found) {
                if(parent[curr] == -1) break;
                curr = parent[curr];
            }
        }
        
        // Find median node
        long long totalWeight = pathWeight[end];
        long long halfWeight = (totalWeight + 1) / 2;
        
        curr = end;
        while(pathWeight[curr] > halfWeight) {
            curr = parent[curr];
        }
        result[q] = curr;
        
        free(parent);
        free(visited);
        free(pathWeight);
    }
    
    // Free memory
    for(int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    
    return result;
}	