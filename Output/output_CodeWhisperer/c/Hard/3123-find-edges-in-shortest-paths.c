/*
 You are given an undirected weighted graph of n nodes numbered from 0 to n - 1. The graph consists of m edges represented by a 2D array edges, where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.
 Consider all the shortest paths from node 0 to node n - 1 in the graph. You need to find a boolean array answer where answer[i] is true if the edge edges[i] is part of at least one shortest path. Otherwise, answer[i] is false.
 Return the array answer.
 Note that the graph may not be connected.
 Example 1:
 Input: n = 6, edges = [[0,1,4],[0,2,1],[1,3,2],[1,4,3],[1,5,1],[2,3,1],[3,5,3],[4,5,2]]
 Output: [true,true,true,false,true,true,true,false]
 Explanation:
 The following are all the shortest paths between nodes 0 and 5:
 The path 0 -> 1 -> 5: The sum of weights is 4 + 1 = 5.
 The path 0 -> 2 -> 3 -> 5: The sum of weights is 1 + 1 + 3 = 5.
 The path 0 -> 2 -> 3 -> 1 -> 5: The sum of weights is 1 + 1 + 2 + 1 = 5.
 Example 2:
 Input: n = 4, edges = [[2,0,1],[0,1,1],[0,3,4],[3,2,2]]
 Output: [true,false,false,true]
 Explanation:
 There is one shortest path between nodes 0 and 3, which is the path 0 -> 2 -> 3 with the sum of weights 1 + 2 = 3.
 Constraints:
 2 <= n <= 5 * 104
 m == edges.length
 1 <= m <= min(5 * 104, n * (n - 1) / 2)
 0 <= ai, bi < n
 ai != bi
 1 <= wi <= 105
 There are no repeated edges.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* findAnswer(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    // Initialize distances array and adjacency list
    long long* dist = (long long*)malloc(n * sizeof(long long));
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    
    // Count number of edges for each node
    for(int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }
    
    // Allocate memory for adjacency lists
    for(int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }
    
    // Build adjacency lists
    for(int i = 0; i < edgesSize; i++) {
        adj[edges[i][0]][adjSize[edges[i][0]]++] = i;
        adj[edges[i][1]][adjSize[edges[i][1]]++] = i;
    }
    
    // Initialize distances
    for(int i = 0; i < n; i++) {
        dist[i] = LLONG_MAX;
    }
    dist[0] = 0;
    
    // Priority queue for Dijkstra's algorithm
    long long* heap = (long long*)malloc(n * sizeof(long long));
    int heapSize = 0;
    heap[heapSize++] = 0;
    
    // Run Dijkstra's algorithm
    while(heapSize > 0) {
        long long curr = heap[0];
        int u = curr >> 32;
        long long d = curr & 0xFFFFFFFFLL;
        
        // Remove min element
        heap[0] = heap[--heapSize];
        int i = 0;
        while(2*i+1 < heapSize) {
            int j = 2*i+1;
            if(j+1 < heapSize && heap[j+1] < heap[j]) j++;
            if(heap[i] <= heap[j]) break;
            long long temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
        }
        
        if(d > dist[u]) continue;
        
        // Check all adjacent edges
        for(int i = 0; i < adjSize[u]; i++) {
            int edgeIdx = adj[u][i];
            int v = edges[edgeIdx][0] ^ edges[edgeIdx][1] ^ u;
            long long newDist = d + edges[edgeIdx][2];
            
            if(newDist < dist[v]) {
                dist[v] = newDist;
                heap[heapSize++] = ((long long)v << 32) | newDist;
                
                // Heapify up
                int j = heapSize - 1;
                while(j > 0) {
                    int p = (j-1)/2;
                    if(heap[p] <= heap[j]) break;
                    long long temp = heap[p];
                    heap[p] = heap[j];
                    heap[j] = temp;
                    j = p;
                }
            }
        }
    }
    
    // Initialize result array
    bool* answer = (bool*)calloc(edgesSize, sizeof(bool));
    *returnSize = edgesSize;
    
    // Check each edge if it's part of a shortest path
    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        if(dist[u] != LLONG_MAX && dist[v] != LLONG_MAX) {
            if(dist[u] + w == dist[v] || dist[v] + w == dist[u]) {
                answer[i] = true;
            }
        }
    }
    
    // Free allocated memory
    free(dist);
    for(int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    free(heap);
    
    return answer;
}        