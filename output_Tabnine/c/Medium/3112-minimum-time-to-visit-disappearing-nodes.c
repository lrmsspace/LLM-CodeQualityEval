/*
 There is an undirected graph of n nodes. You are given a 2D array edges, where edges[i] = [ui, vi, lengthi] describes an edge between node ui and node vi with a traversal time of lengthi units.
 Additionally, you are given an array disappear, where disappear[i] denotes the time when the node i disappears from the graph and you won't be able to visit it.
 Note that the graph might be disconnected and might contain multiple edges.
 Return the array answer, with answer[i] denoting the minimum units of time required to reach node i from node 0. If node i is unreachable from node 0 then answer[i] is -1.
 Example 1:
 Input: n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,1,5]
 Output: [0,-1,4]
 Explanation:
 We are starting our journey from node 0, and our goal is to find the minimum time required to reach each node before it disappears.
 For node 0, we don't need any time as it is our starting point.
 For node 1, we need at least 2 units of time to traverse edges[0]. Unfortunately, it disappears at that moment, so we won't be able to visit it.
 For node 2, we need at least 4 units of time to traverse edges[2].
 Example 2:
 Input: n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,3,5]
 Output: [0,2,3]
 Explanation:
 We are starting our journey from node 0, and our goal is to find the minimum time required to reach each node before it disappears.
 For node 0, we don't need any time as it is the starting point.
 For node 1, we need at least 2 units of time to traverse edges[0].
 For node 2, we need at least 3 units of time to traverse edges[0] and edges[1].
 Example 3:
 Input: n = 2, edges = [[0,1,1]], disappear = [1,1]
 Output: [0,-1]
 Explanation:
 Exactly when we reach node 1, it disappears.
 Constraints:
 1 <= n <= 5 * 104
 0 <= edges.length <= 105
 edges[i] == [ui, vi, lengthi]
 0 <= ui, vi <= n - 1
 1 <= lengthi <= 105
 disappear.length == n
 1 <= disappear[i] <= 105
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minimumTime(int n, int** edges, int edgesSize, int* edgesColSize, int* disappear, int disappearSize, int* returnSize) {

    // Create adjacency list
    int** adjList = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adjList[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            adjList[i][j] = INT_MAX;
    }
    
    // Populate adjacency list
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1], length = edges[i][2];
        adjList[u][v] = length;
        adjList[v][u] = length;
    }
    
    // Perform BFS from node 0
    int* visited = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = 0;  
    visited[0] = 1; 
    int* time = (int*)malloc(n * sizeof(int));

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < n; v++) {
            if (adjList[u][v]!= INT_MAX &&!visited[v]) {
                visited[v] = 1;
                time[v] = time[u] + adjList[u][v];
                queue[rear++] = v;
            }
        }
    }
    
    // Update answer array
    *returnSize = n;
    int* answer = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (disappear[i] > time[i])
            answer[i] = -1;
        else
            answer[i] = time[i];
    }
    
    // Free memory
    free(adjList);
    free(visited);
    free(queue);
    free(time); 
    return answer;
}