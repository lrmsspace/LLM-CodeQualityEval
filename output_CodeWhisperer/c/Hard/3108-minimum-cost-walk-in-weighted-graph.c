/*
 There is an undirected weighted graph with n vertices labeled from 0 to n - 1.
 You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.
 A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.
 The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.
 You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.
 Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.
 Example 1:
 Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]
 Output: [1,-1]
 Explanation:
 To achieve the cost of 1 in the first query, we need to move on the following edges: 0->1 (weight 7), 1->2 (weight 1), 2->1 (weight 1), 1->3 (weight 7).
 In the second query, there is no walk between nodes 3 and 4, so the answer is -1.
 Example 2:
 Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]
 Output: [0]
 Explanation:
 To achieve the cost of 0 in the first query, we need to move on the following edges: 1->2 (weight 1), 2->1 (weight 6), 1->2 (weight 1).
 Constraints:
 2 <= n <= 105
 0 <= edges.length <= 105
 edges[i].length == 3
 0 <= ui, vi <= n - 1
 ui != vi
 0 <= wi <= 105
 1 <= query.length <= 105
 query[i].length == 2
 0 <= si, ti <= n - 1
 si != ti
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minimumCost(int n, int** edges, int edgesSize, int* edgesColSize, int** query, int querySize, int* queryColSize, int* returnSize) {
    // Create adjacency list representation of graph
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));
    
    // Count number of edges for each vertex
    for(int i = 0; i < edgesSize; i++) {
        adjSize[edges[i][0]]++;
        adjSize[edges[i][1]]++;
    }
    
    // Allocate memory for adjacency lists
    for(int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * 3 * sizeof(int));
        adjSize[i] = 0;
    }
    
    // Build adjacency lists
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
    
    *returnSize = querySize;
    int* result = (int*)malloc(querySize * sizeof(int));
    
    // Process each query
    for(int q = 0; q < querySize; q++) {
        int start = query[q][0];
        int end = query[q][1];
        
        // BFS queue
        int* queue = (int*)malloc(n * sizeof(int));
        int front = 0, rear = 0;
        
        // Track visited edges and current AND value
        int* visited = (int*)calloc(edgesSize, sizeof(int));
        int* andValue = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++) andValue[i] = 0x7fffffff;
        
        queue[rear++] = start;
        andValue[start] = 0x7fffffff;
        
        int found = 0;
        while(front < rear) {
            int curr = queue[front++];
            
            if(curr == end) {
                found = 1;
                continue;
            }
            
            for(int i = 0; i < adjSize[curr]; i++) {
                int next = adj[curr][i*3];
                int weight = adj[curr][i*3+1];
                int edgeIdx = adj[curr][i*3+2];
                
                if(!visited[edgeIdx]) {
                    visited[edgeIdx] = 1;
                    int newAnd = andValue[curr] & weight;
                    if(newAnd < andValue[next]) {
                        andValue[next] = newAnd;
                        queue[rear++] = next;
                    }
                }
            }
        }
        
        result[q] = found ? andValue[end] : -1;
        
        free(queue);
        free(visited);
        free(andValue);
    }
    
    // Free adjacency lists
    for(int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    
    return result;
}            
