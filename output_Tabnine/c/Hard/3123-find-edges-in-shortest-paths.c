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
    *returnSize = n;
    bool* answer = malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        answer[i] = false;
    }
    
    // Initialize the adjacency list
    int** adjList = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adjList[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            adjList[i][j] = INT_MAX;
        }
        adjList[i][i] = 0;
    }
    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0], b = edges[i][1], w = edges[i][2];
        adjList[a][b] = w;
        adjList[b][a] = w;
    
        // Add the edge in the adjacency list
        for (int j = 0; j < n; j++) {
            if (adjList[j][a]!= INT_MAX && adjList[j][b] > adjList[j][a] + w) {
                adjList[j][b] = adjList[j][a] + w;
            }
        }
    }
    // Find the shortest paths
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjList[i][k]!= INT_MAX && adjList[k][j]!= INT_MAX && adjList[i][j] > adjList[i][k] + adjList[k][j]) {
                    adjList[i][j] = adjList[i][k] + adjList[k][j];
                }
            }
        }
    }
    // Check if the edge is part of at least one shortest path
    for (int i = 0; i < edgesSize; i++) {
        int a = edges[i][0], b = edges[i][1], w = edges[i][2];
        if (adjList[a][b] <= w) {
            answer[a] = true;
            answer[b] = true;
        }
    }
    return answer;  
    
}