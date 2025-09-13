/*
 You are given an integer n and a 2D integer array queries.
 There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.
 queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.
 There are no two queries such that queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1].
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
 3 <= n <= 105
 1 <= queries.length <= 105
 queries[i].length == 2
 0 <= queries[i][0] < queries[i][1] < n
 1 < queries[i][1] - queries[i][0]
 There are no repeated roads among the queries.
 There are no two queries such that i != j and queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1].
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestDistanceAfterQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Initialize distances array
    int* dist = (int*)malloc(n * sizeof(int));
    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    // Process each query
    for(int q = 0; q < queriesSize; q++) {
        // Reset distances for each query
        for(int i = 0; i < n; i++) {
            dist[i] = n + 1;
        }
        dist[0] = 0;
        
        // Build graph with initial roads and roads added so far
        int** graph = (int**)malloc(n * sizeof(int*));
        for(int i = 0; i < n; i++) {
            graph[i] = (int*)calloc(n, sizeof(int));
        }
        
        // Add initial roads
        for(int i = 0; i < n-1; i++) {
            graph[i][i+1] = 1;
        }
        
        // Add roads from queries processed so far
        for(int i = 0; i <= q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            graph[u][v] = 1;
        }
        
        // BFS to find shortest path
        int* queue = (int*)malloc(n * sizeof(int));
        int front = 0, rear = 0;
        queue[rear++] = 0;
        
        while(front < rear) {
            int curr = queue[front++];
            for(int next = 0; next < n; next++) {
                if(graph[curr][next] && dist[next] > dist[curr] + 1) {
                    dist[next] = dist[curr] + 1;
                    queue[rear++] = next;
                }
            }
        }
        
        result[q] = dist[n-1];
        
        // Free memory
        free(queue);
        for(int i = 0; i < n; i++) {
            free(graph[i]);
        }
        free(graph);
    }
    
    free(dist);
    return result;
}
