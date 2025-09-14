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
    int* dist = (int*)malloc(n * sizeof(int));
    int* prev = (int*)malloc(n * sizeof(int));
    bool* inQueue = (bool*)malloc(n * sizeof(bool));
    bool* answer = (bool*)malloc(edgesSize * sizeof(bool));
    
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        inQueue[i] = false;
    }
    
    dist[0] = 0;
    inQueue[0] = true;
    
    // Bellman-Ford algorithm to find shortest paths
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < edgesSize; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                inQueue[v] = true;
            }
            if (dist[v] != INT_MAX && dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                prev[u] = v;
                inQueue[u] = true;
            }
        }
    }
    
    // Check if the edge is part of any shortest path
    for (int j = 0; j < edgesSize; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        
        if ((dist[u] != INT_MAX && dist[u] + w == dist[v]) || 
            (dist[v] != INT_MAX && dist[v] + w == dist[u])) {
            answer[j] = true;
        } else {
            answer[j] = false;
        }
    }
    
    *returnSize = edgesSize;
    
    free(dist);
    free(prev);
    free(inQueue);
    
    return answer;    
}