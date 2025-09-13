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
    int* answer = (int*)malloc(querySize * sizeof(int));
    *returnSize = querySize;
    
    // Initialize the adjacency list for the graph
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = -1; // -1 indicates no edge
        }
    }
    // Fill the graph with edges
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }
    // Process each query
    for (int i = 0; i < querySize; i++) {
        int si = query[i][0];
        int ti = query[i][1];
        
        // Use BFS or DFS to find the minimum cost path
        int minCost = -1;
        int* visited = (int*)calloc(n, sizeof(int));
        int* stack = (int*)malloc(n * sizeof(int));
        int top = 0;
        
        stack[top++] = si;
        visited[si] = 1;
        
        while (top > 0) {
            int current = stack[--top];
            if (current == ti) {
                // Calculate the cost of the path
                int cost = -1;
                for (int j = 0; j < n; j++) {
                    if (visited[j] && graph[current][j] != -1) {
                        if (cost == -1) {
                            cost = graph[current][j];
                        } else {
                            cost &= graph[current][j];
                        }
                    }
                }
                if (minCost == -1 || cost < minCost) {
                    minCost = cost;
                }
            }
            for (int j = 0; j < n; j++) {
                if (graph[current][j] != -1 && !visited[j]) {
                    visited[j] = 1;
                    stack[top++] = j;
                }
            }
        }
        
        answer[i] = minCost;
        free(visited);
    }
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);    
    return answer;  
}