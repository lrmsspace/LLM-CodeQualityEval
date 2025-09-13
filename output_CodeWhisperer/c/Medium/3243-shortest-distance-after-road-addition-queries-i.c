/*
 You are given an integer n and a 2D integer array queries.
 There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.
 queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.
 Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.
 Example 1:
 Input: n = 5, queries = [[2,4],[0,2],[0,4]]
 Output: [3,2,1]
 Explanation: 
 After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.
 After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.
 After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.
 Example 2:
 Input: n = 4, queries = [[0,3],[0,2]]
 Output: [1,1]
 Explanation:
 After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.
 After the addition of the road from 0 to 2, the length of the shortest path remains 1.
 Constraints:
 3 <= n <= 500
 1 <= queries.length <= 500
 queries[i].length == 2
 0 <= queries[i][0] < queries[i][1] < n
 1 < queries[i][1] - queries[i][0]
 There are no repeated roads among the queries.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Initialize result array
    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    // Create adjacency matrix to store graph
    int** graph = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++) {
            graph[i][j] = 10000; // Initialize with large value
        }
        graph[i][i] = 0; // Distance to self is 0
    }
    
    // Add initial roads from i to i+1
    for(int i = 0; i < n-1; i++) {
        graph[i][i+1] = 1;
    }
    
    // Process each query
    for(int q = 0; q < queriesSize; q++) {
        int u = queries[q][0];
        int v = queries[q][1];
        graph[u][v] = 1; // Add new road
        
        // Floyd-Warshall algorithm to find shortest paths
        int** dist = (int**)malloc(n * sizeof(int*));
        for(int i = 0; i < n; i++) {
            dist[i] = (int*)malloc(n * sizeof(int));
            for(int j = 0; j < n; j++) {
                dist[i][j] = graph[i][j];
            }
        }
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        result[q] = dist[0][n-1];
        
        // Free temporary distance array
        for(int i = 0; i < n; i++) {
            free(dist[i]);
        }
        free(dist);
    }
    
    // Free graph
    for(int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    
    return result;
}        