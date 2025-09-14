/*
 There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
 You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
 Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
 Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
 Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
 Example 1:
 Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
 Output: [8,7,7,8,8]
 Explanation:
 For i = 0, connect node 0 from the first tree to node 0 from the second tree.
 For i = 1, connect node 1 from the first tree to node 4 from the second tree.
 For i = 2, connect node 2 from the first tree to node 7 from the second tree.
 For i = 3, connect node 3 from the first tree to node 0 from the second tree.
 For i = 4, connect node 4 from the first tree to node 4 from the second tree.
 Example 2:
 Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]
 Output: [3,6,6,6,6]
 Explanation:
 For every i, connect node i of the first tree with any node of the second tree.
 Constraints:
 2 <= n, m <= 105
 edges1.length == n - 1
 edges2.length == m - 1
 edges1[i].length == edges2[i].length == 2
 edges1[i] = [ai, bi]
 0 <= ai, bi < n
 edges2[i] = [ui, vi]
 0 <= ui, vi < m
 The input is generated such that edges1 and edges2 represent valid trees.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxTargetNodes(int** edges1, int edges1Size, int* edges1ColSize, int** edges2, int edges2Size, int* edges2ColSize, int* returnSize) {
    // Initialize variables
    int n = edges1Size + 1;
    int m = edges2Size + 1;
    *returnSize = n;
    
    // Allocate memory for adjacency lists
    int** adj1 = (int**)malloc(n * sizeof(int*));
    int** adj2 = (int**)malloc(m * sizeof(int*));
    int* size1 = (int*)calloc(n, sizeof(int));
    int* size2 = (int*)calloc(m, sizeof(int));
    
    // Count degrees for each node
    for(int i = 0; i < edges1Size; i++) {
        size1[edges1[i][0]]++;
        size1[edges1[i][1]]++;
    }
    for(int i = 0; i < edges2Size; i++) {
        size2[edges2[i][0]]++;
        size2[edges2[i][1]]++;
    }
    
    // Allocate memory for adjacency lists based on degrees
    for(int i = 0; i < n; i++) {
        adj1[i] = (int*)malloc(size1[i] * sizeof(int));
        size1[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        adj2[i] = (int*)malloc(size2[i] * sizeof(int));
        size2[i] = 0;
    }
    
    // Build adjacency lists
    for(int i = 0; i < edges1Size; i++) {
        int u = edges1[i][0], v = edges1[i][1];
        adj1[u][size1[u]++] = v;
        adj1[v][size1[v]++] = u;
    }
    for(int i = 0; i < edges2Size; i++) {
        int u = edges2[i][0], v = edges2[i][1];
        adj2[u][size2[u]++] = v;
        adj2[v][size2[v]++] = u;
    }
    
    // Allocate memory for distances arrays
    int* dist1 = (int*)malloc(n * sizeof(int));
    int* dist2 = (int*)malloc(m * sizeof(int));
    
    // Allocate memory for result
    int* result = (int*)malloc(n * sizeof(int));
    
    // For each node in first tree
    for(int i = 0; i < n; i++) {
        // Calculate distances from node i in first tree
        for(int j = 0; j < n; j++) dist1[j] = -1;
        dist1[i] = 0;
        
        int* queue = (int*)malloc(n * sizeof(int));
        int front = 0, rear = 0;
        queue[rear++] = i;
        
        while(front < rear) {
            int curr = queue[front++];
            for(int j = 0; j < size1[curr]; j++) {
                int next = adj1[curr][j];
                if(dist1[next] == -1) {
                    dist1[next] = dist1[curr] + 1;
                    queue[rear++] = next;
                }
            }
        }
        
        // Find max number of target nodes
        int maxCount = 0;
        
        // Try connecting to each node in second tree
        for(int j = 0; j < m; j++) {
            // Calculate distances from node j in second tree
            for(int k = 0; k < m; k++) dist2[k] = -1;
            dist2[j] = 0;
            
            front = rear = 0;
            queue[rear++] = j;
            
            while(front < rear) {
                int curr = queue[front++];
                for(int k = 0; k < size2[curr]; k++) {
                    int next = adj2[curr][k];
                    if(dist2[next] == -1) {
                        dist2[next] = dist2[curr] + 1;
                        queue[rear++] = next;
                    }
                }
            }
            
            // Count target nodes
            int count = 0;
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < m; l++) {
                    if((dist1[k] + 1 + dist2[l]) % 2 == 0) {
                        count++;
                        break;
                    }
                }
            }
            
            maxCount = count > maxCount ? count : maxCount;
        }
        
        result[i] = maxCount;
        free(queue);
    }
    
    // Free allocated memory
    for(int i = 0; i < n; i++) free(adj1[i]);
    for(int i = 0; i < m; i++) free(adj2[i]);
    free(adj1);
    free(adj2);
    free(size1);
    free(size2);
    free(dist1);
    free(dist2);
    
    return result;
}    