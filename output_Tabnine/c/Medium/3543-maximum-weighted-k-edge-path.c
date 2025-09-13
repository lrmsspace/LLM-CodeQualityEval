/*
 You are given an integer n and a Directed Acyclic Graph (DAG) with n nodes labeled from 0 to n - 1. This is represented by a 2D array edges, where edges[i] = [ui, vi, wi] indicates a directed edge from node ui to vi with weight wi.
 You are also given two integers, k and t.
 Your task is to determine the maximum possible sum of edge weights for any path in the graph such that:
 The path contains exactly k edges.
 The total sum of edge weights in the path is strictly less than t.
 Return the maximum possible sum of weights for such a path. If no such path exists, return -1.
 Example 1:
 Input: n = 3, edges = [[0,1,1],[1,2,2]], k = 2, t = 4
 Output: 3
 Explanation:
 The only path with k = 2 edges is 0 -> 1 -> 2 with weight 1 + 2 = 3 < t.
 Thus, the maximum possible sum of weights less than t is 3.
 Example 2:
 Input: n = 3, edges = [[0,1,2],[0,2,3]], k = 1, t = 3
 Output: 2
 Explanation:
 There are two paths with k = 1 edge:
 0 -> 1 with weight 2 < t.
 0 -> 2 with weight 3 = t, which is not strictly less than t.
 Thus, the maximum possible sum of weights less than t is 2.
 Example 3:
 Input: n = 3, edges = [[0,1,6],[1,2,8]], k = 1, t = 6
 Output: -1
 Explanation:
 There are two paths with k = 1 edge:
 0 -> 1 with weight 6 = t, which is not strictly less than t.
 1 -> 2 with weight 8 > t, which is not strictly less than t.
 Since there is no path with sum of weights strictly less than t, the answer is -1.
 Constraints:
 1 <= n <= 300
 0 <= edges.length <= 300
 edges[i] = [ui, vi, wi]
 0 <= ui, vi < n
 ui != vi
 1 <= wi <= 10
 0 <= k <= 300
 1 <= t <= 600
 The input graph is guaranteed to be a DAG.
 There are no duplicate edges.
*/
// Structure to represent an edge in the graph
typedef struct Edge {
    int u;
    int v;
    int weight;
} Edge;

// Function to perform DFS and find the maximum possible sum of weights
int dfs(int node, int k, int t, int* visited, Edge* edges, int edgesSize, int* maxSum) {
    // Base case: if k edges are visited and the total weight is less than t, update the maximum sum
    if (k == 0 && t > 0) {
        *maxSum = t > *maxSum ? t : *maxSum;
        return;
    }

    // Mark the current node as visited
    visited[node] = 1;

    // Explore all adjacent edges
    for (int i = 0; i < edgesSize; i++) {
        Edge edge = edges[i];

        // Check if the edge is adjacent to the current node and not visited
        if (edge.u == node && visited[edge.v] == 0) {
            // Recursively explore the adjacent node
            dfs(edge.v, k - 1, t - edge.weight, visited, edges, edgesSize, maxSum);
        }
    }

    // Backtrack by marking the current node as unvisited
    visited[node] = 0;
}

int maxWeight(int n, int** edges, int edgesSize, int* edgesColSize, int k, int t) {
    // Convert the 2D array of edges to an array of Edge structures
    Edge* edgeArray = (Edge*)malloc(edgesSize * sizeof(Edge));
    for (int i = 0; i < edgesSize; i++) {
        edgeArray[i].u = edges[i][0];
        edgeArray[i].v = edges[i][1];
        edgeArray[i].weight = edges[i][2];
    }

    // Initialize the visited array
    int* visited = (int*)calloc(n, sizeof(int));

    // Initialize the maximum sum variable
    int maxSum = INT_MIN;

    // Perform DFS from each node
    for (int i = 0; i < n; i++) {
        dfs(i, k, t, visited, edgeArray, edgesSize, &maxSum);
    }

    // Free the allocated memory
    free(edgeArray);
    free(visited);

    // Return the maximum possible sum of weights
    return maxSum == INT_MIN ? -1 : maxSum;
}